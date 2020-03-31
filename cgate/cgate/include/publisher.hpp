#ifndef __PUBLISHER_HEADER__
#define __PUBLISHER_HEADER__
#include <map>
#include <mutex>
#include <thread>

#include "../include/cgate-yard.hpp"
#include "../include/cgate_structs_helper.hpp"
#include "../include/order_reply.hpp"
#include "../include/order.hpp"

template <typename T>
struct Publisher
{
    cg_publisher_t *pub_;
    std::string name_{""};
    std::string config_{""};
    std::string broker_code_{""};
    std::string client_code_{""};
    T *responder_;
    std::mutex lock;
    uint32_t current_user_id_;
    std::map<uint32_t, Order> userid2Order;

    Publisher(std::map<std::string, std::string> &settings)
    {
        if (settings.count("name"))
        {
            name_ = settings["name"];
        }
        config_ = settings["config"];
    }

    Publisher(std::map<std::string, std::string> &settings, T &responder)
    {
        if (settings.count("name"))
        {
            name_ = settings["name"];
        }
        config_ = settings["config"];
        broker_code_ = settings["broker_code"];
        client_code_ = settings["client_code"];
        responder_ = &responder;
    }

    uint32_t CheckStateIfNeededOpen()
    {
        uint32_t state;

        cg_pub_getstate(pub_, &state);
        switch (state)
        {
        case CG_STATE_ERROR:
            logger.error("cgate: ROUTER state CG_STATE_ERROR");
            cg_pub_close(pub_);
            sleep(1);
            break;
        case CG_STATE_CLOSED:
            cg_pub_open(pub_, 0);
            sleep(1);
            break;
        case CG_STATE_OPENING:
            break;
        }

        return state;
    }

    int Init(cg_conn_t *conn)
    {
        cg_pub_new(conn, config_.c_str(), &pub_);
        return 0;
    }

    auto GetOrderHandler()
    {
        //получает ордера
        auto lambda = [this](const bson_t &doc) {
            char *str = bson_as_relaxed_extended_json(&doc, NULL);

            //std::cout << "************PUBLISHER************* name: " << name_ << std::endl;
            //std::cout << str << std::endl;
            //std::cout << "************************************" << std::endl;
            // void *data = (void *)bson_get_data(doc);
            //cgate.class.input(order)
            Order order(&doc);
            //std::cout << order << std::endl;
            Send(order);
            free(str);
        };
        return lambda;
    }

    void Send(Order &order)
    {
        if (order.type == "new_order")
        {
            logger.info("cgate: ORDER-GATEWAY Order NEW_ORDER, symbol=%s, exchange=%s, from=%s, price=%s, amount=%d, side=%d, ext_id=%d",
                        order.symbol.c_str(), order.exchange.c_str(), order.from.c_str(), order.price_str.c_str(),
                        order.amount, order.side, order.ext_id);
            auto res = SendNewOrder(order);
            //std::cout << "SendNewOrder Result " << res << std::endl;
        }
        else if (order.type == "cancel_order")
        {
            logger.info("cgate: ORDER-GATEWAY Order CANCEL_ORDER, order_id=%lld, from=%s",
                        order.order_id, order.from.c_str());
            auto res = SendCancelOrder(order);
            //std::cout << "CancelOrder Result " << res << std::endl;
        }
    }

    uint32_t GenerateUserId()
    {
        auto now = std::chrono::system_clock::now();
        auto duration = now.time_since_epoch();
        uint32_t millis = (uint32_t)std::chrono::duration_cast<std::chrono::seconds>(duration).count();
        //std::time_t now_c = std::chrono::system_clock::to_time_t(time_point);
        if (millis > current_user_id_)
        {
            current_user_id_ = millis;
        }
        else
        {
            current_user_id_++;
        }
        return current_user_id_;
    }

    CG_RESULT SendNewOrder(Order &order)
    {

        std::lock_guard<std::mutex> lockGuard(lock);

        if (order.exchange == "moex_forts")
        {
            struct MESSAGE_PUB::FutAddOrder *ord;
            struct cg_msg_data_t *msg;

            CG_RESULT res = CG_ERR_INTERNAL;
            res = cg_pub_msgnew(pub_, CG_KEY_NAME, "FutAddOrder", (struct cg_msg_t **)&msg);
            if (res != CG_ERR_OK)
            {
                return res;
            }
            //memcpy(msg->data, &counter, sizeof(counter));
            //msg->user_id = counter;
            msg->user_id = GenerateUserId();
            ord = (struct MESSAGE_PUB::FutAddOrder *)msg->data;
            memset(ord, 0, sizeof(struct MESSAGE_PUB::FutAddOrder));
            strcpy(ord->broker_code, broker_code_.c_str());
            strcpy(ord->client_code, client_code_.c_str());
            strcpy(ord->isin, order.symbol.c_str());
            strcpy(ord->comment, order.from.c_str());

            ord->type = 1;
            ord->dir = order.dir;
            ord->amount = order.amount;
            strcpy(ord->price, std::to_string((double)order.price / 1000000).c_str());
            ord->ext_id = order.ext_id;
            //ord->du = 0;
            //ord->dont_check_money = 1;

            res = cg_pub_post(pub_, (struct cg_msg_t *)msg, CG_PUB_NEEDREPLY);
            res = cg_pub_msgfree(pub_, (struct cg_msg_t *)msg);
            userid2Order.insert({msg->user_id, order});
            return res;
        }
        else if (order.exchange == "moex_opt")
        {
            //std::cout << "This is option order!!!!!!!!!!!" << std::endl;
            struct MESSAGE_PUB::OptAddOrder *ord;
            struct cg_msg_data_t *msg;

            CG_RESULT res = CG_ERR_INTERNAL;
            res = cg_pub_msgnew(pub_, CG_KEY_NAME, "OptAddOrder", (struct cg_msg_t **)&msg);
            if (res != CG_ERR_OK)
            {
                return res;
            }

            msg->user_id = GenerateUserId();
            ord = (struct MESSAGE_PUB::OptAddOrder *)msg->data;
            memset(ord, 0, sizeof(struct MESSAGE_PUB::OptAddOrder));
            strcpy(ord->broker_code, broker_code_.c_str());
            strcpy(ord->client_code, client_code_.c_str());
            strcpy(ord->isin, order.symbol.c_str());
            strcpy(ord->comment, order.from.c_str());
            ord->type = 1;
            ord->dir = order.dir;
            ord->amount = order.amount;
            strcpy(ord->price, std::to_string((double)order.price / 1000000).c_str());
            ord->ext_id = order.ext_id;
            res = cg_pub_post(pub_, (struct cg_msg_t *)msg, CG_PUB_NEEDREPLY);
            res = cg_pub_msgfree(pub_, (struct cg_msg_t *)msg);
            userid2Order.insert({msg->user_id, order});
            return res;
        }
        return -1;
    }

    CG_RESULT SendCancelOrder(Order &order)
    {
        std::lock_guard<std::mutex> lockGuard(lock);
        //std::cout << "SendCancelOrder exchange = " << order.exchange << std::endl;
        if (order.exchange == "moex_forts")
        {
            struct MESSAGE_PUB::FutDelOrder *ord;
            struct cg_msg_data_t *msg;
            CG_RESULT res = CG_ERR_INTERNAL;
            res = cg_pub_msgnew(pub_, CG_KEY_NAME, "FutDelOrder", (struct cg_msg_t **)&msg);
            if (res != CG_ERR_OK)
            {
                return res;
            }
            //memcpy(msg->data, &counter, sizeof(counter));
            //msg->user_id = counter;
            msg->user_id = GenerateUserId();
            ord = (struct MESSAGE_PUB::FutDelOrder *)msg->data;
            memset(ord, 0, sizeof(struct MESSAGE_PUB::FutDelOrder));
            strcpy(ord->broker_code, broker_code_.c_str());
            ord->order_id = order.order_id;

            res = cg_pub_post(pub_, (struct cg_msg_t *)msg, CG_PUB_NEEDREPLY);
            res = cg_pub_msgfree(pub_, (struct cg_msg_t *)msg);
            userid2Order.insert({msg->user_id, order});
            return res;
        }
        else if (order.exchange == "moex_opt")
        {
            //std::cout << "Try cancel !@@@@@@@@@@@@@@@@@@@@@ OPT" << std::endl;
            struct MESSAGE_PUB::OptDelOrder *ord;
            struct cg_msg_data_t *msg;
            CG_RESULT res = CG_ERR_INTERNAL;
            res = cg_pub_msgnew(pub_, CG_KEY_NAME, "OptDelOrder", (struct cg_msg_t **)&msg);
            if (res != CG_ERR_OK)
            {
                //std::cout << "cant' create msgnew" << std::endl;
                return res;
            }
            //memcpy(msg->data, &counter, sizeof(counter));
            //msg->user_id = counter;
            msg->user_id = GenerateUserId();
            ord = (struct MESSAGE_PUB::OptDelOrder *)msg->data;
            memset(ord, 0, sizeof(struct MESSAGE_PUB::OptDelOrder));
            strcpy(ord->broker_code, broker_code_.c_str());
            ord->order_id = order.order_id;

            res = cg_pub_post(pub_, (struct cg_msg_t *)msg, CG_PUB_NEEDREPLY);
            if (res != CG_ERR_OK)
            {
                //std::cout << "proble with post" << std::endl;
            }
            res = cg_pub_msgfree(pub_, (struct cg_msg_t *)msg);
            if (res != CG_ERR_OK)
            {
                //std::cout << "proble with free" << std::endl;
            }
            userid2Order.insert({msg->user_id, order});
            return res;
        }
        return -1;
    }

    template <typename S>
    void PrintReply(void *data)
    {
        S *t = (S *)data;
        std::cout << to_csv(*t) << std::endl;
        auto bson_ = to_bson(*t);
        size_t len;
        char *str = bson_as_canonical_extended_json(*bson_, &len);
        printf("%s\n", str);
    }

    //FutAdd
    void ReplyMSG101(void *data)
    {
        std::lock_guard<std::mutex> lockGuard(lock);
        struct cg_msg_data_t *replymsg = (struct cg_msg_data_t *)data;
        uint32_t user_id = (uint32_t)replymsg->user_id;
        if (userid2Order.count(user_id))
        {
            MESSAGE_PUB::FORTS_MSG101 *reply = (MESSAGE_PUB::FORTS_MSG101 *)replymsg->data;
            Order order = userid2Order[user_id];
            OrderReply orderReply;
            orderReply.type = "new_reply";
            orderReply.code = reply->code;
            orderReply.order_id = reply->order_id;
            orderReply.message = reply->message;
            orderReply.ext_id = order.ext_id;
            orderReply.to = order.from;
            userid2Order.erase(user_id);
            responder_->Down(orderReply);
        }
        else
        {
            logger.error("ReplyMSG101 can't find user_id %u", user_id);
            //throw "ReplyMSG101 can't find user_id";
        }
    }

    //FutDel
    void ReplyMSG102(void *data)
    {
        std::lock_guard<std::mutex> lockGuard(lock);
        struct cg_msg_data_t *replymsg = (struct cg_msg_data_t *)data;
        uint32_t user_id = (uint32_t)replymsg->user_id;
        if (userid2Order.count(user_id))
        {
            auto order = userid2Order[user_id];
            MESSAGE_PUB::FORTS_MSG102 *reply = (MESSAGE_PUB::FORTS_MSG102 *)replymsg->data;
            //responder_->Reply<MESSAGE_PUB::FORTS_MSG102>(data, order);
            OrderReply orderReply;
            orderReply.type = "cancel_reply";
            orderReply.code = reply->code;
            orderReply.amount = reply->amount;
            orderReply.message = reply->message;
            orderReply.order_id = order.order_id;
            orderReply.to = order.from;
            userid2Order.erase(user_id);
            responder_->Down(orderReply);
        }
        else
        {
            logger.error("ReplyMSG102 can't find user_id %u", user_id);
            //throw "ReplyMSG102 can't find user_id";
        }
    }

    //FutDelUser
    void ReplyMSG103(void *data)
    {
        std::lock_guard<std::mutex> lockGuard(lock);
        MESSAGE_PUB::FORTS_MSG103 *reply = (MESSAGE_PUB::FORTS_MSG103 *)data;
        //responder_->Down<MESSAGE_PUB::FORTS_MSG103>(data);
        responder_->Down(*reply);
    }

    //FutMove
    void ReplyMSG105(void *data)
    {
        std::lock_guard<std::mutex> lockGuard(lock);
        MESSAGE_PUB::FORTS_MSG105 *reply = (MESSAGE_PUB::FORTS_MSG105 *)data;
        responder_->Down(*reply);
    }

    //OptAdd
    void ReplyMSG109(void *data)
    {
        //std::cout << "ReplyMSG109############################" << std::endl;
        std::lock_guard<std::mutex> lockGuard(lock);
        //responder_->Reply<MESSAGE_PUB::FORTS_MSG109>(data);

        struct cg_msg_data_t *replymsg = (struct cg_msg_data_t *)data;
        uint32_t user_id = (uint32_t)replymsg->user_id;
        if (userid2Order.count(user_id))
        {
            //std::cout << "received!!!!!!!!!!!!!!!!!!!" << std::endl;
            MESSAGE_PUB::FORTS_MSG109 *reply = (MESSAGE_PUB::FORTS_MSG109 *)replymsg->data;
            Order order = userid2Order[user_id];
            OrderReply orderReply;
            orderReply.type = "new_reply";
            orderReply.code = reply->code;
            orderReply.order_id = reply->order_id;
            orderReply.message = reply->message;
            orderReply.ext_id = order.ext_id;
            orderReply.to = order.from;
            userid2Order.erase(user_id);
            responder_->Down(orderReply);
        }
        else
        {
            logger.error("ReplyMSG109 can't find user_id %u", user_id);
            //throw "ReplyMSG101 can't find user_id";
        }
    }

    //OptDel
    void ReplyMSG110(void *data)
    {
        //std::lock_guard<std::mutex> lockGuard(lock);
        //responder_->Reply<MESSAGE_PUB::FORTS_MSG110>(data);
        std::lock_guard<std::mutex> lockGuard(lock);
        struct cg_msg_data_t *replymsg = (struct cg_msg_data_t *)data;
        uint32_t user_id = (uint32_t)replymsg->user_id;
        if (userid2Order.count(user_id))
        {
            auto order = userid2Order[user_id];
            MESSAGE_PUB::FORTS_MSG110 *reply = (MESSAGE_PUB::FORTS_MSG110 *)replymsg->data;
            //responder_->Reply<MESSAGE_PUB::FORTS_MSG102>(data, order);
            OrderReply orderReply;
            orderReply.type = "cancel_reply";
            orderReply.code = reply->code;
            orderReply.amount = reply->amount;
            orderReply.message = reply->message;
            orderReply.order_id = order.order_id;
            orderReply.to = order.from;
            userid2Order.erase(user_id);
            responder_->Down(orderReply);
        }
        else
        {
            logger.error("ReplyMSG110 can't find user_id %u", user_id);
            //throw "ReplyMSG102 can't find user_id";
        }
    }

    //OptDelUserOrders
    void ReplyMSG111(void *data)
    {
        std::lock_guard<std::mutex> lockGuard(lock);
        MESSAGE_PUB::FORTS_MSG111 *reply = (MESSAGE_PUB::FORTS_MSG111 *)data;
        responder_->Down(*reply);
    }

    //OptMove
    void ReplyMSG113(void *data)
    {
        std::lock_guard<std::mutex> lockGuard(lock);
        MESSAGE_PUB::FORTS_MSG113 *reply = (MESSAGE_PUB::FORTS_MSG113 *)data;
        responder_->Down(*reply);
    }

    void ReplyCODHeartbeat(void *data)
    {
        std::lock_guard<std::mutex> lockGuard(lock);
        //PrintReply<MESSAGE_PUB::FORTS_MSG101>(data);
        MESSAGE_PUB::CODHeartbeat *reply = (MESSAGE_PUB::CODHeartbeat *)data;
        responder_->Down(*reply);
    }

    //FludControl
    void ReplyMSG99(void *data)
    {
        //std::lock_guard<std::mutex> lockGuard(lock);
        //responder_->Reply<MESSAGE_PUB::FORTS_MSG99>(data);

        std::lock_guard<std::mutex>
            lockGuard(lock);
        struct cg_msg_data_t *replymsg = (struct cg_msg_data_t *)data;
        uint32_t user_id = (uint32_t)replymsg->user_id;
        printf("spam reply user_id = %u\n", user_id);
        if (userid2Order.count(user_id))
        {
            MESSAGE_PUB::FORTS_MSG99 *reply = (MESSAGE_PUB::FORTS_MSG99 *)replymsg->data;
            //std::cout << "penalty remain " << reply->penalty_remain << std::endl;
            //std::cout << "queue_size     " << reply->queue_size << std::endl;

            Order order = userid2Order[user_id];
            SpamReply spamReply;
            spamReply.message = reply->message;
            //std::cout << order << std::endl;
            spamReply.order_id = order.order_id;
            spamReply.ext_id = order.ext_id;
            spamReply.to = order.from;
            spamReply.penalty_remain = reply->penalty_remain;
            spamReply.queue_size = reply->queue_size;
            userid2Order.erase(user_id);
            responder_->Down(spamReply);
        }
        else
        {
            logger.error("ReplyMSG101 can't find user_id %u", user_id);
            //throw "ReplyMSG101 can't find user_id";
        }
    }

    //SystemError
    void ReplyMSG100(void *data)
    {
        std::lock_guard<std::mutex> lockGuard(lock);
        MESSAGE_PUB::FORTS_MSG100 *reply = (MESSAGE_PUB::FORTS_MSG100 *)data;
        responder_->Down(*reply);
    }

    std::function<void(void *)> GetHandler(std::string msg_name)
    {
        if (msg_name == "FORTS_MSG101")
        {
            return [this](void *data) {
                this->ReplyMSG101(data);
            };
        }
        else if (msg_name == "FORTS_MSG102")
        {
            return [this](void *data) {
                this->ReplyMSG102(data);
            };
        }
        else if (msg_name == "FORTS_MSG103")
        {
            return [this](void *data) {
                this->ReplyMSG103(data);
            };
        }
        else if (msg_name == "FORTS_MSG105")
        {
            return [this](void *data) {
                this->ReplyMSG105(data);
            };
        }
        else if (msg_name == "FORTS_MSG109")
        {
            return [this](void *data) {
                this->ReplyMSG109(data);
            };
        }
        else if (msg_name == "FORTS_MSG110")
        {
            return [this](void *data) {
                this->ReplyMSG110(data);
            };
        }
        else if (msg_name == "FORTS_MSG111")
        {
            return [this](void *data) {
                this->ReplyMSG111(data);
            };
        }
        else if (msg_name == "FORTS_MSG113")
        {
            return [this](void *data) {
                this->ReplyMSG113(data);
            };
        }
        else if (msg_name == "CODHeartbeat")
        {
            return [this](void *data) {
                this->ReplyCODHeartbeat(data);
            };
        }
        else if (msg_name == "FORTS_MSG99")
        {
            return [this](void *data) {
                this->ReplyMSG99(data);
            };
        }
        else if (msg_name == "FORTS_MSG100")
        {
            return [this](void *data) {
                this->ReplyMSG100(data);
            };
        }
        throw "unknown message";
    }
};
#endif // !__PUBLISHER_HEADER__

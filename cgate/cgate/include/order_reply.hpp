#ifndef __ORDER_REPLY__
#define __ORDER_REPLY__
#include <string>
#include <stdio.h>
#include <iostream>
#include <mongoc.h>

struct OrderReply
{
    std::string type;
    int32_t code{0};
    std::string message{""};
    uint32_t amount{0};
    uint64_t order_id{0};
    int32_t ext_id{0};
    std::string from{""};
    std::string to{""};

    OrderReply()
    {
    }

    OrderReply(char *buffer, int len)
    {
        bson_t *doc;
        doc = bson_new_from_data((uint8_t *)buffer, len);
        fromBSON(doc);
        bson_destroy(doc);
    }

    bson_t *toBSON()
    {
        bson_t *doc;
        if (type == "new_reply")
        {
            doc = BCON_NEW(
                "type", BCON_UTF8(type.c_str()),
                "code", BCON_UTF8(std::to_string(code).c_str()),
                "message", BCON_UTF8(message.c_str()),
                "to", BCON_UTF8(to.c_str()),
                "order_id", BCON_UTF8(std::to_string(order_id).c_str()),
                "ext_id", BCON_UTF8(std::to_string(ext_id).c_str()));
        }
        else if (type == "cancel_reply")
        {
            doc = BCON_NEW(
                "type", BCON_UTF8(type.c_str()),
                "code", BCON_UTF8(std::to_string(code).c_str()),
                "message", BCON_UTF8(message.c_str()),
                "to", BCON_UTF8(to.c_str()),
                "amount", BCON_UTF8(std::to_string(amount).c_str()),
                "order_id", BCON_UTF8(std::to_string(order_id).c_str()));
        }
        return doc;
    }

    void fromBSON(bson_t *doc)
    {

        bson_iter_t iter;
        uint32_t len;

        if (bson_iter_init(&iter, doc) &&
            bson_iter_find(&iter, "type"))
        {
            type = bson_iter_utf8(&iter, &len);
        }
        else
        {
            throw "can't find type for order in BSON object";
        }

        if (type == "new_reply")
        {
            if (bson_iter_init(&iter, doc))
            {
                while (bson_iter_next(&iter))
                {
                    if (strcmp(bson_iter_key(&iter), "code") == 0)
                    {
                        code = std::stoi(bson_iter_utf8(&iter, &len));
                    }

                    if (strcmp(bson_iter_key(&iter), "message") == 0)
                    {
                        message = bson_iter_utf8(&iter, &len);
                    }
                    //printf("Found sub-key of \"foo\" named \"%s\", value = %s\n", bson_iter_key(&child), bson_iter_utf8(&child, &len));
                    if (strcmp(bson_iter_key(&iter), "order_id") == 0)
                    {
                        amount = std::stold(bson_iter_utf8(&iter, &len));
                    }

                    if (strcmp(bson_iter_key(&iter), "ext_id") == 0)
                    {
                        code = std::stoi(bson_iter_utf8(&iter, &len));
                    }
                }
            }
        }
        else if (type == "cancel_order")
        {
            if (bson_iter_init(&iter, doc))
            {
                while (bson_iter_next(&iter))
                {
                    if (strcmp(bson_iter_key(&iter), "code") == 0)
                    {
                        code = std::stod(bson_iter_utf8(&iter, &len));
                    }

                    if (strcmp(bson_iter_key(&iter), "message") == 0)
                    {
                        message = bson_iter_utf8(&iter, &len);
                    }
                    //printf("Found sub-key of \"foo\" named \"%s\", value = %s\n", bson_iter_key(&child), bson_iter_utf8(&child, &len));
                    if (strcmp(bson_iter_key(&iter), "amount") == 0)
                    {
                        amount = std::stoi(bson_iter_utf8(&iter, &len));
                    }

                    if (strcmp(bson_iter_key(&iter), "order_id") == 0)
                    {
                        amount = std::stold(bson_iter_utf8(&iter, &len));
                    }
                }
            }
        }
    }
};

std::ostream &operator<<(std::ostream &os, const OrderReply &reply)
{
    if (reply.type == "new_reply")
    {
        os << "new_reply: "
           << " code=" << reply.code
           << " message=" << reply.message
           << " order_id=" << reply.order_id << std::endl;
    }
    else if (reply.type == "cancel_reply")
    {
        os << "cancel_reply: "
           << " code=" << reply.code
           << " message=" << reply.message
           << " amount=" << reply.amount << std::endl;
    }

    return os;
}

struct SpamReply
{
    std::string type{"spam_reply"};
    std::string message{""};
    int32_t penalty_remain;
    int32_t queue_size;
    std::string to{""};
    int32_t ext_id{0};
    int64_t order_id{0};

    SpamReply()
    {
    }

    SpamReply(char *buffer, int len)
    {
        bson_t *doc;
        doc = bson_new_from_data((uint8_t *)buffer, len);
        fromBSON(doc);
        bson_destroy(doc);
    }

    bson_t *toBSON()
    {
        bson_t *doc;

        doc = BCON_NEW(
            "type", BCON_UTF8(type.c_str()),
            "message", BCON_UTF8(message.c_str()),
            "to", BCON_UTF8(to.c_str()),
            "penalty_remain", BCON_UTF8(std::to_string(penalty_remain).c_str()),
            "ext_id", BCON_UTF8(std::to_string(ext_id).c_str()),
            "order_id", BCON_UTF8(std::to_string(order_id).c_str()),
            "queue_size", BCON_UTF8(std::to_string(queue_size).c_str()));

        return doc;
    }

    void fromBSON(bson_t *doc)
    {

        bson_iter_t iter;
        uint32_t len;

        if (bson_iter_init(&iter, doc) &&
            bson_iter_find(&iter, "type"))
        {
            type = bson_iter_utf8(&iter, &len);
        }
        else
        {
            throw "can't find type for order in BSON object";
        }

        if (bson_iter_init(&iter, doc))
        {
            while (bson_iter_next(&iter))
            {
                if (strcmp(bson_iter_key(&iter), "penalty_remain") == 0)
                {
                    penalty_remain = std::stoi(bson_iter_utf8(&iter, &len));
                }

                if (strcmp(bson_iter_key(&iter), "queue_size") == 0)
                {
                    queue_size = std::stoi(bson_iter_utf8(&iter, &len));
                }

                if (strcmp(bson_iter_key(&iter), "message") == 0)
                {
                    message = bson_iter_utf8(&iter, &len);
                }
                if (strcmp(bson_iter_key(&iter), "ext_id") == 0)
                {
                    ext_id = std::stoi(bson_iter_utf8(&iter, &len));
                }
                if (strcmp(bson_iter_key(&iter), "order_id") == 0)
                {
                    order_id = std::stol(bson_iter_utf8(&iter, &len));
                }
            }
        }
    }
};

std::ostream &operator<<(std::ostream &os, const SpamReply &reply)
{

    os << "spam_reply: "
       << " penalty_remain=" << reply.penalty_remain
       << " queue_size=" << reply.queue_size
       << " message=" << reply.message << std::endl;

    return os;
}

#endif
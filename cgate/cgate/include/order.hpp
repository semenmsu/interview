#ifndef __ORDER_HEADER__
#define __ORDER_HEADER__

#include <stdio.h>
#include <iostream>
#include <zmq.h>
#include <string>
#include <string.h>
#include <unistd.h>
#include <thread>
#include <mongoc.h>
#include <cstdlib>
#include <cstring>

struct Order
{

    Order()
    {
    }

    Order(const bson_t *doc)
    {
        InitFromBSON(doc);
    }

    Order(char *buffer, int len)
    {
        bson_t *doc;
        doc = bson_new_from_data((uint8_t *)buffer, len);
        InitFromBSON(doc);
        bson_destroy(doc);
    }
    std::string from;
    std::string type;
    std::string symbol;
    std::string exchange{""};
    int64_t price{0};
    std::string price_str;
    int32_t amount{0};
    int32_t side{0};
    int32_t dir{0};
    int32_t ext_id{0};
    int64_t order_id{0};
    char oidstr[25];

    void InitFromBSON(const bson_t *doc)
    {
        bson_iter_t iter;
        bson_iter_t child;
        uint32_t len;
        const bson_oid_t *oid;
        if (bson_iter_init(&iter, doc) &&
            bson_iter_find_descendant(&iter, "fullDocument._id", &child) &&
            BSON_ITER_HOLDS_OID(&child))
        {
            oid = bson_iter_oid(&child);
            bson_oid_to_string(oid, oidstr);
            //printf("oid = %s\n", oidstr);
        }

        if (bson_iter_init(&iter, doc) &&
            bson_iter_find_descendant(&iter, "fullDocument.type", &child))
        {
            type = bson_iter_utf8(&child, &len);
        }
        else
        {
            throw "can't find type for order in BSON object";
        }

        if (bson_iter_init(&iter, doc) &&
            bson_iter_find_descendant(&iter, "fullDocument.from", &child))
        {
            from = bson_iter_utf8(&child, &len);
        }
        else
        {
            throw "can't find from who this order in BSON object";
        }

        if (type == "new_order")
        {
            if (bson_iter_init_find(&iter, doc, "fullDocument") &&
                BSON_ITER_HOLDS_DOCUMENT(&iter) && bson_iter_recurse(&iter, &child))
            {
                while (bson_iter_next(&child))
                {
                    if (strcmp(bson_iter_key(&child), "symbol") == 0)
                    {
                        symbol = bson_iter_utf8(&child, &len);
                    }

                    if (strcmp(bson_iter_key(&child), "exchange") == 0)
                    {
                        exchange = bson_iter_utf8(&child, &len);
                    }

                    if (strcmp(bson_iter_key(&child), "from") == 0)
                    {
                        from = bson_iter_utf8(&child, &len);
                    }

                    if (strcmp(bson_iter_key(&child), "price") == 0)
                    {
                        price = std::stold(bson_iter_utf8(&child, &len));
                        price_str = bson_iter_utf8(&child, &len);
                    }

                    //printf("Found sub-key of \"foo\" named \"%s\", value = %s\n", bson_iter_key(&child), bson_iter_utf8(&child, &len));
                    if (strcmp(bson_iter_key(&child), "amount") == 0)
                    {
                        amount = std::stoi(bson_iter_utf8(&child, &len));
                    }

                    if (strcmp(bson_iter_key(&child), "dir") == 0)
                    {
                        side = std::stoi(bson_iter_utf8(&child, &len));
                        dir = std::stoi(bson_iter_utf8(&child, &len));
                    }

                    if (strcmp(bson_iter_key(&child), "ext_id") == 0)
                    {
                        ext_id = std::stoi(bson_iter_utf8(&child, &len));
                    }
                }
            }
        }
        else if (type == "cancel_order")
        {
            if (bson_iter_init_find(&iter, doc, "fullDocument") &&
                BSON_ITER_HOLDS_DOCUMENT(&iter) && bson_iter_recurse(&iter, &child))
            {
                while (bson_iter_next(&child))
                {
                    if (strcmp(bson_iter_key(&child), "order_id") == 0)
                    {
                        order_id = std::stold(bson_iter_utf8(&child, &len));
                    }

                    if (strcmp(bson_iter_key(&child), "exchange") == 0)
                    {
                        exchange = bson_iter_utf8(&child, &len);
                    }
                }
            }
        }

        //
    }
};

std::ostream &operator<<(std::ostream &os, const Order &order)
{
    if (order.type == "new_order")
    {
        os << "from=" << order.from
           << " symbol=" << order.symbol
           << " type=" << order.type
           << " price=" << order.price
           << " amount=" << order.amount
           << " oid=" << order.oidstr;
    }
    else if (order.type == "cancel_order")
    {
        os << "from=" << order.from
           << " type=" << order.type
           << " order_id=" << order.order_id
           << " oid=" << order.oidstr;
    }

    return os;
}

#endif // !__ORDER_HEADER__
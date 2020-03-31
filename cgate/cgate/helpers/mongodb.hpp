#ifndef ___MONGODB_HEADER__
#define ___MONGODB_HEADER__

#include <mongoc.h>
#include <functional>
#include <map>
#include <functional>
#include <memory>
#include <ctime>
#include "../include/logger.h"
#include "./smart_session_storage.hpp"
//typedef void (*__change_stream_callback)(const bson_t &doc);

template <typename T>
T FindBsonField(bson_iter_t *iter, std::string name)
{
}

template <>
std::string FindBsonField(bson_iter_t *iter, std::string name)
{

    uint32_t len;
    if (bson_iter_find(iter, name.c_str()))
    {
        //std::cout << bson_iter_utf8(iter, &len) << std::endl;
        return bson_iter_utf8(iter, &len);
    }
    return "";
}

template <>
int32_t FindBsonField(bson_iter_t *iter, std::string name)
{

    uint32_t len;
    if (bson_iter_find(iter, name.c_str()))
    {
        //std::cout << bson_iter_utf8(iter, &len) << std::endl;
        return std::stoi(bson_iter_utf8(iter, &len));
    }
    return 0;
}

void GetBsonObjectValueIterFromCurrentIter(bson_iter_t &current_iter, bson_iter_t &value_iter)
{
    bson_iter_recurse(&current_iter, &value_iter);
}

void GetValueIter(bson_iter_t &current_iter, bson_iter_t &value_iter)
{
    bson_iter_recurse(&current_iter, &value_iter);
}

bool NextIter(bson_iter_t &iter)
{
    return bson_iter_next(&iter);
}

bool GetArray(bson_iter_t &iter, const bson_t *doc, std::string array_name)
{
    return (bson_iter_init_find(&iter, doc, array_name.c_str()) &&
            BSON_ITER_HOLDS_ARRAY(&iter));
}

template <typename T>
T GetFieldOfIterValue(bson_iter_t &iter, std::string field_name)
{
    bson_iter_t child;
    GetValueIter(iter, child);
    return FindBsonField<T>(&child, field_name.c_str());
}

typedef std::function<void(const bson_t &doc)> __change_stream_callback;
struct MongoInitializer
{
    MongoInitializer()
    {
        mongoc_init();
    }
    ~MongoInitializer()
    {
        mongoc_cleanup();
    }
};

struct MongoClient
{
    mongoc_client_t *client_{0};
    std::string url_;
    mongoc_uri_t *uri_;

    MongoClient(std::string url)
    {
        url_ = url;
        bson_error_t error;
        uri_ = mongoc_uri_new_with_error(url_.c_str(), &error);
        client_ = mongoc_client_new_from_uri(uri_);
    }

    ~MongoClient()
    {
        //std::cout << "~MongoClient" << std::endl;
        if (uri_)
        {
            //mongoc_uri
            mongoc_uri_destroy(uri_);
        }
        if (client_)
        {
            mongoc_client_destroy(client_);
        }
    }
};

/*
class MongodbCollection
{
  public:
    MongodbCollection(std::string mongodb_url,
                      std::string db_name,
                      std::string collection_name) : mongodb_url(mongodb_url),
                                                     db_name(db_name),
                                                     collection_name(collection_name)
    {
    }

    int Init()
    {
        bson_error_t error;
        uri = mongoc_uri_new_with_error(mongodb_url.c_str(), &error);
        client = mongoc_client_new_from_uri(uri);
        collection = mongoc_client_get_collection(client, db_name.c_str(), collection_name.c_str());
    }

    int InsertOne(bson_t *doc)
    {
        bson_t reply;
        bson_error_t error;

        if (collection)
        {
            if (!mongoc_collection_insert_one(collection, doc, NULL, &reply, &error))
            {
                logger.error("mongodb: TRADES mongoclient collection insert error %s \n", error.message);
                return -1;
            }
        }
        return 0;
    }

    ~MongodbCollection()
    {
        if (collection)
        {
            mongoc_collection_destroy(collection);
        }
        if (client)
        {
            mongoc_client_destroy(client);
        }
        if (uri)
        {
            mongoc_uri_destroy(uri);
        }
    }

  private:
    std::string mongodb_url;
    std::string collection_name;
    std::string db_name;
    mongoc_collection_t *collection;
    mongoc_uri_t *uri;
    mongoc_client_t *client;
};*/

struct MongoChangeStream
{

    MongoClient *client_{0};
    std::string db_name_;
    std::string collection_name_;

    MongoChangeStream(MongoClient &client, std::string db_name, std::string collection_name)
    {
        client_ = &client;
        db_name_ = db_name;
        collection_name_ = collection_name;
    }

    //callback
    int Watch(std::string to, __change_stream_callback callback)
    {
        logger.info("cgate: ORDER-GATEWAY start watch mongodb collection %s", collection_name_.c_str());
        bson_error_t error;
        const bson_t *doc;
        const bson_t *err_doc;
        bson_iter_t iter;
        bson_iter_t iter2;
        bson_iter_t child;
        bson_t *ops = BCON_NEW("maxAwaitTimeMS", BCON_INT32(2000));
        bson_t *pipeline = BCON_NEW("pipeline",
                                    "[",
                                    "{",
                                    "$match",
                                    "{",
                                    "fullDocument.to",
                                    BCON_UTF8(to.c_str()),
                                    "}",
                                    "}",
                                    "]");

        mongoc_client_set_appname(client_->client_, "order-gateway-listener");
        mongoc_collection_t *collection = mongoc_client_get_collection(client_->client_, db_name_.c_str(),
                                                                       collection_name_.c_str());
        mongoc_change_stream_t *stream;
        stream = mongoc_collection_watch(collection, pipeline, ops);
        int error_code = 0;
        while (true)
        {
            while (mongoc_change_stream_next(stream, &doc))
            {
                callback(*doc);
            }

            if (mongoc_change_stream_error_document(stream, &error, &err_doc))
            {
                if (!bson_empty(err_doc))
                {
                    logger.error("cgate: ORDER-GATEWAY Server Error %s", bson_as_relaxed_extended_json(err_doc, NULL));
                }
                else
                {
                    error_code = -1;
                    logger.error("cgate: ORDER-GATEWAY Client Error %s", error.message);
                    break;
                }
                sleep(5);
            }
        }

    mongocleanup:
        bson_destroy(pipeline);
        bson_destroy(ops);
        mongoc_change_stream_destroy(stream);
        mongoc_collection_destroy(collection);
        logger.info("cgate: ORDER-GATEWAY stop watch mongodb collection %s", collection_name_.c_str());
        return error_code;
    }

    ~MongoChangeStream()
    {
    }
};

struct MongoCollection
{

    MongoClient *client_{0};
    std::string db_name_;
    std::string collection_name_;
    mongoc_collection_t *collection_;

    MongoCollection(MongoClient &client, std::string db_name, std::string collection_name)
    {
        client_ = &client;
        db_name_ = db_name;
        collection_name_ = collection_name;
        collection_ = mongoc_client_get_collection(client.client_,
                                                   db_name_.c_str(), collection_name_.c_str());
    }

    int InsertOne(bson_t *doc)
    {
        bson_t reply;
        bson_error_t error;

        if (collection_)
        {
            if (!mongoc_collection_insert_one(collection_, doc, NULL, &reply, &error))
            {
                logger.error("mongodb: InsertOne mongoclient collection insert error %s \n", error.message);
                return -1;
            }
        }
        return 0;
    }

    int ReplaceOne(bson_t *doc, std::string selector_name, std::string selector_value)
    {
        bson_t reply;
        bson_error_t error;
        bson_t *selector = BCON_NEW(selector_name.c_str(), selector_value.c_str());
        bson_t *opts = BCON_NEW("upsert", BCON_BOOL(1));
        std::time_t t = std::time(nullptr);
        char mbstr[100];
        if (std::strftime(mbstr, sizeof(mbstr), "%A %c", std::localtime(&t)))
        {
            //std::cout << mbstr << '\n';
        }
        BSON_APPEND_UTF8(doc, "time", mbstr);
        if (collection_)
        {
            if (!mongoc_collection_replace_one(collection_, selector, doc, opts, &reply, &error))
            {
                logger.error("mongodb: ReplaceOne mongoclient %s\n", error.message);
                return -1;
            }
        }
        return 0;
    }

    auto FindOne(std::string selector_name, std::string selector_value)
    {
        bson_t *filter;
        bson_t *opts;
        mongoc_cursor_t *cursor;
        bson_error_t error;
        const bson_t *doc;
        bson_t *result;
        char *str;

        /* filter by "foo": 1, order by "bar" descending */
        filter = BCON_NEW(selector_name.c_str(), selector_value.c_str());
        opts = BCON_NEW(
            "limit", BCON_INT64(1));

        cursor = mongoc_collection_find_with_opts(collection_, filter, opts, NULL);

        /*while (mongoc_cursor_next(cursor, &doc))
        {
            str = bson_as_canonical_extended_json(doc, NULL);
            printf("%s\n", str);
            bson_free(str);
        }*/
        if (mongoc_cursor_next(cursor, &doc))
        {
            result = bson_copy(doc);
            //str = bson_as_canonical_extended_json(doc, NULL);
            //printf("%s\n", str);
            //bson_free(str);
        }

        if (mongoc_cursor_error(cursor, &error))
        {
            fprintf(stderr, "An error occurred: %s\n", error.message);
        }

        mongoc_cursor_destroy(cursor);
        bson_destroy(filter);
        bson_destroy(opts);
        return std::make_unique<bson_t *>(result);
    }

    int64_t GetLastRevision()
    {
        bson_error_t error;
        const bson_t *doc;
        //mongoc_uri_t *uri = mongoc_uri_new_with_error(mongodb_url.c_str(), &error);
        //mongoc_client_t *client = mongoc_client_new_from_uri(uri);
        //mongoc_collection_t *collection = mongoc_client_get_collection(client, "test", "trades");
        //opts = BCON_NEW("limit", BCON_INT64(1), "sort", "{", "sess_id", BCON_INT32(-1), "}");
        const bson_t *filter = BCON_NEW(NULL);
        //const bson_t *opts = BCON_NEW("limit", BCON_INT64(1), "sort", "{", "_id", BCON_INT32(-1), "}");
        const bson_t *opts = BCON_NEW("limit", BCON_INT64(1), "sort", "{", "replRev", BCON_INT32(-1), "}");
        mongoc_cursor_t *cursor = mongoc_collection_find_with_opts(collection_, filter, opts, NULL);
        int64_t rev = 0;
        int32_t lifenum = 0;
        int32_t sess_id = 0;
        if (mongoc_cursor_next(cursor, &doc))
        {
            bson_iter_t iter;
            uint32_t len;
            if (bson_iter_init_find(&iter, doc, "replRev"))
            {
                rev = std::stold(bson_iter_utf8(&iter, &len));
            }

            //if (bson_iter_init_find(&iter, doc, "lifenum"))
            //{
            //    lifenum = std::stoi(bson_iter_utf8(&iter, &len));
            //}

            //if (bson_iter_init_find(&iter, doc, "sess_id"))
            //{
            //    sess_id = std::stoi(bson_iter_utf8(&iter, &len));
            //}
            //logger.info("cgate: TRADES last trade from db revision = %d, lifenum = %ld, sess_id = %d", rev, lifenum, sess_id);
        }
        else
        {
            std::cout << "no trades" << std::endl;
            logger.info("cgate: TRADES NO trades from db revision = %d, lifenum = %ld, sess_id = %d", rev, lifenum, sess_id);
        }
        mongoc_cursor_destroy(cursor);
        return rev;
        //mongoc_collection_destroy(collection);
        //mongoc_client_destroy(client);
        //mongoc_uri_destroy(uri);
    }

    int64_t GetLastRevision(std::string exchange_name)
    {
        bson_error_t error;
        const bson_t *doc;
        //mongoc_uri_t *uri = mongoc_uri_new_with_error(mongodb_url.c_str(), &error);
        //mongoc_client_t *client = mongoc_client_new_from_uri(uri);
        //mongoc_collection_t *collection = mongoc_client_get_collection(client, "test", "trades");
        //opts = BCON_NEW("limit", BCON_INT64(1), "sort", "{", "sess_id", BCON_INT32(-1), "}");
        const bson_t *filter = BCON_NEW("exchange", exchange_name.c_str());
        //const bson_t *opts = BCON_NEW("limit", BCON_INT64(1), "sort", "{", "_id", BCON_INT32(-1), "}");
        const bson_t *opts = BCON_NEW("limit", BCON_INT64(1), "sort", "{", "replRev", BCON_INT32(-1), "}");
        mongoc_cursor_t *cursor = mongoc_collection_find_with_opts(collection_, filter, opts, NULL);
        int64_t rev = 0;
        int32_t lifenum = 0;
        int32_t sess_id = 0;
        if (mongoc_cursor_next(cursor, &doc))
        {
            bson_iter_t iter;
            uint32_t len;
            if (bson_iter_init_find(&iter, doc, "replRev"))
            {
                rev = std::stold(bson_iter_utf8(&iter, &len));
            }

            //if (bson_iter_init_find(&iter, doc, "lifenum"))
            //{
            //    lifenum = std::stoi(bson_iter_utf8(&iter, &len));
            //}

            //if (bson_iter_init_find(&iter, doc, "sess_id"))
            //{
            //    sess_id = std::stoi(bson_iter_utf8(&iter, &len));
            //}
            //logger.info("cgate: TRADES last trade from db revision = %d, lifenum = %ld, sess_id = %d", rev, lifenum, sess_id);
        }
        else
        {
            std::cout << "no trades" << std::endl;
            logger.info("cgate: TRADES NO trades from db revision = %d, lifenum = %ld, sess_id = %d", rev, lifenum, sess_id);
        }
        mongoc_cursor_destroy(cursor);
        return rev;
        //mongoc_collection_destroy(collection);
        //mongoc_client_destroy(client);
        //mongoc_uri_destroy(uri);
    }

    int32_t GetLastLifenum(std::string stream_name)
    {
        //std::cout << "GET LASST LIFENUM !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;
        bson_error_t error;
        const bson_t *doc;
        //mongoc_uri_t *uri = mongoc_uri_new_with_error(mongodb_url.c_str(), &error);
        //mongoc_client_t *client = mongoc_client_new_from_uri(uri);
        //mongoc_collection_t *collection = mongoc_client_get_collection(client, "test", "trades");
        //opts = BCON_NEW("limit", BCON_INT64(1), "sort", "{", "sess_id", BCON_INT32(-1), "}");
        //const bson_t *filter = BCON_NEW(NULL);
        const bson_t *filter = BCON_NEW("stream", stream_name.c_str());
        //const bson_t *opts = BCON_NEW("limit", BCON_INT64(1), "sort", "{", "_id", BCON_INT32(-1), "}");
        const bson_t *opts = BCON_NEW("limit", BCON_INT64(1), "sort", "{", "_id", BCON_INT32(-1), "}");
        mongoc_cursor_t *cursor = mongoc_collection_find_with_opts(collection_, filter, opts, NULL);

        int32_t lifenum = 0;

        if (mongoc_cursor_next(cursor, &doc))
        {
            bson_iter_t iter;
            uint32_t len;
            if (bson_iter_init_find(&iter, doc, "lifenum"))
            {
                lifenum = std::stoi(bson_iter_utf8(&iter, &len));
                //std::cout << "FIND LIFENUM " << lifenum << std::endl;
            }
        }
        else
        {
            logger.info("cgate: lifenum = %ld", lifenum);
        }
        mongoc_cursor_destroy(cursor);
        return lifenum;
        //mongoc_collection_destroy(collection);
        //mongoc_client_destroy(client);
        //mongoc_uri_destroy(uri);
    }

    ~MongoCollection()
    {
        if (collection_)
        {
            mongoc_collection_destroy(collection_);
        }
    }
};

struct FortsSessionInfo
{
    std::map<int32_t, std::string> isinid2symbol;
    std::map<std::string, int32_t> symbol2isinid;

    FortsSessionInfo(std::string url)
    {
        MongoClient client(url);
        MongoCollection coll(client, "info", "instruments");
        std::string exchanges[]{"moex_forts", "moex_opt"};
        for (auto &exchange : exchanges)
        {
            auto _bson = coll.FindOne("exchange", exchange.c_str());
            ;
            bson_iter_t iter;
            bson_iter_t child;
            if (GetArray(iter, (const bson_t *)*_bson, "instruments"))
            {
                GetValueIter(iter, child);
                while (NextIter(child))
                {
                    auto symbol = GetFieldOfIterValue<std::string>(child, "symbol");
                    auto isin_id = GetFieldOfIterValue<int32_t>(child, "isin_id");
                    //std::cout << symbol << " " << isin_id << std::endl;
                    isinid2symbol.insert({isin_id, symbol});
                    symbol2isinid.insert({symbol, isin_id});
                }
            }
        }
    }
};

//template <class T>
//constexpr enable_if_t<HasHandler<T>::value, bool>
struct SmartMongoStream
{
    MongoClient *client_;
    MongoCollection *collection_;
    std::string gateway_name_{"gw-cgate"};
    SmartSessionStorage *sessionStorage_;

    SmartMongoStream(SmartSessionStorage &sessionStorage, std::map<std::string, std::string> &settings)
    {
        sessionStorage_ = &sessionStorage;
        std::string url = settings["url"];

        std::string db_name = settings["db_name"];
        std::string collection_name = settings["collection_name"];
        gateway_name_ = settings["gw-name"];
        client_ = new MongoClient(url);
        collection_ = new MongoCollection(*client_, db_name, collection_name);
    }

    template <typename T>
    void Insert(void *data)
    {
        T *t = (T *)data;
        std::cout << to_csv(*t) << std::endl;
        auto bson_ = to_bson(*t);
        BSON_APPEND_UTF8(*bson_, "from", gateway_name_.c_str());
        size_t len;
        char *str = bson_as_canonical_extended_json(*bson_, &len);
        //printf("%s\n", str);
        collection_->InsertOne(*bson_);
        //save to mongo
    }

    int64_t GetRevision()
    {
        //replRev
        return collection_->GetLastRevision();
    }

    int64_t GetRevision(std::string exchange_name)
    {
        //replRev
        return collection_->GetLastRevision(exchange_name);
    }

    ~SmartMongoStream()
    {
        //std::cout << "~SmartMongoStream" << std::endl;
        if (client_)
        {
            delete client_;
        }
        if (collection_)
        {
            delete collection_;
        }
    }
};
#endif // !__MONGODB_HEADER__
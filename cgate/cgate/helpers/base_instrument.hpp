#ifndef __BASE_INSTRUMENT__
#define __BASE_INSTRUMENT__
#include <string.h>
#include <memory>
#include <mongoc.h>

struct BaseInstrument
{
    std::string symbol;
    double step_price;
    double min_step_price;
    int64_t min_step_price_i;
    double min_step_amount;
    int64_t min_step_amount_i;
    double min_amount{1};
    int64_t min_amount_i{1};
    int32_t roundto;
    int32_t isin_id;
    std::string type;
    int64_t price_mult;
    int64_t amount_mult;
    int32_t lot_volume;
    std::string code_vcb;
    std::string quote_regime;
    std::string curr{""};

    auto to_bson()
    {
        bson_t *doc;
        doc = bson_new();
        BSON_APPEND_UTF8(doc, "symbol", symbol.c_str());
        BSON_APPEND_UTF8(doc, "step_price", std::to_string(step_price).c_str());
        BSON_APPEND_UTF8(doc, "min_step_price", std::to_string(min_step_price).c_str());
        BSON_APPEND_UTF8(doc, "min_step_price_i", std::to_string(min_step_price_i).c_str());
        BSON_APPEND_UTF8(doc, "min_step_amount", std::to_string(min_step_amount).c_str());
        BSON_APPEND_UTF8(doc, "min_step_amount_i", std::to_string(min_step_amount_i).c_str());
        BSON_APPEND_UTF8(doc, "min_amount", std::to_string(min_amount).c_str());
        BSON_APPEND_UTF8(doc, "min_amount_i", std::to_string(min_amount_i).c_str());
        BSON_APPEND_UTF8(doc, "roundto", std::to_string(roundto).c_str());
        BSON_APPEND_UTF8(doc, "isin_id", std::to_string(isin_id).c_str());
        BSON_APPEND_UTF8(doc, "type", type.c_str());
        BSON_APPEND_UTF8(doc, "price_mult", std::to_string(price_mult).c_str());
        BSON_APPEND_UTF8(doc, "amount_mult", std::to_string(amount_mult).c_str());
        BSON_APPEND_UTF8(doc, "lot_volume", std::to_string(lot_volume).c_str());
        BSON_APPEND_UTF8(doc, "quote_regime", quote_regime.c_str());
        BSON_APPEND_UTF8(doc, "curr", curr.c_str());
        return std::make_unique<bson_t *>(doc);
    }
};
#endif // !__BASE_INSTRUMENT__

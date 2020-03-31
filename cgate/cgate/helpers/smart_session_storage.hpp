#ifndef __SMART_SESSION_STORAGE__
#define __SMART_SESSION_STORAGE__
#include <cgate.h>
#include <functional>
#include <map>
#include <string>
#include "../include/cgate_structs_helper.hpp"
#include "../include/cgate-yard.hpp"
#include "base_instrument.hpp"

struct SmartSessionStorage
{
    struct IsinInfo
    {
        std::string symbol;
        std::string shortSymbol_;

        IsinInfo()
        {
        }
        IsinInfo(std::string prefix, std::string symbol)
        {
            this->symbol = prefix + "@" + symbol;
            shortSymbol_ = symbol;
        }
    };
    std::map<int32_t, BaseInstrument> fut_instruments_;
    std::map<int32_t, BaseInstrument> opt_instruments_;
    std::map<int32_t, IsinInfo> instruments_;
    std::map<int32_t, std::string> isin2name_;
    std::map<std::string, std::string> codevcb2curr_;
    FORTS_FUTINFO_REPL::session session_;

    SmartSessionStorage()
    {
    }

    bool isOnline{false};

    void HandleFutSessContents(FORTS_FUTINFO_REPL::fut_sess_contents &record)
    {

        //std::cout << "HandleOptSessCOntents" << std::endl;
        //std::cout << to_csv(record) << std::endl;
        //isinid2isin.insert({value.isin_id, value.isin});
        //std::cout << to_csv(record) << std::endl;
        //std::cout << record.isin_id << "  " << record.isin << std::endl;
        int64_t price_mult = 1000000;
        int64_t amount_mult = 1;
        auto symbol = std::string(record.isin);
        auto isin_id = record.isin_id;
        int32_t roundto = record.roundto;
        auto step_price = ((double)cg_bcd_to_int64(record.step_price)) / 1000000;
        std::string type_ = "fut";
        auto min_step_price_i = cg_bcd_to_int64(record.min_step);
        // std::cout << "min_step_price_i ===== " << min_step_price_i << std::endl;
        double min_step_price = ((double)min_step_price_i) / 1000000;
        double min_step_amount = 1;
        double min_step_amount_i = 1;
        int32_t lot_volume = record.lot_volume;
        std::string code_vcb = std::string(record.code_vcb);
        if (opt_instruments_.count(isin_id) > 0)
        {
            opt_instruments_[isin_id].symbol = symbol;
            opt_instruments_[isin_id].roundto = roundto;
            opt_instruments_[isin_id].isin_id = isin_id;
            opt_instruments_[isin_id].step_price = step_price;
            opt_instruments_[isin_id].min_step_price = min_step_price;
            opt_instruments_[isin_id].min_step_price_i = min_step_price_i;
            opt_instruments_[isin_id].min_step_amount = min_step_amount;
            opt_instruments_[isin_id].min_step_amount_i = min_step_amount_i;
            opt_instruments_[isin_id].type = type_;
            opt_instruments_[isin_id].price_mult = price_mult;
            opt_instruments_[isin_id].amount_mult = amount_mult;
            opt_instruments_[isin_id].quote_regime = "contract";
            opt_instruments_[isin_id].lot_volume = lot_volume;
            opt_instruments_[isin_id].code_vcb = code_vcb;
        }
        else
        {
            BaseInstrument instrument;
            instrument.symbol = symbol;
            instrument.roundto = roundto;
            instrument.isin_id = isin_id;
            instrument.step_price = step_price;
            instrument.min_step_price = min_step_price;
            instrument.min_step_price_i = min_step_price_i;
            instrument.min_step_amount = min_step_amount;
            instrument.min_step_amount_i = min_step_amount_i;
            instrument.type = type_;
            instrument.price_mult = price_mult;
            instrument.amount_mult = amount_mult;
            instrument.quote_regime = "contract";
            instrument.lot_volume = lot_volume;
            instrument.code_vcb = code_vcb;
            opt_instruments_.insert({isin_id, instrument});
        }

        IsinInfo isinInfo("moex_forts", symbol);
        //std::cout << record.isin_id << " " << isinInfo.symbol << std::endl;
        instruments_.insert({record.isin_id, isinInfo});
    }

    void HandleFutInstruments(FORTS_FUTINFO_REPL::fut_instruments &record)
    {
        //std::cout << to_csv(record) << std::endl;
        int64_t price_mult = 1000000;
        int64_t amount_mult = 1;
        auto symbol = std::string(record.isin);
        auto isin_id = record.isin_id;
        int32_t roundto = record.roundto;
        auto step_price = ((double)cg_bcd_to_int64(record.step_price)) / 1000000;
        std::string type_ = "fut";
        auto min_step_price_i = cg_bcd_to_int64(record.min_step);
        //std::cout << "min_step_price_i ===== " << min_step_price_i << std::endl;
        double min_step_price = ((double)min_step_price_i) / 1000000;

        double min_step_amount = 1;
        double min_step_amount_i = 1;
        int32_t lot_volume = record.lot_volume;
        std::string code_vcb = std::string(record.code_vcb);
        if (fut_instruments_.count(isin_id) > 0)
        {
            fut_instruments_[isin_id].symbol = symbol;
            fut_instruments_[isin_id].roundto = roundto;
            fut_instruments_[isin_id].isin_id = isin_id;
            fut_instruments_[isin_id].step_price = step_price;
            fut_instruments_[isin_id].min_step_price = min_step_price;
            fut_instruments_[isin_id].min_step_price_i = min_step_price_i;
            fut_instruments_[isin_id].min_step_amount = min_step_amount;
            fut_instruments_[isin_id].min_step_amount_i = min_step_amount_i;
            fut_instruments_[isin_id].type = type_;
            fut_instruments_[isin_id].price_mult = price_mult;
            fut_instruments_[isin_id].amount_mult = amount_mult;
            fut_instruments_[isin_id].quote_regime = "contract";
            fut_instruments_[isin_id].lot_volume = lot_volume;
            fut_instruments_[isin_id].code_vcb = code_vcb;
        }
        else
        {
            BaseInstrument instrument;
            instrument.symbol = symbol;
            instrument.roundto = roundto;
            instrument.isin_id = isin_id;
            instrument.step_price = step_price;
            instrument.min_step_price = min_step_price;
            instrument.min_step_price_i = min_step_price_i;
            instrument.min_step_amount = min_step_amount;
            instrument.min_step_amount_i = min_step_amount_i;
            instrument.type = type_;
            instrument.price_mult = price_mult;
            instrument.amount_mult = amount_mult;
            instrument.quote_regime = "contract";
            instrument.lot_volume = lot_volume;
            instrument.code_vcb = code_vcb;
            fut_instruments_.insert({isin_id, instrument});
        }

        //provider->Insert(record, "fut_instruments");
    }

    void HandleFutVcb(FORTS_FUTINFO_REPL::fut_vcb &record)
    {
        //std::cout << "[" << record.code_vcb << "]" << record.curr << std::endl;
        if (!codevcb2curr_.count(std::string(record.code_vcb)))
        {
            codevcb2curr_.insert({std::string(record.code_vcb), std::string(record.curr)});
        }
    }

    void HandleSession(FORTS_FUTINFO_REPL::session &record)
    {
        this->session_ = record;
    }
    void HandleOptSeries(FORTS_OPTINFO_REPL::option_series &record)
    {
        //std::cout << to_csv(record) << std::endl;
        auto bson_ = to_bson(record);
        size_t len;
        char *str = bson_as_relaxed_extended_json(*bson_, &len);
        //std::cout << str << std::endl;
        bson_free(str);
    }

    void HandleOptSessContents(FORTS_OPTINFO_REPL::opt_sess_contents &record)
    {
        //std::cout << "HandleOptSessCOntents" << std::endl;
        //std::cout << to_csv(record) << std::endl;
        //isinid2isin.insert({value.isin_id, value.isin});
        //std::cout << to_csv(record) << std::endl;
        //std::cout << record.isin_id << "  " << record.isin << std::endl;
        int64_t price_mult = 1000000;
        int64_t amount_mult = 1;
        auto symbol = std::string(record.isin);
        auto isin_id = record.isin_id;
        int32_t roundto = record.roundto;
        auto step_price = ((double)cg_bcd_to_int64(record.step_price)) / 1000000;
        std::string type_ = "opt";
        auto min_step_price_i = cg_bcd_to_int64(record.min_step);
        //std::cout << "min_step_price_i ===== " << min_step_price_i << std::endl;
        double min_step_price = ((double)min_step_price_i) / 1000000;
        double min_step_amount = 1;
        double min_step_amount_i = 1;
        int32_t lot_volume = record.lot_volume;
        std::string code_vcb = std::string(record.code_vcb);
        if (opt_instruments_.count(isin_id) > 0)
        {
            opt_instruments_[isin_id].symbol = symbol;
            opt_instruments_[isin_id].roundto = roundto;
            opt_instruments_[isin_id].isin_id = isin_id;
            opt_instruments_[isin_id].step_price = step_price;
            opt_instruments_[isin_id].min_step_price = min_step_price;
            opt_instruments_[isin_id].min_step_price_i = min_step_price_i;
            opt_instruments_[isin_id].min_step_amount = min_step_amount;
            opt_instruments_[isin_id].min_step_amount_i = min_step_amount_i;
            opt_instruments_[isin_id].type = type_;
            opt_instruments_[isin_id].price_mult = price_mult;
            opt_instruments_[isin_id].amount_mult = amount_mult;
            opt_instruments_[isin_id].quote_regime = "contract";
            opt_instruments_[isin_id].lot_volume = lot_volume;
            opt_instruments_[isin_id].code_vcb = code_vcb;
        }
        else
        {
            BaseInstrument instrument;
            instrument.symbol = symbol;
            instrument.roundto = roundto;
            instrument.isin_id = isin_id;
            instrument.step_price = step_price;
            instrument.min_step_price = min_step_price;
            instrument.min_step_price_i = min_step_price_i;
            instrument.min_step_amount = min_step_amount;
            instrument.min_step_amount_i = min_step_amount_i;
            instrument.type = type_;
            instrument.price_mult = price_mult;
            instrument.amount_mult = amount_mult;
            instrument.quote_regime = "contract";
            instrument.lot_volume = lot_volume;
            instrument.code_vcb = code_vcb;
            opt_instruments_.insert({isin_id, instrument});
        }

        IsinInfo isinInfo("moex_opt", symbol);
        //std::cout << record.isin_id << " " << isinInfo.symbol << std::endl;
        instruments_.insert({record.isin_id, isinInfo});

        //auto bson_ = to_bson(record);
        //size_t len;
        //char *str = bson_as_relaxed_extended_json(*bson_, &len);
        //std::cout << str << std::endl;
        //bson_free(str);
    }

    void HandleOptVcb(FORTS_OPTINFO_REPL::opt_vcb &record)
    {
        //std::cout << "[" << record.code_vcb << "]" << record.curr << std::endl;

        if (!codevcb2curr_.count(std::string(record.code_vcb)))
        {
            codevcb2curr_.insert({std::string(record.code_vcb), std::string(record.curr)});
        }
    }

    std::string GetFullSymbolByIsinId(int32_t isin_id)
    {
        //std::cout << "TRY GET FULL SYMBOL BY ISIN ID isin_id: " << isin_id << std::endl;
        if (instruments_.count(isin_id))
        {
            //std::cout << "Retur value NULL " << instruments_[isin_id].symbol << std::endl;
            return instruments_[isin_id].symbol;
        }
        //std::cout << "Retur value NULL" << std::endl;
        return "";
    }

    std::string GetShortSymbolByIsinId(int32_t isin_id)
    {
        if (instruments_.count(isin_id))
        {
            return instruments_[isin_id].shortSymbol_;
        }
        return "";
    }

    /*
    void _SaveInstruments()
    {
        //instruments
        bson_t *doc;
        bson_t child;
        doc = bson_new();
        BSON_APPEND_UTF8(doc, "exchange", "moex_forts");
        bson_t *instruments = bson_new();
        BSON_APPEND_ARRAY_BEGIN(doc, "instruments", &child);
        for (auto &instrument : instruments_)
        {
            auto curr = codevcb2curr_[instrument.second.code_vcb];
            instrument.second.curr = curr;
            std::cout << instrument.first << " " << instrument.second.symbol
                      << " " << instrument.second.roundto << " curr " << curr << std::endl;

            auto bson_ = instrument.second.to_bson();

            //std::cout << str << std::endl;
            BSON_APPEND_DOCUMENT(&child, std::to_string(instrument.second.isin_id).c_str(), *bson_);
            //BSON_APPEND_DOCUMENT(&child, *bson_);
        }
        bson_append_array_end(doc, &child);
        //BSON_APPEND_DOCUMENT(doc, "instruments", instruments);
        //provider->Insert("info", "instruments", doc);
        provider->ReplaceOne("info", "instruments", "exchange", "moex_forts", doc);

        bson_destroy(instruments);
        bson_destroy(doc);
    }*/

    /*
    void _SaveOptInstruments()
    {
        //instruments
        bson_t *doc;
        bson_t child;
        doc = bson_new();
        BSON_APPEND_UTF8(doc, "exchange", "moex_opt");
        bson_t *instruments = bson_new();
        BSON_APPEND_ARRAY_BEGIN(doc, "instruments", &child);
        for (auto &instrument : opt_instruments_)
        {
            auto curr = codevcb2curr_[instrument.second.code_vcb];
            instrument.second.curr = curr;
            std::cout << instrument.first << " " << instrument.second.symbol
                      << " " << instrument.second.roundto << " curr " << curr << std::endl;

            auto bson_ = instrument.second.to_bson();

            //std::cout << str << std::endl;
            BSON_APPEND_DOCUMENT(&child, std::to_string(instrument.second.isin_id).c_str(), *bson_);
            //BSON_APPEND_DOCUMENT(&child, *bson_);
        }
        bson_append_array_end(doc, &child);
        //BSON_APPEND_DOCUMENT(doc, "instruments", instruments);
        //provider->Insert("info", "instruments", doc);
        provider->ReplaceOne("info", "instruments", "exchange", "moex_opt", doc);

        bson_destroy(instruments);
        bson_destroy(doc);
    }*/

    /*void _SaveSession()
    {
        auto _bson = to_bson(forts_session);
        BSON_APPEND_UTF8(*_bson, "exchange", "moex_forts");
        provider->ReplaceOne("info", "sessions", "exchange", "moex_forts", *_bson);
    }*/

    void MakeSnapshotAndStartListenUpdates()
    {
        //_SaveInstruments();
        //_SaveOptInstruments();
        //std::cout << to_csv(forts_session) << std::endl;
        //_SaveSession();
        //session
    }

    std::function<void(void *)> GetHandler(std::string table_name)
    {
        if (table_name == "fut_sess_contents")
        {
            auto lambda = [this](void *data) {
                FORTS_FUTINFO_REPL::fut_sess_contents *record = (FORTS_FUTINFO_REPL::fut_sess_contents *)data;
                this->HandleFutSessContents(*record);
            };
            return lambda;
        }
        else if (table_name == "fut_instruments")
        {
            auto lambda = [this](void *data) {
                FORTS_FUTINFO_REPL::fut_instruments *record = (FORTS_FUTINFO_REPL::fut_instruments *)data;
                this->HandleFutInstruments(*record);
            };
            return lambda;
        }
        else if (table_name == "fut_vcb")
        {
            auto lambda = [this](void *data) {
                FORTS_FUTINFO_REPL::fut_vcb *record = (FORTS_FUTINFO_REPL::fut_vcb *)data;
                this->HandleFutVcb(*record);
            };
            return lambda;
        }
        else if (table_name == "session")
        {
            auto lambda = [this](void *data) {
                FORTS_FUTINFO_REPL::session *record = (FORTS_FUTINFO_REPL::session *)data;
                this->HandleSession(*record);
            };
            return lambda;
        }
        else if (table_name == "option_series")
        {
            auto lambda = [this](void *data) {
                FORTS_OPTINFO_REPL::option_series *record = (FORTS_OPTINFO_REPL::option_series *)data;
                this->HandleOptSeries(*record);
            };
            return lambda;
        }
        else if (table_name == "opt_vcb")
        {
            auto lambda = [this](void *data) {
                FORTS_OPTINFO_REPL::opt_vcb *record = (FORTS_OPTINFO_REPL::opt_vcb *)data;
                this->HandleOptVcb(*record);
            };
            return lambda;
        }
        else if (table_name == "opt_sess_contents")
        {
            auto lambda = [this](void *data) {
                FORTS_OPTINFO_REPL::opt_sess_contents *record = (FORTS_OPTINFO_REPL::opt_sess_contents *)data;
                this->HandleOptSessContents(*record);
            };
            return lambda;
        }
        else
        {
            return [&table_name](void *data) {
                std::cout << table_name << "  "
                          << "unknown handler for StreamInfoStorage" << std::endl;
            };
        }
    }

    void Init(CGateConnection &conn)
    {
        CGateStream futInfo(conn, "FORTS_FUTINFO_REPL", "snapshot+online");
        CGateStream optInfo(conn, "FORTS_OPTINFO_REPL", "snapshot+online");

        futInfo.Pipe("fut_sess_contents", *this);
        futInfo.Pipe("fut_vcb", *this);
        futInfo.Pipe("session", *this);
        optInfo.Pipe("opt_sess_contents", *this);
        optInfo.Pipe("opt_vcb", *this);

        AwaitUntilOnline(conn, futInfo, optInfo);
        CloseAndDestroyStreams(futInfo, optInfo);
    }
};
#endif // !__SMART_SESSION_STORAGE__

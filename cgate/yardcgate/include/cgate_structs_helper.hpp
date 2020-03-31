
#ifndef __CGATE_STRUCTS_HELPER_HEADER__
#define __CGATE_STRUCTS_HELPER_HEADER__

#define CG_SHORT_NAMES
#include <cgate.h>
#include <iostream>
#include <memory>
#include <mongoc.h>
#include <sstream>
#include <map>

#include "rates.h"
#include "optinfo.h"
#include "pos.h"
#include "opttrades.h"
#include "optcommon.h"
#include "fortsmessages.h"
#include "part.h"
#include "mcxccmdcommon.h"
#include "futinfo.h"
#include "futcommon.h"
#include "futtrades.h"


#include "utils.h"


//struct MOEX_RATES_REPL::curr_online

auto to_csv(MOEX_RATES_REPL::curr_online &value) {
    std::stringstream ss;
    ss << "curr_online" <<",";
    ss << value.replID << ",";
    ss << value.replRev << ",";
    ss << value.replAct << ",";
    ss << value.rate_id << ",";
    ss << cg_bcd_to_int64(value.value) << ",";
    ss << std::to_string(cg_time_to_unix_time(value.moment)).c_str() << ",";
    return ss.str();
}


//struct MOEX_RATES_REPL::curr_online

auto to_bson(MOEX_RATES_REPL::curr_online &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"replID", std::to_string(value.replID).c_str());
    BSON_APPEND_UTF8(doc,"replRev", std::to_string(value.replRev).c_str());
    BSON_APPEND_UTF8(doc,"replAct", std::to_string(value.replAct).c_str());
    BSON_APPEND_UTF8(doc,"rate_id", std::to_string(value.rate_id).c_str());
    BSON_APPEND_UTF8(doc,"value", std::to_string(cg_bcd_to_int64(value.value)).c_str());
    BSON_APPEND_UTF8(doc,"moment", std::to_string(cg_time_to_unix_time(value.moment)).c_str());
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct FORTS_OPTINFO_REPL::opt_sess_contents

auto to_csv(FORTS_OPTINFO_REPL::opt_sess_contents &value) {
    std::stringstream ss;
    ss << "opt_sess_contents" <<",";
    ss << value.replID << ",";
    ss << value.replRev << ",";
    ss << value.replAct << ",";
    ss << value.sess_id << ",";
    ss << value.isin_id << ",";
    ss << value.isin << ",";
    ss << value.short_isin << ",";
    ss << value.name << ",";
    ss << value.fut_isin_id << ",";
    ss << cg_bcd_to_int64(value.old_kotir) << ",";
    ss << cg_bcd_to_int64(value.bgo_c) << ",";
    ss << cg_bcd_to_int64(value.bgo_nc) << ",";
    ss << int(value.europe) << ",";
    ss << int(value.put) << ",";
    ss << cg_bcd_to_int64(value.strike) << ",";
    ss << value.roundto << ",";
    ss << cg_bcd_to_int64(value.min_step) << ",";
    ss << value.lot_volume << ",";
    ss << cg_bcd_to_int64(value.step_price) << ",";
    ss << std::to_string(cg_time_to_unix_time(value.d_pg)).c_str() << ",";
    ss << std::to_string(cg_time_to_unix_time(value.d_exec_beg)).c_str() << ",";
    ss << std::to_string(cg_time_to_unix_time(value.d_exec_end)).c_str() << ",";
    ss << value.signs << ",";
    ss << cg_bcd_to_int64(value.last_cl_quote) << ",";
    ss << cg_bcd_to_int64(value.bgo_buy) << ",";
    ss << value.base_isin_id << ",";
    ss << value.option_series_id << ",";
    ss << std::to_string(cg_time_to_unix_time(value.d_start)).c_str() << ",";
    ss << value.base_contract_code << ",";
    ss << cg_bcd_to_int64(value.settlement_price_open) << ",";
    ss << cg_bcd_to_int64(value.base_im_covered_sell) << ",";
    ss << cg_bcd_to_int64(value.base_im_sell) << ",";
    ss << std::to_string(cg_time_to_unix_time(value.last_trade_date)).c_str() << ",";
    ss << cg_bcd_to_int64(value.base_im_buy) << ",";
    ss << cg_bcd_to_int64(value.settlement_price) << ",";
    return ss.str();
}


//struct FORTS_OPTINFO_REPL::opt_sess_contents

auto to_bson(FORTS_OPTINFO_REPL::opt_sess_contents &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"replID", std::to_string(value.replID).c_str());
    BSON_APPEND_UTF8(doc,"replRev", std::to_string(value.replRev).c_str());
    BSON_APPEND_UTF8(doc,"replAct", std::to_string(value.replAct).c_str());
    BSON_APPEND_UTF8(doc,"sess_id", std::to_string(value.sess_id).c_str());
    BSON_APPEND_UTF8(doc,"isin_id", std::to_string(value.isin_id).c_str());
    BSON_APPEND_UTF8(doc,"isin", value.isin);
    BSON_APPEND_UTF8(doc,"short_isin", value.short_isin);
    BSON_APPEND_UTF8(doc,"name", value.name);
    BSON_APPEND_UTF8(doc,"fut_isin_id", std::to_string(value.fut_isin_id).c_str());
    BSON_APPEND_UTF8(doc,"old_kotir", std::to_string(cg_bcd_to_int64(value.old_kotir)).c_str());
    BSON_APPEND_UTF8(doc,"bgo_c", std::to_string(cg_bcd_to_int64(value.bgo_c)).c_str());
    BSON_APPEND_UTF8(doc,"bgo_nc", std::to_string(cg_bcd_to_int64(value.bgo_nc)).c_str());
    BSON_APPEND_UTF8(doc,"europe", std::to_string(value.europe).c_str());
    BSON_APPEND_UTF8(doc,"put", std::to_string(value.put).c_str());
    BSON_APPEND_UTF8(doc,"strike", std::to_string(cg_bcd_to_int64(value.strike)).c_str());
    BSON_APPEND_UTF8(doc,"roundto", std::to_string(value.roundto).c_str());
    BSON_APPEND_UTF8(doc,"min_step", std::to_string(cg_bcd_to_int64(value.min_step)).c_str());
    BSON_APPEND_UTF8(doc,"lot_volume", std::to_string(value.lot_volume).c_str());
    BSON_APPEND_UTF8(doc,"step_price", std::to_string(cg_bcd_to_int64(value.step_price)).c_str());
    BSON_APPEND_UTF8(doc,"d_pg", std::to_string(cg_time_to_unix_time(value.d_pg)).c_str());
    BSON_APPEND_UTF8(doc,"d_exec_beg", std::to_string(cg_time_to_unix_time(value.d_exec_beg)).c_str());
    BSON_APPEND_UTF8(doc,"d_exec_end", std::to_string(cg_time_to_unix_time(value.d_exec_end)).c_str());
    BSON_APPEND_UTF8(doc,"signs", std::to_string(value.signs).c_str());
    BSON_APPEND_UTF8(doc,"last_cl_quote", std::to_string(cg_bcd_to_int64(value.last_cl_quote)).c_str());
    BSON_APPEND_UTF8(doc,"bgo_buy", std::to_string(cg_bcd_to_int64(value.bgo_buy)).c_str());
    BSON_APPEND_UTF8(doc,"base_isin_id", std::to_string(value.base_isin_id).c_str());
    BSON_APPEND_UTF8(doc,"option_series_id", std::to_string(value.option_series_id).c_str());
    BSON_APPEND_UTF8(doc,"d_start", std::to_string(cg_time_to_unix_time(value.d_start)).c_str());
    BSON_APPEND_UTF8(doc,"base_contract_code", value.base_contract_code);
    BSON_APPEND_UTF8(doc,"settlement_price_open", std::to_string(cg_bcd_to_int64(value.settlement_price_open)).c_str());
    BSON_APPEND_UTF8(doc,"base_im_covered_sell", std::to_string(cg_bcd_to_int64(value.base_im_covered_sell)).c_str());
    BSON_APPEND_UTF8(doc,"base_im_sell", std::to_string(cg_bcd_to_int64(value.base_im_sell)).c_str());
    BSON_APPEND_UTF8(doc,"last_trade_date", std::to_string(cg_time_to_unix_time(value.last_trade_date)).c_str());
    BSON_APPEND_UTF8(doc,"base_im_buy", std::to_string(cg_bcd_to_int64(value.base_im_buy)).c_str());
    BSON_APPEND_UTF8(doc,"settlement_price", std::to_string(cg_bcd_to_int64(value.settlement_price)).c_str());
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct FORTS_OPTINFO_REPL::opt_vcb

auto to_csv(FORTS_OPTINFO_REPL::opt_vcb &value) {
    std::stringstream ss;
    ss << "opt_vcb" <<",";
    ss << value.replID << ",";
    ss << value.replRev << ",";
    ss << value.replAct << ",";
    ss << value.code_vcb << ",";
    ss << value.name << ",";
    ss << value.exec_type << ",";
    ss << value.curr << ",";
    ss << value.trade_scheme << ",";
    ss << value.rate_id << ",";
    ss << value.base_contract_id << ",";
    ss << value.base_contract_code << ",";
    return ss.str();
}


//struct FORTS_OPTINFO_REPL::opt_vcb

auto to_bson(FORTS_OPTINFO_REPL::opt_vcb &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"replID", std::to_string(value.replID).c_str());
    BSON_APPEND_UTF8(doc,"replRev", std::to_string(value.replRev).c_str());
    BSON_APPEND_UTF8(doc,"replAct", std::to_string(value.replAct).c_str());
    BSON_APPEND_UTF8(doc,"code_vcb", value.code_vcb);
    BSON_APPEND_UTF8(doc,"name", value.name);
    BSON_APPEND_UTF8(doc,"exec_type", value.exec_type);
    BSON_APPEND_UTF8(doc,"curr", value.curr);
    BSON_APPEND_UTF8(doc,"trade_scheme", value.trade_scheme);
    BSON_APPEND_UTF8(doc,"rate_id", std::to_string(value.rate_id).c_str());
    BSON_APPEND_UTF8(doc,"base_contract_id", std::to_string(value.base_contract_id).c_str());
    BSON_APPEND_UTF8(doc,"base_contract_code", value.base_contract_code);
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct FORTS_OPTINFO_REPL::opt_rejected_orders

auto to_csv(FORTS_OPTINFO_REPL::opt_rejected_orders &value) {
    std::stringstream ss;
    ss << "opt_rejected_orders" <<",";
    ss << value.replID << ",";
    ss << value.replRev << ",";
    ss << value.replAct << ",";
    ss << value.order_id << ",";
    ss << value.sess_id << ",";
    ss << std::to_string(cg_time_to_unix_time(value.moment)).c_str() << ",";
    ss << value.isin_id << ",";
    ss << value.client_code << ",";
    ss << int(value.dir) << ",";
    ss << value.xamount << ",";
    ss << cg_bcd_to_int64(value.price) << ",";
    ss << std::to_string(cg_time_to_unix_time(value.date_exp)).c_str() << ",";
    ss << value.id_ord1 << ",";
    ss << std::to_string(cg_time_to_unix_time(value.moment_reject)).c_str() << ",";
    ss << value.ret_code << ",";
    ss << value.ret_message << ",";
    ss << value.comment << ",";
    ss << value.login_from << ",";
    ss << value.ext_id << ",";
    return ss.str();
}


//struct FORTS_OPTINFO_REPL::opt_rejected_orders

auto to_bson(FORTS_OPTINFO_REPL::opt_rejected_orders &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"replID", std::to_string(value.replID).c_str());
    BSON_APPEND_UTF8(doc,"replRev", std::to_string(value.replRev).c_str());
    BSON_APPEND_UTF8(doc,"replAct", std::to_string(value.replAct).c_str());
    BSON_APPEND_UTF8(doc,"order_id", std::to_string(value.order_id).c_str());
    BSON_APPEND_UTF8(doc,"sess_id", std::to_string(value.sess_id).c_str());
    BSON_APPEND_UTF8(doc,"moment", std::to_string(cg_time_to_unix_time(value.moment)).c_str());
    BSON_APPEND_UTF8(doc,"isin_id", std::to_string(value.isin_id).c_str());
    BSON_APPEND_UTF8(doc,"client_code", value.client_code);
    BSON_APPEND_UTF8(doc,"dir", std::to_string(value.dir).c_str());
    BSON_APPEND_UTF8(doc,"xamount", std::to_string(value.xamount).c_str());
    BSON_APPEND_UTF8(doc,"price", std::to_string(cg_bcd_to_int64(value.price)).c_str());
    BSON_APPEND_UTF8(doc,"date_exp", std::to_string(cg_time_to_unix_time(value.date_exp)).c_str());
    BSON_APPEND_UTF8(doc,"id_ord1", std::to_string(value.id_ord1).c_str());
    BSON_APPEND_UTF8(doc,"moment_reject", std::to_string(cg_time_to_unix_time(value.moment_reject)).c_str());
    BSON_APPEND_UTF8(doc,"ret_code", std::to_string(value.ret_code).c_str());
    BSON_APPEND_UTF8(doc,"ret_message", value.ret_message);
    BSON_APPEND_UTF8(doc,"comment", value.comment);
    BSON_APPEND_UTF8(doc,"login_from", value.login_from);
    BSON_APPEND_UTF8(doc,"ext_id", std::to_string(value.ext_id).c_str());
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct FORTS_OPTINFO_REPL::opt_intercl_info

auto to_csv(FORTS_OPTINFO_REPL::opt_intercl_info &value) {
    std::stringstream ss;
    ss << "opt_intercl_info" <<",";
    ss << value.replID << ",";
    ss << value.replRev << ",";
    ss << value.replAct << ",";
    ss << value.isin_id << ",";
    ss << value.client_code << ",";
    ss << cg_bcd_to_int64(value.vm_intercl) << ",";
    return ss.str();
}


//struct FORTS_OPTINFO_REPL::opt_intercl_info

auto to_bson(FORTS_OPTINFO_REPL::opt_intercl_info &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"replID", std::to_string(value.replID).c_str());
    BSON_APPEND_UTF8(doc,"replRev", std::to_string(value.replRev).c_str());
    BSON_APPEND_UTF8(doc,"replAct", std::to_string(value.replAct).c_str());
    BSON_APPEND_UTF8(doc,"isin_id", std::to_string(value.isin_id).c_str());
    BSON_APPEND_UTF8(doc,"client_code", value.client_code);
    BSON_APPEND_UTF8(doc,"vm_intercl", std::to_string(cg_bcd_to_int64(value.vm_intercl)).c_str());
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct FORTS_OPTINFO_REPL::opt_exp_orders

auto to_csv(FORTS_OPTINFO_REPL::opt_exp_orders &value) {
    std::stringstream ss;
    ss << "opt_exp_orders" <<",";
    ss << value.replID << ",";
    ss << value.replRev << ",";
    ss << value.replAct << ",";
    ss << value.exporder_id << ",";
    ss << value.client_code << ",";
    ss << value.isin_id << ",";
    ss << value.xamount << ",";
    ss << value.sess_id << ",";
    ss << std::to_string(cg_time_to_unix_time(value.date)).c_str() << ",";
    ss << value.xamount_apply << ",";
    return ss.str();
}


//struct FORTS_OPTINFO_REPL::opt_exp_orders

auto to_bson(FORTS_OPTINFO_REPL::opt_exp_orders &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"replID", std::to_string(value.replID).c_str());
    BSON_APPEND_UTF8(doc,"replRev", std::to_string(value.replRev).c_str());
    BSON_APPEND_UTF8(doc,"replAct", std::to_string(value.replAct).c_str());
    BSON_APPEND_UTF8(doc,"exporder_id", std::to_string(value.exporder_id).c_str());
    BSON_APPEND_UTF8(doc,"client_code", value.client_code);
    BSON_APPEND_UTF8(doc,"isin_id", std::to_string(value.isin_id).c_str());
    BSON_APPEND_UTF8(doc,"xamount", std::to_string(value.xamount).c_str());
    BSON_APPEND_UTF8(doc,"sess_id", std::to_string(value.sess_id).c_str());
    BSON_APPEND_UTF8(doc,"date", std::to_string(cg_time_to_unix_time(value.date)).c_str());
    BSON_APPEND_UTF8(doc,"xamount_apply", std::to_string(value.xamount_apply).c_str());
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct FORTS_OPTINFO_REPL::option_series

auto to_csv(FORTS_OPTINFO_REPL::option_series &value) {
    std::stringstream ss;
    ss << "option_series" <<",";
    ss << value.replID << ",";
    ss << value.replRev << ",";
    ss << value.replAct << ",";
    ss << value.series_id << ",";
    ss << value.underlying_id << ",";
    ss << value.base_contract_id << ",";
    ss << std::to_string(cg_time_to_unix_time(value.expiration_date)).c_str() << ",";
    ss << std::to_string(cg_time_to_unix_time(value.expiration_anchor_date)).c_str() << ",";
    ss << value.days_to_expiration << ",";
    ss << value.years_to_expiration << ",";
    ss << value.series_type << ",";
    ss << value.small_name << ",";
    ss << cg_bcd_to_int64(value.A) << ",";
    ss << cg_bcd_to_int64(value.B) << ",";
    ss << cg_bcd_to_int64(value.C) << ",";
    ss << cg_bcd_to_int64(value.D) << ",";
    ss << cg_bcd_to_int64(value.E) << ",";
    ss << cg_bcd_to_int64(value.S) << ",";
    ss << cg_bcd_to_int64(value.strike_step) << ",";
    ss << int(value.use_null_volat) << ",";
    ss << int(value.sub_risk) << ",";
    ss << cg_bcd_to_int64(value.volat_min) << ",";
    ss << cg_bcd_to_int64(value.volat_max) << ",";
    ss << value.volatility_risk << ",";
    ss << value.volatility_mismatch_risk << ",";
    ss << value.signs << ",";
    return ss.str();
}


//struct FORTS_OPTINFO_REPL::option_series

auto to_bson(FORTS_OPTINFO_REPL::option_series &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"replID", std::to_string(value.replID).c_str());
    BSON_APPEND_UTF8(doc,"replRev", std::to_string(value.replRev).c_str());
    BSON_APPEND_UTF8(doc,"replAct", std::to_string(value.replAct).c_str());
    BSON_APPEND_UTF8(doc,"series_id", std::to_string(value.series_id).c_str());
    BSON_APPEND_UTF8(doc,"underlying_id", std::to_string(value.underlying_id).c_str());
    BSON_APPEND_UTF8(doc,"base_contract_id", std::to_string(value.base_contract_id).c_str());
    BSON_APPEND_UTF8(doc,"expiration_date", std::to_string(cg_time_to_unix_time(value.expiration_date)).c_str());
    BSON_APPEND_UTF8(doc,"expiration_anchor_date", std::to_string(cg_time_to_unix_time(value.expiration_anchor_date)).c_str());
    BSON_APPEND_UTF8(doc,"days_to_expiration", std::to_string(value.days_to_expiration).c_str());
    BSON_APPEND_UTF8(doc,"years_to_expiration", std::to_string(value.years_to_expiration).c_str());
    BSON_APPEND_UTF8(doc,"series_type", value.series_type);
    BSON_APPEND_UTF8(doc,"small_name", value.small_name);
    BSON_APPEND_UTF8(doc,"A", std::to_string(cg_bcd_to_int64(value.A)).c_str());
    BSON_APPEND_UTF8(doc,"B", std::to_string(cg_bcd_to_int64(value.B)).c_str());
    BSON_APPEND_UTF8(doc,"C", std::to_string(cg_bcd_to_int64(value.C)).c_str());
    BSON_APPEND_UTF8(doc,"D", std::to_string(cg_bcd_to_int64(value.D)).c_str());
    BSON_APPEND_UTF8(doc,"E", std::to_string(cg_bcd_to_int64(value.E)).c_str());
    BSON_APPEND_UTF8(doc,"S", std::to_string(cg_bcd_to_int64(value.S)).c_str());
    BSON_APPEND_UTF8(doc,"strike_step", std::to_string(cg_bcd_to_int64(value.strike_step)).c_str());
    BSON_APPEND_UTF8(doc,"use_null_volat", std::to_string(value.use_null_volat).c_str());
    BSON_APPEND_UTF8(doc,"sub_risk", std::to_string(value.sub_risk).c_str());
    BSON_APPEND_UTF8(doc,"volat_min", std::to_string(cg_bcd_to_int64(value.volat_min)).c_str());
    BSON_APPEND_UTF8(doc,"volat_max", std::to_string(cg_bcd_to_int64(value.volat_max)).c_str());
    BSON_APPEND_UTF8(doc,"volatility_risk", std::to_string(value.volatility_risk).c_str());
    BSON_APPEND_UTF8(doc,"volatility_mismatch_risk", std::to_string(value.volatility_mismatch_risk).c_str());
    BSON_APPEND_UTF8(doc,"signs", std::to_string(value.signs).c_str());
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct FORTS_OPTINFO_REPL::sys_events

auto to_csv(FORTS_OPTINFO_REPL::sys_events &value) {
    std::stringstream ss;
    ss << "sys_events" <<",";
    ss << value.replID << ",";
    ss << value.replRev << ",";
    ss << value.replAct << ",";
    ss << value.event_id << ",";
    ss << value.sess_id << ",";
    ss << value.event_type << ",";
    ss << value.message << ",";
    return ss.str();
}


//struct FORTS_OPTINFO_REPL::sys_events

auto to_bson(FORTS_OPTINFO_REPL::sys_events &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"replID", std::to_string(value.replID).c_str());
    BSON_APPEND_UTF8(doc,"replRev", std::to_string(value.replRev).c_str());
    BSON_APPEND_UTF8(doc,"replAct", std::to_string(value.replAct).c_str());
    BSON_APPEND_UTF8(doc,"event_id", std::to_string(value.event_id).c_str());
    BSON_APPEND_UTF8(doc,"sess_id", std::to_string(value.sess_id).c_str());
    BSON_APPEND_UTF8(doc,"event_type", std::to_string(value.event_type).c_str());
    BSON_APPEND_UTF8(doc,"message", value.message);
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct FORTS_POS_REPL::position

auto to_csv(FORTS_POS_REPL::position &value) {
    std::stringstream ss;
    ss << "position" <<",";
    ss << value.replID << ",";
    ss << value.replRev << ",";
    ss << value.replAct << ",";
    ss << value.client_code << ",";
    ss << value.isin_id << ",";
    ss << value.xpos << ",";
    ss << value.xbuys_qty << ",";
    ss << value.xsells_qty << ",";
    ss << value.xopen_qty << ",";
    ss << cg_bcd_to_int64(value.waprice) << ",";
    ss << cg_bcd_to_int64(value.net_volume_rur) << ",";
    ss << value.last_deal_id << ",";
    ss << int(value.account_type) << ",";
    return ss.str();
}


//struct FORTS_POS_REPL::position

auto to_bson(FORTS_POS_REPL::position &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"replID", std::to_string(value.replID).c_str());
    BSON_APPEND_UTF8(doc,"replRev", std::to_string(value.replRev).c_str());
    BSON_APPEND_UTF8(doc,"replAct", std::to_string(value.replAct).c_str());
    BSON_APPEND_UTF8(doc,"client_code", value.client_code);
    BSON_APPEND_UTF8(doc,"isin_id", std::to_string(value.isin_id).c_str());
    BSON_APPEND_UTF8(doc,"xpos", std::to_string(value.xpos).c_str());
    BSON_APPEND_UTF8(doc,"xbuys_qty", std::to_string(value.xbuys_qty).c_str());
    BSON_APPEND_UTF8(doc,"xsells_qty", std::to_string(value.xsells_qty).c_str());
    BSON_APPEND_UTF8(doc,"xopen_qty", std::to_string(value.xopen_qty).c_str());
    BSON_APPEND_UTF8(doc,"waprice", std::to_string(cg_bcd_to_int64(value.waprice)).c_str());
    BSON_APPEND_UTF8(doc,"net_volume_rur", std::to_string(cg_bcd_to_int64(value.net_volume_rur)).c_str());
    BSON_APPEND_UTF8(doc,"last_deal_id", std::to_string(value.last_deal_id).c_str());
    BSON_APPEND_UTF8(doc,"account_type", std::to_string(value.account_type).c_str());
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct FORTS_POS_REPL::position_sa

auto to_csv(FORTS_POS_REPL::position_sa &value) {
    std::stringstream ss;
    ss << "position_sa" <<",";
    ss << value.replID << ",";
    ss << value.replRev << ",";
    ss << value.replAct << ",";
    ss << value.client_code << ",";
    ss << value.isin_id << ",";
    ss << value.xpos << ",";
    ss << value.xbuys_qty << ",";
    ss << value.xsells_qty << ",";
    ss << value.xopen_qty << ",";
    ss << cg_bcd_to_int64(value.waprice) << ",";
    ss << cg_bcd_to_int64(value.net_volume_rur) << ",";
    ss << value.last_deal_id << ",";
    return ss.str();
}


//struct FORTS_POS_REPL::position_sa

auto to_bson(FORTS_POS_REPL::position_sa &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"replID", std::to_string(value.replID).c_str());
    BSON_APPEND_UTF8(doc,"replRev", std::to_string(value.replRev).c_str());
    BSON_APPEND_UTF8(doc,"replAct", std::to_string(value.replAct).c_str());
    BSON_APPEND_UTF8(doc,"client_code", value.client_code);
    BSON_APPEND_UTF8(doc,"isin_id", std::to_string(value.isin_id).c_str());
    BSON_APPEND_UTF8(doc,"xpos", std::to_string(value.xpos).c_str());
    BSON_APPEND_UTF8(doc,"xbuys_qty", std::to_string(value.xbuys_qty).c_str());
    BSON_APPEND_UTF8(doc,"xsells_qty", std::to_string(value.xsells_qty).c_str());
    BSON_APPEND_UTF8(doc,"xopen_qty", std::to_string(value.xopen_qty).c_str());
    BSON_APPEND_UTF8(doc,"waprice", std::to_string(cg_bcd_to_int64(value.waprice)).c_str());
    BSON_APPEND_UTF8(doc,"net_volume_rur", std::to_string(cg_bcd_to_int64(value.net_volume_rur)).c_str());
    BSON_APPEND_UTF8(doc,"last_deal_id", std::to_string(value.last_deal_id).c_str());
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct FORTS_POS_REPL::sys_events

auto to_csv(FORTS_POS_REPL::sys_events &value) {
    std::stringstream ss;
    ss << "sys_events" <<",";
    ss << value.replID << ",";
    ss << value.replRev << ",";
    ss << value.replAct << ",";
    ss << value.event_id << ",";
    ss << value.sess_id << ",";
    ss << value.event_type << ",";
    ss << value.message << ",";
    return ss.str();
}


//struct FORTS_POS_REPL::sys_events

auto to_bson(FORTS_POS_REPL::sys_events &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"replID", std::to_string(value.replID).c_str());
    BSON_APPEND_UTF8(doc,"replRev", std::to_string(value.replRev).c_str());
    BSON_APPEND_UTF8(doc,"replAct", std::to_string(value.replAct).c_str());
    BSON_APPEND_UTF8(doc,"event_id", std::to_string(value.event_id).c_str());
    BSON_APPEND_UTF8(doc,"sess_id", std::to_string(value.sess_id).c_str());
    BSON_APPEND_UTF8(doc,"event_type", std::to_string(value.event_type).c_str());
    BSON_APPEND_UTF8(doc,"message", value.message);
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct FORTS_OPTTRADE_REPL::orders_log

auto to_csv(FORTS_OPTTRADE_REPL::orders_log &value) {
    std::stringstream ss;
    ss << "orders_log" <<",";
    ss << value.replID << ",";
    ss << value.replRev << ",";
    ss << value.replAct << ",";
    ss << value.id_ord << ",";
    ss << value.sess_id << ",";
    ss << value.isin_id << ",";
    ss << value.xamount << ",";
    ss << value.xamount_rest << ",";
    ss << value.id_deal << ",";
    ss << value.xstatus << ",";
    ss << cg_bcd_to_int64(value.price) << ",";
    ss << std::to_string(cg_time_to_unix_time(value.moment)).c_str() << ",";
    ss << value.moment_ns << ",";
    ss << int(value.dir) << ",";
    ss << int(value.action) << ",";
    ss << cg_bcd_to_int64(value.deal_price) << ",";
    ss << value.client_code << ",";
    ss << value.login_from << ",";
    ss << value.comment << ",";
    ss << value.ext_id << ",";
    ss << value.broker_to << ",";
    ss << value.broker_to_rts << ",";
    ss << value.broker_from_rts << ",";
    ss << std::to_string(cg_time_to_unix_time(value.date_exp)).c_str() << ",";
    ss << value.id_ord1 << ",";
    ss << std::to_string(cg_time_to_unix_time(value.local_stamp)).c_str() << ",";
    ss << value.aspref << ",";
    return ss.str();
}


//struct FORTS_OPTTRADE_REPL::orders_log

auto to_bson(FORTS_OPTTRADE_REPL::orders_log &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"replID", std::to_string(value.replID).c_str());
    BSON_APPEND_UTF8(doc,"replRev", std::to_string(value.replRev).c_str());
    BSON_APPEND_UTF8(doc,"replAct", std::to_string(value.replAct).c_str());
    BSON_APPEND_UTF8(doc,"id_ord", std::to_string(value.id_ord).c_str());
    BSON_APPEND_UTF8(doc,"sess_id", std::to_string(value.sess_id).c_str());
    BSON_APPEND_UTF8(doc,"isin_id", std::to_string(value.isin_id).c_str());
    BSON_APPEND_UTF8(doc,"xamount", std::to_string(value.xamount).c_str());
    BSON_APPEND_UTF8(doc,"xamount_rest", std::to_string(value.xamount_rest).c_str());
    BSON_APPEND_UTF8(doc,"id_deal", std::to_string(value.id_deal).c_str());
    BSON_APPEND_UTF8(doc,"xstatus", std::to_string(value.xstatus).c_str());
    BSON_APPEND_UTF8(doc,"price", std::to_string(cg_bcd_to_int64(value.price)).c_str());
    BSON_APPEND_UTF8(doc,"moment", std::to_string(cg_time_to_unix_time(value.moment)).c_str());
    BSON_APPEND_UTF8(doc,"moment_ns", std::to_string(value.moment_ns).c_str());
    BSON_APPEND_UTF8(doc,"dir", std::to_string(value.dir).c_str());
    BSON_APPEND_UTF8(doc,"action", std::to_string(value.action).c_str());
    BSON_APPEND_UTF8(doc,"deal_price", std::to_string(cg_bcd_to_int64(value.deal_price)).c_str());
    BSON_APPEND_UTF8(doc,"client_code", value.client_code);
    BSON_APPEND_UTF8(doc,"login_from", value.login_from);
    BSON_APPEND_UTF8(doc,"comment", value.comment);
    BSON_APPEND_UTF8(doc,"ext_id", std::to_string(value.ext_id).c_str());
    BSON_APPEND_UTF8(doc,"broker_to", value.broker_to);
    BSON_APPEND_UTF8(doc,"broker_to_rts", value.broker_to_rts);
    BSON_APPEND_UTF8(doc,"broker_from_rts", value.broker_from_rts);
    BSON_APPEND_UTF8(doc,"date_exp", std::to_string(cg_time_to_unix_time(value.date_exp)).c_str());
    BSON_APPEND_UTF8(doc,"id_ord1", std::to_string(value.id_ord1).c_str());
    BSON_APPEND_UTF8(doc,"local_stamp", std::to_string(cg_time_to_unix_time(value.local_stamp)).c_str());
    BSON_APPEND_UTF8(doc,"aspref", std::to_string(value.aspref).c_str());
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct FORTS_OPTTRADE_REPL::heartbeat

auto to_csv(FORTS_OPTTRADE_REPL::heartbeat &value) {
    std::stringstream ss;
    ss << "heartbeat" <<",";
    ss << value.replID << ",";
    ss << value.replRev << ",";
    ss << value.replAct << ",";
    ss << std::to_string(cg_time_to_unix_time(value.server_time)).c_str() << ",";
    return ss.str();
}


//struct FORTS_OPTTRADE_REPL::heartbeat

auto to_bson(FORTS_OPTTRADE_REPL::heartbeat &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"replID", std::to_string(value.replID).c_str());
    BSON_APPEND_UTF8(doc,"replRev", std::to_string(value.replRev).c_str());
    BSON_APPEND_UTF8(doc,"replAct", std::to_string(value.replAct).c_str());
    BSON_APPEND_UTF8(doc,"server_time", std::to_string(cg_time_to_unix_time(value.server_time)).c_str());
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct FORTS_OPTTRADE_REPL::sys_events

auto to_csv(FORTS_OPTTRADE_REPL::sys_events &value) {
    std::stringstream ss;
    ss << "sys_events" <<",";
    ss << value.replID << ",";
    ss << value.replRev << ",";
    ss << value.replAct << ",";
    ss << value.event_id << ",";
    ss << value.sess_id << ",";
    ss << value.event_type << ",";
    ss << value.message << ",";
    return ss.str();
}


//struct FORTS_OPTTRADE_REPL::sys_events

auto to_bson(FORTS_OPTTRADE_REPL::sys_events &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"replID", std::to_string(value.replID).c_str());
    BSON_APPEND_UTF8(doc,"replRev", std::to_string(value.replRev).c_str());
    BSON_APPEND_UTF8(doc,"replAct", std::to_string(value.replAct).c_str());
    BSON_APPEND_UTF8(doc,"event_id", std::to_string(value.event_id).c_str());
    BSON_APPEND_UTF8(doc,"sess_id", std::to_string(value.sess_id).c_str());
    BSON_APPEND_UTF8(doc,"event_type", std::to_string(value.event_type).c_str());
    BSON_APPEND_UTF8(doc,"message", value.message);
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct FORTS_OPTTRADE_REPL::user_deal

auto to_csv(FORTS_OPTTRADE_REPL::user_deal &value) {
    std::stringstream ss;
    ss << "user_deal" <<",";
    ss << value.replID << ",";
    ss << value.replRev << ",";
    ss << value.replAct << ",";
    ss << value.sess_id << ",";
    ss << value.isin_id << ",";
    ss << value.id_deal << ",";
    ss << value.id_deal_multileg << ",";
    ss << value.xpos << ",";
    ss << value.xamount << ",";
    ss << value.id_ord_buy << ",";
    ss << value.id_ord_sell << ",";
    ss << cg_bcd_to_int64(value.price) << ",";
    ss << std::to_string(cg_time_to_unix_time(value.moment)).c_str() << ",";
    ss << value.moment_ns << ",";
    ss << int(value.nosystem) << ",";
    ss << value.xstatus_buy << ",";
    ss << value.xstatus_sell << ",";
    ss << value.ext_id_buy << ",";
    ss << value.ext_id_sell << ",";
    ss << value.code_buy << ",";
    ss << value.code_sell << ",";
    ss << value.comment_buy << ",";
    ss << value.comment_sell << ",";
    ss << cg_bcd_to_int64(value.fee_buy) << ",";
    ss << cg_bcd_to_int64(value.fee_sell) << ",";
    ss << value.login_buy << ",";
    ss << value.login_sell << ",";
    ss << value.code_rts_buy << ",";
    ss << value.code_rts_sell << ",";
    return ss.str();
}


//struct FORTS_OPTTRADE_REPL::user_deal

auto to_bson(FORTS_OPTTRADE_REPL::user_deal &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"replID", std::to_string(value.replID).c_str());
    BSON_APPEND_UTF8(doc,"replRev", std::to_string(value.replRev).c_str());
    BSON_APPEND_UTF8(doc,"replAct", std::to_string(value.replAct).c_str());
    BSON_APPEND_UTF8(doc,"sess_id", std::to_string(value.sess_id).c_str());
    BSON_APPEND_UTF8(doc,"isin_id", std::to_string(value.isin_id).c_str());
    BSON_APPEND_UTF8(doc,"id_deal", std::to_string(value.id_deal).c_str());
    BSON_APPEND_UTF8(doc,"id_deal_multileg", std::to_string(value.id_deal_multileg).c_str());
    BSON_APPEND_UTF8(doc,"xpos", std::to_string(value.xpos).c_str());
    BSON_APPEND_UTF8(doc,"xamount", std::to_string(value.xamount).c_str());
    BSON_APPEND_UTF8(doc,"id_ord_buy", std::to_string(value.id_ord_buy).c_str());
    BSON_APPEND_UTF8(doc,"id_ord_sell", std::to_string(value.id_ord_sell).c_str());
    BSON_APPEND_UTF8(doc,"price", std::to_string(cg_bcd_to_int64(value.price)).c_str());
    BSON_APPEND_UTF8(doc,"moment", std::to_string(cg_time_to_unix_time(value.moment)).c_str());
    BSON_APPEND_UTF8(doc,"moment_ns", std::to_string(value.moment_ns).c_str());
    BSON_APPEND_UTF8(doc,"nosystem", std::to_string(value.nosystem).c_str());
    BSON_APPEND_UTF8(doc,"xstatus_buy", std::to_string(value.xstatus_buy).c_str());
    BSON_APPEND_UTF8(doc,"xstatus_sell", std::to_string(value.xstatus_sell).c_str());
    BSON_APPEND_UTF8(doc,"ext_id_buy", std::to_string(value.ext_id_buy).c_str());
    BSON_APPEND_UTF8(doc,"ext_id_sell", std::to_string(value.ext_id_sell).c_str());
    BSON_APPEND_UTF8(doc,"code_buy", value.code_buy);
    BSON_APPEND_UTF8(doc,"code_sell", value.code_sell);
    BSON_APPEND_UTF8(doc,"comment_buy", value.comment_buy);
    BSON_APPEND_UTF8(doc,"comment_sell", value.comment_sell);
    BSON_APPEND_UTF8(doc,"fee_buy", std::to_string(cg_bcd_to_int64(value.fee_buy)).c_str());
    BSON_APPEND_UTF8(doc,"fee_sell", std::to_string(cg_bcd_to_int64(value.fee_sell)).c_str());
    BSON_APPEND_UTF8(doc,"login_buy", value.login_buy);
    BSON_APPEND_UTF8(doc,"login_sell", value.login_sell);
    BSON_APPEND_UTF8(doc,"code_rts_buy", value.code_rts_buy);
    BSON_APPEND_UTF8(doc,"code_rts_sell", value.code_rts_sell);
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct FORTS_OPTCOMMON_REPL::common

auto to_csv(FORTS_OPTCOMMON_REPL::common &value) {
    std::stringstream ss;
    ss << "common" <<",";
    ss << value.replID << ",";
    ss << value.replRev << ",";
    ss << value.replAct << ",";
    ss << value.sess_id << ",";
    ss << value.isin_id << ",";
    ss << cg_bcd_to_int64(value.best_buy) << ",";
    ss << value.xamount_buy << ",";
    ss << value.orders_buy_qty << ",";
    ss << value.xorders_buy_amount << ",";
    ss << cg_bcd_to_int64(value.best_sell) << ",";
    ss << value.xamount_sell << ",";
    ss << value.orders_sell_qty << ",";
    ss << value.xorders_sell_amount << ",";
    ss << cg_bcd_to_int64(value.open_price) << ",";
    ss << cg_bcd_to_int64(value.close_price) << ",";
    ss << cg_bcd_to_int64(value.price) << ",";
    ss << cg_bcd_to_int64(value.trend) << ",";
    ss << value.xamount << ",";
    ss << std::to_string(cg_time_to_unix_time(value.deal_time)).c_str() << ",";
    ss << value.deal_time_ns << ",";
    ss << cg_bcd_to_int64(value.min_price) << ",";
    ss << cg_bcd_to_int64(value.max_price) << ",";
    ss << cg_bcd_to_int64(value.avr_price) << ",";
    ss << value.xcontr_count << ",";
    ss << cg_bcd_to_int64(value.capital) << ",";
    ss << value.deal_count << ",";
    ss << cg_bcd_to_int64(value.old_kotir) << ",";
    ss << cg_bcd_to_int64(value.settlement_price_open) << ",";
    ss << value.xpos << ",";
    ss << std::to_string(cg_time_to_unix_time(value.mod_time)).c_str() << ",";
    ss << value.mod_time_ns << ",";
    ss << std::to_string(cg_time_to_unix_time(value.local_time)).c_str() << ",";
    return ss.str();
}


//struct FORTS_OPTCOMMON_REPL::common

auto to_bson(FORTS_OPTCOMMON_REPL::common &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"replID", std::to_string(value.replID).c_str());
    BSON_APPEND_UTF8(doc,"replRev", std::to_string(value.replRev).c_str());
    BSON_APPEND_UTF8(doc,"replAct", std::to_string(value.replAct).c_str());
    BSON_APPEND_UTF8(doc,"sess_id", std::to_string(value.sess_id).c_str());
    BSON_APPEND_UTF8(doc,"isin_id", std::to_string(value.isin_id).c_str());
    BSON_APPEND_UTF8(doc,"best_buy", std::to_string(cg_bcd_to_int64(value.best_buy)).c_str());
    BSON_APPEND_UTF8(doc,"xamount_buy", std::to_string(value.xamount_buy).c_str());
    BSON_APPEND_UTF8(doc,"orders_buy_qty", std::to_string(value.orders_buy_qty).c_str());
    BSON_APPEND_UTF8(doc,"xorders_buy_amount", std::to_string(value.xorders_buy_amount).c_str());
    BSON_APPEND_UTF8(doc,"best_sell", std::to_string(cg_bcd_to_int64(value.best_sell)).c_str());
    BSON_APPEND_UTF8(doc,"xamount_sell", std::to_string(value.xamount_sell).c_str());
    BSON_APPEND_UTF8(doc,"orders_sell_qty", std::to_string(value.orders_sell_qty).c_str());
    BSON_APPEND_UTF8(doc,"xorders_sell_amount", std::to_string(value.xorders_sell_amount).c_str());
    BSON_APPEND_UTF8(doc,"open_price", std::to_string(cg_bcd_to_int64(value.open_price)).c_str());
    BSON_APPEND_UTF8(doc,"close_price", std::to_string(cg_bcd_to_int64(value.close_price)).c_str());
    BSON_APPEND_UTF8(doc,"price", std::to_string(cg_bcd_to_int64(value.price)).c_str());
    BSON_APPEND_UTF8(doc,"trend", std::to_string(cg_bcd_to_int64(value.trend)).c_str());
    BSON_APPEND_UTF8(doc,"xamount", std::to_string(value.xamount).c_str());
    BSON_APPEND_UTF8(doc,"deal_time", std::to_string(cg_time_to_unix_time(value.deal_time)).c_str());
    BSON_APPEND_UTF8(doc,"deal_time_ns", std::to_string(value.deal_time_ns).c_str());
    BSON_APPEND_UTF8(doc,"min_price", std::to_string(cg_bcd_to_int64(value.min_price)).c_str());
    BSON_APPEND_UTF8(doc,"max_price", std::to_string(cg_bcd_to_int64(value.max_price)).c_str());
    BSON_APPEND_UTF8(doc,"avr_price", std::to_string(cg_bcd_to_int64(value.avr_price)).c_str());
    BSON_APPEND_UTF8(doc,"xcontr_count", std::to_string(value.xcontr_count).c_str());
    BSON_APPEND_UTF8(doc,"capital", std::to_string(cg_bcd_to_int64(value.capital)).c_str());
    BSON_APPEND_UTF8(doc,"deal_count", std::to_string(value.deal_count).c_str());
    BSON_APPEND_UTF8(doc,"old_kotir", std::to_string(cg_bcd_to_int64(value.old_kotir)).c_str());
    BSON_APPEND_UTF8(doc,"settlement_price_open", std::to_string(cg_bcd_to_int64(value.settlement_price_open)).c_str());
    BSON_APPEND_UTF8(doc,"xpos", std::to_string(value.xpos).c_str());
    BSON_APPEND_UTF8(doc,"mod_time", std::to_string(cg_time_to_unix_time(value.mod_time)).c_str());
    BSON_APPEND_UTF8(doc,"mod_time_ns", std::to_string(value.mod_time_ns).c_str());
    BSON_APPEND_UTF8(doc,"local_time", std::to_string(cg_time_to_unix_time(value.local_time)).c_str());
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct MESSAGE_PUB::FutAddOrder

auto to_csv(MESSAGE_PUB::FutAddOrder &value) {
    std::stringstream ss;
    ss << "FutAddOrder" <<",";
    ss << value.broker_code << ",";
    ss << value.isin << ",";
    ss << value.client_code << ",";
    ss << value.type << ",";
    ss << value.dir << ",";
    ss << value.amount << ",";
    ss << value.price << ",";
    ss << value.comment << ",";
    ss << value.broker_to << ",";
    ss << value.ext_id << ",";
    ss << value.date_exp << ",";
    ss << value.dont_check_money << ",";
    ss << std::to_string(cg_time_to_unix_time(value.local_stamp)).c_str() << ",";
    ss << value.match_ref << ",";
    ss << int(value.ncc_request) << ",";
    return ss.str();
}


//struct MESSAGE_PUB::FutAddOrder

auto to_bson(MESSAGE_PUB::FutAddOrder &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"broker_code", value.broker_code);
    BSON_APPEND_UTF8(doc,"isin", value.isin);
    BSON_APPEND_UTF8(doc,"client_code", value.client_code);
    BSON_APPEND_UTF8(doc,"type", std::to_string(value.type).c_str());
    BSON_APPEND_UTF8(doc,"dir", std::to_string(value.dir).c_str());
    BSON_APPEND_UTF8(doc,"amount", std::to_string(value.amount).c_str());
    BSON_APPEND_UTF8(doc,"price", value.price);
    BSON_APPEND_UTF8(doc,"comment", value.comment);
    BSON_APPEND_UTF8(doc,"broker_to", value.broker_to);
    BSON_APPEND_UTF8(doc,"ext_id", std::to_string(value.ext_id).c_str());
    BSON_APPEND_UTF8(doc,"date_exp", value.date_exp);
    BSON_APPEND_UTF8(doc,"dont_check_money", std::to_string(value.dont_check_money).c_str());
    BSON_APPEND_UTF8(doc,"local_stamp", std::to_string(cg_time_to_unix_time(value.local_stamp)).c_str());
    BSON_APPEND_UTF8(doc,"match_ref", value.match_ref);
    BSON_APPEND_UTF8(doc,"ncc_request", std::to_string(value.ncc_request).c_str());
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct MESSAGE_PUB::FORTS_MSG101

auto to_csv(MESSAGE_PUB::FORTS_MSG101 &value) {
    std::stringstream ss;
    ss << "FORTS_MSG101" <<",";
    ss << value.code << ",";
    ss << value.message << ",";
    ss << value.order_id << ",";
    return ss.str();
}


//struct MESSAGE_PUB::FORTS_MSG101

auto to_bson(MESSAGE_PUB::FORTS_MSG101 &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"code", std::to_string(value.code).c_str());
    BSON_APPEND_UTF8(doc,"message", value.message);
    BSON_APPEND_UTF8(doc,"order_id", std::to_string(value.order_id).c_str());
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct MESSAGE_PUB::FutDelOrder

auto to_csv(MESSAGE_PUB::FutDelOrder &value) {
    std::stringstream ss;
    ss << "FutDelOrder" <<",";
    ss << value.broker_code << ",";
    ss << value.order_id << ",";
    ss << std::to_string(cg_time_to_unix_time(value.local_stamp)).c_str() << ",";
    ss << int(value.ncc_request) << ",";
    return ss.str();
}


//struct MESSAGE_PUB::FutDelOrder

auto to_bson(MESSAGE_PUB::FutDelOrder &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"broker_code", value.broker_code);
    BSON_APPEND_UTF8(doc,"order_id", std::to_string(value.order_id).c_str());
    BSON_APPEND_UTF8(doc,"local_stamp", std::to_string(cg_time_to_unix_time(value.local_stamp)).c_str());
    BSON_APPEND_UTF8(doc,"ncc_request", std::to_string(value.ncc_request).c_str());
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct MESSAGE_PUB::FORTS_MSG102

auto to_csv(MESSAGE_PUB::FORTS_MSG102 &value) {
    std::stringstream ss;
    ss << "FORTS_MSG102" <<",";
    ss << value.code << ",";
    ss << value.message << ",";
    ss << value.amount << ",";
    return ss.str();
}


//struct MESSAGE_PUB::FORTS_MSG102

auto to_bson(MESSAGE_PUB::FORTS_MSG102 &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"code", std::to_string(value.code).c_str());
    BSON_APPEND_UTF8(doc,"message", value.message);
    BSON_APPEND_UTF8(doc,"amount", std::to_string(value.amount).c_str());
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct MESSAGE_PUB::FutDelUserOrders

auto to_csv(MESSAGE_PUB::FutDelUserOrders &value) {
    std::stringstream ss;
    ss << "FutDelUserOrders" <<",";
    ss << value.broker_code << ",";
    ss << value.buy_sell << ",";
    ss << value.non_system << ",";
    ss << value.code << ",";
    ss << value.base_contract_code << ",";
    ss << value.ext_id << ",";
    ss << value.work_mode << ",";
    ss << value.isin << ",";
    ss << std::to_string(cg_time_to_unix_time(value.local_stamp)).c_str() << ",";
    return ss.str();
}


//struct MESSAGE_PUB::FutDelUserOrders

auto to_bson(MESSAGE_PUB::FutDelUserOrders &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"broker_code", value.broker_code);
    BSON_APPEND_UTF8(doc,"buy_sell", std::to_string(value.buy_sell).c_str());
    BSON_APPEND_UTF8(doc,"non_system", std::to_string(value.non_system).c_str());
    BSON_APPEND_UTF8(doc,"code", value.code);
    BSON_APPEND_UTF8(doc,"base_contract_code", value.base_contract_code);
    BSON_APPEND_UTF8(doc,"ext_id", std::to_string(value.ext_id).c_str());
    BSON_APPEND_UTF8(doc,"work_mode", std::to_string(value.work_mode).c_str());
    BSON_APPEND_UTF8(doc,"isin", value.isin);
    BSON_APPEND_UTF8(doc,"local_stamp", std::to_string(cg_time_to_unix_time(value.local_stamp)).c_str());
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct MESSAGE_PUB::FORTS_MSG103

auto to_csv(MESSAGE_PUB::FORTS_MSG103 &value) {
    std::stringstream ss;
    ss << "FORTS_MSG103" <<",";
    ss << value.code << ",";
    ss << value.message << ",";
    ss << value.num_orders << ",";
    return ss.str();
}


//struct MESSAGE_PUB::FORTS_MSG103

auto to_bson(MESSAGE_PUB::FORTS_MSG103 &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"code", std::to_string(value.code).c_str());
    BSON_APPEND_UTF8(doc,"message", value.message);
    BSON_APPEND_UTF8(doc,"num_orders", std::to_string(value.num_orders).c_str());
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct MESSAGE_PUB::FutChangeClientMoney

auto to_csv(MESSAGE_PUB::FutChangeClientMoney &value) {
    std::stringstream ss;
    ss << "FutChangeClientMoney" <<",";
    ss << value.broker_code << ",";
    ss << value.mode << ",";
    ss << value.code << ",";
    ss << value.limit_money << ",";
    ss << value.coeff_go << ",";
    ss << value.is_auto_update_limit << ",";
    ss << value.no_fut_discount << ",";
    ss << value.check_limit << ",";
    return ss.str();
}


//struct MESSAGE_PUB::FutChangeClientMoney

auto to_bson(MESSAGE_PUB::FutChangeClientMoney &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"broker_code", value.broker_code);
    BSON_APPEND_UTF8(doc,"mode", std::to_string(value.mode).c_str());
    BSON_APPEND_UTF8(doc,"code", value.code);
    BSON_APPEND_UTF8(doc,"limit_money", value.limit_money);
    BSON_APPEND_UTF8(doc,"coeff_go", value.coeff_go);
    BSON_APPEND_UTF8(doc,"is_auto_update_limit", std::to_string(value.is_auto_update_limit).c_str());
    BSON_APPEND_UTF8(doc,"no_fut_discount", std::to_string(value.no_fut_discount).c_str());
    BSON_APPEND_UTF8(doc,"check_limit", std::to_string(value.check_limit).c_str());
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct MESSAGE_PUB::ChangeClientMoney

auto to_csv(MESSAGE_PUB::ChangeClientMoney &value) {
    std::stringstream ss;
    ss << "ChangeClientMoney" <<",";
    ss << value.broker_code << ",";
    ss << value.mode << ",";
    ss << value.code << ",";
    ss << value.limit_money << ",";
    ss << value.is_auto_update_limit << ",";
    ss << value.check_limit << ",";
    return ss.str();
}


//struct MESSAGE_PUB::ChangeClientMoney

auto to_bson(MESSAGE_PUB::ChangeClientMoney &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"broker_code", value.broker_code);
    BSON_APPEND_UTF8(doc,"mode", std::to_string(value.mode).c_str());
    BSON_APPEND_UTF8(doc,"code", value.code);
    BSON_APPEND_UTF8(doc,"limit_money", value.limit_money);
    BSON_APPEND_UTF8(doc,"is_auto_update_limit", std::to_string(value.is_auto_update_limit).c_str());
    BSON_APPEND_UTF8(doc,"check_limit", std::to_string(value.check_limit).c_str());
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct MESSAGE_PUB::FORTS_MSG104

auto to_csv(MESSAGE_PUB::FORTS_MSG104 &value) {
    std::stringstream ss;
    ss << "FORTS_MSG104" <<",";
    ss << value.code << ",";
    ss << value.message << ",";
    return ss.str();
}


//struct MESSAGE_PUB::FORTS_MSG104

auto to_bson(MESSAGE_PUB::FORTS_MSG104 &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"code", std::to_string(value.code).c_str());
    BSON_APPEND_UTF8(doc,"message", value.message);
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct MESSAGE_PUB::FutChangeBFMoney

auto to_csv(MESSAGE_PUB::FutChangeBFMoney &value) {
    std::stringstream ss;
    ss << "FutChangeBFMoney" <<",";
    ss << value.broker_code << ",";
    ss << value.mode << ",";
    ss << value.code << ",";
    ss << value.limit_money << ",";
    return ss.str();
}


//struct MESSAGE_PUB::FutChangeBFMoney

auto to_bson(MESSAGE_PUB::FutChangeBFMoney &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"broker_code", value.broker_code);
    BSON_APPEND_UTF8(doc,"mode", std::to_string(value.mode).c_str());
    BSON_APPEND_UTF8(doc,"code", value.code);
    BSON_APPEND_UTF8(doc,"limit_money", value.limit_money);
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct MESSAGE_PUB::ChangeBFMoney

auto to_csv(MESSAGE_PUB::ChangeBFMoney &value) {
    std::stringstream ss;
    ss << "ChangeBFMoney" <<",";
    ss << value.broker_code << ",";
    ss << value.mode << ",";
    ss << value.code << ",";
    ss << value.limit_money << ",";
    return ss.str();
}


//struct MESSAGE_PUB::ChangeBFMoney

auto to_bson(MESSAGE_PUB::ChangeBFMoney &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"broker_code", value.broker_code);
    BSON_APPEND_UTF8(doc,"mode", std::to_string(value.mode).c_str());
    BSON_APPEND_UTF8(doc,"code", value.code);
    BSON_APPEND_UTF8(doc,"limit_money", value.limit_money);
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct MESSAGE_PUB::FORTS_MSG107

auto to_csv(MESSAGE_PUB::FORTS_MSG107 &value) {
    std::stringstream ss;
    ss << "FORTS_MSG107" <<",";
    ss << value.code << ",";
    ss << value.message << ",";
    return ss.str();
}


//struct MESSAGE_PUB::FORTS_MSG107

auto to_bson(MESSAGE_PUB::FORTS_MSG107 &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"code", std::to_string(value.code).c_str());
    BSON_APPEND_UTF8(doc,"message", value.message);
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct MESSAGE_PUB::FutMoveOrder

auto to_csv(MESSAGE_PUB::FutMoveOrder &value) {
    std::stringstream ss;
    ss << "FutMoveOrder" <<",";
    ss << value.broker_code << ",";
    ss << value.regime << ",";
    ss << value.order_id1 << ",";
    ss << value.amount1 << ",";
    ss << value.price1 << ",";
    ss << value.ext_id1 << ",";
    ss << value.order_id2 << ",";
    ss << value.amount2 << ",";
    ss << value.price2 << ",";
    ss << value.ext_id2 << ",";
    ss << std::to_string(cg_time_to_unix_time(value.local_stamp)).c_str() << ",";
    ss << int(value.ncc_request) << ",";
    return ss.str();
}


//struct MESSAGE_PUB::FutMoveOrder

auto to_bson(MESSAGE_PUB::FutMoveOrder &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"broker_code", value.broker_code);
    BSON_APPEND_UTF8(doc,"regime", std::to_string(value.regime).c_str());
    BSON_APPEND_UTF8(doc,"order_id1", std::to_string(value.order_id1).c_str());
    BSON_APPEND_UTF8(doc,"amount1", std::to_string(value.amount1).c_str());
    BSON_APPEND_UTF8(doc,"price1", value.price1);
    BSON_APPEND_UTF8(doc,"ext_id1", std::to_string(value.ext_id1).c_str());
    BSON_APPEND_UTF8(doc,"order_id2", std::to_string(value.order_id2).c_str());
    BSON_APPEND_UTF8(doc,"amount2", std::to_string(value.amount2).c_str());
    BSON_APPEND_UTF8(doc,"price2", value.price2);
    BSON_APPEND_UTF8(doc,"ext_id2", std::to_string(value.ext_id2).c_str());
    BSON_APPEND_UTF8(doc,"local_stamp", std::to_string(cg_time_to_unix_time(value.local_stamp)).c_str());
    BSON_APPEND_UTF8(doc,"ncc_request", std::to_string(value.ncc_request).c_str());
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct MESSAGE_PUB::FORTS_MSG105

auto to_csv(MESSAGE_PUB::FORTS_MSG105 &value) {
    std::stringstream ss;
    ss << "FORTS_MSG105" <<",";
    ss << value.code << ",";
    ss << value.message << ",";
    ss << value.order_id1 << ",";
    ss << value.order_id2 << ",";
    return ss.str();
}


//struct MESSAGE_PUB::FORTS_MSG105

auto to_bson(MESSAGE_PUB::FORTS_MSG105 &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"code", std::to_string(value.code).c_str());
    BSON_APPEND_UTF8(doc,"message", value.message);
    BSON_APPEND_UTF8(doc,"order_id1", std::to_string(value.order_id1).c_str());
    BSON_APPEND_UTF8(doc,"order_id2", std::to_string(value.order_id2).c_str());
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct MESSAGE_PUB::FutChangeClientProhibit

auto to_csv(MESSAGE_PUB::FutChangeClientProhibit &value) {
    std::stringstream ss;
    ss << "FutChangeClientProhibit" <<",";
    ss << value.broker_code << ",";
    ss << value.mode << ",";
    ss << value.code << ",";
    ss << value.base_contract_code << ",";
    ss << value.isin << ",";
    ss << value.state << ",";
    ss << value.state_mask << ",";
    return ss.str();
}


//struct MESSAGE_PUB::FutChangeClientProhibit

auto to_bson(MESSAGE_PUB::FutChangeClientProhibit &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"broker_code", value.broker_code);
    BSON_APPEND_UTF8(doc,"mode", std::to_string(value.mode).c_str());
    BSON_APPEND_UTF8(doc,"code", value.code);
    BSON_APPEND_UTF8(doc,"base_contract_code", value.base_contract_code);
    BSON_APPEND_UTF8(doc,"isin", value.isin);
    BSON_APPEND_UTF8(doc,"state", std::to_string(value.state).c_str());
    BSON_APPEND_UTF8(doc,"state_mask", std::to_string(value.state_mask).c_str());
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct MESSAGE_PUB::FORTS_MSG115

auto to_csv(MESSAGE_PUB::FORTS_MSG115 &value) {
    std::stringstream ss;
    ss << "FORTS_MSG115" <<",";
    ss << value.code << ",";
    ss << value.message << ",";
    return ss.str();
}


//struct MESSAGE_PUB::FORTS_MSG115

auto to_bson(MESSAGE_PUB::FORTS_MSG115 &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"code", std::to_string(value.code).c_str());
    BSON_APPEND_UTF8(doc,"message", value.message);
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct MESSAGE_PUB::FutAddMultiLegOrder

auto to_csv(MESSAGE_PUB::FutAddMultiLegOrder &value) {
    std::stringstream ss;
    ss << "FutAddMultiLegOrder" <<",";
    ss << value.broker_code << ",";
    ss << value.sess_id << ",";
    ss << value.isin_id << ",";
    ss << value.client_code << ",";
    ss << value.type << ",";
    ss << value.dir << ",";
    ss << value.amount << ",";
    ss << value.swap_price << ",";
    ss << value.comment << ",";
    ss << value.broker_to << ",";
    ss << value.ext_id << ",";
    ss << value.date_exp << ",";
    ss << value.dont_check_money << ",";
    ss << std::to_string(cg_time_to_unix_time(value.local_stamp)).c_str() << ",";
    ss << value.match_ref << ",";
    ss << int(value.ncc_request) << ",";
    return ss.str();
}


//struct MESSAGE_PUB::FutAddMultiLegOrder

auto to_bson(MESSAGE_PUB::FutAddMultiLegOrder &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"broker_code", value.broker_code);
    BSON_APPEND_UTF8(doc,"sess_id", std::to_string(value.sess_id).c_str());
    BSON_APPEND_UTF8(doc,"isin_id", std::to_string(value.isin_id).c_str());
    BSON_APPEND_UTF8(doc,"client_code", value.client_code);
    BSON_APPEND_UTF8(doc,"type", std::to_string(value.type).c_str());
    BSON_APPEND_UTF8(doc,"dir", std::to_string(value.dir).c_str());
    BSON_APPEND_UTF8(doc,"amount", std::to_string(value.amount).c_str());
    BSON_APPEND_UTF8(doc,"swap_price", value.swap_price);
    BSON_APPEND_UTF8(doc,"comment", value.comment);
    BSON_APPEND_UTF8(doc,"broker_to", value.broker_to);
    BSON_APPEND_UTF8(doc,"ext_id", std::to_string(value.ext_id).c_str());
    BSON_APPEND_UTF8(doc,"date_exp", value.date_exp);
    BSON_APPEND_UTF8(doc,"dont_check_money", std::to_string(value.dont_check_money).c_str());
    BSON_APPEND_UTF8(doc,"local_stamp", std::to_string(cg_time_to_unix_time(value.local_stamp)).c_str());
    BSON_APPEND_UTF8(doc,"match_ref", value.match_ref);
    BSON_APPEND_UTF8(doc,"ncc_request", std::to_string(value.ncc_request).c_str());
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct MESSAGE_PUB::FORTS_MSG129

auto to_csv(MESSAGE_PUB::FORTS_MSG129 &value) {
    std::stringstream ss;
    ss << "FORTS_MSG129" <<",";
    ss << value.code << ",";
    ss << value.message << ",";
    ss << value.order_id << ",";
    return ss.str();
}


//struct MESSAGE_PUB::FORTS_MSG129

auto to_bson(MESSAGE_PUB::FORTS_MSG129 &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"code", std::to_string(value.code).c_str());
    BSON_APPEND_UTF8(doc,"message", value.message);
    BSON_APPEND_UTF8(doc,"order_id", std::to_string(value.order_id).c_str());
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct MESSAGE_PUB::FutExchangeBFMoney

auto to_csv(MESSAGE_PUB::FutExchangeBFMoney &value) {
    std::stringstream ss;
    ss << "FutExchangeBFMoney" <<",";
    ss << value.broker_code << ",";
    ss << value.mode << ",";
    ss << value.code_from << ",";
    ss << value.code_to << ",";
    ss << value.amount_money << ",";
    return ss.str();
}


//struct MESSAGE_PUB::FutExchangeBFMoney

auto to_bson(MESSAGE_PUB::FutExchangeBFMoney &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"broker_code", value.broker_code);
    BSON_APPEND_UTF8(doc,"mode", std::to_string(value.mode).c_str());
    BSON_APPEND_UTF8(doc,"code_from", value.code_from);
    BSON_APPEND_UTF8(doc,"code_to", value.code_to);
    BSON_APPEND_UTF8(doc,"amount_money", value.amount_money);
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct MESSAGE_PUB::ExchangeBFMoney

auto to_csv(MESSAGE_PUB::ExchangeBFMoney &value) {
    std::stringstream ss;
    ss << "ExchangeBFMoney" <<",";
    ss << value.broker_code << ",";
    ss << value.mode << ",";
    ss << value.code_from << ",";
    ss << value.code_to << ",";
    ss << value.amount_money << ",";
    return ss.str();
}


//struct MESSAGE_PUB::ExchangeBFMoney

auto to_bson(MESSAGE_PUB::ExchangeBFMoney &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"broker_code", value.broker_code);
    BSON_APPEND_UTF8(doc,"mode", std::to_string(value.mode).c_str());
    BSON_APPEND_UTF8(doc,"code_from", value.code_from);
    BSON_APPEND_UTF8(doc,"code_to", value.code_to);
    BSON_APPEND_UTF8(doc,"amount_money", value.amount_money);
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct MESSAGE_PUB::FORTS_MSG130

auto to_csv(MESSAGE_PUB::FORTS_MSG130 &value) {
    std::stringstream ss;
    ss << "FORTS_MSG130" <<",";
    ss << value.code << ",";
    ss << value.message << ",";
    return ss.str();
}


//struct MESSAGE_PUB::FORTS_MSG130

auto to_bson(MESSAGE_PUB::FORTS_MSG130 &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"code", std::to_string(value.code).c_str());
    BSON_APPEND_UTF8(doc,"message", value.message);
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct MESSAGE_PUB::FutTransferClientPosition

auto to_csv(MESSAGE_PUB::FutTransferClientPosition &value) {
    std::stringstream ss;
    ss << "FutTransferClientPosition" <<",";
    ss << value.broker_code << ",";
    ss << value.code_from << ",";
    ss << value.code_to << ",";
    ss << value.isin << ",";
    ss << value.amount << ",";
    return ss.str();
}


//struct MESSAGE_PUB::FutTransferClientPosition

auto to_bson(MESSAGE_PUB::FutTransferClientPosition &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"broker_code", value.broker_code);
    BSON_APPEND_UTF8(doc,"code_from", value.code_from);
    BSON_APPEND_UTF8(doc,"code_to", value.code_to);
    BSON_APPEND_UTF8(doc,"isin", value.isin);
    BSON_APPEND_UTF8(doc,"amount", std::to_string(value.amount).c_str());
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct MESSAGE_PUB::FORTS_MSG137

auto to_csv(MESSAGE_PUB::FORTS_MSG137 &value) {
    std::stringstream ss;
    ss << "FORTS_MSG137" <<",";
    ss << value.code << ",";
    ss << value.message << ",";
    return ss.str();
}


//struct MESSAGE_PUB::FORTS_MSG137

auto to_bson(MESSAGE_PUB::FORTS_MSG137 &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"code", std::to_string(value.code).c_str());
    BSON_APPEND_UTF8(doc,"message", value.message);
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct MESSAGE_PUB::TransferClientPosition

auto to_csv(MESSAGE_PUB::TransferClientPosition &value) {
    std::stringstream ss;
    ss << "TransferClientPosition" <<",";
    ss << value.broker_code << ",";
    ss << value.code_from << ",";
    ss << value.code_to << ",";
    ss << value.isin << ",";
    ss << value.amount << ",";
    return ss.str();
}


//struct MESSAGE_PUB::TransferClientPosition

auto to_bson(MESSAGE_PUB::TransferClientPosition &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"broker_code", value.broker_code);
    BSON_APPEND_UTF8(doc,"code_from", value.code_from);
    BSON_APPEND_UTF8(doc,"code_to", value.code_to);
    BSON_APPEND_UTF8(doc,"isin", value.isin);
    BSON_APPEND_UTF8(doc,"amount", std::to_string(value.amount).c_str());
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct MESSAGE_PUB::FORTS_MSG173

auto to_csv(MESSAGE_PUB::FORTS_MSG173 &value) {
    std::stringstream ss;
    ss << "FORTS_MSG173" <<",";
    ss << value.code << ",";
    ss << value.message << ",";
    return ss.str();
}


//struct MESSAGE_PUB::FORTS_MSG173

auto to_bson(MESSAGE_PUB::FORTS_MSG173 &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"code", std::to_string(value.code).c_str());
    BSON_APPEND_UTF8(doc,"message", value.message);
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct MESSAGE_PUB::FutChangeBFLimit

auto to_csv(MESSAGE_PUB::FutChangeBFLimit &value) {
    std::stringstream ss;
    ss << "FutChangeBFLimit" <<",";
    ss << value.broker_code << ",";
    ss << value.mode << ",";
    ss << value.code << ",";
    ss << value.limit_money << ",";
    ss << value.check_limit << ",";
    return ss.str();
}


//struct MESSAGE_PUB::FutChangeBFLimit

auto to_bson(MESSAGE_PUB::FutChangeBFLimit &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"broker_code", value.broker_code);
    BSON_APPEND_UTF8(doc,"mode", std::to_string(value.mode).c_str());
    BSON_APPEND_UTF8(doc,"code", value.code);
    BSON_APPEND_UTF8(doc,"limit_money", value.limit_money);
    BSON_APPEND_UTF8(doc,"check_limit", std::to_string(value.check_limit).c_str());
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct MESSAGE_PUB::ChangeBFLimit

auto to_csv(MESSAGE_PUB::ChangeBFLimit &value) {
    std::stringstream ss;
    ss << "ChangeBFLimit" <<",";
    ss << value.broker_code << ",";
    ss << value.mode << ",";
    ss << value.code << ",";
    ss << value.limit_money << ",";
    ss << value.check_limit << ",";
    return ss.str();
}


//struct MESSAGE_PUB::ChangeBFLimit

auto to_bson(MESSAGE_PUB::ChangeBFLimit &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"broker_code", value.broker_code);
    BSON_APPEND_UTF8(doc,"mode", std::to_string(value.mode).c_str());
    BSON_APPEND_UTF8(doc,"code", value.code);
    BSON_APPEND_UTF8(doc,"limit_money", value.limit_money);
    BSON_APPEND_UTF8(doc,"check_limit", std::to_string(value.check_limit).c_str());
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct MESSAGE_PUB::FORTS_MSG161

auto to_csv(MESSAGE_PUB::FORTS_MSG161 &value) {
    std::stringstream ss;
    ss << "FORTS_MSG161" <<",";
    ss << value.code << ",";
    ss << value.message << ",";
    return ss.str();
}


//struct MESSAGE_PUB::FORTS_MSG161

auto to_bson(MESSAGE_PUB::FORTS_MSG161 &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"code", std::to_string(value.code).c_str());
    BSON_APPEND_UTF8(doc,"message", value.message);
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct MESSAGE_PUB::FutChangeBFParameters

auto to_csv(MESSAGE_PUB::FutChangeBFParameters &value) {
    std::stringstream ss;
    ss << "FutChangeBFParameters" <<",";
    ss << value.broker_code << ",";
    ss << value.code_bf << ",";
    ss << value.margin_type << ",";
    ss << value.calendar_spread_margin_type << ",";
    ss << value.num_clr_2delivery << ",";
    ss << value.exp_weight << ",";
    ss << value.go_ratio << ",";
    ss << value.check_limit_on_withdrawal << ",";
    ss << value.limit_tied_to_money << ",";
    ss << value.check_limit_for_orders << ",";
    ss << value.no_fut_discount << ",";
    return ss.str();
}


//struct MESSAGE_PUB::FutChangeBFParameters

auto to_bson(MESSAGE_PUB::FutChangeBFParameters &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"broker_code", value.broker_code);
    BSON_APPEND_UTF8(doc,"code_bf", value.code_bf);
    BSON_APPEND_UTF8(doc,"margin_type", std::to_string(value.margin_type).c_str());
    BSON_APPEND_UTF8(doc,"calendar_spread_margin_type", std::to_string(value.calendar_spread_margin_type).c_str());
    BSON_APPEND_UTF8(doc,"num_clr_2delivery", std::to_string(value.num_clr_2delivery).c_str());
    BSON_APPEND_UTF8(doc,"exp_weight", value.exp_weight);
    BSON_APPEND_UTF8(doc,"go_ratio", value.go_ratio);
    BSON_APPEND_UTF8(doc,"check_limit_on_withdrawal", std::to_string(value.check_limit_on_withdrawal).c_str());
    BSON_APPEND_UTF8(doc,"limit_tied_to_money", std::to_string(value.limit_tied_to_money).c_str());
    BSON_APPEND_UTF8(doc,"check_limit_for_orders", std::to_string(value.check_limit_for_orders).c_str());
    BSON_APPEND_UTF8(doc,"no_fut_discount", std::to_string(value.no_fut_discount).c_str());
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct MESSAGE_PUB::ChangeBFParameters

auto to_csv(MESSAGE_PUB::ChangeBFParameters &value) {
    std::stringstream ss;
    ss << "ChangeBFParameters" <<",";
    ss << value.broker_code << ",";
    ss << value.code_bf << ",";
    ss << value.margin_type << ",";
    ss << value.calendar_spread_margin_type << ",";
    ss << value.num_clr_2delivery << ",";
    ss << value.exp_weight << ",";
    ss << value.go_ratio << ",";
    ss << value.check_limit_on_withdrawal << ",";
    ss << value.limit_tied_to_money << ",";
    ss << value.check_limit_for_orders << ",";
    ss << value.no_fut_discount << ",";
    ss << value.ics_margin_type << ",";
    return ss.str();
}


//struct MESSAGE_PUB::ChangeBFParameters

auto to_bson(MESSAGE_PUB::ChangeBFParameters &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"broker_code", value.broker_code);
    BSON_APPEND_UTF8(doc,"code_bf", value.code_bf);
    BSON_APPEND_UTF8(doc,"margin_type", std::to_string(value.margin_type).c_str());
    BSON_APPEND_UTF8(doc,"calendar_spread_margin_type", std::to_string(value.calendar_spread_margin_type).c_str());
    BSON_APPEND_UTF8(doc,"num_clr_2delivery", std::to_string(value.num_clr_2delivery).c_str());
    BSON_APPEND_UTF8(doc,"exp_weight", value.exp_weight);
    BSON_APPEND_UTF8(doc,"go_ratio", value.go_ratio);
    BSON_APPEND_UTF8(doc,"check_limit_on_withdrawal", std::to_string(value.check_limit_on_withdrawal).c_str());
    BSON_APPEND_UTF8(doc,"limit_tied_to_money", std::to_string(value.limit_tied_to_money).c_str());
    BSON_APPEND_UTF8(doc,"check_limit_for_orders", std::to_string(value.check_limit_for_orders).c_str());
    BSON_APPEND_UTF8(doc,"no_fut_discount", std::to_string(value.no_fut_discount).c_str());
    BSON_APPEND_UTF8(doc,"ics_margin_type", std::to_string(value.ics_margin_type).c_str());
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct MESSAGE_PUB::FORTS_MSG162

auto to_csv(MESSAGE_PUB::FORTS_MSG162 &value) {
    std::stringstream ss;
    ss << "FORTS_MSG162" <<",";
    ss << value.code << ",";
    ss << value.message << ",";
    return ss.str();
}


//struct MESSAGE_PUB::FORTS_MSG162

auto to_bson(MESSAGE_PUB::FORTS_MSG162 &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"code", std::to_string(value.code).c_str());
    BSON_APPEND_UTF8(doc,"message", value.message);
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct MESSAGE_PUB::ChangeClientParametersNextSession

auto to_csv(MESSAGE_PUB::ChangeClientParametersNextSession &value) {
    std::stringstream ss;
    ss << "ChangeClientParametersNextSession" <<",";
    ss << value.broker_code << ",";
    ss << value.code << ",";
    ss << value.calendar_spread_margin_type << ",";
    ss << value.ics_margin_type << ",";
    return ss.str();
}


//struct MESSAGE_PUB::ChangeClientParametersNextSession

auto to_bson(MESSAGE_PUB::ChangeClientParametersNextSession &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"broker_code", value.broker_code);
    BSON_APPEND_UTF8(doc,"code", value.code);
    BSON_APPEND_UTF8(doc,"calendar_spread_margin_type", std::to_string(value.calendar_spread_margin_type).c_str());
    BSON_APPEND_UTF8(doc,"ics_margin_type", std::to_string(value.ics_margin_type).c_str());
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct MESSAGE_PUB::FORTS_MSG163

auto to_csv(MESSAGE_PUB::FORTS_MSG163 &value) {
    std::stringstream ss;
    ss << "FORTS_MSG163" <<",";
    ss << value.code << ",";
    ss << value.message << ",";
    return ss.str();
}


//struct MESSAGE_PUB::FORTS_MSG163

auto to_bson(MESSAGE_PUB::FORTS_MSG163 &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"code", std::to_string(value.code).c_str());
    BSON_APPEND_UTF8(doc,"message", value.message);
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct MESSAGE_PUB::ChangeBFClientDefaultParameters

auto to_csv(MESSAGE_PUB::ChangeBFClientDefaultParameters &value) {
    std::stringstream ss;
    ss << "ChangeBFClientDefaultParameters" <<",";
    ss << value.broker_code << ",";
    ss << value.code_bf << ",";
    ss << value.num_clr_2delivery_client_default << ",";
    ss << value.exp_weight_client_default << ",";
    ss << value.no_fut_discount_client_default << ",";
    return ss.str();
}


//struct MESSAGE_PUB::ChangeBFClientDefaultParameters

auto to_bson(MESSAGE_PUB::ChangeBFClientDefaultParameters &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"broker_code", value.broker_code);
    BSON_APPEND_UTF8(doc,"code_bf", value.code_bf);
    BSON_APPEND_UTF8(doc,"num_clr_2delivery_client_default", std::to_string(value.num_clr_2delivery_client_default).c_str());
    BSON_APPEND_UTF8(doc,"exp_weight_client_default", value.exp_weight_client_default);
    BSON_APPEND_UTF8(doc,"no_fut_discount_client_default", std::to_string(value.no_fut_discount_client_default).c_str());
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct MESSAGE_PUB::FORTS_MSG602

auto to_csv(MESSAGE_PUB::FORTS_MSG602 &value) {
    std::stringstream ss;
    ss << "FORTS_MSG602" <<",";
    ss << value.code << ",";
    ss << value.message << ",";
    return ss.str();
}


//struct MESSAGE_PUB::FORTS_MSG602

auto to_bson(MESSAGE_PUB::FORTS_MSG602 &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"code", std::to_string(value.code).c_str());
    BSON_APPEND_UTF8(doc,"message", value.message);
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct MESSAGE_PUB::OptAddOrder

auto to_csv(MESSAGE_PUB::OptAddOrder &value) {
    std::stringstream ss;
    ss << "OptAddOrder" <<",";
    ss << value.broker_code << ",";
    ss << value.isin << ",";
    ss << value.client_code << ",";
    ss << value.type << ",";
    ss << value.dir << ",";
    ss << value.amount << ",";
    ss << value.price << ",";
    ss << value.comment << ",";
    ss << value.broker_to << ",";
    ss << value.ext_id << ",";
    ss << value.check_limit << ",";
    ss << value.date_exp << ",";
    ss << value.dont_check_money << ",";
    ss << std::to_string(cg_time_to_unix_time(value.local_stamp)).c_str() << ",";
    ss << value.match_ref << ",";
    ss << int(value.ncc_request) << ",";
    return ss.str();
}


//struct MESSAGE_PUB::OptAddOrder

auto to_bson(MESSAGE_PUB::OptAddOrder &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"broker_code", value.broker_code);
    BSON_APPEND_UTF8(doc,"isin", value.isin);
    BSON_APPEND_UTF8(doc,"client_code", value.client_code);
    BSON_APPEND_UTF8(doc,"type", std::to_string(value.type).c_str());
    BSON_APPEND_UTF8(doc,"dir", std::to_string(value.dir).c_str());
    BSON_APPEND_UTF8(doc,"amount", std::to_string(value.amount).c_str());
    BSON_APPEND_UTF8(doc,"price", value.price);
    BSON_APPEND_UTF8(doc,"comment", value.comment);
    BSON_APPEND_UTF8(doc,"broker_to", value.broker_to);
    BSON_APPEND_UTF8(doc,"ext_id", std::to_string(value.ext_id).c_str());
    BSON_APPEND_UTF8(doc,"check_limit", std::to_string(value.check_limit).c_str());
    BSON_APPEND_UTF8(doc,"date_exp", value.date_exp);
    BSON_APPEND_UTF8(doc,"dont_check_money", std::to_string(value.dont_check_money).c_str());
    BSON_APPEND_UTF8(doc,"local_stamp", std::to_string(cg_time_to_unix_time(value.local_stamp)).c_str());
    BSON_APPEND_UTF8(doc,"match_ref", value.match_ref);
    BSON_APPEND_UTF8(doc,"ncc_request", std::to_string(value.ncc_request).c_str());
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct MESSAGE_PUB::FORTS_MSG109

auto to_csv(MESSAGE_PUB::FORTS_MSG109 &value) {
    std::stringstream ss;
    ss << "FORTS_MSG109" <<",";
    ss << value.code << ",";
    ss << value.message << ",";
    ss << value.order_id << ",";
    return ss.str();
}


//struct MESSAGE_PUB::FORTS_MSG109

auto to_bson(MESSAGE_PUB::FORTS_MSG109 &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"code", std::to_string(value.code).c_str());
    BSON_APPEND_UTF8(doc,"message", value.message);
    BSON_APPEND_UTF8(doc,"order_id", std::to_string(value.order_id).c_str());
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct MESSAGE_PUB::OptDelOrder

auto to_csv(MESSAGE_PUB::OptDelOrder &value) {
    std::stringstream ss;
    ss << "OptDelOrder" <<",";
    ss << value.broker_code << ",";
    ss << value.order_id << ",";
    ss << std::to_string(cg_time_to_unix_time(value.local_stamp)).c_str() << ",";
    ss << int(value.ncc_request) << ",";
    return ss.str();
}


//struct MESSAGE_PUB::OptDelOrder

auto to_bson(MESSAGE_PUB::OptDelOrder &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"broker_code", value.broker_code);
    BSON_APPEND_UTF8(doc,"order_id", std::to_string(value.order_id).c_str());
    BSON_APPEND_UTF8(doc,"local_stamp", std::to_string(cg_time_to_unix_time(value.local_stamp)).c_str());
    BSON_APPEND_UTF8(doc,"ncc_request", std::to_string(value.ncc_request).c_str());
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct MESSAGE_PUB::FORTS_MSG110

auto to_csv(MESSAGE_PUB::FORTS_MSG110 &value) {
    std::stringstream ss;
    ss << "FORTS_MSG110" <<",";
    ss << value.code << ",";
    ss << value.message << ",";
    ss << value.amount << ",";
    return ss.str();
}


//struct MESSAGE_PUB::FORTS_MSG110

auto to_bson(MESSAGE_PUB::FORTS_MSG110 &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"code", std::to_string(value.code).c_str());
    BSON_APPEND_UTF8(doc,"message", value.message);
    BSON_APPEND_UTF8(doc,"amount", std::to_string(value.amount).c_str());
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct MESSAGE_PUB::OptDelUserOrders

auto to_csv(MESSAGE_PUB::OptDelUserOrders &value) {
    std::stringstream ss;
    ss << "OptDelUserOrders" <<",";
    ss << value.broker_code << ",";
    ss << value.buy_sell << ",";
    ss << value.non_system << ",";
    ss << value.code << ",";
    ss << value.base_contract_code << ",";
    ss << value.ext_id << ",";
    ss << value.work_mode << ",";
    ss << value.isin << ",";
    ss << std::to_string(cg_time_to_unix_time(value.local_stamp)).c_str() << ",";
    return ss.str();
}


//struct MESSAGE_PUB::OptDelUserOrders

auto to_bson(MESSAGE_PUB::OptDelUserOrders &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"broker_code", value.broker_code);
    BSON_APPEND_UTF8(doc,"buy_sell", std::to_string(value.buy_sell).c_str());
    BSON_APPEND_UTF8(doc,"non_system", std::to_string(value.non_system).c_str());
    BSON_APPEND_UTF8(doc,"code", value.code);
    BSON_APPEND_UTF8(doc,"base_contract_code", value.base_contract_code);
    BSON_APPEND_UTF8(doc,"ext_id", std::to_string(value.ext_id).c_str());
    BSON_APPEND_UTF8(doc,"work_mode", std::to_string(value.work_mode).c_str());
    BSON_APPEND_UTF8(doc,"isin", value.isin);
    BSON_APPEND_UTF8(doc,"local_stamp", std::to_string(cg_time_to_unix_time(value.local_stamp)).c_str());
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct MESSAGE_PUB::FORTS_MSG111

auto to_csv(MESSAGE_PUB::FORTS_MSG111 &value) {
    std::stringstream ss;
    ss << "FORTS_MSG111" <<",";
    ss << value.code << ",";
    ss << value.message << ",";
    ss << value.num_orders << ",";
    return ss.str();
}


//struct MESSAGE_PUB::FORTS_MSG111

auto to_bson(MESSAGE_PUB::FORTS_MSG111 &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"code", std::to_string(value.code).c_str());
    BSON_APPEND_UTF8(doc,"message", value.message);
    BSON_APPEND_UTF8(doc,"num_orders", std::to_string(value.num_orders).c_str());
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct MESSAGE_PUB::OptChangeExpiration

auto to_csv(MESSAGE_PUB::OptChangeExpiration &value) {
    std::stringstream ss;
    ss << "OptChangeExpiration" <<",";
    ss << value.broker_code << ",";
    ss << value.mode << ",";
    ss << value.order_id << ",";
    ss << value.code << ",";
    ss << value.isin << ",";
    ss << value.amount << ",";
    return ss.str();
}


//struct MESSAGE_PUB::OptChangeExpiration

auto to_bson(MESSAGE_PUB::OptChangeExpiration &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"broker_code", value.broker_code);
    BSON_APPEND_UTF8(doc,"mode", std::to_string(value.mode).c_str());
    BSON_APPEND_UTF8(doc,"order_id", std::to_string(value.order_id).c_str());
    BSON_APPEND_UTF8(doc,"code", value.code);
    BSON_APPEND_UTF8(doc,"isin", value.isin);
    BSON_APPEND_UTF8(doc,"amount", std::to_string(value.amount).c_str());
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct MESSAGE_PUB::FORTS_MSG112

auto to_csv(MESSAGE_PUB::FORTS_MSG112 &value) {
    std::stringstream ss;
    ss << "FORTS_MSG112" <<",";
    ss << value.code << ",";
    ss << value.message << ",";
    ss << value.order_id << ",";
    return ss.str();
}


//struct MESSAGE_PUB::FORTS_MSG112

auto to_bson(MESSAGE_PUB::FORTS_MSG112 &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"code", std::to_string(value.code).c_str());
    BSON_APPEND_UTF8(doc,"message", value.message);
    BSON_APPEND_UTF8(doc,"order_id", std::to_string(value.order_id).c_str());
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct MESSAGE_PUB::OptMoveOrder

auto to_csv(MESSAGE_PUB::OptMoveOrder &value) {
    std::stringstream ss;
    ss << "OptMoveOrder" <<",";
    ss << value.broker_code << ",";
    ss << value.regime << ",";
    ss << value.order_id1 << ",";
    ss << value.amount1 << ",";
    ss << value.price1 << ",";
    ss << value.ext_id1 << ",";
    ss << value.check_limit << ",";
    ss << value.order_id2 << ",";
    ss << value.amount2 << ",";
    ss << value.price2 << ",";
    ss << value.ext_id2 << ",";
    ss << std::to_string(cg_time_to_unix_time(value.local_stamp)).c_str() << ",";
    ss << int(value.ncc_request) << ",";
    return ss.str();
}


//struct MESSAGE_PUB::OptMoveOrder

auto to_bson(MESSAGE_PUB::OptMoveOrder &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"broker_code", value.broker_code);
    BSON_APPEND_UTF8(doc,"regime", std::to_string(value.regime).c_str());
    BSON_APPEND_UTF8(doc,"order_id1", std::to_string(value.order_id1).c_str());
    BSON_APPEND_UTF8(doc,"amount1", std::to_string(value.amount1).c_str());
    BSON_APPEND_UTF8(doc,"price1", value.price1);
    BSON_APPEND_UTF8(doc,"ext_id1", std::to_string(value.ext_id1).c_str());
    BSON_APPEND_UTF8(doc,"check_limit", std::to_string(value.check_limit).c_str());
    BSON_APPEND_UTF8(doc,"order_id2", std::to_string(value.order_id2).c_str());
    BSON_APPEND_UTF8(doc,"amount2", std::to_string(value.amount2).c_str());
    BSON_APPEND_UTF8(doc,"price2", value.price2);
    BSON_APPEND_UTF8(doc,"ext_id2", std::to_string(value.ext_id2).c_str());
    BSON_APPEND_UTF8(doc,"local_stamp", std::to_string(cg_time_to_unix_time(value.local_stamp)).c_str());
    BSON_APPEND_UTF8(doc,"ncc_request", std::to_string(value.ncc_request).c_str());
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct MESSAGE_PUB::FORTS_MSG113

auto to_csv(MESSAGE_PUB::FORTS_MSG113 &value) {
    std::stringstream ss;
    ss << "FORTS_MSG113" <<",";
    ss << value.code << ",";
    ss << value.message << ",";
    ss << value.order_id1 << ",";
    ss << value.order_id2 << ",";
    return ss.str();
}


//struct MESSAGE_PUB::FORTS_MSG113

auto to_bson(MESSAGE_PUB::FORTS_MSG113 &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"code", std::to_string(value.code).c_str());
    BSON_APPEND_UTF8(doc,"message", value.message);
    BSON_APPEND_UTF8(doc,"order_id1", std::to_string(value.order_id1).c_str());
    BSON_APPEND_UTF8(doc,"order_id2", std::to_string(value.order_id2).c_str());
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct MESSAGE_PUB::OptChangeClientProhibit

auto to_csv(MESSAGE_PUB::OptChangeClientProhibit &value) {
    std::stringstream ss;
    ss << "OptChangeClientProhibit" <<",";
    ss << value.broker_code << ",";
    ss << value.mode << ",";
    ss << value.code << ",";
    ss << value.base_contract_code << ",";
    ss << value.isin << ",";
    ss << value.state << ",";
    ss << value.state_mask << ",";
    return ss.str();
}


//struct MESSAGE_PUB::OptChangeClientProhibit

auto to_bson(MESSAGE_PUB::OptChangeClientProhibit &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"broker_code", value.broker_code);
    BSON_APPEND_UTF8(doc,"mode", std::to_string(value.mode).c_str());
    BSON_APPEND_UTF8(doc,"code", value.code);
    BSON_APPEND_UTF8(doc,"base_contract_code", value.base_contract_code);
    BSON_APPEND_UTF8(doc,"isin", value.isin);
    BSON_APPEND_UTF8(doc,"state", std::to_string(value.state).c_str());
    BSON_APPEND_UTF8(doc,"state_mask", std::to_string(value.state_mask).c_str());
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct MESSAGE_PUB::FORTS_MSG117

auto to_csv(MESSAGE_PUB::FORTS_MSG117 &value) {
    std::stringstream ss;
    ss << "FORTS_MSG117" <<",";
    ss << value.code << ",";
    ss << value.message << ",";
    return ss.str();
}


//struct MESSAGE_PUB::FORTS_MSG117

auto to_bson(MESSAGE_PUB::FORTS_MSG117 &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"code", std::to_string(value.code).c_str());
    BSON_APPEND_UTF8(doc,"message", value.message);
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct MESSAGE_PUB::OptRecalcCS

auto to_csv(MESSAGE_PUB::OptRecalcCS &value) {
    std::stringstream ss;
    ss << "OptRecalcCS" <<",";
    ss << value.broker_code << ",";
    ss << value.option_series_id << ",";
    return ss.str();
}


//struct MESSAGE_PUB::OptRecalcCS

auto to_bson(MESSAGE_PUB::OptRecalcCS &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"broker_code", value.broker_code);
    BSON_APPEND_UTF8(doc,"option_series_id", std::to_string(value.option_series_id).c_str());
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct MESSAGE_PUB::FORTS_MSG132

auto to_csv(MESSAGE_PUB::FORTS_MSG132 &value) {
    std::stringstream ss;
    ss << "FORTS_MSG132" <<",";
    ss << value.code << ",";
    ss << value.message << ",";
    return ss.str();
}


//struct MESSAGE_PUB::FORTS_MSG132

auto to_bson(MESSAGE_PUB::FORTS_MSG132 &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"code", std::to_string(value.code).c_str());
    BSON_APPEND_UTF8(doc,"message", value.message);
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct MESSAGE_PUB::OptTransferClientPosition

auto to_csv(MESSAGE_PUB::OptTransferClientPosition &value) {
    std::stringstream ss;
    ss << "OptTransferClientPosition" <<",";
    ss << value.broker_code << ",";
    ss << value.code_from << ",";
    ss << value.code_to << ",";
    ss << value.isin << ",";
    ss << value.amount << ",";
    return ss.str();
}


//struct MESSAGE_PUB::OptTransferClientPosition

auto to_bson(MESSAGE_PUB::OptTransferClientPosition &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"broker_code", value.broker_code);
    BSON_APPEND_UTF8(doc,"code_from", value.code_from);
    BSON_APPEND_UTF8(doc,"code_to", value.code_to);
    BSON_APPEND_UTF8(doc,"isin", value.isin);
    BSON_APPEND_UTF8(doc,"amount", std::to_string(value.amount).c_str());
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct MESSAGE_PUB::FORTS_MSG138

auto to_csv(MESSAGE_PUB::FORTS_MSG138 &value) {
    std::stringstream ss;
    ss << "FORTS_MSG138" <<",";
    ss << value.code << ",";
    ss << value.message << ",";
    return ss.str();
}


//struct MESSAGE_PUB::FORTS_MSG138

auto to_bson(MESSAGE_PUB::FORTS_MSG138 &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"code", std::to_string(value.code).c_str());
    BSON_APPEND_UTF8(doc,"message", value.message);
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct MESSAGE_PUB::OptChangeRiskParameters

auto to_csv(MESSAGE_PUB::OptChangeRiskParameters &value) {
    std::stringstream ss;
    ss << "OptChangeRiskParameters" <<",";
    ss << value.broker_code << ",";
    ss << value.client_code << ",";
    ss << value.num_clr_2delivery << ",";
    ss << int(value.use_broker_num_clr_2delivery) << ",";
    ss << value.exp_weight << ",";
    ss << int(value.use_broker_exp_weight) << ",";
    ss << value.short_option_minimum_charge_ratio << ",";
    return ss.str();
}


//struct MESSAGE_PUB::OptChangeRiskParameters

auto to_bson(MESSAGE_PUB::OptChangeRiskParameters &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"broker_code", value.broker_code);
    BSON_APPEND_UTF8(doc,"client_code", value.client_code);
    BSON_APPEND_UTF8(doc,"num_clr_2delivery", std::to_string(value.num_clr_2delivery).c_str());
    BSON_APPEND_UTF8(doc,"use_broker_num_clr_2delivery", std::to_string(value.use_broker_num_clr_2delivery).c_str());
    BSON_APPEND_UTF8(doc,"exp_weight", value.exp_weight);
    BSON_APPEND_UTF8(doc,"use_broker_exp_weight", std::to_string(value.use_broker_exp_weight).c_str());
    BSON_APPEND_UTF8(doc,"short_option_minimum_charge_ratio", value.short_option_minimum_charge_ratio);
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct MESSAGE_PUB::FORTS_MSG140

auto to_csv(MESSAGE_PUB::FORTS_MSG140 &value) {
    std::stringstream ss;
    ss << "FORTS_MSG140" <<",";
    ss << value.code << ",";
    ss << value.message << ",";
    return ss.str();
}


//struct MESSAGE_PUB::FORTS_MSG140

auto to_bson(MESSAGE_PUB::FORTS_MSG140 &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"code", std::to_string(value.code).c_str());
    BSON_APPEND_UTF8(doc,"message", value.message);
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct MESSAGE_PUB::SetSmaPreTradeCheck

auto to_csv(MESSAGE_PUB::SetSmaPreTradeCheck &value) {
    std::stringstream ss;
    ss << "SetSmaPreTradeCheck" <<",";
    ss << value.broker_code << ",";
    ss << value.sma_asp << ",";
    ss << int(value.check_number) << ",";
    ss << value.base_contract_code << ",";
    ss << int(value.instrument_type) << ",";
    ss << value.client_code_check << ",";
    ss << value.value << ",";
    return ss.str();
}


//struct MESSAGE_PUB::SetSmaPreTradeCheck

auto to_bson(MESSAGE_PUB::SetSmaPreTradeCheck &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"broker_code", value.broker_code);
    BSON_APPEND_UTF8(doc,"sma_asp", value.sma_asp);
    BSON_APPEND_UTF8(doc,"check_number", std::to_string(value.check_number).c_str());
    BSON_APPEND_UTF8(doc,"base_contract_code", value.base_contract_code);
    BSON_APPEND_UTF8(doc,"instrument_type", std::to_string(value.instrument_type).c_str());
    BSON_APPEND_UTF8(doc,"client_code_check", value.client_code_check);
    BSON_APPEND_UTF8(doc,"value", value.value);
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct MESSAGE_PUB::FORTS_MSG166

auto to_csv(MESSAGE_PUB::FORTS_MSG166 &value) {
    std::stringstream ss;
    ss << "FORTS_MSG166" <<",";
    ss << value.code << ",";
    ss << value.message << ",";
    return ss.str();
}


//struct MESSAGE_PUB::FORTS_MSG166

auto to_bson(MESSAGE_PUB::FORTS_MSG166 &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"code", std::to_string(value.code).c_str());
    BSON_APPEND_UTF8(doc,"message", value.message);
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct MESSAGE_PUB::DelSmaPreTradeCheck

auto to_csv(MESSAGE_PUB::DelSmaPreTradeCheck &value) {
    std::stringstream ss;
    ss << "DelSmaPreTradeCheck" <<",";
    ss << value.broker_code << ",";
    ss << value.check_id << ",";
    return ss.str();
}


//struct MESSAGE_PUB::DelSmaPreTradeCheck

auto to_bson(MESSAGE_PUB::DelSmaPreTradeCheck &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"broker_code", value.broker_code);
    BSON_APPEND_UTF8(doc,"check_id", std::to_string(value.check_id).c_str());
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct MESSAGE_PUB::FORTS_MSG167

auto to_csv(MESSAGE_PUB::FORTS_MSG167 &value) {
    std::stringstream ss;
    ss << "FORTS_MSG167" <<",";
    ss << value.code << ",";
    ss << value.message << ",";
    return ss.str();
}


//struct MESSAGE_PUB::FORTS_MSG167

auto to_bson(MESSAGE_PUB::FORTS_MSG167 &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"code", std::to_string(value.code).c_str());
    BSON_APPEND_UTF8(doc,"message", value.message);
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct MESSAGE_PUB::UserKillSwitch

auto to_csv(MESSAGE_PUB::UserKillSwitch &value) {
    std::stringstream ss;
    ss << "UserKillSwitch" <<",";
    ss << value.login << ",";
    ss << int(value.disable) << ",";
    ss << int(value.cancel_orders) << ",";
    return ss.str();
}


//struct MESSAGE_PUB::UserKillSwitch

auto to_bson(MESSAGE_PUB::UserKillSwitch &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"login", value.login);
    BSON_APPEND_UTF8(doc,"disable", std::to_string(value.disable).c_str());
    BSON_APPEND_UTF8(doc,"cancel_orders", std::to_string(value.cancel_orders).c_str());
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct MESSAGE_PUB::FORTS_MSG168

auto to_csv(MESSAGE_PUB::FORTS_MSG168 &value) {
    std::stringstream ss;
    ss << "FORTS_MSG168" <<",";
    ss << value.code << ",";
    ss << value.message << ",";
    ss << value.num_orders << ",";
    return ss.str();
}


//struct MESSAGE_PUB::FORTS_MSG168

auto to_bson(MESSAGE_PUB::FORTS_MSG168 &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"code", std::to_string(value.code).c_str());
    BSON_APPEND_UTF8(doc,"message", value.message);
    BSON_APPEND_UTF8(doc,"num_orders", std::to_string(value.num_orders).c_str());
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct MESSAGE_PUB::DelOrdersByBFLimit

auto to_csv(MESSAGE_PUB::DelOrdersByBFLimit &value) {
    std::stringstream ss;
    ss << "DelOrdersByBFLimit" <<",";
    ss << value.broker_code << ",";
    return ss.str();
}


//struct MESSAGE_PUB::DelOrdersByBFLimit

auto to_bson(MESSAGE_PUB::DelOrdersByBFLimit &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"broker_code", value.broker_code);
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct MESSAGE_PUB::FORTS_MSG172

auto to_csv(MESSAGE_PUB::FORTS_MSG172 &value) {
    std::stringstream ss;
    ss << "FORTS_MSG172" <<",";
    ss << value.code << ",";
    ss << value.message << ",";
    ss << value.num_orders << ",";
    return ss.str();
}


//struct MESSAGE_PUB::FORTS_MSG172

auto to_bson(MESSAGE_PUB::FORTS_MSG172 &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"code", std::to_string(value.code).c_str());
    BSON_APPEND_UTF8(doc,"message", value.message);
    BSON_APPEND_UTF8(doc,"num_orders", std::to_string(value.num_orders).c_str());
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct MESSAGE_PUB::FutTransferRisk

auto to_csv(MESSAGE_PUB::FutTransferRisk &value) {
    std::stringstream ss;
    ss << "FutTransferRisk" <<",";
    ss << value.broker_code << ",";
    ss << value.code_from << ",";
    ss << value.isin << ",";
    ss << value.amount << ",";
    return ss.str();
}


//struct MESSAGE_PUB::FutTransferRisk

auto to_bson(MESSAGE_PUB::FutTransferRisk &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"broker_code", value.broker_code);
    BSON_APPEND_UTF8(doc,"code_from", value.code_from);
    BSON_APPEND_UTF8(doc,"isin", value.isin);
    BSON_APPEND_UTF8(doc,"amount", std::to_string(value.amount).c_str());
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct MESSAGE_PUB::FORTS_MSG139

auto to_csv(MESSAGE_PUB::FORTS_MSG139 &value) {
    std::stringstream ss;
    ss << "FORTS_MSG139" <<",";
    ss << value.code << ",";
    ss << value.message << ",";
    ss << value.deal_id1 << ",";
    ss << value.deal_id2 << ",";
    return ss.str();
}


//struct MESSAGE_PUB::FORTS_MSG139

auto to_bson(MESSAGE_PUB::FORTS_MSG139 &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"code", std::to_string(value.code).c_str());
    BSON_APPEND_UTF8(doc,"message", value.message);
    BSON_APPEND_UTF8(doc,"deal_id1", std::to_string(value.deal_id1).c_str());
    BSON_APPEND_UTF8(doc,"deal_id2", std::to_string(value.deal_id2).c_str());
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct MESSAGE_PUB::CODHeartbeat

auto to_csv(MESSAGE_PUB::CODHeartbeat &value) {
    std::stringstream ss;
    ss << "CODHeartbeat" <<",";
    ss << value.seq_number << ",";
    return ss.str();
}


//struct MESSAGE_PUB::CODHeartbeat

auto to_bson(MESSAGE_PUB::CODHeartbeat &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"seq_number", std::to_string(value.seq_number).c_str());
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct MESSAGE_PUB::FORTS_MSG99

auto to_csv(MESSAGE_PUB::FORTS_MSG99 &value) {
    std::stringstream ss;
    ss << "FORTS_MSG99" <<",";
    ss << value.queue_size << ",";
    ss << value.penalty_remain << ",";
    ss << value.message << ",";
    return ss.str();
}


//struct MESSAGE_PUB::FORTS_MSG99

auto to_bson(MESSAGE_PUB::FORTS_MSG99 &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"queue_size", std::to_string(value.queue_size).c_str());
    BSON_APPEND_UTF8(doc,"penalty_remain", std::to_string(value.penalty_remain).c_str());
    BSON_APPEND_UTF8(doc,"message", value.message);
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct MESSAGE_PUB::FORTS_MSG100

auto to_csv(MESSAGE_PUB::FORTS_MSG100 &value) {
    std::stringstream ss;
    ss << "FORTS_MSG100" <<",";
    ss << value.code << ",";
    ss << value.message << ",";
    return ss.str();
}


//struct MESSAGE_PUB::FORTS_MSG100

auto to_bson(MESSAGE_PUB::FORTS_MSG100 &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"code", std::to_string(value.code).c_str());
    BSON_APPEND_UTF8(doc,"message", value.message);
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct FORTS_PART_REPL::part

auto to_csv(FORTS_PART_REPL::part &value) {
    std::stringstream ss;
    ss << "part" <<",";
    ss << value.replID << ",";
    ss << value.replRev << ",";
    ss << value.replAct << ",";
    ss << value.client_code << ",";
    ss << cg_bcd_to_int64(value.money_free) << ",";
    ss << cg_bcd_to_int64(value.money_blocked) << ",";
    ss << cg_bcd_to_int64(value.vm_reserve) << ",";
    ss << cg_bcd_to_int64(value.fee) << ",";
    ss << cg_bcd_to_int64(value.balance_money) << ",";
    ss << cg_bcd_to_int64(value.coeff_go) << ",";
    ss << int(value.limits_set) << ",";
    ss << cg_bcd_to_int64(value.money_old) << ",";
    ss << cg_bcd_to_int64(value.money_amount) << ",";
    ss << cg_bcd_to_int64(value.money_pledge_amount) << ",";
    ss << cg_bcd_to_int64(value.vm_intercl) << ",";
    ss << int(value.is_auto_update_limit) << ",";
    ss << int(value.no_fut_discount) << ",";
    ss << value.num_clr_2delivery << ",";
    return ss.str();
}


//struct FORTS_PART_REPL::part

auto to_bson(FORTS_PART_REPL::part &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"replID", std::to_string(value.replID).c_str());
    BSON_APPEND_UTF8(doc,"replRev", std::to_string(value.replRev).c_str());
    BSON_APPEND_UTF8(doc,"replAct", std::to_string(value.replAct).c_str());
    BSON_APPEND_UTF8(doc,"client_code", value.client_code);
    BSON_APPEND_UTF8(doc,"money_free", std::to_string(cg_bcd_to_int64(value.money_free)).c_str());
    BSON_APPEND_UTF8(doc,"money_blocked", std::to_string(cg_bcd_to_int64(value.money_blocked)).c_str());
    BSON_APPEND_UTF8(doc,"vm_reserve", std::to_string(cg_bcd_to_int64(value.vm_reserve)).c_str());
    BSON_APPEND_UTF8(doc,"fee", std::to_string(cg_bcd_to_int64(value.fee)).c_str());
    BSON_APPEND_UTF8(doc,"balance_money", std::to_string(cg_bcd_to_int64(value.balance_money)).c_str());
    BSON_APPEND_UTF8(doc,"coeff_go", std::to_string(cg_bcd_to_int64(value.coeff_go)).c_str());
    BSON_APPEND_UTF8(doc,"limits_set", std::to_string(value.limits_set).c_str());
    BSON_APPEND_UTF8(doc,"money_old", std::to_string(cg_bcd_to_int64(value.money_old)).c_str());
    BSON_APPEND_UTF8(doc,"money_amount", std::to_string(cg_bcd_to_int64(value.money_amount)).c_str());
    BSON_APPEND_UTF8(doc,"money_pledge_amount", std::to_string(cg_bcd_to_int64(value.money_pledge_amount)).c_str());
    BSON_APPEND_UTF8(doc,"vm_intercl", std::to_string(cg_bcd_to_int64(value.vm_intercl)).c_str());
    BSON_APPEND_UTF8(doc,"is_auto_update_limit", std::to_string(value.is_auto_update_limit).c_str());
    BSON_APPEND_UTF8(doc,"no_fut_discount", std::to_string(value.no_fut_discount).c_str());
    BSON_APPEND_UTF8(doc,"num_clr_2delivery", std::to_string(value.num_clr_2delivery).c_str());
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct FORTS_PART_REPL::part_sa

auto to_csv(FORTS_PART_REPL::part_sa &value) {
    std::stringstream ss;
    ss << "part_sa" <<",";
    ss << value.replID << ",";
    ss << value.replRev << ",";
    ss << value.replAct << ",";
    ss << value.settlement_account << ",";
    ss << cg_bcd_to_int64(value.money_old) << ",";
    ss << cg_bcd_to_int64(value.money_amount) << ",";
    ss << cg_bcd_to_int64(value.money_free) << ",";
    ss << cg_bcd_to_int64(value.money_blocked) << ",";
    ss << cg_bcd_to_int64(value.money_pledge_amount) << ",";
    ss << cg_bcd_to_int64(value.vm_reserve) << ",";
    ss << cg_bcd_to_int64(value.vm_intercl) << ",";
    ss << cg_bcd_to_int64(value.fee) << ",";
    return ss.str();
}


//struct FORTS_PART_REPL::part_sa

auto to_bson(FORTS_PART_REPL::part_sa &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"replID", std::to_string(value.replID).c_str());
    BSON_APPEND_UTF8(doc,"replRev", std::to_string(value.replRev).c_str());
    BSON_APPEND_UTF8(doc,"replAct", std::to_string(value.replAct).c_str());
    BSON_APPEND_UTF8(doc,"settlement_account", value.settlement_account);
    BSON_APPEND_UTF8(doc,"money_old", std::to_string(cg_bcd_to_int64(value.money_old)).c_str());
    BSON_APPEND_UTF8(doc,"money_amount", std::to_string(cg_bcd_to_int64(value.money_amount)).c_str());
    BSON_APPEND_UTF8(doc,"money_free", std::to_string(cg_bcd_to_int64(value.money_free)).c_str());
    BSON_APPEND_UTF8(doc,"money_blocked", std::to_string(cg_bcd_to_int64(value.money_blocked)).c_str());
    BSON_APPEND_UTF8(doc,"money_pledge_amount", std::to_string(cg_bcd_to_int64(value.money_pledge_amount)).c_str());
    BSON_APPEND_UTF8(doc,"vm_reserve", std::to_string(cg_bcd_to_int64(value.vm_reserve)).c_str());
    BSON_APPEND_UTF8(doc,"vm_intercl", std::to_string(cg_bcd_to_int64(value.vm_intercl)).c_str());
    BSON_APPEND_UTF8(doc,"fee", std::to_string(cg_bcd_to_int64(value.fee)).c_str());
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct FORTS_PART_REPL::sys_events

auto to_csv(FORTS_PART_REPL::sys_events &value) {
    std::stringstream ss;
    ss << "sys_events" <<",";
    ss << value.replID << ",";
    ss << value.replRev << ",";
    ss << value.replAct << ",";
    ss << value.event_type << ",";
    ss << value.event_id << ",";
    ss << value.sess_id << ",";
    ss << value.message << ",";
    return ss.str();
}


//struct FORTS_PART_REPL::sys_events

auto to_bson(FORTS_PART_REPL::sys_events &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"replID", std::to_string(value.replID).c_str());
    BSON_APPEND_UTF8(doc,"replRev", std::to_string(value.replRev).c_str());
    BSON_APPEND_UTF8(doc,"replAct", std::to_string(value.replAct).c_str());
    BSON_APPEND_UTF8(doc,"event_type", std::to_string(value.event_type).c_str());
    BSON_APPEND_UTF8(doc,"event_id", std::to_string(value.event_id).c_str());
    BSON_APPEND_UTF8(doc,"sess_id", std::to_string(value.sess_id).c_str());
    BSON_APPEND_UTF8(doc,"message", value.message);
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct MCXCC_MDCOMMON_REPL::COMMON

auto to_csv(MCXCC_MDCOMMON_REPL::COMMON &value) {
    std::stringstream ss;
    ss << "COMMON" <<",";
    ss << value.replID << ",";
    ss << value.replRev << ",";
    ss << value.replAct << ",";
    ss << value.SECBOARD << ",";
    ss << value.SECCODE << ",";
    ss << cg_bcd_to_int64(value.BID) << ",";
    ss << value.BIDDEPTH << ",";
    ss << value.BIDDEPTHT << ",";
    ss << value.NUMBIDS << ",";
    ss << cg_bcd_to_int64(value.OFFER) << ",";
    ss << value.OFFERDEPTH << ",";
    ss << value.OFFERDEPTHT << ",";
    ss << value.NUMOFFERS << ",";
    ss << cg_bcd_to_int64(value.OPEN) << ",";
    ss << cg_bcd_to_int64(value.HIGH) << ",";
    ss << cg_bcd_to_int64(value.LOW) << ",";
    ss << cg_bcd_to_int64(value.LAST) << ",";
    ss << cg_bcd_to_int64(value.LASTNEG) << ",";
    ss << cg_bcd_to_int64(value.CHANGE) << ",";
    ss << value.QTY << ",";
    ss << std::to_string(cg_time_to_unix_time(value.TIME)).c_str() << ",";
    ss << value.VOLTODAY << ",";
    ss << value.VALTODAY << ",";
    ss << cg_bcd_to_int64(value.VALUE) << ",";
    ss << cg_bcd_to_int64(value.WAPRICE) << ",";
    ss << cg_bcd_to_int64(value.HIGHBID) << ",";
    ss << cg_bcd_to_int64(value.LOWOFFER) << ",";
    ss << value.NUMTRADES << ",";
    ss << cg_bcd_to_int64(value.PRICEMINUSPREVWAPRICE) << ",";
    ss << cg_bcd_to_int64(value.CLOSEPRICE) << ",";
    ss << cg_bcd_to_int64(value.LASTBID) << ",";
    ss << cg_bcd_to_int64(value.LASTOFFER) << ",";
    ss << value.LASTSETTLECODE << ",";
    ss << cg_bcd_to_int64(value.BASEPRICE) << ",";
    ss << cg_bcd_to_int64(value.MARKETPRICE) << ",";
    ss << cg_bcd_to_int64(value.MARKETPRICETODAY) << ",";
    ss << value.SETTLECODE << ",";
    ss << cg_bcd_to_int64(value.MARKETPRICE2) << ",";
    ss << cg_bcd_to_int64(value.ADMITTEDQUOTE) << ",";
    ss << std::to_string(cg_time_to_unix_time(value.SETTLEDATE1)).c_str() << ",";
    ss << std::to_string(cg_time_to_unix_time(value.SETTLEDATE2)).c_str() << ",";
    return ss.str();
}


//struct MCXCC_MDCOMMON_REPL::COMMON

auto to_bson(MCXCC_MDCOMMON_REPL::COMMON &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"replID", std::to_string(value.replID).c_str());
    BSON_APPEND_UTF8(doc,"replRev", std::to_string(value.replRev).c_str());
    BSON_APPEND_UTF8(doc,"replAct", std::to_string(value.replAct).c_str());
    BSON_APPEND_UTF8(doc,"SECBOARD", value.SECBOARD);
    BSON_APPEND_UTF8(doc,"SECCODE", value.SECCODE);
    BSON_APPEND_UTF8(doc,"BID", std::to_string(cg_bcd_to_int64(value.BID)).c_str());
    BSON_APPEND_UTF8(doc,"BIDDEPTH", std::to_string(value.BIDDEPTH).c_str());
    BSON_APPEND_UTF8(doc,"BIDDEPTHT", std::to_string(value.BIDDEPTHT).c_str());
    BSON_APPEND_UTF8(doc,"NUMBIDS", std::to_string(value.NUMBIDS).c_str());
    BSON_APPEND_UTF8(doc,"OFFER", std::to_string(cg_bcd_to_int64(value.OFFER)).c_str());
    BSON_APPEND_UTF8(doc,"OFFERDEPTH", std::to_string(value.OFFERDEPTH).c_str());
    BSON_APPEND_UTF8(doc,"OFFERDEPTHT", std::to_string(value.OFFERDEPTHT).c_str());
    BSON_APPEND_UTF8(doc,"NUMOFFERS", std::to_string(value.NUMOFFERS).c_str());
    BSON_APPEND_UTF8(doc,"OPEN", std::to_string(cg_bcd_to_int64(value.OPEN)).c_str());
    BSON_APPEND_UTF8(doc,"HIGH", std::to_string(cg_bcd_to_int64(value.HIGH)).c_str());
    BSON_APPEND_UTF8(doc,"LOW", std::to_string(cg_bcd_to_int64(value.LOW)).c_str());
    BSON_APPEND_UTF8(doc,"LAST", std::to_string(cg_bcd_to_int64(value.LAST)).c_str());
    BSON_APPEND_UTF8(doc,"LASTNEG", std::to_string(cg_bcd_to_int64(value.LASTNEG)).c_str());
    BSON_APPEND_UTF8(doc,"CHANGE", std::to_string(cg_bcd_to_int64(value.CHANGE)).c_str());
    BSON_APPEND_UTF8(doc,"QTY", std::to_string(value.QTY).c_str());
    BSON_APPEND_UTF8(doc,"TIME", std::to_string(cg_time_to_unix_time(value.TIME)).c_str());
    BSON_APPEND_UTF8(doc,"VOLTODAY", std::to_string(value.VOLTODAY).c_str());
    BSON_APPEND_UTF8(doc,"VALTODAY", std::to_string(value.VALTODAY).c_str());
    BSON_APPEND_UTF8(doc,"VALUE", std::to_string(cg_bcd_to_int64(value.VALUE)).c_str());
    BSON_APPEND_UTF8(doc,"WAPRICE", std::to_string(cg_bcd_to_int64(value.WAPRICE)).c_str());
    BSON_APPEND_UTF8(doc,"HIGHBID", std::to_string(cg_bcd_to_int64(value.HIGHBID)).c_str());
    BSON_APPEND_UTF8(doc,"LOWOFFER", std::to_string(cg_bcd_to_int64(value.LOWOFFER)).c_str());
    BSON_APPEND_UTF8(doc,"NUMTRADES", std::to_string(value.NUMTRADES).c_str());
    BSON_APPEND_UTF8(doc,"PRICEMINUSPREVWAPRICE", std::to_string(cg_bcd_to_int64(value.PRICEMINUSPREVWAPRICE)).c_str());
    BSON_APPEND_UTF8(doc,"CLOSEPRICE", std::to_string(cg_bcd_to_int64(value.CLOSEPRICE)).c_str());
    BSON_APPEND_UTF8(doc,"LASTBID", std::to_string(cg_bcd_to_int64(value.LASTBID)).c_str());
    BSON_APPEND_UTF8(doc,"LASTOFFER", std::to_string(cg_bcd_to_int64(value.LASTOFFER)).c_str());
    BSON_APPEND_UTF8(doc,"LASTSETTLECODE", value.LASTSETTLECODE);
    BSON_APPEND_UTF8(doc,"BASEPRICE", std::to_string(cg_bcd_to_int64(value.BASEPRICE)).c_str());
    BSON_APPEND_UTF8(doc,"MARKETPRICE", std::to_string(cg_bcd_to_int64(value.MARKETPRICE)).c_str());
    BSON_APPEND_UTF8(doc,"MARKETPRICETODAY", std::to_string(cg_bcd_to_int64(value.MARKETPRICETODAY)).c_str());
    BSON_APPEND_UTF8(doc,"SETTLECODE", value.SETTLECODE);
    BSON_APPEND_UTF8(doc,"MARKETPRICE2", std::to_string(cg_bcd_to_int64(value.MARKETPRICE2)).c_str());
    BSON_APPEND_UTF8(doc,"ADMITTEDQUOTE", std::to_string(cg_bcd_to_int64(value.ADMITTEDQUOTE)).c_str());
    BSON_APPEND_UTF8(doc,"SETTLEDATE1", std::to_string(cg_time_to_unix_time(value.SETTLEDATE1)).c_str());
    BSON_APPEND_UTF8(doc,"SETTLEDATE2", std::to_string(cg_time_to_unix_time(value.SETTLEDATE2)).c_str());
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct FORTS_FUTINFO_REPL::rates

auto to_csv(FORTS_FUTINFO_REPL::rates &value) {
    std::stringstream ss;
    ss << "rates" <<",";
    ss << value.replID << ",";
    ss << value.replRev << ",";
    ss << value.replAct << ",";
    ss << value.rate_id << ",";
    ss << value.curr_base << ",";
    ss << value.curr_coupled << ",";
    ss << cg_bcd_to_int64(value.radius) << ",";
    return ss.str();
}


//struct FORTS_FUTINFO_REPL::rates

auto to_bson(FORTS_FUTINFO_REPL::rates &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"replID", std::to_string(value.replID).c_str());
    BSON_APPEND_UTF8(doc,"replRev", std::to_string(value.replRev).c_str());
    BSON_APPEND_UTF8(doc,"replAct", std::to_string(value.replAct).c_str());
    BSON_APPEND_UTF8(doc,"rate_id", std::to_string(value.rate_id).c_str());
    BSON_APPEND_UTF8(doc,"curr_base", value.curr_base);
    BSON_APPEND_UTF8(doc,"curr_coupled", value.curr_coupled);
    BSON_APPEND_UTF8(doc,"radius", std::to_string(cg_bcd_to_int64(value.radius)).c_str());
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct FORTS_FUTINFO_REPL::fut_sess_contents

auto to_csv(FORTS_FUTINFO_REPL::fut_sess_contents &value) {
    std::stringstream ss;
    ss << "fut_sess_contents" <<",";
    ss << value.replID << ",";
    ss << value.replRev << ",";
    ss << value.replAct << ",";
    ss << value.sess_id << ",";
    ss << value.isin_id << ",";
    ss << value.short_isin << ",";
    ss << value.isin << ",";
    ss << value.name << ",";
    ss << value.inst_term << ",";
    ss << cg_bcd_to_int64(value.limit_up) << ",";
    ss << cg_bcd_to_int64(value.limit_down) << ",";
    ss << cg_bcd_to_int64(value.old_kotir) << ",";
    ss << cg_bcd_to_int64(value.buy_deposit) << ",";
    ss << cg_bcd_to_int64(value.sell_deposit) << ",";
    ss << value.roundto << ",";
    ss << cg_bcd_to_int64(value.min_step) << ",";
    ss << value.lot_volume << ",";
    ss << cg_bcd_to_int64(value.step_price) << ",";
    ss << std::to_string(cg_time_to_unix_time(value.d_pg)).c_str() << ",";
    ss << int(value.is_spread) << ",";
    ss << std::to_string(cg_time_to_unix_time(value.d_exp_start)).c_str() << ",";
    ss << int(value.is_percent) << ",";
    ss << cg_bcd_to_int64(value.percent_rate) << ",";
    ss << cg_bcd_to_int64(value.last_cl_quote) << ",";
    ss << value.signs << ",";
    ss << int(value.is_trade_evening) << ",";
    ss << value.ticker << ",";
    ss << value.state << ",";
    ss << value.multileg_type << ",";
    ss << value.legs_qty << ",";
    ss << cg_bcd_to_int64(value.step_price_clr) << ",";
    ss << cg_bcd_to_int64(value.step_price_interclr) << ",";
    ss << cg_bcd_to_int64(value.step_price_curr) << ",";
    ss << std::to_string(cg_time_to_unix_time(value.d_start)).c_str() << ",";
    ss << cg_bcd_to_int64(value.pctyield_coeff) << ",";
    ss << cg_bcd_to_int64(value.pctyield_total) << ",";
    ss << std::to_string(cg_time_to_unix_time(value.d_exp_end)).c_str() << ",";
    ss << value.base_contract_code << ",";
    ss << cg_bcd_to_int64(value.settlement_price_open) << ",";
    ss << cg_bcd_to_int64(value.settlement_price) << ",";
    ss << std::to_string(cg_time_to_unix_time(value.last_trade_date)).c_str() << ",";
    return ss.str();
}


//struct FORTS_FUTINFO_REPL::fut_sess_contents

auto to_bson(FORTS_FUTINFO_REPL::fut_sess_contents &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"replID", std::to_string(value.replID).c_str());
    BSON_APPEND_UTF8(doc,"replRev", std::to_string(value.replRev).c_str());
    BSON_APPEND_UTF8(doc,"replAct", std::to_string(value.replAct).c_str());
    BSON_APPEND_UTF8(doc,"sess_id", std::to_string(value.sess_id).c_str());
    BSON_APPEND_UTF8(doc,"isin_id", std::to_string(value.isin_id).c_str());
    BSON_APPEND_UTF8(doc,"short_isin", value.short_isin);
    BSON_APPEND_UTF8(doc,"isin", value.isin);
    BSON_APPEND_UTF8(doc,"name", value.name);
    BSON_APPEND_UTF8(doc,"inst_term", std::to_string(value.inst_term).c_str());
    BSON_APPEND_UTF8(doc,"limit_up", std::to_string(cg_bcd_to_int64(value.limit_up)).c_str());
    BSON_APPEND_UTF8(doc,"limit_down", std::to_string(cg_bcd_to_int64(value.limit_down)).c_str());
    BSON_APPEND_UTF8(doc,"old_kotir", std::to_string(cg_bcd_to_int64(value.old_kotir)).c_str());
    BSON_APPEND_UTF8(doc,"buy_deposit", std::to_string(cg_bcd_to_int64(value.buy_deposit)).c_str());
    BSON_APPEND_UTF8(doc,"sell_deposit", std::to_string(cg_bcd_to_int64(value.sell_deposit)).c_str());
    BSON_APPEND_UTF8(doc,"roundto", std::to_string(value.roundto).c_str());
    BSON_APPEND_UTF8(doc,"min_step", std::to_string(cg_bcd_to_int64(value.min_step)).c_str());
    BSON_APPEND_UTF8(doc,"lot_volume", std::to_string(value.lot_volume).c_str());
    BSON_APPEND_UTF8(doc,"step_price", std::to_string(cg_bcd_to_int64(value.step_price)).c_str());
    BSON_APPEND_UTF8(doc,"d_pg", std::to_string(cg_time_to_unix_time(value.d_pg)).c_str());
    BSON_APPEND_UTF8(doc,"is_spread", std::to_string(value.is_spread).c_str());
    BSON_APPEND_UTF8(doc,"d_exp_start", std::to_string(cg_time_to_unix_time(value.d_exp_start)).c_str());
    BSON_APPEND_UTF8(doc,"is_percent", std::to_string(value.is_percent).c_str());
    BSON_APPEND_UTF8(doc,"percent_rate", std::to_string(cg_bcd_to_int64(value.percent_rate)).c_str());
    BSON_APPEND_UTF8(doc,"last_cl_quote", std::to_string(cg_bcd_to_int64(value.last_cl_quote)).c_str());
    BSON_APPEND_UTF8(doc,"signs", std::to_string(value.signs).c_str());
    BSON_APPEND_UTF8(doc,"is_trade_evening", std::to_string(value.is_trade_evening).c_str());
    BSON_APPEND_UTF8(doc,"ticker", std::to_string(value.ticker).c_str());
    BSON_APPEND_UTF8(doc,"state", std::to_string(value.state).c_str());
    BSON_APPEND_UTF8(doc,"multileg_type", std::to_string(value.multileg_type).c_str());
    BSON_APPEND_UTF8(doc,"legs_qty", std::to_string(value.legs_qty).c_str());
    BSON_APPEND_UTF8(doc,"step_price_clr", std::to_string(cg_bcd_to_int64(value.step_price_clr)).c_str());
    BSON_APPEND_UTF8(doc,"step_price_interclr", std::to_string(cg_bcd_to_int64(value.step_price_interclr)).c_str());
    BSON_APPEND_UTF8(doc,"step_price_curr", std::to_string(cg_bcd_to_int64(value.step_price_curr)).c_str());
    BSON_APPEND_UTF8(doc,"d_start", std::to_string(cg_time_to_unix_time(value.d_start)).c_str());
    BSON_APPEND_UTF8(doc,"pctyield_coeff", std::to_string(cg_bcd_to_int64(value.pctyield_coeff)).c_str());
    BSON_APPEND_UTF8(doc,"pctyield_total", std::to_string(cg_bcd_to_int64(value.pctyield_total)).c_str());
    BSON_APPEND_UTF8(doc,"d_exp_end", std::to_string(cg_time_to_unix_time(value.d_exp_end)).c_str());
    BSON_APPEND_UTF8(doc,"base_contract_code", value.base_contract_code);
    BSON_APPEND_UTF8(doc,"settlement_price_open", std::to_string(cg_bcd_to_int64(value.settlement_price_open)).c_str());
    BSON_APPEND_UTF8(doc,"settlement_price", std::to_string(cg_bcd_to_int64(value.settlement_price)).c_str());
    BSON_APPEND_UTF8(doc,"last_trade_date", std::to_string(cg_time_to_unix_time(value.last_trade_date)).c_str());
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct FORTS_FUTINFO_REPL::fut_vcb

auto to_csv(FORTS_FUTINFO_REPL::fut_vcb &value) {
    std::stringstream ss;
    ss << "fut_vcb" <<",";
    ss << value.replID << ",";
    ss << value.replRev << ",";
    ss << value.replAct << ",";
    ss << value.code_vcb << ",";
    ss << value.name << ",";
    ss << value.exec_type << ",";
    ss << value.curr << ",";
    ss << value.trade_scheme << ",";
    ss << value.section << ",";
    ss << value.rate_id << ",";
    ss << value.base_contract_id << ",";
    ss << value.SECCODE << ",";
    ss << int(value.is_foreign) << ",";
    ss << value.signs << ",";
    ss << value.base_contract_code << ",";
    return ss.str();
}


//struct FORTS_FUTINFO_REPL::fut_vcb

auto to_bson(FORTS_FUTINFO_REPL::fut_vcb &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"replID", std::to_string(value.replID).c_str());
    BSON_APPEND_UTF8(doc,"replRev", std::to_string(value.replRev).c_str());
    BSON_APPEND_UTF8(doc,"replAct", std::to_string(value.replAct).c_str());
    BSON_APPEND_UTF8(doc,"code_vcb", value.code_vcb);
    BSON_APPEND_UTF8(doc,"name", value.name);
    BSON_APPEND_UTF8(doc,"exec_type", value.exec_type);
    BSON_APPEND_UTF8(doc,"curr", value.curr);
    BSON_APPEND_UTF8(doc,"trade_scheme", value.trade_scheme);
    BSON_APPEND_UTF8(doc,"section", value.section);
    BSON_APPEND_UTF8(doc,"rate_id", std::to_string(value.rate_id).c_str());
    BSON_APPEND_UTF8(doc,"base_contract_id", std::to_string(value.base_contract_id).c_str());
    BSON_APPEND_UTF8(doc,"SECCODE", value.SECCODE);
    BSON_APPEND_UTF8(doc,"is_foreign", std::to_string(value.is_foreign).c_str());
    BSON_APPEND_UTF8(doc,"signs", std::to_string(value.signs).c_str());
    BSON_APPEND_UTF8(doc,"base_contract_code", value.base_contract_code);
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct FORTS_FUTINFO_REPL::fut_instruments

auto to_csv(FORTS_FUTINFO_REPL::fut_instruments &value) {
    std::stringstream ss;
    ss << "fut_instruments" <<",";
    ss << value.replID << ",";
    ss << value.replRev << ",";
    ss << value.replAct << ",";
    ss << value.isin_id << ",";
    ss << value.short_isin << ",";
    ss << value.isin << ",";
    ss << value.name << ",";
    ss << value.inst_term << ",";
    ss << value.code_vcb << ",";
    ss << cg_bcd_to_int64(value.old_kotir) << ",";
    ss << value.roundto << ",";
    ss << cg_bcd_to_int64(value.min_step) << ",";
    ss << value.lot_volume << ",";
    ss << cg_bcd_to_int64(value.step_price) << ",";
    ss << std::to_string(cg_time_to_unix_time(value.d_pg)).c_str() << ",";
    ss << int(value.is_spread) << ",";
    ss << std::to_string(cg_time_to_unix_time(value.d_exp)).c_str() << ",";
    ss << int(value.is_percent) << ",";
    ss << cg_bcd_to_int64(value.percent_rate) << ",";
    ss << cg_bcd_to_int64(value.last_cl_quote) << ",";
    ss << value.signs << ",";
    ss << value.multileg_type << ",";
    ss << value.legs_qty << ",";
    ss << cg_bcd_to_int64(value.step_price_clr) << ",";
    ss << cg_bcd_to_int64(value.step_price_interclr) << ",";
    ss << cg_bcd_to_int64(value.step_price_curr) << ",";
    ss << std::to_string(cg_time_to_unix_time(value.d_start)).c_str() << ",";
    ss << cg_bcd_to_int64(value.pctyield_coeff) << ",";
    ss << cg_bcd_to_int64(value.pctyield_total) << ",";
    ss << value.exec_name << ",";
    ss << value.base_contract_code << ",";
    ss << cg_bcd_to_int64(value.settlement_price_open) << ",";
    ss << std::to_string(cg_time_to_unix_time(value.last_trade_date)).c_str() << ",";
    ss << std::to_string(cg_time_to_unix_time(value.d_exp_start)).c_str() << ",";
    ss << cg_bcd_to_int64(value.settlement_price) << ",";
    ss << value.series_type << ",";
    return ss.str();
}


//struct FORTS_FUTINFO_REPL::fut_instruments

auto to_bson(FORTS_FUTINFO_REPL::fut_instruments &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"replID", std::to_string(value.replID).c_str());
    BSON_APPEND_UTF8(doc,"replRev", std::to_string(value.replRev).c_str());
    BSON_APPEND_UTF8(doc,"replAct", std::to_string(value.replAct).c_str());
    BSON_APPEND_UTF8(doc,"isin_id", std::to_string(value.isin_id).c_str());
    BSON_APPEND_UTF8(doc,"short_isin", value.short_isin);
    BSON_APPEND_UTF8(doc,"isin", value.isin);
    BSON_APPEND_UTF8(doc,"name", value.name);
    BSON_APPEND_UTF8(doc,"inst_term", std::to_string(value.inst_term).c_str());
    BSON_APPEND_UTF8(doc,"code_vcb", value.code_vcb);
    BSON_APPEND_UTF8(doc,"old_kotir", std::to_string(cg_bcd_to_int64(value.old_kotir)).c_str());
    BSON_APPEND_UTF8(doc,"roundto", std::to_string(value.roundto).c_str());
    BSON_APPEND_UTF8(doc,"min_step", std::to_string(cg_bcd_to_int64(value.min_step)).c_str());
    BSON_APPEND_UTF8(doc,"lot_volume", std::to_string(value.lot_volume).c_str());
    BSON_APPEND_UTF8(doc,"step_price", std::to_string(cg_bcd_to_int64(value.step_price)).c_str());
    BSON_APPEND_UTF8(doc,"d_pg", std::to_string(cg_time_to_unix_time(value.d_pg)).c_str());
    BSON_APPEND_UTF8(doc,"is_spread", std::to_string(value.is_spread).c_str());
    BSON_APPEND_UTF8(doc,"d_exp", std::to_string(cg_time_to_unix_time(value.d_exp)).c_str());
    BSON_APPEND_UTF8(doc,"is_percent", std::to_string(value.is_percent).c_str());
    BSON_APPEND_UTF8(doc,"percent_rate", std::to_string(cg_bcd_to_int64(value.percent_rate)).c_str());
    BSON_APPEND_UTF8(doc,"last_cl_quote", std::to_string(cg_bcd_to_int64(value.last_cl_quote)).c_str());
    BSON_APPEND_UTF8(doc,"signs", std::to_string(value.signs).c_str());
    BSON_APPEND_UTF8(doc,"multileg_type", std::to_string(value.multileg_type).c_str());
    BSON_APPEND_UTF8(doc,"legs_qty", std::to_string(value.legs_qty).c_str());
    BSON_APPEND_UTF8(doc,"step_price_clr", std::to_string(cg_bcd_to_int64(value.step_price_clr)).c_str());
    BSON_APPEND_UTF8(doc,"step_price_interclr", std::to_string(cg_bcd_to_int64(value.step_price_interclr)).c_str());
    BSON_APPEND_UTF8(doc,"step_price_curr", std::to_string(cg_bcd_to_int64(value.step_price_curr)).c_str());
    BSON_APPEND_UTF8(doc,"d_start", std::to_string(cg_time_to_unix_time(value.d_start)).c_str());
    BSON_APPEND_UTF8(doc,"pctyield_coeff", std::to_string(cg_bcd_to_int64(value.pctyield_coeff)).c_str());
    BSON_APPEND_UTF8(doc,"pctyield_total", std::to_string(cg_bcd_to_int64(value.pctyield_total)).c_str());
    BSON_APPEND_UTF8(doc,"exec_name", value.exec_name);
    BSON_APPEND_UTF8(doc,"base_contract_code", value.base_contract_code);
    BSON_APPEND_UTF8(doc,"settlement_price_open", std::to_string(cg_bcd_to_int64(value.settlement_price_open)).c_str());
    BSON_APPEND_UTF8(doc,"last_trade_date", std::to_string(cg_time_to_unix_time(value.last_trade_date)).c_str());
    BSON_APPEND_UTF8(doc,"d_exp_start", std::to_string(cg_time_to_unix_time(value.d_exp_start)).c_str());
    BSON_APPEND_UTF8(doc,"settlement_price", std::to_string(cg_bcd_to_int64(value.settlement_price)).c_str());
    BSON_APPEND_UTF8(doc,"series_type", value.series_type);
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct FORTS_FUTINFO_REPL::fut_bond_registry

auto to_csv(FORTS_FUTINFO_REPL::fut_bond_registry &value) {
    std::stringstream ss;
    ss << "fut_bond_registry" <<",";
    ss << value.replID << ",";
    ss << value.replRev << ",";
    ss << value.replAct << ",";
    ss << value.bond_id << ",";
    ss << value.small_name << ",";
    ss << value.short_isin << ",";
    ss << value.name << ",";
    ss << std::to_string(cg_time_to_unix_time(value.date_redempt)).c_str() << ",";
    ss << cg_bcd_to_int64(value.nominal) << ",";
    ss << value.bond_type << ",";
    ss << int(value.year_base) << ",";
    return ss.str();
}


//struct FORTS_FUTINFO_REPL::fut_bond_registry

auto to_bson(FORTS_FUTINFO_REPL::fut_bond_registry &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"replID", std::to_string(value.replID).c_str());
    BSON_APPEND_UTF8(doc,"replRev", std::to_string(value.replRev).c_str());
    BSON_APPEND_UTF8(doc,"replAct", std::to_string(value.replAct).c_str());
    BSON_APPEND_UTF8(doc,"bond_id", std::to_string(value.bond_id).c_str());
    BSON_APPEND_UTF8(doc,"small_name", value.small_name);
    BSON_APPEND_UTF8(doc,"short_isin", value.short_isin);
    BSON_APPEND_UTF8(doc,"name", value.name);
    BSON_APPEND_UTF8(doc,"date_redempt", std::to_string(cg_time_to_unix_time(value.date_redempt)).c_str());
    BSON_APPEND_UTF8(doc,"nominal", std::to_string(cg_bcd_to_int64(value.nominal)).c_str());
    BSON_APPEND_UTF8(doc,"bond_type", std::to_string(value.bond_type).c_str());
    BSON_APPEND_UTF8(doc,"year_base", std::to_string(value.year_base).c_str());
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct FORTS_FUTINFO_REPL::dealer

auto to_csv(FORTS_FUTINFO_REPL::dealer &value) {
    std::stringstream ss;
    ss << "dealer" <<",";
    ss << value.replID << ",";
    ss << value.replRev << ",";
    ss << value.replAct << ",";
    ss << value.client_code << ",";
    ss << value.name << ",";
    ss << value.rts_code << ",";
    ss << value.signs << ",";
    ss << value.status << ",";
    ss << value.transfer_code << ",";
    ss << cg_bcd_to_int64(value.exp_weight) << ",";
    ss << value.num_clr_2delivery << ",";
    ss << int(value.margin_type) << ",";
    ss << int(value.calendar_spread_margin_type) << ",";
    ss << value.num_clr_2delivery_client_default << ",";
    ss << cg_bcd_to_int64(value.exp_weight_client_default) << ",";
    ss << cg_bcd_to_int64(value.go_ratio) << ",";
    ss << int(value.check_limit_on_withdrawal) << ",";
    ss << int(value.limit_tied_money) << ",";
    ss << int(value.limits_set) << ",";
    ss << int(value.no_fut_discount) << ",";
    ss << int(value.no_fut_discount_client_default) << ",";
    ss << value.firm_id << ",";
    ss << value.tm_name << ",";
    ss << cg_bcd_to_int64(value.short_option_minimum_charge_ratio) << ",";
    ss << int(value.ics_margin_type) << ",";
    ss << cg_bcd_to_int64(value.coeff_im) << ",";
    return ss.str();
}


//struct FORTS_FUTINFO_REPL::dealer

auto to_bson(FORTS_FUTINFO_REPL::dealer &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"replID", std::to_string(value.replID).c_str());
    BSON_APPEND_UTF8(doc,"replRev", std::to_string(value.replRev).c_str());
    BSON_APPEND_UTF8(doc,"replAct", std::to_string(value.replAct).c_str());
    BSON_APPEND_UTF8(doc,"client_code", value.client_code);
    BSON_APPEND_UTF8(doc,"name", value.name);
    BSON_APPEND_UTF8(doc,"rts_code", value.rts_code);
    BSON_APPEND_UTF8(doc,"signs", std::to_string(value.signs).c_str());
    BSON_APPEND_UTF8(doc,"status", std::to_string(value.status).c_str());
    BSON_APPEND_UTF8(doc,"transfer_code", value.transfer_code);
    BSON_APPEND_UTF8(doc,"exp_weight", std::to_string(cg_bcd_to_int64(value.exp_weight)).c_str());
    BSON_APPEND_UTF8(doc,"num_clr_2delivery", std::to_string(value.num_clr_2delivery).c_str());
    BSON_APPEND_UTF8(doc,"margin_type", std::to_string(value.margin_type).c_str());
    BSON_APPEND_UTF8(doc,"calendar_spread_margin_type", std::to_string(value.calendar_spread_margin_type).c_str());
    BSON_APPEND_UTF8(doc,"num_clr_2delivery_client_default", std::to_string(value.num_clr_2delivery_client_default).c_str());
    BSON_APPEND_UTF8(doc,"exp_weight_client_default", std::to_string(cg_bcd_to_int64(value.exp_weight_client_default)).c_str());
    BSON_APPEND_UTF8(doc,"go_ratio", std::to_string(cg_bcd_to_int64(value.go_ratio)).c_str());
    BSON_APPEND_UTF8(doc,"check_limit_on_withdrawal", std::to_string(value.check_limit_on_withdrawal).c_str());
    BSON_APPEND_UTF8(doc,"limit_tied_money", std::to_string(value.limit_tied_money).c_str());
    BSON_APPEND_UTF8(doc,"limits_set", std::to_string(value.limits_set).c_str());
    BSON_APPEND_UTF8(doc,"no_fut_discount", std::to_string(value.no_fut_discount).c_str());
    BSON_APPEND_UTF8(doc,"no_fut_discount_client_default", std::to_string(value.no_fut_discount_client_default).c_str());
    BSON_APPEND_UTF8(doc,"firm_id", value.firm_id);
    BSON_APPEND_UTF8(doc,"tm_name", value.tm_name);
    BSON_APPEND_UTF8(doc,"short_option_minimum_charge_ratio", std::to_string(cg_bcd_to_int64(value.short_option_minimum_charge_ratio)).c_str());
    BSON_APPEND_UTF8(doc,"ics_margin_type", std::to_string(value.ics_margin_type).c_str());
    BSON_APPEND_UTF8(doc,"coeff_im", std::to_string(cg_bcd_to_int64(value.coeff_im)).c_str());
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct FORTS_FUTINFO_REPL::sys_messages

auto to_csv(FORTS_FUTINFO_REPL::sys_messages &value) {
    std::stringstream ss;
    ss << "sys_messages" <<",";
    ss << value.replID << ",";
    ss << value.replRev << ",";
    ss << value.replAct << ",";
    ss << value.msg_id << ",";
    ss << std::to_string(cg_time_to_unix_time(value.moment)).c_str() << ",";
    ss << value.lang_code << ",";
    ss << int(value.urgency) << ",";
    ss << int(value.status) << ",";
    ss << value.text << ",";
    ss << value.message_body << ",";
    return ss.str();
}


//struct FORTS_FUTINFO_REPL::sys_messages

auto to_bson(FORTS_FUTINFO_REPL::sys_messages &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"replID", std::to_string(value.replID).c_str());
    BSON_APPEND_UTF8(doc,"replRev", std::to_string(value.replRev).c_str());
    BSON_APPEND_UTF8(doc,"replAct", std::to_string(value.replAct).c_str());
    BSON_APPEND_UTF8(doc,"msg_id", std::to_string(value.msg_id).c_str());
    BSON_APPEND_UTF8(doc,"moment", std::to_string(cg_time_to_unix_time(value.moment)).c_str());
    BSON_APPEND_UTF8(doc,"lang_code", value.lang_code);
    BSON_APPEND_UTF8(doc,"urgency", std::to_string(value.urgency).c_str());
    BSON_APPEND_UTF8(doc,"status", std::to_string(value.status).c_str());
    BSON_APPEND_UTF8(doc,"text", value.text);
    BSON_APPEND_UTF8(doc,"message_body", value.message_body);
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct FORTS_FUTINFO_REPL::prohibition

auto to_csv(FORTS_FUTINFO_REPL::prohibition &value) {
    std::stringstream ss;
    ss << "prohibition" <<",";
    ss << value.replID << ",";
    ss << value.replRev << ",";
    ss << value.replAct << ",";
    ss << value.prohib_id << ",";
    ss << value.client_code << ",";
    ss << value.initiator << ",";
    ss << value.section << ",";
    ss << value.code_vcb << ",";
    ss << value.isin_id << ",";
    ss << value.priority << ",";
    ss << value.group_mask << ",";
    ss << value.type << ",";
    ss << value.is_legacy << ",";
    ss << value.base_contract_code << ",";
    return ss.str();
}


//struct FORTS_FUTINFO_REPL::prohibition

auto to_bson(FORTS_FUTINFO_REPL::prohibition &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"replID", std::to_string(value.replID).c_str());
    BSON_APPEND_UTF8(doc,"replRev", std::to_string(value.replRev).c_str());
    BSON_APPEND_UTF8(doc,"replAct", std::to_string(value.replAct).c_str());
    BSON_APPEND_UTF8(doc,"prohib_id", std::to_string(value.prohib_id).c_str());
    BSON_APPEND_UTF8(doc,"client_code", value.client_code);
    BSON_APPEND_UTF8(doc,"initiator", std::to_string(value.initiator).c_str());
    BSON_APPEND_UTF8(doc,"section", value.section);
    BSON_APPEND_UTF8(doc,"code_vcb", value.code_vcb);
    BSON_APPEND_UTF8(doc,"isin_id", std::to_string(value.isin_id).c_str());
    BSON_APPEND_UTF8(doc,"priority", std::to_string(value.priority).c_str());
    BSON_APPEND_UTF8(doc,"group_mask", std::to_string(value.group_mask).c_str());
    BSON_APPEND_UTF8(doc,"type", std::to_string(value.type).c_str());
    BSON_APPEND_UTF8(doc,"is_legacy", std::to_string(value.is_legacy).c_str());
    BSON_APPEND_UTF8(doc,"base_contract_code", value.base_contract_code);
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct FORTS_FUTINFO_REPL::multileg_dict

auto to_csv(FORTS_FUTINFO_REPL::multileg_dict &value) {
    std::stringstream ss;
    ss << "multileg_dict" <<",";
    ss << value.replID << ",";
    ss << value.replRev << ",";
    ss << value.replAct << ",";
    ss << value.sess_id << ",";
    ss << value.isin_id << ",";
    ss << value.isin_id_leg << ",";
    ss << value.qty_ratio << ",";
    ss << value.leg_order_no << ",";
    return ss.str();
}


//struct FORTS_FUTINFO_REPL::multileg_dict

auto to_bson(FORTS_FUTINFO_REPL::multileg_dict &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"replID", std::to_string(value.replID).c_str());
    BSON_APPEND_UTF8(doc,"replRev", std::to_string(value.replRev).c_str());
    BSON_APPEND_UTF8(doc,"replAct", std::to_string(value.replAct).c_str());
    BSON_APPEND_UTF8(doc,"sess_id", std::to_string(value.sess_id).c_str());
    BSON_APPEND_UTF8(doc,"isin_id", std::to_string(value.isin_id).c_str());
    BSON_APPEND_UTF8(doc,"isin_id_leg", std::to_string(value.isin_id_leg).c_str());
    BSON_APPEND_UTF8(doc,"qty_ratio", std::to_string(value.qty_ratio).c_str());
    BSON_APPEND_UTF8(doc,"leg_order_no", std::to_string(value.leg_order_no).c_str());
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct FORTS_FUTINFO_REPL::fut_rejected_orders

auto to_csv(FORTS_FUTINFO_REPL::fut_rejected_orders &value) {
    std::stringstream ss;
    ss << "fut_rejected_orders" <<",";
    ss << value.replID << ",";
    ss << value.replRev << ",";
    ss << value.replAct << ",";
    ss << value.order_id << ",";
    ss << value.sess_id << ",";
    ss << std::to_string(cg_time_to_unix_time(value.moment)).c_str() << ",";
    ss << value.isin_id << ",";
    ss << value.client_code << ",";
    ss << int(value.dir) << ",";
    ss << value.xamount << ",";
    ss << cg_bcd_to_int64(value.price) << ",";
    ss << std::to_string(cg_time_to_unix_time(value.date_exp)).c_str() << ",";
    ss << value.id_ord1 << ",";
    ss << std::to_string(cg_time_to_unix_time(value.moment_reject)).c_str() << ",";
    ss << value.ret_code << ",";
    ss << value.ret_message << ",";
    ss << value.comment << ",";
    ss << value.login_from << ",";
    ss << value.ext_id << ",";
    return ss.str();
}


//struct FORTS_FUTINFO_REPL::fut_rejected_orders

auto to_bson(FORTS_FUTINFO_REPL::fut_rejected_orders &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"replID", std::to_string(value.replID).c_str());
    BSON_APPEND_UTF8(doc,"replRev", std::to_string(value.replRev).c_str());
    BSON_APPEND_UTF8(doc,"replAct", std::to_string(value.replAct).c_str());
    BSON_APPEND_UTF8(doc,"order_id", std::to_string(value.order_id).c_str());
    BSON_APPEND_UTF8(doc,"sess_id", std::to_string(value.sess_id).c_str());
    BSON_APPEND_UTF8(doc,"moment", std::to_string(cg_time_to_unix_time(value.moment)).c_str());
    BSON_APPEND_UTF8(doc,"isin_id", std::to_string(value.isin_id).c_str());
    BSON_APPEND_UTF8(doc,"client_code", value.client_code);
    BSON_APPEND_UTF8(doc,"dir", std::to_string(value.dir).c_str());
    BSON_APPEND_UTF8(doc,"xamount", std::to_string(value.xamount).c_str());
    BSON_APPEND_UTF8(doc,"price", std::to_string(cg_bcd_to_int64(value.price)).c_str());
    BSON_APPEND_UTF8(doc,"date_exp", std::to_string(cg_time_to_unix_time(value.date_exp)).c_str());
    BSON_APPEND_UTF8(doc,"id_ord1", std::to_string(value.id_ord1).c_str());
    BSON_APPEND_UTF8(doc,"moment_reject", std::to_string(cg_time_to_unix_time(value.moment_reject)).c_str());
    BSON_APPEND_UTF8(doc,"ret_code", std::to_string(value.ret_code).c_str());
    BSON_APPEND_UTF8(doc,"ret_message", value.ret_message);
    BSON_APPEND_UTF8(doc,"comment", value.comment);
    BSON_APPEND_UTF8(doc,"login_from", value.login_from);
    BSON_APPEND_UTF8(doc,"ext_id", std::to_string(value.ext_id).c_str());
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct FORTS_FUTINFO_REPL::fut_intercl_info

auto to_csv(FORTS_FUTINFO_REPL::fut_intercl_info &value) {
    std::stringstream ss;
    ss << "fut_intercl_info" <<",";
    ss << value.replID << ",";
    ss << value.replRev << ",";
    ss << value.replAct << ",";
    ss << value.isin_id << ",";
    ss << value.client_code << ",";
    ss << cg_bcd_to_int64(value.vm_intercl) << ",";
    return ss.str();
}


//struct FORTS_FUTINFO_REPL::fut_intercl_info

auto to_bson(FORTS_FUTINFO_REPL::fut_intercl_info &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"replID", std::to_string(value.replID).c_str());
    BSON_APPEND_UTF8(doc,"replRev", std::to_string(value.replRev).c_str());
    BSON_APPEND_UTF8(doc,"replAct", std::to_string(value.replAct).c_str());
    BSON_APPEND_UTF8(doc,"isin_id", std::to_string(value.isin_id).c_str());
    BSON_APPEND_UTF8(doc,"client_code", value.client_code);
    BSON_APPEND_UTF8(doc,"vm_intercl", std::to_string(cg_bcd_to_int64(value.vm_intercl)).c_str());
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct FORTS_FUTINFO_REPL::fut_bond_nkd

auto to_csv(FORTS_FUTINFO_REPL::fut_bond_nkd &value) {
    std::stringstream ss;
    ss << "fut_bond_nkd" <<",";
    ss << value.replID << ",";
    ss << value.replRev << ",";
    ss << value.replAct << ",";
    ss << value.bond_id << ",";
    ss << std::to_string(cg_time_to_unix_time(value.date)).c_str() << ",";
    ss << cg_bcd_to_int64(value.nkd) << ",";
    ss << int(value.is_cupon) << ",";
    return ss.str();
}


//struct FORTS_FUTINFO_REPL::fut_bond_nkd

auto to_bson(FORTS_FUTINFO_REPL::fut_bond_nkd &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"replID", std::to_string(value.replID).c_str());
    BSON_APPEND_UTF8(doc,"replRev", std::to_string(value.replRev).c_str());
    BSON_APPEND_UTF8(doc,"replAct", std::to_string(value.replAct).c_str());
    BSON_APPEND_UTF8(doc,"bond_id", std::to_string(value.bond_id).c_str());
    BSON_APPEND_UTF8(doc,"date", std::to_string(cg_time_to_unix_time(value.date)).c_str());
    BSON_APPEND_UTF8(doc,"nkd", std::to_string(cg_bcd_to_int64(value.nkd)).c_str());
    BSON_APPEND_UTF8(doc,"is_cupon", std::to_string(value.is_cupon).c_str());
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct FORTS_FUTINFO_REPL::fut_bond_nominal

auto to_csv(FORTS_FUTINFO_REPL::fut_bond_nominal &value) {
    std::stringstream ss;
    ss << "fut_bond_nominal" <<",";
    ss << value.replID << ",";
    ss << value.replRev << ",";
    ss << value.replAct << ",";
    ss << value.bond_id << ",";
    ss << std::to_string(cg_time_to_unix_time(value.date)).c_str() << ",";
    ss << cg_bcd_to_int64(value.nominal) << ",";
    ss << cg_bcd_to_int64(value.face_value) << ",";
    ss << cg_bcd_to_int64(value.coupon_nominal) << ",";
    ss << int(value.is_nominal) << ",";
    return ss.str();
}


//struct FORTS_FUTINFO_REPL::fut_bond_nominal

auto to_bson(FORTS_FUTINFO_REPL::fut_bond_nominal &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"replID", std::to_string(value.replID).c_str());
    BSON_APPEND_UTF8(doc,"replRev", std::to_string(value.replRev).c_str());
    BSON_APPEND_UTF8(doc,"replAct", std::to_string(value.replAct).c_str());
    BSON_APPEND_UTF8(doc,"bond_id", std::to_string(value.bond_id).c_str());
    BSON_APPEND_UTF8(doc,"date", std::to_string(cg_time_to_unix_time(value.date)).c_str());
    BSON_APPEND_UTF8(doc,"nominal", std::to_string(cg_bcd_to_int64(value.nominal)).c_str());
    BSON_APPEND_UTF8(doc,"face_value", std::to_string(cg_bcd_to_int64(value.face_value)).c_str());
    BSON_APPEND_UTF8(doc,"coupon_nominal", std::to_string(cg_bcd_to_int64(value.coupon_nominal)).c_str());
    BSON_APPEND_UTF8(doc,"is_nominal", std::to_string(value.is_nominal).c_str());
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct FORTS_FUTINFO_REPL::fut_bond_isin

auto to_csv(FORTS_FUTINFO_REPL::fut_bond_isin &value) {
    std::stringstream ss;
    ss << "fut_bond_isin" <<",";
    ss << value.replID << ",";
    ss << value.replRev << ",";
    ss << value.replAct << ",";
    ss << value.isin_id << ",";
    ss << value.bond_id << ",";
    ss << cg_bcd_to_int64(value.coeff_conversion) << ",";
    return ss.str();
}


//struct FORTS_FUTINFO_REPL::fut_bond_isin

auto to_bson(FORTS_FUTINFO_REPL::fut_bond_isin &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"replID", std::to_string(value.replID).c_str());
    BSON_APPEND_UTF8(doc,"replRev", std::to_string(value.replRev).c_str());
    BSON_APPEND_UTF8(doc,"replAct", std::to_string(value.replAct).c_str());
    BSON_APPEND_UTF8(doc,"isin_id", std::to_string(value.isin_id).c_str());
    BSON_APPEND_UTF8(doc,"bond_id", std::to_string(value.bond_id).c_str());
    BSON_APPEND_UTF8(doc,"coeff_conversion", std::to_string(cg_bcd_to_int64(value.coeff_conversion)).c_str());
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct FORTS_FUTINFO_REPL::user

auto to_csv(FORTS_FUTINFO_REPL::user &value) {
    std::stringstream ss;
    ss << "user" <<",";
    ss << value.replID << ",";
    ss << value.replRev << ",";
    ss << value.replAct << ",";
    ss << value.login << ",";
    ss << std::to_string(cg_time_to_unix_time(value.start_date)).c_str() << ",";
    ss << std::to_string(cg_time_to_unix_time(value.end_date)).c_str() << ",";
    ss << value.client_code << ",";
    ss << value.operation_mask << ",";
    ss << int(value.lang) << ",";
    ss << value.sma_flags << ",";
    ss << value.sma_status << ",";
    ss << value.aspref << ",";
    return ss.str();
}


//struct FORTS_FUTINFO_REPL::user

auto to_bson(FORTS_FUTINFO_REPL::user &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"replID", std::to_string(value.replID).c_str());
    BSON_APPEND_UTF8(doc,"replRev", std::to_string(value.replRev).c_str());
    BSON_APPEND_UTF8(doc,"replAct", std::to_string(value.replAct).c_str());
    BSON_APPEND_UTF8(doc,"login", value.login);
    BSON_APPEND_UTF8(doc,"start_date", std::to_string(cg_time_to_unix_time(value.start_date)).c_str());
    BSON_APPEND_UTF8(doc,"end_date", std::to_string(cg_time_to_unix_time(value.end_date)).c_str());
    BSON_APPEND_UTF8(doc,"client_code", value.client_code);
    BSON_APPEND_UTF8(doc,"operation_mask", std::to_string(value.operation_mask).c_str());
    BSON_APPEND_UTF8(doc,"lang", std::to_string(value.lang).c_str());
    BSON_APPEND_UTF8(doc,"sma_flags", std::to_string(value.sma_flags).c_str());
    BSON_APPEND_UTF8(doc,"sma_status", std::to_string(value.sma_status).c_str());
    BSON_APPEND_UTF8(doc,"aspref", std::to_string(value.aspref).c_str());
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct FORTS_FUTINFO_REPL::usd_online

auto to_csv(FORTS_FUTINFO_REPL::usd_online &value) {
    std::stringstream ss;
    ss << "usd_online" <<",";
    ss << value.replID << ",";
    ss << value.replRev << ",";
    ss << value.replAct << ",";
    ss << value.id << ",";
    ss << cg_bcd_to_int64(value.rate) << ",";
    ss << std::to_string(cg_time_to_unix_time(value.moment)).c_str() << ",";
    return ss.str();
}


//struct FORTS_FUTINFO_REPL::usd_online

auto to_bson(FORTS_FUTINFO_REPL::usd_online &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"replID", std::to_string(value.replID).c_str());
    BSON_APPEND_UTF8(doc,"replRev", std::to_string(value.replRev).c_str());
    BSON_APPEND_UTF8(doc,"replAct", std::to_string(value.replAct).c_str());
    BSON_APPEND_UTF8(doc,"id", std::to_string(value.id).c_str());
    BSON_APPEND_UTF8(doc,"rate", std::to_string(cg_bcd_to_int64(value.rate)).c_str());
    BSON_APPEND_UTF8(doc,"moment", std::to_string(cg_time_to_unix_time(value.moment)).c_str());
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct FORTS_FUTINFO_REPL::investor

auto to_csv(FORTS_FUTINFO_REPL::investor &value) {
    std::stringstream ss;
    ss << "investor" <<",";
    ss << value.replID << ",";
    ss << value.replRev << ",";
    ss << value.replAct << ",";
    ss << value.client_code << ",";
    ss << value.name << ",";
    ss << value.status << ",";
    ss << int(value.calendar_spread_margin_type) << ",";
    ss << value.is_blank << ",";
    ss << cg_bcd_to_int64(value.short_option_minimum_charge_ratio) << ",";
    ss << int(value.ics_margin_type) << ",";
    ss << cg_bcd_to_int64(value.coeff_im) << ",";
    ss << int(value.no_fut_discount) << ",";
    ss << value.num_clr_2delivery << ",";
    ss << cg_bcd_to_int64(value.exp_weight) << ",";
    return ss.str();
}


//struct FORTS_FUTINFO_REPL::investor

auto to_bson(FORTS_FUTINFO_REPL::investor &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"replID", std::to_string(value.replID).c_str());
    BSON_APPEND_UTF8(doc,"replRev", std::to_string(value.replRev).c_str());
    BSON_APPEND_UTF8(doc,"replAct", std::to_string(value.replAct).c_str());
    BSON_APPEND_UTF8(doc,"client_code", value.client_code);
    BSON_APPEND_UTF8(doc,"name", value.name);
    BSON_APPEND_UTF8(doc,"status", std::to_string(value.status).c_str());
    BSON_APPEND_UTF8(doc,"calendar_spread_margin_type", std::to_string(value.calendar_spread_margin_type).c_str());
    BSON_APPEND_UTF8(doc,"is_blank", std::to_string(value.is_blank).c_str());
    BSON_APPEND_UTF8(doc,"short_option_minimum_charge_ratio", std::to_string(cg_bcd_to_int64(value.short_option_minimum_charge_ratio)).c_str());
    BSON_APPEND_UTF8(doc,"ics_margin_type", std::to_string(value.ics_margin_type).c_str());
    BSON_APPEND_UTF8(doc,"coeff_im", std::to_string(cg_bcd_to_int64(value.coeff_im)).c_str());
    BSON_APPEND_UTF8(doc,"no_fut_discount", std::to_string(value.no_fut_discount).c_str());
    BSON_APPEND_UTF8(doc,"num_clr_2delivery", std::to_string(value.num_clr_2delivery).c_str());
    BSON_APPEND_UTF8(doc,"exp_weight", std::to_string(cg_bcd_to_int64(value.exp_weight)).c_str());
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct FORTS_FUTINFO_REPL::fut_margin_type

auto to_csv(FORTS_FUTINFO_REPL::fut_margin_type &value) {
    std::stringstream ss;
    ss << "fut_margin_type" <<",";
    ss << value.replID << ",";
    ss << value.replRev << ",";
    ss << value.replAct << ",";
    ss << value.code << ",";
    ss << int(value.type) << ",";
    ss << int(value.margin_type) << ",";
    ss << int(value.UCP_type) << ",";
    ss << cg_bcd_to_int64(value.prohibit_coeff) << ",";
    ss << value.prohibit_type << ",";
    ss << int(value.settlement_account_type) << ",";
    return ss.str();
}


//struct FORTS_FUTINFO_REPL::fut_margin_type

auto to_bson(FORTS_FUTINFO_REPL::fut_margin_type &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"replID", std::to_string(value.replID).c_str());
    BSON_APPEND_UTF8(doc,"replRev", std::to_string(value.replRev).c_str());
    BSON_APPEND_UTF8(doc,"replAct", std::to_string(value.replAct).c_str());
    BSON_APPEND_UTF8(doc,"code", value.code);
    BSON_APPEND_UTF8(doc,"type", std::to_string(value.type).c_str());
    BSON_APPEND_UTF8(doc,"margin_type", std::to_string(value.margin_type).c_str());
    BSON_APPEND_UTF8(doc,"UCP_type", std::to_string(value.UCP_type).c_str());
    BSON_APPEND_UTF8(doc,"prohibit_coeff", std::to_string(cg_bcd_to_int64(value.prohibit_coeff)).c_str());
    BSON_APPEND_UTF8(doc,"prohibit_type", std::to_string(value.prohibit_type).c_str());
    BSON_APPEND_UTF8(doc,"settlement_account_type", std::to_string(value.settlement_account_type).c_str());
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct FORTS_FUTINFO_REPL::fut_settlement_account

auto to_csv(FORTS_FUTINFO_REPL::fut_settlement_account &value) {
    std::stringstream ss;
    ss << "fut_settlement_account" <<",";
    ss << value.replID << ",";
    ss << value.replRev << ",";
    ss << value.replAct << ",";
    ss << value.code << ",";
    ss << int(value.type) << ",";
    ss << value.settlement_account << ",";
    return ss.str();
}


//struct FORTS_FUTINFO_REPL::fut_settlement_account

auto to_bson(FORTS_FUTINFO_REPL::fut_settlement_account &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"replID", std::to_string(value.replID).c_str());
    BSON_APPEND_UTF8(doc,"replRev", std::to_string(value.replRev).c_str());
    BSON_APPEND_UTF8(doc,"replAct", std::to_string(value.replAct).c_str());
    BSON_APPEND_UTF8(doc,"code", value.code);
    BSON_APPEND_UTF8(doc,"type", std::to_string(value.type).c_str());
    BSON_APPEND_UTF8(doc,"settlement_account", value.settlement_account);
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct FORTS_FUTINFO_REPL::session

auto to_csv(FORTS_FUTINFO_REPL::session &value) {
    std::stringstream ss;
    ss << "session" <<",";
    ss << value.replID << ",";
    ss << value.replRev << ",";
    ss << value.replAct << ",";
    ss << value.sess_id << ",";
    ss << std::to_string(cg_time_to_unix_time(value.begin)).c_str() << ",";
    ss << std::to_string(cg_time_to_unix_time(value.end)).c_str() << ",";
    ss << value.state << ",";
    ss << value.opt_sess_id << ",";
    ss << std::to_string(cg_time_to_unix_time(value.inter_cl_begin)).c_str() << ",";
    ss << std::to_string(cg_time_to_unix_time(value.inter_cl_end)).c_str() << ",";
    ss << value.inter_cl_state << ",";
    ss << int(value.eve_on) << ",";
    ss << std::to_string(cg_time_to_unix_time(value.eve_begin)).c_str() << ",";
    ss << std::to_string(cg_time_to_unix_time(value.eve_end)).c_str() << ",";
    ss << int(value.mon_on) << ",";
    ss << std::to_string(cg_time_to_unix_time(value.mon_begin)).c_str() << ",";
    ss << std::to_string(cg_time_to_unix_time(value.mon_end)).c_str() << ",";
    ss << std::to_string(cg_time_to_unix_time(value.pos_transfer_begin)).c_str() << ",";
    ss << std::to_string(cg_time_to_unix_time(value.pos_transfer_end)).c_str() << ",";
    return ss.str();
}


//struct FORTS_FUTINFO_REPL::session

auto to_bson(FORTS_FUTINFO_REPL::session &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"replID", std::to_string(value.replID).c_str());
    BSON_APPEND_UTF8(doc,"replRev", std::to_string(value.replRev).c_str());
    BSON_APPEND_UTF8(doc,"replAct", std::to_string(value.replAct).c_str());
    BSON_APPEND_UTF8(doc,"sess_id", std::to_string(value.sess_id).c_str());
    BSON_APPEND_UTF8(doc,"begin", std::to_string(cg_time_to_unix_time(value.begin)).c_str());
    BSON_APPEND_UTF8(doc,"end", std::to_string(cg_time_to_unix_time(value.end)).c_str());
    BSON_APPEND_UTF8(doc,"state", std::to_string(value.state).c_str());
    BSON_APPEND_UTF8(doc,"opt_sess_id", std::to_string(value.opt_sess_id).c_str());
    BSON_APPEND_UTF8(doc,"inter_cl_begin", std::to_string(cg_time_to_unix_time(value.inter_cl_begin)).c_str());
    BSON_APPEND_UTF8(doc,"inter_cl_end", std::to_string(cg_time_to_unix_time(value.inter_cl_end)).c_str());
    BSON_APPEND_UTF8(doc,"inter_cl_state", std::to_string(value.inter_cl_state).c_str());
    BSON_APPEND_UTF8(doc,"eve_on", std::to_string(value.eve_on).c_str());
    BSON_APPEND_UTF8(doc,"eve_begin", std::to_string(cg_time_to_unix_time(value.eve_begin)).c_str());
    BSON_APPEND_UTF8(doc,"eve_end", std::to_string(cg_time_to_unix_time(value.eve_end)).c_str());
    BSON_APPEND_UTF8(doc,"mon_on", std::to_string(value.mon_on).c_str());
    BSON_APPEND_UTF8(doc,"mon_begin", std::to_string(cg_time_to_unix_time(value.mon_begin)).c_str());
    BSON_APPEND_UTF8(doc,"mon_end", std::to_string(cg_time_to_unix_time(value.mon_end)).c_str());
    BSON_APPEND_UTF8(doc,"pos_transfer_begin", std::to_string(cg_time_to_unix_time(value.pos_transfer_begin)).c_str());
    BSON_APPEND_UTF8(doc,"pos_transfer_end", std::to_string(cg_time_to_unix_time(value.pos_transfer_end)).c_str());
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct FORTS_FUTINFO_REPL::sma_master

auto to_csv(FORTS_FUTINFO_REPL::sma_master &value) {
    std::stringstream ss;
    ss << "sma_master" <<",";
    ss << value.replID << ",";
    ss << value.replRev << ",";
    ss << value.replAct << ",";
    ss << value.sma_asp << ",";
    ss << value.sma_aspref << ",";
    ss << value.master_asp << ",";
    ss << value.master_aspref << ",";
    return ss.str();
}


//struct FORTS_FUTINFO_REPL::sma_master

auto to_bson(FORTS_FUTINFO_REPL::sma_master &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"replID", std::to_string(value.replID).c_str());
    BSON_APPEND_UTF8(doc,"replRev", std::to_string(value.replRev).c_str());
    BSON_APPEND_UTF8(doc,"replAct", std::to_string(value.replAct).c_str());
    BSON_APPEND_UTF8(doc,"sma_asp", value.sma_asp);
    BSON_APPEND_UTF8(doc,"sma_aspref", std::to_string(value.sma_aspref).c_str());
    BSON_APPEND_UTF8(doc,"master_asp", value.master_asp);
    BSON_APPEND_UTF8(doc,"master_aspref", std::to_string(value.master_aspref).c_str());
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct FORTS_FUTINFO_REPL::sma_pre_trade_check

auto to_csv(FORTS_FUTINFO_REPL::sma_pre_trade_check &value) {
    std::stringstream ss;
    ss << "sma_pre_trade_check" <<",";
    ss << value.replID << ",";
    ss << value.replRev << ",";
    ss << value.replAct << ",";
    ss << value.check_id << ",";
    ss << value.sma_asp << ",";
    ss << value.sma_aspref << ",";
    ss << int(value.check_number) << ",";
    ss << value.base_contract_code << ",";
    ss << int(value.instrument_type) << ",";
    ss << value.client_code_check << ",";
    ss << cg_bcd_to_int64(value.value) << ",";
    return ss.str();
}


//struct FORTS_FUTINFO_REPL::sma_pre_trade_check

auto to_bson(FORTS_FUTINFO_REPL::sma_pre_trade_check &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"replID", std::to_string(value.replID).c_str());
    BSON_APPEND_UTF8(doc,"replRev", std::to_string(value.replRev).c_str());
    BSON_APPEND_UTF8(doc,"replAct", std::to_string(value.replAct).c_str());
    BSON_APPEND_UTF8(doc,"check_id", std::to_string(value.check_id).c_str());
    BSON_APPEND_UTF8(doc,"sma_asp", value.sma_asp);
    BSON_APPEND_UTF8(doc,"sma_aspref", std::to_string(value.sma_aspref).c_str());
    BSON_APPEND_UTF8(doc,"check_number", std::to_string(value.check_number).c_str());
    BSON_APPEND_UTF8(doc,"base_contract_code", value.base_contract_code);
    BSON_APPEND_UTF8(doc,"instrument_type", std::to_string(value.instrument_type).c_str());
    BSON_APPEND_UTF8(doc,"client_code_check", value.client_code_check);
    BSON_APPEND_UTF8(doc,"value", std::to_string(cg_bcd_to_int64(value.value)).c_str());
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct FORTS_FUTINFO_REPL::clearing_members

auto to_csv(FORTS_FUTINFO_REPL::clearing_members &value) {
    std::stringstream ss;
    ss << "clearing_members" <<",";
    ss << value.replID << ",";
    ss << value.replRev << ",";
    ss << value.replAct << ",";
    ss << value.code << ",";
    ss << int(value.lock_type) << ",";
    ss << std::to_string(cg_time_to_unix_time(value.lock_date)).c_str() << ",";
    ss << value.name << ",";
    return ss.str();
}


//struct FORTS_FUTINFO_REPL::clearing_members

auto to_bson(FORTS_FUTINFO_REPL::clearing_members &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"replID", std::to_string(value.replID).c_str());
    BSON_APPEND_UTF8(doc,"replRev", std::to_string(value.replRev).c_str());
    BSON_APPEND_UTF8(doc,"replAct", std::to_string(value.replAct).c_str());
    BSON_APPEND_UTF8(doc,"code", value.code);
    BSON_APPEND_UTF8(doc,"lock_type", std::to_string(value.lock_type).c_str());
    BSON_APPEND_UTF8(doc,"lock_date", std::to_string(cg_time_to_unix_time(value.lock_date)).c_str());
    BSON_APPEND_UTF8(doc,"name", value.name);
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct FORTS_FUTINFO_REPL::sys_events

auto to_csv(FORTS_FUTINFO_REPL::sys_events &value) {
    std::stringstream ss;
    ss << "sys_events" <<",";
    ss << value.replID << ",";
    ss << value.replRev << ",";
    ss << value.replAct << ",";
    ss << value.event_id << ",";
    ss << value.sess_id << ",";
    ss << value.event_type << ",";
    ss << value.message << ",";
    return ss.str();
}


//struct FORTS_FUTINFO_REPL::sys_events

auto to_bson(FORTS_FUTINFO_REPL::sys_events &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"replID", std::to_string(value.replID).c_str());
    BSON_APPEND_UTF8(doc,"replRev", std::to_string(value.replRev).c_str());
    BSON_APPEND_UTF8(doc,"replAct", std::to_string(value.replAct).c_str());
    BSON_APPEND_UTF8(doc,"event_id", std::to_string(value.event_id).c_str());
    BSON_APPEND_UTF8(doc,"sess_id", std::to_string(value.sess_id).c_str());
    BSON_APPEND_UTF8(doc,"event_type", std::to_string(value.event_type).c_str());
    BSON_APPEND_UTF8(doc,"message", value.message);
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct FORTS_FUTCOMMON_REPL::common

auto to_csv(FORTS_FUTCOMMON_REPL::common &value) {
    std::stringstream ss;
    ss << "common" <<",";
    ss << value.replID << ",";
    ss << value.replRev << ",";
    ss << value.replAct << ",";
    ss << value.sess_id << ",";
    ss << value.isin_id << ",";
    ss << cg_bcd_to_int64(value.best_buy) << ",";
    ss << value.xamount_buy << ",";
    ss << value.orders_buy_qty << ",";
    ss << value.xorders_buy_amount << ",";
    ss << cg_bcd_to_int64(value.best_sell) << ",";
    ss << value.xamount_sell << ",";
    ss << value.orders_sell_qty << ",";
    ss << value.xorders_sell_amount << ",";
    ss << cg_bcd_to_int64(value.open_price) << ",";
    ss << cg_bcd_to_int64(value.close_price) << ",";
    ss << cg_bcd_to_int64(value.price) << ",";
    ss << cg_bcd_to_int64(value.trend) << ",";
    ss << value.xamount << ",";
    ss << std::to_string(cg_time_to_unix_time(value.deal_time)).c_str() << ",";
    ss << value.deal_time_ns << ",";
    ss << cg_bcd_to_int64(value.min_price) << ",";
    ss << cg_bcd_to_int64(value.max_price) << ",";
    ss << cg_bcd_to_int64(value.avr_price) << ",";
    ss << value.xcontr_count << ",";
    ss << cg_bcd_to_int64(value.capital) << ",";
    ss << value.deal_count << ",";
    ss << cg_bcd_to_int64(value.settlement_price_open) << ",";
    ss << value.xpos << ",";
    ss << std::to_string(cg_time_to_unix_time(value.mod_time)).c_str() << ",";
    ss << value.mod_time_ns << ",";
    ss << cg_bcd_to_int64(value.market_price) << ",";
    ss << std::to_string(cg_time_to_unix_time(value.local_time)).c_str() << ",";
    return ss.str();
}


//struct FORTS_FUTCOMMON_REPL::common

auto to_bson(FORTS_FUTCOMMON_REPL::common &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"replID", std::to_string(value.replID).c_str());
    BSON_APPEND_UTF8(doc,"replRev", std::to_string(value.replRev).c_str());
    BSON_APPEND_UTF8(doc,"replAct", std::to_string(value.replAct).c_str());
    BSON_APPEND_UTF8(doc,"sess_id", std::to_string(value.sess_id).c_str());
    BSON_APPEND_UTF8(doc,"isin_id", std::to_string(value.isin_id).c_str());
    BSON_APPEND_UTF8(doc,"best_buy", std::to_string(cg_bcd_to_int64(value.best_buy)).c_str());
    BSON_APPEND_UTF8(doc,"xamount_buy", std::to_string(value.xamount_buy).c_str());
    BSON_APPEND_UTF8(doc,"orders_buy_qty", std::to_string(value.orders_buy_qty).c_str());
    BSON_APPEND_UTF8(doc,"xorders_buy_amount", std::to_string(value.xorders_buy_amount).c_str());
    BSON_APPEND_UTF8(doc,"best_sell", std::to_string(cg_bcd_to_int64(value.best_sell)).c_str());
    BSON_APPEND_UTF8(doc,"xamount_sell", std::to_string(value.xamount_sell).c_str());
    BSON_APPEND_UTF8(doc,"orders_sell_qty", std::to_string(value.orders_sell_qty).c_str());
    BSON_APPEND_UTF8(doc,"xorders_sell_amount", std::to_string(value.xorders_sell_amount).c_str());
    BSON_APPEND_UTF8(doc,"open_price", std::to_string(cg_bcd_to_int64(value.open_price)).c_str());
    BSON_APPEND_UTF8(doc,"close_price", std::to_string(cg_bcd_to_int64(value.close_price)).c_str());
    BSON_APPEND_UTF8(doc,"price", std::to_string(cg_bcd_to_int64(value.price)).c_str());
    BSON_APPEND_UTF8(doc,"trend", std::to_string(cg_bcd_to_int64(value.trend)).c_str());
    BSON_APPEND_UTF8(doc,"xamount", std::to_string(value.xamount).c_str());
    BSON_APPEND_UTF8(doc,"deal_time", std::to_string(cg_time_to_unix_time(value.deal_time)).c_str());
    BSON_APPEND_UTF8(doc,"deal_time_ns", std::to_string(value.deal_time_ns).c_str());
    BSON_APPEND_UTF8(doc,"min_price", std::to_string(cg_bcd_to_int64(value.min_price)).c_str());
    BSON_APPEND_UTF8(doc,"max_price", std::to_string(cg_bcd_to_int64(value.max_price)).c_str());
    BSON_APPEND_UTF8(doc,"avr_price", std::to_string(cg_bcd_to_int64(value.avr_price)).c_str());
    BSON_APPEND_UTF8(doc,"xcontr_count", std::to_string(value.xcontr_count).c_str());
    BSON_APPEND_UTF8(doc,"capital", std::to_string(cg_bcd_to_int64(value.capital)).c_str());
    BSON_APPEND_UTF8(doc,"deal_count", std::to_string(value.deal_count).c_str());
    BSON_APPEND_UTF8(doc,"settlement_price_open", std::to_string(cg_bcd_to_int64(value.settlement_price_open)).c_str());
    BSON_APPEND_UTF8(doc,"xpos", std::to_string(value.xpos).c_str());
    BSON_APPEND_UTF8(doc,"mod_time", std::to_string(cg_time_to_unix_time(value.mod_time)).c_str());
    BSON_APPEND_UTF8(doc,"mod_time_ns", std::to_string(value.mod_time_ns).c_str());
    BSON_APPEND_UTF8(doc,"market_price", std::to_string(cg_bcd_to_int64(value.market_price)).c_str());
    BSON_APPEND_UTF8(doc,"local_time", std::to_string(cg_time_to_unix_time(value.local_time)).c_str());
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct FORTS_FUTTRADE_REPL::orders_log

auto to_csv(FORTS_FUTTRADE_REPL::orders_log &value) {
    std::stringstream ss;
    ss << "orders_log" <<",";
    ss << value.replID << ",";
    ss << value.replRev << ",";
    ss << value.replAct << ",";
    ss << value.id_ord << ",";
    ss << value.sess_id << ",";
    ss << value.isin_id << ",";
    ss << value.xamount << ",";
    ss << value.xamount_rest << ",";
    ss << value.id_deal << ",";
    ss << value.xstatus << ",";
    ss << cg_bcd_to_int64(value.price) << ",";
    ss << std::to_string(cg_time_to_unix_time(value.moment)).c_str() << ",";
    ss << value.moment_ns << ",";
    ss << int(value.dir) << ",";
    ss << int(value.action) << ",";
    ss << cg_bcd_to_int64(value.deal_price) << ",";
    ss << value.client_code << ",";
    ss << value.login_from << ",";
    ss << value.comment << ",";
    ss << value.ext_id << ",";
    ss << value.broker_to << ",";
    ss << value.broker_to_rts << ",";
    ss << value.broker_from_rts << ",";
    ss << std::to_string(cg_time_to_unix_time(value.date_exp)).c_str() << ",";
    ss << value.id_ord1 << ",";
    ss << std::to_string(cg_time_to_unix_time(value.local_stamp)).c_str() << ",";
    ss << value.aspref << ",";
    return ss.str();
}


//struct FORTS_FUTTRADE_REPL::orders_log

auto to_bson(FORTS_FUTTRADE_REPL::orders_log &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"replID", std::to_string(value.replID).c_str());
    BSON_APPEND_UTF8(doc,"replRev", std::to_string(value.replRev).c_str());
    BSON_APPEND_UTF8(doc,"replAct", std::to_string(value.replAct).c_str());
    BSON_APPEND_UTF8(doc,"id_ord", std::to_string(value.id_ord).c_str());
    BSON_APPEND_UTF8(doc,"sess_id", std::to_string(value.sess_id).c_str());
    BSON_APPEND_UTF8(doc,"isin_id", std::to_string(value.isin_id).c_str());
    BSON_APPEND_UTF8(doc,"xamount", std::to_string(value.xamount).c_str());
    BSON_APPEND_UTF8(doc,"xamount_rest", std::to_string(value.xamount_rest).c_str());
    BSON_APPEND_UTF8(doc,"id_deal", std::to_string(value.id_deal).c_str());
    BSON_APPEND_UTF8(doc,"xstatus", std::to_string(value.xstatus).c_str());
    BSON_APPEND_UTF8(doc,"price", std::to_string(cg_bcd_to_int64(value.price)).c_str());
    BSON_APPEND_UTF8(doc,"moment", std::to_string(cg_time_to_unix_time(value.moment)).c_str());
    BSON_APPEND_UTF8(doc,"moment_ns", std::to_string(value.moment_ns).c_str());
    BSON_APPEND_UTF8(doc,"dir", std::to_string(value.dir).c_str());
    BSON_APPEND_UTF8(doc,"action", std::to_string(value.action).c_str());
    BSON_APPEND_UTF8(doc,"deal_price", std::to_string(cg_bcd_to_int64(value.deal_price)).c_str());
    BSON_APPEND_UTF8(doc,"client_code", value.client_code);
    BSON_APPEND_UTF8(doc,"login_from", value.login_from);
    BSON_APPEND_UTF8(doc,"comment", value.comment);
    BSON_APPEND_UTF8(doc,"ext_id", std::to_string(value.ext_id).c_str());
    BSON_APPEND_UTF8(doc,"broker_to", value.broker_to);
    BSON_APPEND_UTF8(doc,"broker_to_rts", value.broker_to_rts);
    BSON_APPEND_UTF8(doc,"broker_from_rts", value.broker_from_rts);
    BSON_APPEND_UTF8(doc,"date_exp", std::to_string(cg_time_to_unix_time(value.date_exp)).c_str());
    BSON_APPEND_UTF8(doc,"id_ord1", std::to_string(value.id_ord1).c_str());
    BSON_APPEND_UTF8(doc,"local_stamp", std::to_string(cg_time_to_unix_time(value.local_stamp)).c_str());
    BSON_APPEND_UTF8(doc,"aspref", std::to_string(value.aspref).c_str());
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct FORTS_FUTTRADE_REPL::multileg_orders_log

auto to_csv(FORTS_FUTTRADE_REPL::multileg_orders_log &value) {
    std::stringstream ss;
    ss << "multileg_orders_log" <<",";
    ss << value.replID << ",";
    ss << value.replRev << ",";
    ss << value.replAct << ",";
    ss << value.id_ord << ",";
    ss << value.sess_id << ",";
    ss << value.isin_id << ",";
    ss << value.xamount << ",";
    ss << value.xamount_rest << ",";
    ss << value.id_deal << ",";
    ss << value.xstatus << ",";
    ss << cg_bcd_to_int64(value.price) << ",";
    ss << std::to_string(cg_time_to_unix_time(value.moment)).c_str() << ",";
    ss << value.moment_ns << ",";
    ss << int(value.dir) << ",";
    ss << int(value.action) << ",";
    ss << cg_bcd_to_int64(value.deal_price) << ",";
    ss << cg_bcd_to_int64(value.rate_price) << ",";
    ss << cg_bcd_to_int64(value.swap_price) << ",";
    ss << value.client_code << ",";
    ss << value.login_from << ",";
    ss << value.comment << ",";
    ss << value.ext_id << ",";
    ss << value.broker_to << ",";
    ss << value.broker_to_rts << ",";
    ss << value.broker_from_rts << ",";
    ss << std::to_string(cg_time_to_unix_time(value.date_exp)).c_str() << ",";
    ss << value.id_ord1 << ",";
    ss << std::to_string(cg_time_to_unix_time(value.local_stamp)).c_str() << ",";
    ss << value.aspref << ",";
    return ss.str();
}


//struct FORTS_FUTTRADE_REPL::multileg_orders_log

auto to_bson(FORTS_FUTTRADE_REPL::multileg_orders_log &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"replID", std::to_string(value.replID).c_str());
    BSON_APPEND_UTF8(doc,"replRev", std::to_string(value.replRev).c_str());
    BSON_APPEND_UTF8(doc,"replAct", std::to_string(value.replAct).c_str());
    BSON_APPEND_UTF8(doc,"id_ord", std::to_string(value.id_ord).c_str());
    BSON_APPEND_UTF8(doc,"sess_id", std::to_string(value.sess_id).c_str());
    BSON_APPEND_UTF8(doc,"isin_id", std::to_string(value.isin_id).c_str());
    BSON_APPEND_UTF8(doc,"xamount", std::to_string(value.xamount).c_str());
    BSON_APPEND_UTF8(doc,"xamount_rest", std::to_string(value.xamount_rest).c_str());
    BSON_APPEND_UTF8(doc,"id_deal", std::to_string(value.id_deal).c_str());
    BSON_APPEND_UTF8(doc,"xstatus", std::to_string(value.xstatus).c_str());
    BSON_APPEND_UTF8(doc,"price", std::to_string(cg_bcd_to_int64(value.price)).c_str());
    BSON_APPEND_UTF8(doc,"moment", std::to_string(cg_time_to_unix_time(value.moment)).c_str());
    BSON_APPEND_UTF8(doc,"moment_ns", std::to_string(value.moment_ns).c_str());
    BSON_APPEND_UTF8(doc,"dir", std::to_string(value.dir).c_str());
    BSON_APPEND_UTF8(doc,"action", std::to_string(value.action).c_str());
    BSON_APPEND_UTF8(doc,"deal_price", std::to_string(cg_bcd_to_int64(value.deal_price)).c_str());
    BSON_APPEND_UTF8(doc,"rate_price", std::to_string(cg_bcd_to_int64(value.rate_price)).c_str());
    BSON_APPEND_UTF8(doc,"swap_price", std::to_string(cg_bcd_to_int64(value.swap_price)).c_str());
    BSON_APPEND_UTF8(doc,"client_code", value.client_code);
    BSON_APPEND_UTF8(doc,"login_from", value.login_from);
    BSON_APPEND_UTF8(doc,"comment", value.comment);
    BSON_APPEND_UTF8(doc,"ext_id", std::to_string(value.ext_id).c_str());
    BSON_APPEND_UTF8(doc,"broker_to", value.broker_to);
    BSON_APPEND_UTF8(doc,"broker_to_rts", value.broker_to_rts);
    BSON_APPEND_UTF8(doc,"broker_from_rts", value.broker_from_rts);
    BSON_APPEND_UTF8(doc,"date_exp", std::to_string(cg_time_to_unix_time(value.date_exp)).c_str());
    BSON_APPEND_UTF8(doc,"id_ord1", std::to_string(value.id_ord1).c_str());
    BSON_APPEND_UTF8(doc,"local_stamp", std::to_string(cg_time_to_unix_time(value.local_stamp)).c_str());
    BSON_APPEND_UTF8(doc,"aspref", std::to_string(value.aspref).c_str());
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct FORTS_FUTTRADE_REPL::heartbeat

auto to_csv(FORTS_FUTTRADE_REPL::heartbeat &value) {
    std::stringstream ss;
    ss << "heartbeat" <<",";
    ss << value.replID << ",";
    ss << value.replRev << ",";
    ss << value.replAct << ",";
    ss << std::to_string(cg_time_to_unix_time(value.server_time)).c_str() << ",";
    return ss.str();
}


//struct FORTS_FUTTRADE_REPL::heartbeat

auto to_bson(FORTS_FUTTRADE_REPL::heartbeat &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"replID", std::to_string(value.replID).c_str());
    BSON_APPEND_UTF8(doc,"replRev", std::to_string(value.replRev).c_str());
    BSON_APPEND_UTF8(doc,"replAct", std::to_string(value.replAct).c_str());
    BSON_APPEND_UTF8(doc,"server_time", std::to_string(cg_time_to_unix_time(value.server_time)).c_str());
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct FORTS_FUTTRADE_REPL::sys_events

auto to_csv(FORTS_FUTTRADE_REPL::sys_events &value) {
    std::stringstream ss;
    ss << "sys_events" <<",";
    ss << value.replID << ",";
    ss << value.replRev << ",";
    ss << value.replAct << ",";
    ss << value.event_id << ",";
    ss << value.sess_id << ",";
    ss << value.event_type << ",";
    ss << value.message << ",";
    return ss.str();
}


//struct FORTS_FUTTRADE_REPL::sys_events

auto to_bson(FORTS_FUTTRADE_REPL::sys_events &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"replID", std::to_string(value.replID).c_str());
    BSON_APPEND_UTF8(doc,"replRev", std::to_string(value.replRev).c_str());
    BSON_APPEND_UTF8(doc,"replAct", std::to_string(value.replAct).c_str());
    BSON_APPEND_UTF8(doc,"event_id", std::to_string(value.event_id).c_str());
    BSON_APPEND_UTF8(doc,"sess_id", std::to_string(value.sess_id).c_str());
    BSON_APPEND_UTF8(doc,"event_type", std::to_string(value.event_type).c_str());
    BSON_APPEND_UTF8(doc,"message", value.message);
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct FORTS_FUTTRADE_REPL::user_deal

auto to_csv(FORTS_FUTTRADE_REPL::user_deal &value) {
    std::stringstream ss;
    ss << "user_deal" <<",";
    ss << value.replID << ",";
    ss << value.replRev << ",";
    ss << value.replAct << ",";
    ss << value.sess_id << ",";
    ss << value.isin_id << ",";
    ss << value.id_deal << ",";
    ss << value.id_deal_multileg << ",";
    ss << value.id_repo << ",";
    ss << value.xpos << ",";
    ss << value.xamount << ",";
    ss << value.id_ord_buy << ",";
    ss << value.id_ord_sell << ",";
    ss << cg_bcd_to_int64(value.price) << ",";
    ss << std::to_string(cg_time_to_unix_time(value.moment)).c_str() << ",";
    ss << value.moment_ns << ",";
    ss << int(value.nosystem) << ",";
    ss << value.xstatus_buy << ",";
    ss << value.xstatus_sell << ",";
    ss << value.ext_id_buy << ",";
    ss << value.ext_id_sell << ",";
    ss << value.code_buy << ",";
    ss << value.code_sell << ",";
    ss << value.comment_buy << ",";
    ss << value.comment_sell << ",";
    ss << cg_bcd_to_int64(value.fee_buy) << ",";
    ss << cg_bcd_to_int64(value.fee_sell) << ",";
    ss << value.login_buy << ",";
    ss << value.login_sell << ",";
    ss << value.code_rts_buy << ",";
    ss << value.code_rts_sell << ",";
    return ss.str();
}


//struct FORTS_FUTTRADE_REPL::user_deal

auto to_bson(FORTS_FUTTRADE_REPL::user_deal &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"replID", std::to_string(value.replID).c_str());
    BSON_APPEND_UTF8(doc,"replRev", std::to_string(value.replRev).c_str());
    BSON_APPEND_UTF8(doc,"replAct", std::to_string(value.replAct).c_str());
    BSON_APPEND_UTF8(doc,"sess_id", std::to_string(value.sess_id).c_str());
    BSON_APPEND_UTF8(doc,"isin_id", std::to_string(value.isin_id).c_str());
    BSON_APPEND_UTF8(doc,"id_deal", std::to_string(value.id_deal).c_str());
    BSON_APPEND_UTF8(doc,"id_deal_multileg", std::to_string(value.id_deal_multileg).c_str());
    BSON_APPEND_UTF8(doc,"id_repo", std::to_string(value.id_repo).c_str());
    BSON_APPEND_UTF8(doc,"xpos", std::to_string(value.xpos).c_str());
    BSON_APPEND_UTF8(doc,"xamount", std::to_string(value.xamount).c_str());
    BSON_APPEND_UTF8(doc,"id_ord_buy", std::to_string(value.id_ord_buy).c_str());
    BSON_APPEND_UTF8(doc,"id_ord_sell", std::to_string(value.id_ord_sell).c_str());
    BSON_APPEND_UTF8(doc,"price", std::to_string(cg_bcd_to_int64(value.price)).c_str());
    BSON_APPEND_UTF8(doc,"moment", std::to_string(cg_time_to_unix_time(value.moment)).c_str());
    BSON_APPEND_UTF8(doc,"moment_ns", std::to_string(value.moment_ns).c_str());
    BSON_APPEND_UTF8(doc,"nosystem", std::to_string(value.nosystem).c_str());
    BSON_APPEND_UTF8(doc,"xstatus_buy", std::to_string(value.xstatus_buy).c_str());
    BSON_APPEND_UTF8(doc,"xstatus_sell", std::to_string(value.xstatus_sell).c_str());
    BSON_APPEND_UTF8(doc,"ext_id_buy", std::to_string(value.ext_id_buy).c_str());
    BSON_APPEND_UTF8(doc,"ext_id_sell", std::to_string(value.ext_id_sell).c_str());
    BSON_APPEND_UTF8(doc,"code_buy", value.code_buy);
    BSON_APPEND_UTF8(doc,"code_sell", value.code_sell);
    BSON_APPEND_UTF8(doc,"comment_buy", value.comment_buy);
    BSON_APPEND_UTF8(doc,"comment_sell", value.comment_sell);
    BSON_APPEND_UTF8(doc,"fee_buy", std::to_string(cg_bcd_to_int64(value.fee_buy)).c_str());
    BSON_APPEND_UTF8(doc,"fee_sell", std::to_string(cg_bcd_to_int64(value.fee_sell)).c_str());
    BSON_APPEND_UTF8(doc,"login_buy", value.login_buy);
    BSON_APPEND_UTF8(doc,"login_sell", value.login_sell);
    BSON_APPEND_UTF8(doc,"code_rts_buy", value.code_rts_buy);
    BSON_APPEND_UTF8(doc,"code_rts_sell", value.code_rts_sell);
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}


//struct FORTS_FUTTRADE_REPL::user_multileg_deal

auto to_csv(FORTS_FUTTRADE_REPL::user_multileg_deal &value) {
    std::stringstream ss;
    ss << "user_multileg_deal" <<",";
    ss << value.replID << ",";
    ss << value.replRev << ",";
    ss << value.replAct << ",";
    ss << value.sess_id << ",";
    ss << value.isin_id << ",";
    ss << value.isin_id_rd << ",";
    ss << value.isin_id_rb << ",";
    ss << value.duration << ",";
    ss << value.id_deal << ",";
    ss << value.id_deal_rd << ",";
    ss << value.id_deal_rb << ",";
    ss << value.id_ord_buy << ",";
    ss << value.id_ord_sell << ",";
    ss << value.xamount << ",";
    ss << cg_bcd_to_int64(value.price) << ",";
    ss << cg_bcd_to_int64(value.rate_price) << ",";
    ss << cg_bcd_to_int64(value.swap_price) << ",";
    ss << std::to_string(cg_time_to_unix_time(value.moment)).c_str() << ",";
    ss << value.moment_ns << ",";
    ss << int(value.nosystem) << ",";
    ss << value.xstatus_buy << ",";
    ss << value.xstatus_sell << ",";
    ss << value.ext_id_buy << ",";
    ss << value.ext_id_sell << ",";
    ss << value.code_buy << ",";
    ss << value.code_sell << ",";
    ss << value.comment_buy << ",";
    ss << value.comment_sell << ",";
    ss << value.login_buy << ",";
    ss << value.login_sell << ",";
    ss << value.code_rts_buy << ",";
    ss << value.code_rts_sell << ",";
    return ss.str();
}


//struct FORTS_FUTTRADE_REPL::user_multileg_deal

auto to_bson(FORTS_FUTTRADE_REPL::user_multileg_deal &value) {
    bson_t *doc;
    doc = bson_new();
    BSON_APPEND_UTF8(doc,"replID", std::to_string(value.replID).c_str());
    BSON_APPEND_UTF8(doc,"replRev", std::to_string(value.replRev).c_str());
    BSON_APPEND_UTF8(doc,"replAct", std::to_string(value.replAct).c_str());
    BSON_APPEND_UTF8(doc,"sess_id", std::to_string(value.sess_id).c_str());
    BSON_APPEND_UTF8(doc,"isin_id", std::to_string(value.isin_id).c_str());
    BSON_APPEND_UTF8(doc,"isin_id_rd", std::to_string(value.isin_id_rd).c_str());
    BSON_APPEND_UTF8(doc,"isin_id_rb", std::to_string(value.isin_id_rb).c_str());
    BSON_APPEND_UTF8(doc,"duration", std::to_string(value.duration).c_str());
    BSON_APPEND_UTF8(doc,"id_deal", std::to_string(value.id_deal).c_str());
    BSON_APPEND_UTF8(doc,"id_deal_rd", std::to_string(value.id_deal_rd).c_str());
    BSON_APPEND_UTF8(doc,"id_deal_rb", std::to_string(value.id_deal_rb).c_str());
    BSON_APPEND_UTF8(doc,"id_ord_buy", std::to_string(value.id_ord_buy).c_str());
    BSON_APPEND_UTF8(doc,"id_ord_sell", std::to_string(value.id_ord_sell).c_str());
    BSON_APPEND_UTF8(doc,"xamount", std::to_string(value.xamount).c_str());
    BSON_APPEND_UTF8(doc,"price", std::to_string(cg_bcd_to_int64(value.price)).c_str());
    BSON_APPEND_UTF8(doc,"rate_price", std::to_string(cg_bcd_to_int64(value.rate_price)).c_str());
    BSON_APPEND_UTF8(doc,"swap_price", std::to_string(cg_bcd_to_int64(value.swap_price)).c_str());
    BSON_APPEND_UTF8(doc,"moment", std::to_string(cg_time_to_unix_time(value.moment)).c_str());
    BSON_APPEND_UTF8(doc,"moment_ns", std::to_string(value.moment_ns).c_str());
    BSON_APPEND_UTF8(doc,"nosystem", std::to_string(value.nosystem).c_str());
    BSON_APPEND_UTF8(doc,"xstatus_buy", std::to_string(value.xstatus_buy).c_str());
    BSON_APPEND_UTF8(doc,"xstatus_sell", std::to_string(value.xstatus_sell).c_str());
    BSON_APPEND_UTF8(doc,"ext_id_buy", std::to_string(value.ext_id_buy).c_str());
    BSON_APPEND_UTF8(doc,"ext_id_sell", std::to_string(value.ext_id_sell).c_str());
    BSON_APPEND_UTF8(doc,"code_buy", value.code_buy);
    BSON_APPEND_UTF8(doc,"code_sell", value.code_sell);
    BSON_APPEND_UTF8(doc,"comment_buy", value.comment_buy);
    BSON_APPEND_UTF8(doc,"comment_sell", value.comment_sell);
    BSON_APPEND_UTF8(doc,"login_buy", value.login_buy);
    BSON_APPEND_UTF8(doc,"login_sell", value.login_sell);
    BSON_APPEND_UTF8(doc,"code_rts_buy", value.code_rts_buy);
    BSON_APPEND_UTF8(doc,"code_rts_sell", value.code_rts_sell);
    auto ptr = std::unique_ptr<bson_t>(doc);
    return ptr;
}

std::map<std::string, int> cgate_indexes{
{std::string("MOEX_RATES_REPL/tables/curr_online/index"),MOEX_RATES_REPL::curr_online_index},
{std::string("FORTS_OPTINFO_REPL/tables/opt_sess_contents/index"),FORTS_OPTINFO_REPL::opt_sess_contents_index},
{std::string("FORTS_OPTINFO_REPL/tables/opt_vcb/index"),FORTS_OPTINFO_REPL::opt_vcb_index},
{std::string("FORTS_OPTINFO_REPL/tables/opt_rejected_orders/index"),FORTS_OPTINFO_REPL::opt_rejected_orders_index},
{std::string("FORTS_OPTINFO_REPL/tables/opt_intercl_info/index"),FORTS_OPTINFO_REPL::opt_intercl_info_index},
{std::string("FORTS_OPTINFO_REPL/tables/opt_exp_orders/index"),FORTS_OPTINFO_REPL::opt_exp_orders_index},
{std::string("FORTS_OPTINFO_REPL/tables/option_series/index"),FORTS_OPTINFO_REPL::option_series_index},
{std::string("FORTS_OPTINFO_REPL/tables/sys_events/index"),FORTS_OPTINFO_REPL::sys_events_index},
{std::string("FORTS_POS_REPL/tables/position/index"),FORTS_POS_REPL::position_index},
{std::string("FORTS_POS_REPL/tables/position_sa/index"),FORTS_POS_REPL::position_sa_index},
{std::string("FORTS_POS_REPL/tables/sys_events/index"),FORTS_POS_REPL::sys_events_index},
{std::string("FORTS_OPTTRADE_REPL/tables/orders_log/index"),FORTS_OPTTRADE_REPL::orders_log_index},
{std::string("FORTS_OPTTRADE_REPL/tables/heartbeat/index"),FORTS_OPTTRADE_REPL::heartbeat_index},
{std::string("FORTS_OPTTRADE_REPL/tables/sys_events/index"),FORTS_OPTTRADE_REPL::sys_events_index},
{std::string("FORTS_OPTTRADE_REPL/tables/user_deal/index"),FORTS_OPTTRADE_REPL::user_deal_index},
{std::string("FORTS_OPTCOMMON_REPL/tables/common/index"),FORTS_OPTCOMMON_REPL::common_index},
{std::string("MESSAGE_PUB/tables/FutAddOrder/index"),MESSAGE_PUB::FutAddOrder_index},
{std::string("MESSAGE_PUB/tables/FORTS_MSG101/index"),MESSAGE_PUB::FORTS_MSG101_index},
{std::string("MESSAGE_PUB/tables/FutDelOrder/index"),MESSAGE_PUB::FutDelOrder_index},
{std::string("MESSAGE_PUB/tables/FORTS_MSG102/index"),MESSAGE_PUB::FORTS_MSG102_index},
{std::string("MESSAGE_PUB/tables/FutDelUserOrders/index"),MESSAGE_PUB::FutDelUserOrders_index},
{std::string("MESSAGE_PUB/tables/FORTS_MSG103/index"),MESSAGE_PUB::FORTS_MSG103_index},
{std::string("MESSAGE_PUB/tables/FutChangeClientMoney/index"),MESSAGE_PUB::FutChangeClientMoney_index},
{std::string("MESSAGE_PUB/tables/ChangeClientMoney/index"),MESSAGE_PUB::ChangeClientMoney_index},
{std::string("MESSAGE_PUB/tables/FORTS_MSG104/index"),MESSAGE_PUB::FORTS_MSG104_index},
{std::string("MESSAGE_PUB/tables/FutChangeBFMoney/index"),MESSAGE_PUB::FutChangeBFMoney_index},
{std::string("MESSAGE_PUB/tables/ChangeBFMoney/index"),MESSAGE_PUB::ChangeBFMoney_index},
{std::string("MESSAGE_PUB/tables/FORTS_MSG107/index"),MESSAGE_PUB::FORTS_MSG107_index},
{std::string("MESSAGE_PUB/tables/FutMoveOrder/index"),MESSAGE_PUB::FutMoveOrder_index},
{std::string("MESSAGE_PUB/tables/FORTS_MSG105/index"),MESSAGE_PUB::FORTS_MSG105_index},
{std::string("MESSAGE_PUB/tables/FutChangeClientProhibit/index"),MESSAGE_PUB::FutChangeClientProhibit_index},
{std::string("MESSAGE_PUB/tables/FORTS_MSG115/index"),MESSAGE_PUB::FORTS_MSG115_index},
{std::string("MESSAGE_PUB/tables/FutAddMultiLegOrder/index"),MESSAGE_PUB::FutAddMultiLegOrder_index},
{std::string("MESSAGE_PUB/tables/FORTS_MSG129/index"),MESSAGE_PUB::FORTS_MSG129_index},
{std::string("MESSAGE_PUB/tables/FutExchangeBFMoney/index"),MESSAGE_PUB::FutExchangeBFMoney_index},
{std::string("MESSAGE_PUB/tables/ExchangeBFMoney/index"),MESSAGE_PUB::ExchangeBFMoney_index},
{std::string("MESSAGE_PUB/tables/FORTS_MSG130/index"),MESSAGE_PUB::FORTS_MSG130_index},
{std::string("MESSAGE_PUB/tables/FutTransferClientPosition/index"),MESSAGE_PUB::FutTransferClientPosition_index},
{std::string("MESSAGE_PUB/tables/FORTS_MSG137/index"),MESSAGE_PUB::FORTS_MSG137_index},
{std::string("MESSAGE_PUB/tables/TransferClientPosition/index"),MESSAGE_PUB::TransferClientPosition_index},
{std::string("MESSAGE_PUB/tables/FORTS_MSG173/index"),MESSAGE_PUB::FORTS_MSG173_index},
{std::string("MESSAGE_PUB/tables/FutChangeBFLimit/index"),MESSAGE_PUB::FutChangeBFLimit_index},
{std::string("MESSAGE_PUB/tables/ChangeBFLimit/index"),MESSAGE_PUB::ChangeBFLimit_index},
{std::string("MESSAGE_PUB/tables/FORTS_MSG161/index"),MESSAGE_PUB::FORTS_MSG161_index},
{std::string("MESSAGE_PUB/tables/FutChangeBFParameters/index"),MESSAGE_PUB::FutChangeBFParameters_index},
{std::string("MESSAGE_PUB/tables/ChangeBFParameters/index"),MESSAGE_PUB::ChangeBFParameters_index},
{std::string("MESSAGE_PUB/tables/FORTS_MSG162/index"),MESSAGE_PUB::FORTS_MSG162_index},
{std::string("MESSAGE_PUB/tables/ChangeClientParametersNextSession/index"),MESSAGE_PUB::ChangeClientParametersNextSession_index},
{std::string("MESSAGE_PUB/tables/FORTS_MSG163/index"),MESSAGE_PUB::FORTS_MSG163_index},
{std::string("MESSAGE_PUB/tables/ChangeBFClientDefaultParameters/index"),MESSAGE_PUB::ChangeBFClientDefaultParameters_index},
{std::string("MESSAGE_PUB/tables/FORTS_MSG602/index"),MESSAGE_PUB::FORTS_MSG602_index},
{std::string("MESSAGE_PUB/tables/OptAddOrder/index"),MESSAGE_PUB::OptAddOrder_index},
{std::string("MESSAGE_PUB/tables/FORTS_MSG109/index"),MESSAGE_PUB::FORTS_MSG109_index},
{std::string("MESSAGE_PUB/tables/OptDelOrder/index"),MESSAGE_PUB::OptDelOrder_index},
{std::string("MESSAGE_PUB/tables/FORTS_MSG110/index"),MESSAGE_PUB::FORTS_MSG110_index},
{std::string("MESSAGE_PUB/tables/OptDelUserOrders/index"),MESSAGE_PUB::OptDelUserOrders_index},
{std::string("MESSAGE_PUB/tables/FORTS_MSG111/index"),MESSAGE_PUB::FORTS_MSG111_index},
{std::string("MESSAGE_PUB/tables/OptChangeExpiration/index"),MESSAGE_PUB::OptChangeExpiration_index},
{std::string("MESSAGE_PUB/tables/FORTS_MSG112/index"),MESSAGE_PUB::FORTS_MSG112_index},
{std::string("MESSAGE_PUB/tables/OptMoveOrder/index"),MESSAGE_PUB::OptMoveOrder_index},
{std::string("MESSAGE_PUB/tables/FORTS_MSG113/index"),MESSAGE_PUB::FORTS_MSG113_index},
{std::string("MESSAGE_PUB/tables/OptChangeClientProhibit/index"),MESSAGE_PUB::OptChangeClientProhibit_index},
{std::string("MESSAGE_PUB/tables/FORTS_MSG117/index"),MESSAGE_PUB::FORTS_MSG117_index},
{std::string("MESSAGE_PUB/tables/OptRecalcCS/index"),MESSAGE_PUB::OptRecalcCS_index},
{std::string("MESSAGE_PUB/tables/FORTS_MSG132/index"),MESSAGE_PUB::FORTS_MSG132_index},
{std::string("MESSAGE_PUB/tables/OptTransferClientPosition/index"),MESSAGE_PUB::OptTransferClientPosition_index},
{std::string("MESSAGE_PUB/tables/FORTS_MSG138/index"),MESSAGE_PUB::FORTS_MSG138_index},
{std::string("MESSAGE_PUB/tables/OptChangeRiskParameters/index"),MESSAGE_PUB::OptChangeRiskParameters_index},
{std::string("MESSAGE_PUB/tables/FORTS_MSG140/index"),MESSAGE_PUB::FORTS_MSG140_index},
{std::string("MESSAGE_PUB/tables/SetSmaPreTradeCheck/index"),MESSAGE_PUB::SetSmaPreTradeCheck_index},
{std::string("MESSAGE_PUB/tables/FORTS_MSG166/index"),MESSAGE_PUB::FORTS_MSG166_index},
{std::string("MESSAGE_PUB/tables/DelSmaPreTradeCheck/index"),MESSAGE_PUB::DelSmaPreTradeCheck_index},
{std::string("MESSAGE_PUB/tables/FORTS_MSG167/index"),MESSAGE_PUB::FORTS_MSG167_index},
{std::string("MESSAGE_PUB/tables/UserKillSwitch/index"),MESSAGE_PUB::UserKillSwitch_index},
{std::string("MESSAGE_PUB/tables/FORTS_MSG168/index"),MESSAGE_PUB::FORTS_MSG168_index},
{std::string("MESSAGE_PUB/tables/DelOrdersByBFLimit/index"),MESSAGE_PUB::DelOrdersByBFLimit_index},
{std::string("MESSAGE_PUB/tables/FORTS_MSG172/index"),MESSAGE_PUB::FORTS_MSG172_index},
{std::string("MESSAGE_PUB/tables/FutTransferRisk/index"),MESSAGE_PUB::FutTransferRisk_index},
{std::string("MESSAGE_PUB/tables/FORTS_MSG139/index"),MESSAGE_PUB::FORTS_MSG139_index},
{std::string("MESSAGE_PUB/tables/CODHeartbeat/index"),MESSAGE_PUB::CODHeartbeat_index},
{std::string("MESSAGE_PUB/tables/FORTS_MSG99/index"),MESSAGE_PUB::FORTS_MSG99_index},
{std::string("MESSAGE_PUB/tables/FORTS_MSG100/index"),MESSAGE_PUB::FORTS_MSG100_index},
{std::string("FORTS_PART_REPL/tables/part/index"),FORTS_PART_REPL::part_index},
{std::string("FORTS_PART_REPL/tables/part_sa/index"),FORTS_PART_REPL::part_sa_index},
{std::string("FORTS_PART_REPL/tables/sys_events/index"),FORTS_PART_REPL::sys_events_index},
{std::string("MCXCC_MDCOMMON_REPL/tables/COMMON/index"),MCXCC_MDCOMMON_REPL::COMMON_index},
{std::string("FORTS_FUTINFO_REPL/tables/rates/index"),FORTS_FUTINFO_REPL::rates_index},
{std::string("FORTS_FUTINFO_REPL/tables/fut_sess_contents/index"),FORTS_FUTINFO_REPL::fut_sess_contents_index},
{std::string("FORTS_FUTINFO_REPL/tables/fut_vcb/index"),FORTS_FUTINFO_REPL::fut_vcb_index},
{std::string("FORTS_FUTINFO_REPL/tables/fut_instruments/index"),FORTS_FUTINFO_REPL::fut_instruments_index},
{std::string("FORTS_FUTINFO_REPL/tables/fut_bond_registry/index"),FORTS_FUTINFO_REPL::fut_bond_registry_index},
{std::string("FORTS_FUTINFO_REPL/tables/dealer/index"),FORTS_FUTINFO_REPL::dealer_index},
{std::string("FORTS_FUTINFO_REPL/tables/sys_messages/index"),FORTS_FUTINFO_REPL::sys_messages_index},
{std::string("FORTS_FUTINFO_REPL/tables/prohibition/index"),FORTS_FUTINFO_REPL::prohibition_index},
{std::string("FORTS_FUTINFO_REPL/tables/multileg_dict/index"),FORTS_FUTINFO_REPL::multileg_dict_index},
{std::string("FORTS_FUTINFO_REPL/tables/fut_rejected_orders/index"),FORTS_FUTINFO_REPL::fut_rejected_orders_index},
{std::string("FORTS_FUTINFO_REPL/tables/fut_intercl_info/index"),FORTS_FUTINFO_REPL::fut_intercl_info_index},
{std::string("FORTS_FUTINFO_REPL/tables/fut_bond_nkd/index"),FORTS_FUTINFO_REPL::fut_bond_nkd_index},
{std::string("FORTS_FUTINFO_REPL/tables/fut_bond_nominal/index"),FORTS_FUTINFO_REPL::fut_bond_nominal_index},
{std::string("FORTS_FUTINFO_REPL/tables/fut_bond_isin/index"),FORTS_FUTINFO_REPL::fut_bond_isin_index},
{std::string("FORTS_FUTINFO_REPL/tables/user/index"),FORTS_FUTINFO_REPL::user_index},
{std::string("FORTS_FUTINFO_REPL/tables/usd_online/index"),FORTS_FUTINFO_REPL::usd_online_index},
{std::string("FORTS_FUTINFO_REPL/tables/investor/index"),FORTS_FUTINFO_REPL::investor_index},
{std::string("FORTS_FUTINFO_REPL/tables/fut_margin_type/index"),FORTS_FUTINFO_REPL::fut_margin_type_index},
{std::string("FORTS_FUTINFO_REPL/tables/fut_settlement_account/index"),FORTS_FUTINFO_REPL::fut_settlement_account_index},
{std::string("FORTS_FUTINFO_REPL/tables/session/index"),FORTS_FUTINFO_REPL::session_index},
{std::string("FORTS_FUTINFO_REPL/tables/sma_master/index"),FORTS_FUTINFO_REPL::sma_master_index},
{std::string("FORTS_FUTINFO_REPL/tables/sma_pre_trade_check/index"),FORTS_FUTINFO_REPL::sma_pre_trade_check_index},
{std::string("FORTS_FUTINFO_REPL/tables/clearing_members/index"),FORTS_FUTINFO_REPL::clearing_members_index},
{std::string("FORTS_FUTINFO_REPL/tables/sys_events/index"),FORTS_FUTINFO_REPL::sys_events_index},
{std::string("FORTS_FUTCOMMON_REPL/tables/common/index"),FORTS_FUTCOMMON_REPL::common_index},
{std::string("FORTS_FUTTRADE_REPL/tables/orders_log/index"),FORTS_FUTTRADE_REPL::orders_log_index},
{std::string("FORTS_FUTTRADE_REPL/tables/multileg_orders_log/index"),FORTS_FUTTRADE_REPL::multileg_orders_log_index},
{std::string("FORTS_FUTTRADE_REPL/tables/heartbeat/index"),FORTS_FUTTRADE_REPL::heartbeat_index},
{std::string("FORTS_FUTTRADE_REPL/tables/sys_events/index"),FORTS_FUTTRADE_REPL::sys_events_index},
{std::string("FORTS_FUTTRADE_REPL/tables/user_deal/index"),FORTS_FUTTRADE_REPL::user_deal_index},
{std::string("FORTS_FUTTRADE_REPL/tables/user_multileg_deal/index"),FORTS_FUTTRADE_REPL::user_multileg_deal_index},
};


#endif


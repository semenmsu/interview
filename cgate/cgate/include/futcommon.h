
#ifndef _FORTS_FUTCOMMON_REPL_H_
#define _FORTS_FUTCOMMON_REPL_H_



// Scheme "FORTS_FUTCOMMON_REPL" description


namespace FORTS_FUTCOMMON_REPL
{

#pragma pack(push, 4)

    static const char FORTS_FUTCOMMON_REPL_scheme_string[] = "|STRING|XeNqNlDtvwjAUhff-iihLpkJBLWIIoEp0YEVq1c0y9qW18CP4gcK_bxICBRIbT5HjT8fn2kcnX5SCJwfQhik5S0eDlzQBSRRl8meWOrt9nqaL-VNuyC8ImOcWbzgkEguYZUQJoWQ2z7cMOG1_aij4apkl9lhUKzbNht39NRzCwDuxfsCAMYjRC_B6DzDDZBDYgLFo445ngo4mg7d7qMRCOXnDdb0oTaurqxm0t0f_ieUVeNL1azbuDHAeZe8a9PqroTiDDfnIoSpAokIzAkGLhCsDEdxjwmqQNOY6_J4pYI4sE5eDrJdA0pwh19ERLGZ0gcsICh90BFUSJa1GJDwfwQWz-D8z48lg3DvhrU4nCIpTtFOW6aAnA9byqhCqADYDoDoS4SkKZfzuhaLhxzkDwbchTkd4F1jvwEZcPFekLzNMUihbZLX8RqcaRKsl-swSJ9neNYl1kLVsTz1WMsNmzyu3_viK1avr9Epw2HR09W07-w8f2vmk";


    struct common
    {
        signed long long replID; // i8
        signed long long replRev; // i8
        signed long long replAct; // i8
        signed int sess_id; // i4
        signed int isin_id; // i4
        char best_buy[11]; // d16.5
        signed long long xamount_buy; // i8
        signed int orders_buy_qty; // i4
        signed long long xorders_buy_amount; // i8
        char best_sell[11]; // d16.5
        signed long long xamount_sell; // i8
        signed int orders_sell_qty; // i4
        signed long long xorders_sell_amount; // i8
        char open_price[11]; // d16.5
        char close_price[11]; // d16.5
        char price[11]; // d16.5
        char trend[11]; // d16.5
        signed long long xamount; // i8
        struct cg_time_t deal_time; // t
        unsigned long long deal_time_ns; // u8
        char min_price[11]; // d16.5
        char max_price[11]; // d16.5
        char avr_price[11]; // d16.5
        signed long long xcontr_count; // i8
        char capital[15]; // d26.2
        signed int deal_count; // i4
        char old_kotir[11]; // d16.5
        char settlement_price_open[11]; // d16.5
        signed long long xpos; // i8
        struct cg_time_t mod_time; // t
        unsigned long long mod_time_ns; // u8
        char cur_kotir[11]; // d16.5
        char market_price[11]; // d16.5
        struct cg_time_t local_time; // t
        
    };


    const size_t sizeof_common = 316;
    const size_t common_index = 0;


#pragma pack(pop)

}




#endif //_FORTS_FUTCOMMON_REPL_H_


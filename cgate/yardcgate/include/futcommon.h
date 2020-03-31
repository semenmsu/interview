
#ifndef _FORTS_FUTCOMMON_REPL_H_
#define _FORTS_FUTCOMMON_REPL_H_



// Scheme "FORTS_FUTCOMMON_REPL" description


namespace FORTS_FUTCOMMON_REPL
{

#pragma pack(push, 4)

    static const char FORTS_FUTCOMMON_REPL_scheme_string[] = "|STRING|XeNqNlDtvwjAUhff-iihLpkJBFDEEUCU6sCK16mYZ-9Ja9SP4gcK_bxICBRIbT5HjT8fnHl_ffFkKnhxAG6bkPB0NXtIEJFGUye956uzueZYuF0-5IT8gYJFbvOWQSCxgnhElhJLZIt8x4LT9qaHg61WW2GNRrdgsG3b3N3AIA2_E-gEDxiBGL8DkHmCGySCwBWPR1h3PBB1NB6_3UImFcvKG63pRmlbR1Qza26P_xPIKPOn6NRt3BjiPsncNev3VUJzBhnzkUBUgUaEZgaBFwpWBCO4xYTVIGhOH3zMFzJFl4nKQ9RJImjPkOjqCxZQucBlB4YOOoEqipNWIhOsjuGAW__fMeDoY91Z4qzPpvi5refXUq9ZqrKH6ssP-CmX8voSi4djPQDh1rH_BRoTFFem7ZyYplC2yXn2h0-hC6xX6yBIn2d41XeYga9mekVbJDJs9r9zm_TNWrx6BV4LDZq5W33bO_gEt9ODj";


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
        char settlement_price_open[11]; // d16.5
        signed long long xpos; // i8
        struct cg_time_t mod_time; // t
        unsigned long long mod_time_ns; // u8
        char market_price[11]; // d16.5
        struct cg_time_t local_time; // t
        
    };


    const size_t sizeof_common = 296;
    const size_t common_index = 0;


#pragma pack(pop)

}




#endif //_FORTS_FUTCOMMON_REPL_H_


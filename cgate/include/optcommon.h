
#ifndef _FORTS_OPTCOMMON_REPL_H_
#define _FORTS_OPTCOMMON_REPL_H_



// Scheme "FORTS_OPTCOMMON_REPL" description


namespace FORTS_OPTCOMMON_REPL
{

#pragma pack(push, 4)

    static const char FORTS_OPTCOMMON_REPL_scheme_string[] = "|STRING|XeNqNlDtvwjAUhff-iihLpkJBFDGEoEp0YEVq1c0y9oVa8iP4gcK_bxICBYKNp8jxp-Nzr69PvqgETw6gDVNyno4Gb2kCkijK5G6eOrt9naWL4iU35BcEFLnFGw6JxALmGVFCKJkV-ZYBp91PDSVfLbPEHst6xWbZsL-_hkMY-CDWDxgwBjF6ASb3ADNMBoENGIs27ngm6Gg6eL-HKiyUkzdc34vStG5dw6C9PfpPrK7Ak65fs3VngPMoe9eg118DxRlsyWcOVQkSlZoRCFokXBmI4J4TVoOkMe3we6aAObJMXA6yXgJJc4ZcT0ewmNIFriIofNARVEWUtBqRcH0El8zi_5kZTwfjhxXe6kz6r8taXj_1erRaa6i57LC_Uhm_L6FouO1nINh1rsij62OSQtUhq-UPOiUSWi3RV5Y4yfauHR4HWcc-SKpaZtjueeXWn9-xek2yXQkO27isv118_gGwS9NZ";


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
        struct cg_time_t local_time; // t
        
    };


    const size_t sizeof_common = 284;
    const size_t common_index = 0;


#pragma pack(pop)

}




#endif //_FORTS_OPTCOMMON_REPL_H_


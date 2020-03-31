
#ifndef _FORTS_FUTTRADE_REPL_H_
#define _FORTS_FUTTRADE_REPL_H_



// Scheme "FORTS_FUTTRADE_REPL" description


namespace FORTS_FUTTRADE_REPL
{

#pragma pack(push, 4)

    static const char FORTS_FUTTRADE_REPL_scheme_string[] = "|STRING|XeNrtmE1vGjEQhu_9FYjLnkoCojQHIKpED1wjterN8q4HYtVeb20vhX9f70f2216SbEkicUTz7Lvj8fj1LMv7I2ejA0hFRbgaTye34xGEgSA03K_Gsd59vhvfrz8tVfAIHNZLjX0GoxBzWHlCEvMcYmLvrZc7CozkAQkR2268kT5F5he9827a8Qc4uIFvgbYDlCDzdntcgVKIlsC8JaBo6ASOmIs4dKSQA0iCcidKADOHjNJYx8oORJIG8BQm08XkS5PggkOZqe4Oo7B4R9x6B6GySGDaDOJAm96wx5P1of4sA0aTNExrFVzwtQmZXjL7spOCF8zstqUkeHXBHQQctXNzfSl-g0Ra2DMpECS16sWSjN0gwRoQHCPrNmUtPbU3AhOBKbRpF24XwSqSsKsvnIYEjnl8u_mFymOLthv0wxvFIf0TJ2oyBi_nO46zkbpJY07Jh-8_z9VMLKAiajZN4jwcK6OXrfSAWdxYffJQakR1P-Ix05TBHl2N6WpM5xuTTE5mP6b-4uhqcx_H5jrcYDC_69J-Q-N7BCy1D1hf3O5MtoekfSiH2mY1C1ZkONgWlIovL3xXLdVJITiYc6cuXsz0tdUD_fzbI5NIonaGGxG8L91p0Xl8yjoMtmUVyWH3LDk02W12-f5_7XXeew_nQOE5TtIkLBxXeiRU79zQN9sgPz71MgoYe9vJIRSm3TRw-3iQDzju9TxB7gVlF3FNaW5hakLz9p1PoCrTvmBToirShaSDQ03HOl7UtdrYDmoJkdliMutiqjKdUDbzuHPKmJ6M0gqYIeSMOiVUu1ZNXyrsYzCnKxX_g9EVw8dHdbwMQPIcxrczJDaTe_UD4OXe6vpiKxj_As7Y68GX_py5GvF7MeJ37p81VxrWSOvSr3fUm_zP7H_sQ8Si";


    struct orders_log
    {
        signed long long replID; // i8
        signed long long replRev; // i8
        signed long long replAct; // i8
        signed long long id_ord; // i8
        signed int sess_id; // i4
        signed int isin_id; // i4
        signed long long xamount; // i8
        signed long long xamount_rest; // i8
        signed long long id_deal; // i8
        signed long long xstatus; // i8
        char price[11]; // d16.5
        struct cg_time_t moment; // t
        unsigned long long moment_ns; // u8
        signed char dir; // i1
        signed char action; // i1
        char deal_price[11]; // d16.5
        char client_code[8]; // c7
        char login_from[21]; // c20
        char comment[21]; // c20
        signed int ext_id; // i4
        char broker_to[8]; // c7
        char broker_to_rts[8]; // c7
        char broker_from_rts[8]; // c7
        struct cg_time_t date_exp; // t
        signed long long id_ord1; // i8
        struct cg_time_t local_stamp; // t
        signed int aspref; // i4
        
    };


    const size_t sizeof_orders_log = 232;
    const size_t orders_log_index = 0;


    struct multileg_orders_log
    {
        signed long long replID; // i8
        signed long long replRev; // i8
        signed long long replAct; // i8
        signed long long id_ord; // i8
        signed int sess_id; // i4
        signed int isin_id; // i4
        signed long long xamount; // i8
        signed long long xamount_rest; // i8
        signed long long id_deal; // i8
        signed long long xstatus; // i8
        char price[11]; // d16.5
        struct cg_time_t moment; // t
        unsigned long long moment_ns; // u8
        signed char dir; // i1
        signed char action; // i1
        char deal_price[11]; // d16.5
        char rate_price[11]; // d16.5
        char swap_price[11]; // d16.5
        char client_code[8]; // c7
        char login_from[21]; // c20
        char comment[21]; // c20
        signed int ext_id; // i4
        char broker_to[8]; // c7
        char broker_to_rts[8]; // c7
        char broker_from_rts[8]; // c7
        struct cg_time_t date_exp; // t
        signed long long id_ord1; // i8
        struct cg_time_t local_stamp; // t
        signed int aspref; // i4
        
    };


    const size_t sizeof_multileg_orders_log = 256;
    const size_t multileg_orders_log_index = 1;


    struct heartbeat
    {
        signed long long replID; // i8
        signed long long replRev; // i8
        signed long long replAct; // i8
        struct cg_time_t server_time; // t
        
    };


    const size_t sizeof_heartbeat = 36;
    const size_t heartbeat_index = 2;


    struct sys_events
    {
        signed long long replID; // i8
        signed long long replRev; // i8
        signed long long replAct; // i8
        signed long long event_id; // i8
        signed int sess_id; // i4
        signed int event_type; // i4
        char message[65]; // c64
        
    };


    const size_t sizeof_sys_events = 108;
    const size_t sys_events_index = 3;


    struct user_deal
    {
        signed long long replID; // i8
        signed long long replRev; // i8
        signed long long replAct; // i8
        signed int sess_id; // i4
        signed int isin_id; // i4
        signed long long id_deal; // i8
        signed long long id_deal_multileg; // i8
        signed long long id_repo; // i8
        signed long long xpos; // i8
        signed long long xamount; // i8
        signed long long id_ord_buy; // i8
        signed long long id_ord_sell; // i8
        char price[11]; // d16.5
        struct cg_time_t moment; // t
        unsigned long long moment_ns; // u8
        signed char nosystem; // i1
        signed long long xstatus_buy; // i8
        signed long long xstatus_sell; // i8
        signed int ext_id_buy; // i4
        signed int ext_id_sell; // i4
        char code_buy[8]; // c7
        char code_sell[8]; // c7
        char comment_buy[21]; // c20
        char comment_sell[21]; // c20
        char fee_buy[15]; // d26.2
        char fee_sell[15]; // d26.2
        char login_buy[21]; // c20
        char login_sell[21]; // c20
        char code_rts_buy[8]; // c7
        char code_rts_sell[8]; // c7
        
    };


    const size_t sizeof_user_deal = 296;
    const size_t user_deal_index = 4;


    struct user_multileg_deal
    {
        signed long long replID; // i8
        signed long long replRev; // i8
        signed long long replAct; // i8
        signed int sess_id; // i4
        signed int isin_id; // i4
        signed int isin_id_rd; // i4
        signed int isin_id_rb; // i4
        signed int duration; // i4
        signed long long id_deal; // i8
        signed long long id_deal_rd; // i8
        signed long long id_deal_rb; // i8
        signed long long id_ord_buy; // i8
        signed long long id_ord_sell; // i8
        signed long long xamount; // i8
        char price[11]; // d16.5
        char rate_price[11]; // d16.5
        char swap_price[11]; // d16.5
        struct cg_time_t moment; // t
        unsigned long long moment_ns; // u8
        signed char nosystem; // i1
        signed long long xstatus_buy; // i8
        signed long long xstatus_sell; // i8
        signed int ext_id_buy; // i4
        signed int ext_id_sell; // i4
        char code_buy[8]; // c7
        char code_sell[8]; // c7
        char comment_buy[21]; // c20
        char comment_sell[21]; // c20
        char login_buy[21]; // c20
        char login_sell[21]; // c20
        char code_rts_buy[8]; // c7
        char code_rts_sell[8]; // c7
        
    };


    const size_t sizeof_user_multileg_deal = 288;
    const size_t user_multileg_deal_index = 5;


#pragma pack(pop)

}




#endif //_FORTS_FUTTRADE_REPL_H_


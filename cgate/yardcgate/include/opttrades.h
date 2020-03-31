
#ifndef _FORTS_OPTTRADE_REPL_H_
#define _FORTS_OPTTRADE_REPL_H_



// Scheme "FORTS_OPTTRADE_REPL" description


namespace FORTS_OPTTRADE_REPL
{

#pragma pack(push, 4)

    static const char FORTS_OPTTRADE_REPL_scheme_string[] = "|STRING|XeNrFl0uP2jAQx-_9FBGXnAoLonQPwKoSPXBdqVVvloknrFU7Tv2I4NvXeWzedna7iB7R_PL3vDxjtk8XzoIMpKIi2c2W84dZAEkkCE3Ou5nR8efH2dP-01ZFL8Bhv9X4xCBIMIddKCSx3yEmzuF-G1NgpDJISNnxEAb6mtpf9DFcDO3PkPmBb5F2A5Qge7rbrkApRBtgPRBQNPECF8yFSTwuVACSoPyOEsDMI6M01ka5gVTSCF7NZLmZf-kTXHBoPNXjZpTUZ5jBGYTK2oFl34gjbXvDbc_jQ9NeRozmbtjWqrnoax-yvWTrEkvBa2b1MFASvB3wCAEX7S3uSYrfIJEWbk9qBEmtJrHcYz9IsAYEl9RZprKll-5GYCKyibbtwt0iWKUS4m7gNCFwqezHwy_UXFt0PKAfYWAS-sfkatJAWPEj19lKLQqbV_L5-8-3auYjoCVqiyZxZTbK6pWRZpiZXvT5R8Ug6s6jF8BSnwDru48j622WNwvl0ClNP0-1hzfLfKP474kfy6W6KgSZvWXq7sksjm1f3_dP91Iit7oZbkXwuZlFm9HL0uThZiVrSd62ZvmlKbfN_fv_o-t2ck9WAOKGacrg7NmoqVCTa3vqaYFO5jrJKGDs_y7uRNhu0sDd27l6X_jjeYX8AZVbtaO0djAdofVwgRNoywy3ZUG0RcaQ4hXQ0XG-FbpaQyyGjkNktZmvxpi2zChUPmD8PpXMhEdFBuyL4g15yqlhrvpjp54ONxtkjeLH59ii-oPxF2AmPos=";


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


    struct heartbeat
    {
        signed long long replID; // i8
        signed long long replRev; // i8
        signed long long replAct; // i8
        struct cg_time_t server_time; // t
        
    };


    const size_t sizeof_heartbeat = 36;
    const size_t heartbeat_index = 1;


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
    const size_t sys_events_index = 2;


    struct user_deal
    {
        signed long long replID; // i8
        signed long long replRev; // i8
        signed long long replAct; // i8
        signed int sess_id; // i4
        signed int isin_id; // i4
        signed long long id_deal; // i8
        signed long long id_deal_multileg; // i8
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


    const size_t sizeof_user_deal = 288;
    const size_t user_deal_index = 3;


#pragma pack(pop)

}




#endif //_FORTS_OPTTRADE_REPL_H_


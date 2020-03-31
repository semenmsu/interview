
#ifndef _FORTS_PART_REPL_H_
#define _FORTS_PART_REPL_H_



// Scheme "FORTS_PART_REPL" description


namespace FORTS_PART_REPL
{

#pragma pack(push, 4)

    static const char FORTS_PART_REPL_scheme_string[] = "|STRING|XeNq9lTtvwjAUhff-iihLppKCWtqBhyrRgRWpVbcrY99Qq36kfkTw7-tEFAKENGoRo-1Px77X59ij6VqKqEBjuVbjuN-7iyNUVDOuVuPYu-z2KZ5ObkaWfqDEyciRpcBIEYnjJCfGJZNRxlGw7ZTBXMxnSeQ2eRjxpyQ9XV9g0Q48U3ceoIKjchBOiD8QfTyGpFa4gczgjmGDYW_QjC2Fpp_IWslCgkGLpmgXzH7ZcEkEURSh2riVpBqzDFZ6B_WHvYdjSHDJnQWL-371m2vUgnXoBJHaK9cBzAWyFXbhQ-O4cmioaMW4BeKdBp8z4hCqws7XpDRk3gHjltYP0AB6CVQYGDAUPJh813N-X6JcMVxv0fnsHUpDw3wGr0nkFf_yYdoZj8mWbDB6EEmrtTNii5e3rmplLGpyaZW008CBJVfPXDCYEyH-IXeEHrSc9gdXMdwFo_wHB3eJfkejN70Qjc6x5LJODHqXNaPdWMAieMJe3Y_VtlCuHub5lOGszdXW1oETCRkAstp_M8PGR2Pfh4tdWE3y_3eWbr_ub8BAqf0=";


    struct part
    {
        signed long long replID; // i8
        signed long long replRev; // i8
        signed long long replAct; // i8
        char client_code[8]; // c7
        char money_free[15]; // d26.2
        char money_blocked[15]; // d26.2
        char vm_reserve[15]; // d26.2
        char fee[15]; // d26.2
        char balance_money[15]; // d26.2
        char coeff_go[11]; // d16.5
        signed char limits_set; // i1
        char money_old[15]; // d26.2
        char money_amount[15]; // d26.2
        char money_pledge_amount[15]; // d26.2
        char vm_intercl[15]; // d26.2
        signed char is_auto_update_limit; // i1
        signed char no_fut_discount; // i1
        signed int num_clr_2delivery; // i4
        
    };


    const size_t sizeof_part = 188;
    const size_t part_index = 0;


    struct part_sa
    {
        signed long long replID; // i8
        signed long long replRev; // i8
        signed long long replAct; // i8
        char settlement_account[13]; // c12
        char money_old[15]; // d26.2
        char money_amount[15]; // d26.2
        char money_free[15]; // d26.2
        char money_blocked[15]; // d26.2
        char money_pledge_amount[15]; // d26.2
        char vm_reserve[15]; // d26.2
        char vm_intercl[15]; // d26.2
        char fee[15]; // d26.2
        
    };


    const size_t sizeof_part_sa = 160;
    const size_t part_sa_index = 1;


    struct sys_events
    {
        signed long long replID; // i8
        signed long long replRev; // i8
        signed long long replAct; // i8
        signed int event_type; // i4
        signed long long event_id; // i8
        signed int sess_id; // i4
        char message[65]; // c64
        
    };


    const size_t sizeof_sys_events = 108;
    const size_t sys_events_index = 2;


#pragma pack(pop)

}




#endif //_FORTS_PART_REPL_H_



#ifndef _FORTS_OPTINFO_REPL_H_
#define _FORTS_OPTINFO_REPL_H_



// Scheme "FORTS_OPTINFO_REPL" description


namespace FORTS_OPTINFO_REPL
{

#pragma pack(push, 4)

    static const char FORTS_OPTINFO_REPL_scheme_string[] = "|STRING|XeNrFVU1vgkAQvfdXEC6cKrW11gNqmtiDV5M2vW1wd8RNYZfuzhL99wVEJHypqWkvJOS9ffuYeTN4810UWgkozaWY2sPBg22BoJJxEUxtg5v7iT2f3XmabiGCmYf-OgRL-BFMHRkj0aA1oVIgCNTOzNtwCFmBK4jD5cKxcB-nb3ziuE18BUk_4ZViNyG_nbOSMKoTuObiLOGI0sfnxgVbqZCcIWXPEn5pwBtzUOj1AUbJuFThwzoeG-wGNSr-VR5mw_GgYUJJIxjKbgNRalAjxL0qoUSSyNCcvrcplImQWHHab4gR2AElawiONOyggGCdFM0DoXu8AGKY5lZghyMuGOwK8nLxSRqRJssFeXcsI_i3yQwoA05xrCXqqaKbY5cor94-LpXOpqSi7eZT2BzGhK7_fATPhD_vYIaWnEZ6qVGqRJ_qKCqfATmsn24N5SP0ztfa15CXXvkUr2CmmxBqo9_W2bTyN01KpnfbfOi9JpD8y5bOr63W_Po9fpCo5qhlg6UifnDq1njU1q1THW7WsIrk73vmFn_aH16wkbc=";


    struct opt_sess_contents
    {
        signed long long replID; // i8
        signed long long replRev; // i8
        signed long long replAct; // i8
        signed int sess_id; // i4
        signed int isin_id; // i4
        char isin[26]; // c25
        char short_isin[26]; // c25
        char name[76]; // c75
        signed int fut_isin_id; // i4
        signed char europe; // i1
        signed char put; // i1
        char strike[11]; // d16.5
        signed int roundto; // i4
        char min_step[11]; // d16.5
        signed int lot_volume; // i4
        char step_price[11]; // d16.5
        struct cg_time_t d_exec_beg; // t
        struct cg_time_t d_exec_end; // t
        signed int signs; // i4
        char settlement_price[11]; // d16.5
        
    };


    const size_t sizeof_opt_sess_contents = 248;
    const size_t opt_sess_contents_index = 0;


    struct opt_vcb
    {
        signed long long replID; // i8
        signed long long replRev; // i8
        signed long long replAct; // i8
        char name[76]; // c75
        char exec_type[2]; // c1
        char curr[4]; // c3
        char trade_scheme[2]; // c1
        signed int rate_id; // i4
        signed int base_contract_id; // i4
        char base_contract_code[26]; // c25
        
    };


    const size_t sizeof_opt_vcb = 144;
    const size_t opt_vcb_index = 1;


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


#pragma pack(pop)

}




#endif //_FORTS_OPTINFO_REPL_H_



#ifndef _FORTS_OPTINFO_REPL_H_
#define _FORTS_OPTINFO_REPL_H_



// Scheme "FORTS_OPTINFO_REPL" description


namespace FORTS_OPTINFO_REPL
{

#pragma pack(push, 4)

    static const char FORTS_OPTINFO_REPL_scheme_string[] = "|STRING|XeNrFWMlu2zAQvfcrjFx8ahy7bZKDkyCtc8g1RYveCJoaO2y4KFwM--87khfJpkipiJBcDBjz9MjZHoec3q2lGKzAWK7Vzdn4_OJsAIrpjKvlzZl3i8_XZ3e3n6aWPYOE26mjcwEDRSXcDHXuiAVrCdPKgXJ2eDtdcBDZzm4gF4-z4cBtcvzHr4ej0P4EqzTgnrk4oFydZwfA11MAt1y1AvZWNvkWLPCsjSMtoOL3YL4KzBhMICs2TzAs_HaR5Fa1yMiLdtzsIdn48jygmi81YXXEpAmh0hDwRucHn_j41J57FzdaZ_gLJDdptFeZ03FfJcbCOsiTLEI7stLCV9EPiQoSkhvO0hvKSL7cA1xohDUwModWCKgsCrF8qWx8o4JaR5ggr147aM3w3G_SOaYWOlRU7rDrsYcNh3QfZZgNalzUuXK9QgYMZegGVnyqqcA5gWqi3DYzBGtNpV0u3ZFIjEoFuBkQooP_sh1Yhh13jS2a0SrwLkbYFvhT3wK3uMpgvQM_zv6QQETJ44z8Gg684q--2InxMNx91iCuyDgqbV2Ynx5-d6UudLnGPSp1P5T_QtbeW_Q76GmLIpe9WlgPmEDEmDcHnWVfTq3bgtmeiXEOgwWV7KrjrumObOivpuRjjHotpoKv_xIy8BeYw6bWJsMx5N3LqVy2Hvz_nzKkLho-qh2tOswELwTjKK1XgQRXB3945q6pxCM14WWHI7CoVljncTfKFI3ja2zDsEtolMbAsadhOAqExJjTZb3KG-YqWQ87m1yEA8ISI78wWiZAsA5br6n6T-q018465e6_yzgeAQbHC64W-t1brJ8GWMm9F8EJ3BTTuse9JuuIuP9MYQt-lBTi0u1q2ClXrRlvFaxW0U2Oazt6QvNcbI4XaUppFfNeK6VG23udVIP7B9y6W-8LeL0DIzZcLXsagDCUHOepwutk4ms4qhje3tPwjG4scZpUn8W3sAFqIuBFJETpGdNKKgQ5mlXDUfb-IHaTi_NxYP6eNv9Im2dp80Pa_DNt3r4DtF_jPdaA8hgJvMvT1LuCnxPD7UscURIQWT3WNG9sB6PrDjAuuNscLbtI4CTHnDr2nP6g4SWgQT1qN_MeNanG2q8kWWwkWH3IK2C57Nsm-C1FvV0bpvyTkfSyMXNVHHpLW43y7Tkb7V5y_wGWPW1D";


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
        char code_vcb[26]; // c25
        signed int fut_isin_id; // i4
        char old_kotir[11]; // d16.5
        char bgo_c[10]; // d16.2
        char bgo_nc[10]; // d16.2
        signed char europe; // i1
        signed char put; // i1
        char strike[11]; // d16.5
        signed int roundto; // i4
        char min_step[11]; // d16.5
        signed int lot_volume; // i4
        char step_price[11]; // d16.5
        struct cg_time_t d_pg; // t
        struct cg_time_t d_exec_beg; // t
        struct cg_time_t d_exec_end; // t
        signed int signs; // i4
        char last_cl_quote[11]; // d16.5
        char bgo_buy[10]; // d16.2
        signed int base_isin_id; // i4
        signed int option_series_id; // i4
        struct cg_time_t d_start; // t
        char base_contract_code[26]; // c25
        char settlement_price_open[11]; // d16.5
        char base_im_covered_sell[10]; // d16.2
        char base_im_sell[10]; // d16.2
        struct cg_time_t last_trade_date; // t
        char base_im_buy[10]; // d16.2
        char settlement_price[11]; // d16.5
        
    };


    const size_t sizeof_opt_sess_contents = 436;
    const size_t opt_sess_contents_index = 0;


    struct opt_vcb
    {
        signed long long replID; // i8
        signed long long replRev; // i8
        signed long long replAct; // i8
        char code_vcb[26]; // c25
        char name[76]; // c75
        char exec_type[2]; // c1
        char curr[4]; // c3
        char trade_scheme[2]; // c1
        signed int rate_id; // i4
        signed int base_contract_id; // i4
        char base_contract_code[26]; // c25
        
    };


    const size_t sizeof_opt_vcb = 172;
    const size_t opt_vcb_index = 1;


    struct opt_rejected_orders
    {
        signed long long replID; // i8
        signed long long replRev; // i8
        signed long long replAct; // i8
        signed long long order_id; // i8
        signed int sess_id; // i4
        struct cg_time_t moment; // t
        signed int isin_id; // i4
        char client_code[8]; // c7
        signed char dir; // i1
        signed long long xamount; // i8
        char price[11]; // d16.5
        struct cg_time_t date_exp; // t
        signed long long id_ord1; // i8
        struct cg_time_t moment_reject; // t
        signed int ret_code; // i4
        char ret_message[256]; // c255
        char comment[21]; // c20
        char login_from[21]; // c20
        signed int ext_id; // i4
        
    };


    const size_t sizeof_opt_rejected_orders = 424;
    const size_t opt_rejected_orders_index = 2;


    struct opt_intercl_info
    {
        signed long long replID; // i8
        signed long long replRev; // i8
        signed long long replAct; // i8
        signed int isin_id; // i4
        char client_code[8]; // c7
        char vm_intercl[10]; // d16.2
        
    };


    const size_t sizeof_opt_intercl_info = 48;
    const size_t opt_intercl_info_index = 3;


    struct opt_exp_orders
    {
        signed long long replID; // i8
        signed long long replRev; // i8
        signed long long replAct; // i8
        signed long long exporder_id; // i8
        char client_code[8]; // c7
        signed int isin_id; // i4
        signed long long xamount; // i8
        signed int sess_id; // i4
        struct cg_time_t date; // t
        signed long long xamount_apply; // i8
        
    };


    const size_t sizeof_opt_exp_orders = 76;
    const size_t opt_exp_orders_index = 4;


    struct option_series
    {
        signed long long replID; // i8
        signed long long replRev; // i8
        signed long long replAct; // i8
        signed int series_id; // i4
        signed int underlying_id; // i4
        signed int base_contract_id; // i4
        struct cg_time_t expiration_date; // t
        struct cg_time_t expiration_anchor_date; // t
        signed int days_to_expiration; // i4
        double years_to_expiration; // f
        char series_type[2]; // c1
        char small_name[26]; // c25
        char A[13]; // d20.15
        char B[13]; // d20.15
        char C[13]; // d20.15
        char D[13]; // d20.15
        char E[13]; // d20.15
        char S[13]; // d20.15
        char strike_step[11]; // d16.5
        signed char use_null_volat; // i1
        signed char sub_risk; // i1
        char volat_min[13]; // d20.15
        char volat_max[13]; // d20.15
        double volatility_risk; // f
        double volatility_mismatch_risk; // f
        signed int signs; // i4
        
    };


    const size_t sizeof_option_series = 236;
    const size_t option_series_index = 5;


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
    const size_t sys_events_index = 6;


#pragma pack(pop)

}




#endif //_FORTS_OPTINFO_REPL_H_



#ifndef _FORTS_OPTINFO_REPL_H_
#define _FORTS_OPTINFO_REPL_H_



// Scheme "FORTS_OPTINFO_REPL" description


namespace FORTS_OPTINFO_REPL
{

#pragma pack(push, 4)

    static const char FORTS_OPTINFO_REPL_scheme_string[] = "|STRING|XeNrFWMlu2zAQvfcrDF98ahy7zXJwEqR1DrmmaNEbQVNjhw1FKlwM--87khdJpkipjZBcDBjz9MjZHoec3W1SMViDNlzJm-Hk7Hw4AMlUwuXqZujs8vP18O7208ywZ0jhdmbpQsBA0hRuRiqzxIAxhClpQVozup0tOYhkb9eQicf5aGC3Gf7j16Oxb3-CdRxwz2wYUKzOkyPg6ymAGy5bAQcrm154CzwrbUkLKP89mq8889LtGKL7UCIhL8pyfYAkk8szj2qxUoRVEdMmhIxDwGmVHTfMJ6f2zNmw0VjNXyC6Sa2cTKwK-5piLIyFLMoilCVrJVwZWp8oJyGZ5iy-oYRkqwPA-kbYACMLaIWATIIQw1fShDcqqLGECfLqlIXWDC_cNp5jaqBDRWUWWxobVHOIN0mC2aDaBp0r1st7XFOGbqgEYh0D1gqUCml3mSFYazLucuFOisQoQ4CbASE6-J-2A4uw464TIAktA29DhG2BP_XNc4vLBDZ78OP8N_EUkjzOyc_RwEn-6vKdaAej_WcNyomM48LWhfnp4VdX6lx0K9zjQtR9bV-zxbsrel5dxcL_LbdFr-bWI8YTMeb0UWfZl1PrrmB2B16YQ2NBRbuq3jXdkQ391ZR8jFGvxZTz9V9CGv4As9jUSic4Y7x7ORXLVoP_7yNEqvKGD2pHqw4zwXPBqKX1ypPg8uD3z9wNTfFIjXjZ4QjMqxU2WdiNIkWT8Bq7MOwTGqTRUPfUD0eOSDHmdFWt8gtfB9Jq2Nn03B8QVhj5pVZpBAQbv_Waqv-kTnvtrFPu_ruM4xGgcbzgcqnevcX6aYB1evDCO4GbYlr1uNdk1Yj7zxS24EdJIS7droadctWa8VbBahXd6Li2pyc0y8S2vkhTSsuY91opFdre66Qc3D_gSt16X8DrHWix5XLV0wCEoeQ4T-VeRxNfwVHJ8Goehyd0a4hVpPwsvIUtUB0ALwMhis-YJqVCkNqs6o-y90exm56fTTzzt7j5e9w8j5sf4uYfcfPuHaD9Gu-wBqTDSOBdnsbeFdyCaG5ewoiCgKTlS0zzxvYwuukA44LbbW3ZZQSXcsypZc_xDxpeAhrUo3Iz71GTKqz9SpLBRoL1hzzxFcu-bYLfUVTbtWHKPxlJLxszV8aht7RVKN-es_H-mfYvn-9h3g==";


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


    const size_t sizeof_opt_sess_contents = 408;
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


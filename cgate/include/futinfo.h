
#ifndef _FORTS_FUTINFO_REPL_H_
#define _FORTS_FUTINFO_REPL_H_



// Scheme "FORTS_FUTINFO_REPL" description


namespace FORTS_FUTINFO_REPL
{

#pragma pack(push, 4)

    static const char FORTS_FUTINFO_REPL_scheme_string[] = "|STRING|XeNrtWM9v2jAUvu-vQFw4rYyq7XoAqknswLXSpt2sYD9Sa46d2s-s_PezUwgpSV5Ay9pV2gWR-Mv3nt-P7zmZ3j1larAB66TRs-Hk4tNwAJobIXU6G3pcf7wd3s0_TB1_gAzmU0xWCgY6yWA2sgmCG82nawlK7O9BrpaL0QC3ebiSt6Nxff0eNjTgC0cCEKwyKUrA1TGAe2vZKnGwh_DJdSOGG58rEATMJkJ6tweIyc1FAZFawNMOslz8YEUg2HLBvo0GXstHH-6j9TDaQRsCFFjGxVob2_3X76fSxXhW-MZFjl6mau2ROXAu7FkjaHz9tBXWqbRJJzUJcA_GIouwMmOX100sxHL8LZc_15_WDhmCzdq9UDKTyHxeK4o6SJhfmoSt_JYJyI2TWMVd1mOn1ElAa7wWaNq9z0KMHUKH9wbZxih_CFVDMgIJy63kQFJJx1xuITmkdXIMEQye8uBUYsu9YQNNDpaHwm3n2QGK9il9agqmTLWjypBhaHtgsAEdRLDdIEr-EywVooonDanwCqWClEUAUW-QOvaI21NSwbiyZDoqUBl0wJ6Bj4pJYkVHDnOO23gZJAjWa5KqhKLBRHVYjdUDWrTajZOgkD2bcAx_BBD64ABRhUEX6uh52yYHuoePn6A7K4n6UpSXqBQHNg2VmmT3NmDqzP0Pm6ik1mdvMmreySR5j2L9ikL8Xx_70Me_rH6UoJ075M9SUgdWhlNytTb4pE1GK2LUq4hWefuV0CjP4YXs3zulryA9yGIthdQc7jgOmXw3lMh3hNiUoYsZ7UYJo_wpQR2OhXMgM7pd7uJ6R1QCgvIkM5q0ENdpCxFBWQhvDrFLtVuHLdNUL6DHnMdNsCvT3ppqz9dzM21dcZp_g6NIYbZa0ud33DMFPQSzQJKkByW8uWrMVhmH_hJ2oPzznI13H5l-A7_vS_s=";


    struct rates
    {
        signed long long replID; // i8
        signed long long replRev; // i8
        signed long long replAct; // i8
        signed int rate_id; // i4
        char curr_base[16]; // c15
        char curr_coupled[16]; // c15
        char radius[11]; // d16.5
        
    };


    const size_t sizeof_rates = 72;
    const size_t rates_index = 0;


    struct fut_sess_contents
    {
        signed long long replID; // i8
        signed long long replRev; // i8
        signed long long replAct; // i8
        signed int sess_id; // i4
        signed int isin_id; // i4
        char short_isin[26]; // c25
        char isin[26]; // c25
        char name[76]; // c75
        signed int inst_term; // i4
        char limit_up[11]; // d16.5
        char limit_down[11]; // d16.5
        char buy_deposit[10]; // d16.2
        char sell_deposit[10]; // d16.2
        signed int roundto; // i4
        char min_step[11]; // d16.5
        signed int lot_volume; // i4
        char step_price[11]; // d16.5
        signed char is_spread; // i1
        struct cg_time_t d_exp_start; // t
        signed char is_percent; // i1
        char percent_rate[5]; // d6.2
        signed int signs; // i4
        signed char is_trade_evening; // i1
        signed int ticker; // i4
        signed int state; // i4
        signed int multileg_type; // i4
        signed int legs_qty; // i4
        char step_price_clr[11]; // d16.5
        char step_price_interclr[11]; // d16.5
        char step_price_curr[11]; // d16.5
        struct cg_time_t d_start; // t
        char pctyield_coeff[11]; // d16.5
        char pctyield_total[11]; // d16.5
        struct cg_time_t d_exp_end; // t
        char base_contract_code[26]; // c25
        char settlement_price_open[11]; // d16.5
        char settlement_price[11]; // d16.5
        struct cg_time_t last_trade_date; // t
        
    };


    const size_t sizeof_fut_sess_contents = 416;
    const size_t fut_sess_contents_index = 1;


    struct fut_instruments
    {
        signed long long replID; // i8
        signed long long replRev; // i8
        signed long long replAct; // i8
        signed int isin_id; // i4
        char short_isin[26]; // c25
        char isin[26]; // c25
        char name[76]; // c75
        signed int inst_term; // i4
        signed int roundto; // i4
        char min_step[11]; // d16.5
        signed int lot_volume; // i4
        char step_price[11]; // d16.5
        signed char is_spread; // i1
        signed char is_percent; // i1
        char percent_rate[5]; // d6.2
        signed int signs; // i4
        signed int multileg_type; // i4
        signed int legs_qty; // i4
        char step_price_clr[11]; // d16.5
        char step_price_interclr[11]; // d16.5
        char step_price_curr[11]; // d16.5
        struct cg_time_t d_start; // t
        char pctyield_coeff[11]; // d16.5
        char pctyield_total[11]; // d16.5
        char base_contract_code[26]; // c25
        char settlement_price_open[11]; // d16.5
        struct cg_time_t last_trade_date; // t
        struct cg_time_t d_exp_start; // t
        char settlement_price[11]; // d16.5
        char series_type[2]; // c1
        
    };


    const size_t sizeof_fut_instruments = 352;
    const size_t fut_instruments_index = 2;


    struct session
    {
        signed long long replID; // i8
        signed long long replRev; // i8
        signed long long replAct; // i8
        signed int sess_id; // i4
        struct cg_time_t begin; // t
        struct cg_time_t end; // t
        signed int state; // i4
        signed int opt_sess_id; // i4
        struct cg_time_t inter_cl_begin; // t
        struct cg_time_t inter_cl_end; // t
        signed int inter_cl_state; // i4
        signed char eve_on; // i1
        struct cg_time_t eve_begin; // t
        struct cg_time_t eve_end; // t
        signed char mon_on; // i1
        struct cg_time_t mon_begin; // t
        struct cg_time_t mon_end; // t
        struct cg_time_t pos_transfer_begin; // t
        struct cg_time_t pos_transfer_end; // t
        
    };


    const size_t sizeof_session = 144;
    const size_t session_index = 3;


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
    const size_t sys_events_index = 4;


#pragma pack(pop)

}




#endif //_FORTS_FUTINFO_REPL_H_


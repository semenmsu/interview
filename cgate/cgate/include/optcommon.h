
#ifndef _FORTS_OPTCOMMON_REPL_H_
#define _FORTS_OPTCOMMON_REPL_H_



// Scheme "FORTS_OPTCOMMON_REPL" description


namespace FORTS_OPTCOMMON_REPL
{

#pragma pack(push, 4)

    static const char FORTS_OPTCOMMON_REPL_scheme_string[] = "|STRING|XeNqNlMFvwiAUxu_7K5peeppOsxkPVbPEHbyabNmNIDw3MuBVoKb-92trdboKciLALx_f4718-aJSMtmDsQL1LB0NntIENEMu9NcsLd32cZou5g-5Zd-gYJ47upGQaKpgljFUCnU2z7cCJO8ODRRytcwSdyjqnZhmw_79GvZh4JU5P2DBWiL4GXj-DwgrdBDYgHVkUx5OBB9NBi__oYoqLPUV1_eChtdf1zBk5w7-F6sL8Kjr12zdWZAyyt4l6PXXQHEGW_KeQyxAk8IIBkGLTKKFCO4-4QxoHvMdfs8cqCROqPNDzksQbU9Q2dNRIqZ0RasIiu5NBFUx1M4QFq6P0UI4-jcz48lgfLPCa53eIKDk5AedMEFPFpyTdSDUA9gWQJqRCFdRoPW7V8jDzTkBwd5IZLeaLDSHqkNWy09yzC2yWpL3LCm12JXtiJWQdeyNPKtlhu2dV2799hGr1-TfheCwDdV67UL2FxRF37Q=";


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
        struct cg_time_t local_time; // t
        
    };


    const size_t sizeof_common = 296;
    const size_t common_index = 0;


#pragma pack(pop)

}




#endif //_FORTS_OPTCOMMON_REPL_H_


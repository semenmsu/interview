
#ifndef _MCXCC_MDCOMMON_REPL_H_
#define _MCXCC_MDCOMMON_REPL_H_



// Scheme "MCXCC_MDCOMMON_REPL" description


namespace MCXCC_MDCOMMON_REPL
{

#pragma pack(push, 4)

    static const char MCXCC_MDCOMMON_REPL_scheme_string[] = "|STRING|XeNqVlUtzgjAQgO_9FYwXTtXqdBwPPiaSVZgCQQjanhwLsWVG0So49t8XKMUnCT0xsF82X7JL0h0c1yvpwHb7YBP2as36U01iobfxg_CjV4uj5WOnNug_dPfeJ1uzfjdavK-YFC7WrCcrxDCIKfe7y4Ct_Pzjjm1XGpal6HubvAUduXEbt9mBDyAvKgccUIYE2cUc3vMdQiEYCqDZuiaGJ0W_2a6378QxWFQtt_gjaDliukZCOQVw40lGI7C5HhkhMDkxfJeM49lYYHJlVG2scgGdzPhx5FAhYMKYyygqMsfARSb0rXwnqGYUo6Pr4JTolGDEGT5FFQj3wu-m-2bIsjUFhJst6tJkv8UtlFSe2ggDp_KZjaGZrmPZMK1ip-jEATGW1lO4iIQRryKlHKBUB9GfjaqIGch-Afov7qLqd-FKfmcZW9xsCBsapYAnLqFQYV6MKDRLG_vEtC6YIPTZMWc0_Dr_PdPnGp67shSHwVeckruYyTl756xP0jSyWGm6pKuq5kvvhrOEjezCSZ75BfQDuoULNw==";


    struct COMMON
    {
        signed long long replID; // i8
        signed long long replRev; // i8
        signed long long replAct; // i8
        char SECBOARD[5]; // c4
        char SECCODE[13]; // c12
        char BID[10]; // d16.6
        signed long long BIDDEPTH; // i8
        signed long long BIDDEPTHT; // i8
        signed int NUMBIDS; // i4
        char OFFER[10]; // d16.6
        signed long long OFFERDEPTH; // i8
        signed long long OFFERDEPTHT; // i8
        signed int NUMOFFERS; // i4
        char OPEN[10]; // d16.6
        char HIGH[10]; // d16.6
        char LOW[10]; // d16.6
        char LAST[10]; // d16.6
        char LASTNEG[10]; // d16.6
        char CHANGE[10]; // d16.6
        signed long long QTY; // i8
        struct cg_time_t TIME; // t
        signed long long VOLTODAY; // i8
        signed long long VALTODAY; // i8
        char VALUE[10]; // d16.2
        char WAPRICE[10]; // d16.6
        char HIGHBID[10]; // d16.6
        char LOWOFFER[10]; // d16.6
        signed int NUMTRADES; // i4
        char PRICEMINUSPREVWAPRICE[10]; // d16.6
        char CLOSEPRICE[10]; // d16.6
        char LASTBID[10]; // d16.6
        char LASTOFFER[10]; // d16.6
        char LASTSETTLECODE[13]; // c12
        char BASEPRICE[10]; // d16.6
        char MARKETPRICE[10]; // d16.6
        char MARKETPRICETODAY[10]; // d16.6
        char SETTLECODE[13]; // c12
        char MARKETPRICE2[10]; // d16.6
        char ADMITTEDQUOTE[10]; // d16.6
        struct cg_time_t SETTLEDATE1; // t
        struct cg_time_t SETTLEDATE2; // t
        
    };


    const size_t sizeof_COMMON = 380;
    const size_t COMMON_index = 0;


#pragma pack(pop)

}




#endif //_MCXCC_MDCOMMON_REPL_H_


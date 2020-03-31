
#ifndef _FORTS_POS_REPL_H_
#define _FORTS_POS_REPL_H_



// Scheme "FORTS_POS_REPL" description


namespace FORTS_POS_REPL
{

#pragma pack(push, 4)

    static const char FORTS_POS_REPL_scheme_string[] = "|STRING|XeNrtlUFPgzAUx-9-CsKFk0PIxB0YiwkeuC7ReGu68jablMJ4LbJvb4eMTbYxExfjwSO8H__X9v0awlmdCauCEnkup7Y3urMtkCxPuVxNba2WtxN7Ft2EyN4ggyhUdCHAkjSDqVPkyJX5zInCJQeRtq9LKEQSO5baFOaJTxz3uD6Hahh4ZOo8wAQHqYhZJewg9tCHOHJJeNqljPtAbdZ_vke90Bska7UZQBCEuMTkBchh5J0WJWfdTlIvGN33GQmKVLnQGZBSlx3qByO_jwqKiqRAxeHmj5pSxnJtznBb7yhvS3GZQt1SSfxKdlMmSUyeHUtLvtampEoNTkufmL4JcpvaQOD86eW7iVtfDiLdRsPTNhKkf0JIz_838pKRZ9VAen3dTOZ1jUMzDqjM4PHXhWvaDl5wBMRB2T4jvtz_IyYzIXS1dzoYn5ra_hyuNrSDyJ_PzG1_Xh9En1my";


    struct position
    {
        signed long long replID; // i8
        signed long long replRev; // i8
        signed long long replAct; // i8
        char client_code[8]; // c7
        signed int isin_id; // i4
        signed long long xpos; // i8
        signed long long xbuys_qty; // i8
        signed long long xsells_qty; // i8
        signed long long xopen_qty; // i8
        char waprice[11]; // d16.5
        char net_volume_rur[15]; // d26.2
        signed long long last_deal_id; // i8
        signed char account_type; // i1
        
    };


    const size_t sizeof_position = 108;
    const size_t position_index = 0;


    struct position_sa
    {
        signed long long replID; // i8
        signed long long replRev; // i8
        signed long long replAct; // i8
        char client_code[13]; // c12
        signed int isin_id; // i4
        signed long long xpos; // i8
        signed long long xbuys_qty; // i8
        signed long long xsells_qty; // i8
        signed long long xopen_qty; // i8
        char waprice[11]; // d16.5
        char net_volume_rur[15]; // d26.2
        signed long long last_deal_id; // i8
        
    };


    const size_t sizeof_position_sa = 112;
    const size_t position_sa_index = 1;


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




#endif //_FORTS_POS_REPL_H_


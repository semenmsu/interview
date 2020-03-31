
#ifndef _MOEX_RATES_REPL_H_
#define _MOEX_RATES_REPL_H_



// Scheme "MOEX_RATES_REPL" description


namespace MOEX_RATES_REPL
{

#pragma pack(push, 4)

    static const char MOEX_RATES_REPL_scheme_string[] = "|STRING|XeNqNkUELgjAYhu_9iuFlp7SgwoMagR28BkW3Ye6zBtunzU3q36diIhXSaYzn2Tve7wu2DyVJDboSBYbO0l04BDAruMBr6FiTz31nG82CKruBgigw6UUCwVRBSDOrNStQCgQaBbkAyXuioZRJTIl5ls1N-NT75geop4VdZiaE1AATfBBWn0KdSgtvzJcbd_1pqEIBDl-YFgvk8OhxEp_ZqCFLYnakxKK421bXti3dPfjRvMnyOjadedif_g1txzVK9bpFNGe_mBf9nJo0";


    struct curr_online
    {
        signed long long replID; // i8
        signed long long replRev; // i8
        signed long long replAct; // i8
        signed int rate_id; // i4
        char value[11]; // d16.5
        struct cg_time_t moment; // t
        
    };


    const size_t sizeof_curr_online = 52;
    const size_t curr_online_index = 0;


#pragma pack(pop)

}




#endif //_MOEX_RATES_REPL_H_


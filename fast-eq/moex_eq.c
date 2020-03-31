#include <stdio.h>
#include <string.h>
#include "moex_eq.h"
#include "utils.h"

int moex_eq_parse_template_X_MSR_FOND(unsigned char *packet, int *offset, unsigned char *pmap, struct moex_eq__X_MSR_FOND *t)
{
    t->pmap = pmap;

    //nopmap_string_nonullable_constant MessageType
    //strcpy(t->MessageType, "X");

    //nopmap_string_nonullable_constant ApplVerID
    //strcpy(t->ApplVerID, "9");

    //nopmap_string_nonullable_constant BeginString
    //strcpy(t->BeginString, "FIXT.1.1");

    //nopmap_string_nonullable_constant SenderCompID
    //strcpy(t->SenderCompID, "MOEX");

    //nopmap_uint32_nonullable_noop MsgSeqNum
#ifdef DEBUG2
    int t_MsgSeqNum_start = *offset;
#endif

    //>>> MsgSeqNum
    t->MsgSeqNum = 0;
    while (!((packet[*offset] & 0x80)))
    {
        t->MsgSeqNum |= packet[(*offset)++];
        t->MsgSeqNum <<= 7;
    }
    t->MsgSeqNum |= (packet[(*offset)++] & 0x7f);
    //<<<

#ifdef DEBUG
    printf("t->MsgSeqNum = %u\n", t->MsgSeqNum);
#endif

#ifdef DEBUG1
    printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
    printf("name = %sMsgSeqNum%s\n", KRED, RESET_COLOR);
    printf("type = %snopmap_uint32_nonullable_noop\n%s", KBLU, RESET_COLOR);
    printf("byte_representation: ");
    printf("%s", COLOR_BYTES);
    for (int i = t_MsgSeqNum_start; i < *offset; i++)
    {
        printf("%02x ", packet[i]);
    }
    printf("%s\n", RESET_COLOR);
    printf("value = %s%u%s\n", KMAG, t->MsgSeqNum, RESET_COLOR);
    printf("\n");
#endif

#ifdef DEBUG3
    getchar();
#endif

    //nopmap_uint64_nonullable_noop SendingTime
#ifdef DEBUG2
    int t_SendingTime_start = *offset;
#endif

    //>>> SendingTime
    t->SendingTime = 0;
    while (!((packet[*offset] & 0x80)))
    {
        (t->SendingTime) |= packet[(*offset)++];
        (t->SendingTime) <<= 7;
    }
    (t->SendingTime) |= (packet[(*offset)++] & 0x7f);
    //<<<

#ifdef DEBUG
    printf("t->SendingTime = %lu\n", t->SendingTime);
#endif

#ifdef DEBUG1
    printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
    printf("name = %sSendingTime%s\n", KRED, RESET_COLOR);
    printf("type = %snopmap_uint64_nonullable_noop\n%s", KBLU, RESET_COLOR);
    printf("byte_representation: ");
    printf("%s", COLOR_BYTES);
    for (int i = t_SendingTime_start; i < *offset; i++)
    {
        printf("%02x ", packet[i]);
    }
    printf("%s\n", RESET_COLOR);
    printf("value = %s%lu%s\n", KMAG, t->SendingTime, RESET_COLOR);
    printf("\n");
#endif

#ifdef DEBUG3
    getchar();
#endif

//nopmap_uint64_nullable_noop LastUpdateTime
#ifdef DEBUG2
    int t_LastUpdateTime_start = *offset;
#endif

    //>>> LastUpdateTime
    if (packet[*offset] == 0x80)
    {
        t->LastUpdateTime.is_null = 1;
        (*offset)++;
    }
    else
    {
        t->LastUpdateTime.value = 0;
        t->LastUpdateTime.is_null = 0;
        while (!((packet[*offset] & 0x80)))
        {
            (t->LastUpdateTime.value) |= packet[(*offset)++];
            (t->LastUpdateTime.value) <<= 7;
        }
        (t->LastUpdateTime.value) |= (packet[(*offset)++] & 0x7f);
        (t->LastUpdateTime.value)--;
    }
    //<<<

#ifdef DEBUG

    if (t->LastUpdateTime.is_null)
    {
        printf("t->LastUpdateTime = %sNULL%s\n", KMAG, RESET_COLOR);
    }
    else
    {
        printf("t->LastUpdateTime = %s%lu%s\n", KMAG, t->LastUpdateTime.value, RESET_COLOR);
    }

#endif

#ifdef DEBUG1
    printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
    printf("name = %sLastUpdateTime%s\n", KRED, RESET_COLOR);
    printf("type = %snopmap_uint64_nullable_noop\n%s", KBLU, RESET_COLOR);
    printf("byte_representation: ");
    printf("%s", COLOR_BYTES);
    for (int i = t_LastUpdateTime_start; i < *offset; i++)
    {
        printf("%02x ", packet[i]);
    }
    printf("%s\n", RESET_COLOR);

    if (t->LastUpdateTime.is_null)
    {
        printf("t->LastUpdateTime = %sNULL%s\n", KMAG, RESET_COLOR);
    }
    else
    {
        printf("t->LastUpdateTime = %s%lu%s\n", KMAG, t->LastUpdateTime.value, RESET_COLOR);
    }

    printf("\n");
#endif

#ifdef DEBUG3
    getchar();
#endif

    //nopmap_uint32_nonullable_noop NoMDEntries
#ifdef DEBUG2
    int t_NoMDEntries_start = *offset;
#endif

    //>>> NoMDEntries
    t->NoMDEntries = 0;
    while (!((packet[*offset] & 0x80)))
    {
        t->NoMDEntries |= packet[(*offset)++];
        t->NoMDEntries <<= 7;
    }
    t->NoMDEntries |= (packet[(*offset)++] & 0x7f);
    //<<<

#ifdef DEBUG
    printf("t->NoMDEntries = %u\n", t->NoMDEntries);
#endif

#ifdef DEBUG1
    printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
    printf("name = %sNoMDEntries%s\n", KRED, RESET_COLOR);
    printf("type = %snopmap_uint32_nonullable_noop\n%s", KBLU, RESET_COLOR);
    printf("byte_representation: ");
    printf("%s", COLOR_BYTES);
    for (int i = t_NoMDEntries_start; i < *offset; i++)
    {
        printf("%02x ", packet[i]);
    }
    printf("%s\n", RESET_COLOR);
    printf("value = %s%u%s\n", KMAG, t->NoMDEntries, RESET_COLOR);
    printf("\n");
#endif

#ifdef DEBUG3
    getchar();
#endif

    if (t->NoMDEntries >= moex_eq__X_MSR_FOND__GroupMDEntries__MAX)
    {
        return -1;
    }

    for (int i_0 = 0; i_0 < t->NoMDEntries; i_0++)
    {
        //PMAP for this sequence doesn't required

//nopmap_uint32_nullable_noop MDUpdateAction
#ifdef DEBUG2
        int t_GroupMDEntries_i_0_MDUpdateAction_start = *offset;
#endif

        //>>> MDUpdateAction
        if (packet[*offset] == 0x80)
        {
            t->GroupMDEntries[i_0].MDUpdateAction.is_null = 1;
            t->GroupMDEntries[i_0].MDUpdateAction.value = 0;
            (*offset)++;
        }
        else
        {
            t->GroupMDEntries[i_0].MDUpdateAction.value = 0;
            t->GroupMDEntries[i_0].MDUpdateAction.is_null = 0;
            while (!((packet[*offset] & 0x80)))
            {
                (t->GroupMDEntries[i_0].MDUpdateAction.value) |= packet[(*offset)++];
                (t->GroupMDEntries[i_0].MDUpdateAction.value) <<= 7;
            }
            (t->GroupMDEntries[i_0].MDUpdateAction.value) |= (packet[(*offset)++] & 0x7f);
            (t->GroupMDEntries[i_0].MDUpdateAction.value)--;
        }
        //<<<

#ifdef DEBUG

        if (t->GroupMDEntries[i_0].MDUpdateAction.is_null)
        {
            printf("t->GroupMDEntries[%d].MDUpdateAction = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
        }
        else
        {
            printf("t->GroupMDEntries[%d].MDUpdateAction = %s%u%s\n", i_0, KMAG, t->GroupMDEntries[i_0].MDUpdateAction.value, RESET_COLOR);
        }

#endif

#ifdef DEBUG1
        printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
        printf("name = %sMDUpdateAction%s\n", KRED, RESET_COLOR);
        printf("type = %snopmap_uint32_nullable_noop\n%s", KBLU, RESET_COLOR);
        printf("byte_representation: ");
        printf("%s", COLOR_BYTES);
        for (int i = t_GroupMDEntries_i_0_MDUpdateAction_start; i < *offset; i++)
        {
            printf("%02x ", packet[i]);
        }
        printf("%s\n", RESET_COLOR);

        if (t->GroupMDEntries[i_0].MDUpdateAction.is_null)
        {
            printf("t->GroupMDEntries[%d].MDUpdateAction = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
        }
        else
        {
            printf("t->GroupMDEntries[%d].MDUpdateAction = %s%u%s\n", i_0, KMAG, t->GroupMDEntries[i_0].MDUpdateAction.value, RESET_COLOR);
        }

        printf("\n");
#endif

#ifdef DEBUG3
        getchar();
#endif

//nopmap_string_nullable_noop MDEntryType
#ifdef DEBUG2
        int t_GroupMDEntries_i_0_MDEntryType_start = *offset;
#endif

        //>>> MDEntryType
        t->GroupMDEntries[i_0].MDEntryType.start = packet + *offset;
        if (packet[*offset] == 0x80)
        {
            (*offset)++;
            t->GroupMDEntries[i_0].MDEntryType.len = 0;
            t->GroupMDEntries[i_0].MDEntryType.is_null = 1;
            //printf("t->GroupMDEntries[i_0].MDEntryType = EMPTY \n");
        }
        else
        {
            t->GroupMDEntries[i_0].MDEntryType.len = 0;
            t->GroupMDEntries[i_0].MDEntryType.is_null = 0;
            while (!((packet[(*offset)] & 0x80)))
            {
                t->GroupMDEntries[i_0].MDEntryType.len++;
                (*offset)++;
            }
            packet[*offset] = packet[*offset] & 0x7F;
            (*offset)++;
            t->GroupMDEntries[i_0].MDEntryType.len++;
        }
        //<<<

#ifdef DEBUG

        if (1)
        {

            if (t->GroupMDEntries[i_0].MDEntryType.is_null)
            {
                printf("t->GroupMDEntries[%d].MDEntryType = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
            }
            else
            {
                unsigned char fake[128];
                strncpy(fake, t->GroupMDEntries[i_0].MDEntryType.start, t->GroupMDEntries[i_0].MDEntryType.len);
                fake[t->GroupMDEntries[i_0].MDEntryType.len] = '\0';
                printf("t->GroupMDEntries[%d].MDEntryType = %s%s%s\n", i_0, KMAG, fake, RESET_COLOR);
            }
        }

#endif

#ifdef DEBUG1
        printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
        printf("name = %sMDEntryType%s\n", KRED, RESET_COLOR);
        printf("type = %s nopmap_string_nullable_noop\n%s", KBLU, RESET_COLOR);
        printf("byte_representation: ");
        printf("%s", COLOR_BYTES);
        for (int i = t_GroupMDEntries_i_0_MDEntryType_start; i < *offset; i++)
        {
            printf("%02x ", packet[i]);
        }
        printf("%s\n", RESET_COLOR);

        if (1)
        {

            if (t->GroupMDEntries[i_0].MDEntryType.is_null)
            {
                printf("t->GroupMDEntries[%d].MDEntryType = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
            }
            else
            {
                unsigned char fake[128];
                strncpy(fake, t->GroupMDEntries[i_0].MDEntryType.start, t->GroupMDEntries[i_0].MDEntryType.len);
                fake[t->GroupMDEntries[i_0].MDEntryType.len] = '\0';
                printf("t->GroupMDEntries[%d].MDEntryType = %s%s%s\n", i_0, KMAG, fake, RESET_COLOR);
            }
        }

        printf("\n");
#endif

#ifdef DEBUG3
        getchar();
#endif

//nopmap_string_nullable_noop MDEntryID
#ifdef DEBUG2
        int t_GroupMDEntries_i_0_MDEntryID_start = *offset;
#endif

        //>>> MDEntryID
        t->GroupMDEntries[i_0].MDEntryID.start = packet + *offset;
        if (packet[*offset] == 0x80)
        {
            (*offset)++;
            t->GroupMDEntries[i_0].MDEntryID.len = 0;
            t->GroupMDEntries[i_0].MDEntryID.is_null = 1;
            //printf("t->GroupMDEntries[i_0].MDEntryID = EMPTY \n");
        }
        else
        {
            t->GroupMDEntries[i_0].MDEntryID.len = 0;
            t->GroupMDEntries[i_0].MDEntryID.is_null = 0;
            while (!((packet[(*offset)] & 0x80)))
            {
                t->GroupMDEntries[i_0].MDEntryID.len++;
                (*offset)++;
            }
            packet[*offset] = packet[*offset] & 0x7F;
            (*offset)++;
            t->GroupMDEntries[i_0].MDEntryID.len++;
        }
        //<<<

#ifdef DEBUG

        if (1)
        {

            if (t->GroupMDEntries[i_0].MDEntryID.is_null)
            {
                printf("t->GroupMDEntries[%d].MDEntryID = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
            }
            else
            {
                unsigned char fake[128];
                strncpy(fake, t->GroupMDEntries[i_0].MDEntryID.start, t->GroupMDEntries[i_0].MDEntryID.len);
                fake[t->GroupMDEntries[i_0].MDEntryID.len] = '\0';
                printf("t->GroupMDEntries[%d].MDEntryID = %s%s%s\n", i_0, KMAG, fake, RESET_COLOR);
            }
        }

#endif

#ifdef DEBUG1
        printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
        printf("name = %sMDEntryID%s\n", KRED, RESET_COLOR);
        printf("type = %s nopmap_string_nullable_noop\n%s", KBLU, RESET_COLOR);
        printf("byte_representation: ");
        printf("%s", COLOR_BYTES);
        for (int i = t_GroupMDEntries_i_0_MDEntryID_start; i < *offset; i++)
        {
            printf("%02x ", packet[i]);
        }
        printf("%s\n", RESET_COLOR);

        if (1)
        {

            if (t->GroupMDEntries[i_0].MDEntryID.is_null)
            {
                printf("t->GroupMDEntries[%d].MDEntryID = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
            }
            else
            {
                unsigned char fake[128];
                strncpy(fake, t->GroupMDEntries[i_0].MDEntryID.start, t->GroupMDEntries[i_0].MDEntryID.len);
                fake[t->GroupMDEntries[i_0].MDEntryID.len] = '\0';
                printf("t->GroupMDEntries[%d].MDEntryID = %s%s%s\n", i_0, KMAG, fake, RESET_COLOR);
            }
        }

        printf("\n");
#endif

#ifdef DEBUG3
        getchar();
#endif

//nopmap_string_nullable_noop Symbol
#ifdef DEBUG2
        int t_GroupMDEntries_i_0_Symbol_start = *offset;
#endif

        //>>> Symbol
        t->GroupMDEntries[i_0].Symbol.start = packet + *offset;
        if (packet[*offset] == 0x80)
        {
            (*offset)++;
            t->GroupMDEntries[i_0].Symbol.len = 0;
            t->GroupMDEntries[i_0].Symbol.is_null = 1;
            //printf("t->GroupMDEntries[i_0].Symbol = EMPTY \n");
        }
        else
        {
            t->GroupMDEntries[i_0].Symbol.len = 0;
            t->GroupMDEntries[i_0].Symbol.is_null = 0;
            while (!((packet[(*offset)] & 0x80)))
            {
                t->GroupMDEntries[i_0].Symbol.len++;
                (*offset)++;
            }
            packet[*offset] = packet[*offset] & 0x7F;
            (*offset)++;
            t->GroupMDEntries[i_0].Symbol.len++;
        }
        //<<<

#ifdef DEBUG

        if (1)
        {

            if (t->GroupMDEntries[i_0].Symbol.is_null)
            {
                printf("t->GroupMDEntries[%d].Symbol = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
            }
            else
            {
                unsigned char fake[128];
                strncpy(fake, t->GroupMDEntries[i_0].Symbol.start, t->GroupMDEntries[i_0].Symbol.len);
                fake[t->GroupMDEntries[i_0].Symbol.len] = '\0';
                printf("t->GroupMDEntries[%d].Symbol = %s%s%s\n", i_0, KMAG, fake, RESET_COLOR);
            }
        }

#endif

#ifdef DEBUG1
        printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
        printf("name = %sSymbol%s\n", KRED, RESET_COLOR);
        printf("type = %s nopmap_string_nullable_noop\n%s", KBLU, RESET_COLOR);
        printf("byte_representation: ");
        printf("%s", COLOR_BYTES);
        for (int i = t_GroupMDEntries_i_0_Symbol_start; i < *offset; i++)
        {
            printf("%02x ", packet[i]);
        }
        printf("%s\n", RESET_COLOR);

        if (1)
        {

            if (t->GroupMDEntries[i_0].Symbol.is_null)
            {
                printf("t->GroupMDEntries[%d].Symbol = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
            }
            else
            {
                unsigned char fake[128];
                strncpy(fake, t->GroupMDEntries[i_0].Symbol.start, t->GroupMDEntries[i_0].Symbol.len);
                fake[t->GroupMDEntries[i_0].Symbol.len] = '\0';
                printf("t->GroupMDEntries[%d].Symbol = %s%s%s\n", i_0, KMAG, fake, RESET_COLOR);
            }
        }

        printf("\n");
#endif

#ifdef DEBUG3
        getchar();
#endif

//nopmap_int32_nullable_noop RptSeq
#ifdef DEBUG2
        int t_GroupMDEntries_i_0_RptSeq_start = *offset;
#endif

        //>>> RptSeq
        if (packet[*offset] == 0x80)
        {
            (*offset)++;
            t->GroupMDEntries[i_0].RptSeq.is_null = 1;
        }
        else
        {
            t->GroupMDEntries[i_0].RptSeq.value = 0 - (packet[*offset] & 0x40);
            t->GroupMDEntries[i_0].RptSeq.is_null = 0;
            while (!((packet[*offset] & 0x80)))
            {
                (t->GroupMDEntries[i_0].RptSeq.value) |= packet[(*offset)++];
                (t->GroupMDEntries[i_0].RptSeq.value) <<= 7;
            }
            (t->GroupMDEntries[i_0].RptSeq.value) |= (packet[(*offset)++] & 0x7f);
            if (t->GroupMDEntries[i_0].RptSeq.value > 0)
            {
                (t->GroupMDEntries[i_0].RptSeq.value)--;
            }
        }
        //<<<

#ifdef DEBUG

        if (t->GroupMDEntries[i_0].RptSeq.is_null)
        {
            printf("t->GroupMDEntries[%d].RptSeq = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
        }
        else
        {
            printf("t->GroupMDEntries[%d].RptSeq = %s%d%s\n", i_0, KMAG, t->GroupMDEntries[i_0].RptSeq.value, RESET_COLOR);
        }

#endif

#ifdef DEBUG1
        printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
        printf("name = %sRptSeq%s\n", KRED, RESET_COLOR);
        printf("type = %snopmap_int32_nullable_noop\n%s", KBLU, RESET_COLOR);
        printf("byte_representation: ");
        printf("%s", COLOR_BYTES);
        for (int i = t_GroupMDEntries_i_0_RptSeq_start; i < *offset; i++)
        {
            printf("%02x ", packet[i]);
        }
        printf("%s\n", RESET_COLOR);

        if (t->GroupMDEntries[i_0].RptSeq.is_null)
        {
            printf("t->GroupMDEntries[%d].RptSeq = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
        }
        else
        {
            printf("t->GroupMDEntries[%d].RptSeq = %s%d%s\n", i_0, KMAG, t->GroupMDEntries[i_0].RptSeq.value, RESET_COLOR);
        }

        printf("\n");
#endif

#ifdef DEBUG3
        getchar();
#endif

        //nopmap_decimal_nullable_noop

//nopmap_int32_nullable_noop MDEntryPx
#ifdef DEBUG2
        int t_GroupMDEntries_i_0_MDEntryPxexponenta_start = *offset;
#endif

        //>>> MDEntryPx
        if (packet[*offset] == 0x80)
        {
            (*offset)++;
            t->GroupMDEntries[i_0].MDEntryPx.exponenta.is_null = 1;
        }
        else
        {
            t->GroupMDEntries[i_0].MDEntryPx.exponenta.value = 0 - (packet[*offset] & 0x40);
            t->GroupMDEntries[i_0].MDEntryPx.exponenta.is_null = 0;
            while (!((packet[*offset] & 0x80)))
            {
                (t->GroupMDEntries[i_0].MDEntryPx.exponenta.value) |= packet[(*offset)++];
                (t->GroupMDEntries[i_0].MDEntryPx.exponenta.value) <<= 7;
            }
            (t->GroupMDEntries[i_0].MDEntryPx.exponenta.value) |= (packet[(*offset)++] & 0x7f);
            if (t->GroupMDEntries[i_0].MDEntryPx.exponenta.value > 0)
            {
                (t->GroupMDEntries[i_0].MDEntryPx.exponenta.value)--;
            }
        }
        //<<<

#ifdef DEBUG

        if (t->GroupMDEntries[i_0].MDEntryPx.exponenta.is_null)
        {
            printf("t->GroupMDEntries[%d].MDEntryPx.exponenta = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
        }
        else
        {
            printf("t->GroupMDEntries[%d].MDEntryPx.exponenta = %s%d%s\n", i_0, KMAG, t->GroupMDEntries[i_0].MDEntryPx.exponenta.value, RESET_COLOR);
        }

#endif

#ifdef DEBUG1
        printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
        printf("name = %sMDEntryPx%s\n", KRED, RESET_COLOR);
        printf("type = %snopmap_int32_nullable_noop\n%s", KBLU, RESET_COLOR);
        printf("byte_representation: ");
        printf("%s", COLOR_BYTES);
        for (int i = t_GroupMDEntries_i_0_MDEntryPxexponenta_start; i < *offset; i++)
        {
            printf("%02x ", packet[i]);
        }
        printf("%s\n", RESET_COLOR);

        if (t->GroupMDEntries[i_0].MDEntryPx.exponenta.is_null)
        {
            printf("t->GroupMDEntries[%d].MDEntryPx.exponenta = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
        }
        else
        {
            printf("t->GroupMDEntries[%d].MDEntryPx.exponenta = %s%d%s\n", i_0, KMAG, t->GroupMDEntries[i_0].MDEntryPx.exponenta.value, RESET_COLOR);
        }

        printf("\n");
#endif

#ifdef DEBUG3
        getchar();
#endif

        if (!t->GroupMDEntries[i_0].MDEntryPx.exponenta.is_null)
        {
            //calc mantissa
            //nopmap_int64_nonullable_noop MDEntryPx
#ifdef DEBUG2
            int t_GroupMDEntries_i_0_MDEntryPxmantissa_start = *offset;
#endif

            //>>> MDEntryPx
            t->GroupMDEntries[i_0].MDEntryPx.mantissa = 0 - (packet[*offset] & 0x40);
            while (!((packet[*offset] & 0x80)))
            {
                t->GroupMDEntries[i_0].MDEntryPx.mantissa |= packet[(*offset)++];
                t->GroupMDEntries[i_0].MDEntryPx.mantissa <<= 7;
            }
            t->GroupMDEntries[i_0].MDEntryPx.mantissa |= (packet[(*offset)++] & 0x7f);
            //<<<

#ifdef DEBUG
            printf("t->GroupMDEntries[%d].MDEntryPx.mantissa = %ld\n", i_0, t->GroupMDEntries[i_0].MDEntryPx.mantissa);
#endif

#ifdef DEBUG1
            printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
            printf("name = %sMDEntryPx%s\n", KRED, RESET_COLOR);
            printf("type = %snopmap_int64_nonullable_noop\n%s", KBLU, RESET_COLOR);
            printf("byte_representation: ");
            printf("%s", COLOR_BYTES);
            for (int i = t_GroupMDEntries_i_0_MDEntryPxmantissa_start; i < *offset; i++)
            {
                printf("%02x ", packet[i]);
            }
            printf("%s\n", RESET_COLOR);
            printf("value = %s%ld%s\n", KMAG, t->GroupMDEntries[i_0].MDEntryPx.mantissa, RESET_COLOR);
            printf("\n");
#endif

#ifdef DEBUG3
            getchar();
#endif
        }

        //nopmap_decimal_nullable_noop

//nopmap_int32_nullable_noop MDEntrySize
#ifdef DEBUG2
        int t_GroupMDEntries_i_0_MDEntrySizeexponenta_start = *offset;
#endif

        //>>> MDEntrySize
        if (packet[*offset] == 0x80)
        {
            (*offset)++;
            t->GroupMDEntries[i_0].MDEntrySize.exponenta.is_null = 1;
        }
        else
        {
            t->GroupMDEntries[i_0].MDEntrySize.exponenta.value = 0 - (packet[*offset] & 0x40);
            t->GroupMDEntries[i_0].MDEntrySize.exponenta.is_null = 0;
            while (!((packet[*offset] & 0x80)))
            {
                (t->GroupMDEntries[i_0].MDEntrySize.exponenta.value) |= packet[(*offset)++];
                (t->GroupMDEntries[i_0].MDEntrySize.exponenta.value) <<= 7;
            }
            (t->GroupMDEntries[i_0].MDEntrySize.exponenta.value) |= (packet[(*offset)++] & 0x7f);
            if (t->GroupMDEntries[i_0].MDEntrySize.exponenta.value > 0)
            {
                (t->GroupMDEntries[i_0].MDEntrySize.exponenta.value)--;
            }
        }
        //<<<

#ifdef DEBUG

        if (t->GroupMDEntries[i_0].MDEntrySize.exponenta.is_null)
        {
            printf("t->GroupMDEntries[%d].MDEntrySize.exponenta = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
        }
        else
        {
            printf("t->GroupMDEntries[%d].MDEntrySize.exponenta = %s%d%s\n", i_0, KMAG, t->GroupMDEntries[i_0].MDEntrySize.exponenta.value, RESET_COLOR);
        }

#endif

#ifdef DEBUG1
        printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
        printf("name = %sMDEntrySize%s\n", KRED, RESET_COLOR);
        printf("type = %snopmap_int32_nullable_noop\n%s", KBLU, RESET_COLOR);
        printf("byte_representation: ");
        printf("%s", COLOR_BYTES);
        for (int i = t_GroupMDEntries_i_0_MDEntrySizeexponenta_start; i < *offset; i++)
        {
            printf("%02x ", packet[i]);
        }
        printf("%s\n", RESET_COLOR);

        if (t->GroupMDEntries[i_0].MDEntrySize.exponenta.is_null)
        {
            printf("t->GroupMDEntries[%d].MDEntrySize.exponenta = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
        }
        else
        {
            printf("t->GroupMDEntries[%d].MDEntrySize.exponenta = %s%d%s\n", i_0, KMAG, t->GroupMDEntries[i_0].MDEntrySize.exponenta.value, RESET_COLOR);
        }

        printf("\n");
#endif

#ifdef DEBUG3
        getchar();
#endif

        if (!t->GroupMDEntries[i_0].MDEntrySize.exponenta.is_null)
        {
            //calc mantissa
            //nopmap_int64_nonullable_noop MDEntrySize
#ifdef DEBUG2
            int t_GroupMDEntries_i_0_MDEntrySizemantissa_start = *offset;
#endif

            //>>> MDEntrySize
            t->GroupMDEntries[i_0].MDEntrySize.mantissa = 0 - (packet[*offset] & 0x40);
            while (!((packet[*offset] & 0x80)))
            {
                t->GroupMDEntries[i_0].MDEntrySize.mantissa |= packet[(*offset)++];
                t->GroupMDEntries[i_0].MDEntrySize.mantissa <<= 7;
            }
            t->GroupMDEntries[i_0].MDEntrySize.mantissa |= (packet[(*offset)++] & 0x7f);
            //<<<

#ifdef DEBUG
            printf("t->GroupMDEntries[%d].MDEntrySize.mantissa = %ld\n", i_0, t->GroupMDEntries[i_0].MDEntrySize.mantissa);
#endif

#ifdef DEBUG1
            printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
            printf("name = %sMDEntrySize%s\n", KRED, RESET_COLOR);
            printf("type = %snopmap_int64_nonullable_noop\n%s", KBLU, RESET_COLOR);
            printf("byte_representation: ");
            printf("%s", COLOR_BYTES);
            for (int i = t_GroupMDEntries_i_0_MDEntrySizemantissa_start; i < *offset; i++)
            {
                printf("%02x ", packet[i]);
            }
            printf("%s\n", RESET_COLOR);
            printf("value = %s%ld%s\n", KMAG, t->GroupMDEntries[i_0].MDEntrySize.mantissa, RESET_COLOR);
            printf("\n");
#endif

#ifdef DEBUG3
            getchar();
#endif
        }

//nopmap_uint32_nullable_noop MDEntryDate
#ifdef DEBUG2
        int t_GroupMDEntries_i_0_MDEntryDate_start = *offset;
#endif

        //>>> MDEntryDate
        if (packet[*offset] == 0x80)
        {
            t->GroupMDEntries[i_0].MDEntryDate.is_null = 1;
            t->GroupMDEntries[i_0].MDEntryDate.value = 0;
            (*offset)++;
        }
        else
        {
            t->GroupMDEntries[i_0].MDEntryDate.value = 0;
            t->GroupMDEntries[i_0].MDEntryDate.is_null = 0;
            while (!((packet[*offset] & 0x80)))
            {
                (t->GroupMDEntries[i_0].MDEntryDate.value) |= packet[(*offset)++];
                (t->GroupMDEntries[i_0].MDEntryDate.value) <<= 7;
            }
            (t->GroupMDEntries[i_0].MDEntryDate.value) |= (packet[(*offset)++] & 0x7f);
            (t->GroupMDEntries[i_0].MDEntryDate.value)--;
        }
        //<<<

#ifdef DEBUG

        if (t->GroupMDEntries[i_0].MDEntryDate.is_null)
        {
            printf("t->GroupMDEntries[%d].MDEntryDate = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
        }
        else
        {
            printf("t->GroupMDEntries[%d].MDEntryDate = %s%u%s\n", i_0, KMAG, t->GroupMDEntries[i_0].MDEntryDate.value, RESET_COLOR);
        }

#endif

#ifdef DEBUG1
        printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
        printf("name = %sMDEntryDate%s\n", KRED, RESET_COLOR);
        printf("type = %snopmap_uint32_nullable_noop\n%s", KBLU, RESET_COLOR);
        printf("byte_representation: ");
        printf("%s", COLOR_BYTES);
        for (int i = t_GroupMDEntries_i_0_MDEntryDate_start; i < *offset; i++)
        {
            printf("%02x ", packet[i]);
        }
        printf("%s\n", RESET_COLOR);

        if (t->GroupMDEntries[i_0].MDEntryDate.is_null)
        {
            printf("t->GroupMDEntries[%d].MDEntryDate = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
        }
        else
        {
            printf("t->GroupMDEntries[%d].MDEntryDate = %s%u%s\n", i_0, KMAG, t->GroupMDEntries[i_0].MDEntryDate.value, RESET_COLOR);
        }

        printf("\n");
#endif

#ifdef DEBUG3
        getchar();
#endif

//nopmap_uint32_nullable_noop MDEntryTime
#ifdef DEBUG2
        int t_GroupMDEntries_i_0_MDEntryTime_start = *offset;
#endif

        //>>> MDEntryTime
        if (packet[*offset] == 0x80)
        {
            t->GroupMDEntries[i_0].MDEntryTime.is_null = 1;
            t->GroupMDEntries[i_0].MDEntryTime.value = 0;
            (*offset)++;
        }
        else
        {
            t->GroupMDEntries[i_0].MDEntryTime.value = 0;
            t->GroupMDEntries[i_0].MDEntryTime.is_null = 0;
            while (!((packet[*offset] & 0x80)))
            {
                (t->GroupMDEntries[i_0].MDEntryTime.value) |= packet[(*offset)++];
                (t->GroupMDEntries[i_0].MDEntryTime.value) <<= 7;
            }
            (t->GroupMDEntries[i_0].MDEntryTime.value) |= (packet[(*offset)++] & 0x7f);
            (t->GroupMDEntries[i_0].MDEntryTime.value)--;
        }
        //<<<

#ifdef DEBUG

        if (t->GroupMDEntries[i_0].MDEntryTime.is_null)
        {
            printf("t->GroupMDEntries[%d].MDEntryTime = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
        }
        else
        {
            printf("t->GroupMDEntries[%d].MDEntryTime = %s%u%s\n", i_0, KMAG, t->GroupMDEntries[i_0].MDEntryTime.value, RESET_COLOR);
        }

#endif

#ifdef DEBUG1
        printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
        printf("name = %sMDEntryTime%s\n", KRED, RESET_COLOR);
        printf("type = %snopmap_uint32_nullable_noop\n%s", KBLU, RESET_COLOR);
        printf("byte_representation: ");
        printf("%s", COLOR_BYTES);
        for (int i = t_GroupMDEntries_i_0_MDEntryTime_start; i < *offset; i++)
        {
            printf("%02x ", packet[i]);
        }
        printf("%s\n", RESET_COLOR);

        if (t->GroupMDEntries[i_0].MDEntryTime.is_null)
        {
            printf("t->GroupMDEntries[%d].MDEntryTime = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
        }
        else
        {
            printf("t->GroupMDEntries[%d].MDEntryTime = %s%u%s\n", i_0, KMAG, t->GroupMDEntries[i_0].MDEntryTime.value, RESET_COLOR);
        }

        printf("\n");
#endif

#ifdef DEBUG3
        getchar();
#endif

//nopmap_uint32_nullable_noop StartTime
#ifdef DEBUG2
        int t_GroupMDEntries_i_0_StartTime_start = *offset;
#endif

        //>>> StartTime
        if (packet[*offset] == 0x80)
        {
            t->GroupMDEntries[i_0].StartTime.is_null = 1;
            t->GroupMDEntries[i_0].StartTime.value = 0;
            (*offset)++;
        }
        else
        {
            t->GroupMDEntries[i_0].StartTime.value = 0;
            t->GroupMDEntries[i_0].StartTime.is_null = 0;
            while (!((packet[*offset] & 0x80)))
            {
                (t->GroupMDEntries[i_0].StartTime.value) |= packet[(*offset)++];
                (t->GroupMDEntries[i_0].StartTime.value) <<= 7;
            }
            (t->GroupMDEntries[i_0].StartTime.value) |= (packet[(*offset)++] & 0x7f);
            (t->GroupMDEntries[i_0].StartTime.value)--;
        }
        //<<<

#ifdef DEBUG

        if (t->GroupMDEntries[i_0].StartTime.is_null)
        {
            printf("t->GroupMDEntries[%d].StartTime = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
        }
        else
        {
            printf("t->GroupMDEntries[%d].StartTime = %s%u%s\n", i_0, KMAG, t->GroupMDEntries[i_0].StartTime.value, RESET_COLOR);
        }

#endif

#ifdef DEBUG1
        printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
        printf("name = %sStartTime%s\n", KRED, RESET_COLOR);
        printf("type = %snopmap_uint32_nullable_noop\n%s", KBLU, RESET_COLOR);
        printf("byte_representation: ");
        printf("%s", COLOR_BYTES);
        for (int i = t_GroupMDEntries_i_0_StartTime_start; i < *offset; i++)
        {
            printf("%02x ", packet[i]);
        }
        printf("%s\n", RESET_COLOR);

        if (t->GroupMDEntries[i_0].StartTime.is_null)
        {
            printf("t->GroupMDEntries[%d].StartTime = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
        }
        else
        {
            printf("t->GroupMDEntries[%d].StartTime = %s%u%s\n", i_0, KMAG, t->GroupMDEntries[i_0].StartTime.value, RESET_COLOR);
        }

        printf("\n");
#endif

#ifdef DEBUG3
        getchar();
#endif

//nopmap_string_nullable_noop QuoteCondition
#ifdef DEBUG2
        int t_GroupMDEntries_i_0_QuoteCondition_start = *offset;
#endif

        //>>> QuoteCondition
        t->GroupMDEntries[i_0].QuoteCondition.start = packet + *offset;
        if (packet[*offset] == 0x80)
        {
            (*offset)++;
            t->GroupMDEntries[i_0].QuoteCondition.len = 0;
            t->GroupMDEntries[i_0].QuoteCondition.is_null = 1;
            //printf("t->GroupMDEntries[i_0].QuoteCondition = EMPTY \n");
        }
        else
        {
            t->GroupMDEntries[i_0].QuoteCondition.len = 0;
            t->GroupMDEntries[i_0].QuoteCondition.is_null = 0;
            while (!((packet[(*offset)] & 0x80)))
            {
                t->GroupMDEntries[i_0].QuoteCondition.len++;
                (*offset)++;
            }
            packet[*offset] = packet[*offset] & 0x7F;
            (*offset)++;
            t->GroupMDEntries[i_0].QuoteCondition.len++;
        }
        //<<<

#ifdef DEBUG

        if (1)
        {

            if (t->GroupMDEntries[i_0].QuoteCondition.is_null)
            {
                printf("t->GroupMDEntries[%d].QuoteCondition = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
            }
            else
            {
                unsigned char fake[128];
                strncpy(fake, t->GroupMDEntries[i_0].QuoteCondition.start, t->GroupMDEntries[i_0].QuoteCondition.len);
                fake[t->GroupMDEntries[i_0].QuoteCondition.len] = '\0';
                printf("t->GroupMDEntries[%d].QuoteCondition = %s%s%s\n", i_0, KMAG, fake, RESET_COLOR);
            }
        }

#endif

#ifdef DEBUG1
        printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
        printf("name = %sQuoteCondition%s\n", KRED, RESET_COLOR);
        printf("type = %s nopmap_string_nullable_noop\n%s", KBLU, RESET_COLOR);
        printf("byte_representation: ");
        printf("%s", COLOR_BYTES);
        for (int i = t_GroupMDEntries_i_0_QuoteCondition_start; i < *offset; i++)
        {
            printf("%02x ", packet[i]);
        }
        printf("%s\n", RESET_COLOR);

        if (1)
        {

            if (t->GroupMDEntries[i_0].QuoteCondition.is_null)
            {
                printf("t->GroupMDEntries[%d].QuoteCondition = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
            }
            else
            {
                unsigned char fake[128];
                strncpy(fake, t->GroupMDEntries[i_0].QuoteCondition.start, t->GroupMDEntries[i_0].QuoteCondition.len);
                fake[t->GroupMDEntries[i_0].QuoteCondition.len] = '\0';
                printf("t->GroupMDEntries[%d].QuoteCondition = %s%s%s\n", i_0, KMAG, fake, RESET_COLOR);
            }
        }

        printf("\n");
#endif

#ifdef DEBUG3
        getchar();
#endif

//nopmap_string_nullable_noop TradeCondition
#ifdef DEBUG2
        int t_GroupMDEntries_i_0_TradeCondition_start = *offset;
#endif

        //>>> TradeCondition
        t->GroupMDEntries[i_0].TradeCondition.start = packet + *offset;
        if (packet[*offset] == 0x80)
        {
            (*offset)++;
            t->GroupMDEntries[i_0].TradeCondition.len = 0;
            t->GroupMDEntries[i_0].TradeCondition.is_null = 1;
            //printf("t->GroupMDEntries[i_0].TradeCondition = EMPTY \n");
        }
        else
        {
            t->GroupMDEntries[i_0].TradeCondition.len = 0;
            t->GroupMDEntries[i_0].TradeCondition.is_null = 0;
            while (!((packet[(*offset)] & 0x80)))
            {
                t->GroupMDEntries[i_0].TradeCondition.len++;
                (*offset)++;
            }
            packet[*offset] = packet[*offset] & 0x7F;
            (*offset)++;
            t->GroupMDEntries[i_0].TradeCondition.len++;
        }
        //<<<

#ifdef DEBUG

        if (1)
        {

            if (t->GroupMDEntries[i_0].TradeCondition.is_null)
            {
                printf("t->GroupMDEntries[%d].TradeCondition = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
            }
            else
            {
                unsigned char fake[128];
                strncpy(fake, t->GroupMDEntries[i_0].TradeCondition.start, t->GroupMDEntries[i_0].TradeCondition.len);
                fake[t->GroupMDEntries[i_0].TradeCondition.len] = '\0';
                printf("t->GroupMDEntries[%d].TradeCondition = %s%s%s\n", i_0, KMAG, fake, RESET_COLOR);
            }
        }

#endif

#ifdef DEBUG1
        printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
        printf("name = %sTradeCondition%s\n", KRED, RESET_COLOR);
        printf("type = %s nopmap_string_nullable_noop\n%s", KBLU, RESET_COLOR);
        printf("byte_representation: ");
        printf("%s", COLOR_BYTES);
        for (int i = t_GroupMDEntries_i_0_TradeCondition_start; i < *offset; i++)
        {
            printf("%02x ", packet[i]);
        }
        printf("%s\n", RESET_COLOR);

        if (1)
        {

            if (t->GroupMDEntries[i_0].TradeCondition.is_null)
            {
                printf("t->GroupMDEntries[%d].TradeCondition = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
            }
            else
            {
                unsigned char fake[128];
                strncpy(fake, t->GroupMDEntries[i_0].TradeCondition.start, t->GroupMDEntries[i_0].TradeCondition.len);
                fake[t->GroupMDEntries[i_0].TradeCondition.len] = '\0';
                printf("t->GroupMDEntries[%d].TradeCondition = %s%s%s\n", i_0, KMAG, fake, RESET_COLOR);
            }
        }

        printf("\n");
#endif

#ifdef DEBUG3
        getchar();
#endif

//nopmap_string_nullable_noop OpenCloseSettlFlag
#ifdef DEBUG2
        int t_GroupMDEntries_i_0_OpenCloseSettlFlag_start = *offset;
#endif

        //>>> OpenCloseSettlFlag
        t->GroupMDEntries[i_0].OpenCloseSettlFlag.start = packet + *offset;
        if (packet[*offset] == 0x80)
        {
            (*offset)++;
            t->GroupMDEntries[i_0].OpenCloseSettlFlag.len = 0;
            t->GroupMDEntries[i_0].OpenCloseSettlFlag.is_null = 1;
            //printf("t->GroupMDEntries[i_0].OpenCloseSettlFlag = EMPTY \n");
        }
        else
        {
            t->GroupMDEntries[i_0].OpenCloseSettlFlag.len = 0;
            t->GroupMDEntries[i_0].OpenCloseSettlFlag.is_null = 0;
            while (!((packet[(*offset)] & 0x80)))
            {
                t->GroupMDEntries[i_0].OpenCloseSettlFlag.len++;
                (*offset)++;
            }
            packet[*offset] = packet[*offset] & 0x7F;
            (*offset)++;
            t->GroupMDEntries[i_0].OpenCloseSettlFlag.len++;
        }
        //<<<

#ifdef DEBUG

        if (1)
        {

            if (t->GroupMDEntries[i_0].OpenCloseSettlFlag.is_null)
            {
                printf("t->GroupMDEntries[%d].OpenCloseSettlFlag = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
            }
            else
            {
                unsigned char fake[128];
                strncpy(fake, t->GroupMDEntries[i_0].OpenCloseSettlFlag.start, t->GroupMDEntries[i_0].OpenCloseSettlFlag.len);
                fake[t->GroupMDEntries[i_0].OpenCloseSettlFlag.len] = '\0';
                printf("t->GroupMDEntries[%d].OpenCloseSettlFlag = %s%s%s\n", i_0, KMAG, fake, RESET_COLOR);
            }
        }

#endif

#ifdef DEBUG1
        printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
        printf("name = %sOpenCloseSettlFlag%s\n", KRED, RESET_COLOR);
        printf("type = %s nopmap_string_nullable_noop\n%s", KBLU, RESET_COLOR);
        printf("byte_representation: ");
        printf("%s", COLOR_BYTES);
        for (int i = t_GroupMDEntries_i_0_OpenCloseSettlFlag_start; i < *offset; i++)
        {
            printf("%02x ", packet[i]);
        }
        printf("%s\n", RESET_COLOR);

        if (1)
        {

            if (t->GroupMDEntries[i_0].OpenCloseSettlFlag.is_null)
            {
                printf("t->GroupMDEntries[%d].OpenCloseSettlFlag = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
            }
            else
            {
                unsigned char fake[128];
                strncpy(fake, t->GroupMDEntries[i_0].OpenCloseSettlFlag.start, t->GroupMDEntries[i_0].OpenCloseSettlFlag.len);
                fake[t->GroupMDEntries[i_0].OpenCloseSettlFlag.len] = '\0';
                printf("t->GroupMDEntries[%d].OpenCloseSettlFlag = %s%s%s\n", i_0, KMAG, fake, RESET_COLOR);
            }
        }

        printf("\n");
#endif

#ifdef DEBUG3
        getchar();
#endif

        //nopmap_decimal_nullable_noop

//nopmap_int32_nullable_noop NetChgPrevDay
#ifdef DEBUG2
        int t_GroupMDEntries_i_0_NetChgPrevDayexponenta_start = *offset;
#endif

        //>>> NetChgPrevDay
        if (packet[*offset] == 0x80)
        {
            (*offset)++;
            t->GroupMDEntries[i_0].NetChgPrevDay.exponenta.is_null = 1;
        }
        else
        {
            t->GroupMDEntries[i_0].NetChgPrevDay.exponenta.value = 0 - (packet[*offset] & 0x40);
            t->GroupMDEntries[i_0].NetChgPrevDay.exponenta.is_null = 0;
            while (!((packet[*offset] & 0x80)))
            {
                (t->GroupMDEntries[i_0].NetChgPrevDay.exponenta.value) |= packet[(*offset)++];
                (t->GroupMDEntries[i_0].NetChgPrevDay.exponenta.value) <<= 7;
            }
            (t->GroupMDEntries[i_0].NetChgPrevDay.exponenta.value) |= (packet[(*offset)++] & 0x7f);
            if (t->GroupMDEntries[i_0].NetChgPrevDay.exponenta.value > 0)
            {
                (t->GroupMDEntries[i_0].NetChgPrevDay.exponenta.value)--;
            }
        }
        //<<<

#ifdef DEBUG

        if (t->GroupMDEntries[i_0].NetChgPrevDay.exponenta.is_null)
        {
            printf("t->GroupMDEntries[%d].NetChgPrevDay.exponenta = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
        }
        else
        {
            printf("t->GroupMDEntries[%d].NetChgPrevDay.exponenta = %s%d%s\n", i_0, KMAG, t->GroupMDEntries[i_0].NetChgPrevDay.exponenta.value, RESET_COLOR);
        }

#endif

#ifdef DEBUG1
        printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
        printf("name = %sNetChgPrevDay%s\n", KRED, RESET_COLOR);
        printf("type = %snopmap_int32_nullable_noop\n%s", KBLU, RESET_COLOR);
        printf("byte_representation: ");
        printf("%s", COLOR_BYTES);
        for (int i = t_GroupMDEntries_i_0_NetChgPrevDayexponenta_start; i < *offset; i++)
        {
            printf("%02x ", packet[i]);
        }
        printf("%s\n", RESET_COLOR);

        if (t->GroupMDEntries[i_0].NetChgPrevDay.exponenta.is_null)
        {
            printf("t->GroupMDEntries[%d].NetChgPrevDay.exponenta = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
        }
        else
        {
            printf("t->GroupMDEntries[%d].NetChgPrevDay.exponenta = %s%d%s\n", i_0, KMAG, t->GroupMDEntries[i_0].NetChgPrevDay.exponenta.value, RESET_COLOR);
        }

        printf("\n");
#endif

#ifdef DEBUG3
        getchar();
#endif

        if (!t->GroupMDEntries[i_0].NetChgPrevDay.exponenta.is_null)
        {
            //calc mantissa
            //nopmap_int64_nonullable_noop NetChgPrevDay
#ifdef DEBUG2
            int t_GroupMDEntries_i_0_NetChgPrevDaymantissa_start = *offset;
#endif

            //>>> NetChgPrevDay
            t->GroupMDEntries[i_0].NetChgPrevDay.mantissa = 0 - (packet[*offset] & 0x40);
            while (!((packet[*offset] & 0x80)))
            {
                t->GroupMDEntries[i_0].NetChgPrevDay.mantissa |= packet[(*offset)++];
                t->GroupMDEntries[i_0].NetChgPrevDay.mantissa <<= 7;
            }
            t->GroupMDEntries[i_0].NetChgPrevDay.mantissa |= (packet[(*offset)++] & 0x7f);
            //<<<

#ifdef DEBUG
            printf("t->GroupMDEntries[%d].NetChgPrevDay.mantissa = %ld\n", i_0, t->GroupMDEntries[i_0].NetChgPrevDay.mantissa);
#endif

#ifdef DEBUG1
            printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
            printf("name = %sNetChgPrevDay%s\n", KRED, RESET_COLOR);
            printf("type = %snopmap_int64_nonullable_noop\n%s", KBLU, RESET_COLOR);
            printf("byte_representation: ");
            printf("%s", COLOR_BYTES);
            for (int i = t_GroupMDEntries_i_0_NetChgPrevDaymantissa_start; i < *offset; i++)
            {
                printf("%02x ", packet[i]);
            }
            printf("%s\n", RESET_COLOR);
            printf("value = %s%ld%s\n", KMAG, t->GroupMDEntries[i_0].NetChgPrevDay.mantissa, RESET_COLOR);
            printf("\n");
#endif

#ifdef DEBUG3
            getchar();
#endif
        }

        //nopmap_decimal_nullable_noop

//nopmap_int32_nullable_noop AccruedInterestAmt
#ifdef DEBUG2
        int t_GroupMDEntries_i_0_AccruedInterestAmtexponenta_start = *offset;
#endif

        //>>> AccruedInterestAmt
        if (packet[*offset] == 0x80)
        {
            (*offset)++;
            t->GroupMDEntries[i_0].AccruedInterestAmt.exponenta.is_null = 1;
        }
        else
        {
            t->GroupMDEntries[i_0].AccruedInterestAmt.exponenta.value = 0 - (packet[*offset] & 0x40);
            t->GroupMDEntries[i_0].AccruedInterestAmt.exponenta.is_null = 0;
            while (!((packet[*offset] & 0x80)))
            {
                (t->GroupMDEntries[i_0].AccruedInterestAmt.exponenta.value) |= packet[(*offset)++];
                (t->GroupMDEntries[i_0].AccruedInterestAmt.exponenta.value) <<= 7;
            }
            (t->GroupMDEntries[i_0].AccruedInterestAmt.exponenta.value) |= (packet[(*offset)++] & 0x7f);
            if (t->GroupMDEntries[i_0].AccruedInterestAmt.exponenta.value > 0)
            {
                (t->GroupMDEntries[i_0].AccruedInterestAmt.exponenta.value)--;
            }
        }
        //<<<

#ifdef DEBUG

        if (t->GroupMDEntries[i_0].AccruedInterestAmt.exponenta.is_null)
        {
            printf("t->GroupMDEntries[%d].AccruedInterestAmt.exponenta = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
        }
        else
        {
            printf("t->GroupMDEntries[%d].AccruedInterestAmt.exponenta = %s%d%s\n", i_0, KMAG, t->GroupMDEntries[i_0].AccruedInterestAmt.exponenta.value, RESET_COLOR);
        }

#endif

#ifdef DEBUG1
        printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
        printf("name = %sAccruedInterestAmt%s\n", KRED, RESET_COLOR);
        printf("type = %snopmap_int32_nullable_noop\n%s", KBLU, RESET_COLOR);
        printf("byte_representation: ");
        printf("%s", COLOR_BYTES);
        for (int i = t_GroupMDEntries_i_0_AccruedInterestAmtexponenta_start; i < *offset; i++)
        {
            printf("%02x ", packet[i]);
        }
        printf("%s\n", RESET_COLOR);

        if (t->GroupMDEntries[i_0].AccruedInterestAmt.exponenta.is_null)
        {
            printf("t->GroupMDEntries[%d].AccruedInterestAmt.exponenta = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
        }
        else
        {
            printf("t->GroupMDEntries[%d].AccruedInterestAmt.exponenta = %s%d%s\n", i_0, KMAG, t->GroupMDEntries[i_0].AccruedInterestAmt.exponenta.value, RESET_COLOR);
        }

        printf("\n");
#endif

#ifdef DEBUG3
        getchar();
#endif

        if (!t->GroupMDEntries[i_0].AccruedInterestAmt.exponenta.is_null)
        {
            //calc mantissa
            //nopmap_int64_nonullable_noop AccruedInterestAmt
#ifdef DEBUG2
            int t_GroupMDEntries_i_0_AccruedInterestAmtmantissa_start = *offset;
#endif

            //>>> AccruedInterestAmt
            t->GroupMDEntries[i_0].AccruedInterestAmt.mantissa = 0 - (packet[*offset] & 0x40);
            while (!((packet[*offset] & 0x80)))
            {
                t->GroupMDEntries[i_0].AccruedInterestAmt.mantissa |= packet[(*offset)++];
                t->GroupMDEntries[i_0].AccruedInterestAmt.mantissa <<= 7;
            }
            t->GroupMDEntries[i_0].AccruedInterestAmt.mantissa |= (packet[(*offset)++] & 0x7f);
            //<<<

#ifdef DEBUG
            printf("t->GroupMDEntries[%d].AccruedInterestAmt.mantissa = %ld\n", i_0, t->GroupMDEntries[i_0].AccruedInterestAmt.mantissa);
#endif

#ifdef DEBUG1
            printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
            printf("name = %sAccruedInterestAmt%s\n", KRED, RESET_COLOR);
            printf("type = %snopmap_int64_nonullable_noop\n%s", KBLU, RESET_COLOR);
            printf("byte_representation: ");
            printf("%s", COLOR_BYTES);
            for (int i = t_GroupMDEntries_i_0_AccruedInterestAmtmantissa_start; i < *offset; i++)
            {
                printf("%02x ", packet[i]);
            }
            printf("%s\n", RESET_COLOR);
            printf("value = %s%ld%s\n", KMAG, t->GroupMDEntries[i_0].AccruedInterestAmt.mantissa, RESET_COLOR);
            printf("\n");
#endif

#ifdef DEBUG3
            getchar();
#endif
        }

        //nopmap_decimal_nullable_noop

//nopmap_int32_nullable_noop ChgFromWAPrice
#ifdef DEBUG2
        int t_GroupMDEntries_i_0_ChgFromWAPriceexponenta_start = *offset;
#endif

        //>>> ChgFromWAPrice
        if (packet[*offset] == 0x80)
        {
            (*offset)++;
            t->GroupMDEntries[i_0].ChgFromWAPrice.exponenta.is_null = 1;
        }
        else
        {
            t->GroupMDEntries[i_0].ChgFromWAPrice.exponenta.value = 0 - (packet[*offset] & 0x40);
            t->GroupMDEntries[i_0].ChgFromWAPrice.exponenta.is_null = 0;
            while (!((packet[*offset] & 0x80)))
            {
                (t->GroupMDEntries[i_0].ChgFromWAPrice.exponenta.value) |= packet[(*offset)++];
                (t->GroupMDEntries[i_0].ChgFromWAPrice.exponenta.value) <<= 7;
            }
            (t->GroupMDEntries[i_0].ChgFromWAPrice.exponenta.value) |= (packet[(*offset)++] & 0x7f);
            if (t->GroupMDEntries[i_0].ChgFromWAPrice.exponenta.value > 0)
            {
                (t->GroupMDEntries[i_0].ChgFromWAPrice.exponenta.value)--;
            }
        }
        //<<<

#ifdef DEBUG

        if (t->GroupMDEntries[i_0].ChgFromWAPrice.exponenta.is_null)
        {
            printf("t->GroupMDEntries[%d].ChgFromWAPrice.exponenta = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
        }
        else
        {
            printf("t->GroupMDEntries[%d].ChgFromWAPrice.exponenta = %s%d%s\n", i_0, KMAG, t->GroupMDEntries[i_0].ChgFromWAPrice.exponenta.value, RESET_COLOR);
        }

#endif

#ifdef DEBUG1
        printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
        printf("name = %sChgFromWAPrice%s\n", KRED, RESET_COLOR);
        printf("type = %snopmap_int32_nullable_noop\n%s", KBLU, RESET_COLOR);
        printf("byte_representation: ");
        printf("%s", COLOR_BYTES);
        for (int i = t_GroupMDEntries_i_0_ChgFromWAPriceexponenta_start; i < *offset; i++)
        {
            printf("%02x ", packet[i]);
        }
        printf("%s\n", RESET_COLOR);

        if (t->GroupMDEntries[i_0].ChgFromWAPrice.exponenta.is_null)
        {
            printf("t->GroupMDEntries[%d].ChgFromWAPrice.exponenta = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
        }
        else
        {
            printf("t->GroupMDEntries[%d].ChgFromWAPrice.exponenta = %s%d%s\n", i_0, KMAG, t->GroupMDEntries[i_0].ChgFromWAPrice.exponenta.value, RESET_COLOR);
        }

        printf("\n");
#endif

#ifdef DEBUG3
        getchar();
#endif

        if (!t->GroupMDEntries[i_0].ChgFromWAPrice.exponenta.is_null)
        {
            //calc mantissa
            //nopmap_int64_nonullable_noop ChgFromWAPrice
#ifdef DEBUG2
            int t_GroupMDEntries_i_0_ChgFromWAPricemantissa_start = *offset;
#endif

            //>>> ChgFromWAPrice
            t->GroupMDEntries[i_0].ChgFromWAPrice.mantissa = 0 - (packet[*offset] & 0x40);
            while (!((packet[*offset] & 0x80)))
            {
                t->GroupMDEntries[i_0].ChgFromWAPrice.mantissa |= packet[(*offset)++];
                t->GroupMDEntries[i_0].ChgFromWAPrice.mantissa <<= 7;
            }
            t->GroupMDEntries[i_0].ChgFromWAPrice.mantissa |= (packet[(*offset)++] & 0x7f);
            //<<<

#ifdef DEBUG
            printf("t->GroupMDEntries[%d].ChgFromWAPrice.mantissa = %ld\n", i_0, t->GroupMDEntries[i_0].ChgFromWAPrice.mantissa);
#endif

#ifdef DEBUG1
            printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
            printf("name = %sChgFromWAPrice%s\n", KRED, RESET_COLOR);
            printf("type = %snopmap_int64_nonullable_noop\n%s", KBLU, RESET_COLOR);
            printf("byte_representation: ");
            printf("%s", COLOR_BYTES);
            for (int i = t_GroupMDEntries_i_0_ChgFromWAPricemantissa_start; i < *offset; i++)
            {
                printf("%02x ", packet[i]);
            }
            printf("%s\n", RESET_COLOR);
            printf("value = %s%ld%s\n", KMAG, t->GroupMDEntries[i_0].ChgFromWAPrice.mantissa, RESET_COLOR);
            printf("\n");
#endif

#ifdef DEBUG3
            getchar();
#endif
        }

        //nopmap_decimal_nullable_noop

//nopmap_int32_nullable_noop ChgOpenInterest
#ifdef DEBUG2
        int t_GroupMDEntries_i_0_ChgOpenInterestexponenta_start = *offset;
#endif

        //>>> ChgOpenInterest
        if (packet[*offset] == 0x80)
        {
            (*offset)++;
            t->GroupMDEntries[i_0].ChgOpenInterest.exponenta.is_null = 1;
        }
        else
        {
            t->GroupMDEntries[i_0].ChgOpenInterest.exponenta.value = 0 - (packet[*offset] & 0x40);
            t->GroupMDEntries[i_0].ChgOpenInterest.exponenta.is_null = 0;
            while (!((packet[*offset] & 0x80)))
            {
                (t->GroupMDEntries[i_0].ChgOpenInterest.exponenta.value) |= packet[(*offset)++];
                (t->GroupMDEntries[i_0].ChgOpenInterest.exponenta.value) <<= 7;
            }
            (t->GroupMDEntries[i_0].ChgOpenInterest.exponenta.value) |= (packet[(*offset)++] & 0x7f);
            if (t->GroupMDEntries[i_0].ChgOpenInterest.exponenta.value > 0)
            {
                (t->GroupMDEntries[i_0].ChgOpenInterest.exponenta.value)--;
            }
        }
        //<<<

#ifdef DEBUG

        if (t->GroupMDEntries[i_0].ChgOpenInterest.exponenta.is_null)
        {
            printf("t->GroupMDEntries[%d].ChgOpenInterest.exponenta = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
        }
        else
        {
            printf("t->GroupMDEntries[%d].ChgOpenInterest.exponenta = %s%d%s\n", i_0, KMAG, t->GroupMDEntries[i_0].ChgOpenInterest.exponenta.value, RESET_COLOR);
        }

#endif

#ifdef DEBUG1
        printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
        printf("name = %sChgOpenInterest%s\n", KRED, RESET_COLOR);
        printf("type = %snopmap_int32_nullable_noop\n%s", KBLU, RESET_COLOR);
        printf("byte_representation: ");
        printf("%s", COLOR_BYTES);
        for (int i = t_GroupMDEntries_i_0_ChgOpenInterestexponenta_start; i < *offset; i++)
        {
            printf("%02x ", packet[i]);
        }
        printf("%s\n", RESET_COLOR);

        if (t->GroupMDEntries[i_0].ChgOpenInterest.exponenta.is_null)
        {
            printf("t->GroupMDEntries[%d].ChgOpenInterest.exponenta = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
        }
        else
        {
            printf("t->GroupMDEntries[%d].ChgOpenInterest.exponenta = %s%d%s\n", i_0, KMAG, t->GroupMDEntries[i_0].ChgOpenInterest.exponenta.value, RESET_COLOR);
        }

        printf("\n");
#endif

#ifdef DEBUG3
        getchar();
#endif

        if (!t->GroupMDEntries[i_0].ChgOpenInterest.exponenta.is_null)
        {
            //calc mantissa
            //nopmap_int64_nonullable_noop ChgOpenInterest
#ifdef DEBUG2
            int t_GroupMDEntries_i_0_ChgOpenInterestmantissa_start = *offset;
#endif

            //>>> ChgOpenInterest
            t->GroupMDEntries[i_0].ChgOpenInterest.mantissa = 0 - (packet[*offset] & 0x40);
            while (!((packet[*offset] & 0x80)))
            {
                t->GroupMDEntries[i_0].ChgOpenInterest.mantissa |= packet[(*offset)++];
                t->GroupMDEntries[i_0].ChgOpenInterest.mantissa <<= 7;
            }
            t->GroupMDEntries[i_0].ChgOpenInterest.mantissa |= (packet[(*offset)++] & 0x7f);
            //<<<

#ifdef DEBUG
            printf("t->GroupMDEntries[%d].ChgOpenInterest.mantissa = %ld\n", i_0, t->GroupMDEntries[i_0].ChgOpenInterest.mantissa);
#endif

#ifdef DEBUG1
            printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
            printf("name = %sChgOpenInterest%s\n", KRED, RESET_COLOR);
            printf("type = %snopmap_int64_nonullable_noop\n%s", KBLU, RESET_COLOR);
            printf("byte_representation: ");
            printf("%s", COLOR_BYTES);
            for (int i = t_GroupMDEntries_i_0_ChgOpenInterestmantissa_start; i < *offset; i++)
            {
                printf("%02x ", packet[i]);
            }
            printf("%s\n", RESET_COLOR);
            printf("value = %s%ld%s\n", KMAG, t->GroupMDEntries[i_0].ChgOpenInterest.mantissa, RESET_COLOR);
            printf("\n");
#endif

#ifdef DEBUG3
            getchar();
#endif
        }

        //nopmap_decimal_nullable_noop

//nopmap_int32_nullable_noop BidMarketSize
#ifdef DEBUG2
        int t_GroupMDEntries_i_0_BidMarketSizeexponenta_start = *offset;
#endif

        //>>> BidMarketSize
        if (packet[*offset] == 0x80)
        {
            (*offset)++;
            t->GroupMDEntries[i_0].BidMarketSize.exponenta.is_null = 1;
        }
        else
        {
            t->GroupMDEntries[i_0].BidMarketSize.exponenta.value = 0 - (packet[*offset] & 0x40);
            t->GroupMDEntries[i_0].BidMarketSize.exponenta.is_null = 0;
            while (!((packet[*offset] & 0x80)))
            {
                (t->GroupMDEntries[i_0].BidMarketSize.exponenta.value) |= packet[(*offset)++];
                (t->GroupMDEntries[i_0].BidMarketSize.exponenta.value) <<= 7;
            }
            (t->GroupMDEntries[i_0].BidMarketSize.exponenta.value) |= (packet[(*offset)++] & 0x7f);
            if (t->GroupMDEntries[i_0].BidMarketSize.exponenta.value > 0)
            {
                (t->GroupMDEntries[i_0].BidMarketSize.exponenta.value)--;
            }
        }
        //<<<

#ifdef DEBUG

        if (t->GroupMDEntries[i_0].BidMarketSize.exponenta.is_null)
        {
            printf("t->GroupMDEntries[%d].BidMarketSize.exponenta = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
        }
        else
        {
            printf("t->GroupMDEntries[%d].BidMarketSize.exponenta = %s%d%s\n", i_0, KMAG, t->GroupMDEntries[i_0].BidMarketSize.exponenta.value, RESET_COLOR);
        }

#endif

#ifdef DEBUG1
        printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
        printf("name = %sBidMarketSize%s\n", KRED, RESET_COLOR);
        printf("type = %snopmap_int32_nullable_noop\n%s", KBLU, RESET_COLOR);
        printf("byte_representation: ");
        printf("%s", COLOR_BYTES);
        for (int i = t_GroupMDEntries_i_0_BidMarketSizeexponenta_start; i < *offset; i++)
        {
            printf("%02x ", packet[i]);
        }
        printf("%s\n", RESET_COLOR);

        if (t->GroupMDEntries[i_0].BidMarketSize.exponenta.is_null)
        {
            printf("t->GroupMDEntries[%d].BidMarketSize.exponenta = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
        }
        else
        {
            printf("t->GroupMDEntries[%d].BidMarketSize.exponenta = %s%d%s\n", i_0, KMAG, t->GroupMDEntries[i_0].BidMarketSize.exponenta.value, RESET_COLOR);
        }

        printf("\n");
#endif

#ifdef DEBUG3
        getchar();
#endif

        if (!t->GroupMDEntries[i_0].BidMarketSize.exponenta.is_null)
        {
            //calc mantissa
            //nopmap_int64_nonullable_noop BidMarketSize
#ifdef DEBUG2
            int t_GroupMDEntries_i_0_BidMarketSizemantissa_start = *offset;
#endif

            //>>> BidMarketSize
            t->GroupMDEntries[i_0].BidMarketSize.mantissa = 0 - (packet[*offset] & 0x40);
            while (!((packet[*offset] & 0x80)))
            {
                t->GroupMDEntries[i_0].BidMarketSize.mantissa |= packet[(*offset)++];
                t->GroupMDEntries[i_0].BidMarketSize.mantissa <<= 7;
            }
            t->GroupMDEntries[i_0].BidMarketSize.mantissa |= (packet[(*offset)++] & 0x7f);
            //<<<

#ifdef DEBUG
            printf("t->GroupMDEntries[%d].BidMarketSize.mantissa = %ld\n", i_0, t->GroupMDEntries[i_0].BidMarketSize.mantissa);
#endif

#ifdef DEBUG1
            printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
            printf("name = %sBidMarketSize%s\n", KRED, RESET_COLOR);
            printf("type = %snopmap_int64_nonullable_noop\n%s", KBLU, RESET_COLOR);
            printf("byte_representation: ");
            printf("%s", COLOR_BYTES);
            for (int i = t_GroupMDEntries_i_0_BidMarketSizemantissa_start; i < *offset; i++)
            {
                printf("%02x ", packet[i]);
            }
            printf("%s\n", RESET_COLOR);
            printf("value = %s%ld%s\n", KMAG, t->GroupMDEntries[i_0].BidMarketSize.mantissa, RESET_COLOR);
            printf("\n");
#endif

#ifdef DEBUG3
            getchar();
#endif
        }

        //nopmap_decimal_nullable_noop

//nopmap_int32_nullable_noop AskMarketSize
#ifdef DEBUG2
        int t_GroupMDEntries_i_0_AskMarketSizeexponenta_start = *offset;
#endif

        //>>> AskMarketSize
        if (packet[*offset] == 0x80)
        {
            (*offset)++;
            t->GroupMDEntries[i_0].AskMarketSize.exponenta.is_null = 1;
        }
        else
        {
            t->GroupMDEntries[i_0].AskMarketSize.exponenta.value = 0 - (packet[*offset] & 0x40);
            t->GroupMDEntries[i_0].AskMarketSize.exponenta.is_null = 0;
            while (!((packet[*offset] & 0x80)))
            {
                (t->GroupMDEntries[i_0].AskMarketSize.exponenta.value) |= packet[(*offset)++];
                (t->GroupMDEntries[i_0].AskMarketSize.exponenta.value) <<= 7;
            }
            (t->GroupMDEntries[i_0].AskMarketSize.exponenta.value) |= (packet[(*offset)++] & 0x7f);
            if (t->GroupMDEntries[i_0].AskMarketSize.exponenta.value > 0)
            {
                (t->GroupMDEntries[i_0].AskMarketSize.exponenta.value)--;
            }
        }
        //<<<

#ifdef DEBUG

        if (t->GroupMDEntries[i_0].AskMarketSize.exponenta.is_null)
        {
            printf("t->GroupMDEntries[%d].AskMarketSize.exponenta = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
        }
        else
        {
            printf("t->GroupMDEntries[%d].AskMarketSize.exponenta = %s%d%s\n", i_0, KMAG, t->GroupMDEntries[i_0].AskMarketSize.exponenta.value, RESET_COLOR);
        }

#endif

#ifdef DEBUG1
        printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
        printf("name = %sAskMarketSize%s\n", KRED, RESET_COLOR);
        printf("type = %snopmap_int32_nullable_noop\n%s", KBLU, RESET_COLOR);
        printf("byte_representation: ");
        printf("%s", COLOR_BYTES);
        for (int i = t_GroupMDEntries_i_0_AskMarketSizeexponenta_start; i < *offset; i++)
        {
            printf("%02x ", packet[i]);
        }
        printf("%s\n", RESET_COLOR);

        if (t->GroupMDEntries[i_0].AskMarketSize.exponenta.is_null)
        {
            printf("t->GroupMDEntries[%d].AskMarketSize.exponenta = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
        }
        else
        {
            printf("t->GroupMDEntries[%d].AskMarketSize.exponenta = %s%d%s\n", i_0, KMAG, t->GroupMDEntries[i_0].AskMarketSize.exponenta.value, RESET_COLOR);
        }

        printf("\n");
#endif

#ifdef DEBUG3
        getchar();
#endif

        if (!t->GroupMDEntries[i_0].AskMarketSize.exponenta.is_null)
        {
            //calc mantissa
            //nopmap_int64_nonullable_noop AskMarketSize
#ifdef DEBUG2
            int t_GroupMDEntries_i_0_AskMarketSizemantissa_start = *offset;
#endif

            //>>> AskMarketSize
            t->GroupMDEntries[i_0].AskMarketSize.mantissa = 0 - (packet[*offset] & 0x40);
            while (!((packet[*offset] & 0x80)))
            {
                t->GroupMDEntries[i_0].AskMarketSize.mantissa |= packet[(*offset)++];
                t->GroupMDEntries[i_0].AskMarketSize.mantissa <<= 7;
            }
            t->GroupMDEntries[i_0].AskMarketSize.mantissa |= (packet[(*offset)++] & 0x7f);
            //<<<

#ifdef DEBUG
            printf("t->GroupMDEntries[%d].AskMarketSize.mantissa = %ld\n", i_0, t->GroupMDEntries[i_0].AskMarketSize.mantissa);
#endif

#ifdef DEBUG1
            printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
            printf("name = %sAskMarketSize%s\n", KRED, RESET_COLOR);
            printf("type = %snopmap_int64_nonullable_noop\n%s", KBLU, RESET_COLOR);
            printf("byte_representation: ");
            printf("%s", COLOR_BYTES);
            for (int i = t_GroupMDEntries_i_0_AskMarketSizemantissa_start; i < *offset; i++)
            {
                printf("%02x ", packet[i]);
            }
            printf("%s\n", RESET_COLOR);
            printf("value = %s%ld%s\n", KMAG, t->GroupMDEntries[i_0].AskMarketSize.mantissa, RESET_COLOR);
            printf("\n");
#endif

#ifdef DEBUG3
            getchar();
#endif
        }

//nopmap_int32_nullable_noop TotalNumOfTrades
#ifdef DEBUG2
        int t_GroupMDEntries_i_0_TotalNumOfTrades_start = *offset;
#endif

        //>>> TotalNumOfTrades
        if (packet[*offset] == 0x80)
        {
            (*offset)++;
            t->GroupMDEntries[i_0].TotalNumOfTrades.is_null = 1;
        }
        else
        {
            t->GroupMDEntries[i_0].TotalNumOfTrades.value = 0 - (packet[*offset] & 0x40);
            t->GroupMDEntries[i_0].TotalNumOfTrades.is_null = 0;
            while (!((packet[*offset] & 0x80)))
            {
                (t->GroupMDEntries[i_0].TotalNumOfTrades.value) |= packet[(*offset)++];
                (t->GroupMDEntries[i_0].TotalNumOfTrades.value) <<= 7;
            }
            (t->GroupMDEntries[i_0].TotalNumOfTrades.value) |= (packet[(*offset)++] & 0x7f);
            if (t->GroupMDEntries[i_0].TotalNumOfTrades.value > 0)
            {
                (t->GroupMDEntries[i_0].TotalNumOfTrades.value)--;
            }
        }
        //<<<

#ifdef DEBUG

        if (t->GroupMDEntries[i_0].TotalNumOfTrades.is_null)
        {
            printf("t->GroupMDEntries[%d].TotalNumOfTrades = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
        }
        else
        {
            printf("t->GroupMDEntries[%d].TotalNumOfTrades = %s%d%s\n", i_0, KMAG, t->GroupMDEntries[i_0].TotalNumOfTrades.value, RESET_COLOR);
        }

#endif

#ifdef DEBUG1
        printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
        printf("name = %sTotalNumOfTrades%s\n", KRED, RESET_COLOR);
        printf("type = %snopmap_int32_nullable_noop\n%s", KBLU, RESET_COLOR);
        printf("byte_representation: ");
        printf("%s", COLOR_BYTES);
        for (int i = t_GroupMDEntries_i_0_TotalNumOfTrades_start; i < *offset; i++)
        {
            printf("%02x ", packet[i]);
        }
        printf("%s\n", RESET_COLOR);

        if (t->GroupMDEntries[i_0].TotalNumOfTrades.is_null)
        {
            printf("t->GroupMDEntries[%d].TotalNumOfTrades = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
        }
        else
        {
            printf("t->GroupMDEntries[%d].TotalNumOfTrades = %s%d%s\n", i_0, KMAG, t->GroupMDEntries[i_0].TotalNumOfTrades.value, RESET_COLOR);
        }

        printf("\n");
#endif

#ifdef DEBUG3
        getchar();
#endif

        //nopmap_decimal_nullable_noop

//nopmap_int32_nullable_noop TradeValue
#ifdef DEBUG2
        int t_GroupMDEntries_i_0_TradeValueexponenta_start = *offset;
#endif

        //>>> TradeValue
        if (packet[*offset] == 0x80)
        {
            (*offset)++;
            t->GroupMDEntries[i_0].TradeValue.exponenta.is_null = 1;
        }
        else
        {
            t->GroupMDEntries[i_0].TradeValue.exponenta.value = 0 - (packet[*offset] & 0x40);
            t->GroupMDEntries[i_0].TradeValue.exponenta.is_null = 0;
            while (!((packet[*offset] & 0x80)))
            {
                (t->GroupMDEntries[i_0].TradeValue.exponenta.value) |= packet[(*offset)++];
                (t->GroupMDEntries[i_0].TradeValue.exponenta.value) <<= 7;
            }
            (t->GroupMDEntries[i_0].TradeValue.exponenta.value) |= (packet[(*offset)++] & 0x7f);
            if (t->GroupMDEntries[i_0].TradeValue.exponenta.value > 0)
            {
                (t->GroupMDEntries[i_0].TradeValue.exponenta.value)--;
            }
        }
        //<<<

#ifdef DEBUG

        if (t->GroupMDEntries[i_0].TradeValue.exponenta.is_null)
        {
            printf("t->GroupMDEntries[%d].TradeValue.exponenta = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
        }
        else
        {
            printf("t->GroupMDEntries[%d].TradeValue.exponenta = %s%d%s\n", i_0, KMAG, t->GroupMDEntries[i_0].TradeValue.exponenta.value, RESET_COLOR);
        }

#endif

#ifdef DEBUG1
        printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
        printf("name = %sTradeValue%s\n", KRED, RESET_COLOR);
        printf("type = %snopmap_int32_nullable_noop\n%s", KBLU, RESET_COLOR);
        printf("byte_representation: ");
        printf("%s", COLOR_BYTES);
        for (int i = t_GroupMDEntries_i_0_TradeValueexponenta_start; i < *offset; i++)
        {
            printf("%02x ", packet[i]);
        }
        printf("%s\n", RESET_COLOR);

        if (t->GroupMDEntries[i_0].TradeValue.exponenta.is_null)
        {
            printf("t->GroupMDEntries[%d].TradeValue.exponenta = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
        }
        else
        {
            printf("t->GroupMDEntries[%d].TradeValue.exponenta = %s%d%s\n", i_0, KMAG, t->GroupMDEntries[i_0].TradeValue.exponenta.value, RESET_COLOR);
        }

        printf("\n");
#endif

#ifdef DEBUG3
        getchar();
#endif

        if (!t->GroupMDEntries[i_0].TradeValue.exponenta.is_null)
        {
            //calc mantissa
            //nopmap_int64_nonullable_noop TradeValue
#ifdef DEBUG2
            int t_GroupMDEntries_i_0_TradeValuemantissa_start = *offset;
#endif

            //>>> TradeValue
            t->GroupMDEntries[i_0].TradeValue.mantissa = 0 - (packet[*offset] & 0x40);
            while (!((packet[*offset] & 0x80)))
            {
                t->GroupMDEntries[i_0].TradeValue.mantissa |= packet[(*offset)++];
                t->GroupMDEntries[i_0].TradeValue.mantissa <<= 7;
            }
            t->GroupMDEntries[i_0].TradeValue.mantissa |= (packet[(*offset)++] & 0x7f);
            //<<<

#ifdef DEBUG
            printf("t->GroupMDEntries[%d].TradeValue.mantissa = %ld\n", i_0, t->GroupMDEntries[i_0].TradeValue.mantissa);
#endif

#ifdef DEBUG1
            printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
            printf("name = %sTradeValue%s\n", KRED, RESET_COLOR);
            printf("type = %snopmap_int64_nonullable_noop\n%s", KBLU, RESET_COLOR);
            printf("byte_representation: ");
            printf("%s", COLOR_BYTES);
            for (int i = t_GroupMDEntries_i_0_TradeValuemantissa_start; i < *offset; i++)
            {
                printf("%02x ", packet[i]);
            }
            printf("%s\n", RESET_COLOR);
            printf("value = %s%ld%s\n", KMAG, t->GroupMDEntries[i_0].TradeValue.mantissa, RESET_COLOR);
            printf("\n");
#endif

#ifdef DEBUG3
            getchar();
#endif
        }

        //nopmap_decimal_nullable_noop

//nopmap_int32_nullable_noop Yield
#ifdef DEBUG2
        int t_GroupMDEntries_i_0_Yieldexponenta_start = *offset;
#endif

        //>>> Yield
        if (packet[*offset] == 0x80)
        {
            (*offset)++;
            t->GroupMDEntries[i_0].Yield.exponenta.is_null = 1;
        }
        else
        {
            t->GroupMDEntries[i_0].Yield.exponenta.value = 0 - (packet[*offset] & 0x40);
            t->GroupMDEntries[i_0].Yield.exponenta.is_null = 0;
            while (!((packet[*offset] & 0x80)))
            {
                (t->GroupMDEntries[i_0].Yield.exponenta.value) |= packet[(*offset)++];
                (t->GroupMDEntries[i_0].Yield.exponenta.value) <<= 7;
            }
            (t->GroupMDEntries[i_0].Yield.exponenta.value) |= (packet[(*offset)++] & 0x7f);
            if (t->GroupMDEntries[i_0].Yield.exponenta.value > 0)
            {
                (t->GroupMDEntries[i_0].Yield.exponenta.value)--;
            }
        }
        //<<<

#ifdef DEBUG

        if (t->GroupMDEntries[i_0].Yield.exponenta.is_null)
        {
            printf("t->GroupMDEntries[%d].Yield.exponenta = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
        }
        else
        {
            printf("t->GroupMDEntries[%d].Yield.exponenta = %s%d%s\n", i_0, KMAG, t->GroupMDEntries[i_0].Yield.exponenta.value, RESET_COLOR);
        }

#endif

#ifdef DEBUG1
        printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
        printf("name = %sYield%s\n", KRED, RESET_COLOR);
        printf("type = %snopmap_int32_nullable_noop\n%s", KBLU, RESET_COLOR);
        printf("byte_representation: ");
        printf("%s", COLOR_BYTES);
        for (int i = t_GroupMDEntries_i_0_Yieldexponenta_start; i < *offset; i++)
        {
            printf("%02x ", packet[i]);
        }
        printf("%s\n", RESET_COLOR);

        if (t->GroupMDEntries[i_0].Yield.exponenta.is_null)
        {
            printf("t->GroupMDEntries[%d].Yield.exponenta = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
        }
        else
        {
            printf("t->GroupMDEntries[%d].Yield.exponenta = %s%d%s\n", i_0, KMAG, t->GroupMDEntries[i_0].Yield.exponenta.value, RESET_COLOR);
        }

        printf("\n");
#endif

#ifdef DEBUG3
        getchar();
#endif

        if (!t->GroupMDEntries[i_0].Yield.exponenta.is_null)
        {
            //calc mantissa
            //nopmap_int64_nonullable_noop Yield
#ifdef DEBUG2
            int t_GroupMDEntries_i_0_Yieldmantissa_start = *offset;
#endif

            //>>> Yield
            t->GroupMDEntries[i_0].Yield.mantissa = 0 - (packet[*offset] & 0x40);
            while (!((packet[*offset] & 0x80)))
            {
                t->GroupMDEntries[i_0].Yield.mantissa |= packet[(*offset)++];
                t->GroupMDEntries[i_0].Yield.mantissa <<= 7;
            }
            t->GroupMDEntries[i_0].Yield.mantissa |= (packet[(*offset)++] & 0x7f);
            //<<<

#ifdef DEBUG
            printf("t->GroupMDEntries[%d].Yield.mantissa = %ld\n", i_0, t->GroupMDEntries[i_0].Yield.mantissa);
#endif

#ifdef DEBUG1
            printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
            printf("name = %sYield%s\n", KRED, RESET_COLOR);
            printf("type = %snopmap_int64_nonullable_noop\n%s", KBLU, RESET_COLOR);
            printf("byte_representation: ");
            printf("%s", COLOR_BYTES);
            for (int i = t_GroupMDEntries_i_0_Yieldmantissa_start; i < *offset; i++)
            {
                printf("%02x ", packet[i]);
            }
            printf("%s\n", RESET_COLOR);
            printf("value = %s%ld%s\n", KMAG, t->GroupMDEntries[i_0].Yield.mantissa, RESET_COLOR);
            printf("\n");
#endif

#ifdef DEBUG3
            getchar();
#endif
        }

//nopmap_int32_nullable_noop OfferNbOr
#ifdef DEBUG2
        int t_GroupMDEntries_i_0_OfferNbOr_start = *offset;
#endif

        //>>> OfferNbOr
        if (packet[*offset] == 0x80)
        {
            (*offset)++;
            t->GroupMDEntries[i_0].OfferNbOr.is_null = 1;
        }
        else
        {
            t->GroupMDEntries[i_0].OfferNbOr.value = 0 - (packet[*offset] & 0x40);
            t->GroupMDEntries[i_0].OfferNbOr.is_null = 0;
            while (!((packet[*offset] & 0x80)))
            {
                (t->GroupMDEntries[i_0].OfferNbOr.value) |= packet[(*offset)++];
                (t->GroupMDEntries[i_0].OfferNbOr.value) <<= 7;
            }
            (t->GroupMDEntries[i_0].OfferNbOr.value) |= (packet[(*offset)++] & 0x7f);
            if (t->GroupMDEntries[i_0].OfferNbOr.value > 0)
            {
                (t->GroupMDEntries[i_0].OfferNbOr.value)--;
            }
        }
        //<<<

#ifdef DEBUG

        if (t->GroupMDEntries[i_0].OfferNbOr.is_null)
        {
            printf("t->GroupMDEntries[%d].OfferNbOr = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
        }
        else
        {
            printf("t->GroupMDEntries[%d].OfferNbOr = %s%d%s\n", i_0, KMAG, t->GroupMDEntries[i_0].OfferNbOr.value, RESET_COLOR);
        }

#endif

#ifdef DEBUG1
        printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
        printf("name = %sOfferNbOr%s\n", KRED, RESET_COLOR);
        printf("type = %snopmap_int32_nullable_noop\n%s", KBLU, RESET_COLOR);
        printf("byte_representation: ");
        printf("%s", COLOR_BYTES);
        for (int i = t_GroupMDEntries_i_0_OfferNbOr_start; i < *offset; i++)
        {
            printf("%02x ", packet[i]);
        }
        printf("%s\n", RESET_COLOR);

        if (t->GroupMDEntries[i_0].OfferNbOr.is_null)
        {
            printf("t->GroupMDEntries[%d].OfferNbOr = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
        }
        else
        {
            printf("t->GroupMDEntries[%d].OfferNbOr = %s%d%s\n", i_0, KMAG, t->GroupMDEntries[i_0].OfferNbOr.value, RESET_COLOR);
        }

        printf("\n");
#endif

#ifdef DEBUG3
        getchar();
#endif

//nopmap_int32_nullable_noop BidNbOr
#ifdef DEBUG2
        int t_GroupMDEntries_i_0_BidNbOr_start = *offset;
#endif

        //>>> BidNbOr
        if (packet[*offset] == 0x80)
        {
            (*offset)++;
            t->GroupMDEntries[i_0].BidNbOr.is_null = 1;
        }
        else
        {
            t->GroupMDEntries[i_0].BidNbOr.value = 0 - (packet[*offset] & 0x40);
            t->GroupMDEntries[i_0].BidNbOr.is_null = 0;
            while (!((packet[*offset] & 0x80)))
            {
                (t->GroupMDEntries[i_0].BidNbOr.value) |= packet[(*offset)++];
                (t->GroupMDEntries[i_0].BidNbOr.value) <<= 7;
            }
            (t->GroupMDEntries[i_0].BidNbOr.value) |= (packet[(*offset)++] & 0x7f);
            if (t->GroupMDEntries[i_0].BidNbOr.value > 0)
            {
                (t->GroupMDEntries[i_0].BidNbOr.value)--;
            }
        }
        //<<<

#ifdef DEBUG

        if (t->GroupMDEntries[i_0].BidNbOr.is_null)
        {
            printf("t->GroupMDEntries[%d].BidNbOr = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
        }
        else
        {
            printf("t->GroupMDEntries[%d].BidNbOr = %s%d%s\n", i_0, KMAG, t->GroupMDEntries[i_0].BidNbOr.value, RESET_COLOR);
        }

#endif

#ifdef DEBUG1
        printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
        printf("name = %sBidNbOr%s\n", KRED, RESET_COLOR);
        printf("type = %snopmap_int32_nullable_noop\n%s", KBLU, RESET_COLOR);
        printf("byte_representation: ");
        printf("%s", COLOR_BYTES);
        for (int i = t_GroupMDEntries_i_0_BidNbOr_start; i < *offset; i++)
        {
            printf("%02x ", packet[i]);
        }
        printf("%s\n", RESET_COLOR);

        if (t->GroupMDEntries[i_0].BidNbOr.is_null)
        {
            printf("t->GroupMDEntries[%d].BidNbOr = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
        }
        else
        {
            printf("t->GroupMDEntries[%d].BidNbOr = %s%d%s\n", i_0, KMAG, t->GroupMDEntries[i_0].BidNbOr.value, RESET_COLOR);
        }

        printf("\n");
#endif

#ifdef DEBUG3
        getchar();
#endif

        //nopmap_decimal_nullable_noop

//nopmap_int32_nullable_noop ChgFromSettlmnt
#ifdef DEBUG2
        int t_GroupMDEntries_i_0_ChgFromSettlmntexponenta_start = *offset;
#endif

        //>>> ChgFromSettlmnt
        if (packet[*offset] == 0x80)
        {
            (*offset)++;
            t->GroupMDEntries[i_0].ChgFromSettlmnt.exponenta.is_null = 1;
        }
        else
        {
            t->GroupMDEntries[i_0].ChgFromSettlmnt.exponenta.value = 0 - (packet[*offset] & 0x40);
            t->GroupMDEntries[i_0].ChgFromSettlmnt.exponenta.is_null = 0;
            while (!((packet[*offset] & 0x80)))
            {
                (t->GroupMDEntries[i_0].ChgFromSettlmnt.exponenta.value) |= packet[(*offset)++];
                (t->GroupMDEntries[i_0].ChgFromSettlmnt.exponenta.value) <<= 7;
            }
            (t->GroupMDEntries[i_0].ChgFromSettlmnt.exponenta.value) |= (packet[(*offset)++] & 0x7f);
            if (t->GroupMDEntries[i_0].ChgFromSettlmnt.exponenta.value > 0)
            {
                (t->GroupMDEntries[i_0].ChgFromSettlmnt.exponenta.value)--;
            }
        }
        //<<<

#ifdef DEBUG

        if (t->GroupMDEntries[i_0].ChgFromSettlmnt.exponenta.is_null)
        {
            printf("t->GroupMDEntries[%d].ChgFromSettlmnt.exponenta = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
        }
        else
        {
            printf("t->GroupMDEntries[%d].ChgFromSettlmnt.exponenta = %s%d%s\n", i_0, KMAG, t->GroupMDEntries[i_0].ChgFromSettlmnt.exponenta.value, RESET_COLOR);
        }

#endif

#ifdef DEBUG1
        printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
        printf("name = %sChgFromSettlmnt%s\n", KRED, RESET_COLOR);
        printf("type = %snopmap_int32_nullable_noop\n%s", KBLU, RESET_COLOR);
        printf("byte_representation: ");
        printf("%s", COLOR_BYTES);
        for (int i = t_GroupMDEntries_i_0_ChgFromSettlmntexponenta_start; i < *offset; i++)
        {
            printf("%02x ", packet[i]);
        }
        printf("%s\n", RESET_COLOR);

        if (t->GroupMDEntries[i_0].ChgFromSettlmnt.exponenta.is_null)
        {
            printf("t->GroupMDEntries[%d].ChgFromSettlmnt.exponenta = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
        }
        else
        {
            printf("t->GroupMDEntries[%d].ChgFromSettlmnt.exponenta = %s%d%s\n", i_0, KMAG, t->GroupMDEntries[i_0].ChgFromSettlmnt.exponenta.value, RESET_COLOR);
        }

        printf("\n");
#endif

#ifdef DEBUG3
        getchar();
#endif

        if (!t->GroupMDEntries[i_0].ChgFromSettlmnt.exponenta.is_null)
        {
            //calc mantissa
            //nopmap_int64_nonullable_noop ChgFromSettlmnt
#ifdef DEBUG2
            int t_GroupMDEntries_i_0_ChgFromSettlmntmantissa_start = *offset;
#endif

            //>>> ChgFromSettlmnt
            t->GroupMDEntries[i_0].ChgFromSettlmnt.mantissa = 0 - (packet[*offset] & 0x40);
            while (!((packet[*offset] & 0x80)))
            {
                t->GroupMDEntries[i_0].ChgFromSettlmnt.mantissa |= packet[(*offset)++];
                t->GroupMDEntries[i_0].ChgFromSettlmnt.mantissa <<= 7;
            }
            t->GroupMDEntries[i_0].ChgFromSettlmnt.mantissa |= (packet[(*offset)++] & 0x7f);
            //<<<

#ifdef DEBUG
            printf("t->GroupMDEntries[%d].ChgFromSettlmnt.mantissa = %ld\n", i_0, t->GroupMDEntries[i_0].ChgFromSettlmnt.mantissa);
#endif

#ifdef DEBUG1
            printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
            printf("name = %sChgFromSettlmnt%s\n", KRED, RESET_COLOR);
            printf("type = %snopmap_int64_nonullable_noop\n%s", KBLU, RESET_COLOR);
            printf("byte_representation: ");
            printf("%s", COLOR_BYTES);
            for (int i = t_GroupMDEntries_i_0_ChgFromSettlmntmantissa_start; i < *offset; i++)
            {
                printf("%02x ", packet[i]);
            }
            printf("%s\n", RESET_COLOR);
            printf("value = %s%ld%s\n", KMAG, t->GroupMDEntries[i_0].ChgFromSettlmnt.mantissa, RESET_COLOR);
            printf("\n");
#endif

#ifdef DEBUG3
            getchar();
#endif
        }

        //nopmap_decimal_nullable_noop

//nopmap_int32_nullable_noop MinCurrPx
#ifdef DEBUG2
        int t_GroupMDEntries_i_0_MinCurrPxexponenta_start = *offset;
#endif

        //>>> MinCurrPx
        if (packet[*offset] == 0x80)
        {
            (*offset)++;
            t->GroupMDEntries[i_0].MinCurrPx.exponenta.is_null = 1;
        }
        else
        {
            t->GroupMDEntries[i_0].MinCurrPx.exponenta.value = 0 - (packet[*offset] & 0x40);
            t->GroupMDEntries[i_0].MinCurrPx.exponenta.is_null = 0;
            while (!((packet[*offset] & 0x80)))
            {
                (t->GroupMDEntries[i_0].MinCurrPx.exponenta.value) |= packet[(*offset)++];
                (t->GroupMDEntries[i_0].MinCurrPx.exponenta.value) <<= 7;
            }
            (t->GroupMDEntries[i_0].MinCurrPx.exponenta.value) |= (packet[(*offset)++] & 0x7f);
            if (t->GroupMDEntries[i_0].MinCurrPx.exponenta.value > 0)
            {
                (t->GroupMDEntries[i_0].MinCurrPx.exponenta.value)--;
            }
        }
        //<<<

#ifdef DEBUG

        if (t->GroupMDEntries[i_0].MinCurrPx.exponenta.is_null)
        {
            printf("t->GroupMDEntries[%d].MinCurrPx.exponenta = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
        }
        else
        {
            printf("t->GroupMDEntries[%d].MinCurrPx.exponenta = %s%d%s\n", i_0, KMAG, t->GroupMDEntries[i_0].MinCurrPx.exponenta.value, RESET_COLOR);
        }

#endif

#ifdef DEBUG1
        printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
        printf("name = %sMinCurrPx%s\n", KRED, RESET_COLOR);
        printf("type = %snopmap_int32_nullable_noop\n%s", KBLU, RESET_COLOR);
        printf("byte_representation: ");
        printf("%s", COLOR_BYTES);
        for (int i = t_GroupMDEntries_i_0_MinCurrPxexponenta_start; i < *offset; i++)
        {
            printf("%02x ", packet[i]);
        }
        printf("%s\n", RESET_COLOR);

        if (t->GroupMDEntries[i_0].MinCurrPx.exponenta.is_null)
        {
            printf("t->GroupMDEntries[%d].MinCurrPx.exponenta = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
        }
        else
        {
            printf("t->GroupMDEntries[%d].MinCurrPx.exponenta = %s%d%s\n", i_0, KMAG, t->GroupMDEntries[i_0].MinCurrPx.exponenta.value, RESET_COLOR);
        }

        printf("\n");
#endif

#ifdef DEBUG3
        getchar();
#endif

        if (!t->GroupMDEntries[i_0].MinCurrPx.exponenta.is_null)
        {
            //calc mantissa
            //nopmap_int64_nonullable_noop MinCurrPx
#ifdef DEBUG2
            int t_GroupMDEntries_i_0_MinCurrPxmantissa_start = *offset;
#endif

            //>>> MinCurrPx
            t->GroupMDEntries[i_0].MinCurrPx.mantissa = 0 - (packet[*offset] & 0x40);
            while (!((packet[*offset] & 0x80)))
            {
                t->GroupMDEntries[i_0].MinCurrPx.mantissa |= packet[(*offset)++];
                t->GroupMDEntries[i_0].MinCurrPx.mantissa <<= 7;
            }
            t->GroupMDEntries[i_0].MinCurrPx.mantissa |= (packet[(*offset)++] & 0x7f);
            //<<<

#ifdef DEBUG
            printf("t->GroupMDEntries[%d].MinCurrPx.mantissa = %ld\n", i_0, t->GroupMDEntries[i_0].MinCurrPx.mantissa);
#endif

#ifdef DEBUG1
            printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
            printf("name = %sMinCurrPx%s\n", KRED, RESET_COLOR);
            printf("type = %snopmap_int64_nonullable_noop\n%s", KBLU, RESET_COLOR);
            printf("byte_representation: ");
            printf("%s", COLOR_BYTES);
            for (int i = t_GroupMDEntries_i_0_MinCurrPxmantissa_start; i < *offset; i++)
            {
                printf("%02x ", packet[i]);
            }
            printf("%s\n", RESET_COLOR);
            printf("value = %s%ld%s\n", KMAG, t->GroupMDEntries[i_0].MinCurrPx.mantissa, RESET_COLOR);
            printf("\n");
#endif

#ifdef DEBUG3
            getchar();
#endif
        }

//nopmap_uint32_nullable_noop MinCurrPxChgTime
#ifdef DEBUG2
        int t_GroupMDEntries_i_0_MinCurrPxChgTime_start = *offset;
#endif

        //>>> MinCurrPxChgTime
        if (packet[*offset] == 0x80)
        {
            t->GroupMDEntries[i_0].MinCurrPxChgTime.is_null = 1;
            t->GroupMDEntries[i_0].MinCurrPxChgTime.value = 0;
            (*offset)++;
        }
        else
        {
            t->GroupMDEntries[i_0].MinCurrPxChgTime.value = 0;
            t->GroupMDEntries[i_0].MinCurrPxChgTime.is_null = 0;
            while (!((packet[*offset] & 0x80)))
            {
                (t->GroupMDEntries[i_0].MinCurrPxChgTime.value) |= packet[(*offset)++];
                (t->GroupMDEntries[i_0].MinCurrPxChgTime.value) <<= 7;
            }
            (t->GroupMDEntries[i_0].MinCurrPxChgTime.value) |= (packet[(*offset)++] & 0x7f);
            (t->GroupMDEntries[i_0].MinCurrPxChgTime.value)--;
        }
        //<<<

#ifdef DEBUG

        if (t->GroupMDEntries[i_0].MinCurrPxChgTime.is_null)
        {
            printf("t->GroupMDEntries[%d].MinCurrPxChgTime = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
        }
        else
        {
            printf("t->GroupMDEntries[%d].MinCurrPxChgTime = %s%u%s\n", i_0, KMAG, t->GroupMDEntries[i_0].MinCurrPxChgTime.value, RESET_COLOR);
        }

#endif

#ifdef DEBUG1
        printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
        printf("name = %sMinCurrPxChgTime%s\n", KRED, RESET_COLOR);
        printf("type = %snopmap_uint32_nullable_noop\n%s", KBLU, RESET_COLOR);
        printf("byte_representation: ");
        printf("%s", COLOR_BYTES);
        for (int i = t_GroupMDEntries_i_0_MinCurrPxChgTime_start; i < *offset; i++)
        {
            printf("%02x ", packet[i]);
        }
        printf("%s\n", RESET_COLOR);

        if (t->GroupMDEntries[i_0].MinCurrPxChgTime.is_null)
        {
            printf("t->GroupMDEntries[%d].MinCurrPxChgTime = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
        }
        else
        {
            printf("t->GroupMDEntries[%d].MinCurrPxChgTime = %s%u%s\n", i_0, KMAG, t->GroupMDEntries[i_0].MinCurrPxChgTime.value, RESET_COLOR);
        }

        printf("\n");
#endif

#ifdef DEBUG3
        getchar();
#endif

//nopmap_uint32_nullable_noop VolumeIndicator
#ifdef DEBUG2
        int t_GroupMDEntries_i_0_VolumeIndicator_start = *offset;
#endif

        //>>> VolumeIndicator
        if (packet[*offset] == 0x80)
        {
            t->GroupMDEntries[i_0].VolumeIndicator.is_null = 1;
            t->GroupMDEntries[i_0].VolumeIndicator.value = 0;
            (*offset)++;
        }
        else
        {
            t->GroupMDEntries[i_0].VolumeIndicator.value = 0;
            t->GroupMDEntries[i_0].VolumeIndicator.is_null = 0;
            while (!((packet[*offset] & 0x80)))
            {
                (t->GroupMDEntries[i_0].VolumeIndicator.value) |= packet[(*offset)++];
                (t->GroupMDEntries[i_0].VolumeIndicator.value) <<= 7;
            }
            (t->GroupMDEntries[i_0].VolumeIndicator.value) |= (packet[(*offset)++] & 0x7f);
            (t->GroupMDEntries[i_0].VolumeIndicator.value)--;
        }
        //<<<

#ifdef DEBUG

        if (t->GroupMDEntries[i_0].VolumeIndicator.is_null)
        {
            printf("t->GroupMDEntries[%d].VolumeIndicator = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
        }
        else
        {
            printf("t->GroupMDEntries[%d].VolumeIndicator = %s%u%s\n", i_0, KMAG, t->GroupMDEntries[i_0].VolumeIndicator.value, RESET_COLOR);
        }

#endif

#ifdef DEBUG1
        printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
        printf("name = %sVolumeIndicator%s\n", KRED, RESET_COLOR);
        printf("type = %snopmap_uint32_nullable_noop\n%s", KBLU, RESET_COLOR);
        printf("byte_representation: ");
        printf("%s", COLOR_BYTES);
        for (int i = t_GroupMDEntries_i_0_VolumeIndicator_start; i < *offset; i++)
        {
            printf("%02x ", packet[i]);
        }
        printf("%s\n", RESET_COLOR);

        if (t->GroupMDEntries[i_0].VolumeIndicator.is_null)
        {
            printf("t->GroupMDEntries[%d].VolumeIndicator = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
        }
        else
        {
            printf("t->GroupMDEntries[%d].VolumeIndicator = %s%u%s\n", i_0, KMAG, t->GroupMDEntries[i_0].VolumeIndicator.value, RESET_COLOR);
        }

        printf("\n");
#endif

#ifdef DEBUG3
        getchar();
#endif

//nopmap_uint32_nullable_noop SettlDate
#ifdef DEBUG2
        int t_GroupMDEntries_i_0_SettlDate_start = *offset;
#endif

        //>>> SettlDate
        if (packet[*offset] == 0x80)
        {
            t->GroupMDEntries[i_0].SettlDate.is_null = 1;
            t->GroupMDEntries[i_0].SettlDate.value = 0;
            (*offset)++;
        }
        else
        {
            t->GroupMDEntries[i_0].SettlDate.value = 0;
            t->GroupMDEntries[i_0].SettlDate.is_null = 0;
            while (!((packet[*offset] & 0x80)))
            {
                (t->GroupMDEntries[i_0].SettlDate.value) |= packet[(*offset)++];
                (t->GroupMDEntries[i_0].SettlDate.value) <<= 7;
            }
            (t->GroupMDEntries[i_0].SettlDate.value) |= (packet[(*offset)++] & 0x7f);
            (t->GroupMDEntries[i_0].SettlDate.value)--;
        }
        //<<<

#ifdef DEBUG

        if (t->GroupMDEntries[i_0].SettlDate.is_null)
        {
            printf("t->GroupMDEntries[%d].SettlDate = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
        }
        else
        {
            printf("t->GroupMDEntries[%d].SettlDate = %s%u%s\n", i_0, KMAG, t->GroupMDEntries[i_0].SettlDate.value, RESET_COLOR);
        }

#endif

#ifdef DEBUG1
        printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
        printf("name = %sSettlDate%s\n", KRED, RESET_COLOR);
        printf("type = %snopmap_uint32_nullable_noop\n%s", KBLU, RESET_COLOR);
        printf("byte_representation: ");
        printf("%s", COLOR_BYTES);
        for (int i = t_GroupMDEntries_i_0_SettlDate_start; i < *offset; i++)
        {
            printf("%02x ", packet[i]);
        }
        printf("%s\n", RESET_COLOR);

        if (t->GroupMDEntries[i_0].SettlDate.is_null)
        {
            printf("t->GroupMDEntries[%d].SettlDate = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
        }
        else
        {
            printf("t->GroupMDEntries[%d].SettlDate = %s%u%s\n", i_0, KMAG, t->GroupMDEntries[i_0].SettlDate.value, RESET_COLOR);
        }

        printf("\n");
#endif

#ifdef DEBUG3
        getchar();
#endif

//nopmap_string_nullable_noop SettleType
#ifdef DEBUG2
        int t_GroupMDEntries_i_0_SettleType_start = *offset;
#endif

        //>>> SettleType
        t->GroupMDEntries[i_0].SettleType.start = packet + *offset;
        if (packet[*offset] == 0x80)
        {
            (*offset)++;
            t->GroupMDEntries[i_0].SettleType.len = 0;
            t->GroupMDEntries[i_0].SettleType.is_null = 1;
            //printf("t->GroupMDEntries[i_0].SettleType = EMPTY \n");
        }
        else
        {
            t->GroupMDEntries[i_0].SettleType.len = 0;
            t->GroupMDEntries[i_0].SettleType.is_null = 0;
            while (!((packet[(*offset)] & 0x80)))
            {
                t->GroupMDEntries[i_0].SettleType.len++;
                (*offset)++;
            }
            packet[*offset] = packet[*offset] & 0x7F;
            (*offset)++;
            t->GroupMDEntries[i_0].SettleType.len++;
        }
        //<<<

#ifdef DEBUG

        if (1)
        {

            if (t->GroupMDEntries[i_0].SettleType.is_null)
            {
                printf("t->GroupMDEntries[%d].SettleType = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
            }
            else
            {
                unsigned char fake[128];
                strncpy(fake, t->GroupMDEntries[i_0].SettleType.start, t->GroupMDEntries[i_0].SettleType.len);
                fake[t->GroupMDEntries[i_0].SettleType.len] = '\0';
                printf("t->GroupMDEntries[%d].SettleType = %s%s%s\n", i_0, KMAG, fake, RESET_COLOR);
            }
        }

#endif

#ifdef DEBUG1
        printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
        printf("name = %sSettleType%s\n", KRED, RESET_COLOR);
        printf("type = %s nopmap_string_nullable_noop\n%s", KBLU, RESET_COLOR);
        printf("byte_representation: ");
        printf("%s", COLOR_BYTES);
        for (int i = t_GroupMDEntries_i_0_SettleType_start; i < *offset; i++)
        {
            printf("%02x ", packet[i]);
        }
        printf("%s\n", RESET_COLOR);

        if (1)
        {

            if (t->GroupMDEntries[i_0].SettleType.is_null)
            {
                printf("t->GroupMDEntries[%d].SettleType = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
            }
            else
            {
                unsigned char fake[128];
                strncpy(fake, t->GroupMDEntries[i_0].SettleType.start, t->GroupMDEntries[i_0].SettleType.len);
                fake[t->GroupMDEntries[i_0].SettleType.len] = '\0';
                printf("t->GroupMDEntries[%d].SettleType = %s%s%s\n", i_0, KMAG, fake, RESET_COLOR);
            }
        }

        printf("\n");
#endif

#ifdef DEBUG3
        getchar();
#endif

//nopmap_string_nullable_noop CXFlag
#ifdef DEBUG2
        int t_GroupMDEntries_i_0_CXFlag_start = *offset;
#endif

        //>>> CXFlag
        t->GroupMDEntries[i_0].CXFlag.start = packet + *offset;
        if (packet[*offset] == 0x80)
        {
            (*offset)++;
            t->GroupMDEntries[i_0].CXFlag.len = 0;
            t->GroupMDEntries[i_0].CXFlag.is_null = 1;
            //printf("t->GroupMDEntries[i_0].CXFlag = EMPTY \n");
        }
        else
        {
            t->GroupMDEntries[i_0].CXFlag.len = 0;
            t->GroupMDEntries[i_0].CXFlag.is_null = 0;
            while (!((packet[(*offset)] & 0x80)))
            {
                t->GroupMDEntries[i_0].CXFlag.len++;
                (*offset)++;
            }
            packet[*offset] = packet[*offset] & 0x7F;
            (*offset)++;
            t->GroupMDEntries[i_0].CXFlag.len++;
        }
        //<<<

#ifdef DEBUG

        if (1)
        {

            if (t->GroupMDEntries[i_0].CXFlag.is_null)
            {
                printf("t->GroupMDEntries[%d].CXFlag = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
            }
            else
            {
                unsigned char fake[128];
                strncpy(fake, t->GroupMDEntries[i_0].CXFlag.start, t->GroupMDEntries[i_0].CXFlag.len);
                fake[t->GroupMDEntries[i_0].CXFlag.len] = '\0';
                printf("t->GroupMDEntries[%d].CXFlag = %s%s%s\n", i_0, KMAG, fake, RESET_COLOR);
            }
        }

#endif

#ifdef DEBUG1
        printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
        printf("name = %sCXFlag%s\n", KRED, RESET_COLOR);
        printf("type = %s nopmap_string_nullable_noop\n%s", KBLU, RESET_COLOR);
        printf("byte_representation: ");
        printf("%s", COLOR_BYTES);
        for (int i = t_GroupMDEntries_i_0_CXFlag_start; i < *offset; i++)
        {
            printf("%02x ", packet[i]);
        }
        printf("%s\n", RESET_COLOR);

        if (1)
        {

            if (t->GroupMDEntries[i_0].CXFlag.is_null)
            {
                printf("t->GroupMDEntries[%d].CXFlag = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
            }
            else
            {
                unsigned char fake[128];
                strncpy(fake, t->GroupMDEntries[i_0].CXFlag.start, t->GroupMDEntries[i_0].CXFlag.len);
                fake[t->GroupMDEntries[i_0].CXFlag.len] = '\0';
                printf("t->GroupMDEntries[%d].CXFlag = %s%s%s\n", i_0, KMAG, fake, RESET_COLOR);
            }
        }

        printf("\n");
#endif

#ifdef DEBUG3
        getchar();
#endif

//nopmap_string_nullable_noop TradingSessionID
#ifdef DEBUG2
        int t_GroupMDEntries_i_0_TradingSessionID_start = *offset;
#endif

        //>>> TradingSessionID
        t->GroupMDEntries[i_0].TradingSessionID.start = packet + *offset;
        if (packet[*offset] == 0x80)
        {
            (*offset)++;
            t->GroupMDEntries[i_0].TradingSessionID.len = 0;
            t->GroupMDEntries[i_0].TradingSessionID.is_null = 1;
            //printf("t->GroupMDEntries[i_0].TradingSessionID = EMPTY \n");
        }
        else
        {
            t->GroupMDEntries[i_0].TradingSessionID.len = 0;
            t->GroupMDEntries[i_0].TradingSessionID.is_null = 0;
            while (!((packet[(*offset)] & 0x80)))
            {
                t->GroupMDEntries[i_0].TradingSessionID.len++;
                (*offset)++;
            }
            packet[*offset] = packet[*offset] & 0x7F;
            (*offset)++;
            t->GroupMDEntries[i_0].TradingSessionID.len++;
        }
        //<<<

#ifdef DEBUG

        if (1)
        {

            if (t->GroupMDEntries[i_0].TradingSessionID.is_null)
            {
                printf("t->GroupMDEntries[%d].TradingSessionID = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
            }
            else
            {
                unsigned char fake[128];
                strncpy(fake, t->GroupMDEntries[i_0].TradingSessionID.start, t->GroupMDEntries[i_0].TradingSessionID.len);
                fake[t->GroupMDEntries[i_0].TradingSessionID.len] = '\0';
                printf("t->GroupMDEntries[%d].TradingSessionID = %s%s%s\n", i_0, KMAG, fake, RESET_COLOR);
            }
        }

#endif

#ifdef DEBUG1
        printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
        printf("name = %sTradingSessionID%s\n", KRED, RESET_COLOR);
        printf("type = %s nopmap_string_nullable_noop\n%s", KBLU, RESET_COLOR);
        printf("byte_representation: ");
        printf("%s", COLOR_BYTES);
        for (int i = t_GroupMDEntries_i_0_TradingSessionID_start; i < *offset; i++)
        {
            printf("%02x ", packet[i]);
        }
        printf("%s\n", RESET_COLOR);

        if (1)
        {

            if (t->GroupMDEntries[i_0].TradingSessionID.is_null)
            {
                printf("t->GroupMDEntries[%d].TradingSessionID = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
            }
            else
            {
                unsigned char fake[128];
                strncpy(fake, t->GroupMDEntries[i_0].TradingSessionID.start, t->GroupMDEntries[i_0].TradingSessionID.len);
                fake[t->GroupMDEntries[i_0].TradingSessionID.len] = '\0';
                printf("t->GroupMDEntries[%d].TradingSessionID = %s%s%s\n", i_0, KMAG, fake, RESET_COLOR);
            }
        }

        printf("\n");
#endif

#ifdef DEBUG3
        getchar();
#endif

//nopmap_string_nullable_noop TradingSessionSubID
#ifdef DEBUG2
        int t_GroupMDEntries_i_0_TradingSessionSubID_start = *offset;
#endif

        //>>> TradingSessionSubID
        t->GroupMDEntries[i_0].TradingSessionSubID.start = packet + *offset;
        if (packet[*offset] == 0x80)
        {
            (*offset)++;
            t->GroupMDEntries[i_0].TradingSessionSubID.len = 0;
            t->GroupMDEntries[i_0].TradingSessionSubID.is_null = 1;
            //printf("t->GroupMDEntries[i_0].TradingSessionSubID = EMPTY \n");
        }
        else
        {
            t->GroupMDEntries[i_0].TradingSessionSubID.len = 0;
            t->GroupMDEntries[i_0].TradingSessionSubID.is_null = 0;
            while (!((packet[(*offset)] & 0x80)))
            {
                t->GroupMDEntries[i_0].TradingSessionSubID.len++;
                (*offset)++;
            }
            packet[*offset] = packet[*offset] & 0x7F;
            (*offset)++;
            t->GroupMDEntries[i_0].TradingSessionSubID.len++;
        }
        //<<<

#ifdef DEBUG

        if (1)
        {

            if (t->GroupMDEntries[i_0].TradingSessionSubID.is_null)
            {
                printf("t->GroupMDEntries[%d].TradingSessionSubID = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
            }
            else
            {
                unsigned char fake[128];
                strncpy(fake, t->GroupMDEntries[i_0].TradingSessionSubID.start, t->GroupMDEntries[i_0].TradingSessionSubID.len);
                fake[t->GroupMDEntries[i_0].TradingSessionSubID.len] = '\0';
                printf("t->GroupMDEntries[%d].TradingSessionSubID = %s%s%s\n", i_0, KMAG, fake, RESET_COLOR);
            }
        }

#endif

#ifdef DEBUG1
        printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
        printf("name = %sTradingSessionSubID%s\n", KRED, RESET_COLOR);
        printf("type = %s nopmap_string_nullable_noop\n%s", KBLU, RESET_COLOR);
        printf("byte_representation: ");
        printf("%s", COLOR_BYTES);
        for (int i = t_GroupMDEntries_i_0_TradingSessionSubID_start; i < *offset; i++)
        {
            printf("%02x ", packet[i]);
        }
        printf("%s\n", RESET_COLOR);

        if (1)
        {

            if (t->GroupMDEntries[i_0].TradingSessionSubID.is_null)
            {
                printf("t->GroupMDEntries[%d].TradingSessionSubID = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
            }
            else
            {
                unsigned char fake[128];
                strncpy(fake, t->GroupMDEntries[i_0].TradingSessionSubID.start, t->GroupMDEntries[i_0].TradingSessionSubID.len);
                fake[t->GroupMDEntries[i_0].TradingSessionSubID.len] = '\0';
                printf("t->GroupMDEntries[%d].TradingSessionSubID = %s%s%s\n", i_0, KMAG, fake, RESET_COLOR);
            }
        }

        printf("\n");
#endif

#ifdef DEBUG3
        getchar();
#endif
    }
    return 0;
}
int moex_eq_parse_template_X_TLR_FOND(unsigned char *packet, int *offset, unsigned char *pmap, struct moex_eq__X_TLR_FOND *t)
{
    t->pmap = pmap;

    //nopmap_string_nonullable_constant MessageType
    //strcpy(t->MessageType, "X");

    //nopmap_string_nonullable_constant ApplVerID
    //strcpy(t->ApplVerID, "9");

    //nopmap_string_nonullable_constant BeginString
    //strcpy(t->BeginString, "FIXT.1.1");

    //nopmap_string_nonullable_constant SenderCompID
    //strcpy(t->SenderCompID, "MOEX");

    //nopmap_uint32_nonullable_noop MsgSeqNum
#ifdef DEBUG2
    int t_MsgSeqNum_start = *offset;
#endif

    //>>> MsgSeqNum
    t->MsgSeqNum = 0;
    while (!((packet[*offset] & 0x80)))
    {
        t->MsgSeqNum |= packet[(*offset)++];
        t->MsgSeqNum <<= 7;
    }
    t->MsgSeqNum |= (packet[(*offset)++] & 0x7f);
    //<<<

#ifdef DEBUG
    printf("t->MsgSeqNum = %u\n", t->MsgSeqNum);
#endif

#ifdef DEBUG1
    printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
    printf("name = %sMsgSeqNum%s\n", KRED, RESET_COLOR);
    printf("type = %snopmap_uint32_nonullable_noop\n%s", KBLU, RESET_COLOR);
    printf("byte_representation: ");
    printf("%s", COLOR_BYTES);
    for (int i = t_MsgSeqNum_start; i < *offset; i++)
    {
        printf("%02x ", packet[i]);
    }
    printf("%s\n", RESET_COLOR);
    printf("value = %s%u%s\n", KMAG, t->MsgSeqNum, RESET_COLOR);
    printf("\n");
#endif

#ifdef DEBUG3
    getchar();
#endif

    //nopmap_uint64_nonullable_noop SendingTime
#ifdef DEBUG2
    int t_SendingTime_start = *offset;
#endif

    //>>> SendingTime
    t->SendingTime = 0;
    while (!((packet[*offset] & 0x80)))
    {
        (t->SendingTime) |= packet[(*offset)++];
        (t->SendingTime) <<= 7;
    }
    (t->SendingTime) |= (packet[(*offset)++] & 0x7f);
    //<<<

#ifdef DEBUG
    printf("t->SendingTime = %lu\n", t->SendingTime);
#endif

#ifdef DEBUG1
    printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
    printf("name = %sSendingTime%s\n", KRED, RESET_COLOR);
    printf("type = %snopmap_uint64_nonullable_noop\n%s", KBLU, RESET_COLOR);
    printf("byte_representation: ");
    printf("%s", COLOR_BYTES);
    for (int i = t_SendingTime_start; i < *offset; i++)
    {
        printf("%02x ", packet[i]);
    }
    printf("%s\n", RESET_COLOR);
    printf("value = %s%lu%s\n", KMAG, t->SendingTime, RESET_COLOR);
    printf("\n");
#endif

#ifdef DEBUG3
    getchar();
#endif

    //nopmap_uint32_nonullable_noop NoMDEntries
#ifdef DEBUG2
    int t_NoMDEntries_start = *offset;
#endif

    //>>> NoMDEntries
    t->NoMDEntries = 0;
    while (!((packet[*offset] & 0x80)))
    {
        t->NoMDEntries |= packet[(*offset)++];
        t->NoMDEntries <<= 7;
    }
    t->NoMDEntries |= (packet[(*offset)++] & 0x7f);
    //<<<

#ifdef DEBUG
    printf("t->NoMDEntries = %u\n", t->NoMDEntries);
#endif

#ifdef DEBUG1
    printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
    printf("name = %sNoMDEntries%s\n", KRED, RESET_COLOR);
    printf("type = %snopmap_uint32_nonullable_noop\n%s", KBLU, RESET_COLOR);
    printf("byte_representation: ");
    printf("%s", COLOR_BYTES);
    for (int i = t_NoMDEntries_start; i < *offset; i++)
    {
        printf("%02x ", packet[i]);
    }
    printf("%s\n", RESET_COLOR);
    printf("value = %s%u%s\n", KMAG, t->NoMDEntries, RESET_COLOR);
    printf("\n");
#endif

#ifdef DEBUG3
    getchar();
#endif

    if (t->NoMDEntries >= moex_eq__X_TLR_FOND__GroupMDEntries__MAX)
    {
        return -1;
    }

    for (int i_0 = 0; i_0 < t->NoMDEntries; i_0++)
    {
        //PMAP for this sequence doesn't required

//nopmap_uint32_nullable_noop MDUpdateAction
#ifdef DEBUG2
        int t_GroupMDEntries_i_0_MDUpdateAction_start = *offset;
#endif

        //>>> MDUpdateAction
        if (packet[*offset] == 0x80)
        {
            t->GroupMDEntries[i_0].MDUpdateAction.is_null = 1;
            t->GroupMDEntries[i_0].MDUpdateAction.value = 0;
            (*offset)++;
        }
        else
        {
            t->GroupMDEntries[i_0].MDUpdateAction.value = 0;
            t->GroupMDEntries[i_0].MDUpdateAction.is_null = 0;
            while (!((packet[*offset] & 0x80)))
            {
                (t->GroupMDEntries[i_0].MDUpdateAction.value) |= packet[(*offset)++];
                (t->GroupMDEntries[i_0].MDUpdateAction.value) <<= 7;
            }
            (t->GroupMDEntries[i_0].MDUpdateAction.value) |= (packet[(*offset)++] & 0x7f);
            (t->GroupMDEntries[i_0].MDUpdateAction.value)--;
        }
        //<<<

#ifdef DEBUG

        if (t->GroupMDEntries[i_0].MDUpdateAction.is_null)
        {
            printf("t->GroupMDEntries[%d].MDUpdateAction = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
        }
        else
        {
            printf("t->GroupMDEntries[%d].MDUpdateAction = %s%u%s\n", i_0, KMAG, t->GroupMDEntries[i_0].MDUpdateAction.value, RESET_COLOR);
        }

#endif

#ifdef DEBUG1
        printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
        printf("name = %sMDUpdateAction%s\n", KRED, RESET_COLOR);
        printf("type = %snopmap_uint32_nullable_noop\n%s", KBLU, RESET_COLOR);
        printf("byte_representation: ");
        printf("%s", COLOR_BYTES);
        for (int i = t_GroupMDEntries_i_0_MDUpdateAction_start; i < *offset; i++)
        {
            printf("%02x ", packet[i]);
        }
        printf("%s\n", RESET_COLOR);

        if (t->GroupMDEntries[i_0].MDUpdateAction.is_null)
        {
            printf("t->GroupMDEntries[%d].MDUpdateAction = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
        }
        else
        {
            printf("t->GroupMDEntries[%d].MDUpdateAction = %s%u%s\n", i_0, KMAG, t->GroupMDEntries[i_0].MDUpdateAction.value, RESET_COLOR);
        }

        printf("\n");
#endif

#ifdef DEBUG3
        getchar();
#endif

//nopmap_string_nonullable_noop MDEntryType
#ifdef DEBUG2
        int t_GroupMDEntries_i_0_MDEntryType_start = *offset;
#endif

        //>>> MDEntryType
        t->GroupMDEntries[i_0].MDEntryType.start = packet + *offset;
        if (packet[*offset] == 0x80)
        {
            (*offset)++;
            t->GroupMDEntries[i_0].MDEntryType.len = 0;
            t->GroupMDEntries[i_0].MDEntryType.is_null = 1;
            //printf("t->GroupMDEntries[i_0].MDEntryType = EMPTY \n");
        }
        else
        {
            t->GroupMDEntries[i_0].MDEntryType.len = 0;
            while (!((packet[(*offset)] & 0x80)))
            {
                t->GroupMDEntries[i_0].MDEntryType.len++;
                (*offset)++;
            }
            packet[*offset] = packet[*offset] & 0x7F;
            (*offset)++;
            t->GroupMDEntries[i_0].MDEntryType.len++;
        }
        //<<<

#ifdef DEBUG

        {
            unsigned char fake[128];
            strncpy(fake, t->GroupMDEntries[i_0].MDEntryType.start, t->GroupMDEntries[i_0].MDEntryType.len);
            fake[t->GroupMDEntries[i_0].MDEntryType.len] = '\0';
            printf("t->GroupMDEntries[%d].MDEntryType = %s%s%s\n", i_0, KMAG, fake, RESET_COLOR);
        }

#endif

#ifdef DEBUG1
        printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
        printf("name = %sMDEntryType%s\n", KRED, RESET_COLOR);
        printf("type = %s nopmap_string_nonullable_noop\n%s", KBLU, RESET_COLOR);
        printf("byte_representation: ");
        printf("%s", COLOR_BYTES);
        for (int i = t_GroupMDEntries_i_0_MDEntryType_start; i < *offset; i++)
        {
            printf("%02x ", packet[i]);
        }
        printf("%s\n", RESET_COLOR);

        {
            unsigned char fake[128];
            strncpy(fake, t->GroupMDEntries[i_0].MDEntryType.start, t->GroupMDEntries[i_0].MDEntryType.len);
            fake[t->GroupMDEntries[i_0].MDEntryType.len] = '\0';
            printf("t->GroupMDEntries[%d].MDEntryType = %s%s%s\n", i_0, KMAG, fake, RESET_COLOR);
        }

        printf("\n");
#endif

#ifdef DEBUG3
        getchar();
#endif

//nopmap_string_nullable_noop MDEntryID
#ifdef DEBUG2
        int t_GroupMDEntries_i_0_MDEntryID_start = *offset;
#endif

        //>>> MDEntryID
        t->GroupMDEntries[i_0].MDEntryID.start = packet + *offset;
        if (packet[*offset] == 0x80)
        {
            (*offset)++;
            t->GroupMDEntries[i_0].MDEntryID.len = 0;
            t->GroupMDEntries[i_0].MDEntryID.is_null = 1;
            //printf("t->GroupMDEntries[i_0].MDEntryID = EMPTY \n");
        }
        else
        {
            t->GroupMDEntries[i_0].MDEntryID.len = 0;
            t->GroupMDEntries[i_0].MDEntryID.is_null = 0;
            while (!((packet[(*offset)] & 0x80)))
            {
                t->GroupMDEntries[i_0].MDEntryID.len++;
                (*offset)++;
            }
            packet[*offset] = packet[*offset] & 0x7F;
            (*offset)++;
            t->GroupMDEntries[i_0].MDEntryID.len++;
        }
        //<<<

#ifdef DEBUG

        if (1)
        {

            if (t->GroupMDEntries[i_0].MDEntryID.is_null)
            {
                printf("t->GroupMDEntries[%d].MDEntryID = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
            }
            else
            {
                unsigned char fake[128];
                strncpy(fake, t->GroupMDEntries[i_0].MDEntryID.start, t->GroupMDEntries[i_0].MDEntryID.len);
                fake[t->GroupMDEntries[i_0].MDEntryID.len] = '\0';
                printf("t->GroupMDEntries[%d].MDEntryID = %s%s%s\n", i_0, KMAG, fake, RESET_COLOR);
            }
        }

#endif

#ifdef DEBUG1
        printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
        printf("name = %sMDEntryID%s\n", KRED, RESET_COLOR);
        printf("type = %s nopmap_string_nullable_noop\n%s", KBLU, RESET_COLOR);
        printf("byte_representation: ");
        printf("%s", COLOR_BYTES);
        for (int i = t_GroupMDEntries_i_0_MDEntryID_start; i < *offset; i++)
        {
            printf("%02x ", packet[i]);
        }
        printf("%s\n", RESET_COLOR);

        if (1)
        {

            if (t->GroupMDEntries[i_0].MDEntryID.is_null)
            {
                printf("t->GroupMDEntries[%d].MDEntryID = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
            }
            else
            {
                unsigned char fake[128];
                strncpy(fake, t->GroupMDEntries[i_0].MDEntryID.start, t->GroupMDEntries[i_0].MDEntryID.len);
                fake[t->GroupMDEntries[i_0].MDEntryID.len] = '\0';
                printf("t->GroupMDEntries[%d].MDEntryID = %s%s%s\n", i_0, KMAG, fake, RESET_COLOR);
            }
        }

        printf("\n");
#endif

#ifdef DEBUG3
        getchar();
#endif

//nopmap_string_nullable_noop Symbol
#ifdef DEBUG2
        int t_GroupMDEntries_i_0_Symbol_start = *offset;
#endif

        //>>> Symbol
        t->GroupMDEntries[i_0].Symbol.start = packet + *offset;
        if (packet[*offset] == 0x80)
        {
            (*offset)++;
            t->GroupMDEntries[i_0].Symbol.len = 0;
            t->GroupMDEntries[i_0].Symbol.is_null = 1;
            //printf("t->GroupMDEntries[i_0].Symbol = EMPTY \n");
        }
        else
        {
            t->GroupMDEntries[i_0].Symbol.len = 0;
            t->GroupMDEntries[i_0].Symbol.is_null = 0;
            while (!((packet[(*offset)] & 0x80)))
            {
                t->GroupMDEntries[i_0].Symbol.len++;
                (*offset)++;
            }
            packet[*offset] = packet[*offset] & 0x7F;
            (*offset)++;
            t->GroupMDEntries[i_0].Symbol.len++;
        }
        //<<<

#ifdef DEBUG

        if (1)
        {

            if (t->GroupMDEntries[i_0].Symbol.is_null)
            {
                printf("t->GroupMDEntries[%d].Symbol = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
            }
            else
            {
                unsigned char fake[128];
                strncpy(fake, t->GroupMDEntries[i_0].Symbol.start, t->GroupMDEntries[i_0].Symbol.len);
                fake[t->GroupMDEntries[i_0].Symbol.len] = '\0';
                printf("t->GroupMDEntries[%d].Symbol = %s%s%s\n", i_0, KMAG, fake, RESET_COLOR);
            }
        }

#endif

#ifdef DEBUG1
        printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
        printf("name = %sSymbol%s\n", KRED, RESET_COLOR);
        printf("type = %s nopmap_string_nullable_noop\n%s", KBLU, RESET_COLOR);
        printf("byte_representation: ");
        printf("%s", COLOR_BYTES);
        for (int i = t_GroupMDEntries_i_0_Symbol_start; i < *offset; i++)
        {
            printf("%02x ", packet[i]);
        }
        printf("%s\n", RESET_COLOR);

        if (1)
        {

            if (t->GroupMDEntries[i_0].Symbol.is_null)
            {
                printf("t->GroupMDEntries[%d].Symbol = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
            }
            else
            {
                unsigned char fake[128];
                strncpy(fake, t->GroupMDEntries[i_0].Symbol.start, t->GroupMDEntries[i_0].Symbol.len);
                fake[t->GroupMDEntries[i_0].Symbol.len] = '\0';
                printf("t->GroupMDEntries[%d].Symbol = %s%s%s\n", i_0, KMAG, fake, RESET_COLOR);
            }
        }

        printf("\n");
#endif

#ifdef DEBUG3
        getchar();
#endif

//nopmap_int32_nullable_noop RptSeq
#ifdef DEBUG2
        int t_GroupMDEntries_i_0_RptSeq_start = *offset;
#endif

        //>>> RptSeq
        if (packet[*offset] == 0x80)
        {
            (*offset)++;
            t->GroupMDEntries[i_0].RptSeq.is_null = 1;
        }
        else
        {
            t->GroupMDEntries[i_0].RptSeq.value = 0 - (packet[*offset] & 0x40);
            t->GroupMDEntries[i_0].RptSeq.is_null = 0;
            while (!((packet[*offset] & 0x80)))
            {
                (t->GroupMDEntries[i_0].RptSeq.value) |= packet[(*offset)++];
                (t->GroupMDEntries[i_0].RptSeq.value) <<= 7;
            }
            (t->GroupMDEntries[i_0].RptSeq.value) |= (packet[(*offset)++] & 0x7f);
            if (t->GroupMDEntries[i_0].RptSeq.value > 0)
            {
                (t->GroupMDEntries[i_0].RptSeq.value)--;
            }
        }
        //<<<

#ifdef DEBUG

        if (t->GroupMDEntries[i_0].RptSeq.is_null)
        {
            printf("t->GroupMDEntries[%d].RptSeq = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
        }
        else
        {
            printf("t->GroupMDEntries[%d].RptSeq = %s%d%s\n", i_0, KMAG, t->GroupMDEntries[i_0].RptSeq.value, RESET_COLOR);
        }

#endif

#ifdef DEBUG1
        printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
        printf("name = %sRptSeq%s\n", KRED, RESET_COLOR);
        printf("type = %snopmap_int32_nullable_noop\n%s", KBLU, RESET_COLOR);
        printf("byte_representation: ");
        printf("%s", COLOR_BYTES);
        for (int i = t_GroupMDEntries_i_0_RptSeq_start; i < *offset; i++)
        {
            printf("%02x ", packet[i]);
        }
        printf("%s\n", RESET_COLOR);

        if (t->GroupMDEntries[i_0].RptSeq.is_null)
        {
            printf("t->GroupMDEntries[%d].RptSeq = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
        }
        else
        {
            printf("t->GroupMDEntries[%d].RptSeq = %s%d%s\n", i_0, KMAG, t->GroupMDEntries[i_0].RptSeq.value, RESET_COLOR);
        }

        printf("\n");
#endif

#ifdef DEBUG3
        getchar();
#endif

//nopmap_uint32_nullable_noop MDEntryDate
#ifdef DEBUG2
        int t_GroupMDEntries_i_0_MDEntryDate_start = *offset;
#endif

        //>>> MDEntryDate
        if (packet[*offset] == 0x80)
        {
            t->GroupMDEntries[i_0].MDEntryDate.is_null = 1;
            t->GroupMDEntries[i_0].MDEntryDate.value = 0;
            (*offset)++;
        }
        else
        {
            t->GroupMDEntries[i_0].MDEntryDate.value = 0;
            t->GroupMDEntries[i_0].MDEntryDate.is_null = 0;
            while (!((packet[*offset] & 0x80)))
            {
                (t->GroupMDEntries[i_0].MDEntryDate.value) |= packet[(*offset)++];
                (t->GroupMDEntries[i_0].MDEntryDate.value) <<= 7;
            }
            (t->GroupMDEntries[i_0].MDEntryDate.value) |= (packet[(*offset)++] & 0x7f);
            (t->GroupMDEntries[i_0].MDEntryDate.value)--;
        }
        //<<<

#ifdef DEBUG

        if (t->GroupMDEntries[i_0].MDEntryDate.is_null)
        {
            printf("t->GroupMDEntries[%d].MDEntryDate = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
        }
        else
        {
            printf("t->GroupMDEntries[%d].MDEntryDate = %s%u%s\n", i_0, KMAG, t->GroupMDEntries[i_0].MDEntryDate.value, RESET_COLOR);
        }

#endif

#ifdef DEBUG1
        printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
        printf("name = %sMDEntryDate%s\n", KRED, RESET_COLOR);
        printf("type = %snopmap_uint32_nullable_noop\n%s", KBLU, RESET_COLOR);
        printf("byte_representation: ");
        printf("%s", COLOR_BYTES);
        for (int i = t_GroupMDEntries_i_0_MDEntryDate_start; i < *offset; i++)
        {
            printf("%02x ", packet[i]);
        }
        printf("%s\n", RESET_COLOR);

        if (t->GroupMDEntries[i_0].MDEntryDate.is_null)
        {
            printf("t->GroupMDEntries[%d].MDEntryDate = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
        }
        else
        {
            printf("t->GroupMDEntries[%d].MDEntryDate = %s%u%s\n", i_0, KMAG, t->GroupMDEntries[i_0].MDEntryDate.value, RESET_COLOR);
        }

        printf("\n");
#endif

#ifdef DEBUG3
        getchar();
#endif

//nopmap_uint32_nullable_noop MDEntryTime
#ifdef DEBUG2
        int t_GroupMDEntries_i_0_MDEntryTime_start = *offset;
#endif

        //>>> MDEntryTime
        if (packet[*offset] == 0x80)
        {
            t->GroupMDEntries[i_0].MDEntryTime.is_null = 1;
            t->GroupMDEntries[i_0].MDEntryTime.value = 0;
            (*offset)++;
        }
        else
        {
            t->GroupMDEntries[i_0].MDEntryTime.value = 0;
            t->GroupMDEntries[i_0].MDEntryTime.is_null = 0;
            while (!((packet[*offset] & 0x80)))
            {
                (t->GroupMDEntries[i_0].MDEntryTime.value) |= packet[(*offset)++];
                (t->GroupMDEntries[i_0].MDEntryTime.value) <<= 7;
            }
            (t->GroupMDEntries[i_0].MDEntryTime.value) |= (packet[(*offset)++] & 0x7f);
            (t->GroupMDEntries[i_0].MDEntryTime.value)--;
        }
        //<<<

#ifdef DEBUG

        if (t->GroupMDEntries[i_0].MDEntryTime.is_null)
        {
            printf("t->GroupMDEntries[%d].MDEntryTime = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
        }
        else
        {
            printf("t->GroupMDEntries[%d].MDEntryTime = %s%u%s\n", i_0, KMAG, t->GroupMDEntries[i_0].MDEntryTime.value, RESET_COLOR);
        }

#endif

#ifdef DEBUG1
        printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
        printf("name = %sMDEntryTime%s\n", KRED, RESET_COLOR);
        printf("type = %snopmap_uint32_nullable_noop\n%s", KBLU, RESET_COLOR);
        printf("byte_representation: ");
        printf("%s", COLOR_BYTES);
        for (int i = t_GroupMDEntries_i_0_MDEntryTime_start; i < *offset; i++)
        {
            printf("%02x ", packet[i]);
        }
        printf("%s\n", RESET_COLOR);

        if (t->GroupMDEntries[i_0].MDEntryTime.is_null)
        {
            printf("t->GroupMDEntries[%d].MDEntryTime = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
        }
        else
        {
            printf("t->GroupMDEntries[%d].MDEntryTime = %s%u%s\n", i_0, KMAG, t->GroupMDEntries[i_0].MDEntryTime.value, RESET_COLOR);
        }

        printf("\n");
#endif

#ifdef DEBUG3
        getchar();
#endif

//nopmap_uint32_nullable_noop OrigTime
#ifdef DEBUG2
        int t_GroupMDEntries_i_0_OrigTime_start = *offset;
#endif

        //>>> OrigTime
        if (packet[*offset] == 0x80)
        {
            t->GroupMDEntries[i_0].OrigTime.is_null = 1;
            t->GroupMDEntries[i_0].OrigTime.value = 0;
            (*offset)++;
        }
        else
        {
            t->GroupMDEntries[i_0].OrigTime.value = 0;
            t->GroupMDEntries[i_0].OrigTime.is_null = 0;
            while (!((packet[*offset] & 0x80)))
            {
                (t->GroupMDEntries[i_0].OrigTime.value) |= packet[(*offset)++];
                (t->GroupMDEntries[i_0].OrigTime.value) <<= 7;
            }
            (t->GroupMDEntries[i_0].OrigTime.value) |= (packet[(*offset)++] & 0x7f);
            (t->GroupMDEntries[i_0].OrigTime.value)--;
        }
        //<<<

#ifdef DEBUG

        if (t->GroupMDEntries[i_0].OrigTime.is_null)
        {
            printf("t->GroupMDEntries[%d].OrigTime = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
        }
        else
        {
            printf("t->GroupMDEntries[%d].OrigTime = %s%u%s\n", i_0, KMAG, t->GroupMDEntries[i_0].OrigTime.value, RESET_COLOR);
        }

#endif

#ifdef DEBUG1
        printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
        printf("name = %sOrigTime%s\n", KRED, RESET_COLOR);
        printf("type = %snopmap_uint32_nullable_noop\n%s", KBLU, RESET_COLOR);
        printf("byte_representation: ");
        printf("%s", COLOR_BYTES);
        for (int i = t_GroupMDEntries_i_0_OrigTime_start; i < *offset; i++)
        {
            printf("%02x ", packet[i]);
        }
        printf("%s\n", RESET_COLOR);

        if (t->GroupMDEntries[i_0].OrigTime.is_null)
        {
            printf("t->GroupMDEntries[%d].OrigTime = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
        }
        else
        {
            printf("t->GroupMDEntries[%d].OrigTime = %s%u%s\n", i_0, KMAG, t->GroupMDEntries[i_0].OrigTime.value, RESET_COLOR);
        }

        printf("\n");
#endif

#ifdef DEBUG3
        getchar();
#endif

//nopmap_string_nullable_noop OrderSide
#ifdef DEBUG2
        int t_GroupMDEntries_i_0_OrderSide_start = *offset;
#endif

        //>>> OrderSide
        t->GroupMDEntries[i_0].OrderSide.start = packet + *offset;
        if (packet[*offset] == 0x80)
        {
            (*offset)++;
            t->GroupMDEntries[i_0].OrderSide.len = 0;
            t->GroupMDEntries[i_0].OrderSide.is_null = 1;
            //printf("t->GroupMDEntries[i_0].OrderSide = EMPTY \n");
        }
        else
        {
            t->GroupMDEntries[i_0].OrderSide.len = 0;
            t->GroupMDEntries[i_0].OrderSide.is_null = 0;
            while (!((packet[(*offset)] & 0x80)))
            {
                t->GroupMDEntries[i_0].OrderSide.len++;
                (*offset)++;
            }
            packet[*offset] = packet[*offset] & 0x7F;
            (*offset)++;
            t->GroupMDEntries[i_0].OrderSide.len++;
        }
        //<<<

#ifdef DEBUG

        if (1)
        {

            if (t->GroupMDEntries[i_0].OrderSide.is_null)
            {
                printf("t->GroupMDEntries[%d].OrderSide = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
            }
            else
            {
                unsigned char fake[128];
                strncpy(fake, t->GroupMDEntries[i_0].OrderSide.start, t->GroupMDEntries[i_0].OrderSide.len);
                fake[t->GroupMDEntries[i_0].OrderSide.len] = '\0';
                printf("t->GroupMDEntries[%d].OrderSide = %s%s%s\n", i_0, KMAG, fake, RESET_COLOR);
            }
        }

#endif

#ifdef DEBUG1
        printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
        printf("name = %sOrderSide%s\n", KRED, RESET_COLOR);
        printf("type = %s nopmap_string_nullable_noop\n%s", KBLU, RESET_COLOR);
        printf("byte_representation: ");
        printf("%s", COLOR_BYTES);
        for (int i = t_GroupMDEntries_i_0_OrderSide_start; i < *offset; i++)
        {
            printf("%02x ", packet[i]);
        }
        printf("%s\n", RESET_COLOR);

        if (1)
        {

            if (t->GroupMDEntries[i_0].OrderSide.is_null)
            {
                printf("t->GroupMDEntries[%d].OrderSide = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
            }
            else
            {
                unsigned char fake[128];
                strncpy(fake, t->GroupMDEntries[i_0].OrderSide.start, t->GroupMDEntries[i_0].OrderSide.len);
                fake[t->GroupMDEntries[i_0].OrderSide.len] = '\0';
                printf("t->GroupMDEntries[%d].OrderSide = %s%s%s\n", i_0, KMAG, fake, RESET_COLOR);
            }
        }

        printf("\n");
#endif

#ifdef DEBUG3
        getchar();
#endif

        //nopmap_decimal_nullable_noop

//nopmap_int32_nullable_noop MDEntryPx
#ifdef DEBUG2
        int t_GroupMDEntries_i_0_MDEntryPxexponenta_start = *offset;
#endif

        //>>> MDEntryPx
        if (packet[*offset] == 0x80)
        {
            (*offset)++;
            t->GroupMDEntries[i_0].MDEntryPx.exponenta.is_null = 1;
        }
        else
        {
            t->GroupMDEntries[i_0].MDEntryPx.exponenta.value = 0 - (packet[*offset] & 0x40);
            t->GroupMDEntries[i_0].MDEntryPx.exponenta.is_null = 0;
            while (!((packet[*offset] & 0x80)))
            {
                (t->GroupMDEntries[i_0].MDEntryPx.exponenta.value) |= packet[(*offset)++];
                (t->GroupMDEntries[i_0].MDEntryPx.exponenta.value) <<= 7;
            }
            (t->GroupMDEntries[i_0].MDEntryPx.exponenta.value) |= (packet[(*offset)++] & 0x7f);
            if (t->GroupMDEntries[i_0].MDEntryPx.exponenta.value > 0)
            {
                (t->GroupMDEntries[i_0].MDEntryPx.exponenta.value)--;
            }
        }
        //<<<

#ifdef DEBUG

        if (t->GroupMDEntries[i_0].MDEntryPx.exponenta.is_null)
        {
            printf("t->GroupMDEntries[%d].MDEntryPx.exponenta = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
        }
        else
        {
            printf("t->GroupMDEntries[%d].MDEntryPx.exponenta = %s%d%s\n", i_0, KMAG, t->GroupMDEntries[i_0].MDEntryPx.exponenta.value, RESET_COLOR);
        }

#endif

#ifdef DEBUG1
        printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
        printf("name = %sMDEntryPx%s\n", KRED, RESET_COLOR);
        printf("type = %snopmap_int32_nullable_noop\n%s", KBLU, RESET_COLOR);
        printf("byte_representation: ");
        printf("%s", COLOR_BYTES);
        for (int i = t_GroupMDEntries_i_0_MDEntryPxexponenta_start; i < *offset; i++)
        {
            printf("%02x ", packet[i]);
        }
        printf("%s\n", RESET_COLOR);

        if (t->GroupMDEntries[i_0].MDEntryPx.exponenta.is_null)
        {
            printf("t->GroupMDEntries[%d].MDEntryPx.exponenta = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
        }
        else
        {
            printf("t->GroupMDEntries[%d].MDEntryPx.exponenta = %s%d%s\n", i_0, KMAG, t->GroupMDEntries[i_0].MDEntryPx.exponenta.value, RESET_COLOR);
        }

        printf("\n");
#endif

#ifdef DEBUG3
        getchar();
#endif

        if (!t->GroupMDEntries[i_0].MDEntryPx.exponenta.is_null)
        {
            //calc mantissa
            //nopmap_int64_nonullable_noop MDEntryPx
#ifdef DEBUG2
            int t_GroupMDEntries_i_0_MDEntryPxmantissa_start = *offset;
#endif

            //>>> MDEntryPx
            t->GroupMDEntries[i_0].MDEntryPx.mantissa = 0 - (packet[*offset] & 0x40);
            while (!((packet[*offset] & 0x80)))
            {
                t->GroupMDEntries[i_0].MDEntryPx.mantissa |= packet[(*offset)++];
                t->GroupMDEntries[i_0].MDEntryPx.mantissa <<= 7;
            }
            t->GroupMDEntries[i_0].MDEntryPx.mantissa |= (packet[(*offset)++] & 0x7f);
            //<<<

#ifdef DEBUG
            printf("t->GroupMDEntries[%d].MDEntryPx.mantissa = %ld\n", i_0, t->GroupMDEntries[i_0].MDEntryPx.mantissa);
#endif

#ifdef DEBUG1
            printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
            printf("name = %sMDEntryPx%s\n", KRED, RESET_COLOR);
            printf("type = %snopmap_int64_nonullable_noop\n%s", KBLU, RESET_COLOR);
            printf("byte_representation: ");
            printf("%s", COLOR_BYTES);
            for (int i = t_GroupMDEntries_i_0_MDEntryPxmantissa_start; i < *offset; i++)
            {
                printf("%02x ", packet[i]);
            }
            printf("%s\n", RESET_COLOR);
            printf("value = %s%ld%s\n", KMAG, t->GroupMDEntries[i_0].MDEntryPx.mantissa, RESET_COLOR);
            printf("\n");
#endif

#ifdef DEBUG3
            getchar();
#endif
        }

        //nopmap_decimal_nullable_noop

//nopmap_int32_nullable_noop MDEntrySize
#ifdef DEBUG2
        int t_GroupMDEntries_i_0_MDEntrySizeexponenta_start = *offset;
#endif

        //>>> MDEntrySize
        if (packet[*offset] == 0x80)
        {
            (*offset)++;
            t->GroupMDEntries[i_0].MDEntrySize.exponenta.is_null = 1;
        }
        else
        {
            t->GroupMDEntries[i_0].MDEntrySize.exponenta.value = 0 - (packet[*offset] & 0x40);
            t->GroupMDEntries[i_0].MDEntrySize.exponenta.is_null = 0;
            while (!((packet[*offset] & 0x80)))
            {
                (t->GroupMDEntries[i_0].MDEntrySize.exponenta.value) |= packet[(*offset)++];
                (t->GroupMDEntries[i_0].MDEntrySize.exponenta.value) <<= 7;
            }
            (t->GroupMDEntries[i_0].MDEntrySize.exponenta.value) |= (packet[(*offset)++] & 0x7f);
            if (t->GroupMDEntries[i_0].MDEntrySize.exponenta.value > 0)
            {
                (t->GroupMDEntries[i_0].MDEntrySize.exponenta.value)--;
            }
        }
        //<<<

#ifdef DEBUG

        if (t->GroupMDEntries[i_0].MDEntrySize.exponenta.is_null)
        {
            printf("t->GroupMDEntries[%d].MDEntrySize.exponenta = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
        }
        else
        {
            printf("t->GroupMDEntries[%d].MDEntrySize.exponenta = %s%d%s\n", i_0, KMAG, t->GroupMDEntries[i_0].MDEntrySize.exponenta.value, RESET_COLOR);
        }

#endif

#ifdef DEBUG1
        printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
        printf("name = %sMDEntrySize%s\n", KRED, RESET_COLOR);
        printf("type = %snopmap_int32_nullable_noop\n%s", KBLU, RESET_COLOR);
        printf("byte_representation: ");
        printf("%s", COLOR_BYTES);
        for (int i = t_GroupMDEntries_i_0_MDEntrySizeexponenta_start; i < *offset; i++)
        {
            printf("%02x ", packet[i]);
        }
        printf("%s\n", RESET_COLOR);

        if (t->GroupMDEntries[i_0].MDEntrySize.exponenta.is_null)
        {
            printf("t->GroupMDEntries[%d].MDEntrySize.exponenta = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
        }
        else
        {
            printf("t->GroupMDEntries[%d].MDEntrySize.exponenta = %s%d%s\n", i_0, KMAG, t->GroupMDEntries[i_0].MDEntrySize.exponenta.value, RESET_COLOR);
        }

        printf("\n");
#endif

#ifdef DEBUG3
        getchar();
#endif

        if (!t->GroupMDEntries[i_0].MDEntrySize.exponenta.is_null)
        {
            //calc mantissa
            //nopmap_int64_nonullable_noop MDEntrySize
#ifdef DEBUG2
            int t_GroupMDEntries_i_0_MDEntrySizemantissa_start = *offset;
#endif

            //>>> MDEntrySize
            t->GroupMDEntries[i_0].MDEntrySize.mantissa = 0 - (packet[*offset] & 0x40);
            while (!((packet[*offset] & 0x80)))
            {
                t->GroupMDEntries[i_0].MDEntrySize.mantissa |= packet[(*offset)++];
                t->GroupMDEntries[i_0].MDEntrySize.mantissa <<= 7;
            }
            t->GroupMDEntries[i_0].MDEntrySize.mantissa |= (packet[(*offset)++] & 0x7f);
            //<<<

#ifdef DEBUG
            printf("t->GroupMDEntries[%d].MDEntrySize.mantissa = %ld\n", i_0, t->GroupMDEntries[i_0].MDEntrySize.mantissa);
#endif

#ifdef DEBUG1
            printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
            printf("name = %sMDEntrySize%s\n", KRED, RESET_COLOR);
            printf("type = %snopmap_int64_nonullable_noop\n%s", KBLU, RESET_COLOR);
            printf("byte_representation: ");
            printf("%s", COLOR_BYTES);
            for (int i = t_GroupMDEntries_i_0_MDEntrySizemantissa_start; i < *offset; i++)
            {
                printf("%02x ", packet[i]);
            }
            printf("%s\n", RESET_COLOR);
            printf("value = %s%ld%s\n", KMAG, t->GroupMDEntries[i_0].MDEntrySize.mantissa, RESET_COLOR);
            printf("\n");
#endif

#ifdef DEBUG3
            getchar();
#endif
        }

        //nopmap_decimal_nullable_noop

//nopmap_int32_nullable_noop AccruedInterestAmt
#ifdef DEBUG2
        int t_GroupMDEntries_i_0_AccruedInterestAmtexponenta_start = *offset;
#endif

        //>>> AccruedInterestAmt
        if (packet[*offset] == 0x80)
        {
            (*offset)++;
            t->GroupMDEntries[i_0].AccruedInterestAmt.exponenta.is_null = 1;
        }
        else
        {
            t->GroupMDEntries[i_0].AccruedInterestAmt.exponenta.value = 0 - (packet[*offset] & 0x40);
            t->GroupMDEntries[i_0].AccruedInterestAmt.exponenta.is_null = 0;
            while (!((packet[*offset] & 0x80)))
            {
                (t->GroupMDEntries[i_0].AccruedInterestAmt.exponenta.value) |= packet[(*offset)++];
                (t->GroupMDEntries[i_0].AccruedInterestAmt.exponenta.value) <<= 7;
            }
            (t->GroupMDEntries[i_0].AccruedInterestAmt.exponenta.value) |= (packet[(*offset)++] & 0x7f);
            if (t->GroupMDEntries[i_0].AccruedInterestAmt.exponenta.value > 0)
            {
                (t->GroupMDEntries[i_0].AccruedInterestAmt.exponenta.value)--;
            }
        }
        //<<<

#ifdef DEBUG

        if (t->GroupMDEntries[i_0].AccruedInterestAmt.exponenta.is_null)
        {
            printf("t->GroupMDEntries[%d].AccruedInterestAmt.exponenta = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
        }
        else
        {
            printf("t->GroupMDEntries[%d].AccruedInterestAmt.exponenta = %s%d%s\n", i_0, KMAG, t->GroupMDEntries[i_0].AccruedInterestAmt.exponenta.value, RESET_COLOR);
        }

#endif

#ifdef DEBUG1
        printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
        printf("name = %sAccruedInterestAmt%s\n", KRED, RESET_COLOR);
        printf("type = %snopmap_int32_nullable_noop\n%s", KBLU, RESET_COLOR);
        printf("byte_representation: ");
        printf("%s", COLOR_BYTES);
        for (int i = t_GroupMDEntries_i_0_AccruedInterestAmtexponenta_start; i < *offset; i++)
        {
            printf("%02x ", packet[i]);
        }
        printf("%s\n", RESET_COLOR);

        if (t->GroupMDEntries[i_0].AccruedInterestAmt.exponenta.is_null)
        {
            printf("t->GroupMDEntries[%d].AccruedInterestAmt.exponenta = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
        }
        else
        {
            printf("t->GroupMDEntries[%d].AccruedInterestAmt.exponenta = %s%d%s\n", i_0, KMAG, t->GroupMDEntries[i_0].AccruedInterestAmt.exponenta.value, RESET_COLOR);
        }

        printf("\n");
#endif

#ifdef DEBUG3
        getchar();
#endif

        if (!t->GroupMDEntries[i_0].AccruedInterestAmt.exponenta.is_null)
        {
            //calc mantissa
            //nopmap_int64_nonullable_noop AccruedInterestAmt
#ifdef DEBUG2
            int t_GroupMDEntries_i_0_AccruedInterestAmtmantissa_start = *offset;
#endif

            //>>> AccruedInterestAmt
            t->GroupMDEntries[i_0].AccruedInterestAmt.mantissa = 0 - (packet[*offset] & 0x40);
            while (!((packet[*offset] & 0x80)))
            {
                t->GroupMDEntries[i_0].AccruedInterestAmt.mantissa |= packet[(*offset)++];
                t->GroupMDEntries[i_0].AccruedInterestAmt.mantissa <<= 7;
            }
            t->GroupMDEntries[i_0].AccruedInterestAmt.mantissa |= (packet[(*offset)++] & 0x7f);
            //<<<

#ifdef DEBUG
            printf("t->GroupMDEntries[%d].AccruedInterestAmt.mantissa = %ld\n", i_0, t->GroupMDEntries[i_0].AccruedInterestAmt.mantissa);
#endif

#ifdef DEBUG1
            printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
            printf("name = %sAccruedInterestAmt%s\n", KRED, RESET_COLOR);
            printf("type = %snopmap_int64_nonullable_noop\n%s", KBLU, RESET_COLOR);
            printf("byte_representation: ");
            printf("%s", COLOR_BYTES);
            for (int i = t_GroupMDEntries_i_0_AccruedInterestAmtmantissa_start; i < *offset; i++)
            {
                printf("%02x ", packet[i]);
            }
            printf("%s\n", RESET_COLOR);
            printf("value = %s%ld%s\n", KMAG, t->GroupMDEntries[i_0].AccruedInterestAmt.mantissa, RESET_COLOR);
            printf("\n");
#endif

#ifdef DEBUG3
            getchar();
#endif
        }

        //nopmap_decimal_nullable_noop

//nopmap_int32_nullable_noop TradeValue
#ifdef DEBUG2
        int t_GroupMDEntries_i_0_TradeValueexponenta_start = *offset;
#endif

        //>>> TradeValue
        if (packet[*offset] == 0x80)
        {
            (*offset)++;
            t->GroupMDEntries[i_0].TradeValue.exponenta.is_null = 1;
        }
        else
        {
            t->GroupMDEntries[i_0].TradeValue.exponenta.value = 0 - (packet[*offset] & 0x40);
            t->GroupMDEntries[i_0].TradeValue.exponenta.is_null = 0;
            while (!((packet[*offset] & 0x80)))
            {
                (t->GroupMDEntries[i_0].TradeValue.exponenta.value) |= packet[(*offset)++];
                (t->GroupMDEntries[i_0].TradeValue.exponenta.value) <<= 7;
            }
            (t->GroupMDEntries[i_0].TradeValue.exponenta.value) |= (packet[(*offset)++] & 0x7f);
            if (t->GroupMDEntries[i_0].TradeValue.exponenta.value > 0)
            {
                (t->GroupMDEntries[i_0].TradeValue.exponenta.value)--;
            }
        }
        //<<<

#ifdef DEBUG

        if (t->GroupMDEntries[i_0].TradeValue.exponenta.is_null)
        {
            printf("t->GroupMDEntries[%d].TradeValue.exponenta = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
        }
        else
        {
            printf("t->GroupMDEntries[%d].TradeValue.exponenta = %s%d%s\n", i_0, KMAG, t->GroupMDEntries[i_0].TradeValue.exponenta.value, RESET_COLOR);
        }

#endif

#ifdef DEBUG1
        printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
        printf("name = %sTradeValue%s\n", KRED, RESET_COLOR);
        printf("type = %snopmap_int32_nullable_noop\n%s", KBLU, RESET_COLOR);
        printf("byte_representation: ");
        printf("%s", COLOR_BYTES);
        for (int i = t_GroupMDEntries_i_0_TradeValueexponenta_start; i < *offset; i++)
        {
            printf("%02x ", packet[i]);
        }
        printf("%s\n", RESET_COLOR);

        if (t->GroupMDEntries[i_0].TradeValue.exponenta.is_null)
        {
            printf("t->GroupMDEntries[%d].TradeValue.exponenta = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
        }
        else
        {
            printf("t->GroupMDEntries[%d].TradeValue.exponenta = %s%d%s\n", i_0, KMAG, t->GroupMDEntries[i_0].TradeValue.exponenta.value, RESET_COLOR);
        }

        printf("\n");
#endif

#ifdef DEBUG3
        getchar();
#endif

        if (!t->GroupMDEntries[i_0].TradeValue.exponenta.is_null)
        {
            //calc mantissa
            //nopmap_int64_nonullable_noop TradeValue
#ifdef DEBUG2
            int t_GroupMDEntries_i_0_TradeValuemantissa_start = *offset;
#endif

            //>>> TradeValue
            t->GroupMDEntries[i_0].TradeValue.mantissa = 0 - (packet[*offset] & 0x40);
            while (!((packet[*offset] & 0x80)))
            {
                t->GroupMDEntries[i_0].TradeValue.mantissa |= packet[(*offset)++];
                t->GroupMDEntries[i_0].TradeValue.mantissa <<= 7;
            }
            t->GroupMDEntries[i_0].TradeValue.mantissa |= (packet[(*offset)++] & 0x7f);
            //<<<

#ifdef DEBUG
            printf("t->GroupMDEntries[%d].TradeValue.mantissa = %ld\n", i_0, t->GroupMDEntries[i_0].TradeValue.mantissa);
#endif

#ifdef DEBUG1
            printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
            printf("name = %sTradeValue%s\n", KRED, RESET_COLOR);
            printf("type = %snopmap_int64_nonullable_noop\n%s", KBLU, RESET_COLOR);
            printf("byte_representation: ");
            printf("%s", COLOR_BYTES);
            for (int i = t_GroupMDEntries_i_0_TradeValuemantissa_start; i < *offset; i++)
            {
                printf("%02x ", packet[i]);
            }
            printf("%s\n", RESET_COLOR);
            printf("value = %s%ld%s\n", KMAG, t->GroupMDEntries[i_0].TradeValue.mantissa, RESET_COLOR);
            printf("\n");
#endif

#ifdef DEBUG3
            getchar();
#endif
        }

        //nopmap_decimal_nullable_noop

//nopmap_int32_nullable_noop Yield
#ifdef DEBUG2
        int t_GroupMDEntries_i_0_Yieldexponenta_start = *offset;
#endif

        //>>> Yield
        if (packet[*offset] == 0x80)
        {
            (*offset)++;
            t->GroupMDEntries[i_0].Yield.exponenta.is_null = 1;
        }
        else
        {
            t->GroupMDEntries[i_0].Yield.exponenta.value = 0 - (packet[*offset] & 0x40);
            t->GroupMDEntries[i_0].Yield.exponenta.is_null = 0;
            while (!((packet[*offset] & 0x80)))
            {
                (t->GroupMDEntries[i_0].Yield.exponenta.value) |= packet[(*offset)++];
                (t->GroupMDEntries[i_0].Yield.exponenta.value) <<= 7;
            }
            (t->GroupMDEntries[i_0].Yield.exponenta.value) |= (packet[(*offset)++] & 0x7f);
            if (t->GroupMDEntries[i_0].Yield.exponenta.value > 0)
            {
                (t->GroupMDEntries[i_0].Yield.exponenta.value)--;
            }
        }
        //<<<

#ifdef DEBUG

        if (t->GroupMDEntries[i_0].Yield.exponenta.is_null)
        {
            printf("t->GroupMDEntries[%d].Yield.exponenta = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
        }
        else
        {
            printf("t->GroupMDEntries[%d].Yield.exponenta = %s%d%s\n", i_0, KMAG, t->GroupMDEntries[i_0].Yield.exponenta.value, RESET_COLOR);
        }

#endif

#ifdef DEBUG1
        printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
        printf("name = %sYield%s\n", KRED, RESET_COLOR);
        printf("type = %snopmap_int32_nullable_noop\n%s", KBLU, RESET_COLOR);
        printf("byte_representation: ");
        printf("%s", COLOR_BYTES);
        for (int i = t_GroupMDEntries_i_0_Yieldexponenta_start; i < *offset; i++)
        {
            printf("%02x ", packet[i]);
        }
        printf("%s\n", RESET_COLOR);

        if (t->GroupMDEntries[i_0].Yield.exponenta.is_null)
        {
            printf("t->GroupMDEntries[%d].Yield.exponenta = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
        }
        else
        {
            printf("t->GroupMDEntries[%d].Yield.exponenta = %s%d%s\n", i_0, KMAG, t->GroupMDEntries[i_0].Yield.exponenta.value, RESET_COLOR);
        }

        printf("\n");
#endif

#ifdef DEBUG3
        getchar();
#endif

        if (!t->GroupMDEntries[i_0].Yield.exponenta.is_null)
        {
            //calc mantissa
            //nopmap_int64_nonullable_noop Yield
#ifdef DEBUG2
            int t_GroupMDEntries_i_0_Yieldmantissa_start = *offset;
#endif

            //>>> Yield
            t->GroupMDEntries[i_0].Yield.mantissa = 0 - (packet[*offset] & 0x40);
            while (!((packet[*offset] & 0x80)))
            {
                t->GroupMDEntries[i_0].Yield.mantissa |= packet[(*offset)++];
                t->GroupMDEntries[i_0].Yield.mantissa <<= 7;
            }
            t->GroupMDEntries[i_0].Yield.mantissa |= (packet[(*offset)++] & 0x7f);
            //<<<

#ifdef DEBUG
            printf("t->GroupMDEntries[%d].Yield.mantissa = %ld\n", i_0, t->GroupMDEntries[i_0].Yield.mantissa);
#endif

#ifdef DEBUG1
            printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
            printf("name = %sYield%s\n", KRED, RESET_COLOR);
            printf("type = %snopmap_int64_nonullable_noop\n%s", KBLU, RESET_COLOR);
            printf("byte_representation: ");
            printf("%s", COLOR_BYTES);
            for (int i = t_GroupMDEntries_i_0_Yieldmantissa_start; i < *offset; i++)
            {
                printf("%02x ", packet[i]);
            }
            printf("%s\n", RESET_COLOR);
            printf("value = %s%ld%s\n", KMAG, t->GroupMDEntries[i_0].Yield.mantissa, RESET_COLOR);
            printf("\n");
#endif

#ifdef DEBUG3
            getchar();
#endif
        }

//nopmap_uint32_nullable_noop SettlDate
#ifdef DEBUG2
        int t_GroupMDEntries_i_0_SettlDate_start = *offset;
#endif

        //>>> SettlDate
        if (packet[*offset] == 0x80)
        {
            t->GroupMDEntries[i_0].SettlDate.is_null = 1;
            t->GroupMDEntries[i_0].SettlDate.value = 0;
            (*offset)++;
        }
        else
        {
            t->GroupMDEntries[i_0].SettlDate.value = 0;
            t->GroupMDEntries[i_0].SettlDate.is_null = 0;
            while (!((packet[*offset] & 0x80)))
            {
                (t->GroupMDEntries[i_0].SettlDate.value) |= packet[(*offset)++];
                (t->GroupMDEntries[i_0].SettlDate.value) <<= 7;
            }
            (t->GroupMDEntries[i_0].SettlDate.value) |= (packet[(*offset)++] & 0x7f);
            (t->GroupMDEntries[i_0].SettlDate.value)--;
        }
        //<<<

#ifdef DEBUG

        if (t->GroupMDEntries[i_0].SettlDate.is_null)
        {
            printf("t->GroupMDEntries[%d].SettlDate = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
        }
        else
        {
            printf("t->GroupMDEntries[%d].SettlDate = %s%u%s\n", i_0, KMAG, t->GroupMDEntries[i_0].SettlDate.value, RESET_COLOR);
        }

#endif

#ifdef DEBUG1
        printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
        printf("name = %sSettlDate%s\n", KRED, RESET_COLOR);
        printf("type = %snopmap_uint32_nullable_noop\n%s", KBLU, RESET_COLOR);
        printf("byte_representation: ");
        printf("%s", COLOR_BYTES);
        for (int i = t_GroupMDEntries_i_0_SettlDate_start; i < *offset; i++)
        {
            printf("%02x ", packet[i]);
        }
        printf("%s\n", RESET_COLOR);

        if (t->GroupMDEntries[i_0].SettlDate.is_null)
        {
            printf("t->GroupMDEntries[%d].SettlDate = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
        }
        else
        {
            printf("t->GroupMDEntries[%d].SettlDate = %s%u%s\n", i_0, KMAG, t->GroupMDEntries[i_0].SettlDate.value, RESET_COLOR);
        }

        printf("\n");
#endif

#ifdef DEBUG3
        getchar();
#endif

//nopmap_string_nullable_noop SettleType
#ifdef DEBUG2
        int t_GroupMDEntries_i_0_SettleType_start = *offset;
#endif

        //>>> SettleType
        t->GroupMDEntries[i_0].SettleType.start = packet + *offset;
        if (packet[*offset] == 0x80)
        {
            (*offset)++;
            t->GroupMDEntries[i_0].SettleType.len = 0;
            t->GroupMDEntries[i_0].SettleType.is_null = 1;
            //printf("t->GroupMDEntries[i_0].SettleType = EMPTY \n");
        }
        else
        {
            t->GroupMDEntries[i_0].SettleType.len = 0;
            t->GroupMDEntries[i_0].SettleType.is_null = 0;
            while (!((packet[(*offset)] & 0x80)))
            {
                t->GroupMDEntries[i_0].SettleType.len++;
                (*offset)++;
            }
            packet[*offset] = packet[*offset] & 0x7F;
            (*offset)++;
            t->GroupMDEntries[i_0].SettleType.len++;
        }
        //<<<

#ifdef DEBUG

        if (1)
        {

            if (t->GroupMDEntries[i_0].SettleType.is_null)
            {
                printf("t->GroupMDEntries[%d].SettleType = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
            }
            else
            {
                unsigned char fake[128];
                strncpy(fake, t->GroupMDEntries[i_0].SettleType.start, t->GroupMDEntries[i_0].SettleType.len);
                fake[t->GroupMDEntries[i_0].SettleType.len] = '\0';
                printf("t->GroupMDEntries[%d].SettleType = %s%s%s\n", i_0, KMAG, fake, RESET_COLOR);
            }
        }

#endif

#ifdef DEBUG1
        printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
        printf("name = %sSettleType%s\n", KRED, RESET_COLOR);
        printf("type = %s nopmap_string_nullable_noop\n%s", KBLU, RESET_COLOR);
        printf("byte_representation: ");
        printf("%s", COLOR_BYTES);
        for (int i = t_GroupMDEntries_i_0_SettleType_start; i < *offset; i++)
        {
            printf("%02x ", packet[i]);
        }
        printf("%s\n", RESET_COLOR);

        if (1)
        {

            if (t->GroupMDEntries[i_0].SettleType.is_null)
            {
                printf("t->GroupMDEntries[%d].SettleType = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
            }
            else
            {
                unsigned char fake[128];
                strncpy(fake, t->GroupMDEntries[i_0].SettleType.start, t->GroupMDEntries[i_0].SettleType.len);
                fake[t->GroupMDEntries[i_0].SettleType.len] = '\0';
                printf("t->GroupMDEntries[%d].SettleType = %s%s%s\n", i_0, KMAG, fake, RESET_COLOR);
            }
        }

        printf("\n");
#endif

#ifdef DEBUG3
        getchar();
#endif

        //nopmap_decimal_nullable_noop

//nopmap_int32_nullable_noop Price
#ifdef DEBUG2
        int t_GroupMDEntries_i_0_Priceexponenta_start = *offset;
#endif

        //>>> Price
        if (packet[*offset] == 0x80)
        {
            (*offset)++;
            t->GroupMDEntries[i_0].Price.exponenta.is_null = 1;
        }
        else
        {
            t->GroupMDEntries[i_0].Price.exponenta.value = 0 - (packet[*offset] & 0x40);
            t->GroupMDEntries[i_0].Price.exponenta.is_null = 0;
            while (!((packet[*offset] & 0x80)))
            {
                (t->GroupMDEntries[i_0].Price.exponenta.value) |= packet[(*offset)++];
                (t->GroupMDEntries[i_0].Price.exponenta.value) <<= 7;
            }
            (t->GroupMDEntries[i_0].Price.exponenta.value) |= (packet[(*offset)++] & 0x7f);
            if (t->GroupMDEntries[i_0].Price.exponenta.value > 0)
            {
                (t->GroupMDEntries[i_0].Price.exponenta.value)--;
            }
        }
        //<<<

#ifdef DEBUG

        if (t->GroupMDEntries[i_0].Price.exponenta.is_null)
        {
            printf("t->GroupMDEntries[%d].Price.exponenta = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
        }
        else
        {
            printf("t->GroupMDEntries[%d].Price.exponenta = %s%d%s\n", i_0, KMAG, t->GroupMDEntries[i_0].Price.exponenta.value, RESET_COLOR);
        }

#endif

#ifdef DEBUG1
        printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
        printf("name = %sPrice%s\n", KRED, RESET_COLOR);
        printf("type = %snopmap_int32_nullable_noop\n%s", KBLU, RESET_COLOR);
        printf("byte_representation: ");
        printf("%s", COLOR_BYTES);
        for (int i = t_GroupMDEntries_i_0_Priceexponenta_start; i < *offset; i++)
        {
            printf("%02x ", packet[i]);
        }
        printf("%s\n", RESET_COLOR);

        if (t->GroupMDEntries[i_0].Price.exponenta.is_null)
        {
            printf("t->GroupMDEntries[%d].Price.exponenta = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
        }
        else
        {
            printf("t->GroupMDEntries[%d].Price.exponenta = %s%d%s\n", i_0, KMAG, t->GroupMDEntries[i_0].Price.exponenta.value, RESET_COLOR);
        }

        printf("\n");
#endif

#ifdef DEBUG3
        getchar();
#endif

        if (!t->GroupMDEntries[i_0].Price.exponenta.is_null)
        {
            //calc mantissa
            //nopmap_int64_nonullable_noop Price
#ifdef DEBUG2
            int t_GroupMDEntries_i_0_Pricemantissa_start = *offset;
#endif

            //>>> Price
            t->GroupMDEntries[i_0].Price.mantissa = 0 - (packet[*offset] & 0x40);
            while (!((packet[*offset] & 0x80)))
            {
                t->GroupMDEntries[i_0].Price.mantissa |= packet[(*offset)++];
                t->GroupMDEntries[i_0].Price.mantissa <<= 7;
            }
            t->GroupMDEntries[i_0].Price.mantissa |= (packet[(*offset)++] & 0x7f);
            //<<<

#ifdef DEBUG
            printf("t->GroupMDEntries[%d].Price.mantissa = %ld\n", i_0, t->GroupMDEntries[i_0].Price.mantissa);
#endif

#ifdef DEBUG1
            printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
            printf("name = %sPrice%s\n", KRED, RESET_COLOR);
            printf("type = %snopmap_int64_nonullable_noop\n%s", KBLU, RESET_COLOR);
            printf("byte_representation: ");
            printf("%s", COLOR_BYTES);
            for (int i = t_GroupMDEntries_i_0_Pricemantissa_start; i < *offset; i++)
            {
                printf("%02x ", packet[i]);
            }
            printf("%s\n", RESET_COLOR);
            printf("value = %s%ld%s\n", KMAG, t->GroupMDEntries[i_0].Price.mantissa, RESET_COLOR);
            printf("\n");
#endif

#ifdef DEBUG3
            getchar();
#endif
        }

//nopmap_int32_nullable_noop PriceType
#ifdef DEBUG2
        int t_GroupMDEntries_i_0_PriceType_start = *offset;
#endif

        //>>> PriceType
        if (packet[*offset] == 0x80)
        {
            (*offset)++;
            t->GroupMDEntries[i_0].PriceType.is_null = 1;
        }
        else
        {
            t->GroupMDEntries[i_0].PriceType.value = 0 - (packet[*offset] & 0x40);
            t->GroupMDEntries[i_0].PriceType.is_null = 0;
            while (!((packet[*offset] & 0x80)))
            {
                (t->GroupMDEntries[i_0].PriceType.value) |= packet[(*offset)++];
                (t->GroupMDEntries[i_0].PriceType.value) <<= 7;
            }
            (t->GroupMDEntries[i_0].PriceType.value) |= (packet[(*offset)++] & 0x7f);
            if (t->GroupMDEntries[i_0].PriceType.value > 0)
            {
                (t->GroupMDEntries[i_0].PriceType.value)--;
            }
        }
        //<<<

#ifdef DEBUG

        if (t->GroupMDEntries[i_0].PriceType.is_null)
        {
            printf("t->GroupMDEntries[%d].PriceType = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
        }
        else
        {
            printf("t->GroupMDEntries[%d].PriceType = %s%d%s\n", i_0, KMAG, t->GroupMDEntries[i_0].PriceType.value, RESET_COLOR);
        }

#endif

#ifdef DEBUG1
        printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
        printf("name = %sPriceType%s\n", KRED, RESET_COLOR);
        printf("type = %snopmap_int32_nullable_noop\n%s", KBLU, RESET_COLOR);
        printf("byte_representation: ");
        printf("%s", COLOR_BYTES);
        for (int i = t_GroupMDEntries_i_0_PriceType_start; i < *offset; i++)
        {
            printf("%02x ", packet[i]);
        }
        printf("%s\n", RESET_COLOR);

        if (t->GroupMDEntries[i_0].PriceType.is_null)
        {
            printf("t->GroupMDEntries[%d].PriceType = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
        }
        else
        {
            printf("t->GroupMDEntries[%d].PriceType = %s%d%s\n", i_0, KMAG, t->GroupMDEntries[i_0].PriceType.value, RESET_COLOR);
        }

        printf("\n");
#endif

#ifdef DEBUG3
        getchar();
#endif

        //nopmap_decimal_nullable_noop

//nopmap_int32_nullable_noop RepoToPx
#ifdef DEBUG2
        int t_GroupMDEntries_i_0_RepoToPxexponenta_start = *offset;
#endif

        //>>> RepoToPx
        if (packet[*offset] == 0x80)
        {
            (*offset)++;
            t->GroupMDEntries[i_0].RepoToPx.exponenta.is_null = 1;
        }
        else
        {
            t->GroupMDEntries[i_0].RepoToPx.exponenta.value = 0 - (packet[*offset] & 0x40);
            t->GroupMDEntries[i_0].RepoToPx.exponenta.is_null = 0;
            while (!((packet[*offset] & 0x80)))
            {
                (t->GroupMDEntries[i_0].RepoToPx.exponenta.value) |= packet[(*offset)++];
                (t->GroupMDEntries[i_0].RepoToPx.exponenta.value) <<= 7;
            }
            (t->GroupMDEntries[i_0].RepoToPx.exponenta.value) |= (packet[(*offset)++] & 0x7f);
            if (t->GroupMDEntries[i_0].RepoToPx.exponenta.value > 0)
            {
                (t->GroupMDEntries[i_0].RepoToPx.exponenta.value)--;
            }
        }
        //<<<

#ifdef DEBUG

        if (t->GroupMDEntries[i_0].RepoToPx.exponenta.is_null)
        {
            printf("t->GroupMDEntries[%d].RepoToPx.exponenta = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
        }
        else
        {
            printf("t->GroupMDEntries[%d].RepoToPx.exponenta = %s%d%s\n", i_0, KMAG, t->GroupMDEntries[i_0].RepoToPx.exponenta.value, RESET_COLOR);
        }

#endif

#ifdef DEBUG1
        printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
        printf("name = %sRepoToPx%s\n", KRED, RESET_COLOR);
        printf("type = %snopmap_int32_nullable_noop\n%s", KBLU, RESET_COLOR);
        printf("byte_representation: ");
        printf("%s", COLOR_BYTES);
        for (int i = t_GroupMDEntries_i_0_RepoToPxexponenta_start; i < *offset; i++)
        {
            printf("%02x ", packet[i]);
        }
        printf("%s\n", RESET_COLOR);

        if (t->GroupMDEntries[i_0].RepoToPx.exponenta.is_null)
        {
            printf("t->GroupMDEntries[%d].RepoToPx.exponenta = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
        }
        else
        {
            printf("t->GroupMDEntries[%d].RepoToPx.exponenta = %s%d%s\n", i_0, KMAG, t->GroupMDEntries[i_0].RepoToPx.exponenta.value, RESET_COLOR);
        }

        printf("\n");
#endif

#ifdef DEBUG3
        getchar();
#endif

        if (!t->GroupMDEntries[i_0].RepoToPx.exponenta.is_null)
        {
            //calc mantissa
            //nopmap_int64_nonullable_noop RepoToPx
#ifdef DEBUG2
            int t_GroupMDEntries_i_0_RepoToPxmantissa_start = *offset;
#endif

            //>>> RepoToPx
            t->GroupMDEntries[i_0].RepoToPx.mantissa = 0 - (packet[*offset] & 0x40);
            while (!((packet[*offset] & 0x80)))
            {
                t->GroupMDEntries[i_0].RepoToPx.mantissa |= packet[(*offset)++];
                t->GroupMDEntries[i_0].RepoToPx.mantissa <<= 7;
            }
            t->GroupMDEntries[i_0].RepoToPx.mantissa |= (packet[(*offset)++] & 0x7f);
            //<<<

#ifdef DEBUG
            printf("t->GroupMDEntries[%d].RepoToPx.mantissa = %ld\n", i_0, t->GroupMDEntries[i_0].RepoToPx.mantissa);
#endif

#ifdef DEBUG1
            printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
            printf("name = %sRepoToPx%s\n", KRED, RESET_COLOR);
            printf("type = %snopmap_int64_nonullable_noop\n%s", KBLU, RESET_COLOR);
            printf("byte_representation: ");
            printf("%s", COLOR_BYTES);
            for (int i = t_GroupMDEntries_i_0_RepoToPxmantissa_start; i < *offset; i++)
            {
                printf("%02x ", packet[i]);
            }
            printf("%s\n", RESET_COLOR);
            printf("value = %s%ld%s\n", KMAG, t->GroupMDEntries[i_0].RepoToPx.mantissa, RESET_COLOR);
            printf("\n");
#endif

#ifdef DEBUG3
            getchar();
#endif
        }

        //nopmap_decimal_nullable_noop

//nopmap_int32_nullable_noop BuyBackPx
#ifdef DEBUG2
        int t_GroupMDEntries_i_0_BuyBackPxexponenta_start = *offset;
#endif

        //>>> BuyBackPx
        if (packet[*offset] == 0x80)
        {
            (*offset)++;
            t->GroupMDEntries[i_0].BuyBackPx.exponenta.is_null = 1;
        }
        else
        {
            t->GroupMDEntries[i_0].BuyBackPx.exponenta.value = 0 - (packet[*offset] & 0x40);
            t->GroupMDEntries[i_0].BuyBackPx.exponenta.is_null = 0;
            while (!((packet[*offset] & 0x80)))
            {
                (t->GroupMDEntries[i_0].BuyBackPx.exponenta.value) |= packet[(*offset)++];
                (t->GroupMDEntries[i_0].BuyBackPx.exponenta.value) <<= 7;
            }
            (t->GroupMDEntries[i_0].BuyBackPx.exponenta.value) |= (packet[(*offset)++] & 0x7f);
            if (t->GroupMDEntries[i_0].BuyBackPx.exponenta.value > 0)
            {
                (t->GroupMDEntries[i_0].BuyBackPx.exponenta.value)--;
            }
        }
        //<<<

#ifdef DEBUG

        if (t->GroupMDEntries[i_0].BuyBackPx.exponenta.is_null)
        {
            printf("t->GroupMDEntries[%d].BuyBackPx.exponenta = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
        }
        else
        {
            printf("t->GroupMDEntries[%d].BuyBackPx.exponenta = %s%d%s\n", i_0, KMAG, t->GroupMDEntries[i_0].BuyBackPx.exponenta.value, RESET_COLOR);
        }

#endif

#ifdef DEBUG1
        printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
        printf("name = %sBuyBackPx%s\n", KRED, RESET_COLOR);
        printf("type = %snopmap_int32_nullable_noop\n%s", KBLU, RESET_COLOR);
        printf("byte_representation: ");
        printf("%s", COLOR_BYTES);
        for (int i = t_GroupMDEntries_i_0_BuyBackPxexponenta_start; i < *offset; i++)
        {
            printf("%02x ", packet[i]);
        }
        printf("%s\n", RESET_COLOR);

        if (t->GroupMDEntries[i_0].BuyBackPx.exponenta.is_null)
        {
            printf("t->GroupMDEntries[%d].BuyBackPx.exponenta = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
        }
        else
        {
            printf("t->GroupMDEntries[%d].BuyBackPx.exponenta = %s%d%s\n", i_0, KMAG, t->GroupMDEntries[i_0].BuyBackPx.exponenta.value, RESET_COLOR);
        }

        printf("\n");
#endif

#ifdef DEBUG3
        getchar();
#endif

        if (!t->GroupMDEntries[i_0].BuyBackPx.exponenta.is_null)
        {
            //calc mantissa
            //nopmap_int64_nonullable_noop BuyBackPx
#ifdef DEBUG2
            int t_GroupMDEntries_i_0_BuyBackPxmantissa_start = *offset;
#endif

            //>>> BuyBackPx
            t->GroupMDEntries[i_0].BuyBackPx.mantissa = 0 - (packet[*offset] & 0x40);
            while (!((packet[*offset] & 0x80)))
            {
                t->GroupMDEntries[i_0].BuyBackPx.mantissa |= packet[(*offset)++];
                t->GroupMDEntries[i_0].BuyBackPx.mantissa <<= 7;
            }
            t->GroupMDEntries[i_0].BuyBackPx.mantissa |= (packet[(*offset)++] & 0x7f);
            //<<<

#ifdef DEBUG
            printf("t->GroupMDEntries[%d].BuyBackPx.mantissa = %ld\n", i_0, t->GroupMDEntries[i_0].BuyBackPx.mantissa);
#endif

#ifdef DEBUG1
            printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
            printf("name = %sBuyBackPx%s\n", KRED, RESET_COLOR);
            printf("type = %snopmap_int64_nonullable_noop\n%s", KBLU, RESET_COLOR);
            printf("byte_representation: ");
            printf("%s", COLOR_BYTES);
            for (int i = t_GroupMDEntries_i_0_BuyBackPxmantissa_start; i < *offset; i++)
            {
                printf("%02x ", packet[i]);
            }
            printf("%s\n", RESET_COLOR);
            printf("value = %s%ld%s\n", KMAG, t->GroupMDEntries[i_0].BuyBackPx.mantissa, RESET_COLOR);
            printf("\n");
#endif

#ifdef DEBUG3
            getchar();
#endif
        }

//nopmap_uint32_nullable_noop BuyBackDate
#ifdef DEBUG2
        int t_GroupMDEntries_i_0_BuyBackDate_start = *offset;
#endif

        //>>> BuyBackDate
        if (packet[*offset] == 0x80)
        {
            t->GroupMDEntries[i_0].BuyBackDate.is_null = 1;
            t->GroupMDEntries[i_0].BuyBackDate.value = 0;
            (*offset)++;
        }
        else
        {
            t->GroupMDEntries[i_0].BuyBackDate.value = 0;
            t->GroupMDEntries[i_0].BuyBackDate.is_null = 0;
            while (!((packet[*offset] & 0x80)))
            {
                (t->GroupMDEntries[i_0].BuyBackDate.value) |= packet[(*offset)++];
                (t->GroupMDEntries[i_0].BuyBackDate.value) <<= 7;
            }
            (t->GroupMDEntries[i_0].BuyBackDate.value) |= (packet[(*offset)++] & 0x7f);
            (t->GroupMDEntries[i_0].BuyBackDate.value)--;
        }
        //<<<

#ifdef DEBUG

        if (t->GroupMDEntries[i_0].BuyBackDate.is_null)
        {
            printf("t->GroupMDEntries[%d].BuyBackDate = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
        }
        else
        {
            printf("t->GroupMDEntries[%d].BuyBackDate = %s%u%s\n", i_0, KMAG, t->GroupMDEntries[i_0].BuyBackDate.value, RESET_COLOR);
        }

#endif

#ifdef DEBUG1
        printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
        printf("name = %sBuyBackDate%s\n", KRED, RESET_COLOR);
        printf("type = %snopmap_uint32_nullable_noop\n%s", KBLU, RESET_COLOR);
        printf("byte_representation: ");
        printf("%s", COLOR_BYTES);
        for (int i = t_GroupMDEntries_i_0_BuyBackDate_start; i < *offset; i++)
        {
            printf("%02x ", packet[i]);
        }
        printf("%s\n", RESET_COLOR);

        if (t->GroupMDEntries[i_0].BuyBackDate.is_null)
        {
            printf("t->GroupMDEntries[%d].BuyBackDate = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
        }
        else
        {
            printf("t->GroupMDEntries[%d].BuyBackDate = %s%u%s\n", i_0, KMAG, t->GroupMDEntries[i_0].BuyBackDate.value, RESET_COLOR);
        }

        printf("\n");
#endif

#ifdef DEBUG3
        getchar();
#endif

//nopmap_string_nullable_noop TradingSessionID
#ifdef DEBUG2
        int t_GroupMDEntries_i_0_TradingSessionID_start = *offset;
#endif

        //>>> TradingSessionID
        t->GroupMDEntries[i_0].TradingSessionID.start = packet + *offset;
        if (packet[*offset] == 0x80)
        {
            (*offset)++;
            t->GroupMDEntries[i_0].TradingSessionID.len = 0;
            t->GroupMDEntries[i_0].TradingSessionID.is_null = 1;
            //printf("t->GroupMDEntries[i_0].TradingSessionID = EMPTY \n");
        }
        else
        {
            t->GroupMDEntries[i_0].TradingSessionID.len = 0;
            t->GroupMDEntries[i_0].TradingSessionID.is_null = 0;
            while (!((packet[(*offset)] & 0x80)))
            {
                t->GroupMDEntries[i_0].TradingSessionID.len++;
                (*offset)++;
            }
            packet[*offset] = packet[*offset] & 0x7F;
            (*offset)++;
            t->GroupMDEntries[i_0].TradingSessionID.len++;
        }
        //<<<

#ifdef DEBUG

        if (1)
        {

            if (t->GroupMDEntries[i_0].TradingSessionID.is_null)
            {
                printf("t->GroupMDEntries[%d].TradingSessionID = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
            }
            else
            {
                unsigned char fake[128];
                strncpy(fake, t->GroupMDEntries[i_0].TradingSessionID.start, t->GroupMDEntries[i_0].TradingSessionID.len);
                fake[t->GroupMDEntries[i_0].TradingSessionID.len] = '\0';
                printf("t->GroupMDEntries[%d].TradingSessionID = %s%s%s\n", i_0, KMAG, fake, RESET_COLOR);
            }
        }

#endif

#ifdef DEBUG1
        printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
        printf("name = %sTradingSessionID%s\n", KRED, RESET_COLOR);
        printf("type = %s nopmap_string_nullable_noop\n%s", KBLU, RESET_COLOR);
        printf("byte_representation: ");
        printf("%s", COLOR_BYTES);
        for (int i = t_GroupMDEntries_i_0_TradingSessionID_start; i < *offset; i++)
        {
            printf("%02x ", packet[i]);
        }
        printf("%s\n", RESET_COLOR);

        if (1)
        {

            if (t->GroupMDEntries[i_0].TradingSessionID.is_null)
            {
                printf("t->GroupMDEntries[%d].TradingSessionID = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
            }
            else
            {
                unsigned char fake[128];
                strncpy(fake, t->GroupMDEntries[i_0].TradingSessionID.start, t->GroupMDEntries[i_0].TradingSessionID.len);
                fake[t->GroupMDEntries[i_0].TradingSessionID.len] = '\0';
                printf("t->GroupMDEntries[%d].TradingSessionID = %s%s%s\n", i_0, KMAG, fake, RESET_COLOR);
            }
        }

        printf("\n");
#endif

#ifdef DEBUG3
        getchar();
#endif

//nopmap_string_nullable_noop TradingSessionSubID
#ifdef DEBUG2
        int t_GroupMDEntries_i_0_TradingSessionSubID_start = *offset;
#endif

        //>>> TradingSessionSubID
        t->GroupMDEntries[i_0].TradingSessionSubID.start = packet + *offset;
        if (packet[*offset] == 0x80)
        {
            (*offset)++;
            t->GroupMDEntries[i_0].TradingSessionSubID.len = 0;
            t->GroupMDEntries[i_0].TradingSessionSubID.is_null = 1;
            //printf("t->GroupMDEntries[i_0].TradingSessionSubID = EMPTY \n");
        }
        else
        {
            t->GroupMDEntries[i_0].TradingSessionSubID.len = 0;
            t->GroupMDEntries[i_0].TradingSessionSubID.is_null = 0;
            while (!((packet[(*offset)] & 0x80)))
            {
                t->GroupMDEntries[i_0].TradingSessionSubID.len++;
                (*offset)++;
            }
            packet[*offset] = packet[*offset] & 0x7F;
            (*offset)++;
            t->GroupMDEntries[i_0].TradingSessionSubID.len++;
        }
        //<<<

#ifdef DEBUG

        if (1)
        {

            if (t->GroupMDEntries[i_0].TradingSessionSubID.is_null)
            {
                printf("t->GroupMDEntries[%d].TradingSessionSubID = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
            }
            else
            {
                unsigned char fake[128];
                strncpy(fake, t->GroupMDEntries[i_0].TradingSessionSubID.start, t->GroupMDEntries[i_0].TradingSessionSubID.len);
                fake[t->GroupMDEntries[i_0].TradingSessionSubID.len] = '\0';
                printf("t->GroupMDEntries[%d].TradingSessionSubID = %s%s%s\n", i_0, KMAG, fake, RESET_COLOR);
            }
        }

#endif

#ifdef DEBUG1
        printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
        printf("name = %sTradingSessionSubID%s\n", KRED, RESET_COLOR);
        printf("type = %s nopmap_string_nullable_noop\n%s", KBLU, RESET_COLOR);
        printf("byte_representation: ");
        printf("%s", COLOR_BYTES);
        for (int i = t_GroupMDEntries_i_0_TradingSessionSubID_start; i < *offset; i++)
        {
            printf("%02x ", packet[i]);
        }
        printf("%s\n", RESET_COLOR);

        if (1)
        {

            if (t->GroupMDEntries[i_0].TradingSessionSubID.is_null)
            {
                printf("t->GroupMDEntries[%d].TradingSessionSubID = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
            }
            else
            {
                unsigned char fake[128];
                strncpy(fake, t->GroupMDEntries[i_0].TradingSessionSubID.start, t->GroupMDEntries[i_0].TradingSessionSubID.len);
                fake[t->GroupMDEntries[i_0].TradingSessionSubID.len] = '\0';
                printf("t->GroupMDEntries[%d].TradingSessionSubID = %s%s%s\n", i_0, KMAG, fake, RESET_COLOR);
            }
        }

        printf("\n");
#endif

#ifdef DEBUG3
        getchar();
#endif

//nopmap_string_nullable_noop RefOrderID
#ifdef DEBUG2
        int t_GroupMDEntries_i_0_RefOrderID_start = *offset;
#endif

        //>>> RefOrderID
        t->GroupMDEntries[i_0].RefOrderID.start = packet + *offset;
        if (packet[*offset] == 0x80)
        {
            (*offset)++;
            t->GroupMDEntries[i_0].RefOrderID.len = 0;
            t->GroupMDEntries[i_0].RefOrderID.is_null = 1;
            //printf("t->GroupMDEntries[i_0].RefOrderID = EMPTY \n");
        }
        else
        {
            t->GroupMDEntries[i_0].RefOrderID.len = 0;
            t->GroupMDEntries[i_0].RefOrderID.is_null = 0;
            while (!((packet[(*offset)] & 0x80)))
            {
                t->GroupMDEntries[i_0].RefOrderID.len++;
                (*offset)++;
            }
            packet[*offset] = packet[*offset] & 0x7F;
            (*offset)++;
            t->GroupMDEntries[i_0].RefOrderID.len++;
        }
        //<<<

#ifdef DEBUG

        if (1)
        {

            if (t->GroupMDEntries[i_0].RefOrderID.is_null)
            {
                printf("t->GroupMDEntries[%d].RefOrderID = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
            }
            else
            {
                unsigned char fake[128];
                strncpy(fake, t->GroupMDEntries[i_0].RefOrderID.start, t->GroupMDEntries[i_0].RefOrderID.len);
                fake[t->GroupMDEntries[i_0].RefOrderID.len] = '\0';
                printf("t->GroupMDEntries[%d].RefOrderID = %s%s%s\n", i_0, KMAG, fake, RESET_COLOR);
            }
        }

#endif

#ifdef DEBUG1
        printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
        printf("name = %sRefOrderID%s\n", KRED, RESET_COLOR);
        printf("type = %s nopmap_string_nullable_noop\n%s", KBLU, RESET_COLOR);
        printf("byte_representation: ");
        printf("%s", COLOR_BYTES);
        for (int i = t_GroupMDEntries_i_0_RefOrderID_start; i < *offset; i++)
        {
            printf("%02x ", packet[i]);
        }
        printf("%s\n", RESET_COLOR);

        if (1)
        {

            if (t->GroupMDEntries[i_0].RefOrderID.is_null)
            {
                printf("t->GroupMDEntries[%d].RefOrderID = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
            }
            else
            {
                unsigned char fake[128];
                strncpy(fake, t->GroupMDEntries[i_0].RefOrderID.start, t->GroupMDEntries[i_0].RefOrderID.len);
                fake[t->GroupMDEntries[i_0].RefOrderID.len] = '\0';
                printf("t->GroupMDEntries[%d].RefOrderID = %s%s%s\n", i_0, KMAG, fake, RESET_COLOR);
            }
        }

        printf("\n");
#endif

#ifdef DEBUG3
        getchar();
#endif
    }
    return 0;
}
int moex_eq_parse_template_d(unsigned char *packet, int *offset, unsigned char *pmap, struct moex_eq__d *t)
{
    t->pmap = pmap;

    //nopmap_string_nonullable_constant MessageType
    //strcpy(t->MessageType, "d");

    //nopmap_string_nonullable_constant ApplVerID
    //strcpy(t->ApplVerID, "9");

    //nopmap_string_nonullable_constant BeginString
    //strcpy(t->BeginString, "FIXT.1.1");

    //nopmap_string_nonullable_constant SenderCompID
    //strcpy(t->SenderCompID, "MOEX");

    //pmap_uint32_nonullable_increment INCRMENT
    t->MsgSeqNum = 0;
    while (!((packet[*offset] & 0x80)))
    {
        t->MsgSeqNum |= packet[(*offset)++];
        t->MsgSeqNum <<= 7;
    }
    t->MsgSeqNum |= (packet[(*offset)++] & 0x7f);
    //SURPRIZE!!!!!!!!!!!!!!!

    //nopmap_uint64_nonullable_noop SendingTime
#ifdef DEBUG2
    int t_SendingTime_start = *offset;
#endif

    //>>> SendingTime
    t->SendingTime = 0;
    while (!((packet[*offset] & 0x80)))
    {
        (t->SendingTime) |= packet[(*offset)++];
        (t->SendingTime) <<= 7;
    }
    (t->SendingTime) |= (packet[(*offset)++] & 0x7f);
    //<<<

#ifdef DEBUG
    printf("t->SendingTime = %lu\n", t->SendingTime);
#endif

#ifdef DEBUG1
    printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
    printf("name = %sSendingTime%s\n", KRED, RESET_COLOR);
    printf("type = %snopmap_uint64_nonullable_noop\n%s", KBLU, RESET_COLOR);
    printf("byte_representation: ");
    printf("%s", COLOR_BYTES);
    for (int i = t_SendingTime_start; i < *offset; i++)
    {
        printf("%02x ", packet[i]);
    }
    printf("%s\n", RESET_COLOR);
    printf("value = %s%lu%s\n", KMAG, t->SendingTime, RESET_COLOR);
    printf("\n");
#endif

#ifdef DEBUG3
    getchar();
#endif

    //npmap_string_nonullable_default MessageEncoding
    strcpy(t->MessageEncoding.default_value, "UTF-8");

//nopmap_int32_nullable_noop TotNumReports
#ifdef DEBUG2
    int t_TotNumReports_start = *offset;
#endif

    //>>> TotNumReports
    if (packet[*offset] == 0x80)
    {
        (*offset)++;
        t->TotNumReports.is_null = 1;
    }
    else
    {
        t->TotNumReports.value = 0 - (packet[*offset] & 0x40);
        t->TotNumReports.is_null = 0;
        while (!((packet[*offset] & 0x80)))
        {
            (t->TotNumReports.value) |= packet[(*offset)++];
            (t->TotNumReports.value) <<= 7;
        }
        (t->TotNumReports.value) |= (packet[(*offset)++] & 0x7f);
        if (t->TotNumReports.value > 0)
        {
            (t->TotNumReports.value)--;
        }
    }
    //<<<

#ifdef DEBUG

    if (t->TotNumReports.is_null)
    {
        printf("t->TotNumReports = %sNULL%s\n", KMAG, RESET_COLOR);
    }
    else
    {
        printf("t->TotNumReports = %s%d%s\n", KMAG, t->TotNumReports.value, RESET_COLOR);
    }

#endif

#ifdef DEBUG1
    printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
    printf("name = %sTotNumReports%s\n", KRED, RESET_COLOR);
    printf("type = %snopmap_int32_nullable_noop\n%s", KBLU, RESET_COLOR);
    printf("byte_representation: ");
    printf("%s", COLOR_BYTES);
    for (int i = t_TotNumReports_start; i < *offset; i++)
    {
        printf("%02x ", packet[i]);
    }
    printf("%s\n", RESET_COLOR);

    if (t->TotNumReports.is_null)
    {
        printf("t->TotNumReports = %sNULL%s\n", KMAG, RESET_COLOR);
    }
    else
    {
        printf("t->TotNumReports = %s%d%s\n", KMAG, t->TotNumReports.value, RESET_COLOR);
    }

    printf("\n");
#endif

#ifdef DEBUG3
    getchar();
#endif

    //nopmap_string_nullable_noop Symbol
#ifdef DEBUG2
    int t_Symbol_start = *offset;
#endif

    //>>> Symbol
    t->Symbol.start = packet + *offset;
    if (packet[*offset] == 0x80)
    {
        (*offset)++;
        t->Symbol.len = 0;
        t->Symbol.is_null = 1;
        //printf("t->Symbol = EMPTY \n");
    }
    else
    {
        t->Symbol.len = 0;
        t->Symbol.is_null = 0;
        while (!((packet[(*offset)] & 0x80)))
        {
            t->Symbol.len++;
            (*offset)++;
        }
        packet[*offset] = packet[*offset] & 0x7F;
        (*offset)++;
        t->Symbol.len++;
    }
    //<<<

#ifdef DEBUG

    if (1)
    {

        if (t->Symbol.is_null)
        {
            printf("t->Symbol = %sNULL%s\n", KMAG, RESET_COLOR);
        }
        else
        {
            unsigned char fake[128];
            strncpy(fake, t->Symbol.start, t->Symbol.len);
            fake[t->Symbol.len] = '\0';
            printf("t->Symbol = %s%s%s\n", KMAG, fake, RESET_COLOR);
        }
    }

#endif

#ifdef DEBUG1
    printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
    printf("name = %sSymbol%s\n", KRED, RESET_COLOR);
    printf("type = %s nopmap_string_nullable_noop\n%s", KBLU, RESET_COLOR);
    printf("byte_representation: ");
    printf("%s", COLOR_BYTES);
    for (int i = t_Symbol_start; i < *offset; i++)
    {
        printf("%02x ", packet[i]);
    }
    printf("%s\n", RESET_COLOR);

    if (1)
    {

        if (t->Symbol.is_null)
        {
            printf("t->Symbol = %sNULL%s\n", KMAG, RESET_COLOR);
        }
        else
        {
            unsigned char fake[128];
            strncpy(fake, t->Symbol.start, t->Symbol.len);
            fake[t->Symbol.len] = '\0';
            printf("t->Symbol = %s%s%s\n", KMAG, fake, RESET_COLOR);
        }
    }

    printf("\n");
#endif

#ifdef DEBUG3
    getchar();
#endif

    //nopmap_bytevector_nullable_noop (lazy evaluation)
    if (packet[*offset] == 0x80)
    {
        t->SecurityID.len = 0;
        t->SecurityID.start = packet + *offset;
        (*offset)++;
        t->SecurityID.is_null = 1;
    }
    else
    {
        t->SecurityID.len = 0;
        t->SecurityID.is_null = 0;
        while (!((packet[*offset] & 0x80)))
        {
            t->SecurityID.len |= packet[(*offset)++];
            t->SecurityID.len <<= 7;
        }
        t->SecurityID.len |= (packet[(*offset)++] & 0x7f);
        t->SecurityID.len--;
        t->SecurityID.start = packet + *offset;
        (*offset) += t->SecurityID.len;
        char fake[128];
        strncpy(fake, t->SecurityID.start, t->SecurityID.len);
        fake[t->SecurityID.len] = '\0';
        //printf("t->SecurityID = %s\n", fake);
    }
#ifdef DEBUG

    if (t->SecurityID.is_null)
    {
        printf("t->SecurityID = %sNULL%s\n", KMAG, RESET_COLOR);
    }
    else
    {
        unsigned char fake[128];
        strncpy(fake, t->SecurityID.start, t->SecurityID.len);
        fake[t->SecurityID.len] = '\0';
        printf("t->SecurityID = %s%s%s\n", KMAG, fake, RESET_COLOR);
    }

#endif

    //nopmap_bytevector_nullable_noop (lazy evaluation)
    if (packet[*offset] == 0x80)
    {
        t->SecurityIDSource.len = 0;
        t->SecurityIDSource.start = packet + *offset;
        (*offset)++;
        t->SecurityIDSource.is_null = 1;
    }
    else
    {
        t->SecurityIDSource.len = 0;
        t->SecurityIDSource.is_null = 0;
        while (!((packet[*offset] & 0x80)))
        {
            t->SecurityIDSource.len |= packet[(*offset)++];
            t->SecurityIDSource.len <<= 7;
        }
        t->SecurityIDSource.len |= (packet[(*offset)++] & 0x7f);
        t->SecurityIDSource.len--;
        t->SecurityIDSource.start = packet + *offset;
        (*offset) += t->SecurityIDSource.len;
        char fake[128];
        strncpy(fake, t->SecurityIDSource.start, t->SecurityIDSource.len);
        fake[t->SecurityIDSource.len] = '\0';
        //printf("t->SecurityIDSource = %s\n", fake);
    }
#ifdef DEBUG

    if (t->SecurityIDSource.is_null)
    {
        printf("t->SecurityIDSource = %sNULL%s\n", KMAG, RESET_COLOR);
    }
    else
    {
        unsigned char fake[128];
        strncpy(fake, t->SecurityIDSource.start, t->SecurityIDSource.len);
        fake[t->SecurityIDSource.len] = '\0';
        printf("t->SecurityIDSource = %s%s%s\n", KMAG, fake, RESET_COLOR);
    }

#endif

//nopmap_int32_nullable_noop Product
#ifdef DEBUG2
    int t_Product_start = *offset;
#endif

    //>>> Product
    if (packet[*offset] == 0x80)
    {
        (*offset)++;
        t->Product.is_null = 1;
    }
    else
    {
        t->Product.value = 0 - (packet[*offset] & 0x40);
        t->Product.is_null = 0;
        while (!((packet[*offset] & 0x80)))
        {
            (t->Product.value) |= packet[(*offset)++];
            (t->Product.value) <<= 7;
        }
        (t->Product.value) |= (packet[(*offset)++] & 0x7f);
        if (t->Product.value > 0)
        {
            (t->Product.value)--;
        }
    }
    //<<<

#ifdef DEBUG

    if (t->Product.is_null)
    {
        printf("t->Product = %sNULL%s\n", KMAG, RESET_COLOR);
    }
    else
    {
        printf("t->Product = %s%d%s\n", KMAG, t->Product.value, RESET_COLOR);
    }

#endif

#ifdef DEBUG1
    printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
    printf("name = %sProduct%s\n", KRED, RESET_COLOR);
    printf("type = %snopmap_int32_nullable_noop\n%s", KBLU, RESET_COLOR);
    printf("byte_representation: ");
    printf("%s", COLOR_BYTES);
    for (int i = t_Product_start; i < *offset; i++)
    {
        printf("%02x ", packet[i]);
    }
    printf("%s\n", RESET_COLOR);

    if (t->Product.is_null)
    {
        printf("t->Product = %sNULL%s\n", KMAG, RESET_COLOR);
    }
    else
    {
        printf("t->Product = %s%d%s\n", KMAG, t->Product.value, RESET_COLOR);
    }

    printf("\n");
#endif

#ifdef DEBUG3
    getchar();
#endif

    //nopmap_bytevector_nullable_noop (lazy evaluation)
    if (packet[*offset] == 0x80)
    {
        t->CFICode.len = 0;
        t->CFICode.start = packet + *offset;
        (*offset)++;
        t->CFICode.is_null = 1;
    }
    else
    {
        t->CFICode.len = 0;
        t->CFICode.is_null = 0;
        while (!((packet[*offset] & 0x80)))
        {
            t->CFICode.len |= packet[(*offset)++];
            t->CFICode.len <<= 7;
        }
        t->CFICode.len |= (packet[(*offset)++] & 0x7f);
        t->CFICode.len--;
        t->CFICode.start = packet + *offset;
        (*offset) += t->CFICode.len;
        char fake[128];
        strncpy(fake, t->CFICode.start, t->CFICode.len);
        fake[t->CFICode.len] = '\0';
        //printf("t->CFICode = %s\n", fake);
    }
#ifdef DEBUG

    if (t->CFICode.is_null)
    {
        printf("t->CFICode = %sNULL%s\n", KMAG, RESET_COLOR);
    }
    else
    {
        unsigned char fake[128];
        strncpy(fake, t->CFICode.start, t->CFICode.len);
        fake[t->CFICode.len] = '\0';
        printf("t->CFICode = %s%s%s\n", KMAG, fake, RESET_COLOR);
    }

#endif

    //nopmap_bytevector_nullable_noop (lazy evaluation)
    if (packet[*offset] == 0x80)
    {
        t->SecurityType.len = 0;
        t->SecurityType.start = packet + *offset;
        (*offset)++;
        t->SecurityType.is_null = 1;
    }
    else
    {
        t->SecurityType.len = 0;
        t->SecurityType.is_null = 0;
        while (!((packet[*offset] & 0x80)))
        {
            t->SecurityType.len |= packet[(*offset)++];
            t->SecurityType.len <<= 7;
        }
        t->SecurityType.len |= (packet[(*offset)++] & 0x7f);
        t->SecurityType.len--;
        t->SecurityType.start = packet + *offset;
        (*offset) += t->SecurityType.len;
        char fake[128];
        strncpy(fake, t->SecurityType.start, t->SecurityType.len);
        fake[t->SecurityType.len] = '\0';
        //printf("t->SecurityType = %s\n", fake);
    }
#ifdef DEBUG

    if (t->SecurityType.is_null)
    {
        printf("t->SecurityType = %sNULL%s\n", KMAG, RESET_COLOR);
    }
    else
    {
        unsigned char fake[128];
        strncpy(fake, t->SecurityType.start, t->SecurityType.len);
        fake[t->SecurityType.len] = '\0';
        printf("t->SecurityType = %s%s%s\n", KMAG, fake, RESET_COLOR);
    }

#endif

//nopmap_uint32_nullable_noop MaturityDate
#ifdef DEBUG2
    int t_MaturityDate_start = *offset;
#endif

    //>>> MaturityDate
    if (packet[*offset] == 0x80)
    {
        t->MaturityDate.is_null = 1;
        t->MaturityDate.value = 0;
        (*offset)++;
    }
    else
    {
        t->MaturityDate.value = 0;
        t->MaturityDate.is_null = 0;
        while (!((packet[*offset] & 0x80)))
        {
            (t->MaturityDate.value) |= packet[(*offset)++];
            (t->MaturityDate.value) <<= 7;
        }
        (t->MaturityDate.value) |= (packet[(*offset)++] & 0x7f);
        (t->MaturityDate.value)--;
    }
    //<<<

#ifdef DEBUG

    if (t->MaturityDate.is_null)
    {
        printf("t->MaturityDate = %sNULL%s\n", KMAG, RESET_COLOR);
    }
    else
    {
        printf("t->MaturityDate = %s%u%s\n", KMAG, t->MaturityDate.value, RESET_COLOR);
    }

#endif

#ifdef DEBUG1
    printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
    printf("name = %sMaturityDate%s\n", KRED, RESET_COLOR);
    printf("type = %snopmap_uint32_nullable_noop\n%s", KBLU, RESET_COLOR);
    printf("byte_representation: ");
    printf("%s", COLOR_BYTES);
    for (int i = t_MaturityDate_start; i < *offset; i++)
    {
        printf("%02x ", packet[i]);
    }
    printf("%s\n", RESET_COLOR);

    if (t->MaturityDate.is_null)
    {
        printf("t->MaturityDate = %sNULL%s\n", KMAG, RESET_COLOR);
    }
    else
    {
        printf("t->MaturityDate = %s%u%s\n", KMAG, t->MaturityDate.value, RESET_COLOR);
    }

    printf("\n");
#endif

#ifdef DEBUG3
    getchar();
#endif

//nopmap_uint32_nullable_noop SettlDate
#ifdef DEBUG2
    int t_SettlDate_start = *offset;
#endif

    //>>> SettlDate
    if (packet[*offset] == 0x80)
    {
        t->SettlDate.is_null = 1;
        t->SettlDate.value = 0;
        (*offset)++;
    }
    else
    {
        t->SettlDate.value = 0;
        t->SettlDate.is_null = 0;
        while (!((packet[*offset] & 0x80)))
        {
            (t->SettlDate.value) |= packet[(*offset)++];
            (t->SettlDate.value) <<= 7;
        }
        (t->SettlDate.value) |= (packet[(*offset)++] & 0x7f);
        (t->SettlDate.value)--;
    }
    //<<<

#ifdef DEBUG

    if (t->SettlDate.is_null)
    {
        printf("t->SettlDate = %sNULL%s\n", KMAG, RESET_COLOR);
    }
    else
    {
        printf("t->SettlDate = %s%u%s\n", KMAG, t->SettlDate.value, RESET_COLOR);
    }

#endif

#ifdef DEBUG1
    printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
    printf("name = %sSettlDate%s\n", KRED, RESET_COLOR);
    printf("type = %snopmap_uint32_nullable_noop\n%s", KBLU, RESET_COLOR);
    printf("byte_representation: ");
    printf("%s", COLOR_BYTES);
    for (int i = t_SettlDate_start; i < *offset; i++)
    {
        printf("%02x ", packet[i]);
    }
    printf("%s\n", RESET_COLOR);

    if (t->SettlDate.is_null)
    {
        printf("t->SettlDate = %sNULL%s\n", KMAG, RESET_COLOR);
    }
    else
    {
        printf("t->SettlDate = %s%u%s\n", KMAG, t->SettlDate.value, RESET_COLOR);
    }

    printf("\n");
#endif

#ifdef DEBUG3
    getchar();
#endif

    //nopmap_string_nullable_noop SettleType
#ifdef DEBUG2
    int t_SettleType_start = *offset;
#endif

    //>>> SettleType
    t->SettleType.start = packet + *offset;
    if (packet[*offset] == 0x80)
    {
        (*offset)++;
        t->SettleType.len = 0;
        t->SettleType.is_null = 1;
        //printf("t->SettleType = EMPTY \n");
    }
    else
    {
        t->SettleType.len = 0;
        t->SettleType.is_null = 0;
        while (!((packet[(*offset)] & 0x80)))
        {
            t->SettleType.len++;
            (*offset)++;
        }
        packet[*offset] = packet[*offset] & 0x7F;
        (*offset)++;
        t->SettleType.len++;
    }
    //<<<

#ifdef DEBUG

    if (1)
    {

        if (t->SettleType.is_null)
        {
            printf("t->SettleType = %sNULL%s\n", KMAG, RESET_COLOR);
        }
        else
        {
            unsigned char fake[128];
            strncpy(fake, t->SettleType.start, t->SettleType.len);
            fake[t->SettleType.len] = '\0';
            printf("t->SettleType = %s%s%s\n", KMAG, fake, RESET_COLOR);
        }
    }

#endif

#ifdef DEBUG1
    printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
    printf("name = %sSettleType%s\n", KRED, RESET_COLOR);
    printf("type = %s nopmap_string_nullable_noop\n%s", KBLU, RESET_COLOR);
    printf("byte_representation: ");
    printf("%s", COLOR_BYTES);
    for (int i = t_SettleType_start; i < *offset; i++)
    {
        printf("%02x ", packet[i]);
    }
    printf("%s\n", RESET_COLOR);

    if (1)
    {

        if (t->SettleType.is_null)
        {
            printf("t->SettleType = %sNULL%s\n", KMAG, RESET_COLOR);
        }
        else
        {
            unsigned char fake[128];
            strncpy(fake, t->SettleType.start, t->SettleType.len);
            fake[t->SettleType.len] = '\0';
            printf("t->SettleType = %s%s%s\n", KMAG, fake, RESET_COLOR);
        }
    }

    printf("\n");
#endif

#ifdef DEBUG3
    getchar();
#endif

    //nopmap_decimal_nullable_noop

//nopmap_int32_nullable_noop OrigIssueAmt
#ifdef DEBUG2
    int t_OrigIssueAmtexponenta_start = *offset;
#endif

    //>>> OrigIssueAmt
    if (packet[*offset] == 0x80)
    {
        (*offset)++;
        t->OrigIssueAmt.exponenta.is_null = 1;
    }
    else
    {
        t->OrigIssueAmt.exponenta.value = 0 - (packet[*offset] & 0x40);
        t->OrigIssueAmt.exponenta.is_null = 0;
        while (!((packet[*offset] & 0x80)))
        {
            (t->OrigIssueAmt.exponenta.value) |= packet[(*offset)++];
            (t->OrigIssueAmt.exponenta.value) <<= 7;
        }
        (t->OrigIssueAmt.exponenta.value) |= (packet[(*offset)++] & 0x7f);
        if (t->OrigIssueAmt.exponenta.value > 0)
        {
            (t->OrigIssueAmt.exponenta.value)--;
        }
    }
    //<<<

#ifdef DEBUG

    if (t->OrigIssueAmt.exponenta.is_null)
    {
        printf("t->OrigIssueAmt.exponenta = %sNULL%s\n", KMAG, RESET_COLOR);
    }
    else
    {
        printf("t->OrigIssueAmt.exponenta = %s%d%s\n", KMAG, t->OrigIssueAmt.exponenta.value, RESET_COLOR);
    }

#endif

#ifdef DEBUG1
    printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
    printf("name = %sOrigIssueAmt%s\n", KRED, RESET_COLOR);
    printf("type = %snopmap_int32_nullable_noop\n%s", KBLU, RESET_COLOR);
    printf("byte_representation: ");
    printf("%s", COLOR_BYTES);
    for (int i = t_OrigIssueAmtexponenta_start; i < *offset; i++)
    {
        printf("%02x ", packet[i]);
    }
    printf("%s\n", RESET_COLOR);

    if (t->OrigIssueAmt.exponenta.is_null)
    {
        printf("t->OrigIssueAmt.exponenta = %sNULL%s\n", KMAG, RESET_COLOR);
    }
    else
    {
        printf("t->OrigIssueAmt.exponenta = %s%d%s\n", KMAG, t->OrigIssueAmt.exponenta.value, RESET_COLOR);
    }

    printf("\n");
#endif

#ifdef DEBUG3
    getchar();
#endif

    if (!t->OrigIssueAmt.exponenta.is_null)
    {
        //calc mantissa
        //nopmap_int64_nonullable_noop OrigIssueAmt
#ifdef DEBUG2
        int t_OrigIssueAmtmantissa_start = *offset;
#endif

        //>>> OrigIssueAmt
        t->OrigIssueAmt.mantissa = 0 - (packet[*offset] & 0x40);
        while (!((packet[*offset] & 0x80)))
        {
            t->OrigIssueAmt.mantissa |= packet[(*offset)++];
            t->OrigIssueAmt.mantissa <<= 7;
        }
        t->OrigIssueAmt.mantissa |= (packet[(*offset)++] & 0x7f);
        //<<<

#ifdef DEBUG
        printf("t->OrigIssueAmt.mantissa = %ld\n", t->OrigIssueAmt.mantissa);
#endif

#ifdef DEBUG1
        printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
        printf("name = %sOrigIssueAmt%s\n", KRED, RESET_COLOR);
        printf("type = %snopmap_int64_nonullable_noop\n%s", KBLU, RESET_COLOR);
        printf("byte_representation: ");
        printf("%s", COLOR_BYTES);
        for (int i = t_OrigIssueAmtmantissa_start; i < *offset; i++)
        {
            printf("%02x ", packet[i]);
        }
        printf("%s\n", RESET_COLOR);
        printf("value = %s%ld%s\n", KMAG, t->OrigIssueAmt.mantissa, RESET_COLOR);
        printf("\n");
#endif

#ifdef DEBUG3
        getchar();
#endif
    }

//nopmap_uint32_nullable_noop CouponPaymentDate
#ifdef DEBUG2
    int t_CouponPaymentDate_start = *offset;
#endif

    //>>> CouponPaymentDate
    if (packet[*offset] == 0x80)
    {
        t->CouponPaymentDate.is_null = 1;
        t->CouponPaymentDate.value = 0;
        (*offset)++;
    }
    else
    {
        t->CouponPaymentDate.value = 0;
        t->CouponPaymentDate.is_null = 0;
        while (!((packet[*offset] & 0x80)))
        {
            (t->CouponPaymentDate.value) |= packet[(*offset)++];
            (t->CouponPaymentDate.value) <<= 7;
        }
        (t->CouponPaymentDate.value) |= (packet[(*offset)++] & 0x7f);
        (t->CouponPaymentDate.value)--;
    }
    //<<<

#ifdef DEBUG

    if (t->CouponPaymentDate.is_null)
    {
        printf("t->CouponPaymentDate = %sNULL%s\n", KMAG, RESET_COLOR);
    }
    else
    {
        printf("t->CouponPaymentDate = %s%u%s\n", KMAG, t->CouponPaymentDate.value, RESET_COLOR);
    }

#endif

#ifdef DEBUG1
    printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
    printf("name = %sCouponPaymentDate%s\n", KRED, RESET_COLOR);
    printf("type = %snopmap_uint32_nullable_noop\n%s", KBLU, RESET_COLOR);
    printf("byte_representation: ");
    printf("%s", COLOR_BYTES);
    for (int i = t_CouponPaymentDate_start; i < *offset; i++)
    {
        printf("%02x ", packet[i]);
    }
    printf("%s\n", RESET_COLOR);

    if (t->CouponPaymentDate.is_null)
    {
        printf("t->CouponPaymentDate = %sNULL%s\n", KMAG, RESET_COLOR);
    }
    else
    {
        printf("t->CouponPaymentDate = %s%u%s\n", KMAG, t->CouponPaymentDate.value, RESET_COLOR);
    }

    printf("\n");
#endif

#ifdef DEBUG3
    getchar();
#endif

    //nopmap_decimal_nullable_noop

//nopmap_int32_nullable_noop CouponRate
#ifdef DEBUG2
    int t_CouponRateexponenta_start = *offset;
#endif

    //>>> CouponRate
    if (packet[*offset] == 0x80)
    {
        (*offset)++;
        t->CouponRate.exponenta.is_null = 1;
    }
    else
    {
        t->CouponRate.exponenta.value = 0 - (packet[*offset] & 0x40);
        t->CouponRate.exponenta.is_null = 0;
        while (!((packet[*offset] & 0x80)))
        {
            (t->CouponRate.exponenta.value) |= packet[(*offset)++];
            (t->CouponRate.exponenta.value) <<= 7;
        }
        (t->CouponRate.exponenta.value) |= (packet[(*offset)++] & 0x7f);
        if (t->CouponRate.exponenta.value > 0)
        {
            (t->CouponRate.exponenta.value)--;
        }
    }
    //<<<

#ifdef DEBUG

    if (t->CouponRate.exponenta.is_null)
    {
        printf("t->CouponRate.exponenta = %sNULL%s\n", KMAG, RESET_COLOR);
    }
    else
    {
        printf("t->CouponRate.exponenta = %s%d%s\n", KMAG, t->CouponRate.exponenta.value, RESET_COLOR);
    }

#endif

#ifdef DEBUG1
    printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
    printf("name = %sCouponRate%s\n", KRED, RESET_COLOR);
    printf("type = %snopmap_int32_nullable_noop\n%s", KBLU, RESET_COLOR);
    printf("byte_representation: ");
    printf("%s", COLOR_BYTES);
    for (int i = t_CouponRateexponenta_start; i < *offset; i++)
    {
        printf("%02x ", packet[i]);
    }
    printf("%s\n", RESET_COLOR);

    if (t->CouponRate.exponenta.is_null)
    {
        printf("t->CouponRate.exponenta = %sNULL%s\n", KMAG, RESET_COLOR);
    }
    else
    {
        printf("t->CouponRate.exponenta = %s%d%s\n", KMAG, t->CouponRate.exponenta.value, RESET_COLOR);
    }

    printf("\n");
#endif

#ifdef DEBUG3
    getchar();
#endif

    if (!t->CouponRate.exponenta.is_null)
    {
        //calc mantissa
        //nopmap_int64_nonullable_noop CouponRate
#ifdef DEBUG2
        int t_CouponRatemantissa_start = *offset;
#endif

        //>>> CouponRate
        t->CouponRate.mantissa = 0 - (packet[*offset] & 0x40);
        while (!((packet[*offset] & 0x80)))
        {
            t->CouponRate.mantissa |= packet[(*offset)++];
            t->CouponRate.mantissa <<= 7;
        }
        t->CouponRate.mantissa |= (packet[(*offset)++] & 0x7f);
        //<<<

#ifdef DEBUG
        printf("t->CouponRate.mantissa = %ld\n", t->CouponRate.mantissa);
#endif

#ifdef DEBUG1
        printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
        printf("name = %sCouponRate%s\n", KRED, RESET_COLOR);
        printf("type = %snopmap_int64_nonullable_noop\n%s", KBLU, RESET_COLOR);
        printf("byte_representation: ");
        printf("%s", COLOR_BYTES);
        for (int i = t_CouponRatemantissa_start; i < *offset; i++)
        {
            printf("%02x ", packet[i]);
        }
        printf("%s\n", RESET_COLOR);
        printf("value = %s%ld%s\n", KMAG, t->CouponRate.mantissa, RESET_COLOR);
        printf("\n");
#endif

#ifdef DEBUG3
        getchar();
#endif
    }

//nopmap_uint32_nullable_noop SettlFixingDate
#ifdef DEBUG2
    int t_SettlFixingDate_start = *offset;
#endif

    //>>> SettlFixingDate
    if (packet[*offset] == 0x80)
    {
        t->SettlFixingDate.is_null = 1;
        t->SettlFixingDate.value = 0;
        (*offset)++;
    }
    else
    {
        t->SettlFixingDate.value = 0;
        t->SettlFixingDate.is_null = 0;
        while (!((packet[*offset] & 0x80)))
        {
            (t->SettlFixingDate.value) |= packet[(*offset)++];
            (t->SettlFixingDate.value) <<= 7;
        }
        (t->SettlFixingDate.value) |= (packet[(*offset)++] & 0x7f);
        (t->SettlFixingDate.value)--;
    }
    //<<<

#ifdef DEBUG

    if (t->SettlFixingDate.is_null)
    {
        printf("t->SettlFixingDate = %sNULL%s\n", KMAG, RESET_COLOR);
    }
    else
    {
        printf("t->SettlFixingDate = %s%u%s\n", KMAG, t->SettlFixingDate.value, RESET_COLOR);
    }

#endif

#ifdef DEBUG1
    printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
    printf("name = %sSettlFixingDate%s\n", KRED, RESET_COLOR);
    printf("type = %snopmap_uint32_nullable_noop\n%s", KBLU, RESET_COLOR);
    printf("byte_representation: ");
    printf("%s", COLOR_BYTES);
    for (int i = t_SettlFixingDate_start; i < *offset; i++)
    {
        printf("%02x ", packet[i]);
    }
    printf("%s\n", RESET_COLOR);

    if (t->SettlFixingDate.is_null)
    {
        printf("t->SettlFixingDate = %sNULL%s\n", KMAG, RESET_COLOR);
    }
    else
    {
        printf("t->SettlFixingDate = %s%u%s\n", KMAG, t->SettlFixingDate.value, RESET_COLOR);
    }

    printf("\n");
#endif

#ifdef DEBUG3
    getchar();
#endif

    //nopmap_decimal_nullable_noop

//nopmap_int32_nullable_noop DividendNetPx
#ifdef DEBUG2
    int t_DividendNetPxexponenta_start = *offset;
#endif

    //>>> DividendNetPx
    if (packet[*offset] == 0x80)
    {
        (*offset)++;
        t->DividendNetPx.exponenta.is_null = 1;
    }
    else
    {
        t->DividendNetPx.exponenta.value = 0 - (packet[*offset] & 0x40);
        t->DividendNetPx.exponenta.is_null = 0;
        while (!((packet[*offset] & 0x80)))
        {
            (t->DividendNetPx.exponenta.value) |= packet[(*offset)++];
            (t->DividendNetPx.exponenta.value) <<= 7;
        }
        (t->DividendNetPx.exponenta.value) |= (packet[(*offset)++] & 0x7f);
        if (t->DividendNetPx.exponenta.value > 0)
        {
            (t->DividendNetPx.exponenta.value)--;
        }
    }
    //<<<

#ifdef DEBUG

    if (t->DividendNetPx.exponenta.is_null)
    {
        printf("t->DividendNetPx.exponenta = %sNULL%s\n", KMAG, RESET_COLOR);
    }
    else
    {
        printf("t->DividendNetPx.exponenta = %s%d%s\n", KMAG, t->DividendNetPx.exponenta.value, RESET_COLOR);
    }

#endif

#ifdef DEBUG1
    printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
    printf("name = %sDividendNetPx%s\n", KRED, RESET_COLOR);
    printf("type = %snopmap_int32_nullable_noop\n%s", KBLU, RESET_COLOR);
    printf("byte_representation: ");
    printf("%s", COLOR_BYTES);
    for (int i = t_DividendNetPxexponenta_start; i < *offset; i++)
    {
        printf("%02x ", packet[i]);
    }
    printf("%s\n", RESET_COLOR);

    if (t->DividendNetPx.exponenta.is_null)
    {
        printf("t->DividendNetPx.exponenta = %sNULL%s\n", KMAG, RESET_COLOR);
    }
    else
    {
        printf("t->DividendNetPx.exponenta = %s%d%s\n", KMAG, t->DividendNetPx.exponenta.value, RESET_COLOR);
    }

    printf("\n");
#endif

#ifdef DEBUG3
    getchar();
#endif

    if (!t->DividendNetPx.exponenta.is_null)
    {
        //calc mantissa
        //nopmap_int64_nonullable_noop DividendNetPx
#ifdef DEBUG2
        int t_DividendNetPxmantissa_start = *offset;
#endif

        //>>> DividendNetPx
        t->DividendNetPx.mantissa = 0 - (packet[*offset] & 0x40);
        while (!((packet[*offset] & 0x80)))
        {
            t->DividendNetPx.mantissa |= packet[(*offset)++];
            t->DividendNetPx.mantissa <<= 7;
        }
        t->DividendNetPx.mantissa |= (packet[(*offset)++] & 0x7f);
        //<<<

#ifdef DEBUG
        printf("t->DividendNetPx.mantissa = %ld\n", t->DividendNetPx.mantissa);
#endif

#ifdef DEBUG1
        printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
        printf("name = %sDividendNetPx%s\n", KRED, RESET_COLOR);
        printf("type = %snopmap_int64_nonullable_noop\n%s", KBLU, RESET_COLOR);
        printf("byte_representation: ");
        printf("%s", COLOR_BYTES);
        for (int i = t_DividendNetPxmantissa_start; i < *offset; i++)
        {
            printf("%02x ", packet[i]);
        }
        printf("%s\n", RESET_COLOR);
        printf("value = %s%ld%s\n", KMAG, t->DividendNetPx.mantissa, RESET_COLOR);
        printf("\n");
#endif

#ifdef DEBUG3
        getchar();
#endif
    }

    //nopmap_bytevector_nullable_noop (lazy evaluation)
    if (packet[*offset] == 0x80)
    {
        t->SecurityDesc.len = 0;
        t->SecurityDesc.start = packet + *offset;
        (*offset)++;
        t->SecurityDesc.is_null = 1;
    }
    else
    {
        t->SecurityDesc.len = 0;
        t->SecurityDesc.is_null = 0;
        while (!((packet[*offset] & 0x80)))
        {
            t->SecurityDesc.len |= packet[(*offset)++];
            t->SecurityDesc.len <<= 7;
        }
        t->SecurityDesc.len |= (packet[(*offset)++] & 0x7f);
        t->SecurityDesc.len--;
        t->SecurityDesc.start = packet + *offset;
        (*offset) += t->SecurityDesc.len;
        char fake[128];
        strncpy(fake, t->SecurityDesc.start, t->SecurityDesc.len);
        fake[t->SecurityDesc.len] = '\0';
        //printf("t->SecurityDesc = %s\n", fake);
    }
#ifdef DEBUG

    if (t->SecurityDesc.is_null)
    {
        printf("t->SecurityDesc = %sNULL%s\n", KMAG, RESET_COLOR);
    }
    else
    {
        unsigned char fake[128];
        strncpy(fake, t->SecurityDesc.start, t->SecurityDesc.len);
        fake[t->SecurityDesc.len] = '\0';
        printf("t->SecurityDesc = %s%s%s\n", KMAG, fake, RESET_COLOR);
    }

#endif

    //nopmap_bytevector_nullable_noop (lazy evaluation)
    if (packet[*offset] == 0x80)
    {
        t->EncodedSecurityDesc.len = 0;
        t->EncodedSecurityDesc.start = packet + *offset;
        (*offset)++;
        t->EncodedSecurityDesc.is_null = 1;
    }
    else
    {
        t->EncodedSecurityDesc.len = 0;
        t->EncodedSecurityDesc.is_null = 0;
        while (!((packet[*offset] & 0x80)))
        {
            t->EncodedSecurityDesc.len |= packet[(*offset)++];
            t->EncodedSecurityDesc.len <<= 7;
        }
        t->EncodedSecurityDesc.len |= (packet[(*offset)++] & 0x7f);
        t->EncodedSecurityDesc.len--;
        t->EncodedSecurityDesc.start = packet + *offset;
        (*offset) += t->EncodedSecurityDesc.len;
        char fake[128];
        strncpy(fake, t->EncodedSecurityDesc.start, t->EncodedSecurityDesc.len);
        fake[t->EncodedSecurityDesc.len] = '\0';
        //printf("t->EncodedSecurityDesc = %s\n", fake);
    }
#ifdef DEBUG

    if (t->EncodedSecurityDesc.is_null)
    {
        printf("t->EncodedSecurityDesc = %sNULL%s\n", KMAG, RESET_COLOR);
    }
    else
    {
        unsigned char fake[128];
        strncpy(fake, t->EncodedSecurityDesc.start, t->EncodedSecurityDesc.len);
        fake[t->EncodedSecurityDesc.len] = '\0';
        printf("t->EncodedSecurityDesc = %s%s%s\n", KMAG, fake, RESET_COLOR);
    }

#endif

    //nopmap_bytevector_nullable_noop (lazy evaluation)
    if (packet[*offset] == 0x80)
    {
        t->QuoteText.len = 0;
        t->QuoteText.start = packet + *offset;
        (*offset)++;
        t->QuoteText.is_null = 1;
    }
    else
    {
        t->QuoteText.len = 0;
        t->QuoteText.is_null = 0;
        while (!((packet[*offset] & 0x80)))
        {
            t->QuoteText.len |= packet[(*offset)++];
            t->QuoteText.len <<= 7;
        }
        t->QuoteText.len |= (packet[(*offset)++] & 0x7f);
        t->QuoteText.len--;
        t->QuoteText.start = packet + *offset;
        (*offset) += t->QuoteText.len;
        char fake[128];
        strncpy(fake, t->QuoteText.start, t->QuoteText.len);
        fake[t->QuoteText.len] = '\0';
        //printf("t->QuoteText = %s\n", fake);
    }
#ifdef DEBUG

    if (t->QuoteText.is_null)
    {
        printf("t->QuoteText = %sNULL%s\n", KMAG, RESET_COLOR);
    }
    else
    {
        unsigned char fake[128];
        strncpy(fake, t->QuoteText.start, t->QuoteText.len);
        fake[t->QuoteText.len] = '\0';
        printf("t->QuoteText = %s%s%s\n", KMAG, fake, RESET_COLOR);
    }

#endif

//nopmap_uint32_nullable_noop NoInstrAttrib
#ifdef DEBUG2
    int t_NoInstrAttrib_start = *offset;
#endif

    //>>> NoInstrAttrib
    if (packet[*offset] == 0x80)
    {
        t->NoInstrAttrib.is_null = 1;
        t->NoInstrAttrib.value = 0;
        (*offset)++;
    }
    else
    {
        t->NoInstrAttrib.value = 0;
        t->NoInstrAttrib.is_null = 0;
        while (!((packet[*offset] & 0x80)))
        {
            (t->NoInstrAttrib.value) |= packet[(*offset)++];
            (t->NoInstrAttrib.value) <<= 7;
        }
        (t->NoInstrAttrib.value) |= (packet[(*offset)++] & 0x7f);
        (t->NoInstrAttrib.value)--;
    }
    //<<<

#ifdef DEBUG

    if (t->NoInstrAttrib.is_null)
    {
        printf("t->NoInstrAttrib = %sNULL%s\n", KMAG, RESET_COLOR);
    }
    else
    {
        printf("t->NoInstrAttrib = %s%u%s\n", KMAG, t->NoInstrAttrib.value, RESET_COLOR);
    }

#endif

#ifdef DEBUG1
    printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
    printf("name = %sNoInstrAttrib%s\n", KRED, RESET_COLOR);
    printf("type = %snopmap_uint32_nullable_noop\n%s", KBLU, RESET_COLOR);
    printf("byte_representation: ");
    printf("%s", COLOR_BYTES);
    for (int i = t_NoInstrAttrib_start; i < *offset; i++)
    {
        printf("%02x ", packet[i]);
    }
    printf("%s\n", RESET_COLOR);

    if (t->NoInstrAttrib.is_null)
    {
        printf("t->NoInstrAttrib = %sNULL%s\n", KMAG, RESET_COLOR);
    }
    else
    {
        printf("t->NoInstrAttrib = %s%u%s\n", KMAG, t->NoInstrAttrib.value, RESET_COLOR);
    }

    printf("\n");
#endif

#ifdef DEBUG3
    getchar();
#endif

    if (t->NoInstrAttrib.value >= moex_eq__d__GroupInstrAttrib__MAX)
    {
        return -1;
    }

    for (int i_0 = 0; i_0 < t->NoInstrAttrib.value; i_0++)
    {
        //PMAP for this sequence doesn't required
//nopmap_int32_nonullable_noop InstrAttribType
#ifdef DEBUG2
        int t_GroupInstrAttrib_i_0_InstrAttribType_start = *offset;
#endif

        //>>> InstrAttribType
        t->GroupInstrAttrib[i_0].InstrAttribType = 0 - (packet[*offset] & 0x40);
        while (!((packet[*offset] & 0x80)))
        {
            t->GroupInstrAttrib[i_0].InstrAttribType |= packet[(*offset)++];
            t->GroupInstrAttrib[i_0].InstrAttribType <<= 7;
        }
        t->GroupInstrAttrib[i_0].InstrAttribType |= (packet[(*offset)++] & 0x7f);
        //<<<

#ifdef DEBUG
        printf("t->GroupInstrAttrib[%d].InstrAttribType = %d\n", i_0, t->GroupInstrAttrib[i_0].InstrAttribType);
#endif

#ifdef DEBUG1
        printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
        printf("name = %sInstrAttribType%s\n", KRED, RESET_COLOR);
        printf("type = %snopmap_int32_nonullable_noop\n%s", KBLU, RESET_COLOR);
        printf("byte_representation: ");
        printf("%s", COLOR_BYTES);
        for (int i = t_GroupInstrAttrib_i_0_InstrAttribType_start; i < *offset; i++)
        {
            printf("%02x ", packet[i]);
        }
        printf("%s\n", RESET_COLOR);
        printf("value = %s%d%s\n", KMAG, t->GroupInstrAttrib[i_0].InstrAttribType, RESET_COLOR);
        printf("\n");
#endif

#ifdef DEBUG3
        getchar();
#endif

        //nopmap_bytevector_nullable_noop (lazy evaluation)
        if (packet[*offset] == 0x80)
        {
            t->GroupInstrAttrib[i_0].InstrAttribValue.len = 0;
            t->GroupInstrAttrib[i_0].InstrAttribValue.start = packet + *offset;
            (*offset)++;
            t->GroupInstrAttrib[i_0].InstrAttribValue.is_null = 1;
        }
        else
        {
            t->GroupInstrAttrib[i_0].InstrAttribValue.len = 0;
            t->GroupInstrAttrib[i_0].InstrAttribValue.is_null = 0;
            while (!((packet[*offset] & 0x80)))
            {
                t->GroupInstrAttrib[i_0].InstrAttribValue.len |= packet[(*offset)++];
                t->GroupInstrAttrib[i_0].InstrAttribValue.len <<= 7;
            }
            t->GroupInstrAttrib[i_0].InstrAttribValue.len |= (packet[(*offset)++] & 0x7f);
            t->GroupInstrAttrib[i_0].InstrAttribValue.len--;
            t->GroupInstrAttrib[i_0].InstrAttribValue.start = packet + *offset;
            (*offset) += t->GroupInstrAttrib[i_0].InstrAttribValue.len;
            char fake[128];
            strncpy(fake, t->GroupInstrAttrib[i_0].InstrAttribValue.start, t->GroupInstrAttrib[i_0].InstrAttribValue.len);
            fake[t->GroupInstrAttrib[i_0].InstrAttribValue.len] = '\0';
            //printf("t->GroupInstrAttrib[i_0].InstrAttribValue = %s\n", fake);
        }
#ifdef DEBUG

        if (t->GroupInstrAttrib[i_0].InstrAttribValue.is_null)
        {
            printf("t->GroupInstrAttrib[%d].InstrAttribValue = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
        }
        else
        {
            unsigned char fake[128];
            strncpy(fake, t->GroupInstrAttrib[i_0].InstrAttribValue.start, t->GroupInstrAttrib[i_0].InstrAttribValue.len);
            fake[t->GroupInstrAttrib[i_0].InstrAttribValue.len] = '\0';
            printf("t->GroupInstrAttrib[%d].InstrAttribValue = %s%s%s\n", i_0, KMAG, fake, RESET_COLOR);
        }

#endif
    }
    //nopmap_string_nullable_noop Currency
#ifdef DEBUG2
    int t_Currency_start = *offset;
#endif

    //>>> Currency
    t->Currency.start = packet + *offset;
    if (packet[*offset] == 0x80)
    {
        (*offset)++;
        t->Currency.len = 0;
        t->Currency.is_null = 1;
        //printf("t->Currency = EMPTY \n");
    }
    else
    {
        t->Currency.len = 0;
        t->Currency.is_null = 0;
        while (!((packet[(*offset)] & 0x80)))
        {
            t->Currency.len++;
            (*offset)++;
        }
        packet[*offset] = packet[*offset] & 0x7F;
        (*offset)++;
        t->Currency.len++;
    }
    //<<<

#ifdef DEBUG

    if (1)
    {

        if (t->Currency.is_null)
        {
            printf("t->Currency = %sNULL%s\n", KMAG, RESET_COLOR);
        }
        else
        {
            unsigned char fake[128];
            strncpy(fake, t->Currency.start, t->Currency.len);
            fake[t->Currency.len] = '\0';
            printf("t->Currency = %s%s%s\n", KMAG, fake, RESET_COLOR);
        }
    }

#endif

#ifdef DEBUG1
    printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
    printf("name = %sCurrency%s\n", KRED, RESET_COLOR);
    printf("type = %s nopmap_string_nullable_noop\n%s", KBLU, RESET_COLOR);
    printf("byte_representation: ");
    printf("%s", COLOR_BYTES);
    for (int i = t_Currency_start; i < *offset; i++)
    {
        printf("%02x ", packet[i]);
    }
    printf("%s\n", RESET_COLOR);

    if (1)
    {

        if (t->Currency.is_null)
        {
            printf("t->Currency = %sNULL%s\n", KMAG, RESET_COLOR);
        }
        else
        {
            unsigned char fake[128];
            strncpy(fake, t->Currency.start, t->Currency.len);
            fake[t->Currency.len] = '\0';
            printf("t->Currency = %s%s%s\n", KMAG, fake, RESET_COLOR);
        }
    }

    printf("\n");
#endif

#ifdef DEBUG3
    getchar();
#endif

//nopmap_uint32_nullable_noop NoMarketSegments
#ifdef DEBUG2
    int t_NoMarketSegments_start = *offset;
#endif

    //>>> NoMarketSegments
    if (packet[*offset] == 0x80)
    {
        t->NoMarketSegments.is_null = 1;
        t->NoMarketSegments.value = 0;
        (*offset)++;
    }
    else
    {
        t->NoMarketSegments.value = 0;
        t->NoMarketSegments.is_null = 0;
        while (!((packet[*offset] & 0x80)))
        {
            (t->NoMarketSegments.value) |= packet[(*offset)++];
            (t->NoMarketSegments.value) <<= 7;
        }
        (t->NoMarketSegments.value) |= (packet[(*offset)++] & 0x7f);
        (t->NoMarketSegments.value)--;
    }
    //<<<

#ifdef DEBUG

    if (t->NoMarketSegments.is_null)
    {
        printf("t->NoMarketSegments = %sNULL%s\n", KMAG, RESET_COLOR);
    }
    else
    {
        printf("t->NoMarketSegments = %s%u%s\n", KMAG, t->NoMarketSegments.value, RESET_COLOR);
    }

#endif

#ifdef DEBUG1
    printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
    printf("name = %sNoMarketSegments%s\n", KRED, RESET_COLOR);
    printf("type = %snopmap_uint32_nullable_noop\n%s", KBLU, RESET_COLOR);
    printf("byte_representation: ");
    printf("%s", COLOR_BYTES);
    for (int i = t_NoMarketSegments_start; i < *offset; i++)
    {
        printf("%02x ", packet[i]);
    }
    printf("%s\n", RESET_COLOR);

    if (t->NoMarketSegments.is_null)
    {
        printf("t->NoMarketSegments = %sNULL%s\n", KMAG, RESET_COLOR);
    }
    else
    {
        printf("t->NoMarketSegments = %s%u%s\n", KMAG, t->NoMarketSegments.value, RESET_COLOR);
    }

    printf("\n");
#endif

#ifdef DEBUG3
    getchar();
#endif

    if (t->NoMarketSegments.value >= moex_eq__d__MarketSegmentGrp__MAX)
    {
        return -1;
    }

    for (int i_0 = 0; i_0 < t->NoMarketSegments.value; i_0++)
    {
        //PMAP for this sequence doesn't required
        //nopmap_decimal_nullable_noop

//nopmap_int32_nullable_noop RoundLot
#ifdef DEBUG2
        int t_MarketSegmentGrp_i_0_RoundLotexponenta_start = *offset;
#endif

        //>>> RoundLot
        if (packet[*offset] == 0x80)
        {
            (*offset)++;
            t->MarketSegmentGrp[i_0].RoundLot.exponenta.is_null = 1;
        }
        else
        {
            t->MarketSegmentGrp[i_0].RoundLot.exponenta.value = 0 - (packet[*offset] & 0x40);
            t->MarketSegmentGrp[i_0].RoundLot.exponenta.is_null = 0;
            while (!((packet[*offset] & 0x80)))
            {
                (t->MarketSegmentGrp[i_0].RoundLot.exponenta.value) |= packet[(*offset)++];
                (t->MarketSegmentGrp[i_0].RoundLot.exponenta.value) <<= 7;
            }
            (t->MarketSegmentGrp[i_0].RoundLot.exponenta.value) |= (packet[(*offset)++] & 0x7f);
            if (t->MarketSegmentGrp[i_0].RoundLot.exponenta.value > 0)
            {
                (t->MarketSegmentGrp[i_0].RoundLot.exponenta.value)--;
            }
        }
        //<<<

#ifdef DEBUG

        if (t->MarketSegmentGrp[i_0].RoundLot.exponenta.is_null)
        {
            printf("t->MarketSegmentGrp[%d].RoundLot.exponenta = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
        }
        else
        {
            printf("t->MarketSegmentGrp[%d].RoundLot.exponenta = %s%d%s\n", i_0, KMAG, t->MarketSegmentGrp[i_0].RoundLot.exponenta.value, RESET_COLOR);
        }

#endif

#ifdef DEBUG1
        printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
        printf("name = %sRoundLot%s\n", KRED, RESET_COLOR);
        printf("type = %snopmap_int32_nullable_noop\n%s", KBLU, RESET_COLOR);
        printf("byte_representation: ");
        printf("%s", COLOR_BYTES);
        for (int i = t_MarketSegmentGrp_i_0_RoundLotexponenta_start; i < *offset; i++)
        {
            printf("%02x ", packet[i]);
        }
        printf("%s\n", RESET_COLOR);

        if (t->MarketSegmentGrp[i_0].RoundLot.exponenta.is_null)
        {
            printf("t->MarketSegmentGrp[%d].RoundLot.exponenta = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
        }
        else
        {
            printf("t->MarketSegmentGrp[%d].RoundLot.exponenta = %s%d%s\n", i_0, KMAG, t->MarketSegmentGrp[i_0].RoundLot.exponenta.value, RESET_COLOR);
        }

        printf("\n");
#endif

#ifdef DEBUG3
        getchar();
#endif

        if (!t->MarketSegmentGrp[i_0].RoundLot.exponenta.is_null)
        {
            //calc mantissa
            //nopmap_int64_nonullable_noop RoundLot
#ifdef DEBUG2
            int t_MarketSegmentGrp_i_0_RoundLotmantissa_start = *offset;
#endif

            //>>> RoundLot
            t->MarketSegmentGrp[i_0].RoundLot.mantissa = 0 - (packet[*offset] & 0x40);
            while (!((packet[*offset] & 0x80)))
            {
                t->MarketSegmentGrp[i_0].RoundLot.mantissa |= packet[(*offset)++];
                t->MarketSegmentGrp[i_0].RoundLot.mantissa <<= 7;
            }
            t->MarketSegmentGrp[i_0].RoundLot.mantissa |= (packet[(*offset)++] & 0x7f);
            //<<<

#ifdef DEBUG
            printf("t->MarketSegmentGrp[%d].RoundLot.mantissa = %ld\n", i_0, t->MarketSegmentGrp[i_0].RoundLot.mantissa);
#endif

#ifdef DEBUG1
            printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
            printf("name = %sRoundLot%s\n", KRED, RESET_COLOR);
            printf("type = %snopmap_int64_nonullable_noop\n%s", KBLU, RESET_COLOR);
            printf("byte_representation: ");
            printf("%s", COLOR_BYTES);
            for (int i = t_MarketSegmentGrp_i_0_RoundLotmantissa_start; i < *offset; i++)
            {
                printf("%02x ", packet[i]);
            }
            printf("%s\n", RESET_COLOR);
            printf("value = %s%ld%s\n", KMAG, t->MarketSegmentGrp[i_0].RoundLot.mantissa, RESET_COLOR);
            printf("\n");
#endif

#ifdef DEBUG3
            getchar();
#endif
        }

//nopmap_uint32_nullable_noop NoTradingSessionRules
#ifdef DEBUG2
        int t_MarketSegmentGrp_i_0_NoTradingSessionRules_start = *offset;
#endif

        //>>> NoTradingSessionRules
        if (packet[*offset] == 0x80)
        {
            t->MarketSegmentGrp[i_0].NoTradingSessionRules.is_null = 1;
            t->MarketSegmentGrp[i_0].NoTradingSessionRules.value = 0;
            (*offset)++;
        }
        else
        {
            t->MarketSegmentGrp[i_0].NoTradingSessionRules.value = 0;
            t->MarketSegmentGrp[i_0].NoTradingSessionRules.is_null = 0;
            while (!((packet[*offset] & 0x80)))
            {
                (t->MarketSegmentGrp[i_0].NoTradingSessionRules.value) |= packet[(*offset)++];
                (t->MarketSegmentGrp[i_0].NoTradingSessionRules.value) <<= 7;
            }
            (t->MarketSegmentGrp[i_0].NoTradingSessionRules.value) |= (packet[(*offset)++] & 0x7f);
            (t->MarketSegmentGrp[i_0].NoTradingSessionRules.value)--;
        }
        //<<<

#ifdef DEBUG

        if (t->MarketSegmentGrp[i_0].NoTradingSessionRules.is_null)
        {
            printf("t->MarketSegmentGrp[%d].NoTradingSessionRules = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
        }
        else
        {
            printf("t->MarketSegmentGrp[%d].NoTradingSessionRules = %s%u%s\n", i_0, KMAG, t->MarketSegmentGrp[i_0].NoTradingSessionRules.value, RESET_COLOR);
        }

#endif

#ifdef DEBUG1
        printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
        printf("name = %sNoTradingSessionRules%s\n", KRED, RESET_COLOR);
        printf("type = %snopmap_uint32_nullable_noop\n%s", KBLU, RESET_COLOR);
        printf("byte_representation: ");
        printf("%s", COLOR_BYTES);
        for (int i = t_MarketSegmentGrp_i_0_NoTradingSessionRules_start; i < *offset; i++)
        {
            printf("%02x ", packet[i]);
        }
        printf("%s\n", RESET_COLOR);

        if (t->MarketSegmentGrp[i_0].NoTradingSessionRules.is_null)
        {
            printf("t->MarketSegmentGrp[%d].NoTradingSessionRules = %sNULL%s\n", i_0, KMAG, RESET_COLOR);
        }
        else
        {
            printf("t->MarketSegmentGrp[%d].NoTradingSessionRules = %s%u%s\n", i_0, KMAG, t->MarketSegmentGrp[i_0].NoTradingSessionRules.value, RESET_COLOR);
        }

        printf("\n");
#endif

#ifdef DEBUG3
        getchar();
#endif

        if (t->MarketSegmentGrp[i_0].NoTradingSessionRules.value >= moex_eq__d__MarketSegmentGrp__TradingSessionRulesGrp__MAX)
        {
            return -1;
        }

        for (int i_1 = 0; i_1 < t->MarketSegmentGrp[i_0].NoTradingSessionRules.value; i_1++)
        {
            //PMAP for this sequence doesn't required
            //nopmap_string_nonullable_noop TradingSessionID
#ifdef DEBUG2
            int t_MarketSegmentGrp_i_0_TradingSessionRulesGrp_i_1_TradingSessionID_start = *offset;
#endif

            //>>> TradingSessionID
            t->MarketSegmentGrp[i_0].TradingSessionRulesGrp[i_1].TradingSessionID.start = packet + *offset;
            if (packet[*offset] == 0x80)
            {
                (*offset)++;
                t->MarketSegmentGrp[i_0].TradingSessionRulesGrp[i_1].TradingSessionID.len = 0;
                t->MarketSegmentGrp[i_0].TradingSessionRulesGrp[i_1].TradingSessionID.is_null = 1;
                //printf("t->MarketSegmentGrp[i_0].TradingSessionRulesGrp[i_1].TradingSessionID = EMPTY \n");
            }
            else
            {
                t->MarketSegmentGrp[i_0].TradingSessionRulesGrp[i_1].TradingSessionID.len = 0;
                while (!((packet[(*offset)] & 0x80)))
                {
                    t->MarketSegmentGrp[i_0].TradingSessionRulesGrp[i_1].TradingSessionID.len++;
                    (*offset)++;
                }
                packet[*offset] = packet[*offset] & 0x7F;
                (*offset)++;
                t->MarketSegmentGrp[i_0].TradingSessionRulesGrp[i_1].TradingSessionID.len++;
            }
            //<<<

#ifdef DEBUG

            {
                unsigned char fake[128];
                strncpy(fake, t->MarketSegmentGrp[i_0].TradingSessionRulesGrp[i_1].TradingSessionID.start, t->MarketSegmentGrp[i_0].TradingSessionRulesGrp[i_1].TradingSessionID.len);
                fake[t->MarketSegmentGrp[i_0].TradingSessionRulesGrp[i_1].TradingSessionID.len] = '\0';
                printf("t->MarketSegmentGrp[%d].TradingSessionRulesGrp[%d].TradingSessionID = %s%s%s\n", i_0, i_1, KMAG, fake, RESET_COLOR);
            }

#endif

#ifdef DEBUG1
            printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
            printf("name = %sTradingSessionID%s\n", KRED, RESET_COLOR);
            printf("type = %s nopmap_string_nonullable_noop\n%s", KBLU, RESET_COLOR);
            printf("byte_representation: ");
            printf("%s", COLOR_BYTES);
            for (int i = t_MarketSegmentGrp_i_0_TradingSessionRulesGrp_i_1_TradingSessionID_start; i < *offset; i++)
            {
                printf("%02x ", packet[i]);
            }
            printf("%s\n", RESET_COLOR);

            {
                unsigned char fake[128];
                strncpy(fake, t->MarketSegmentGrp[i_0].TradingSessionRulesGrp[i_1].TradingSessionID.start, t->MarketSegmentGrp[i_0].TradingSessionRulesGrp[i_1].TradingSessionID.len);
                fake[t->MarketSegmentGrp[i_0].TradingSessionRulesGrp[i_1].TradingSessionID.len] = '\0';
                printf("t->MarketSegmentGrp[%d].TradingSessionRulesGrp[%d].TradingSessionID = %s%s%s\n", i_0, i_1, KMAG, fake, RESET_COLOR);
            }

            printf("\n");
#endif

#ifdef DEBUG3
            getchar();
#endif

            //nopmap_string_nullable_noop TradingSessionSubID
#ifdef DEBUG2
            int t_MarketSegmentGrp_i_0_TradingSessionRulesGrp_i_1_TradingSessionSubID_start = *offset;
#endif

            //>>> TradingSessionSubID
            t->MarketSegmentGrp[i_0].TradingSessionRulesGrp[i_1].TradingSessionSubID.start = packet + *offset;
            if (packet[*offset] == 0x80)
            {
                (*offset)++;
                t->MarketSegmentGrp[i_0].TradingSessionRulesGrp[i_1].TradingSessionSubID.len = 0;
                t->MarketSegmentGrp[i_0].TradingSessionRulesGrp[i_1].TradingSessionSubID.is_null = 1;
                //printf("t->MarketSegmentGrp[i_0].TradingSessionRulesGrp[i_1].TradingSessionSubID = EMPTY \n");
            }
            else
            {
                t->MarketSegmentGrp[i_0].TradingSessionRulesGrp[i_1].TradingSessionSubID.len = 0;
                t->MarketSegmentGrp[i_0].TradingSessionRulesGrp[i_1].TradingSessionSubID.is_null = 0;
                while (!((packet[(*offset)] & 0x80)))
                {
                    t->MarketSegmentGrp[i_0].TradingSessionRulesGrp[i_1].TradingSessionSubID.len++;
                    (*offset)++;
                }
                packet[*offset] = packet[*offset] & 0x7F;
                (*offset)++;
                t->MarketSegmentGrp[i_0].TradingSessionRulesGrp[i_1].TradingSessionSubID.len++;
            }
            //<<<

#ifdef DEBUG

            if (1)
            {

                if (t->MarketSegmentGrp[i_0].TradingSessionRulesGrp[i_1].TradingSessionSubID.is_null)
                {
                    printf("t->MarketSegmentGrp[%d].TradingSessionRulesGrp[%d].TradingSessionSubID = %sNULL%s\n", i_0, i_1, KMAG, RESET_COLOR);
                }
                else
                {
                    unsigned char fake[128];
                    strncpy(fake, t->MarketSegmentGrp[i_0].TradingSessionRulesGrp[i_1].TradingSessionSubID.start, t->MarketSegmentGrp[i_0].TradingSessionRulesGrp[i_1].TradingSessionSubID.len);
                    fake[t->MarketSegmentGrp[i_0].TradingSessionRulesGrp[i_1].TradingSessionSubID.len] = '\0';
                    printf("t->MarketSegmentGrp[%d].TradingSessionRulesGrp[%d].TradingSessionSubID = %s%s%s\n", i_0, i_1, KMAG, fake, RESET_COLOR);
                }
            }

#endif

#ifdef DEBUG1
            printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
            printf("name = %sTradingSessionSubID%s\n", KRED, RESET_COLOR);
            printf("type = %s nopmap_string_nullable_noop\n%s", KBLU, RESET_COLOR);
            printf("byte_representation: ");
            printf("%s", COLOR_BYTES);
            for (int i = t_MarketSegmentGrp_i_0_TradingSessionRulesGrp_i_1_TradingSessionSubID_start; i < *offset; i++)
            {
                printf("%02x ", packet[i]);
            }
            printf("%s\n", RESET_COLOR);

            if (1)
            {

                if (t->MarketSegmentGrp[i_0].TradingSessionRulesGrp[i_1].TradingSessionSubID.is_null)
                {
                    printf("t->MarketSegmentGrp[%d].TradingSessionRulesGrp[%d].TradingSessionSubID = %sNULL%s\n", i_0, i_1, KMAG, RESET_COLOR);
                }
                else
                {
                    unsigned char fake[128];
                    strncpy(fake, t->MarketSegmentGrp[i_0].TradingSessionRulesGrp[i_1].TradingSessionSubID.start, t->MarketSegmentGrp[i_0].TradingSessionRulesGrp[i_1].TradingSessionSubID.len);
                    fake[t->MarketSegmentGrp[i_0].TradingSessionRulesGrp[i_1].TradingSessionSubID.len] = '\0';
                    printf("t->MarketSegmentGrp[%d].TradingSessionRulesGrp[%d].TradingSessionSubID = %s%s%s\n", i_0, i_1, KMAG, fake, RESET_COLOR);
                }
            }

            printf("\n");
#endif

#ifdef DEBUG3
            getchar();
#endif

//nopmap_int32_nullable_noop SecurityTradingStatus
#ifdef DEBUG2
            int t_MarketSegmentGrp_i_0_TradingSessionRulesGrp_i_1_SecurityTradingStatus_start = *offset;
#endif

            //>>> SecurityTradingStatus
            if (packet[*offset] == 0x80)
            {
                (*offset)++;
                t->MarketSegmentGrp[i_0].TradingSessionRulesGrp[i_1].SecurityTradingStatus.is_null = 1;
            }
            else
            {
                t->MarketSegmentGrp[i_0].TradingSessionRulesGrp[i_1].SecurityTradingStatus.value = 0 - (packet[*offset] & 0x40);
                t->MarketSegmentGrp[i_0].TradingSessionRulesGrp[i_1].SecurityTradingStatus.is_null = 0;
                while (!((packet[*offset] & 0x80)))
                {
                    (t->MarketSegmentGrp[i_0].TradingSessionRulesGrp[i_1].SecurityTradingStatus.value) |= packet[(*offset)++];
                    (t->MarketSegmentGrp[i_0].TradingSessionRulesGrp[i_1].SecurityTradingStatus.value) <<= 7;
                }
                (t->MarketSegmentGrp[i_0].TradingSessionRulesGrp[i_1].SecurityTradingStatus.value) |= (packet[(*offset)++] & 0x7f);
                if (t->MarketSegmentGrp[i_0].TradingSessionRulesGrp[i_1].SecurityTradingStatus.value > 0)
                {
                    (t->MarketSegmentGrp[i_0].TradingSessionRulesGrp[i_1].SecurityTradingStatus.value)--;
                }
            }
            //<<<

#ifdef DEBUG

            if (t->MarketSegmentGrp[i_0].TradingSessionRulesGrp[i_1].SecurityTradingStatus.is_null)
            {
                printf("t->MarketSegmentGrp[%d].TradingSessionRulesGrp[%d].SecurityTradingStatus = %sNULL%s\n", i_0, i_1, KMAG, RESET_COLOR);
            }
            else
            {
                printf("t->MarketSegmentGrp[%d].TradingSessionRulesGrp[%d].SecurityTradingStatus = %s%d%s\n", i_0, i_1, KMAG, t->MarketSegmentGrp[i_0].TradingSessionRulesGrp[i_1].SecurityTradingStatus.value, RESET_COLOR);
            }

#endif

#ifdef DEBUG1
            printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
            printf("name = %sSecurityTradingStatus%s\n", KRED, RESET_COLOR);
            printf("type = %snopmap_int32_nullable_noop\n%s", KBLU, RESET_COLOR);
            printf("byte_representation: ");
            printf("%s", COLOR_BYTES);
            for (int i = t_MarketSegmentGrp_i_0_TradingSessionRulesGrp_i_1_SecurityTradingStatus_start; i < *offset; i++)
            {
                printf("%02x ", packet[i]);
            }
            printf("%s\n", RESET_COLOR);

            if (t->MarketSegmentGrp[i_0].TradingSessionRulesGrp[i_1].SecurityTradingStatus.is_null)
            {
                printf("t->MarketSegmentGrp[%d].TradingSessionRulesGrp[%d].SecurityTradingStatus = %sNULL%s\n", i_0, i_1, KMAG, RESET_COLOR);
            }
            else
            {
                printf("t->MarketSegmentGrp[%d].TradingSessionRulesGrp[%d].SecurityTradingStatus = %s%d%s\n", i_0, i_1, KMAG, t->MarketSegmentGrp[i_0].TradingSessionRulesGrp[i_1].SecurityTradingStatus.value, RESET_COLOR);
            }

            printf("\n");
#endif

#ifdef DEBUG3
            getchar();
#endif

//nopmap_int32_nullable_noop OrderNote
#ifdef DEBUG2
            int t_MarketSegmentGrp_i_0_TradingSessionRulesGrp_i_1_OrderNote_start = *offset;
#endif

            //>>> OrderNote
            if (packet[*offset] == 0x80)
            {
                (*offset)++;
                t->MarketSegmentGrp[i_0].TradingSessionRulesGrp[i_1].OrderNote.is_null = 1;
            }
            else
            {
                t->MarketSegmentGrp[i_0].TradingSessionRulesGrp[i_1].OrderNote.value = 0 - (packet[*offset] & 0x40);
                t->MarketSegmentGrp[i_0].TradingSessionRulesGrp[i_1].OrderNote.is_null = 0;
                while (!((packet[*offset] & 0x80)))
                {
                    (t->MarketSegmentGrp[i_0].TradingSessionRulesGrp[i_1].OrderNote.value) |= packet[(*offset)++];
                    (t->MarketSegmentGrp[i_0].TradingSessionRulesGrp[i_1].OrderNote.value) <<= 7;
                }
                (t->MarketSegmentGrp[i_0].TradingSessionRulesGrp[i_1].OrderNote.value) |= (packet[(*offset)++] & 0x7f);
                if (t->MarketSegmentGrp[i_0].TradingSessionRulesGrp[i_1].OrderNote.value > 0)
                {
                    (t->MarketSegmentGrp[i_0].TradingSessionRulesGrp[i_1].OrderNote.value)--;
                }
            }
            //<<<

#ifdef DEBUG

            if (t->MarketSegmentGrp[i_0].TradingSessionRulesGrp[i_1].OrderNote.is_null)
            {
                printf("t->MarketSegmentGrp[%d].TradingSessionRulesGrp[%d].OrderNote = %sNULL%s\n", i_0, i_1, KMAG, RESET_COLOR);
            }
            else
            {
                printf("t->MarketSegmentGrp[%d].TradingSessionRulesGrp[%d].OrderNote = %s%d%s\n", i_0, i_1, KMAG, t->MarketSegmentGrp[i_0].TradingSessionRulesGrp[i_1].OrderNote.value, RESET_COLOR);
            }

#endif

#ifdef DEBUG1
            printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
            printf("name = %sOrderNote%s\n", KRED, RESET_COLOR);
            printf("type = %snopmap_int32_nullable_noop\n%s", KBLU, RESET_COLOR);
            printf("byte_representation: ");
            printf("%s", COLOR_BYTES);
            for (int i = t_MarketSegmentGrp_i_0_TradingSessionRulesGrp_i_1_OrderNote_start; i < *offset; i++)
            {
                printf("%02x ", packet[i]);
            }
            printf("%s\n", RESET_COLOR);

            if (t->MarketSegmentGrp[i_0].TradingSessionRulesGrp[i_1].OrderNote.is_null)
            {
                printf("t->MarketSegmentGrp[%d].TradingSessionRulesGrp[%d].OrderNote = %sNULL%s\n", i_0, i_1, KMAG, RESET_COLOR);
            }
            else
            {
                printf("t->MarketSegmentGrp[%d].TradingSessionRulesGrp[%d].OrderNote = %s%d%s\n", i_0, i_1, KMAG, t->MarketSegmentGrp[i_0].TradingSessionRulesGrp[i_1].OrderNote.value, RESET_COLOR);
            }

            printf("\n");
#endif

#ifdef DEBUG3
            getchar();
#endif
        }
    }
    //nopmap_string_nullable_noop SettlCurrency
#ifdef DEBUG2
    int t_SettlCurrency_start = *offset;
#endif

    //>>> SettlCurrency
    t->SettlCurrency.start = packet + *offset;
    if (packet[*offset] == 0x80)
    {
        (*offset)++;
        t->SettlCurrency.len = 0;
        t->SettlCurrency.is_null = 1;
        //printf("t->SettlCurrency = EMPTY \n");
    }
    else
    {
        t->SettlCurrency.len = 0;
        t->SettlCurrency.is_null = 0;
        while (!((packet[(*offset)] & 0x80)))
        {
            t->SettlCurrency.len++;
            (*offset)++;
        }
        packet[*offset] = packet[*offset] & 0x7F;
        (*offset)++;
        t->SettlCurrency.len++;
    }
    //<<<

#ifdef DEBUG

    if (1)
    {

        if (t->SettlCurrency.is_null)
        {
            printf("t->SettlCurrency = %sNULL%s\n", KMAG, RESET_COLOR);
        }
        else
        {
            unsigned char fake[128];
            strncpy(fake, t->SettlCurrency.start, t->SettlCurrency.len);
            fake[t->SettlCurrency.len] = '\0';
            printf("t->SettlCurrency = %s%s%s\n", KMAG, fake, RESET_COLOR);
        }
    }

#endif

#ifdef DEBUG1
    printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
    printf("name = %sSettlCurrency%s\n", KRED, RESET_COLOR);
    printf("type = %s nopmap_string_nullable_noop\n%s", KBLU, RESET_COLOR);
    printf("byte_representation: ");
    printf("%s", COLOR_BYTES);
    for (int i = t_SettlCurrency_start; i < *offset; i++)
    {
        printf("%02x ", packet[i]);
    }
    printf("%s\n", RESET_COLOR);

    if (1)
    {

        if (t->SettlCurrency.is_null)
        {
            printf("t->SettlCurrency = %sNULL%s\n", KMAG, RESET_COLOR);
        }
        else
        {
            unsigned char fake[128];
            strncpy(fake, t->SettlCurrency.start, t->SettlCurrency.len);
            fake[t->SettlCurrency.len] = '\0';
            printf("t->SettlCurrency = %s%s%s\n", KMAG, fake, RESET_COLOR);
        }
    }

    printf("\n");
#endif

#ifdef DEBUG3
    getchar();
#endif

//nopmap_int32_nullable_noop PriceType
#ifdef DEBUG2
    int t_PriceType_start = *offset;
#endif

    //>>> PriceType
    if (packet[*offset] == 0x80)
    {
        (*offset)++;
        t->PriceType.is_null = 1;
    }
    else
    {
        t->PriceType.value = 0 - (packet[*offset] & 0x40);
        t->PriceType.is_null = 0;
        while (!((packet[*offset] & 0x80)))
        {
            (t->PriceType.value) |= packet[(*offset)++];
            (t->PriceType.value) <<= 7;
        }
        (t->PriceType.value) |= (packet[(*offset)++] & 0x7f);
        if (t->PriceType.value > 0)
        {
            (t->PriceType.value)--;
        }
    }
    //<<<

#ifdef DEBUG

    if (t->PriceType.is_null)
    {
        printf("t->PriceType = %sNULL%s\n", KMAG, RESET_COLOR);
    }
    else
    {
        printf("t->PriceType = %s%d%s\n", KMAG, t->PriceType.value, RESET_COLOR);
    }

#endif

#ifdef DEBUG1
    printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
    printf("name = %sPriceType%s\n", KRED, RESET_COLOR);
    printf("type = %snopmap_int32_nullable_noop\n%s", KBLU, RESET_COLOR);
    printf("byte_representation: ");
    printf("%s", COLOR_BYTES);
    for (int i = t_PriceType_start; i < *offset; i++)
    {
        printf("%02x ", packet[i]);
    }
    printf("%s\n", RESET_COLOR);

    if (t->PriceType.is_null)
    {
        printf("t->PriceType = %sNULL%s\n", KMAG, RESET_COLOR);
    }
    else
    {
        printf("t->PriceType = %s%d%s\n", KMAG, t->PriceType.value, RESET_COLOR);
    }

    printf("\n");
#endif

#ifdef DEBUG3
    getchar();
#endif

    //nopmap_string_nullable_noop StateSecurityID
#ifdef DEBUG2
    int t_StateSecurityID_start = *offset;
#endif

    //>>> StateSecurityID
    t->StateSecurityID.start = packet + *offset;
    if (packet[*offset] == 0x80)
    {
        (*offset)++;
        t->StateSecurityID.len = 0;
        t->StateSecurityID.is_null = 1;
        //printf("t->StateSecurityID = EMPTY \n");
    }
    else
    {
        t->StateSecurityID.len = 0;
        t->StateSecurityID.is_null = 0;
        while (!((packet[(*offset)] & 0x80)))
        {
            t->StateSecurityID.len++;
            (*offset)++;
        }
        packet[*offset] = packet[*offset] & 0x7F;
        (*offset)++;
        t->StateSecurityID.len++;
    }
    //<<<

#ifdef DEBUG

    if (1)
    {

        if (t->StateSecurityID.is_null)
        {
            printf("t->StateSecurityID = %sNULL%s\n", KMAG, RESET_COLOR);
        }
        else
        {
            unsigned char fake[128];
            strncpy(fake, t->StateSecurityID.start, t->StateSecurityID.len);
            fake[t->StateSecurityID.len] = '\0';
            printf("t->StateSecurityID = %s%s%s\n", KMAG, fake, RESET_COLOR);
        }
    }

#endif

#ifdef DEBUG1
    printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
    printf("name = %sStateSecurityID%s\n", KRED, RESET_COLOR);
    printf("type = %s nopmap_string_nullable_noop\n%s", KBLU, RESET_COLOR);
    printf("byte_representation: ");
    printf("%s", COLOR_BYTES);
    for (int i = t_StateSecurityID_start; i < *offset; i++)
    {
        printf("%02x ", packet[i]);
    }
    printf("%s\n", RESET_COLOR);

    if (1)
    {

        if (t->StateSecurityID.is_null)
        {
            printf("t->StateSecurityID = %sNULL%s\n", KMAG, RESET_COLOR);
        }
        else
        {
            unsigned char fake[128];
            strncpy(fake, t->StateSecurityID.start, t->StateSecurityID.len);
            fake[t->StateSecurityID.len] = '\0';
            printf("t->StateSecurityID = %s%s%s\n", KMAG, fake, RESET_COLOR);
        }
    }

    printf("\n");
#endif

#ifdef DEBUG3
    getchar();
#endif

    //nopmap_bytevector_nullable_noop (lazy evaluation)
    if (packet[*offset] == 0x80)
    {
        t->EncodedShortSecurityDesc.len = 0;
        t->EncodedShortSecurityDesc.start = packet + *offset;
        (*offset)++;
        t->EncodedShortSecurityDesc.is_null = 1;
    }
    else
    {
        t->EncodedShortSecurityDesc.len = 0;
        t->EncodedShortSecurityDesc.is_null = 0;
        while (!((packet[*offset] & 0x80)))
        {
            t->EncodedShortSecurityDesc.len |= packet[(*offset)++];
            t->EncodedShortSecurityDesc.len <<= 7;
        }
        t->EncodedShortSecurityDesc.len |= (packet[(*offset)++] & 0x7f);
        t->EncodedShortSecurityDesc.len--;
        t->EncodedShortSecurityDesc.start = packet + *offset;
        (*offset) += t->EncodedShortSecurityDesc.len;
        char fake[128];
        strncpy(fake, t->EncodedShortSecurityDesc.start, t->EncodedShortSecurityDesc.len);
        fake[t->EncodedShortSecurityDesc.len] = '\0';
        //printf("t->EncodedShortSecurityDesc = %s\n", fake);
    }
#ifdef DEBUG

    if (t->EncodedShortSecurityDesc.is_null)
    {
        printf("t->EncodedShortSecurityDesc = %sNULL%s\n", KMAG, RESET_COLOR);
    }
    else
    {
        unsigned char fake[128];
        strncpy(fake, t->EncodedShortSecurityDesc.start, t->EncodedShortSecurityDesc.len);
        fake[t->EncodedShortSecurityDesc.len] = '\0';
        printf("t->EncodedShortSecurityDesc = %s%s%s\n", KMAG, fake, RESET_COLOR);
    }

#endif

    //nopmap_bytevector_nullable_noop (lazy evaluation)
    if (packet[*offset] == 0x80)
    {
        t->MarketCode.len = 0;
        t->MarketCode.start = packet + *offset;
        (*offset)++;
        t->MarketCode.is_null = 1;
    }
    else
    {
        t->MarketCode.len = 0;
        t->MarketCode.is_null = 0;
        while (!((packet[*offset] & 0x80)))
        {
            t->MarketCode.len |= packet[(*offset)++];
            t->MarketCode.len <<= 7;
        }
        t->MarketCode.len |= (packet[(*offset)++] & 0x7f);
        t->MarketCode.len--;
        t->MarketCode.start = packet + *offset;
        (*offset) += t->MarketCode.len;
        char fake[128];
        strncpy(fake, t->MarketCode.start, t->MarketCode.len);
        fake[t->MarketCode.len] = '\0';
        //printf("t->MarketCode = %s\n", fake);
    }
#ifdef DEBUG

    if (t->MarketCode.is_null)
    {
        printf("t->MarketCode = %sNULL%s\n", KMAG, RESET_COLOR);
    }
    else
    {
        unsigned char fake[128];
        strncpy(fake, t->MarketCode.start, t->MarketCode.len);
        fake[t->MarketCode.len] = '\0';
        printf("t->MarketCode = %s%s%s\n", KMAG, fake, RESET_COLOR);
    }

#endif

    //nopmap_decimal_nullable_noop

//nopmap_int32_nullable_noop MinPriceIncrement
#ifdef DEBUG2
    int t_MinPriceIncrementexponenta_start = *offset;
#endif

    //>>> MinPriceIncrement
    if (packet[*offset] == 0x80)
    {
        (*offset)++;
        t->MinPriceIncrement.exponenta.is_null = 1;
    }
    else
    {
        t->MinPriceIncrement.exponenta.value = 0 - (packet[*offset] & 0x40);
        t->MinPriceIncrement.exponenta.is_null = 0;
        while (!((packet[*offset] & 0x80)))
        {
            (t->MinPriceIncrement.exponenta.value) |= packet[(*offset)++];
            (t->MinPriceIncrement.exponenta.value) <<= 7;
        }
        (t->MinPriceIncrement.exponenta.value) |= (packet[(*offset)++] & 0x7f);
        if (t->MinPriceIncrement.exponenta.value > 0)
        {
            (t->MinPriceIncrement.exponenta.value)--;
        }
    }
    //<<<

#ifdef DEBUG

    if (t->MinPriceIncrement.exponenta.is_null)
    {
        printf("t->MinPriceIncrement.exponenta = %sNULL%s\n", KMAG, RESET_COLOR);
    }
    else
    {
        printf("t->MinPriceIncrement.exponenta = %s%d%s\n", KMAG, t->MinPriceIncrement.exponenta.value, RESET_COLOR);
    }

#endif

#ifdef DEBUG1
    printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
    printf("name = %sMinPriceIncrement%s\n", KRED, RESET_COLOR);
    printf("type = %snopmap_int32_nullable_noop\n%s", KBLU, RESET_COLOR);
    printf("byte_representation: ");
    printf("%s", COLOR_BYTES);
    for (int i = t_MinPriceIncrementexponenta_start; i < *offset; i++)
    {
        printf("%02x ", packet[i]);
    }
    printf("%s\n", RESET_COLOR);

    if (t->MinPriceIncrement.exponenta.is_null)
    {
        printf("t->MinPriceIncrement.exponenta = %sNULL%s\n", KMAG, RESET_COLOR);
    }
    else
    {
        printf("t->MinPriceIncrement.exponenta = %s%d%s\n", KMAG, t->MinPriceIncrement.exponenta.value, RESET_COLOR);
    }

    printf("\n");
#endif

#ifdef DEBUG3
    getchar();
#endif

    if (!t->MinPriceIncrement.exponenta.is_null)
    {
        //calc mantissa
        //nopmap_int64_nonullable_noop MinPriceIncrement
#ifdef DEBUG2
        int t_MinPriceIncrementmantissa_start = *offset;
#endif

        //>>> MinPriceIncrement
        t->MinPriceIncrement.mantissa = 0 - (packet[*offset] & 0x40);
        while (!((packet[*offset] & 0x80)))
        {
            t->MinPriceIncrement.mantissa |= packet[(*offset)++];
            t->MinPriceIncrement.mantissa <<= 7;
        }
        t->MinPriceIncrement.mantissa |= (packet[(*offset)++] & 0x7f);
        //<<<

#ifdef DEBUG
        printf("t->MinPriceIncrement.mantissa = %ld\n", t->MinPriceIncrement.mantissa);
#endif

#ifdef DEBUG1
        printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
        printf("name = %sMinPriceIncrement%s\n", KRED, RESET_COLOR);
        printf("type = %snopmap_int64_nonullable_noop\n%s", KBLU, RESET_COLOR);
        printf("byte_representation: ");
        printf("%s", COLOR_BYTES);
        for (int i = t_MinPriceIncrementmantissa_start; i < *offset; i++)
        {
            printf("%02x ", packet[i]);
        }
        printf("%s\n", RESET_COLOR);
        printf("value = %s%ld%s\n", KMAG, t->MinPriceIncrement.mantissa, RESET_COLOR);
        printf("\n");
#endif

#ifdef DEBUG3
        getchar();
#endif
    }

    //nopmap_decimal_nullable_noop

//nopmap_int32_nullable_noop MktShareLimit
#ifdef DEBUG2
    int t_MktShareLimitexponenta_start = *offset;
#endif

    //>>> MktShareLimit
    if (packet[*offset] == 0x80)
    {
        (*offset)++;
        t->MktShareLimit.exponenta.is_null = 1;
    }
    else
    {
        t->MktShareLimit.exponenta.value = 0 - (packet[*offset] & 0x40);
        t->MktShareLimit.exponenta.is_null = 0;
        while (!((packet[*offset] & 0x80)))
        {
            (t->MktShareLimit.exponenta.value) |= packet[(*offset)++];
            (t->MktShareLimit.exponenta.value) <<= 7;
        }
        (t->MktShareLimit.exponenta.value) |= (packet[(*offset)++] & 0x7f);
        if (t->MktShareLimit.exponenta.value > 0)
        {
            (t->MktShareLimit.exponenta.value)--;
        }
    }
    //<<<

#ifdef DEBUG

    if (t->MktShareLimit.exponenta.is_null)
    {
        printf("t->MktShareLimit.exponenta = %sNULL%s\n", KMAG, RESET_COLOR);
    }
    else
    {
        printf("t->MktShareLimit.exponenta = %s%d%s\n", KMAG, t->MktShareLimit.exponenta.value, RESET_COLOR);
    }

#endif

#ifdef DEBUG1
    printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
    printf("name = %sMktShareLimit%s\n", KRED, RESET_COLOR);
    printf("type = %snopmap_int32_nullable_noop\n%s", KBLU, RESET_COLOR);
    printf("byte_representation: ");
    printf("%s", COLOR_BYTES);
    for (int i = t_MktShareLimitexponenta_start; i < *offset; i++)
    {
        printf("%02x ", packet[i]);
    }
    printf("%s\n", RESET_COLOR);

    if (t->MktShareLimit.exponenta.is_null)
    {
        printf("t->MktShareLimit.exponenta = %sNULL%s\n", KMAG, RESET_COLOR);
    }
    else
    {
        printf("t->MktShareLimit.exponenta = %s%d%s\n", KMAG, t->MktShareLimit.exponenta.value, RESET_COLOR);
    }

    printf("\n");
#endif

#ifdef DEBUG3
    getchar();
#endif

    if (!t->MktShareLimit.exponenta.is_null)
    {
        //calc mantissa
        //nopmap_int64_nonullable_noop MktShareLimit
#ifdef DEBUG2
        int t_MktShareLimitmantissa_start = *offset;
#endif

        //>>> MktShareLimit
        t->MktShareLimit.mantissa = 0 - (packet[*offset] & 0x40);
        while (!((packet[*offset] & 0x80)))
        {
            t->MktShareLimit.mantissa |= packet[(*offset)++];
            t->MktShareLimit.mantissa <<= 7;
        }
        t->MktShareLimit.mantissa |= (packet[(*offset)++] & 0x7f);
        //<<<

#ifdef DEBUG
        printf("t->MktShareLimit.mantissa = %ld\n", t->MktShareLimit.mantissa);
#endif

#ifdef DEBUG1
        printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
        printf("name = %sMktShareLimit%s\n", KRED, RESET_COLOR);
        printf("type = %snopmap_int64_nonullable_noop\n%s", KBLU, RESET_COLOR);
        printf("byte_representation: ");
        printf("%s", COLOR_BYTES);
        for (int i = t_MktShareLimitmantissa_start; i < *offset; i++)
        {
            printf("%02x ", packet[i]);
        }
        printf("%s\n", RESET_COLOR);
        printf("value = %s%ld%s\n", KMAG, t->MktShareLimit.mantissa, RESET_COLOR);
        printf("\n");
#endif

#ifdef DEBUG3
        getchar();
#endif
    }

    //nopmap_decimal_nullable_noop

//nopmap_int32_nullable_noop MktShareThreshold
#ifdef DEBUG2
    int t_MktShareThresholdexponenta_start = *offset;
#endif

    //>>> MktShareThreshold
    if (packet[*offset] == 0x80)
    {
        (*offset)++;
        t->MktShareThreshold.exponenta.is_null = 1;
    }
    else
    {
        t->MktShareThreshold.exponenta.value = 0 - (packet[*offset] & 0x40);
        t->MktShareThreshold.exponenta.is_null = 0;
        while (!((packet[*offset] & 0x80)))
        {
            (t->MktShareThreshold.exponenta.value) |= packet[(*offset)++];
            (t->MktShareThreshold.exponenta.value) <<= 7;
        }
        (t->MktShareThreshold.exponenta.value) |= (packet[(*offset)++] & 0x7f);
        if (t->MktShareThreshold.exponenta.value > 0)
        {
            (t->MktShareThreshold.exponenta.value)--;
        }
    }
    //<<<

#ifdef DEBUG

    if (t->MktShareThreshold.exponenta.is_null)
    {
        printf("t->MktShareThreshold.exponenta = %sNULL%s\n", KMAG, RESET_COLOR);
    }
    else
    {
        printf("t->MktShareThreshold.exponenta = %s%d%s\n", KMAG, t->MktShareThreshold.exponenta.value, RESET_COLOR);
    }

#endif

#ifdef DEBUG1
    printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
    printf("name = %sMktShareThreshold%s\n", KRED, RESET_COLOR);
    printf("type = %snopmap_int32_nullable_noop\n%s", KBLU, RESET_COLOR);
    printf("byte_representation: ");
    printf("%s", COLOR_BYTES);
    for (int i = t_MktShareThresholdexponenta_start; i < *offset; i++)
    {
        printf("%02x ", packet[i]);
    }
    printf("%s\n", RESET_COLOR);

    if (t->MktShareThreshold.exponenta.is_null)
    {
        printf("t->MktShareThreshold.exponenta = %sNULL%s\n", KMAG, RESET_COLOR);
    }
    else
    {
        printf("t->MktShareThreshold.exponenta = %s%d%s\n", KMAG, t->MktShareThreshold.exponenta.value, RESET_COLOR);
    }

    printf("\n");
#endif

#ifdef DEBUG3
    getchar();
#endif

    if (!t->MktShareThreshold.exponenta.is_null)
    {
        //calc mantissa
        //nopmap_int64_nonullable_noop MktShareThreshold
#ifdef DEBUG2
        int t_MktShareThresholdmantissa_start = *offset;
#endif

        //>>> MktShareThreshold
        t->MktShareThreshold.mantissa = 0 - (packet[*offset] & 0x40);
        while (!((packet[*offset] & 0x80)))
        {
            t->MktShareThreshold.mantissa |= packet[(*offset)++];
            t->MktShareThreshold.mantissa <<= 7;
        }
        t->MktShareThreshold.mantissa |= (packet[(*offset)++] & 0x7f);
        //<<<

#ifdef DEBUG
        printf("t->MktShareThreshold.mantissa = %ld\n", t->MktShareThreshold.mantissa);
#endif

#ifdef DEBUG1
        printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
        printf("name = %sMktShareThreshold%s\n", KRED, RESET_COLOR);
        printf("type = %snopmap_int64_nonullable_noop\n%s", KBLU, RESET_COLOR);
        printf("byte_representation: ");
        printf("%s", COLOR_BYTES);
        for (int i = t_MktShareThresholdmantissa_start; i < *offset; i++)
        {
            printf("%02x ", packet[i]);
        }
        printf("%s\n", RESET_COLOR);
        printf("value = %s%ld%s\n", KMAG, t->MktShareThreshold.mantissa, RESET_COLOR);
        printf("\n");
#endif

#ifdef DEBUG3
        getchar();
#endif
    }

    //nopmap_decimal_nullable_noop

//nopmap_int32_nullable_noop MaxOrdersVolume
#ifdef DEBUG2
    int t_MaxOrdersVolumeexponenta_start = *offset;
#endif

    //>>> MaxOrdersVolume
    if (packet[*offset] == 0x80)
    {
        (*offset)++;
        t->MaxOrdersVolume.exponenta.is_null = 1;
    }
    else
    {
        t->MaxOrdersVolume.exponenta.value = 0 - (packet[*offset] & 0x40);
        t->MaxOrdersVolume.exponenta.is_null = 0;
        while (!((packet[*offset] & 0x80)))
        {
            (t->MaxOrdersVolume.exponenta.value) |= packet[(*offset)++];
            (t->MaxOrdersVolume.exponenta.value) <<= 7;
        }
        (t->MaxOrdersVolume.exponenta.value) |= (packet[(*offset)++] & 0x7f);
        if (t->MaxOrdersVolume.exponenta.value > 0)
        {
            (t->MaxOrdersVolume.exponenta.value)--;
        }
    }
    //<<<

#ifdef DEBUG

    if (t->MaxOrdersVolume.exponenta.is_null)
    {
        printf("t->MaxOrdersVolume.exponenta = %sNULL%s\n", KMAG, RESET_COLOR);
    }
    else
    {
        printf("t->MaxOrdersVolume.exponenta = %s%d%s\n", KMAG, t->MaxOrdersVolume.exponenta.value, RESET_COLOR);
    }

#endif

#ifdef DEBUG1
    printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
    printf("name = %sMaxOrdersVolume%s\n", KRED, RESET_COLOR);
    printf("type = %snopmap_int32_nullable_noop\n%s", KBLU, RESET_COLOR);
    printf("byte_representation: ");
    printf("%s", COLOR_BYTES);
    for (int i = t_MaxOrdersVolumeexponenta_start; i < *offset; i++)
    {
        printf("%02x ", packet[i]);
    }
    printf("%s\n", RESET_COLOR);

    if (t->MaxOrdersVolume.exponenta.is_null)
    {
        printf("t->MaxOrdersVolume.exponenta = %sNULL%s\n", KMAG, RESET_COLOR);
    }
    else
    {
        printf("t->MaxOrdersVolume.exponenta = %s%d%s\n", KMAG, t->MaxOrdersVolume.exponenta.value, RESET_COLOR);
    }

    printf("\n");
#endif

#ifdef DEBUG3
    getchar();
#endif

    if (!t->MaxOrdersVolume.exponenta.is_null)
    {
        //calc mantissa
        //nopmap_int64_nonullable_noop MaxOrdersVolume
#ifdef DEBUG2
        int t_MaxOrdersVolumemantissa_start = *offset;
#endif

        //>>> MaxOrdersVolume
        t->MaxOrdersVolume.mantissa = 0 - (packet[*offset] & 0x40);
        while (!((packet[*offset] & 0x80)))
        {
            t->MaxOrdersVolume.mantissa |= packet[(*offset)++];
            t->MaxOrdersVolume.mantissa <<= 7;
        }
        t->MaxOrdersVolume.mantissa |= (packet[(*offset)++] & 0x7f);
        //<<<

#ifdef DEBUG
        printf("t->MaxOrdersVolume.mantissa = %ld\n", t->MaxOrdersVolume.mantissa);
#endif

#ifdef DEBUG1
        printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
        printf("name = %sMaxOrdersVolume%s\n", KRED, RESET_COLOR);
        printf("type = %snopmap_int64_nonullable_noop\n%s", KBLU, RESET_COLOR);
        printf("byte_representation: ");
        printf("%s", COLOR_BYTES);
        for (int i = t_MaxOrdersVolumemantissa_start; i < *offset; i++)
        {
            printf("%02x ", packet[i]);
        }
        printf("%s\n", RESET_COLOR);
        printf("value = %s%ld%s\n", KMAG, t->MaxOrdersVolume.mantissa, RESET_COLOR);
        printf("\n");
#endif

#ifdef DEBUG3
        getchar();
#endif
    }

    //nopmap_decimal_nullable_noop

//nopmap_int32_nullable_noop PriceMvmLimit
#ifdef DEBUG2
    int t_PriceMvmLimitexponenta_start = *offset;
#endif

    //>>> PriceMvmLimit
    if (packet[*offset] == 0x80)
    {
        (*offset)++;
        t->PriceMvmLimit.exponenta.is_null = 1;
    }
    else
    {
        t->PriceMvmLimit.exponenta.value = 0 - (packet[*offset] & 0x40);
        t->PriceMvmLimit.exponenta.is_null = 0;
        while (!((packet[*offset] & 0x80)))
        {
            (t->PriceMvmLimit.exponenta.value) |= packet[(*offset)++];
            (t->PriceMvmLimit.exponenta.value) <<= 7;
        }
        (t->PriceMvmLimit.exponenta.value) |= (packet[(*offset)++] & 0x7f);
        if (t->PriceMvmLimit.exponenta.value > 0)
        {
            (t->PriceMvmLimit.exponenta.value)--;
        }
    }
    //<<<

#ifdef DEBUG

    if (t->PriceMvmLimit.exponenta.is_null)
    {
        printf("t->PriceMvmLimit.exponenta = %sNULL%s\n", KMAG, RESET_COLOR);
    }
    else
    {
        printf("t->PriceMvmLimit.exponenta = %s%d%s\n", KMAG, t->PriceMvmLimit.exponenta.value, RESET_COLOR);
    }

#endif

#ifdef DEBUG1
    printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
    printf("name = %sPriceMvmLimit%s\n", KRED, RESET_COLOR);
    printf("type = %snopmap_int32_nullable_noop\n%s", KBLU, RESET_COLOR);
    printf("byte_representation: ");
    printf("%s", COLOR_BYTES);
    for (int i = t_PriceMvmLimitexponenta_start; i < *offset; i++)
    {
        printf("%02x ", packet[i]);
    }
    printf("%s\n", RESET_COLOR);

    if (t->PriceMvmLimit.exponenta.is_null)
    {
        printf("t->PriceMvmLimit.exponenta = %sNULL%s\n", KMAG, RESET_COLOR);
    }
    else
    {
        printf("t->PriceMvmLimit.exponenta = %s%d%s\n", KMAG, t->PriceMvmLimit.exponenta.value, RESET_COLOR);
    }

    printf("\n");
#endif

#ifdef DEBUG3
    getchar();
#endif

    if (!t->PriceMvmLimit.exponenta.is_null)
    {
        //calc mantissa
        //nopmap_int64_nonullable_noop PriceMvmLimit
#ifdef DEBUG2
        int t_PriceMvmLimitmantissa_start = *offset;
#endif

        //>>> PriceMvmLimit
        t->PriceMvmLimit.mantissa = 0 - (packet[*offset] & 0x40);
        while (!((packet[*offset] & 0x80)))
        {
            t->PriceMvmLimit.mantissa |= packet[(*offset)++];
            t->PriceMvmLimit.mantissa <<= 7;
        }
        t->PriceMvmLimit.mantissa |= (packet[(*offset)++] & 0x7f);
        //<<<

#ifdef DEBUG
        printf("t->PriceMvmLimit.mantissa = %ld\n", t->PriceMvmLimit.mantissa);
#endif

#ifdef DEBUG1
        printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
        printf("name = %sPriceMvmLimit%s\n", KRED, RESET_COLOR);
        printf("type = %snopmap_int64_nonullable_noop\n%s", KBLU, RESET_COLOR);
        printf("byte_representation: ");
        printf("%s", COLOR_BYTES);
        for (int i = t_PriceMvmLimitmantissa_start; i < *offset; i++)
        {
            printf("%02x ", packet[i]);
        }
        printf("%s\n", RESET_COLOR);
        printf("value = %s%ld%s\n", KMAG, t->PriceMvmLimit.mantissa, RESET_COLOR);
        printf("\n");
#endif

#ifdef DEBUG3
        getchar();
#endif
    }

    //nopmap_decimal_nullable_noop

//nopmap_int32_nullable_noop FaceValue
#ifdef DEBUG2
    int t_FaceValueexponenta_start = *offset;
#endif

    //>>> FaceValue
    if (packet[*offset] == 0x80)
    {
        (*offset)++;
        t->FaceValue.exponenta.is_null = 1;
    }
    else
    {
        t->FaceValue.exponenta.value = 0 - (packet[*offset] & 0x40);
        t->FaceValue.exponenta.is_null = 0;
        while (!((packet[*offset] & 0x80)))
        {
            (t->FaceValue.exponenta.value) |= packet[(*offset)++];
            (t->FaceValue.exponenta.value) <<= 7;
        }
        (t->FaceValue.exponenta.value) |= (packet[(*offset)++] & 0x7f);
        if (t->FaceValue.exponenta.value > 0)
        {
            (t->FaceValue.exponenta.value)--;
        }
    }
    //<<<

#ifdef DEBUG

    if (t->FaceValue.exponenta.is_null)
    {
        printf("t->FaceValue.exponenta = %sNULL%s\n", KMAG, RESET_COLOR);
    }
    else
    {
        printf("t->FaceValue.exponenta = %s%d%s\n", KMAG, t->FaceValue.exponenta.value, RESET_COLOR);
    }

#endif

#ifdef DEBUG1
    printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
    printf("name = %sFaceValue%s\n", KRED, RESET_COLOR);
    printf("type = %snopmap_int32_nullable_noop\n%s", KBLU, RESET_COLOR);
    printf("byte_representation: ");
    printf("%s", COLOR_BYTES);
    for (int i = t_FaceValueexponenta_start; i < *offset; i++)
    {
        printf("%02x ", packet[i]);
    }
    printf("%s\n", RESET_COLOR);

    if (t->FaceValue.exponenta.is_null)
    {
        printf("t->FaceValue.exponenta = %sNULL%s\n", KMAG, RESET_COLOR);
    }
    else
    {
        printf("t->FaceValue.exponenta = %s%d%s\n", KMAG, t->FaceValue.exponenta.value, RESET_COLOR);
    }

    printf("\n");
#endif

#ifdef DEBUG3
    getchar();
#endif

    if (!t->FaceValue.exponenta.is_null)
    {
        //calc mantissa
        //nopmap_int64_nonullable_noop FaceValue
#ifdef DEBUG2
        int t_FaceValuemantissa_start = *offset;
#endif

        //>>> FaceValue
        t->FaceValue.mantissa = 0 - (packet[*offset] & 0x40);
        while (!((packet[*offset] & 0x80)))
        {
            t->FaceValue.mantissa |= packet[(*offset)++];
            t->FaceValue.mantissa <<= 7;
        }
        t->FaceValue.mantissa |= (packet[(*offset)++] & 0x7f);
        //<<<

#ifdef DEBUG
        printf("t->FaceValue.mantissa = %ld\n", t->FaceValue.mantissa);
#endif

#ifdef DEBUG1
        printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
        printf("name = %sFaceValue%s\n", KRED, RESET_COLOR);
        printf("type = %snopmap_int64_nonullable_noop\n%s", KBLU, RESET_COLOR);
        printf("byte_representation: ");
        printf("%s", COLOR_BYTES);
        for (int i = t_FaceValuemantissa_start; i < *offset; i++)
        {
            printf("%02x ", packet[i]);
        }
        printf("%s\n", RESET_COLOR);
        printf("value = %s%ld%s\n", KMAG, t->FaceValue.mantissa, RESET_COLOR);
        printf("\n");
#endif

#ifdef DEBUG3
        getchar();
#endif
    }

    //nopmap_decimal_nullable_noop

//nopmap_int32_nullable_noop BaseSwapPx
#ifdef DEBUG2
    int t_BaseSwapPxexponenta_start = *offset;
#endif

    //>>> BaseSwapPx
    if (packet[*offset] == 0x80)
    {
        (*offset)++;
        t->BaseSwapPx.exponenta.is_null = 1;
    }
    else
    {
        t->BaseSwapPx.exponenta.value = 0 - (packet[*offset] & 0x40);
        t->BaseSwapPx.exponenta.is_null = 0;
        while (!((packet[*offset] & 0x80)))
        {
            (t->BaseSwapPx.exponenta.value) |= packet[(*offset)++];
            (t->BaseSwapPx.exponenta.value) <<= 7;
        }
        (t->BaseSwapPx.exponenta.value) |= (packet[(*offset)++] & 0x7f);
        if (t->BaseSwapPx.exponenta.value > 0)
        {
            (t->BaseSwapPx.exponenta.value)--;
        }
    }
    //<<<

#ifdef DEBUG

    if (t->BaseSwapPx.exponenta.is_null)
    {
        printf("t->BaseSwapPx.exponenta = %sNULL%s\n", KMAG, RESET_COLOR);
    }
    else
    {
        printf("t->BaseSwapPx.exponenta = %s%d%s\n", KMAG, t->BaseSwapPx.exponenta.value, RESET_COLOR);
    }

#endif

#ifdef DEBUG1
    printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
    printf("name = %sBaseSwapPx%s\n", KRED, RESET_COLOR);
    printf("type = %snopmap_int32_nullable_noop\n%s", KBLU, RESET_COLOR);
    printf("byte_representation: ");
    printf("%s", COLOR_BYTES);
    for (int i = t_BaseSwapPxexponenta_start; i < *offset; i++)
    {
        printf("%02x ", packet[i]);
    }
    printf("%s\n", RESET_COLOR);

    if (t->BaseSwapPx.exponenta.is_null)
    {
        printf("t->BaseSwapPx.exponenta = %sNULL%s\n", KMAG, RESET_COLOR);
    }
    else
    {
        printf("t->BaseSwapPx.exponenta = %s%d%s\n", KMAG, t->BaseSwapPx.exponenta.value, RESET_COLOR);
    }

    printf("\n");
#endif

#ifdef DEBUG3
    getchar();
#endif

    if (!t->BaseSwapPx.exponenta.is_null)
    {
        //calc mantissa
        //nopmap_int64_nonullable_noop BaseSwapPx
#ifdef DEBUG2
        int t_BaseSwapPxmantissa_start = *offset;
#endif

        //>>> BaseSwapPx
        t->BaseSwapPx.mantissa = 0 - (packet[*offset] & 0x40);
        while (!((packet[*offset] & 0x80)))
        {
            t->BaseSwapPx.mantissa |= packet[(*offset)++];
            t->BaseSwapPx.mantissa <<= 7;
        }
        t->BaseSwapPx.mantissa |= (packet[(*offset)++] & 0x7f);
        //<<<

#ifdef DEBUG
        printf("t->BaseSwapPx.mantissa = %ld\n", t->BaseSwapPx.mantissa);
#endif

#ifdef DEBUG1
        printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
        printf("name = %sBaseSwapPx%s\n", KRED, RESET_COLOR);
        printf("type = %snopmap_int64_nonullable_noop\n%s", KBLU, RESET_COLOR);
        printf("byte_representation: ");
        printf("%s", COLOR_BYTES);
        for (int i = t_BaseSwapPxmantissa_start; i < *offset; i++)
        {
            printf("%02x ", packet[i]);
        }
        printf("%s\n", RESET_COLOR);
        printf("value = %s%ld%s\n", KMAG, t->BaseSwapPx.mantissa, RESET_COLOR);
        printf("\n");
#endif

#ifdef DEBUG3
        getchar();
#endif
    }

    //nopmap_decimal_nullable_noop

//nopmap_int32_nullable_noop RepoToPx
#ifdef DEBUG2
    int t_RepoToPxexponenta_start = *offset;
#endif

    //>>> RepoToPx
    if (packet[*offset] == 0x80)
    {
        (*offset)++;
        t->RepoToPx.exponenta.is_null = 1;
    }
    else
    {
        t->RepoToPx.exponenta.value = 0 - (packet[*offset] & 0x40);
        t->RepoToPx.exponenta.is_null = 0;
        while (!((packet[*offset] & 0x80)))
        {
            (t->RepoToPx.exponenta.value) |= packet[(*offset)++];
            (t->RepoToPx.exponenta.value) <<= 7;
        }
        (t->RepoToPx.exponenta.value) |= (packet[(*offset)++] & 0x7f);
        if (t->RepoToPx.exponenta.value > 0)
        {
            (t->RepoToPx.exponenta.value)--;
        }
    }
    //<<<

#ifdef DEBUG

    if (t->RepoToPx.exponenta.is_null)
    {
        printf("t->RepoToPx.exponenta = %sNULL%s\n", KMAG, RESET_COLOR);
    }
    else
    {
        printf("t->RepoToPx.exponenta = %s%d%s\n", KMAG, t->RepoToPx.exponenta.value, RESET_COLOR);
    }

#endif

#ifdef DEBUG1
    printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
    printf("name = %sRepoToPx%s\n", KRED, RESET_COLOR);
    printf("type = %snopmap_int32_nullable_noop\n%s", KBLU, RESET_COLOR);
    printf("byte_representation: ");
    printf("%s", COLOR_BYTES);
    for (int i = t_RepoToPxexponenta_start; i < *offset; i++)
    {
        printf("%02x ", packet[i]);
    }
    printf("%s\n", RESET_COLOR);

    if (t->RepoToPx.exponenta.is_null)
    {
        printf("t->RepoToPx.exponenta = %sNULL%s\n", KMAG, RESET_COLOR);
    }
    else
    {
        printf("t->RepoToPx.exponenta = %s%d%s\n", KMAG, t->RepoToPx.exponenta.value, RESET_COLOR);
    }

    printf("\n");
#endif

#ifdef DEBUG3
    getchar();
#endif

    if (!t->RepoToPx.exponenta.is_null)
    {
        //calc mantissa
        //nopmap_int64_nonullable_noop RepoToPx
#ifdef DEBUG2
        int t_RepoToPxmantissa_start = *offset;
#endif

        //>>> RepoToPx
        t->RepoToPx.mantissa = 0 - (packet[*offset] & 0x40);
        while (!((packet[*offset] & 0x80)))
        {
            t->RepoToPx.mantissa |= packet[(*offset)++];
            t->RepoToPx.mantissa <<= 7;
        }
        t->RepoToPx.mantissa |= (packet[(*offset)++] & 0x7f);
        //<<<

#ifdef DEBUG
        printf("t->RepoToPx.mantissa = %ld\n", t->RepoToPx.mantissa);
#endif

#ifdef DEBUG1
        printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
        printf("name = %sRepoToPx%s\n", KRED, RESET_COLOR);
        printf("type = %snopmap_int64_nonullable_noop\n%s", KBLU, RESET_COLOR);
        printf("byte_representation: ");
        printf("%s", COLOR_BYTES);
        for (int i = t_RepoToPxmantissa_start; i < *offset; i++)
        {
            printf("%02x ", packet[i]);
        }
        printf("%s\n", RESET_COLOR);
        printf("value = %s%ld%s\n", KMAG, t->RepoToPx.mantissa, RESET_COLOR);
        printf("\n");
#endif

#ifdef DEBUG3
        getchar();
#endif
    }

    //nopmap_decimal_nullable_noop

//nopmap_int32_nullable_noop BuyBackPx
#ifdef DEBUG2
    int t_BuyBackPxexponenta_start = *offset;
#endif

    //>>> BuyBackPx
    if (packet[*offset] == 0x80)
    {
        (*offset)++;
        t->BuyBackPx.exponenta.is_null = 1;
    }
    else
    {
        t->BuyBackPx.exponenta.value = 0 - (packet[*offset] & 0x40);
        t->BuyBackPx.exponenta.is_null = 0;
        while (!((packet[*offset] & 0x80)))
        {
            (t->BuyBackPx.exponenta.value) |= packet[(*offset)++];
            (t->BuyBackPx.exponenta.value) <<= 7;
        }
        (t->BuyBackPx.exponenta.value) |= (packet[(*offset)++] & 0x7f);
        if (t->BuyBackPx.exponenta.value > 0)
        {
            (t->BuyBackPx.exponenta.value)--;
        }
    }
    //<<<

#ifdef DEBUG

    if (t->BuyBackPx.exponenta.is_null)
    {
        printf("t->BuyBackPx.exponenta = %sNULL%s\n", KMAG, RESET_COLOR);
    }
    else
    {
        printf("t->BuyBackPx.exponenta = %s%d%s\n", KMAG, t->BuyBackPx.exponenta.value, RESET_COLOR);
    }

#endif

#ifdef DEBUG1
    printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
    printf("name = %sBuyBackPx%s\n", KRED, RESET_COLOR);
    printf("type = %snopmap_int32_nullable_noop\n%s", KBLU, RESET_COLOR);
    printf("byte_representation: ");
    printf("%s", COLOR_BYTES);
    for (int i = t_BuyBackPxexponenta_start; i < *offset; i++)
    {
        printf("%02x ", packet[i]);
    }
    printf("%s\n", RESET_COLOR);

    if (t->BuyBackPx.exponenta.is_null)
    {
        printf("t->BuyBackPx.exponenta = %sNULL%s\n", KMAG, RESET_COLOR);
    }
    else
    {
        printf("t->BuyBackPx.exponenta = %s%d%s\n", KMAG, t->BuyBackPx.exponenta.value, RESET_COLOR);
    }

    printf("\n");
#endif

#ifdef DEBUG3
    getchar();
#endif

    if (!t->BuyBackPx.exponenta.is_null)
    {
        //calc mantissa
        //nopmap_int64_nonullable_noop BuyBackPx
#ifdef DEBUG2
        int t_BuyBackPxmantissa_start = *offset;
#endif

        //>>> BuyBackPx
        t->BuyBackPx.mantissa = 0 - (packet[*offset] & 0x40);
        while (!((packet[*offset] & 0x80)))
        {
            t->BuyBackPx.mantissa |= packet[(*offset)++];
            t->BuyBackPx.mantissa <<= 7;
        }
        t->BuyBackPx.mantissa |= (packet[(*offset)++] & 0x7f);
        //<<<

#ifdef DEBUG
        printf("t->BuyBackPx.mantissa = %ld\n", t->BuyBackPx.mantissa);
#endif

#ifdef DEBUG1
        printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
        printf("name = %sBuyBackPx%s\n", KRED, RESET_COLOR);
        printf("type = %snopmap_int64_nonullable_noop\n%s", KBLU, RESET_COLOR);
        printf("byte_representation: ");
        printf("%s", COLOR_BYTES);
        for (int i = t_BuyBackPxmantissa_start; i < *offset; i++)
        {
            printf("%02x ", packet[i]);
        }
        printf("%s\n", RESET_COLOR);
        printf("value = %s%ld%s\n", KMAG, t->BuyBackPx.mantissa, RESET_COLOR);
        printf("\n");
#endif

#ifdef DEBUG3
        getchar();
#endif
    }

//nopmap_uint32_nullable_noop BuyBackDate
#ifdef DEBUG2
    int t_BuyBackDate_start = *offset;
#endif

    //>>> BuyBackDate
    if (packet[*offset] == 0x80)
    {
        t->BuyBackDate.is_null = 1;
        t->BuyBackDate.value = 0;
        (*offset)++;
    }
    else
    {
        t->BuyBackDate.value = 0;
        t->BuyBackDate.is_null = 0;
        while (!((packet[*offset] & 0x80)))
        {
            (t->BuyBackDate.value) |= packet[(*offset)++];
            (t->BuyBackDate.value) <<= 7;
        }
        (t->BuyBackDate.value) |= (packet[(*offset)++] & 0x7f);
        (t->BuyBackDate.value)--;
    }
    //<<<

#ifdef DEBUG

    if (t->BuyBackDate.is_null)
    {
        printf("t->BuyBackDate = %sNULL%s\n", KMAG, RESET_COLOR);
    }
    else
    {
        printf("t->BuyBackDate = %s%u%s\n", KMAG, t->BuyBackDate.value, RESET_COLOR);
    }

#endif

#ifdef DEBUG1
    printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
    printf("name = %sBuyBackDate%s\n", KRED, RESET_COLOR);
    printf("type = %snopmap_uint32_nullable_noop\n%s", KBLU, RESET_COLOR);
    printf("byte_representation: ");
    printf("%s", COLOR_BYTES);
    for (int i = t_BuyBackDate_start; i < *offset; i++)
    {
        printf("%02x ", packet[i]);
    }
    printf("%s\n", RESET_COLOR);

    if (t->BuyBackDate.is_null)
    {
        printf("t->BuyBackDate = %sNULL%s\n", KMAG, RESET_COLOR);
    }
    else
    {
        printf("t->BuyBackDate = %s%u%s\n", KMAG, t->BuyBackDate.value, RESET_COLOR);
    }

    printf("\n");
#endif

#ifdef DEBUG3
    getchar();
#endif

    //nopmap_decimal_nullable_noop

//nopmap_int32_nullable_noop NoSharesIssued
#ifdef DEBUG2
    int t_NoSharesIssuedexponenta_start = *offset;
#endif

    //>>> NoSharesIssued
    if (packet[*offset] == 0x80)
    {
        (*offset)++;
        t->NoSharesIssued.exponenta.is_null = 1;
    }
    else
    {
        t->NoSharesIssued.exponenta.value = 0 - (packet[*offset] & 0x40);
        t->NoSharesIssued.exponenta.is_null = 0;
        while (!((packet[*offset] & 0x80)))
        {
            (t->NoSharesIssued.exponenta.value) |= packet[(*offset)++];
            (t->NoSharesIssued.exponenta.value) <<= 7;
        }
        (t->NoSharesIssued.exponenta.value) |= (packet[(*offset)++] & 0x7f);
        if (t->NoSharesIssued.exponenta.value > 0)
        {
            (t->NoSharesIssued.exponenta.value)--;
        }
    }
    //<<<

#ifdef DEBUG

    if (t->NoSharesIssued.exponenta.is_null)
    {
        printf("t->NoSharesIssued.exponenta = %sNULL%s\n", KMAG, RESET_COLOR);
    }
    else
    {
        printf("t->NoSharesIssued.exponenta = %s%d%s\n", KMAG, t->NoSharesIssued.exponenta.value, RESET_COLOR);
    }

#endif

#ifdef DEBUG1
    printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
    printf("name = %sNoSharesIssued%s\n", KRED, RESET_COLOR);
    printf("type = %snopmap_int32_nullable_noop\n%s", KBLU, RESET_COLOR);
    printf("byte_representation: ");
    printf("%s", COLOR_BYTES);
    for (int i = t_NoSharesIssuedexponenta_start; i < *offset; i++)
    {
        printf("%02x ", packet[i]);
    }
    printf("%s\n", RESET_COLOR);

    if (t->NoSharesIssued.exponenta.is_null)
    {
        printf("t->NoSharesIssued.exponenta = %sNULL%s\n", KMAG, RESET_COLOR);
    }
    else
    {
        printf("t->NoSharesIssued.exponenta = %s%d%s\n", KMAG, t->NoSharesIssued.exponenta.value, RESET_COLOR);
    }

    printf("\n");
#endif

#ifdef DEBUG3
    getchar();
#endif

    if (!t->NoSharesIssued.exponenta.is_null)
    {
        //calc mantissa
        //nopmap_int64_nonullable_noop NoSharesIssued
#ifdef DEBUG2
        int t_NoSharesIssuedmantissa_start = *offset;
#endif

        //>>> NoSharesIssued
        t->NoSharesIssued.mantissa = 0 - (packet[*offset] & 0x40);
        while (!((packet[*offset] & 0x80)))
        {
            t->NoSharesIssued.mantissa |= packet[(*offset)++];
            t->NoSharesIssued.mantissa <<= 7;
        }
        t->NoSharesIssued.mantissa |= (packet[(*offset)++] & 0x7f);
        //<<<

#ifdef DEBUG
        printf("t->NoSharesIssued.mantissa = %ld\n", t->NoSharesIssued.mantissa);
#endif

#ifdef DEBUG1
        printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
        printf("name = %sNoSharesIssued%s\n", KRED, RESET_COLOR);
        printf("type = %snopmap_int64_nonullable_noop\n%s", KBLU, RESET_COLOR);
        printf("byte_representation: ");
        printf("%s", COLOR_BYTES);
        for (int i = t_NoSharesIssuedmantissa_start; i < *offset; i++)
        {
            printf("%02x ", packet[i]);
        }
        printf("%s\n", RESET_COLOR);
        printf("value = %s%ld%s\n", KMAG, t->NoSharesIssued.mantissa, RESET_COLOR);
        printf("\n");
#endif

#ifdef DEBUG3
        getchar();
#endif
    }

    //nopmap_decimal_nullable_noop

//nopmap_int32_nullable_noop HighLimit
#ifdef DEBUG2
    int t_HighLimitexponenta_start = *offset;
#endif

    //>>> HighLimit
    if (packet[*offset] == 0x80)
    {
        (*offset)++;
        t->HighLimit.exponenta.is_null = 1;
    }
    else
    {
        t->HighLimit.exponenta.value = 0 - (packet[*offset] & 0x40);
        t->HighLimit.exponenta.is_null = 0;
        while (!((packet[*offset] & 0x80)))
        {
            (t->HighLimit.exponenta.value) |= packet[(*offset)++];
            (t->HighLimit.exponenta.value) <<= 7;
        }
        (t->HighLimit.exponenta.value) |= (packet[(*offset)++] & 0x7f);
        if (t->HighLimit.exponenta.value > 0)
        {
            (t->HighLimit.exponenta.value)--;
        }
    }
    //<<<

#ifdef DEBUG

    if (t->HighLimit.exponenta.is_null)
    {
        printf("t->HighLimit.exponenta = %sNULL%s\n", KMAG, RESET_COLOR);
    }
    else
    {
        printf("t->HighLimit.exponenta = %s%d%s\n", KMAG, t->HighLimit.exponenta.value, RESET_COLOR);
    }

#endif

#ifdef DEBUG1
    printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
    printf("name = %sHighLimit%s\n", KRED, RESET_COLOR);
    printf("type = %snopmap_int32_nullable_noop\n%s", KBLU, RESET_COLOR);
    printf("byte_representation: ");
    printf("%s", COLOR_BYTES);
    for (int i = t_HighLimitexponenta_start; i < *offset; i++)
    {
        printf("%02x ", packet[i]);
    }
    printf("%s\n", RESET_COLOR);

    if (t->HighLimit.exponenta.is_null)
    {
        printf("t->HighLimit.exponenta = %sNULL%s\n", KMAG, RESET_COLOR);
    }
    else
    {
        printf("t->HighLimit.exponenta = %s%d%s\n", KMAG, t->HighLimit.exponenta.value, RESET_COLOR);
    }

    printf("\n");
#endif

#ifdef DEBUG3
    getchar();
#endif

    if (!t->HighLimit.exponenta.is_null)
    {
        //calc mantissa
        //nopmap_int64_nonullable_noop HighLimit
#ifdef DEBUG2
        int t_HighLimitmantissa_start = *offset;
#endif

        //>>> HighLimit
        t->HighLimit.mantissa = 0 - (packet[*offset] & 0x40);
        while (!((packet[*offset] & 0x80)))
        {
            t->HighLimit.mantissa |= packet[(*offset)++];
            t->HighLimit.mantissa <<= 7;
        }
        t->HighLimit.mantissa |= (packet[(*offset)++] & 0x7f);
        //<<<

#ifdef DEBUG
        printf("t->HighLimit.mantissa = %ld\n", t->HighLimit.mantissa);
#endif

#ifdef DEBUG1
        printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
        printf("name = %sHighLimit%s\n", KRED, RESET_COLOR);
        printf("type = %snopmap_int64_nonullable_noop\n%s", KBLU, RESET_COLOR);
        printf("byte_representation: ");
        printf("%s", COLOR_BYTES);
        for (int i = t_HighLimitmantissa_start; i < *offset; i++)
        {
            printf("%02x ", packet[i]);
        }
        printf("%s\n", RESET_COLOR);
        printf("value = %s%ld%s\n", KMAG, t->HighLimit.mantissa, RESET_COLOR);
        printf("\n");
#endif

#ifdef DEBUG3
        getchar();
#endif
    }

    //nopmap_decimal_nullable_noop

//nopmap_int32_nullable_noop LowLimit
#ifdef DEBUG2
    int t_LowLimitexponenta_start = *offset;
#endif

    //>>> LowLimit
    if (packet[*offset] == 0x80)
    {
        (*offset)++;
        t->LowLimit.exponenta.is_null = 1;
    }
    else
    {
        t->LowLimit.exponenta.value = 0 - (packet[*offset] & 0x40);
        t->LowLimit.exponenta.is_null = 0;
        while (!((packet[*offset] & 0x80)))
        {
            (t->LowLimit.exponenta.value) |= packet[(*offset)++];
            (t->LowLimit.exponenta.value) <<= 7;
        }
        (t->LowLimit.exponenta.value) |= (packet[(*offset)++] & 0x7f);
        if (t->LowLimit.exponenta.value > 0)
        {
            (t->LowLimit.exponenta.value)--;
        }
    }
    //<<<

#ifdef DEBUG

    if (t->LowLimit.exponenta.is_null)
    {
        printf("t->LowLimit.exponenta = %sNULL%s\n", KMAG, RESET_COLOR);
    }
    else
    {
        printf("t->LowLimit.exponenta = %s%d%s\n", KMAG, t->LowLimit.exponenta.value, RESET_COLOR);
    }

#endif

#ifdef DEBUG1
    printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
    printf("name = %sLowLimit%s\n", KRED, RESET_COLOR);
    printf("type = %snopmap_int32_nullable_noop\n%s", KBLU, RESET_COLOR);
    printf("byte_representation: ");
    printf("%s", COLOR_BYTES);
    for (int i = t_LowLimitexponenta_start; i < *offset; i++)
    {
        printf("%02x ", packet[i]);
    }
    printf("%s\n", RESET_COLOR);

    if (t->LowLimit.exponenta.is_null)
    {
        printf("t->LowLimit.exponenta = %sNULL%s\n", KMAG, RESET_COLOR);
    }
    else
    {
        printf("t->LowLimit.exponenta = %s%d%s\n", KMAG, t->LowLimit.exponenta.value, RESET_COLOR);
    }

    printf("\n");
#endif

#ifdef DEBUG3
    getchar();
#endif

    if (!t->LowLimit.exponenta.is_null)
    {
        //calc mantissa
        //nopmap_int64_nonullable_noop LowLimit
#ifdef DEBUG2
        int t_LowLimitmantissa_start = *offset;
#endif

        //>>> LowLimit
        t->LowLimit.mantissa = 0 - (packet[*offset] & 0x40);
        while (!((packet[*offset] & 0x80)))
        {
            t->LowLimit.mantissa |= packet[(*offset)++];
            t->LowLimit.mantissa <<= 7;
        }
        t->LowLimit.mantissa |= (packet[(*offset)++] & 0x7f);
        //<<<

#ifdef DEBUG
        printf("t->LowLimit.mantissa = %ld\n", t->LowLimit.mantissa);
#endif

#ifdef DEBUG1
        printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
        printf("name = %sLowLimit%s\n", KRED, RESET_COLOR);
        printf("type = %snopmap_int64_nonullable_noop\n%s", KBLU, RESET_COLOR);
        printf("byte_representation: ");
        printf("%s", COLOR_BYTES);
        for (int i = t_LowLimitmantissa_start; i < *offset; i++)
        {
            printf("%02x ", packet[i]);
        }
        printf("%s\n", RESET_COLOR);
        printf("value = %s%ld%s\n", KMAG, t->LowLimit.mantissa, RESET_COLOR);
        printf("\n");
#endif

#ifdef DEBUG3
        getchar();
#endif
    }

//nopmap_int32_nullable_noop NumOfDaysToMaturity
#ifdef DEBUG2
    int t_NumOfDaysToMaturity_start = *offset;
#endif

    //>>> NumOfDaysToMaturity
    if (packet[*offset] == 0x80)
    {
        (*offset)++;
        t->NumOfDaysToMaturity.is_null = 1;
    }
    else
    {
        t->NumOfDaysToMaturity.value = 0 - (packet[*offset] & 0x40);
        t->NumOfDaysToMaturity.is_null = 0;
        while (!((packet[*offset] & 0x80)))
        {
            (t->NumOfDaysToMaturity.value) |= packet[(*offset)++];
            (t->NumOfDaysToMaturity.value) <<= 7;
        }
        (t->NumOfDaysToMaturity.value) |= (packet[(*offset)++] & 0x7f);
        if (t->NumOfDaysToMaturity.value > 0)
        {
            (t->NumOfDaysToMaturity.value)--;
        }
    }
    //<<<

#ifdef DEBUG

    if (t->NumOfDaysToMaturity.is_null)
    {
        printf("t->NumOfDaysToMaturity = %sNULL%s\n", KMAG, RESET_COLOR);
    }
    else
    {
        printf("t->NumOfDaysToMaturity = %s%d%s\n", KMAG, t->NumOfDaysToMaturity.value, RESET_COLOR);
    }

#endif

#ifdef DEBUG1
    printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
    printf("name = %sNumOfDaysToMaturity%s\n", KRED, RESET_COLOR);
    printf("type = %snopmap_int32_nullable_noop\n%s", KBLU, RESET_COLOR);
    printf("byte_representation: ");
    printf("%s", COLOR_BYTES);
    for (int i = t_NumOfDaysToMaturity_start; i < *offset; i++)
    {
        printf("%02x ", packet[i]);
    }
    printf("%s\n", RESET_COLOR);

    if (t->NumOfDaysToMaturity.is_null)
    {
        printf("t->NumOfDaysToMaturity = %sNULL%s\n", KMAG, RESET_COLOR);
    }
    else
    {
        printf("t->NumOfDaysToMaturity = %s%d%s\n", KMAG, t->NumOfDaysToMaturity.value, RESET_COLOR);
    }

    printf("\n");
#endif

#ifdef DEBUG3
    getchar();
#endif

    return 0;
}
int moex_eq_parse_template_f(unsigned char *packet, int *offset, unsigned char *pmap, struct moex_eq__f *t)
{
    t->pmap = pmap;

    //nopmap_string_nonullable_constant MessageType
    //strcpy(t->MessageType, "f");

    //nopmap_string_nonullable_constant ApplVerID
    //strcpy(t->ApplVerID, "9");

    //nopmap_string_nonullable_constant BeginString
    //strcpy(t->BeginString, "FIXT.1.1");

    //nopmap_string_nonullable_constant SenderCompID
    //strcpy(t->SenderCompID, "MOEX");

    //nopmap_uint32_nonullable_noop MsgSeqNum
#ifdef DEBUG2
    int t_MsgSeqNum_start = *offset;
#endif

    //>>> MsgSeqNum
    t->MsgSeqNum = 0;
    while (!((packet[*offset] & 0x80)))
    {
        t->MsgSeqNum |= packet[(*offset)++];
        t->MsgSeqNum <<= 7;
    }
    t->MsgSeqNum |= (packet[(*offset)++] & 0x7f);
    //<<<

#ifdef DEBUG
    printf("t->MsgSeqNum = %u\n", t->MsgSeqNum);
#endif

#ifdef DEBUG1
    printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
    printf("name = %sMsgSeqNum%s\n", KRED, RESET_COLOR);
    printf("type = %snopmap_uint32_nonullable_noop\n%s", KBLU, RESET_COLOR);
    printf("byte_representation: ");
    printf("%s", COLOR_BYTES);
    for (int i = t_MsgSeqNum_start; i < *offset; i++)
    {
        printf("%02x ", packet[i]);
    }
    printf("%s\n", RESET_COLOR);
    printf("value = %s%u%s\n", KMAG, t->MsgSeqNum, RESET_COLOR);
    printf("\n");
#endif

#ifdef DEBUG3
    getchar();
#endif

    //nopmap_uint64_nonullable_noop SendingTime
#ifdef DEBUG2
    int t_SendingTime_start = *offset;
#endif

    //>>> SendingTime
    t->SendingTime = 0;
    while (!((packet[*offset] & 0x80)))
    {
        (t->SendingTime) |= packet[(*offset)++];
        (t->SendingTime) <<= 7;
    }
    (t->SendingTime) |= (packet[(*offset)++] & 0x7f);
    //<<<

#ifdef DEBUG
    printf("t->SendingTime = %lu\n", t->SendingTime);
#endif

#ifdef DEBUG1
    printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
    printf("name = %sSendingTime%s\n", KRED, RESET_COLOR);
    printf("type = %snopmap_uint64_nonullable_noop\n%s", KBLU, RESET_COLOR);
    printf("byte_representation: ");
    printf("%s", COLOR_BYTES);
    for (int i = t_SendingTime_start; i < *offset; i++)
    {
        printf("%02x ", packet[i]);
    }
    printf("%s\n", RESET_COLOR);
    printf("value = %s%lu%s\n", KMAG, t->SendingTime, RESET_COLOR);
    printf("\n");
#endif

#ifdef DEBUG3
    getchar();
#endif

    //nopmap_string_nonullable_noop Symbol
#ifdef DEBUG2
    int t_Symbol_start = *offset;
#endif

    //>>> Symbol
    t->Symbol.start = packet + *offset;
    if (packet[*offset] == 0x80)
    {
        (*offset)++;
        t->Symbol.len = 0;
        t->Symbol.is_null = 1;
        //printf("t->Symbol = EMPTY \n");
    }
    else
    {
        t->Symbol.len = 0;
        while (!((packet[(*offset)] & 0x80)))
        {
            t->Symbol.len++;
            (*offset)++;
        }
        packet[*offset] = packet[*offset] & 0x7F;
        (*offset)++;
        t->Symbol.len++;
    }
    //<<<

#ifdef DEBUG

    {
        unsigned char fake[128];
        strncpy(fake, t->Symbol.start, t->Symbol.len);
        fake[t->Symbol.len] = '\0';
        printf("t->Symbol = %s%s%s\n", KMAG, fake, RESET_COLOR);
    }

#endif

#ifdef DEBUG1
    printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
    printf("name = %sSymbol%s\n", KRED, RESET_COLOR);
    printf("type = %s nopmap_string_nonullable_noop\n%s", KBLU, RESET_COLOR);
    printf("byte_representation: ");
    printf("%s", COLOR_BYTES);
    for (int i = t_Symbol_start; i < *offset; i++)
    {
        printf("%02x ", packet[i]);
    }
    printf("%s\n", RESET_COLOR);

    {
        unsigned char fake[128];
        strncpy(fake, t->Symbol.start, t->Symbol.len);
        fake[t->Symbol.len] = '\0';
        printf("t->Symbol = %s%s%s\n", KMAG, fake, RESET_COLOR);
    }

    printf("\n");
#endif

#ifdef DEBUG3
    getchar();
#endif

    //nopmap_string_nullable_noop TradingSessionID
#ifdef DEBUG2
    int t_TradingSessionID_start = *offset;
#endif

    //>>> TradingSessionID
    t->TradingSessionID.start = packet + *offset;
    if (packet[*offset] == 0x80)
    {
        (*offset)++;
        t->TradingSessionID.len = 0;
        t->TradingSessionID.is_null = 1;
        //printf("t->TradingSessionID = EMPTY \n");
    }
    else
    {
        t->TradingSessionID.len = 0;
        t->TradingSessionID.is_null = 0;
        while (!((packet[(*offset)] & 0x80)))
        {
            t->TradingSessionID.len++;
            (*offset)++;
        }
        packet[*offset] = packet[*offset] & 0x7F;
        (*offset)++;
        t->TradingSessionID.len++;
    }
    //<<<

#ifdef DEBUG

    if (1)
    {

        if (t->TradingSessionID.is_null)
        {
            printf("t->TradingSessionID = %sNULL%s\n", KMAG, RESET_COLOR);
        }
        else
        {
            unsigned char fake[128];
            strncpy(fake, t->TradingSessionID.start, t->TradingSessionID.len);
            fake[t->TradingSessionID.len] = '\0';
            printf("t->TradingSessionID = %s%s%s\n", KMAG, fake, RESET_COLOR);
        }
    }

#endif

#ifdef DEBUG1
    printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
    printf("name = %sTradingSessionID%s\n", KRED, RESET_COLOR);
    printf("type = %s nopmap_string_nullable_noop\n%s", KBLU, RESET_COLOR);
    printf("byte_representation: ");
    printf("%s", COLOR_BYTES);
    for (int i = t_TradingSessionID_start; i < *offset; i++)
    {
        printf("%02x ", packet[i]);
    }
    printf("%s\n", RESET_COLOR);

    if (1)
    {

        if (t->TradingSessionID.is_null)
        {
            printf("t->TradingSessionID = %sNULL%s\n", KMAG, RESET_COLOR);
        }
        else
        {
            unsigned char fake[128];
            strncpy(fake, t->TradingSessionID.start, t->TradingSessionID.len);
            fake[t->TradingSessionID.len] = '\0';
            printf("t->TradingSessionID = %s%s%s\n", KMAG, fake, RESET_COLOR);
        }
    }

    printf("\n");
#endif

#ifdef DEBUG3
    getchar();
#endif

    //nopmap_string_nullable_noop TradingSessionSubID
#ifdef DEBUG2
    int t_TradingSessionSubID_start = *offset;
#endif

    //>>> TradingSessionSubID
    t->TradingSessionSubID.start = packet + *offset;
    if (packet[*offset] == 0x80)
    {
        (*offset)++;
        t->TradingSessionSubID.len = 0;
        t->TradingSessionSubID.is_null = 1;
        //printf("t->TradingSessionSubID = EMPTY \n");
    }
    else
    {
        t->TradingSessionSubID.len = 0;
        t->TradingSessionSubID.is_null = 0;
        while (!((packet[(*offset)] & 0x80)))
        {
            t->TradingSessionSubID.len++;
            (*offset)++;
        }
        packet[*offset] = packet[*offset] & 0x7F;
        (*offset)++;
        t->TradingSessionSubID.len++;
    }
    //<<<

#ifdef DEBUG

    if (1)
    {

        if (t->TradingSessionSubID.is_null)
        {
            printf("t->TradingSessionSubID = %sNULL%s\n", KMAG, RESET_COLOR);
        }
        else
        {
            unsigned char fake[128];
            strncpy(fake, t->TradingSessionSubID.start, t->TradingSessionSubID.len);
            fake[t->TradingSessionSubID.len] = '\0';
            printf("t->TradingSessionSubID = %s%s%s\n", KMAG, fake, RESET_COLOR);
        }
    }

#endif

#ifdef DEBUG1
    printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
    printf("name = %sTradingSessionSubID%s\n", KRED, RESET_COLOR);
    printf("type = %s nopmap_string_nullable_noop\n%s", KBLU, RESET_COLOR);
    printf("byte_representation: ");
    printf("%s", COLOR_BYTES);
    for (int i = t_TradingSessionSubID_start; i < *offset; i++)
    {
        printf("%02x ", packet[i]);
    }
    printf("%s\n", RESET_COLOR);

    if (1)
    {

        if (t->TradingSessionSubID.is_null)
        {
            printf("t->TradingSessionSubID = %sNULL%s\n", KMAG, RESET_COLOR);
        }
        else
        {
            unsigned char fake[128];
            strncpy(fake, t->TradingSessionSubID.start, t->TradingSessionSubID.len);
            fake[t->TradingSessionSubID.len] = '\0';
            printf("t->TradingSessionSubID = %s%s%s\n", KMAG, fake, RESET_COLOR);
        }
    }

    printf("\n");
#endif

#ifdef DEBUG3
    getchar();
#endif

//nopmap_int32_nullable_noop SecurityTradingStatus
#ifdef DEBUG2
    int t_SecurityTradingStatus_start = *offset;
#endif

    //>>> SecurityTradingStatus
    if (packet[*offset] == 0x80)
    {
        (*offset)++;
        t->SecurityTradingStatus.is_null = 1;
    }
    else
    {
        t->SecurityTradingStatus.value = 0 - (packet[*offset] & 0x40);
        t->SecurityTradingStatus.is_null = 0;
        while (!((packet[*offset] & 0x80)))
        {
            (t->SecurityTradingStatus.value) |= packet[(*offset)++];
            (t->SecurityTradingStatus.value) <<= 7;
        }
        (t->SecurityTradingStatus.value) |= (packet[(*offset)++] & 0x7f);
        if (t->SecurityTradingStatus.value > 0)
        {
            (t->SecurityTradingStatus.value)--;
        }
    }
    //<<<

#ifdef DEBUG

    if (t->SecurityTradingStatus.is_null)
    {
        printf("t->SecurityTradingStatus = %sNULL%s\n", KMAG, RESET_COLOR);
    }
    else
    {
        printf("t->SecurityTradingStatus = %s%d%s\n", KMAG, t->SecurityTradingStatus.value, RESET_COLOR);
    }

#endif

#ifdef DEBUG1
    printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
    printf("name = %sSecurityTradingStatus%s\n", KRED, RESET_COLOR);
    printf("type = %snopmap_int32_nullable_noop\n%s", KBLU, RESET_COLOR);
    printf("byte_representation: ");
    printf("%s", COLOR_BYTES);
    for (int i = t_SecurityTradingStatus_start; i < *offset; i++)
    {
        printf("%02x ", packet[i]);
    }
    printf("%s\n", RESET_COLOR);

    if (t->SecurityTradingStatus.is_null)
    {
        printf("t->SecurityTradingStatus = %sNULL%s\n", KMAG, RESET_COLOR);
    }
    else
    {
        printf("t->SecurityTradingStatus = %s%d%s\n", KMAG, t->SecurityTradingStatus.value, RESET_COLOR);
    }

    printf("\n");
#endif

#ifdef DEBUG3
    getchar();
#endif

//nopmap_uint32_nullable_noop AuctionIndicator
#ifdef DEBUG2
    int t_AuctionIndicator_start = *offset;
#endif

    //>>> AuctionIndicator
    if (packet[*offset] == 0x80)
    {
        t->AuctionIndicator.is_null = 1;
        t->AuctionIndicator.value = 0;
        (*offset)++;
    }
    else
    {
        t->AuctionIndicator.value = 0;
        t->AuctionIndicator.is_null = 0;
        while (!((packet[*offset] & 0x80)))
        {
            (t->AuctionIndicator.value) |= packet[(*offset)++];
            (t->AuctionIndicator.value) <<= 7;
        }
        (t->AuctionIndicator.value) |= (packet[(*offset)++] & 0x7f);
        (t->AuctionIndicator.value)--;
    }
    //<<<

#ifdef DEBUG

    if (t->AuctionIndicator.is_null)
    {
        printf("t->AuctionIndicator = %sNULL%s\n", KMAG, RESET_COLOR);
    }
    else
    {
        printf("t->AuctionIndicator = %s%u%s\n", KMAG, t->AuctionIndicator.value, RESET_COLOR);
    }

#endif

#ifdef DEBUG1
    printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
    printf("name = %sAuctionIndicator%s\n", KRED, RESET_COLOR);
    printf("type = %snopmap_uint32_nullable_noop\n%s", KBLU, RESET_COLOR);
    printf("byte_representation: ");
    printf("%s", COLOR_BYTES);
    for (int i = t_AuctionIndicator_start; i < *offset; i++)
    {
        printf("%02x ", packet[i]);
    }
    printf("%s\n", RESET_COLOR);

    if (t->AuctionIndicator.is_null)
    {
        printf("t->AuctionIndicator = %sNULL%s\n", KMAG, RESET_COLOR);
    }
    else
    {
        printf("t->AuctionIndicator = %s%u%s\n", KMAG, t->AuctionIndicator.value, RESET_COLOR);
    }

    printf("\n");
#endif

#ifdef DEBUG3
    getchar();
#endif

    return 0;
}
int moex_eq_parse_template_h(unsigned char *packet, int *offset, unsigned char *pmap, struct moex_eq__h *t)
{
    t->pmap = pmap;

    //nopmap_string_nonullable_constant MessageType
    //strcpy(t->MessageType, "h");

    //nopmap_string_nonullable_constant ApplVerID
    //strcpy(t->ApplVerID, "9");

    //nopmap_string_nonullable_constant BeginString
    //strcpy(t->BeginString, "FIXT.1.1");

    //nopmap_string_nonullable_constant SenderCompID
    //strcpy(t->SenderCompID, "MOEX");

    //nopmap_uint32_nonullable_noop MsgSeqNum
#ifdef DEBUG2
    int t_MsgSeqNum_start = *offset;
#endif

    //>>> MsgSeqNum
    t->MsgSeqNum = 0;
    while (!((packet[*offset] & 0x80)))
    {
        t->MsgSeqNum |= packet[(*offset)++];
        t->MsgSeqNum <<= 7;
    }
    t->MsgSeqNum |= (packet[(*offset)++] & 0x7f);
    //<<<

#ifdef DEBUG
    printf("t->MsgSeqNum = %u\n", t->MsgSeqNum);
#endif

#ifdef DEBUG1
    printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
    printf("name = %sMsgSeqNum%s\n", KRED, RESET_COLOR);
    printf("type = %snopmap_uint32_nonullable_noop\n%s", KBLU, RESET_COLOR);
    printf("byte_representation: ");
    printf("%s", COLOR_BYTES);
    for (int i = t_MsgSeqNum_start; i < *offset; i++)
    {
        printf("%02x ", packet[i]);
    }
    printf("%s\n", RESET_COLOR);
    printf("value = %s%u%s\n", KMAG, t->MsgSeqNum, RESET_COLOR);
    printf("\n");
#endif

#ifdef DEBUG3
    getchar();
#endif

    //nopmap_uint64_nonullable_noop SendingTime
#ifdef DEBUG2
    int t_SendingTime_start = *offset;
#endif

    //>>> SendingTime
    t->SendingTime = 0;
    while (!((packet[*offset] & 0x80)))
    {
        (t->SendingTime) |= packet[(*offset)++];
        (t->SendingTime) <<= 7;
    }
    (t->SendingTime) |= (packet[(*offset)++] & 0x7f);
    //<<<

#ifdef DEBUG
    printf("t->SendingTime = %lu\n", t->SendingTime);
#endif

#ifdef DEBUG1
    printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
    printf("name = %sSendingTime%s\n", KRED, RESET_COLOR);
    printf("type = %snopmap_uint64_nonullable_noop\n%s", KBLU, RESET_COLOR);
    printf("byte_representation: ");
    printf("%s", COLOR_BYTES);
    for (int i = t_SendingTime_start; i < *offset; i++)
    {
        printf("%02x ", packet[i]);
    }
    printf("%s\n", RESET_COLOR);
    printf("value = %s%lu%s\n", KMAG, t->SendingTime, RESET_COLOR);
    printf("\n");
#endif

#ifdef DEBUG3
    getchar();
#endif

    //nopmap_int32_nonullable_noop TradSesStatus
#ifdef DEBUG2
    int t_TradSesStatus_start = *offset;
#endif

    //>>> TradSesStatus
    t->TradSesStatus = 0 - (packet[*offset] & 0x40);
    while (!((packet[*offset] & 0x80)))
    {
        t->TradSesStatus |= packet[(*offset)++];
        t->TradSesStatus <<= 7;
    }
    t->TradSesStatus |= (packet[(*offset)++] & 0x7f);
    //<<<

#ifdef DEBUG
    printf("t->TradSesStatus = %d\n", t->TradSesStatus);
#endif

#ifdef DEBUG1
    printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
    printf("name = %sTradSesStatus%s\n", KRED, RESET_COLOR);
    printf("type = %snopmap_int32_nonullable_noop\n%s", KBLU, RESET_COLOR);
    printf("byte_representation: ");
    printf("%s", COLOR_BYTES);
    for (int i = t_TradSesStatus_start; i < *offset; i++)
    {
        printf("%02x ", packet[i]);
    }
    printf("%s\n", RESET_COLOR);
    printf("value = %s%d%s\n", KMAG, t->TradSesStatus, RESET_COLOR);
    printf("\n");
#endif

#ifdef DEBUG3
    getchar();
#endif

    //nopmap_string_nullable_noop Text
#ifdef DEBUG2
    int t_Text_start = *offset;
#endif

    //>>> Text
    t->Text.start = packet + *offset;
    if (packet[*offset] == 0x80)
    {
        (*offset)++;
        t->Text.len = 0;
        t->Text.is_null = 1;
        //printf("t->Text = EMPTY \n");
    }
    else
    {
        t->Text.len = 0;
        t->Text.is_null = 0;
        while (!((packet[(*offset)] & 0x80)))
        {
            t->Text.len++;
            (*offset)++;
        }
        packet[*offset] = packet[*offset] & 0x7F;
        (*offset)++;
        t->Text.len++;
    }
    //<<<

#ifdef DEBUG

    if (1)
    {

        if (t->Text.is_null)
        {
            printf("t->Text = %sNULL%s\n", KMAG, RESET_COLOR);
        }
        else
        {
            unsigned char fake[128];
            strncpy(fake, t->Text.start, t->Text.len);
            fake[t->Text.len] = '\0';
            printf("t->Text = %s%s%s\n", KMAG, fake, RESET_COLOR);
        }
    }

#endif

#ifdef DEBUG1
    printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
    printf("name = %sText%s\n", KRED, RESET_COLOR);
    printf("type = %s nopmap_string_nullable_noop\n%s", KBLU, RESET_COLOR);
    printf("byte_representation: ");
    printf("%s", COLOR_BYTES);
    for (int i = t_Text_start; i < *offset; i++)
    {
        printf("%02x ", packet[i]);
    }
    printf("%s\n", RESET_COLOR);

    if (1)
    {

        if (t->Text.is_null)
        {
            printf("t->Text = %sNULL%s\n", KMAG, RESET_COLOR);
        }
        else
        {
            unsigned char fake[128];
            strncpy(fake, t->Text.start, t->Text.len);
            fake[t->Text.len] = '\0';
            printf("t->Text = %s%s%s\n", KMAG, fake, RESET_COLOR);
        }
    }

    printf("\n");
#endif

#ifdef DEBUG3
    getchar();
#endif

    //nopmap_string_nonullable_noop TradingSessionID
#ifdef DEBUG2
    int t_TradingSessionID_start = *offset;
#endif

    //>>> TradingSessionID
    t->TradingSessionID.start = packet + *offset;
    if (packet[*offset] == 0x80)
    {
        (*offset)++;
        t->TradingSessionID.len = 0;
        t->TradingSessionID.is_null = 1;
        //printf("t->TradingSessionID = EMPTY \n");
    }
    else
    {
        t->TradingSessionID.len = 0;
        while (!((packet[(*offset)] & 0x80)))
        {
            t->TradingSessionID.len++;
            (*offset)++;
        }
        packet[*offset] = packet[*offset] & 0x7F;
        (*offset)++;
        t->TradingSessionID.len++;
    }
    //<<<

#ifdef DEBUG

    {
        unsigned char fake[128];
        strncpy(fake, t->TradingSessionID.start, t->TradingSessionID.len);
        fake[t->TradingSessionID.len] = '\0';
        printf("t->TradingSessionID = %s%s%s\n", KMAG, fake, RESET_COLOR);
    }

#endif

#ifdef DEBUG1
    printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
    printf("name = %sTradingSessionID%s\n", KRED, RESET_COLOR);
    printf("type = %s nopmap_string_nonullable_noop\n%s", KBLU, RESET_COLOR);
    printf("byte_representation: ");
    printf("%s", COLOR_BYTES);
    for (int i = t_TradingSessionID_start; i < *offset; i++)
    {
        printf("%02x ", packet[i]);
    }
    printf("%s\n", RESET_COLOR);

    {
        unsigned char fake[128];
        strncpy(fake, t->TradingSessionID.start, t->TradingSessionID.len);
        fake[t->TradingSessionID.len] = '\0';
        printf("t->TradingSessionID = %s%s%s\n", KMAG, fake, RESET_COLOR);
    }

    printf("\n");
#endif

#ifdef DEBUG3
    getchar();
#endif

    return 0;
}
int moex_eq_parse_template_0(unsigned char *packet, int *offset, unsigned char *pmap, struct moex_eq__0 *t)
{
    t->pmap = pmap;

    //nopmap_string_nonullable_constant MessageType
    //strcpy(t->MessageType, "0");

    //nopmap_string_nonullable_constant BeginString
    //strcpy(t->BeginString, "FIXT.1.1");

    //nopmap_string_nonullable_constant SenderCompID
    //strcpy(t->SenderCompID, "MOEX");

    //nopmap_uint32_nonullable_noop MsgSeqNum
#ifdef DEBUG2
    int t_MsgSeqNum_start = *offset;
#endif

    //>>> MsgSeqNum
    t->MsgSeqNum = 0;
    while (!((packet[*offset] & 0x80)))
    {
        t->MsgSeqNum |= packet[(*offset)++];
        t->MsgSeqNum <<= 7;
    }
    t->MsgSeqNum |= (packet[(*offset)++] & 0x7f);
    //<<<

#ifdef DEBUG
    printf("t->MsgSeqNum = %u\n", t->MsgSeqNum);
#endif

#ifdef DEBUG1
    printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
    printf("name = %sMsgSeqNum%s\n", KRED, RESET_COLOR);
    printf("type = %snopmap_uint32_nonullable_noop\n%s", KBLU, RESET_COLOR);
    printf("byte_representation: ");
    printf("%s", COLOR_BYTES);
    for (int i = t_MsgSeqNum_start; i < *offset; i++)
    {
        printf("%02x ", packet[i]);
    }
    printf("%s\n", RESET_COLOR);
    printf("value = %s%u%s\n", KMAG, t->MsgSeqNum, RESET_COLOR);
    printf("\n");
#endif

#ifdef DEBUG3
    getchar();
#endif

    //nopmap_uint64_nonullable_noop SendingTime
#ifdef DEBUG2
    int t_SendingTime_start = *offset;
#endif

    //>>> SendingTime
    t->SendingTime = 0;
    while (!((packet[*offset] & 0x80)))
    {
        (t->SendingTime) |= packet[(*offset)++];
        (t->SendingTime) <<= 7;
    }
    (t->SendingTime) |= (packet[(*offset)++] & 0x7f);
    //<<<

#ifdef DEBUG
    printf("t->SendingTime = %lu\n", t->SendingTime);
#endif

#ifdef DEBUG1
    printf("offset = %d\n", *offset);
#endif

#ifdef DEBUG2
    printf("name = %sSendingTime%s\n", KRED, RESET_COLOR);
    printf("type = %snopmap_uint64_nonullable_noop\n%s", KBLU, RESET_COLOR);
    printf("byte_representation: ");
    printf("%s", COLOR_BYTES);
    for (int i = t_SendingTime_start; i < *offset; i++)
    {
        printf("%02x ", packet[i]);
    }
    printf("%s\n", RESET_COLOR);
    printf("value = %s%lu%s\n", KMAG, t->SendingTime, RESET_COLOR);
    printf("\n");
#endif

#ifdef DEBUG3
    getchar();
#endif

    return 0;
}

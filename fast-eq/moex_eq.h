#include<stdio.h>
#include<string.h>
#include "utils.h"

#define DEBUG 1
#define DEBUG1 1
#define DEBUG2 1
//#define DEBUG3 1

//template X_MSR_FOND*********************************

typedef struct moex_eq__X_MSR_FOND moex_eq__2523;

#define moex_eq__X_MSR_FOND__GroupMDEntries__MAX 40


struct moex_eq__X_MSR_FOND__GroupMDEntries
{
    struct uint32_nullable_t MDUpdateAction; //nopmap_uint32_nullable_noop_type
    struct ascii_string_nullable_t MDEntryType; //nopmap_string_nullable_noop_type
    struct ascii_string_nullable_t MDEntryID; //nopmap_string_nullable_noop_type
    struct ascii_string_nullable_t Symbol; //nopmap_string_nullable_noop_type
    struct int32_nullable_t RptSeq; //nopmap_int32_nullable_noop_type
    struct decimal_nullable_t MDEntryPx; //nopmap_decimal_nullable_noop_type
    struct decimal_nullable_t MDEntrySize; //nopmap_decimal_nullable_noop_type
    struct uint32_nullable_t MDEntryDate; //nopmap_uint32_nullable_noop_type
    struct uint32_nullable_t MDEntryTime; //nopmap_uint32_nullable_noop_type
    struct uint32_nullable_t StartTime; //nopmap_uint32_nullable_noop_type
    struct ascii_string_nullable_t QuoteCondition; //nopmap_string_nullable_noop_type
    struct ascii_string_nullable_t TradeCondition; //nopmap_string_nullable_noop_type
    struct ascii_string_nullable_t OpenCloseSettlFlag; //nopmap_string_nullable_noop_type
    struct decimal_nullable_t NetChgPrevDay; //nopmap_decimal_nullable_noop_type
    struct decimal_nullable_t AccruedInterestAmt; //nopmap_decimal_nullable_noop_type
    struct decimal_nullable_t ChgFromWAPrice; //nopmap_decimal_nullable_noop_type
    struct decimal_nullable_t ChgOpenInterest; //nopmap_decimal_nullable_noop_type
    struct decimal_nullable_t BidMarketSize; //nopmap_decimal_nullable_noop_type
    struct decimal_nullable_t AskMarketSize; //nopmap_decimal_nullable_noop_type
    struct int32_nullable_t TotalNumOfTrades; //nopmap_int32_nullable_noop_type
    struct decimal_nullable_t TradeValue; //nopmap_decimal_nullable_noop_type
    struct decimal_nullable_t Yield; //nopmap_decimal_nullable_noop_type
    struct int32_nullable_t OfferNbOr; //nopmap_int32_nullable_noop_type
    struct int32_nullable_t BidNbOr; //nopmap_int32_nullable_noop_type
    struct decimal_nullable_t ChgFromSettlmnt; //nopmap_decimal_nullable_noop_type
    struct decimal_nullable_t MinCurrPx; //nopmap_decimal_nullable_noop_type
    struct uint32_nullable_t MinCurrPxChgTime; //nopmap_uint32_nullable_noop_type
    struct uint32_nullable_t VolumeIndicator; //nopmap_uint32_nullable_noop_type
    struct uint32_nullable_t SettlDate; //nopmap_uint32_nullable_noop_type
    struct ascii_string_nullable_t SettleType; //nopmap_string_nullable_noop_type
    struct ascii_string_nullable_t CXFlag; //nopmap_string_nullable_noop_type
    struct ascii_string_nullable_t TradingSessionID; //nopmap_string_nullable_noop_type
    struct ascii_string_nullable_t TradingSessionSubID; //nopmap_string_nullable_noop_type
};

struct moex_eq__X_MSR_FOND_State
{
    char MessageType[2]; //CONSTANT value = X, nopmap_string_nonullable_constant_type
    char ApplVerID[2]; //CONSTANT value = 9, nopmap_string_nonullable_constant_type
    char BeginString[9]; //CONSTANT value = FIXT.1.1, nopmap_string_nonullable_constant_type
    char SenderCompID[5]; //CONSTANT value = MOEX, nopmap_string_nonullable_constant_type
};

struct moex_eq__X_MSR_FOND
{
    struct moex_eq__X_MSR_FOND_State moex_eq__X_MSR_FOND_State;
    char *pmap; //for template pmap required
    char MessageType[2]; //CONSTANT value = X, nopmap_string_nonullable_constant_type
    char ApplVerID[2]; //CONSTANT value = 9, nopmap_string_nonullable_constant_type
    char BeginString[9]; //CONSTANT value = FIXT.1.1, nopmap_string_nonullable_constant_type
    char SenderCompID[5]; //CONSTANT value = MOEX, nopmap_string_nonullable_constant_type
    uint32_t MsgSeqNum; //nopmap_uint32_nonullable_noop_type
    uint64_t SendingTime; //nopmap_uint64_nonullable_noop_type
    struct uint64_nullable_t LastUpdateTime; //nopmap_uint64_nullable_noop_type
    uint32_t NoMDEntries; //nopmap_uint32_nonullable_noop_type
    struct moex_eq__X_MSR_FOND__GroupMDEntries GroupMDEntries [moex_eq__X_MSR_FOND__GroupMDEntries__MAX];
};





//template X_TLR_FOND*********************************

typedef struct moex_eq__X_TLR_FOND moex_eq__2521;

#define moex_eq__X_TLR_FOND__GroupMDEntries__MAX 40


struct moex_eq__X_TLR_FOND__GroupMDEntries
{
    struct uint32_nullable_t MDUpdateAction; //nopmap_uint32_nullable_noop_type
    struct ascii_string_t MDEntryType; //nopmap_string_nonullable_noop_type
    struct ascii_string_nullable_t MDEntryID; //nopmap_string_nullable_noop_type
    struct ascii_string_nullable_t Symbol; //nopmap_string_nullable_noop_type
    struct int32_nullable_t RptSeq; //nopmap_int32_nullable_noop_type
    struct uint32_nullable_t MDEntryDate; //nopmap_uint32_nullable_noop_type
    struct uint32_nullable_t MDEntryTime; //nopmap_uint32_nullable_noop_type
    struct uint32_nullable_t OrigTime; //nopmap_uint32_nullable_noop_type
    struct ascii_string_nullable_t OrderSide; //nopmap_string_nullable_noop_type
    struct decimal_nullable_t MDEntryPx; //nopmap_decimal_nullable_noop_type
    struct decimal_nullable_t MDEntrySize; //nopmap_decimal_nullable_noop_type
    struct decimal_nullable_t AccruedInterestAmt; //nopmap_decimal_nullable_noop_type
    struct decimal_nullable_t TradeValue; //nopmap_decimal_nullable_noop_type
    struct decimal_nullable_t Yield; //nopmap_decimal_nullable_noop_type
    struct uint32_nullable_t SettlDate; //nopmap_uint32_nullable_noop_type
    struct ascii_string_nullable_t SettleType; //nopmap_string_nullable_noop_type
    struct decimal_nullable_t Price; //nopmap_decimal_nullable_noop_type
    struct int32_nullable_t PriceType; //nopmap_int32_nullable_noop_type
    struct decimal_nullable_t RepoToPx; //nopmap_decimal_nullable_noop_type
    struct decimal_nullable_t BuyBackPx; //nopmap_decimal_nullable_noop_type
    struct uint32_nullable_t BuyBackDate; //nopmap_uint32_nullable_noop_type
    struct ascii_string_nullable_t TradingSessionID; //nopmap_string_nullable_noop_type
    struct ascii_string_nullable_t TradingSessionSubID; //nopmap_string_nullable_noop_type
    struct ascii_string_nullable_t RefOrderID; //nopmap_string_nullable_noop_type
};

struct moex_eq__X_TLR_FOND_State
{
    char MessageType[2]; //CONSTANT value = X, nopmap_string_nonullable_constant_type
    char ApplVerID[2]; //CONSTANT value = 9, nopmap_string_nonullable_constant_type
    char BeginString[9]; //CONSTANT value = FIXT.1.1, nopmap_string_nonullable_constant_type
    char SenderCompID[5]; //CONSTANT value = MOEX, nopmap_string_nonullable_constant_type
};

struct moex_eq__X_TLR_FOND
{
    struct moex_eq__X_TLR_FOND_State moex_eq__X_TLR_FOND_State;
    char *pmap; //for template pmap required
    char MessageType[2]; //CONSTANT value = X, nopmap_string_nonullable_constant_type
    char ApplVerID[2]; //CONSTANT value = 9, nopmap_string_nonullable_constant_type
    char BeginString[9]; //CONSTANT value = FIXT.1.1, nopmap_string_nonullable_constant_type
    char SenderCompID[5]; //CONSTANT value = MOEX, nopmap_string_nonullable_constant_type
    uint32_t MsgSeqNum; //nopmap_uint32_nonullable_noop_type
    uint64_t SendingTime; //nopmap_uint64_nonullable_noop_type
    uint32_t NoMDEntries; //nopmap_uint32_nonullable_noop_type
    struct moex_eq__X_TLR_FOND__GroupMDEntries GroupMDEntries [moex_eq__X_TLR_FOND__GroupMDEntries__MAX];
};





//template d*********************************

typedef struct moex_eq__d moex_eq__2115;

#define moex_eq__d__GroupInstrAttrib__MAX 40
#define moex_eq__d__MarketSegmentGrp__MAX 40
#define moex_eq__d__MarketSegmentGrp__TradingSessionRulesGrp__MAX 40


struct moex_eq__d__MarketSegmentGrp__TradingSessionRulesGrp
{
    struct ascii_string_t TradingSessionID; //nopmap_string_nonullable_noop_type
    struct ascii_string_nullable_t TradingSessionSubID; //nopmap_string_nullable_noop_type
    struct int32_nullable_t SecurityTradingStatus; //nopmap_int32_nullable_noop_type
    struct int32_nullable_t OrderNote; //nopmap_int32_nullable_noop_type
};

struct moex_eq__d__MarketSegmentGrp
{
    struct decimal_nullable_t RoundLot; //nopmap_decimal_nullable_noop_type
    struct uint32_nullable_t NoTradingSessionRules; //nopmap_uint32_nullable_noop_type
    struct moex_eq__d__MarketSegmentGrp__TradingSessionRulesGrp TradingSessionRulesGrp [moex_eq__d__MarketSegmentGrp__TradingSessionRulesGrp__MAX];
};

struct moex_eq__d__GroupInstrAttrib
{
    int32_t InstrAttribType; //nopmap_int32_nonullable_noop_type
    struct byte_vector_nullable_t InstrAttribValue; //nopmap_bytevector_nullable_noop_type
};

struct moex_eq__d_State
{
    char MessageType[2]; //CONSTANT value = d, nopmap_string_nonullable_constant_type
    char ApplVerID[2]; //CONSTANT value = 9, nopmap_string_nonullable_constant_type
    char BeginString[9]; //CONSTANT value = FIXT.1.1, nopmap_string_nonullable_constant_type
    char SenderCompID[5]; //CONSTANT value = MOEX, nopmap_string_nonullable_constant_type
    uint32_t MsgSeqNum; //pmap_uint32_nonullable_increment_type
    struct ascii_string_default_t MessageEncoding; //PMAP default value = UTF-8, pmap_string_nonullable_default_type
};

struct moex_eq__d
{
    struct moex_eq__d_State moex_eq__d_State;
    char *pmap; //for template pmap required
    char MessageType[2]; //CONSTANT value = d, nopmap_string_nonullable_constant_type
    char ApplVerID[2]; //CONSTANT value = 9, nopmap_string_nonullable_constant_type
    char BeginString[9]; //CONSTANT value = FIXT.1.1, nopmap_string_nonullable_constant_type
    char SenderCompID[5]; //CONSTANT value = MOEX, nopmap_string_nonullable_constant_type
    uint32_t MsgSeqNum; //pmap_uint32_nonullable_increment_type
    uint64_t SendingTime; //nopmap_uint64_nonullable_noop_type
    struct ascii_string_default_t MessageEncoding; //PMAP default value = UTF-8, pmap_string_nonullable_default_type
    struct int32_nullable_t TotNumReports; //nopmap_int32_nullable_noop_type
    struct ascii_string_nullable_t Symbol; //nopmap_string_nullable_noop_type
    struct byte_vector_nullable_t SecurityID; //nopmap_bytevector_nullable_noop_type
    struct byte_vector_nullable_t SecurityIDSource; //nopmap_bytevector_nullable_noop_type
    struct int32_nullable_t Product; //nopmap_int32_nullable_noop_type
    struct byte_vector_nullable_t CFICode; //nopmap_bytevector_nullable_noop_type
    struct byte_vector_nullable_t SecurityType; //nopmap_bytevector_nullable_noop_type
    struct uint32_nullable_t MaturityDate; //nopmap_uint32_nullable_noop_type
    struct uint32_nullable_t SettlDate; //nopmap_uint32_nullable_noop_type
    struct ascii_string_nullable_t SettleType; //nopmap_string_nullable_noop_type
    struct decimal_nullable_t OrigIssueAmt; //nopmap_decimal_nullable_noop_type
    struct uint32_nullable_t CouponPaymentDate; //nopmap_uint32_nullable_noop_type
    struct decimal_nullable_t CouponRate; //nopmap_decimal_nullable_noop_type
    struct uint32_nullable_t SettlFixingDate; //nopmap_uint32_nullable_noop_type
    struct decimal_nullable_t DividendNetPx; //nopmap_decimal_nullable_noop_type
    struct byte_vector_nullable_t SecurityDesc; //nopmap_bytevector_nullable_noop_type
    struct byte_vector_nullable_t EncodedSecurityDesc; //nopmap_bytevector_nullable_noop_type
    struct byte_vector_nullable_t QuoteText; //nopmap_bytevector_nullable_noop_type
    struct uint32_nullable_t NoInstrAttrib; //nopmap_uint32_nullable_noop_type
    struct moex_eq__d__GroupInstrAttrib GroupInstrAttrib [moex_eq__d__GroupInstrAttrib__MAX];
    struct ascii_string_nullable_t Currency; //nopmap_string_nullable_noop_type
    struct uint32_nullable_t NoMarketSegments; //nopmap_uint32_nullable_noop_type
    struct moex_eq__d__MarketSegmentGrp MarketSegmentGrp [moex_eq__d__MarketSegmentGrp__MAX];
    struct ascii_string_nullable_t SettlCurrency; //nopmap_string_nullable_noop_type
    struct int32_nullable_t PriceType; //nopmap_int32_nullable_noop_type
    struct ascii_string_nullable_t StateSecurityID; //nopmap_string_nullable_noop_type
    struct byte_vector_nullable_t EncodedShortSecurityDesc; //nopmap_bytevector_nullable_noop_type
    struct byte_vector_nullable_t MarketCode; //nopmap_bytevector_nullable_noop_type
    struct decimal_nullable_t MinPriceIncrement; //nopmap_decimal_nullable_noop_type
    struct decimal_nullable_t MktShareLimit; //nopmap_decimal_nullable_noop_type
    struct decimal_nullable_t MktShareThreshold; //nopmap_decimal_nullable_noop_type
    struct decimal_nullable_t MaxOrdersVolume; //nopmap_decimal_nullable_noop_type
    struct decimal_nullable_t PriceMvmLimit; //nopmap_decimal_nullable_noop_type
    struct decimal_nullable_t FaceValue; //nopmap_decimal_nullable_noop_type
    struct decimal_nullable_t BaseSwapPx; //nopmap_decimal_nullable_noop_type
    struct decimal_nullable_t RepoToPx; //nopmap_decimal_nullable_noop_type
    struct decimal_nullable_t BuyBackPx; //nopmap_decimal_nullable_noop_type
    struct uint32_nullable_t BuyBackDate; //nopmap_uint32_nullable_noop_type
    struct decimal_nullable_t NoSharesIssued; //nopmap_decimal_nullable_noop_type
    struct decimal_nullable_t HighLimit; //nopmap_decimal_nullable_noop_type
    struct decimal_nullable_t LowLimit; //nopmap_decimal_nullable_noop_type
    struct int32_nullable_t NumOfDaysToMaturity; //nopmap_int32_nullable_noop_type
};





//template f*********************************

typedef struct moex_eq__f moex_eq__2106;



struct moex_eq__f_State
{
    char MessageType[2]; //CONSTANT value = f, nopmap_string_nonullable_constant_type
    char ApplVerID[2]; //CONSTANT value = 9, nopmap_string_nonullable_constant_type
    char BeginString[9]; //CONSTANT value = FIXT.1.1, nopmap_string_nonullable_constant_type
    char SenderCompID[5]; //CONSTANT value = MOEX, nopmap_string_nonullable_constant_type
};

struct moex_eq__f
{
    struct moex_eq__f_State moex_eq__f_State;
    char *pmap; //for template pmap required
    char MessageType[2]; //CONSTANT value = f, nopmap_string_nonullable_constant_type
    char ApplVerID[2]; //CONSTANT value = 9, nopmap_string_nonullable_constant_type
    char BeginString[9]; //CONSTANT value = FIXT.1.1, nopmap_string_nonullable_constant_type
    char SenderCompID[5]; //CONSTANT value = MOEX, nopmap_string_nonullable_constant_type
    uint32_t MsgSeqNum; //nopmap_uint32_nonullable_noop_type
    uint64_t SendingTime; //nopmap_uint64_nonullable_noop_type
    struct ascii_string_t Symbol; //nopmap_string_nonullable_noop_type
    struct ascii_string_nullable_t TradingSessionID; //nopmap_string_nullable_noop_type
    struct ascii_string_nullable_t TradingSessionSubID; //nopmap_string_nullable_noop_type
    struct int32_nullable_t SecurityTradingStatus; //nopmap_int32_nullable_noop_type
    struct uint32_nullable_t AuctionIndicator; //nopmap_uint32_nullable_noop_type
};





//template h*********************************

typedef struct moex_eq__h moex_eq__2107;



struct moex_eq__h_State
{
    char MessageType[2]; //CONSTANT value = h, nopmap_string_nonullable_constant_type
    char ApplVerID[2]; //CONSTANT value = 9, nopmap_string_nonullable_constant_type
    char BeginString[9]; //CONSTANT value = FIXT.1.1, nopmap_string_nonullable_constant_type
    char SenderCompID[5]; //CONSTANT value = MOEX, nopmap_string_nonullable_constant_type
};

struct moex_eq__h
{
    struct moex_eq__h_State moex_eq__h_State;
    char *pmap; //for template pmap required
    char MessageType[2]; //CONSTANT value = h, nopmap_string_nonullable_constant_type
    char ApplVerID[2]; //CONSTANT value = 9, nopmap_string_nonullable_constant_type
    char BeginString[9]; //CONSTANT value = FIXT.1.1, nopmap_string_nonullable_constant_type
    char SenderCompID[5]; //CONSTANT value = MOEX, nopmap_string_nonullable_constant_type
    uint32_t MsgSeqNum; //nopmap_uint32_nonullable_noop_type
    uint64_t SendingTime; //nopmap_uint64_nonullable_noop_type
    int32_t TradSesStatus; //nopmap_int32_nonullable_noop_type
    struct ascii_string_nullable_t Text; //nopmap_string_nullable_noop_type
    struct ascii_string_t TradingSessionID; //nopmap_string_nonullable_noop_type
};





//template 0*********************************

typedef struct moex_eq__0 moex_eq__2108;



struct moex_eq__0_State
{
    char MessageType[2]; //CONSTANT value = 0, nopmap_string_nonullable_constant_type
    char BeginString[9]; //CONSTANT value = FIXT.1.1, nopmap_string_nonullable_constant_type
    char SenderCompID[5]; //CONSTANT value = MOEX, nopmap_string_nonullable_constant_type
};

struct moex_eq__0
{
    struct moex_eq__0_State moex_eq__0_State;
    char *pmap; //for template pmap required
    char MessageType[2]; //CONSTANT value = 0, nopmap_string_nonullable_constant_type
    char BeginString[9]; //CONSTANT value = FIXT.1.1, nopmap_string_nonullable_constant_type
    char SenderCompID[5]; //CONSTANT value = MOEX, nopmap_string_nonullable_constant_type
    uint32_t MsgSeqNum; //nopmap_uint32_nonullable_noop_type
    uint64_t SendingTime; //nopmap_uint64_nonullable_noop_type
};




#define moex_eq_parse__2523(packet, offset, pmap, template) moex_eq_parse_template_X_MSR_FOND(packet, offset, pmap, template)
#define moex_eq_parse__2521(packet, offset, pmap, template) moex_eq_parse_template_X_TLR_FOND(packet, offset, pmap, template)
#define moex_eq_parse__2115(packet, offset, pmap, template) moex_eq_parse_template_d(packet, offset, pmap, template)
#define moex_eq_parse__2106(packet, offset, pmap, template) moex_eq_parse_template_f(packet, offset, pmap, template)
#define moex_eq_parse__2107(packet, offset, pmap, template) moex_eq_parse_template_h(packet, offset, pmap, template)
#define moex_eq_parse__2108(packet, offset, pmap, template) moex_eq_parse_template_0(packet, offset, pmap, template)


#ifdef __cplusplus
extern "C"
{
#endif
int moex_eq_parse_template_X_MSR_FOND(unsigned char *packet, int *offset, unsigned char * pmap, struct moex_eq__X_MSR_FOND *t);
int moex_eq_parse_template_X_TLR_FOND(unsigned char *packet, int *offset, unsigned char * pmap, struct moex_eq__X_TLR_FOND *t);
int moex_eq_parse_template_d(unsigned char *packet, int *offset, unsigned char * pmap, struct moex_eq__d *t);
int moex_eq_parse_template_f(unsigned char *packet, int *offset, unsigned char * pmap, struct moex_eq__f *t);
int moex_eq_parse_template_h(unsigned char *packet, int *offset, unsigned char * pmap, struct moex_eq__h *t);
int moex_eq_parse_template_0(unsigned char *packet, int *offset, unsigned char * pmap, struct moex_eq__0 *t);
#ifdef __cplusplus
}
#endif

#ifndef __LOCAL_UTILS__
#define __LOCAL_UTILS__
#include <time.h>
#include <cgate.h>
#include <string>

#define MAX_MULTIPLIER_DIGITS 6
// helper variable used as a notification flag to exit

int64_t cg_bcd_to_int64(char *bcd)
{
    int64_t intpart;
    int8_t scale;
    cg_bcd_get(bcd, &intpart, &scale);
    int32_t nums = MAX_MULTIPLIER_DIGITS - scale;
    for (int i = 0; i < nums; i++)
    {
        intpart *= 10;
    }
    return intpart;
}

time_t cg_time_to_unix_time(cg_time_t &t)
{
    struct tm tm = {0};         // Initalize to all 0's
    tm.tm_year = t.year - 1900; // This is year-1900, so 112 = 2012
    tm.tm_mon = t.month;
    tm.tm_mday = t.day;
    tm.tm_hour = t.hour;
    tm.tm_min = t.minute;
    tm.tm_sec = t.second;
    time_t timeSinceEpoch = mktime(&tm);
    return timeSinceEpoch;
}

std::string get_cg_time_str(cg_time_t &t)
{
    char buff[32];
    sprintf(buff, "%04d-%02d-%02d %02d:%02d:%02d", t.year, t.month, t.day, t.hour, t.minute, t.second);
    return std::string(buff);
}
std::string get_date_from_cg_time(cg_time_t &t)
{
    char buff[32];
    sprintf(buff, "%04d%02d%02d", t.year, t.month, t.day);
    return std::string(buff);
}
#endif // !__LOCAL_UTILS__

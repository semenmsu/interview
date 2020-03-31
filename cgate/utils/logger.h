#ifndef __LOGGER_H__
#define __LOGGER_H__
#include <stdio.h>
#include <iostream>
#include <stdarg.h>
#include <string.h>

class Logger
{
public:
    Logger() = default;

    void info(const char *format, ...)
    {
        va_list argptr;
        va_start(argptr, format);
        char buff[8192];
        vsprintf(buff, format, argptr);
        fprintf(stdout, "[%s] INFO  %s\n", getTime().c_str(), buff);
        fflush(stdout);
        va_end(argptr);
    }

    void warn(const char *format, ...)
    {
        va_list argptr;
        va_start(argptr, format);
        char buff[8192];
        vsprintf(buff, format, argptr);
        fprintf(stdout, "[%s] WARN  %s\n", getTime().c_str(), buff);
        fflush(stdout);
        va_end(argptr);
    }

    void error(const char *format, ...)
    {
        va_list argptr;
        va_start(argptr, format);
        char buff[8192];
        vsprintf(buff, format, argptr);
        fprintf(stdout, "[%s] ERROR %s\n", getTime().c_str(), buff);
        fflush(stdout);
        va_end(argptr);
    }

private:
    std::string getTime()
    {
        time_t rawtime;
        struct tm *timeinfo;
        char buffer[80];
        time(&rawtime);
        timeinfo = localtime(&rawtime);
        strftime(buffer, sizeof(buffer), "%d/%m/%Y %H:%M:%S", timeinfo);
        std::string str(buffer);
        return str;
    }
};

Logger logger;

#endif // !__LOGGER_H__

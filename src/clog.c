#include "clog.h"
#include "ansi.h"

#include <stdio.h>
#include <stdarg.h>
#include <time.h>

static enum CLoggerDebugMode debug = CLOG_DEBUG_DEFAULT; // Default value

void clog_message(const char* location, const char* format, va_list args)
{
    time_t now;
    struct tm* timestamp = localtime(&now);
    char buffer[10];

    strftime(buffer, sizeof(buffer), "%H:%M:%S", timestamp);

    printf("%s - %s -> ", buffer, location);
    vprintf(format, args);
    printf("\n");
}

void clog_info(const char* location, char* format, ...)
{
    if (debug)
    {
        printf(CLOGGER_FG_HBLU"[INFO] "CLOGGER_RESET);

        va_list args;

        va_start(args, format);
        clog_message(location, format, args);
        va_end(args);
    }
}

void clog_debug(const char* location, char* format, ...)
{
    if (debug)
    {
        printf(CLOGGER_FG_HGRN"[DEBUG] "CLOGGER_RESET);

        va_list args;

        va_start(args, format);
        clog_message(location, format, args);
        va_end(args);
    }
}

void clog_warning(const char* location, char* format, ...)
{
    printf(CLOGGER_FG_HYEL"[WARNING] "CLOGGER_RESET);

    va_list args;

    va_start(args, format);
    clog_message(location, format, args);
    va_end(args);
}

void clog_error(const char* location, char* format, ...)
{
    printf(CLOGGER_FG_HRED"[ERROR] "CLOGGER_RESET);

    va_list args;

    va_start(args, format);
    clog_message(location, format, args);
    va_end(args);
}

void clog_fatal(const char* location, char* format, ...)
{
    printf(CLOGGER_FG_HRED"[FATAL] "CLOGGER_RESET);

    va_list args;

    va_start(args, format);
    clog_message(location, format, args);
    va_end(args);
}

void set_clogger_debug(enum CLoggerDebugMode value)
{
    debug = value;
}

#include "clog.h"
#include "ansi.h"

#include <stdio.h>
#include <stdarg.h>
#include <time.h>

static enum CLoggerDebugMode debug = CLOG_DEBUG_DEFAULT; // Default value

void clog_messagef(const char* location, const char* format, va_list args)
{
    time_t now;
    struct tm* timestamp = localtime(&now);
    char timestamp_buffer[10];

    strftime(timestamp_buffer, sizeof(timestamp_buffer), "%H:%M:%S", timestamp);

    printf(CLOGGER_FG_BOLD_CYN"%s"CLOGGER_RESET_CONSOLE" >> "CLOGGER_FG_BOLD_MAG"%s"CLOGGER_RESET_CONSOLE" >> ", timestamp_buffer, location);

    vprintf(format, args);
    printf("\n");
}

void clog_message(const char* location, char* message, ...)
{
    va_list args;

    va_start(args, message);
    clog_messagef(location, message, args);
    va_end(args);
}

void clog_info(const char* location, char* message, ...)
{
    if (debug)
    {
        printf(CLOGGER_FG_HBLU"[INFO]"CLOGGER_RESET_CONSOLE" >> ");

        va_list args;

        va_start(args, message);
        clog_messagef(location, message, args);
        va_end(args);
    }
}

void clog_debug(const char* location, char* message, ...)
{
    if (debug)
    {
        printf(CLOGGER_FG_HGRN"[DEBUG]"CLOGGER_RESET_CONSOLE" >> ");

        va_list args;

        va_start(args, message);
        clog_messagef(location, message, args);
        va_end(args);
    }
}

void clog_warning(const char* location, char* message, ...)
{
    printf(CLOGGER_FG_HYEL"[WARNING]"CLOGGER_RESET_CONSOLE" >> ");

    va_list args;

    va_start(args, message);
    clog_messagef(location, message, args);
    va_end(args);
}

void clog_error(const char* location, char* message, ...)
{
    printf(CLOGGER_FG_HRED"[ERROR]"CLOGGER_RESET_CONSOLE" >> ");

    va_list args;

    va_start(args, message);
    clog_messagef(location, message, args);
    va_end(args);
}

void clog_fatal(const char* location, char* message, ...)
{
    printf(CLOGGER_BG_RED"[FATAL]"CLOGGER_RESET_CONSOLE" >> ");

    va_list args;

    va_start(args, message);
    clog_messagef(location, message, args);
    va_end(args);
}

void set_clogger_debug(enum CLoggerDebugMode value)
{
    debug = value;
}


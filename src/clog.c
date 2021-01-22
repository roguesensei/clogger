#include "clog.h"
#include "ansi.h"

#include <stdio.h>
#include <stdarg.h>
#include <time.h>

void clog_message(const char* location, const char* format, va_list args)
{
    time_t now;
    struct tm *timestamp = localtime(&now);
    char buffer[10];

    strftime(buffer, sizeof(buffer), "%H:%M:%S", timestamp);

    printf("%s - %s -> ", buffer, location);
    vprintf(format, args);
    printf("\n");
}

void clog_debug(const char* location, char* format, ...)
{
    printf(CLOGGER_FG_HGRN"[DEBUG]\t"CLOGGER_RESET);
    // clog_message(location);

    va_list args;

    va_start(args, format);
    clog_message(location, format, args);
    va_end(args);
}
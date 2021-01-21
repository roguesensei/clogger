#include "clog.h"

#include <stdio.h>
#include <stdarg.h>
#include <time.h>

void clog_message(const char* location, const char* message)
{
    time_t now;
    struct tm *timestamp = localtime(&now);
    char buffer[10];

    strftime(buffer, sizeof(buffer), "%H:%M:%S", timestamp);

    printf("%s [%s]\t%s", buffer, location, message);

    // The formatting magic
    // va_list args;
    //
    // va_start(args, format);
    // vprintf(format, args);
    // va_end(args);
}

void clog_debug(const char* location, const char* format, ...)
{
    printf("[DEBUG]\t");

    va_list args;

    va_start(args, format);
    char* message = va_arg(args, char *);
    clog_message(location, message);
    va_end(args);
}
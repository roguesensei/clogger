#include "clogger/clogger.h"
#include "clogger/clog.h"

#include <stdio.h>
#include <stdarg.h>

void default_callback(const char* clogger_name, const char* location) { }

clogger make_clogger(const char* clogger_name)
{
    return (clogger) {clogger_name, default_callback, {Blue, Clear}, CLogFalse};
}

void clogger_info(clogger* logger, const char* location, const char* message, ...)
{
    if (logger->debug_mode)
    {
        clog_set_console_colour(logger->colour, 0);
        printf("%s", logger->name);
        clog_reset_console_colour();
        printf(" >> ");

        va_list args;

        va_start(args, message);
        clog_info(location, message, args);
        va_end(args);
    }
}

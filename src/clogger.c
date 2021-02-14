#include "clogger/clogger.h"
#include "clogger/clog.h"

#include <stdio.h>
#include <stdarg.h>
#include <string.h>

void default_callback(const char* clogger_name, const char* location) { }

void clogger_message(char* message_out, const char* message, va_list args)
{
    char test[256];
    sscanf(test, message, &args);

    strncpy(message_out, test, strlen(test));
    // strncpy(message_out, message, strlen(message));
}

clogger make_clogger(const char* clogger_name)
{
    return (clogger) {clogger_name, default_callback, {Blue, Clear}, clog_false};
}

void clogger_info(clogger* logger, const char* location, const char* message, ...)
{
    if (logger->debug_mode)
    {
        clog_set_console_colour(logger->colour, 0);
        printf("%s", logger->name);
        clog_reset_console_colour();
        printf(" >> ");

        clog_set_console_colour((clog_console_colour) {Blue, Black}, CLOGGER_FOREGROUND_INTENSE);
        printf("[INFO]");
        clog_reset_console_colour();
        printf(" >> ");

        va_list args;

        va_start(args, message);
        clog_messagef(location, message, args);
        va_end(args);
    }
}

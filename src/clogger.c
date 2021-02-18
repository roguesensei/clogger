#include "clogger/clogger.h"
#include "clogger/clog.h"

#include <stdio.h>
#include <stdarg.h>

void default_callback(const char* clogger_name, const char* location) { }

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

        clog_set_console_colour((clog_console_colour) {Blue, Clear}, CLOGGER_FOREGROUND_INTENSE);
        printf("[INFO]");
        clog_reset_console_colour();
        printf(" >> ");

        va_list args;

        va_start(args, message);
        clog_messagef(location, message, args);
        va_end(args);
    }
}

void clogger_debug(clogger* logger, const char* location, const char* message, ...)
{
    if (logger->debug_mode)
    {
        clog_set_console_colour(logger->colour, 0);
        printf("%s", logger->name);
        clog_reset_console_colour();
        printf(" >> ");

        clog_set_console_colour((clog_console_colour) {Green, Clear}, CLOGGER_FOREGROUND_INTENSE);
        printf("[DEBUG]");
        clog_reset_console_colour();
        printf(" >> ");

        va_list args;

        va_start(args, message);
        clog_messagef(location, message, args);
        va_end(args);
    }
}

void clogger_warning(clogger* logger, const char* location, const char* message, ...)
{
    clog_set_console_colour(logger->colour, 0);
    printf("%s", logger->name);
    clog_reset_console_colour();
    printf(" >> ");

    clog_set_console_colour((clog_console_colour) {Yellow, Clear}, CLOGGER_FOREGROUND_INTENSE);
    printf("[WARNING]");
    clog_reset_console_colour();
    printf(" >> ");

    va_list args;

    va_start(args, message);
    clog_messagef(location, message, args);
    va_end(args);
}

void clogger_error(clogger* logger, const char* location, const char* message, ...)
{
    clog_set_console_colour(logger->colour, 0);
    printf("%s", logger->name);
    clog_reset_console_colour();
    printf(" >> ");

    clog_set_console_colour((clog_console_colour) {Red, Clear}, CLOGGER_FOREGROUND_INTENSE);
    printf("[ERROR]");
    clog_reset_console_colour();
    printf(" >> ");

    va_list args;

    va_start(args, message);
    clog_messagef(location, message, args);
    va_end(args);

    // Error callback
    logger->error_callback(logger->name, location);
}

void clogger_critical(clogger* logger, const char* location, const char* message, ...)
{
    clog_set_console_colour(logger->colour, 0);
    printf("%s", logger->name);
    clog_reset_console_colour();
    printf(" >> ");

    clog_set_console_colour((clog_console_colour) {White, Red},
                            CLOGGER_FOREGROUND_INTENSE | CLOGGER_BACKGROUND_INTENSE);
    printf("[CRITICAL]");
    clog_reset_console_colour();
    printf(" >> ");

    va_list args;

    va_start(args, message);
    clog_messagef(location, message, args);
    va_end(args);

    // Error callback
    logger->error_callback(logger->name, location);
}

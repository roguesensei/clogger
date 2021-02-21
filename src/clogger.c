#include "clogger/clogger.h"
#include "clogger/clog.h"

#include <stdio.h>
#include <stdarg.h>

void default_callback(clog_level level, const char* clogger_name, const char* location) { }

clogger make_clogger(const char* clogger_name)
{
    return (clogger) {clogger_name, default_callback, {Blue, Clear}, clog_false, 0};
}

void clogger_info(clogger* logger, const char* location, const char* message, ...)
{
    if (logger->debug_mode)
    {
        va_list args;

        va_start(args, message);
        clog_messagef(clog_level_info, logger, location, message, args);
        va_end(args);
    }
}

void clogger_debug(clogger* logger, const char* location, const char* message, ...)
{
    if (logger->debug_mode)
    {
        va_list args;

        va_start(args, message);
        clog_messagef(clog_level_debug, logger, location, message, args);
        va_end(args);
    }
}

void clogger_warning(clogger* logger, const char* location, const char* message, ...)
{
    va_list args;

    va_start(args, message);
    clog_messagef(clog_level_warning, logger, location, message, args);
    va_end(args);
}

void clogger_error(clogger* logger, const char* location, const char* message, ...)
{
    va_list args;

    va_start(args, message);
    clog_messagef(clog_level_error, logger, location, message, args);
    va_end(args);

    // Error callback
    logger->error_callback(clog_level_error, logger->name, location);
}

void clogger_critical(clogger* logger, const char* location, const char* message, ...)
{
    va_list args;

    va_start(args, message);
    clog_messagef(clog_level_critical, logger, location, message, args);
    va_end(args);

    // Error callback
    logger->error_callback(clog_level_critical, logger->name, location);
}

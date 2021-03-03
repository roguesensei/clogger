#include "clogger/clogger.h"
#include "clogger/clog.h"

#include <stdio.h>
#include <stdarg.h>
#include <pthread.h>

void default_callback(clog_level level, const char* clogger_name, const char* location) { }

void default_callback_async(const pthread_t* thread, const char* clogger_name, const char* location) { }

// The "do nothing" thread so when the thread is joined, it doesn't crash
void* thread_do_nothing(void* args) { return NULL; }

clogger make_clogger(const char* clogger_name)
{
    return (clogger) {clogger_name, default_callback, /* default_callback_async, */ {Blue, Clear}, clog_level_warning,
                      0};
}

void clogger_info(clogger* logger, const char* location, const char* message, ...)
{
    if (logger->log_level <= clog_level_info)
    {
        va_list args;

        va_start(args, message);
        clog_messagef(clog_level_info, logger, location, message, args);
        va_end(args);
    }
}

void clogger_debug(clogger* logger, const char* location, const char* message, ...)
{
    if (logger->log_level <= clog_level_debug)
    {
        va_list args;

        va_start(args, message);
        clog_messagef(clog_level_debug, logger, location, message, args);
        va_end(args);
    }
}

void clogger_warning(clogger* logger, const char* location, const char* message, ...)
{
    if (logger->log_level <= clog_level_warning)
    {
        va_list args;

        va_start(args, message);
        clog_messagef(clog_level_warning, logger, location, message, args);
        va_end(args);
    }
}

void clogger_error(clogger* logger, const char* location, const char* message, ...)
{
    if (logger->log_level <= clog_level_error)
    {
        va_list args;

        va_start(args, message);
        clog_messagef(clog_level_error, logger, location, message, args);
        va_end(args);

        // Error callback
        logger->error_callback(clog_level_error, logger->name, location);
    }
}

void clogger_critical(clogger* logger, const char* location, const char* message, ...)
{
    if (logger->log_level <= clog_level_critical)
    {
        va_list args;

        va_start(args, message);
        clog_messagef(clog_level_critical, logger, location, message, args);
        va_end(args);

        // Error callback
        logger->error_callback(clog_level_critical, logger->name, location);
    }
}

clog_thread clogger_info_async(clogger* logger, const char* location, const char* message, ...)
{
    pthread_t thread;

    if (logger->log_level <= clog_level_info)
    {
        va_list args;

        va_start(args, message);
        thread = (pthread_t) clog_messagef_async(clog_level_info, logger, location, message, args);
        va_end(args);
    }
    else
    {
        pthread_create(&thread, NULL, thread_do_nothing, NULL);
    }

    return (clog_thread) thread;
}

clog_thread clogger_debug_async(clogger* logger, const char* location, const char* message, ...)
{
    pthread_t thread;

    if (logger->log_level <= clog_level_debug)
    {
        va_list args;

        va_start(args, message);
        thread = (pthread_t) clog_messagef_async(clog_level_debug, logger, location, message, args);
        va_end(args);
    }
    else
    {
        pthread_create(&thread, NULL, thread_do_nothing, NULL);
    }

    return (clog_thread) thread;
}

clog_thread clogger_warning_async(clogger* logger, const char* location, const char* message, ...)
{
    pthread_t thread;

    if (logger->log_level <= clog_level_warning)
    {
        va_list args;

        va_start(args, message);
        thread = (pthread_t) clog_messagef_async(clog_level_warning, logger, location, message, args);
        va_end(args);
    }
    else
    {
        pthread_create(&thread, NULL, thread_do_nothing, NULL);
    }

    return (clog_thread) thread;
}

clog_thread clogger_error_async(clogger* logger, const char* location, const char* message, ...)
{
    pthread_t thread;

    if (logger->log_level <= clog_level_error)
    {
        va_list args;

        va_start(args, message);
        thread = (pthread_t) clog_messagef_async(clog_level_error, logger, location, message, args);
        va_end(args);

        // Error callback
        // logger->error_callback_async(&thread ,/*clog_level_error,*/ logger->name, location);
    }
    else
    {
        pthread_create(&thread, NULL, thread_do_nothing, NULL);
    }

    return (clog_thread) thread;
}

clog_thread clogger_critical_async(clogger* logger, const char* location, const char* message, ...)
{
    pthread_t thread;

    if (logger->log_level <= clog_level_critical)
    {
        va_list args;

        va_start(args, message);
        thread = (pthread_t) clog_messagef_async(clog_level_critical, logger, location, message, args);
        va_end(args);

        // Error callback
        // logger->error_callback(clog_level_critical, logger->name, location);
    }
    else
    {
        pthread_create(&thread, NULL, thread_do_nothing, NULL);
    }

    return (clog_thread) thread;
}

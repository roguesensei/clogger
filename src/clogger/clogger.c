#include "clogger.h"
#include "clog.h"

#include <stdio.h>
#include <stdarg.h>
#include <pthread.h>

// The "do nothing" thread so when the thread is joined, it doesn't crash
void* thread_do_nothing(void* args) { return NULL; }

clogger_t make_clogger(const char* clogger_name)
{
    return (clogger_t) {clogger_name, NULL, {BLUE, CLEAR}, CLOG_LEVEL_WARNING, 0};
}

void clogger_info(clogger_t* logger, const char* location, const char* message, ...)
{
    if (logger->log_level <= CLOG_LEVEL_INFO)
    {
        va_list args;

        va_start(args, message);
        clog_messagef(CLOG_LEVEL_INFO, logger, location, message, args);
        va_end(args);
    }
}

void clogger_debug(clogger_t* logger, const char* location, const char* message, ...)
{
    if (logger->log_level <= CLOG_LEVEL_DEBUG)
    {
        va_list args;

        va_start(args, message);
        clog_messagef(CLOG_LEVEL_DEBUG, logger, location, message, args);
        va_end(args);
    }
}

void clogger_warning(clogger_t* logger, const char* location, const char* message, ...)
{
    if (logger->log_level <= CLOG_LEVEL_WARNING)
    {
        va_list args;

        va_start(args, message);
        clog_messagef(CLOG_LEVEL_WARNING, logger, location, message, args);
        va_end(args);
    }
}

void clogger_error(clogger_t* logger, const char* location, const char* message, ...)
{
    if (logger->log_level <= CLOG_LEVEL_ERROR)
    {
        va_list args;

        va_start(args, message);
        clog_messagef(CLOG_LEVEL_ERROR, logger, location, message, args);
        va_end(args);

        // Error callback
        if (logger->error_callback)
        {
            logger->error_callback(CLOG_LEVEL_ERROR, logger->name, location);
        }
    }
}

void clogger_critical(clogger_t* logger, const char* location, const char* message, ...)
{
    if (logger->log_level <= CLOG_LEVEL_CRITICAL)
    {
        va_list args;

        va_start(args, message);
        clog_messagef(CLOG_LEVEL_CRITICAL, logger, location, message, args);
        va_end(args);

        // Error callback
        if (logger->error_callback)
        {
            logger->error_callback(CLOG_LEVEL_CRITICAL, logger->name, location);
        }
    }
}

pthread_t clogger_info_async(clogger_t* logger, const char* location, const char* message, ...)
{
    pthread_t thread;

    if (logger->log_level <= CLOG_LEVEL_INFO)
    {
        va_list args;

        va_start(args, message);
        thread = (pthread_t) clog_messagef_async(CLOG_LEVEL_INFO, logger, location, message, args);
        va_end(args);
    }
    else
    {
        pthread_create(&thread, NULL, thread_do_nothing, NULL);
    }

    return thread;
}

pthread_t clogger_debug_async(clogger_t* logger, const char* location, const char* message, ...)
{
    pthread_t thread;

    if (logger->log_level <= CLOG_LEVEL_DEBUG)
    {
        va_list args;

        va_start(args, message);
        thread = (pthread_t) clog_messagef_async(CLOG_LEVEL_DEBUG, logger, location, message, args);
        va_end(args);
    }
    else
    {
        pthread_create(&thread, NULL, thread_do_nothing, NULL);
    }

    return thread;
}

pthread_t clogger_warning_async(clogger_t* logger, const char* location, const char* message, ...)
{
    pthread_t thread;

    if (logger->log_level <= CLOG_LEVEL_WARNING)
    {
        va_list args;

        va_start(args, message);
        thread = (pthread_t) clog_messagef_async(CLOG_LEVEL_WARNING, logger, location, message, args);
        va_end(args);
    }
    else
    {
        pthread_create(&thread, NULL, thread_do_nothing, NULL);
    }

    return thread;
}

pthread_t clogger_error_async(clogger_t* logger, const char* location, const char* message, ...)
{
    pthread_t thread;

    if (logger->log_level <= CLOG_LEVEL_ERROR)
    {
        va_list args;

        va_start(args, message);
        thread = (pthread_t) clog_messagef_async(CLOG_LEVEL_ERROR, logger, location, message, args);
        va_end(args);

        // Error callback
        // logger->error_callback_async(&thread ,/*clog_level_error,*/ logger->name, location);
    }
    else
    {
        pthread_create(&thread, NULL, thread_do_nothing, NULL);
    }

    return thread;
}

pthread_t clogger_critical_async(clogger_t* logger, const char* location, const char* message, ...)
{
    pthread_t thread;

    if (logger->log_level <= CLOG_LEVEL_CRITICAL)
    {
        va_list args;

        va_start(args, message);
        thread = (pthread_t) clog_messagef_async(CLOG_LEVEL_CRITICAL, logger, location, message, args);
        va_end(args);

        // Error callback
        // logger->error_callback(clog_level_critical, logger->name, location);
    }
    else
    {
        pthread_create(&thread, NULL, thread_do_nothing, NULL);
    }

    return thread;
}

#include "clogger.h"
#include "clog.h"
#include "clogger_pch.h"


uint8_t clear_flags(uint8_t bits, uint8_t flags)
{
    bits &= ~flags;

    return bits;
}

uint8_t set_flags(uint8_t bits, uint8_t flags)
{
    bits |= flags;

    return bits;
}

clogger_t* clogger_create(const char* clogger_name)
{
    clogger_t* logger = malloc(sizeof(clogger_t));
    char* default_file_path = "clogger.txt";

    logger->name = clogger_name;
    logger->error_callback = NULL;
    logger->console_colour = (clog_console_colour_t) {BLUE, CLEAR};
    logger->log_level = CLOG_LEVEL_WARNING;
    logger->colour_flags = 0;
    logger->file_opt = CLOGGER_FILE_OPT_DEFAULT;
    logger->log_file_path = calloc(strlen(default_file_path) + 1, sizeof(char));

    memset(logger->log_file_path, 0, sizeof(char));
    strncpy(logger->log_file_path, default_file_path, strlen(default_file_path));

    return logger;
}

void clogger_destroy(clogger_t* logger)
{
    free(logger->log_file_path);
    free(logger);
}


void clogger_info(clogger_t* logger, const char* location, const char* message, ...)
{
    if (logger->log_level <= CLOG_LEVEL_INFO)
    {
        va_list args;

        va_start(args, message);
        int written = clog_messagef(CLOG_LEVEL_INFO, logger, location, message, args);
        va_end(args);

        // Log to file
        if (logger->file_opt & CLOGGER_FILE_OPT_INFO_BIT)
        {
            char fmessage[++written];

            va_start(args, message);
            vsnprintf(fmessage, sizeof(fmessage), message, args);
            va_end(args);

            if (logger->file_opt & CLOGGER_FILE_OPT_PREPEND_BIT)
            {
                clog_prepend_to_file(logger->log_file_path, location, "%s >> [INFO] >> %s", logger->name, fmessage);
            }
            else
            {
                clog_append_to_file(logger->log_file_path, location, "%s >> [INFO] >> %s", logger->name, fmessage);
            }
        }
    }
}

void clogger_debug(clogger_t* logger, const char* location, const char* message, ...)
{
    if (logger->log_level <= CLOG_LEVEL_DEBUG)
    {
        va_list args;

        va_start(args, message);
        int written = clog_messagef(CLOG_LEVEL_DEBUG, logger, location, message, args);
        va_end(args);

        // Log to file
        if (logger->file_opt & CLOGGER_FILE_OPT_DEBUG_BIT)
        {
            char fmessage[++written];

            va_start(args, message);
            vsnprintf(fmessage, sizeof(fmessage), message, args);
            va_end(args);

            if (logger->file_opt & CLOGGER_FILE_OPT_PREPEND_BIT)
            {
                clog_prepend_to_file(logger->log_file_path, location, "%s >> [DEBUG] >> %s", logger->name, fmessage);
            }
            else
            {
                clog_append_to_file(logger->log_file_path, location, "%s >> [DEBUG] >> %s", logger->name, fmessage);
            }
        }
    }
}

void clogger_warning(clogger_t* logger, const char* location, const char* message, ...)
{
    if (logger->log_level <= CLOG_LEVEL_WARNING)
    {
        va_list args;

        va_start(args, message);
        int written = clog_messagef(CLOG_LEVEL_WARNING, logger, location, message, args);
        va_end(args);

        // Log to file
        if (logger->file_opt & CLOGGER_FILE_OPT_WARNING_BIT)
        {
            char fmessage[++written];

            va_start(args, message);
            vsnprintf(fmessage, sizeof(fmessage), message, args);
            va_end(args);

            if (logger->file_opt & CLOGGER_FILE_OPT_PREPEND_BIT)
            {
                clog_prepend_to_file(logger->log_file_path, location, "%s >> [WARNING] >> %s", logger->name, fmessage);
            }
            else
            {
                clog_append_to_file(logger->log_file_path, location, "%s >> [WARNING] >> %s", logger->name, fmessage);
            }
        }
    }
}

void clogger_error(clogger_t* logger, const char* location, const char* message, ...)
{
    if (logger->log_level <= CLOG_LEVEL_ERROR)
    {
        va_list args;

        va_start(args, message);
        int written = clog_messagef(CLOG_LEVEL_ERROR, logger, location, message, args);
        va_end(args);

        // Log to file
        if (logger->file_opt & CLOGGER_FILE_OPT_ERROR_BIT)
        {
            char fmessage[++written];

            va_start(args, message);
            vsnprintf(fmessage, sizeof(fmessage), message, args);
            va_end(args);

            if (logger->file_opt & CLOGGER_FILE_OPT_PREPEND_BIT)
            {
                clog_prepend_to_file(logger->log_file_path, location, "%s >> [ERROR] >> %s", logger->name, fmessage);
            }
            else
            {
                clog_append_to_file(logger->log_file_path, location, "%s >> [ERROR] >> %s", logger->name, fmessage);
            }
        }

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
        int written = clog_messagef(CLOG_LEVEL_CRITICAL, logger, location, message, args);
        va_end(args);

        // Log to file
        if (logger->file_opt & CLOGGER_FILE_OPT_CRITICAL_BIT)
        {
            char fmessage[++written];

            va_start(args, message);
            vsnprintf(fmessage, sizeof(fmessage), message, args);
            va_end(args);

            if (logger->file_opt & CLOGGER_FILE_OPT_PREPEND_BIT)
            {
                clog_prepend_to_file(logger->log_file_path, location, "%s >> [CRITICAL] >> %s", logger->name, fmessage);
            }
            else
            {
                clog_append_to_file(logger->log_file_path, location, "%s >> [CRITICAL] >> %s", logger->name, fmessage);
            }
        }

        // Error callback
        if (logger->error_callback)
        {
            logger->error_callback(CLOG_LEVEL_CRITICAL, logger->name, location);
        }
    }
}

void clogger_set_file_opt_option(clogger_t* logger, clogger_file_opt_t option, int enabled)
{
    if (enabled)
    {
        logger->file_opt = set_flags(logger->file_opt, option);
    }
    else
    {
        logger->file_opt = clear_flags(logger->file_opt, option);
    }
}

void clogger_set_file_opt_path(clogger_t* logger, const char* path)
{
    realloc(logger->log_file_path, (strlen(path) * sizeof(char) + sizeof(char)));
    strncpy(logger->log_file_path, path, strlen(logger->log_file_path));
}

clogger_t make_clogger(const char* clogger_name)
{
    return (clogger_t) {clogger_name, NULL, {BLUE, CLEAR}, CLOG_LEVEL_WARNING, 0, 0, NULL};
}

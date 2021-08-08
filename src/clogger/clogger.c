#include "clogger.h"
#include "clog.h"

// The "do nothing" thread so when the thread is joined, it doesn't crash
void* thread_do_nothing(void* args) { return NULL; }

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
        int written = clog_messagef(CLOG_LEVEL_ERROR, logger, location, message, args);
        va_end(args);

        // Log to file
        if (logger->file_opt & CLOGGER_FILEOPT_ERROR_BIT)
        {
            char fmessage[++written];
            va_start(args, message);
            vsnprintf(fmessage, sizeof(fmessage), message, args);

            clog_append_to_file(logger->log_file_path, location, "%s >> [ERROR] >> %s", logger->name, fmessage);
            va_end(args);
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
        clog_messagef(CLOG_LEVEL_CRITICAL, logger, location, message, args);
        va_end(args);

        // Error callback
        if (logger->error_callback)
        {
            logger->error_callback(CLOG_LEVEL_CRITICAL, logger->name, location);
        }
    }
}

#include "clog.h"
#include "ansi.h"

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <time.h>

static enum CLoggerBool debug = CLOG_DEBUG_DEFAULT; // Default value

void format_timestamp(char* buffer)
{
    char timestamp_buffer[10];
    time_t now = time(NULL);
    struct tm* timestamp = localtime(&now);

    strftime(timestamp_buffer, sizeof timestamp_buffer, "%H:%M:%S", timestamp);

    strcpy(buffer, timestamp_buffer);
}

void clog_messagef(const char* location, const char* format, va_list args)
{
    char timestamp[10];

    format_timestamp(timestamp);

    printf(CLOGGER_FG_BOLD_CYN"%s"CLOGGER_RESET_CONSOLE" >> "CLOGGER_FG_BOLD_MAG"%s"CLOGGER_RESET_CONSOLE" >> ", timestamp, location);

    vprintf(format, args);
    printf(CLOGGER_RESET_CONSOLE"\n");
}

void clog_message(const char* location, const char* message, ...)
{
    va_list args;

    va_start(args, message);
    clog_messagef(location, message, args);
    va_end(args);
}

void clog_info(const char* location, const char* message, ...)
{
    if (debug)
    {
        printf(CLOGGER_FG_HBLU"[INFO]"CLOGGER_RESET_CONSOLE" >> ");

        va_list args;

        va_start(args, message);
        clog_messagef(location, message, args);
        va_end(args);
    }
}

void clog_debug(const char* location, const char* message, ...)
{
    if (debug)
    {
        printf(CLOGGER_FG_HGRN"[DEBUG]"CLOGGER_RESET_CONSOLE" >> ");

        va_list args;

        va_start(args, message);
        clog_messagef(location, message, args);
        va_end(args);
    }
}

void clog_warning(const char* location, const char* message, ...)
{
    printf(CLOGGER_FG_HYEL"[WARNING]"CLOGGER_RESET_CONSOLE" >> ");

    va_list args;

    va_start(args, message);
    clog_messagef(location, message, args);
    va_end(args);
}

void clog_error(const char* location, const char* message, ...)
{
    printf(CLOGGER_FG_HRED"[ERROR]"CLOGGER_RESET_CONSOLE" >> ");

    va_list args;

    va_start(args, message);
    clog_messagef(location, message, args);
    va_end(args);
}

void clog_fatal(const char* location, const char* message, ...)
{
    printf(CLOGGER_BG_RED"[FATAL]"CLOGGER_RESET_CONSOLE" >> ");

    va_list args;

    va_start(args, message);
    clog_messagef(location, message, args);
    va_end(args);
}

int clog_to_file(const char* file_path, const char* location, const char* message)
{
    enum CLoggerBool result = CLOGGER_FALSE;
    FILE* file_ptr;

    file_ptr = fopen(file_path, "a+");

    if (file_ptr != NULL)
    {
        char timestamp[10];

        format_timestamp(timestamp);

        fputs(timestamp, file_ptr);
        fputs(" >> ", file_ptr);
        fputs(location, file_ptr);
        fputs(" >> ", file_ptr);
        fputs(message, file_ptr);
        fputs("\n", file_ptr);

        result = CLOGGER_TRUE;

        fclose(file_ptr);
    }
    else
    {
        char* exc = "Could not open ";

        unsigned int error_length = strlen(exc) + strlen(file_path);
        char error[error_length];

        for (int i = 0; i < error_length; ++i)
        {
            if (i < strlen(exc))
            {
                error[i] = (char)exc[i];
            }
            else
            {
                error[i] = (char)file_path[i - strlen(exc)];
            }
        }

        perror(error);
    }

    return result;
}

void set_clogger_debug(enum CLoggerBool value)
{
    debug = value;
}


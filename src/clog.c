#include "clog.h"
#include "ansi.h"

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <time.h>

static clog_bool debug_mode = CLOG_DEBUG_DEFAULT; // Default value

void format_timestamp(char* buffer)
{
    char timestamp_buffer[10];
    time_t now = time(NULL);
    struct tm* timestamp = localtime(&now);

    strftime(timestamp_buffer, sizeof timestamp_buffer, "%H:%M:%S", timestamp);

    strcpy(buffer, timestamp_buffer);
}

int clog_messagef(const char* location, const char* format, va_list args)
{
    int chars_written = 0;
    char timestamp[10];

    format_timestamp(timestamp);

    chars_written += printf(
            CLOGGER_FG_BOLD_CYN"%s"CLOGGER_RESET_CONSOLE" >> "CLOGGER_FG_BOLD_MAG"%s"CLOGGER_RESET_CONSOLE" >> ",
            timestamp, location);

    chars_written += vprintf(format, args);
    chars_written += printf(CLOGGER_RESET_CONSOLE"\n");

    return chars_written;
}

int clog_message(const char* location, const char* message, ...)
{
    int chars_written = 0;
    va_list args;

    va_start(args, message);
    chars_written += clog_messagef(location, message, args);
    va_end(args);

    return chars_written;
}

int clog_info(const char* location, const char* message, ...)
{
    int chars_written = 0;

    if (debug_mode)
    {
        va_list args;

        chars_written += printf(CLOGGER_FG_HBLU"[INFO]"CLOGGER_RESET_CONSOLE" >> ");

        va_start(args, message);
        chars_written += clog_messagef(location, message, args);
        va_end(args);
    }

    return chars_written;
}

int clog_debug(const char* location, const char* message, ...)
{
    int chars_written = 0;

    if (debug_mode)
    {
        va_list args;

        chars_written += printf(CLOGGER_FG_HGRN"[DEBUG]"CLOGGER_RESET_CONSOLE" >> ");

        va_start(args, message);
        chars_written += clog_messagef(location, message, args);
        va_end(args);
    }

    return chars_written;
}

int clog_warning(const char* location, const char* message, ...)
{
    int chars_written = 0;
    va_list args;

    chars_written += printf(CLOGGER_FG_HYEL"[WARNING]"CLOGGER_RESET_CONSOLE" >> ");

    va_start(args, message);
    chars_written += clog_messagef(location, message, args);
    va_end(args);

    return chars_written;
}

int clog_error(const char* location, const char* message, ...)
{
    int chars_written = 0;
    va_list args;

    chars_written += printf(CLOGGER_FG_HRED"[ERROR]"CLOGGER_RESET_CONSOLE" >> ");

    va_start(args, message);
    chars_written += clog_messagef(location, message, args);
    va_end(args);

    return chars_written;
}

int clog_fatal(const char* location, const char* message, ...)
{
    int chars_written = 0;
    va_list args;

    chars_written += printf(CLOGGER_BG_RED"[FATAL]"CLOGGER_RESET_CONSOLE" >> ");

    va_start(args, message);
    chars_written += clog_messagef(location, message, args);
    va_end(args);

    return chars_written;
}

void clog_trace(const char* function_name, const char* file_name, int line)
{
    printf("Traceback:\n\tIn function: %s >> %s:%d\n", function_name, file_name, line);
}

clog_bool clog_to_file(const char* file_path, const char* location, const char* message)
{
    clog_bool result = CLOGGER_FALSE;
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
        perror(file_path);
        clog_error(__FUNCTION__, "Could not open file %s", file_path);
    }

    return result;
}

void set_clogger_debug(clog_bool value)
{
    debug_mode = value;
}


#include "clogger/clog.h"
#include "clogger/console.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <time.h>

typedef struct thread_args
{
    clog_level level;
    const char* location;
    clogger* logger;
    const char* format;
    va_list* args;
} thread_args;

void format_timestamp(char* buffer)
{
    char timestamp_buffer[10];
    time_t now = time(NULL);
    struct tm* timestamp = localtime(&now);

    strftime(timestamp_buffer, sizeof timestamp_buffer, "%H:%M:%S", timestamp);

    strncpy(buffer, timestamp_buffer, sizeof(timestamp_buffer));
}

void* clog_message_thread(void* args)
{
    thread_args* arguments = (thread_args*) args;

    clog_messagef(arguments->level, arguments->logger, arguments->location, arguments->format, *arguments->args);

    pthread_exit(NULL);
    return NULL;
}

void clog_messagef(clog_level level, clogger* logger, const char* location, const char* format, va_list args)
{
    char timestamp[10];
    const char separator[] = " >> ";

    format_timestamp(timestamp);

    // Timestamp
    clog_set_console_colour((clog_console_colour) {Cyan, Clear}, CLOGGER_FOREGROUND_INTENSE);
    printf("%s", timestamp);
    clog_reset_console_colour();

    printf("%s", separator);

    // Logger name
    if (logger != NULL)
    {
        clog_set_console_colour(logger->colour, logger->colour_flags);
        printf("%s", logger->name);
        clog_reset_console_colour();

        printf("%s", separator);
    }

    // Log level
    switch (level)
    {
        case clog_level_info:
            clog_set_console_colour((clog_console_colour) {Blue, Clear}, CLOGGER_FOREGROUND_INTENSE);
            printf("[INFO]");
            clog_reset_console_colour();

            printf("%s", separator);
            break;
        case clog_level_debug:
            clog_set_console_colour((clog_console_colour) {Green, Clear}, CLOGGER_FOREGROUND_INTENSE);
            printf("[DEBUG]");
            clog_reset_console_colour();

            printf("%s", separator);
        case clog_level_warning:
            clog_set_console_colour((clog_console_colour) {Yellow, Clear}, CLOGGER_FOREGROUND_INTENSE);
            printf("[WARNING]");
            clog_reset_console_colour();

            printf("%s", separator);
            break;
        case clog_level_error:
            clog_set_console_colour((clog_console_colour) {Red, Clear}, CLOGGER_FOREGROUND_INTENSE);
            printf("[ERROR]");
            clog_reset_console_colour();

            printf("%s", separator);
            break;
        case clog_level_critical:
            clog_set_console_colour((clog_console_colour) {White, Red},
                                    CLOGGER_FOREGROUND_INTENSE | CLOGGER_BACKGROUND_INTENSE);
            printf("[CRITICAL]");
            clog_reset_console_colour();

            printf("%s", separator);
            break;
        default:
            break;
    }

    // Location
    clog_set_console_colour((clog_console_colour) {Magenta, Clear}, CLOGGER_FOREGROUND_INTENSE);
    printf("%s", location);
    clog_reset_console_colour();

    printf("%s", separator);

    vprintf(format, args);
    printf("\n");
}

pthread_t clog_messagef_async(clog_level level, clogger* logger, const char* location, const char* format, va_list args)
{
    pthread_t thread;

    thread_args arguments = {level, location, logger, format, (va_list*) &args};

    pthread_create(&thread, NULL, clog_message_thread, &arguments);

    return thread;
}

void clog_message(const char* location, const char* message, ...)
{
    va_list args;

    va_start(args, message);
    clog_messagef(clog_level_message, NULL, location, message, args);
    va_end(args);
}

void clog_info(const char* location, const char* message, ...)
{
    va_list args;

    va_start(args, message);
    clog_messagef(clog_level_info, NULL, location, message, args);
    va_end(args);
}

void clog_debug(const char* location, const char* message, ...)
{
    va_list args;

    va_start(args, message);
    clog_messagef(clog_level_debug, NULL, location, message, args);
    va_end(args);
}

void clog_warning(const char* location, const char* message, ...)
{
    va_list args;

    va_start(args, message);
    clog_messagef(clog_level_warning, NULL, location, message, args);
    va_end(args);
}

void clog_error(const char* location, const char* message, ...)
{
    va_list args;

    va_start(args, message);
    clog_messagef(clog_level_error, NULL, location, message, args);
    va_end(args);
}

void clog_critical(const char* location, const char* message, ...)
{
    va_list args;

    va_start(args, message);
    clog_messagef(clog_level_critical, NULL, location, message, args);
    va_end(args);
}

pthread_t clog_message_async(const char* location, const char* message, ...)
{
    pthread_t thread;
    va_list args;

    va_start(args, message);
    thread = (pthread_t) clog_messagef_async(clog_level_message, NULL, location, message, args);
    va_end(args);

    return thread;
}

pthread_t clog_info_async(const char* location, const char* message, ...)
{
    pthread_t thread;
    va_list args;

    va_start(args, message);
    thread = (pthread_t) clog_messagef_async(clog_level_info, NULL, location, message, args);
    va_end(args);

    return thread;
}

pthread_t clog_debug_async(const char* location, const char* message, ...)
{
    pthread_t thread;
    va_list args;

    va_start(args, message);
    thread = (pthread_t) clog_messagef_async(clog_level_debug, NULL, location, message, args);
    va_end(args);

    return thread;
}

pthread_t clog_warning_async(const char* location, const char* message, ...)
{
    pthread_t thread;
    va_list args;

    va_start(args, message);
    thread = (pthread_t) clog_messagef_async(clog_level_warning, NULL, location, message, args);
    va_end(args);

    return thread;
}

pthread_t clog_error_async(const char* location, const char* message, ...)
{
    pthread_t thread;
    va_list args;

    va_start(args, message);
    thread = (pthread_t) clog_messagef_async(clog_level_error, NULL, location, message, args);
    va_end(args);

    return thread;
}

pthread_t clog_critical_async(const char* location, const char* message, ...)
{
    pthread_t thread;
    va_list args;

    va_start(args, message);
    thread = (pthread_t) clog_messagef_async(clog_level_critical, NULL, location, message, args);
    va_end(args);

    return thread;
}

void clog_trace(const char* function_name, const char* file_name, int line)
{
    printf("Traceback:\n\tIn function: %s >> %s:%d\n", function_name, file_name, line);
}

void clog_assert(int condition, const char* location, const char* message, ...)
{
    if (!condition)
    {
        va_list args;

        clog_set_console_colour((clog_console_colour) {White, Red},
                                CLOGGER_FOREGROUND_INTENSE | CLOGGER_BACKGROUND_INTENSE);
        printf("[ASSERT FAILED]");
        clog_reset_console_colour();

        printf(" >> ");

        va_start(args, message);
        clog_messagef(clog_level_message, NULL, location, message, args);
        va_end(args);

        abort();
    }
}

clog_bool clog_to_file(const char* file_path, const char* location, const char* message, ...)
{
    va_list args;

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

        va_start(args, message);
        vfprintf(file_ptr, message, args);
        va_end(args);

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


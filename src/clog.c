#include "clogger/clog.h"
#include "clogger/console.h"

#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <time.h>

typedef struct thread_args
{
    clog_level_t level;
    const char* location;
    clogger_t* logger;
    const char* format;
    va_list* args;
} thread_args_t;

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
    thread_args_t* arguments = (thread_args_t*) args;

    clog_messagef(arguments->level, arguments->logger, arguments->location, arguments->format, *arguments->args);

    pthread_exit(NULL);
    return NULL;
}

void clog_messagef(clog_level_t level, clogger_t* logger, const char* location, const char* format, va_list args)
{
    char timestamp[10];
    const char separator[] = " >> ";

    format_timestamp(timestamp);

    // Timestamp
    clog_set_console_colour((clog_console_colour_t) {CYAN, CLEAR}, CLOGGER_FOREGROUND_INTENSE);
    printf("%s", timestamp);
    clog_reset_console_colour();

    printf("%s", separator);

    // Logger name
    if (logger != NULL)
    {
        clog_set_console_colour(logger->console_colour, logger->colour_flags);
        printf("%s", logger->name);
        clog_reset_console_colour();

        printf("%s", separator);
    }

    // Log level
    switch (level)
    {
        case CLOG_LEVEL_INFO:
            clog_set_console_colour((clog_console_colour_t) {BLUE, CLEAR}, CLOGGER_FOREGROUND_INTENSE);
            printf("[INFO]");
            clog_reset_console_colour();

            printf("%s", separator);
            break;
        case CLOG_LEVEL_DEBUG:
            clog_set_console_colour((clog_console_colour_t) {GREEN, CLEAR}, CLOGGER_FOREGROUND_INTENSE);
            printf("[DEBUG]");
            clog_reset_console_colour();

            printf("%s", separator);
            break;
        case CLOG_LEVEL_WARNING:
            clog_set_console_colour((clog_console_colour_t) {YELLOW, CLEAR}, CLOGGER_FOREGROUND_INTENSE);
            printf("[WARNING]");
            clog_reset_console_colour();

            printf("%s", separator);
            break;
        case CLOG_LEVEL_ERROR:
            clog_set_console_colour((clog_console_colour_t) {RED, CLEAR}, CLOGGER_FOREGROUND_INTENSE);
            printf("[ERROR]");
            clog_reset_console_colour();

            printf("%s", separator);
            break;
        case CLOG_LEVEL_CRITICAL:
            clog_set_console_colour((clog_console_colour_t) {WHITE, RED},
                                    CLOGGER_FOREGROUND_INTENSE | CLOGGER_BACKGROUND_INTENSE);
            printf("[CRITICAL]");
            clog_reset_console_colour();

            printf("%s", separator);
            break;
        default:
            break;
    }

    // Location
    clog_set_console_colour((clog_console_colour_t) {MAGENTA, CLEAR}, CLOGGER_FOREGROUND_INTENSE);
    printf("%s", location);
    clog_reset_console_colour();

    printf("%s", separator);

    vprintf(format, args);
    printf("\n");
}

pthread_t clog_messagef_async(clog_level_t level, clogger_t* logger, const char* location, const char* format, va_list args)
{
    pthread_t thread;

    thread_args_t arguments = {level, location, logger, format, (va_list*) &args};

    pthread_create(&thread, NULL, clog_message_thread, &arguments);

    return thread;
}

void clog_message(const char* location, const char* message, ...)
{
    va_list args;

    va_start(args, message);
    clog_messagef(CLOG_LEVEL_MESSAGE, NULL, location, message, args);
    va_end(args);
}

void clog_info(const char* location, const char* message, ...)
{
    va_list args;

    va_start(args, message);
    clog_messagef(CLOG_LEVEL_INFO, NULL, location, message, args);
    va_end(args);
}

void clog_debug(const char* location, const char* message, ...)
{
    va_list args;

    va_start(args, message);
    clog_messagef(CLOG_LEVEL_DEBUG, NULL, location, message, args);
    va_end(args);
}

void clog_warning(const char* location, const char* message, ...)
{
    va_list args;

    va_start(args, message);
    clog_messagef(CLOG_LEVEL_WARNING, NULL, location, message, args);
    va_end(args);
}

void clog_error(const char* location, const char* message, ...)
{
    va_list args;

    va_start(args, message);
    clog_messagef(CLOG_LEVEL_ERROR, NULL, location, message, args);
    va_end(args);
}

void clog_critical(const char* location, const char* message, ...)
{
    va_list args;

    va_start(args, message);
    clog_messagef(CLOG_LEVEL_CRITICAL, NULL, location, message, args);
    va_end(args);
}

pthread_t clog_message_async(const char* location, const char* message, ...)
{
    pthread_t thread;
    va_list args;

    va_start(args, message);
    thread = (pthread_t) clog_messagef_async(CLOG_LEVEL_MESSAGE, NULL, location, message, args);
    va_end(args);

    return thread;
}

pthread_t clog_info_async(const char* location, const char* message, ...)
{
    pthread_t thread;
    va_list args;

    va_start(args, message);
    thread = (pthread_t) clog_messagef_async(CLOG_LEVEL_INFO, NULL, location, message, args);
    va_end(args);

    return thread;
}

pthread_t clog_debug_async(const char* location, const char* message, ...)
{
    pthread_t thread;
    va_list args;

    va_start(args, message);
    thread = (pthread_t) clog_messagef_async(CLOG_LEVEL_DEBUG, NULL, location, message, args);
    va_end(args);

    return thread;
}

pthread_t clog_warning_async(const char* location, const char* message, ...)
{
    pthread_t thread;
    va_list args;

    va_start(args, message);
    thread = (pthread_t) clog_messagef_async(CLOG_LEVEL_WARNING, NULL, location, message, args);
    va_end(args);

    return thread;
}

pthread_t clog_error_async(const char* location, const char* message, ...)
{
    pthread_t thread;
    va_list args;

    va_start(args, message);
    thread = (pthread_t) clog_messagef_async(CLOG_LEVEL_ERROR, NULL, location, message, args);
    va_end(args);

    return thread;
}

pthread_t clog_critical_async(const char* location, const char* message, ...)
{
    pthread_t thread;
    va_list args;

    va_start(args, message);
    thread = (pthread_t) clog_messagef_async(CLOG_LEVEL_CRITICAL, NULL, location, message, args);
    va_end(args);

    return thread;
}

void clog_trace(const char* function_name, const char* file_name, int line)
{
    printf("Traceback:\n\tIn function: %s >> %s:%d\n", function_name, file_name, line);
}



int clog_to_file(const char* file_path, const char* location, const char* message, ...)
{
    va_list args;

    int result = CLOGGER_FALSE;
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


#ifndef CLOGGER_CORE_H
#define CLOGGER_CORE_H

#define CLOGGER_FALSE 0
#define CLOGGER_TRUE 1

#ifdef __cplusplus
extern "C" {
#endif

typedef enum clog_level
{
    CLOG_LEVEL_MESSAGE,
    CLOG_LEVEL_INFO,
    CLOG_LEVEL_DEBUG,
    CLOG_LEVEL_WARNING,
    CLOG_LEVEL_ERROR,
    CLOG_LEVEL_CRITICAL,
    CLOG_LEVEL_FATAL_ASSERT,
    CLOG_LEVEL_NON_FATAL_ASSERT
} clog_level_t;

typedef enum clog_colour
{
    CLEAR, BLACK, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE
} clog_colour_t;

typedef struct clog_console_colour
{
    clog_colour_t foreground_colour;
    clog_colour_t background_colour;
} clog_console_colour_t;

typedef struct clogger
{
    const char* name;
    void (* error_callback)(clog_level_t level, const char* clogger_name, const char* location);
    // void (* error_callback_async)(const clog_thread* thread, const char* clogger_name, const char* location);
    clog_console_colour_t console_colour;
    clog_level_t log_level;
    unsigned short colour_flags;
} clogger_t;

#ifdef __cplusplus
}
#endif

#endif //CLOGGER_CORE_H

#ifndef CLOGGER_CORE_H
#define CLOGGER_CORE_H

#define CLOGGER_FALSE 0
#define CLOGGER_TRUE 1

#ifdef __cplusplus
extern "C" {
#endif

typedef enum clog_level
{
    clog_level_message, clog_level_info, clog_level_debug, clog_level_warning, clog_level_error, clog_level_critical
} clog_level_t;

typedef enum clog_colour
{
    Clear, Black, Red, Green, Yellow, Blue, Magenta, Cyan, White
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

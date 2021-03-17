#ifndef CLOGGER_CORE_H
#define CLOGGER_CORE_H

#define CLOGGER_FALSE 0
#define CLOGGER_TRUE 1

#ifdef __cplusplus
#define CLOGGER_API extern "C"
#else
#define CLOGGER_API
#endif

typedef enum clog_bool
{
    clog_false = CLOGGER_FALSE, clog_true = CLOGGER_TRUE
} clog_bool;

typedef enum clog_level
{
    clog_level_message, clog_level_info, clog_level_debug, clog_level_warning, clog_level_error, clog_level_critical
} clog_level;

typedef enum clog_colour
{
    Clear, Black, Red, Green, Yellow, Blue, Magenta, Cyan, White
} clog_colour;

typedef struct clog_console_colour
{
    clog_colour foreground_colour;
    clog_colour background_colour;
} clog_console_colour;

typedef struct clogger
{
    const char* name;
    void (* error_callback)(clog_level level, const char* clogger_name, const char* location);
    // void (* error_callback_async)(const clog_thread* thread, const char* clogger_name, const char* location);
    clog_console_colour colour;
    clog_level log_level;
    unsigned short colour_flags;
} clogger;

#endif //CLOGGER_CORE_H

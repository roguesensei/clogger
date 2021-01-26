#ifndef CLOGGER_CLOG_H
#define CLOGGER_CLOG_H

#define CLOGGER_FALSE 0
#define CLOGGER_TRUE 1

#ifdef CLOGGER_DEBUG
    #define CLOG_DEBUG_DEFAULT CLOGGER_TRUE
#else
    #define CLOG_DEBUG_DEFAULT CLOGGER_FALSE
#endif

#ifdef __cplusplus
    #define CLOGGER_API extern "C"
#else
    #define CLOGGER_API
#endif

enum CLoggerBool
{
    CLogFalse = CLOGGER_FALSE, CLogTrue = CLOGGER_TRUE
};

typedef enum CLoggerBool clog_bool;

// Generic logging message
CLOGGER_API int clog_message(const char* location, const char* format, ...);

// Pre-defined log functions by level, where info/debug can be configured to display only in debug mode
CLOGGER_API int clog_info(const char* location, const char* message, ...);
CLOGGER_API int clog_debug(const char* location, const char* message, ...);
CLOGGER_API int clog_warning(const char* location, const char* message, ...);
CLOGGER_API int clog_error(const char* location, const char* message, ...);
CLOGGER_API int clog_fatal(const char* location, const char* message, ...);

// Displays a traceback message
CLOGGER_API void clog_trace(const char* function_name, const char* file_name, int line);
// Shorthand macros
#define CLOGGER_TRACE() clog_trace(__FUNCTION__, __FILE__, __LINE__)
#define CLOGGER_TRACE_LINE(line) clog_trace(__FUNCTION__, __FILE__, line)

// Log message to file: returns CLOGGER_FALSE if the file is not found etc. else CLOGGER_TRUE
CLOGGER_API clog_bool clog_to_file(const char* file_path, const char* location, const char* message);

// Toggle whether or not INFO/DEBUG messages should be shown
CLOGGER_API void set_clogger_debug(clog_bool value);

#endif //CLOGGER_CLOG_H

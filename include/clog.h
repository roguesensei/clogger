#ifndef CLOGGER_CLOG_H
#define CLOGGER_CLOG_H

#ifdef CLOGGER_DEBUG
    #define CLOG_DEBUG_DEFAULT 1
#else
    #define CLOG_DEBUG_DEFAULT 0
#endif

#ifdef __cplusplus
#define CLOGGER_API extern "C"
#else
#define CLOGGER_API
#endif

enum CLoggerDebugMode
{
    CLogFalse = 0,
    CLogTrue = 1
};

// Generic logging message
CLOGGER_API void clog_message(const char* location, const char* format, ...);

// Pre-defined log functions by level, where info/debug can be configured to display only in debug mode
CLOGGER_API void clog_info(const char* location, const char* message, ...);
CLOGGER_API void clog_debug(const char* location, const char* message, ...);
CLOGGER_API void clog_warning(const char* location, const char* message, ...);
CLOGGER_API void clog_error(const char* location, const char* message, ...);
CLOGGER_API void clog_fatal(const char* location, const char* message, ...);

// Toggle whether or not INFO/DEBUG messages should be shown
CLOGGER_API void set_clogger_debug(enum CLoggerDebugMode value);

#endif //CLOGGER_CLOG_H

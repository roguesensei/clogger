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

// Generic logging message
CLOGGER_API void clog_message(const char* location, const char* format, ...);

// Pre-defined log functions by level, where info/debug can be configured to display only in debug mode
CLOGGER_API void clog_info(const char* location, const char* message, ...);
CLOGGER_API void clog_debug(const char* location, const char* message, ...);
CLOGGER_API void clog_warning(const char* location, const char* message, ...);
CLOGGER_API void clog_error(const char* location, const char* message, ...);
CLOGGER_API void clog_fatal(const char* location, const char* message, ...);

// Log message to file: returns CLOGGER_FALSE if the file is not found etc. else CLOGGER_TRUE
CLOGGER_API int clog_to_file(const char* file_path, const char* location, const char* message);

// Toggle whether or not INFO/DEBUG messages should be shown
CLOGGER_API void set_clogger_debug(enum CLoggerBool value);

#endif //CLOGGER_CLOG_H

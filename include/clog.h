#ifndef CLOGGER_CLOG_H
#define CLOGGER_CLOG_H

enum CLoggerDebugMode
{
    CLogFalse = 0,
    CLogTrue = 1
};

#ifdef CLOGGER_DEBUG
    #define CLOG_DEBUG_DEFAULT 1
#else
    #define CLOG_DEBUG_DEFAULT 0
#endif

// Generic logging message
void clog_message(const char* location, char* format, ...);

// Pre-defined log functions by level, where info/debug can be configured to display only in debug mode
void clog_info(const char* location, char* message, ...);
void clog_debug(const char* location, char* message, ...);
void clog_warning(const char* location, char* message, ...);
void clog_error(const char* location, char* message, ...);
void clog_fatal(const char* location, char* message, ...);

// Toggle whether or not INFO/DEBUG messages should be shown
void set_clogger_debug(enum CLoggerDebugMode value);

#endif //CLOGGER_CLOG_H

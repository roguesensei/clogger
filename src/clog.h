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

void clog_info(const char* location, char* format, ...);
void clog_debug(const char* location, char* format, ...);
void clog_warning(const char* location, char* format, ...);
void clog_error(const char* location, char* format, ...);
void clog_fatal(const char* location, char* format, ...);

// Toggle whether or not INFO/DEBUG messages should be shown
void set_clogger_debug(enum CLoggerDebugMode value);

#endif //CLOGGER_CLOG_H

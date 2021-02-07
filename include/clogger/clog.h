#ifndef CLOGGER_CLOG_H
#define CLOGGER_CLOG_H

#include "core.h"

// Generic logging message
CLOGGER_API int clog_message(const char* location, const char* format, ...);

// Pre-defined log functions by level, where info/debug can be configured to display only in debug mode
CLOGGER_API int clog_info(const char* location, const char* message, ...);
CLOGGER_API int clog_debug(const char* location, const char* message, ...);
CLOGGER_API int clog_warning(const char* location, const char* message, ...);
CLOGGER_API int clog_error(const char* location, const char* message, ...);
CLOGGER_API int clog_critical(const char* location, const char* message, ...);

// Displays a traceback message
CLOGGER_API void clog_trace(const char* function_name, const char* file_name, int line);
// Shorthand macros
#define CLOGGER_TRACE() clog_trace(__FUNCTION__, __FILE__, __LINE__)
#define CLOGGER_TRACE_LINE(line) clog_trace(__FUNCTION__, __FILE__, line)

// Assert function
CLOGGER_API void clog_assert(int condition, const char* location, const char* message, ...);

// Log message to file: returns CLOGGER_FALSE if the file is not found etc. else CLOGGER_TRUE
CLOGGER_API clog_bool clog_to_file(const char* file_path, const char* location, const char* message);

// Toggle whether or not INFO/DEBUG messages should be shown
CLOGGER_API void set_clogger_debug(clog_bool value);

#endif //CLOGGER_CLOG_H

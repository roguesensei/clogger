#ifndef CLOGGER_CLOG_H
#define CLOGGER_CLOG_H

#include <pthread.h>
#include <stdarg.h>

#include "core.h"

// Formatter sync/async
CLOGGER_API void clog_messagef(clog_level level, clogger* logger, const char* location, const char* format, va_list args);
CLOGGER_API pthread_t clog_messagef_async(clog_level level, clogger* logger, const char* location, const char* format, va_list args);

// Generic logging message
CLOGGER_API void clog_message(const char* location, const char* message, ...);

// Pre-defined log functions by level, where info/debug can be configured to display only in debug mode
CLOGGER_API void clog_info(const char* location, const char* message, ...);
CLOGGER_API void clog_debug(const char* location, const char* message, ...);
CLOGGER_API void clog_warning(const char* location, const char* message, ...);
CLOGGER_API void clog_error(const char* location, const char* message, ...);
CLOGGER_API void clog_critical(const char* location, const char* message, ...);

// Asynchronous varients
CLOGGER_API pthread_t clog_message_async(const char* location, const char* message, ...);
CLOGGER_API pthread_t clog_info_async(const char* location, const char* message, ...);
CLOGGER_API pthread_t clog_debug_async(const char* location, const char* message, ...);
CLOGGER_API pthread_t clog_warning_async(const char* location, const char* message, ...);
CLOGGER_API pthread_t clog_error_async(const char* location, const char* message, ...);
CLOGGER_API pthread_t clog_critical_async(const char* location, const char* message, ...);

// Displays a traceback message
CLOGGER_API void clog_trace(const char* function_name, const char* file_name, int line);
// Shorthand macros
#define CLOGGER_TRACE() clog_trace(__FUNCTION__, __FILE__, __LINE__)
#define CLOGGER_TRACE_LINE(line) clog_trace(__FUNCTION__, __FILE__, line)

// Assert function
CLOGGER_API void clog_assert(int condition, const char* location, const char* message, ...);

// Log message to file: returns CLOGGER_FALSE if the file is not found etc. else CLOGGER_TRUE
CLOGGER_API clog_bool clog_to_file(const char* file_path, const char* location, const char* message, ...);

#endif //CLOGGER_CLOG_H

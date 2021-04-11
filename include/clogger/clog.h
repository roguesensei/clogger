#ifndef CLOGGER_CLOG_H
#define CLOGGER_CLOG_H

#ifdef __cplusplus
extern "C" {
#endif

#include <pthread.h>
#include <stdarg.h>

#include "core.h"

// Formatter sync/async
void clog_messagef(clog_level_t level, clogger_t* logger, const char* location, const char* format, va_list args);
pthread_t clog_messagef_async(clog_level_t level, clogger_t* logger, const char* location, const char* format, va_list args);

// Generic logging message
void clog_message(const char* location, const char* message, ...);

// Pre-defined log functions by level, where info/debug can be configured to display only in debug mode
void clog_info(const char* location, const char* message, ...);
void clog_debug(const char* location, const char* message, ...);
void clog_warning(const char* location, const char* message, ...);
void clog_error(const char* location, const char* message, ...);
void clog_critical(const char* location, const char* message, ...);

// Asynchronous varients
pthread_t clog_message_async(const char* location, const char* message, ...);
pthread_t clog_info_async(const char* location, const char* message, ...);
pthread_t clog_debug_async(const char* location, const char* message, ...);
pthread_t clog_warning_async(const char* location, const char* message, ...);
pthread_t clog_error_async(const char* location, const char* message, ...);
pthread_t clog_critical_async(const char* location, const char* message, ...);

// Displays a traceback message
void clog_trace(const char* function_name, const char* file_name, int line);
// Shorthand macros
#define CLOGGER_TRACE() clog_trace(__FUNCTION__, __FILE__, __LINE__)
#define CLOGGER_TRACE_LINE(line) clog_trace(__FUNCTION__, __FILE__, line)



// Log message to file: returns CLOGGER_FALSE if the file is not found etc. else CLOGGER_TRUE
int clog_to_file(const char* file_path, const char* location, const char* message, ...);

#ifdef __cplusplus
}
#endif

#endif //CLOGGER_CLOG_H

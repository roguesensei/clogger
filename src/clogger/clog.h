//! @file
//! @brief Standard log functions

#ifndef CLOGGER_CLOG_H
#define CLOGGER_CLOG_H

#ifdef __cplusplus
extern "C" {
#endif

#include <pthread.h>
#include <stdarg.h>

#include "core.h"

/// @brief The common log function used throughout
/// @note This function isn't typically used by the end user, it's advisable to use the standard functions
/// @param level [in] The log level
/// @param logger [in] Pointer to a `clogger_t` data structure. Pass `NULL` if not used
/// @param location [in] Location of the log, usually `__FUNCTION__` though can be `NULL`
/// @param format [in] String detailing the format
/// @param args [in] Variable arguments list to use with the `format` string
void clog_messagef(clog_level_t level, clogger_t* logger, const char* location, const char* format, va_list args);

/// @brief Asynchronous variant of `clog_messagef()`
/// @note This function isn't typically used by the end user, it's advisable to use the standard functions
/// @param level [in] The log level
/// @param logger [in] Pointer to a `clogger_t` data structure. Pass `NULL` if not used
/// @param location [in] Location of the log, usually `__FUNCTION__` though can be `NULL`
/// @param format [in] String detailing the format
/// @param args [in] Variable arguments list to use with the `format` string
/// @return Thread of the function so it can be joined/awaited
pthread_t clog_messagef_async(clog_level_t level, clogger_t* logger, const char* location, const char* format, va_list args);

/// @brief The generic logging message
/// @param location [in] Location of the log, usually `__FUNCTION__` though can be `NULL`
/// @param message [in] Format-able string message as you would use `printf()`
/// @param ... [in] Variable-length args for the `message` string
void clog_message(const char* location, const char* message, ...);

/// @brief Log a message representing a `CLOG_LEVEL_INFO` level message
/// @param location [in] Location of the log
/// @param message [in] Format-able string message as you would use `printf()`
/// @param ... [in] Variable-length args
void clog_info(const char* location, const char* message, ...);

/// @brief Log a message representing a `CLOG_LEVEL_DEBUG` level message
/// @param location [in] Location of the log
/// @param message [in] Format-able string message as you would use `printf()`
/// @param ... [in] Variable-length args
void clog_debug(const char* location, const char* message, ...);

/// @brief Log a message representing a `CLOG_LEVEL_WARNING` level message
/// @param location [in] Location of the log,
/// @param message [in] Format-able string message as you would use `printf()`
/// @param ... [in] Variable-length args
void clog_warning(const char* location, const char* message, ...);

/// @brief Log a message representing a `CLOG_LEVEL_ERROR` level message
/// @param location [in] Location of the log
/// @param message [in] Format-able string message as you would use `printf()`
/// @param ... [in] Variable-length args
void clog_error(const char* location, const char* message, ...);

/// @brief Log a message representing a `CLOG_LEVEL_CRITICAL` level message
/// @param location [in] Location of the log
/// @param message [in] Format-able string message as you would use `printf()`
/// @param ... [in] Variable-length args
void clog_critical(const char* location, const char* message, ...);

/// @brief Asynchronous variant of `clog_message()`
/// @param location [in] Location of the log
/// @param message [in] Format-able string message as you would use `printf()`
/// @param ... [in] Variable-length args
/// @return Thread of the function so it can be joined/awaited
pthread_t clog_message_async(const char* location, const char* message, ...);

/// @brief Asynchronous variant of `clog_info()`
/// @param location [in] Location of the log
/// @param message [in] Format-able string message as you would use `printf()`
/// @param ... [in] Variable-length args
/// @return Thread of the function so it can be joined/awaited
pthread_t clog_info_async(const char* location, const char* message, ...);

/// @brief Asynchronous variant of `clog_debug()`
/// @param location [in] Location of the log
/// @param message [in] Format-able string message as you would use `printf()`
/// @param ... [in] Variable-length args
/// @return Thread of the function so it can be joined/awaited
pthread_t clog_debug_async(const char* location, const char* message, ...);

/// @brief Asynchronous variant of `clog_warning()`
/// @param location [in] Location of the log
/// @param message [in] Format-able string message as you would use `printf()`
/// @param ... [in] Variable-length args
/// @return Thread of the function so it can be joined/awaited
pthread_t clog_warning_async(const char* location, const char* message, ...);

/// @brief Asynchronous variant of `clog_error()`
/// @param location [in] Location of the log
/// @param message [in] Format-able string message as you would use `printf()`
/// @param ... [in] Variable-length args
/// @return Thread of the function so it can be joined/awaited
pthread_t clog_error_async(const char* location, const char* message, ...);

/// @brief Asynchronous variant of `clog_critical()`
/// @param location [in] Location of the log
/// @param message [in] Format-able string message as you would use `printf()`
/// @param ... [in] Variable-length args
/// @return Thread of the function so it can be joined/awaited
pthread_t clog_critical_async(const char* location, const char* message, ...);

/// @brief Log message to file
/// @param file_path [in] The file path to dump the log message.
/// @deprecated Please use `clog_append_to_file()`
/// @param location [in] Location of the log
/// @param message [in] Format-able string message as you would use `printf()`
/// @param ... [in] Variable-length args
/// @return `CLOGGER_FALSE` on failure or `CLOGGER_TRUE` on success
int clog_to_file(const char* file_path, const char* location, const char* message, ...);

/// @brief Log message to file
/// @param file_path [in] The file path to dump the log message.
/// @warning This should be the path to the actual file e.g. `/logs/log.txt`
/// @param location [in] Location of the log
/// @param message [in] Format-able string message as you would use `printf()`
/// @param ... [in] Variable-length args
/// @return `CLOGGER_FALSE` on failure or `CLOGGER_TRUE` on success
int clog_append_to_file(const char* file_path, const char* location, const char* message, ...);

/// @brief Prepend log message to file
/// @param file_path [in] The file path to dump the log message.
/// @warning This should be the path to the actual file e.g. `/logs/log.txt`
/// @param location [in] Location of the log
/// @param message [in] Format-able string message as you would use `printf()`
/// @param ... [in] Variable-length args
/// @return `CLOGGER_FALSE` on failure or `CLOGGER_TRUE` on success
int clog_prepend_to_file(const char* file_path, const char* location, const char* message, ...);

/// @brief Displays a function traceback message
/// @details This should be used in sync with the error/critical functions to make debugging/tracing easier as they will not trace back themselves.
/// @param function_name [in] Name of the function, usually `__FUNCTION__`
/// @param file_name [in] Name of the file, usually `__FILE__`
/// @param line [in] The line number, usually `__LINE__` (or some variant)
/// @remarks In some IDEs, the traceback message printed to the console/terminal is clickable, allowing the end-user to jump to the point of interest.
void clog_trace(const char* function_name, const char* file_name, int line);

/// @brief Shorthand macro for `clog_trace`
#define CLOGGER_TRACE() clog_trace(__FUNCTION__, __FILE__, __LINE__)

/// @brief Shorthand macto for `clog_trace`, allowing line specification
#define CLOGGER_TRACE_LINE(line) clog_trace(__FUNCTION__, __FILE__, line)

#ifdef __cplusplus
}
#endif

#endif //CLOGGER_CLOG_H

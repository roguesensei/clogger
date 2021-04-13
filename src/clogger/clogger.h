//! @file
//! @brief File for use with the `clogger_t` structure

#ifndef CLOGGER_CLOGGER_H
#define CLOGGER_CLOGGER_H

#include "core.h"
#include "console.h"

#ifdef __cplusplus
extern "C" {
#endif

#include <pthread.h>

/// @brief Simplified `clogger_t` structure creation function
/// @param clogger_name [in] Name of the `clogger`
/// @return Initialized `clogger_t`
clogger_t make_clogger(const char* clogger_name);

/// @brief `CLOG_LEVEL_INFO` log message, will only call if the `clogger_t` struct is set as such
/// @param logger [in] Pointer to `clogger_t` data structure
/// @param location [in] Location of the log
/// @param message [in] Format-able string message as you would use `printf()`
/// @param ... [in] Variable-length args
void clogger_info(clogger_t* logger, const char* location, const char* message, ...);

/// @brief `CLOG_LEVEL_DEBUG` log message, will only call if the `clogger_t` struct is set as such
/// @param logger [in] Pointer to `clogger_t` data structure
/// @param location [in] Location of the log
/// @param message [in] Format-able string message as you would use `printf()`
/// @param ... [in] Variable-length args
void clogger_debug(clogger_t* logger, const char* location, const char* message, ...);

/// @brief `CLOG_LEVEL_WARNING` log message, will only call if the `clogger_t` struct is set as such
/// @param logger [in] Pointer to `clogger_t` data structure
/// @param location [in] Location of the log
/// @param message [in] Format-able string message as you would use `printf()`
/// @param ... [in] Variable-length args
void clogger_warning(clogger_t* logger, const char* location, const char* message, ...);

/// @brief `CLOG_LEVEL_ERROR` log message, will only call if the `clogger_t` struct is set as such
/// @param logger [in] Pointer to `clogger_t` data structure
/// @param location [in] Location of the log
/// @param message [in] Format-able string message as you would use `printf()`
/// @param ... [in] Variable-length args
void clogger_error(clogger_t* logger, const char* location, const char* message, ...);

/// @brief `CLOG_LEVEL_CRITICAL` log message, will only call if the `clogger_t` struct is set as such
/// @param logger [in] Pointer to `clogger_t` data structure
/// @param location [in] Location of the log
/// @param message [in] Format-able string message as you would use `printf()`
/// @param ... [in] Variable-length args
void clogger_critical(clogger_t* logger, const char* location, const char* message, ...);

/// @brief Asynchronous variant of `clogger_info()`
/// @param logger [in] Pointer to `clogger_t` data structure
/// @param location [in] Location of the log
/// @param message [in] Format-able string message as you would use `printf()`
/// @param ... [in] Variable-length args
/// @return Thread of the function so it can be joined/awaited
pthread_t clogger_info_async(clogger_t* logger, const char* location, const char* message, ...);

/// @brief Asynchronous variant of `clogger_debug()`
/// @param logger [in] Pointer to `clogger_t` data structure
/// @param location [in] Location of the log
/// @param message [in] Format-able string message as you would use `printf()`
/// @param ... [in] Variable-length args
/// @return Thread of the function so it can be joined/awaited
pthread_t clogger_debug_async(clogger_t* logger, const char* location, const char* message, ...);

/// @brief Asynchronous variant of `clogger_warning()`
/// @param logger [in] Pointer to `clogger_t` data structure
/// @param location [in] Location of the log
/// @param message [in] Format-able string message as you would use `printf()`
/// @param ... [in] Variable-length args
/// @return Thread of the function so it can be joined/awaited
pthread_t clogger_warning_async(clogger_t* logger, const char* location, const char* message, ...);

/// @brief Asynchronous variant of `clogger_error()`
/// @note Unlike its sync variant, this does not yet support error callback
/// @param logger [in] Pointer to `clogger_t` data structure
/// @param location [in] Location of the log
/// @param message [in] Format-able string message as you would use `printf()`
/// @param ... [in] Variable-length args
/// @return Thread of the function so it can be joined/awaited
pthread_t clogger_error_async(clogger_t* logger, const char* location, const char* message, ...);

/// @brief Asynchronous variant of `clogger_critical()`
/// @param logger [in] Pointer to `clogger_t` data structure
/// @param location [in] Location of the log
/// @param message [in] Format-able string message as you would use `printf()`
/// @param ... [in] Variable-length args
/// @return Thread of the function so it can be joined/awaited
pthread_t clogger_critical_async(clogger_t* logger, const char* location, const char* message, ...);

#ifdef __cplusplus
}
#endif

#endif //CLOGGER_CLOGGER_H

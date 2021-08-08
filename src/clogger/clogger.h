//! @file
//! @brief File for use with the `clogger_t` structure

#ifndef CLOGGER_CLOGGER_H
#define CLOGGER_CLOGGER_H

#include "core.h"
#include "console.h"

#ifdef __cplusplus
extern "C" {
#endif

/// @brief Determines whether the `clogger_t` should append or prepend to file
#define CLOGGER_FILEOPT_PREPEND_BIT 0x1
/// @brief Determines whether the `clogger_t` should log INFO messages to file
#define CLOGGER_FILEOPT_INFO_BIT 0x2
/// @brief Determines whether the `clogger_t` should log DEBUG messages to file
#define CLOGGER_FILEOPT_DEBUG_BIT 0x4
/// @brief Determines whether the `clogger_t` should log WARNING messages to file
#define CLOGGER_FILEOPT_WARNING_BIT 0x8
/// @brief Determines whether the `clogger_t` should log ERROR messages to file
#define CLOGGER_FILEOPT_ERROR_BIT 0x10
/// @brief Determines whether the `clogger_t` should log CRITICAL messages to file
#define CLOGGER_FILEOPT_CRITICAL_BIT 0x20
/// @brief Default `clogger_t::file_opt`
#define CLOGGER_FILEOPT_DEFAULT_BITS 0x30
/// @brief Turns off all `clogger_t::file_opt` bits
#define CLOGGER_FILEOPT_OFF_BITS 0x0

typedef enum clogger_fileopt
{
    CLOGGER_FILEOPT_OFF = CLOGGER_FILEOPT_OFF_BITS,
    CLOGGER_FILEOPT_PREPEND = CLOGGER_FILEOPT_PREPEND_BIT,
    CLOGGER_FILEOPT_INFO = CLOGGER_FILEOPT_INFO_BIT
} clogger_fileopt_t;

/// @brief Creates a `clogger_t` instance
/// @param clogger_name [in] Name of the `clogger`
/// @return Initalized `clogger_t`
clogger_t* clogger_create(const char* clogger_name);

/// @brief Destroys a `clogger_t` instance
/// @param logger Pointer to the instance to destroy
void clogger_destroy(clogger_t* logger);

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

void clogger_set_fileopt_option(clogger_t* logger, unsigned char option, int enabled);

void clogger_set_fileopt_path(clogger_t* logger, const char* path);

/// @brief Simplified `clogger_t` structure creation function
/// @deprecated Use `clogger_create()` instead
/// @param clogger_name [in] Name of the `clogger`
/// @return Initialized `clogger_t`
clogger_t make_clogger(const char* clogger_name);

#ifdef __cplusplus
}
#endif

#endif //CLOGGER_CLOGGER_H

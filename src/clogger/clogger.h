//! @file
//! @brief File for use with the `clogger_t` structure

#ifndef CLOGGER_CLOGGER_H
#define CLOGGER_CLOGGER_H

#include "core.h"

#ifdef __cplusplus
extern "C" {
#endif

#define CLOGGER_FILE_OPT_OFF_BITS 0x0
#define CLOGGER_FILE_OPT_PREPEND_BIT 0x1
#define CLOGGER_FILE_OPT_INFO_BIT 0x2
#define CLOGGER_FILE_OPT_DEBUG_BIT 0x4
#define CLOGGER_FILE_OPT_WARNING_BIT 0x8
#define CLOGGER_FILE_OPT_ERROR_BIT 0x10
#define CLOGGER_FILE_OPT_CRITICAL_BIT 0x20
#define CLOGGER_FILE_OPT_DEFAULT_BITS 0x30

/// @brief Enumeration of bit flags for `clogger_t::file_opt`
typedef enum clogger_file_opt
{
    CLOGGER_FILE_OPT_OFF = CLOGGER_FILE_OPT_OFF_BITS, ///< Turns off all `clogger_t::file_opt` bits
    CLOGGER_FILE_OPT_PREPEND = CLOGGER_FILE_OPT_PREPEND_BIT, ///< Determines whether the `clogger_t` should append or prepend to file
    CLOGGER_FILE_OPT_INFO = CLOGGER_FILE_OPT_INFO_BIT, ///< Determines whether the `clogger_t` should log `INFO` messages to file
    CLOGGER_FILE_OPT_DEBUG = CLOGGER_FILE_OPT_DEBUG_BIT, ///< Determines whether the `clogger_t` should log `DEBUG` messages to file
    CLOGGER_FILE_OPT_WARNING = CLOGGER_FILE_OPT_WARNING_BIT, ///< Determines whether the `clogger_t` should log `WARNING` messages to file
    CLOGGER_FILE_OPT_ERROR = CLOGGER_FILE_OPT_ERROR_BIT, ///< Determines whether the `clogger_t` should log `ERROR` messages to file
    CLOGGER_FILE_OPT_CRITICAL = CLOGGER_FILE_OPT_CRITICAL_BIT, ///< Determines whether the `clogger_t` should log `CRITICAL` messages to file
    CLOGGER_FILE_OPT_DEFAULT = CLOGGER_FILE_OPT_DEFAULT_BITS ///< Default `clogger_t::file_opt`
} clogger_file_opt_t;

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

/// @brief Set the `clogger_t::file_opt`
/// @param logger Pointer to the `clogger_t` to set the option for
/// @param option Flags
/// @param enabled Enable or disable
void clogger_set_file_opt_option(clogger_t* logger, clogger_file_opt_t option, int enabled);

/// @brief Set the default file path to the log file
/// @param logger Pointer to the `clogger_t`
/// @param path Path to log file
void clogger_set_file_opt_path(clogger_t* logger, const char* path);

/// @brief Simplified `clogger_t` structure creation function
/// @deprecated Use `clogger_create()` instead
/// @param clogger_name [in] Name of the `clogger`
/// @return Initialized `clogger_t`
clogger_t make_clogger(const char* clogger_name);

#ifdef __cplusplus
}
#endif

#endif //CLOGGER_CLOGGER_H

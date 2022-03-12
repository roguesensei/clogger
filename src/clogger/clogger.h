//! @file
//! @brief File for use with the `CLogger` structure

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

/// @brief Enumeration of bit flags for CLogger::file_opt
typedef enum CLoggerFileOpt
{
    CLOGGER_FILE_OPT_OFF = CLOGGER_FILE_OPT_OFF_BITS, ///< Turns off all `CLogger::file_opt` bits
    CLOGGER_FILE_OPT_PREPEND = CLOGGER_FILE_OPT_PREPEND_BIT, ///< Determines whether the `CLogger` should append or prepend to file
    CLOGGER_FILE_OPT_INFO = CLOGGER_FILE_OPT_INFO_BIT, ///< Determines whether the `CLogger` should log `INFO` messages to file
    CLOGGER_FILE_OPT_DEBUG = CLOGGER_FILE_OPT_DEBUG_BIT, ///< Determines whether the `CLogger` should log `DEBUG` messages to file
    CLOGGER_FILE_OPT_WARNING = CLOGGER_FILE_OPT_WARNING_BIT, ///< Determines whether the `CLogger` should log `WARNING` messages to file
    CLOGGER_FILE_OPT_ERROR = CLOGGER_FILE_OPT_ERROR_BIT, ///< Determines whether the `CLogger` should log `ERROR` messages to file
    CLOGGER_FILE_OPT_CRITICAL = CLOGGER_FILE_OPT_CRITICAL_BIT, ///< Determines whether the `CLogger` should log `CRITICAL` messages to file
    CLOGGER_FILE_OPT_DEFAULT = CLOGGER_FILE_OPT_DEFAULT_BITS ///< Default `CLogger::file_opt`
} CLoggerFileOpt;

/// @brief Creates a logger instance
/// @param clogger_name [in] Name of the logger
/// @return Initalized logger
void clogger_init(CLogger* logger, const char* clogger_name);

/// @brief `CLOG_LEVEL_INFO` log message, will only call if the `CLogger` struct is set as such
/// @param logger [in] Pointer to `CLogger` data structure
/// @param location [in] Location of the log
/// @param message [in] Format-able string message as you would use `printf()`
/// @param ... [in] Variable-length args
void clogger_info(CLogger* logger, const char* location, const char* message, ...);

/// @brief `CLOG_LEVEL_DEBUG` log message, will only call if the `CLogger` struct is set as such
/// @param logger [in] Pointer to `CLogger` data structure
/// @param location [in] Location of the log
/// @param message [in] Format-able string message as you would use `printf()`
/// @param ... [in] Variable-length args
void clogger_debug(CLogger* logger, const char* location, const char* message, ...);

/// @brief `CLOG_LEVEL_WARNING` log message, will only call if the `CLogger` struct is set as such
/// @param logger [in] Pointer to `CLogger` data structure
/// @param location [in] Location of the log
/// @param message [in] Format-able string message as you would use `printf()`
/// @param ... [in] Variable-length args
void clogger_warning(CLogger* logger, const char* location, const char* message, ...);

/// @brief `CLOG_LEVEL_ERROR` log message, will only call if the `CLogger` struct is set as such
/// @param logger [in] Pointer to `CLogger` data structure
/// @param location [in] Location of the log
/// @param message [in] Format-able string message as you would use `printf()`
/// @param ... [in] Variable-length args
void clogger_error(CLogger* logger, const char* location, const char* message, ...);

/// @brief `CLOG_LEVEL_CRITICAL` log message, will only call if the `CLogger` struct is set as such
/// @param logger [in] Pointer to `CLogger` data structure
/// @param location [in] Location of the log
/// @param message [in] Format-able string message as you would use `printf()`
/// @param ... [in] Variable-length args
void clogger_critical(CLogger* logger, const char* location, const char* message, ...);

/// @brief Set the `CLogger::file_opt`
/// @param logger Pointer to the `CLogger` to set the option for
/// @param option Flags
/// @param enabled Enable or disable
void clogger_set_file_opt_option(CLogger* logger, CLoggerFileOpt option, CLoggerBool enabled);

/// @brief Set the default file path to the log file
/// @param logger Pointer to the `CLogger`
/// @param path Path to log file
void clogger_set_file_opt_path(CLogger* logger, const char* path);

#ifdef __cplusplus
}
#endif

#endif //CLOGGER_CLOGGER_H

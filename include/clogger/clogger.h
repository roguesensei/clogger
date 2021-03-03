#ifndef CLOGGER_CLOGGER_H
#define CLOGGER_CLOGGER_H

#include "core.h"
#include "console.h"

// Simplified creation method
CLOGGER_API clogger make_clogger(const char* clogger_name);

// Sync
CLOGGER_API void clogger_info(clogger* logger, const char* location, const char* message, ...);
CLOGGER_API void clogger_debug(clogger* logger, const char* location, const char* message, ...);
CLOGGER_API void clogger_warning(clogger* logger, const char* location, const char* message, ...);
CLOGGER_API void clogger_error(clogger* logger, const char* location, const char* message, ...);
CLOGGER_API void clogger_critical(clogger* logger, const char* location, const char* message, ...);

// Async
CLOGGER_API clog_thread clogger_info_async(clogger* logger, const char* location, const char* message, ...);
CLOGGER_API clog_thread clogger_debug_async(clogger* logger, const char* location, const char* message, ...);
CLOGGER_API clog_thread clogger_warning_async(clogger* logger, const char* location, const char* message, ...);
CLOGGER_API clog_thread clogger_error_async(clogger* logger, const char* location, const char* message, ...);
CLOGGER_API clog_thread clogger_critical_async(clogger* logger, const char* location, const char* message, ...);

#endif //CLOGGER_CLOGGER_H

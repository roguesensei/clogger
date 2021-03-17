#ifndef CLOGGER_CLOGGER_H
#define CLOGGER_CLOGGER_H

#include "core.h"
#include "console.h"

#include <pthread.h>

// Simplified creation method
CLOGGER_API clogger make_clogger(const char* clogger_name);

// Sync
CLOGGER_API void clogger_info(clogger* logger, const char* location, const char* message, ...);
CLOGGER_API void clogger_debug(clogger* logger, const char* location, const char* message, ...);
CLOGGER_API void clogger_warning(clogger* logger, const char* location, const char* message, ...);
CLOGGER_API void clogger_error(clogger* logger, const char* location, const char* message, ...);
CLOGGER_API void clogger_critical(clogger* logger, const char* location, const char* message, ...);

// Async
CLOGGER_API pthread_t clogger_info_async(clogger* logger, const char* location, const char* message, ...);
CLOGGER_API pthread_t clogger_debug_async(clogger* logger, const char* location, const char* message, ...);
CLOGGER_API pthread_t clogger_warning_async(clogger* logger, const char* location, const char* message, ...);
CLOGGER_API pthread_t clogger_error_async(clogger* logger, const char* location, const char* message, ...);
CLOGGER_API pthread_t clogger_critical_async(clogger* logger, const char* location, const char* message, ...);

#endif //CLOGGER_CLOGGER_H

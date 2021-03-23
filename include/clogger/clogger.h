#ifndef CLOGGER_CLOGGER_H
#define CLOGGER_CLOGGER_H

#include "core.h"
#include "console.h"

#ifdef __cplusplus
extern "C" {
#endif

#include <pthread.h>

// Simplified creation method
clogger make_clogger(const char* clogger_name);

// Sync
void clogger_info(clogger* logger, const char* location, const char* message, ...);
void clogger_debug(clogger* logger, const char* location, const char* message, ...);
void clogger_warning(clogger* logger, const char* location, const char* message, ...);
void clogger_error(clogger* logger, const char* location, const char* message, ...);
void clogger_critical(clogger* logger, const char* location, const char* message, ...);

// Async
pthread_t clogger_info_async(clogger* logger, const char* location, const char* message, ...);
pthread_t clogger_debug_async(clogger* logger, const char* location, const char* message, ...);
pthread_t clogger_warning_async(clogger* logger, const char* location, const char* message, ...);
pthread_t clogger_error_async(clogger* logger, const char* location, const char* message, ...);
pthread_t clogger_critical_async(clogger* logger, const char* location, const char* message, ...);

#ifdef __cplusplus
}
#endif

#endif //CLOGGER_CLOGGER_H

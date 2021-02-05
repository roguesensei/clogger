#ifndef CLOGGER_CORE_H
#define CLOGGER_CORE_H

#define CLOGGER_FALSE 0
#define CLOGGER_TRUE 1

#ifdef CLOGGER_DEBUG
    #define CLOG_DEBUG_DEFAULT CLOGGER_TRUE
#else
    #define CLOG_DEBUG_DEFAULT CLOGGER_FALSE
#endif

#ifdef __cplusplus
    #define CLOGGER_API extern "C"
#else
    #define CLOGGER_API
#endif

typedef enum
{
    CLogFalse = CLOGGER_FALSE, CLogTrue = CLOGGER_TRUE
} clog_bool;

#endif //CLOGGER_CORE_H

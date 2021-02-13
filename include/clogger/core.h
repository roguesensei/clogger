#ifndef CLOGGER_CORE_H
#define CLOGGER_CORE_H

#define CLOGGER_FALSE 0b00000000
#define CLOGGER_TRUE 0b00000001

#ifdef __cplusplus
    #define CLOGGER_API extern "C"
#else
    #define CLOGGER_API
#endif

typedef enum
{
    clog_false = CLOGGER_FALSE, clog_true = CLOGGER_TRUE
} clog_bool;

#endif //CLOGGER_CORE_H

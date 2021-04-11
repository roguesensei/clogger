#include "clogger/clog_assert.h"
#include "clogger/core.h"
#include "clogger/console.h"
#include "clogger/clog.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

typedef enum fatal
{
    NON_FATAL, FATAL
} fatal_t;

int evaluate_assert(fatal_t fatal, int condition, const char* location, const char* message, va_list args)
{
    if (!condition)
    {
        if (fatal)
        {
            clog_set_console_colour((clog_console_colour_t) {WHITE, RED},
                                    CLOGGER_FOREGROUND_INTENSE | CLOGGER_BACKGROUND_INTENSE);
        }
        else
        {
            clog_set_console_colour((clog_console_colour_t) {WHITE, YELLOW}, CLOGGER_FOREGROUND_INTENSE);
        }
        printf("[ASSERT FAILED]");
        clog_reset_console_colour();

        printf(" >> ");

        clog_messagef(CLOG_LEVEL_MESSAGE, NULL, location, message, args);
    }

    return condition;
}

void clog_assert(int condition, const char* location, const char* message, ...)
{
    va_list args;

    va_start(args, message);
    evaluate_assert(FATAL, condition, location, message, args);
    va_end(args);

    if (!condition)
    {
        abort();
    }
}

void clog_assert_equal_int32(int expected, int actual, const char* location, const char* message, ...)
{
    va_list args;

    va_start(args, message);
    int result = evaluate_assert(FATAL, expected == actual, location, message, args);
    va_end(args);

    if (!result)
    {
        clog_set_console_colour((clog_console_colour_t) {RED, CLEAR}, CLOGGER_FOREGROUND_INTENSE);
        printf("[EXPECTED RESULT]");
        clog_reset_console_colour();

        printf(" >> %d\n", expected);

        clog_set_console_colour((clog_console_colour_t) {RED, CLEAR}, CLOGGER_FOREGROUND_INTENSE);
        printf("[ACTUAL RESULT]");
        clog_reset_console_colour();

        printf(" >> %d\n", actual);

        abort();
    }
}

int clog_expect(int condition, const char* location, const char* message, ...)
{
    va_list args;

    va_start(args, message);
    evaluate_assert(NON_FATAL, condition, location, message, args);
    va_end(args);

    return condition;
}

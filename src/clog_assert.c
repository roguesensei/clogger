#include "clogger/clog_assert.h"
#include "clogger/core.h"
#include "clogger/console.h"
#include "clogger/clog.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

typedef enum fatal
{
    NON_FATAL = CLOG_LEVEL_NON_FATAL_ASSERT, FATAL = CLOG_LEVEL_FATAL_ASSERT
} fatal_t;

int evaluate_assert(fatal_t fatal, int condition, const char* location, const char* message, va_list args)
{
    if (!condition)
    {
        clog_messagef((clog_level_t) fatal, NULL, location, message, args);
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

void clog_assert_equal_uint32(unsigned int expected, unsigned int actual, const char* location, const char* message, ...)
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

        printf(" >> %u\n", expected);

        clog_set_console_colour((clog_console_colour_t) {RED, CLEAR}, CLOGGER_FOREGROUND_INTENSE);
        printf("[ACTUAL RESULT]");
        clog_reset_console_colour();

        printf(" >> %u\n", actual);

        abort();
    }
}

void clog_assert_equal_size(size_t expected, size_t actual, const char* location, const char* message, ...)
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

void clog_assert_equal_str(const char* expected, size_t expected_size, const char* actual, size_t actual_size, const char* location, const char* message, ...)
{
    va_list args;

    va_start(args, message);
    int result = evaluate_assert(FATAL, strncmp(expected, actual, expected_size) == 0, location, message, args);
    va_end(args);

    if (!result)
    {
        clog_set_console_colour((clog_console_colour_t) {RED, CLEAR}, CLOGGER_FOREGROUND_INTENSE);
        printf("[EXPECTED RESULT]");
        clog_reset_console_colour();

        printf(" >> %s (%d bytes)\n", expected, expected_size);

        clog_set_console_colour((clog_console_colour_t) {RED, CLEAR}, CLOGGER_FOREGROUND_INTENSE);
        printf("[ACTUAL RESULT]");
        clog_reset_console_colour();

        printf(" >> %s (%d bytes)\n", actual, actual_size);

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

int clog_expect_equal_int32(int expected, int actual, const char* location, const char* message, ...)
{
    int condition = expected == actual;
    va_list args;

    va_start(args, message);
    if (!evaluate_assert(NON_FATAL, condition, location, message, args))
    {
        clog_set_console_colour((clog_console_colour_t) {YELLOW, CLEAR}, 0);
        printf("[EXPECTED RESULT]");
        clog_reset_console_colour();

        printf(" >> %d\n", expected);

        clog_set_console_colour((clog_console_colour_t) {YELLOW, CLEAR}, 0);
        printf("[ACTUAL RESULT]");
        clog_reset_console_colour();

        printf(" >> %d\n", actual);
    }
    va_end(args);

    return condition;
}
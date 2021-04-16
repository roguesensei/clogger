#include "clog_assert.h"
#include "clogger_pch.h"
#include "core.h"
#include "console.h"
#include "clog.h"

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

void clog_assert_int16_eq(short expected, short actual, const char* location, const char* message, ...)
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

void clog_assert_int16_neq(short not_expected, short actual, const char* location, const char* message, ...)
{
    va_list args;

    va_start(args, message);
    int result = evaluate_assert(FATAL, not_expected != actual, location, message, args);
    va_end(args);

    if (!result)
    {
        clog_set_console_colour((clog_console_colour_t) {RED, CLEAR}, CLOGGER_FOREGROUND_INTENSE);
        printf("[EXPECTED RESULT]");
        clog_reset_console_colour();

        printf(" >> NOT %d\n", not_expected);

        clog_set_console_colour((clog_console_colour_t) {RED, CLEAR}, CLOGGER_FOREGROUND_INTENSE);
        printf("[ACTUAL RESULT]");
        clog_reset_console_colour();

        printf(" >> %d\n", actual);

        abort();
    }
}

void clog_assert_uint16_eq(unsigned short expected, unsigned short actual, const char* location, const char* message, ...)
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

void clog_assert_uint16_neq(unsigned short not_expected, unsigned short actual, const char* location, const char* message, ...)
{
    va_list args;

    va_start(args, message);
    int result = evaluate_assert(FATAL, not_expected != actual, location, message, args);
    va_end(args);

    if (!result)
    {
        clog_set_console_colour((clog_console_colour_t) {RED, CLEAR}, CLOGGER_FOREGROUND_INTENSE);
        printf("[EXPECTED RESULT]");
        clog_reset_console_colour();

        printf(" >> NOT %u\n", not_expected);

        clog_set_console_colour((clog_console_colour_t) {RED, CLEAR}, CLOGGER_FOREGROUND_INTENSE);
        printf("[ACTUAL RESULT]");
        clog_reset_console_colour();

        printf(" >> %u\n", actual);

        abort();
    }
}

void clog_assert_int32_eq(int expected, int actual, const char* location, const char* message, ...)
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

void clog_assert_int32_neq(int not_expected, int actual, const char* location, const char* message, ...)
{
    va_list args;

    va_start(args, message);
    int result = evaluate_assert(FATAL, not_expected != actual, location, message, args);
    va_end(args);

    if (!result)
    {
        clog_set_console_colour((clog_console_colour_t) {RED, CLEAR}, CLOGGER_FOREGROUND_INTENSE);
        printf("[EXPECTED RESULT]");
        clog_reset_console_colour();

        printf(" >> NOT %d\n", not_expected);

        clog_set_console_colour((clog_console_colour_t) {RED, CLEAR}, CLOGGER_FOREGROUND_INTENSE);
        printf("[ACTUAL RESULT]");
        clog_reset_console_colour();

        printf(" >> %d\n", actual);

        abort();
    }
}

void clog_assert_uint32_eq(unsigned int expected, unsigned int actual, const char* location, const char* message, ...)
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

void clog_assert_uint32_neq(unsigned int not_expected, unsigned int actual, const char* location, const char* message, ...)
{
    va_list args;

    va_start(args, message);
    int result = evaluate_assert(FATAL, not_expected != actual, location, message, args);
    va_end(args);

    if (!result)
    {
        clog_set_console_colour((clog_console_colour_t) {RED, CLEAR}, CLOGGER_FOREGROUND_INTENSE);
        printf("[EXPECTED RESULT]");
        clog_reset_console_colour();

        printf(" >> NOT %u\n", not_expected);

        clog_set_console_colour((clog_console_colour_t) {RED, CLEAR}, CLOGGER_FOREGROUND_INTENSE);
        printf("[ACTUAL RESULT]");
        clog_reset_console_colour();

        printf(" >> %u\n", actual);

        abort();
    }
}

void clog_assert_int64_eq(long expected, long actual, const char* location, const char* message, ...)
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

        printf(" >> %ld\n", expected);

        clog_set_console_colour((clog_console_colour_t) {RED, CLEAR}, CLOGGER_FOREGROUND_INTENSE);
        printf("[ACTUAL RESULT]");
        clog_reset_console_colour();

        printf(" >> %ld\n", actual);

        abort();
    }
}

void clog_assert_int64_neq(long not_expected, long actual, const char* location, const char* message, ...)
{
    va_list args;

    va_start(args, message);
    int result = evaluate_assert(FATAL, not_expected != actual, location, message, args);
    va_end(args);

    if (!result)
    {
        clog_set_console_colour((clog_console_colour_t) {RED, CLEAR}, CLOGGER_FOREGROUND_INTENSE);
        printf("[EXPECTED RESULT]");
        clog_reset_console_colour();

        printf(" >> NOT %ld\n", not_expected);

        clog_set_console_colour((clog_console_colour_t) {RED, CLEAR}, CLOGGER_FOREGROUND_INTENSE);
        printf("[ACTUAL RESULT]");
        clog_reset_console_colour();

        printf(" >> %ld\n", actual);

        abort();
    }
}

void clog_assert_uint64_eq(unsigned long expected, unsigned long actual, const char* location, const char* message, ...)
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

        printf(" >> %lu\n", expected);

        clog_set_console_colour((clog_console_colour_t) {RED, CLEAR}, CLOGGER_FOREGROUND_INTENSE);
        printf("[ACTUAL RESULT]");
        clog_reset_console_colour();

        printf(" >> %lu\n", actual);

        abort();
    }
}

void clog_assert_uint64_neq(unsigned long not_expected, unsigned long actual, const char* location, const char* message, ...)
{
    va_list args;

    va_start(args, message);
    int result = evaluate_assert(FATAL, not_expected != actual, location, message, args);
    va_end(args);

    if (!result)
    {
        clog_set_console_colour((clog_console_colour_t) {RED, CLEAR}, CLOGGER_FOREGROUND_INTENSE);
        printf("[EXPECTED RESULT]");
        clog_reset_console_colour();

        printf(" >> NOT %lu\n", not_expected);

        clog_set_console_colour((clog_console_colour_t) {RED, CLEAR}, CLOGGER_FOREGROUND_INTENSE);
        printf("[ACTUAL RESULT]");
        clog_reset_console_colour();

        printf(" >> %lu\n", actual);

        abort();
    }
}

void clog_assert_size_eq(size_t expected, size_t actual, const char* location, const char* message, ...)
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

void clog_assert_size_neq(size_t not_expected, size_t actual, const char* location, const char* message, ...)
{
    va_list args;

    va_start(args, message);
    int result = evaluate_assert(FATAL, not_expected != actual, location, message, args);
    va_end(args);

    if (!result)
    {
        clog_set_console_colour((clog_console_colour_t) {RED, CLEAR}, CLOGGER_FOREGROUND_INTENSE);
        printf("[EXPECTED RESULT]");
        clog_reset_console_colour();

        printf(" >> NOT %d\n", not_expected);

        clog_set_console_colour((clog_console_colour_t) {RED, CLEAR}, CLOGGER_FOREGROUND_INTENSE);
        printf("[ACTUAL RESULT]");
        clog_reset_console_colour();

        printf(" >> %d\n", actual);

        abort();
    }
}

void clog_assert_str_eq(const char* expected, size_t expected_size, const char* actual, size_t actual_size, const char* location, const char* message, ...)
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

void clog_assert_str_neq(const char* not_expected, size_t expected_size, const char* actual, size_t actual_size, const char* location, const char* message, ...)
{
    va_list args;

    va_start(args, message);
    int result = evaluate_assert(FATAL, strncmp(not_expected, actual, expected_size) != 0, location, message, args);
    va_end(args);

    if (!result)
    {
        clog_set_console_colour((clog_console_colour_t) {RED, CLEAR}, CLOGGER_FOREGROUND_INTENSE);
        printf("[EXPECTED RESULT]");
        clog_reset_console_colour();

        printf(" >> NOT %s (%d bytes)\n", not_expected, expected_size);

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

int clog_expect_int32_eq(int expected, int actual, const char* location, const char* message, ...)
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
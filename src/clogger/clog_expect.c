#include "clog_expect.h"
#include "clogger_pch.h"
#include "core.h"
#include "console.h"
#include "clog.h"

int evaluate_assert(int condition, const char* location, const char* message, va_list args)
{
    if (!condition)
    {
        clog_messagef(CLOG_LEVEL_FATAL_ASSERT, NULL, location, message, args);
    }

    return condition;
}

int clog_expect(int condition, const char* location, const char* message, ...)
{
    va_list args;

    va_start(args, message);
    evaluate_assert(condition, location, message, args);
    va_end(args);

    return condition;
}

int clog_expect_int8_eq(int8_t expected, int8_t actual, const char* location, const char* message, ...)
{
    int condition = expected == actual;
    va_list args;

    va_start(args, message);
    if (!evaluate_assert(condition, location, message, args))
    {
        clog_set_console_colour((clog_console_colour_t) {YELLOW, CLEAR}, CLOGGER_FOREGROUND_INTENSE);
        printf("[EXPECTED RESULT]");
        clog_reset_console_colour();

        printf(" >> %d\n", expected);

        clog_set_console_colour((clog_console_colour_t) {YELLOW, CLEAR}, CLOGGER_FOREGROUND_INTENSE);
        printf("[ACTUAL RESULT]");
        clog_reset_console_colour();

        printf(" >> %d\n", actual);
    }
    va_end(args);

    return condition;
}

int clog_expect_int8_neq(int8_t not_expected, int8_t actual, const char* location, const char* message, ...)
{
    int condition = not_expected != actual;
    va_list args;

    va_start(args, message);
    if (!evaluate_assert(condition, location, message, args))
    {
        clog_set_console_colour((clog_console_colour_t) {YELLOW, CLEAR}, CLOGGER_FOREGROUND_INTENSE);
        printf("[EXPECTED RESULT]");
        clog_reset_console_colour();

        printf(" >> NOT %d\n", not_expected);

        clog_set_console_colour((clog_console_colour_t) {YELLOW, CLEAR}, CLOGGER_FOREGROUND_INTENSE);
        printf("[ACTUAL RESULT]");
        clog_reset_console_colour();

        printf(" >> %d\n", actual);
    }
    va_end(args);

    return condition;
}

int clog_expect_int8_is_nullptr(const int8_t* value_ptr, const char* location, const char* message, ...)
{
    int condition = value_ptr == NULL;

    va_list args;

    va_start(args, message);
    if (!evaluate_assert(condition, location, message, args))
    {
        clog_set_console_colour((clog_console_colour_t) {YELLOW, CLEAR}, CLOGGER_FOREGROUND_INTENSE);
        printf("[EXPECTED NULLPTR]");
        clog_reset_console_colour();

        printf(" >> AT ADDRESS %p\n", value_ptr);
    }
    va_end(args);

    return condition;
}

int clog_expect_int8_is_not_nullptr(const int8_t* value_ptr, const char* location, const char* message, ...)
{
    int condition = value_ptr != NULL;

    va_list args;

    va_start(args, message);
    if (!evaluate_assert(condition, location, message, args))
    {
        clog_set_console_colour((clog_console_colour_t) {YELLOW, CLEAR}, CLOGGER_FOREGROUND_INTENSE);
        printf("[RECEIVED NULLPTR]");
        clog_reset_console_colour();
    }
    va_end(args);

    return condition;
}

int clog_expect_uint8_eq(uint8_t expected, uint8_t actual, const char* location, const char* message, ...)
{
    int condition = expected == actual;
    va_list args;

    va_start(args, message);
    if (!evaluate_assert(condition, location, message, args))
    {
        clog_set_console_colour((clog_console_colour_t) {YELLOW, CLEAR}, CLOGGER_FOREGROUND_INTENSE);
        printf("[EXPECTED RESULT]");
        clog_reset_console_colour();

        printf(" >> %u\n", expected);

        clog_set_console_colour((clog_console_colour_t) {YELLOW, CLEAR}, CLOGGER_FOREGROUND_INTENSE);
        printf("[ACTUAL RESULT]");
        clog_reset_console_colour();

        printf(" >> %u\n", actual);
    }
    va_end(args);

    return condition;
}

int clog_expect_uint8_neq(uint8_t not_expected, uint8_t actual, const char* location, const char* message, ...)
{
    int condition = not_expected != actual;
    va_list args;

    va_start(args, message);
    if (!evaluate_assert(condition, location, message, args))
    {
        clog_set_console_colour((clog_console_colour_t) {YELLOW, CLEAR}, CLOGGER_FOREGROUND_INTENSE);
        printf("[EXPECTED RESULT]");
        clog_reset_console_colour();

        printf(" >> NOT %u\n", not_expected);

        clog_set_console_colour((clog_console_colour_t) {YELLOW, CLEAR}, CLOGGER_FOREGROUND_INTENSE);
        printf("[ACTUAL RESULT]");
        clog_reset_console_colour();

        printf(" >> %u\n", actual);
    }
    va_end(args);

    return condition;
}

int clog_expect_uint8_is_nullptr(const uint8_t* value_ptr, const char* location, const char* message, ...)
{
    int condition = value_ptr == NULL;

    va_list args;

    va_start(args, message);
    if (!evaluate_assert(condition, location, message, args))
    {
        clog_set_console_colour((clog_console_colour_t) {YELLOW, CLEAR}, CLOGGER_FOREGROUND_INTENSE);
        printf("[EXPECTED NULLPTR]");
        clog_reset_console_colour();

        printf(" >> AT ADDRESS %p\n", value_ptr);
    }
    va_end(args);

    return condition;
}

int clog_expect_uint8_is_not_nullptr(const uint8_t* value_ptr, const char* location, const char* message, ...)
{
    int condition = value_ptr != NULL;

    va_list args;

    va_start(args, message);
    if (!evaluate_assert(condition, location, message, args))
    {
        clog_set_console_colour((clog_console_colour_t) {YELLOW, CLEAR}, CLOGGER_FOREGROUND_INTENSE);
        printf("[RECEIVED NULLPTR]");
        clog_reset_console_colour();
    }
    va_end(args);

    return condition;
}

int clog_expect_int16_eq(int16_t expected, int16_t actual, const char* location, const char* message, ...)
{
    int condition = expected == actual;
    va_list args;

    va_start(args, message);
    if (!evaluate_assert(condition, location, message, args))
    {
        clog_set_console_colour((clog_console_colour_t) {YELLOW, CLEAR}, CLOGGER_FOREGROUND_INTENSE);
        printf("[EXPECTED RESULT]");
        clog_reset_console_colour();

        printf(" >> %d\n", expected);

        clog_set_console_colour((clog_console_colour_t) {YELLOW, CLEAR}, CLOGGER_FOREGROUND_INTENSE);
        printf("[ACTUAL RESULT]");
        clog_reset_console_colour();

        printf(" >> %d\n", actual);
    }
    va_end(args);

    return condition;
}

int clog_expect_int16_neq(int16_t not_expected, int16_t actual, const char* location, const char* message, ...)
{
    int condition = not_expected != actual;
    va_list args;

    va_start(args, message);
    if (!evaluate_assert(condition, location, message, args))
    {
        clog_set_console_colour((clog_console_colour_t) {YELLOW, CLEAR}, CLOGGER_FOREGROUND_INTENSE);
        printf("[EXPECTED RESULT]");
        clog_reset_console_colour();

        printf(" >> NOT %d\n", not_expected);

        clog_set_console_colour((clog_console_colour_t) {YELLOW, CLEAR}, CLOGGER_FOREGROUND_INTENSE);
        printf("[ACTUAL RESULT]");
        clog_reset_console_colour();

        printf(" >> %d\n", actual);
    }
    va_end(args);

    return condition;
}

int clog_expect_int16_is_nullptr(const int16_t* value_ptr, const char* location, const char* message, ...)
{
    int condition = value_ptr == NULL;

    va_list args;

    va_start(args, message);
    if (!evaluate_assert(condition, location, message, args))
    {
        clog_set_console_colour((clog_console_colour_t) {YELLOW, CLEAR}, CLOGGER_FOREGROUND_INTENSE);
        printf("[EXPECTED NULLPTR]");
        clog_reset_console_colour();

        printf(" >> AT ADDRESS %p\n", value_ptr);
    }
    va_end(args);

    return condition;
}

int clog_expect_int16_is_not_nullptr(const int16_t* value_ptr, const char* location, const char* message, ...)
{
    int condition = value_ptr != NULL;

    va_list args;

    va_start(args, message);
    if (!evaluate_assert(condition, location, message, args))
    {
        clog_set_console_colour((clog_console_colour_t) {YELLOW, CLEAR}, CLOGGER_FOREGROUND_INTENSE);
        printf("[RECEIVED NULLPTR]");
        clog_reset_console_colour();
    }
    va_end(args);

    return condition;
}

int clog_expect_uint16_eq(uint16_t expected, uint16_t actual, const char* location, const char* message, ...)
{
    int condition = expected == actual;
    va_list args;

    va_start(args, message);
    if (!evaluate_assert(condition, location, message, args))
    {
        clog_set_console_colour((clog_console_colour_t) {YELLOW, CLEAR}, CLOGGER_FOREGROUND_INTENSE);
        printf("[EXPECTED RESULT]");
        clog_reset_console_colour();

        printf(" >> %u\n", expected);

        clog_set_console_colour((clog_console_colour_t) {YELLOW, CLEAR}, CLOGGER_FOREGROUND_INTENSE);
        printf("[ACTUAL RESULT]");
        clog_reset_console_colour();

        printf(" >> %u\n", actual);
    }
    va_end(args);

    return condition;
}

int clog_expect_uint16_neq(uint16_t not_expected, uint16_t actual, const char* location, const char* message, ...)
{
    int condition = not_expected != actual;
    va_list args;

    va_start(args, message);
    if (!evaluate_assert(condition, location, message, args))
    {
        clog_set_console_colour((clog_console_colour_t) {YELLOW, CLEAR}, CLOGGER_FOREGROUND_INTENSE);
        printf("[EXPECTED RESULT]");
        clog_reset_console_colour();

        printf(" >> NOT %u\n", not_expected);

        clog_set_console_colour((clog_console_colour_t) {YELLOW, CLEAR}, CLOGGER_FOREGROUND_INTENSE);
        printf("[ACTUAL RESULT]");
        clog_reset_console_colour();

        printf(" >> %u\n", actual);
    }
    va_end(args);

    return condition;
}

int clog_expect_uint16_is_nullptr(const uint16_t* value_ptr, const char* location, const char* message, ...)
{
    int condition = value_ptr == NULL;

    va_list args;

    va_start(args, message);
    if (!evaluate_assert(condition, location, message, args))
    {
        clog_set_console_colour((clog_console_colour_t) {YELLOW, CLEAR}, CLOGGER_FOREGROUND_INTENSE);
        printf("[EXPECTED NULLPTR]");
        clog_reset_console_colour();

        printf(" >> AT ADDRESS %p\n", value_ptr);
    }
    va_end(args);

    return condition;
}

int clog_expect_uint16_is_not_nullptr(const uint16_t* value_ptr, const char* location, const char* message, ...)
{
    int condition = value_ptr != NULL;

    va_list args;

    va_start(args, message);
    if (!evaluate_assert(condition, location, message, args))
    {
        clog_set_console_colour((clog_console_colour_t) {YELLOW, CLEAR}, CLOGGER_FOREGROUND_INTENSE);
        printf("[RECEIVED NULLPTR]");
        clog_reset_console_colour();
    }
    va_end(args);

    return condition;
}

int clog_expect_int32_eq(int32_t expected, int32_t actual, const char* location, const char* message, ...)
{
    int condition = expected == actual;
    va_list args;

    va_start(args, message);
    if (!evaluate_assert(condition, location, message, args))
    {
        clog_set_console_colour((clog_console_colour_t) {YELLOW, CLEAR}, CLOGGER_FOREGROUND_INTENSE);
        printf("[EXPECTED RESULT]");
        clog_reset_console_colour();

        printf(" >> %d\n", expected);

        clog_set_console_colour((clog_console_colour_t) {YELLOW, CLEAR}, CLOGGER_FOREGROUND_INTENSE);
        printf("[ACTUAL RESULT]");
        clog_reset_console_colour();

        printf(" >> %d\n", actual);
    }
    va_end(args);

    return condition;
}

int clog_expect_int32_neq(int32_t not_expected, int32_t actual, const char* location, const char* message, ...)
{
    int condition = not_expected != actual;
    va_list args;

    va_start(args, message);
    if (!evaluate_assert(condition, location, message, args))
    {
        clog_set_console_colour((clog_console_colour_t) {YELLOW, CLEAR}, CLOGGER_FOREGROUND_INTENSE);
        printf("[EXPECTED RESULT]");
        clog_reset_console_colour();

        printf(" >> NOT %d\n", not_expected);

        clog_set_console_colour((clog_console_colour_t) {YELLOW, CLEAR}, CLOGGER_FOREGROUND_INTENSE);
        printf("[ACTUAL RESULT]");
        clog_reset_console_colour();

        printf(" >> %d\n", actual);
    }
    va_end(args);

    return condition;
}

int clog_expect_int32_is_nullptr(const int32_t* value_ptr, const char* location, const char* message, ...)
{
    int condition = value_ptr == NULL;

    va_list args;

    va_start(args, message);
    if (!evaluate_assert(condition, location, message, args))
    {
        clog_set_console_colour((clog_console_colour_t) {YELLOW, CLEAR}, CLOGGER_FOREGROUND_INTENSE);
        printf("[EXPECTED NULLPTR]");
        clog_reset_console_colour();

        printf(" >> AT ADDRESS %p\n", value_ptr);
    }
    va_end(args);

    return condition;
}

int clog_expect_int32_is_not_nullptr(const int32_t* value_ptr, const char* location, const char* message, ...)
{
    int condition = value_ptr != NULL;

    va_list args;

    va_start(args, message);
    if (!evaluate_assert(condition, location, message, args))
    {
        clog_set_console_colour((clog_console_colour_t) {YELLOW, CLEAR}, CLOGGER_FOREGROUND_INTENSE);
        printf("[RECEIVED NULLPTR]");
        clog_reset_console_colour();
    }
    va_end(args);

    return condition;
}

int clog_expect_uint32_eq(uint32_t expected, uint32_t actual, const char* location, const char* message, ...)
{
    int condition = expected == actual;
    va_list args;

    va_start(args, message);
    if (!evaluate_assert(condition, location, message, args))
    {
        clog_set_console_colour((clog_console_colour_t) {YELLOW, CLEAR}, CLOGGER_FOREGROUND_INTENSE);
        printf("[EXPECTED RESULT]");
        clog_reset_console_colour();

        printf(" >> %u\n", expected);

        clog_set_console_colour((clog_console_colour_t) {YELLOW, CLEAR}, CLOGGER_FOREGROUND_INTENSE);
        printf("[ACTUAL RESULT]");
        clog_reset_console_colour();

        printf(" >> %u\n", actual);
    }
    va_end(args);

    return condition;
}

int clog_expect_uint32_neq(uint32_t not_expected, uint32_t actual, const char* location, const char* message, ...)
{
    int condition = not_expected != actual;
    va_list args;

    va_start(args, message);
    if (!evaluate_assert(condition, location, message, args))
    {
        clog_set_console_colour((clog_console_colour_t) {YELLOW, CLEAR}, CLOGGER_FOREGROUND_INTENSE);
        printf("[EXPECTED RESULT]");
        clog_reset_console_colour();

        printf(" >> NOT %u\n", not_expected);

        clog_set_console_colour((clog_console_colour_t) {YELLOW, CLEAR}, CLOGGER_FOREGROUND_INTENSE);
        printf("[ACTUAL RESULT]");
        clog_reset_console_colour();

        printf(" >> %u\n", actual);
    }
    va_end(args);

    return condition;
}

int clog_expect_uint32_is_nullptr(const uint32_t* value_ptr, const char* location, const char* message, ...)
{
    int condition = value_ptr == NULL;

    va_list args;

    va_start(args, message);
    if (!evaluate_assert(condition, location, message, args))
    {
        clog_set_console_colour((clog_console_colour_t) {YELLOW, CLEAR}, CLOGGER_FOREGROUND_INTENSE);
        printf("[EXPECTED NULLPTR]");
        clog_reset_console_colour();

        printf(" >> AT ADDRESS %p\n", value_ptr);
    }
    va_end(args);

    return condition;
}

int clog_expect_uint32_is_not_nullptr(const uint32_t* value_ptr, const char* location, const char* message, ...)
{
    int condition = value_ptr != NULL;

    va_list args;

    va_start(args, message);
    if (!evaluate_assert(condition, location, message, args))
    {
        clog_set_console_colour((clog_console_colour_t) {YELLOW, CLEAR}, CLOGGER_FOREGROUND_INTENSE);
        printf("[RECEIVED NULLPTR]");
        clog_reset_console_colour();
    }
    va_end(args);

    return condition;
}

int clog_expect_int64_eq(int64_t expected, int64_t actual, const char* location, const char* message, ...)
{
    int condition = expected == actual;
    va_list args;

    va_start(args, message);
    if (!evaluate_assert(condition, location, message, args))
    {
        clog_set_console_colour((clog_console_colour_t) {YELLOW, CLEAR}, CLOGGER_FOREGROUND_INTENSE);
        printf("[EXPECTED RESULT]");
        clog_reset_console_colour();

        printf(" >> %ld\n", (long) expected);

        clog_set_console_colour((clog_console_colour_t) {YELLOW, CLEAR}, CLOGGER_FOREGROUND_INTENSE);
        printf("[ACTUAL RESULT]");
        clog_reset_console_colour();

        printf(" >> %ld\n", (long) actual);
    }
    va_end(args);

    return condition;
}

int clog_expect_int64_neq(int64_t not_expected, int64_t actual, const char* location, const char* message, ...)
{
    int condition = not_expected != actual;
    va_list args;

    va_start(args, message);
    if (!evaluate_assert(condition, location, message, args))
    {
        clog_set_console_colour((clog_console_colour_t) {YELLOW, CLEAR}, CLOGGER_FOREGROUND_INTENSE);
        printf("[EXPECTED RESULT]");
        clog_reset_console_colour();

        printf(" >> NOT %ld\n", (long) not_expected);

        clog_set_console_colour((clog_console_colour_t) {YELLOW, CLEAR}, CLOGGER_FOREGROUND_INTENSE);
        printf("[ACTUAL RESULT]");
        clog_reset_console_colour();

        printf(" >> %ld\n", (long) actual);
    }
    va_end(args);

    return condition;
}

int clog_expect_int64_is_nullptr(const int64_t* value_ptr, const char* location, const char* message, ...)
{
    int condition = value_ptr == NULL;

    va_list args;

    va_start(args, message);
    if (!evaluate_assert(condition, location, message, args))
    {
        clog_set_console_colour((clog_console_colour_t) {YELLOW, CLEAR}, CLOGGER_FOREGROUND_INTENSE);
        printf("[EXPECTED NULLPTR]");
        clog_reset_console_colour();

        printf(" >> AT ADDRESS %p\n", value_ptr);
    }
    va_end(args);

    return condition;
}

int clog_expect_int64_is_not_nullptr(const int64_t* value_ptr, const char* location, const char* message, ...)
{
    int condition = value_ptr != NULL;

    va_list args;

    va_start(args, message);
    if (!evaluate_assert(condition, location, message, args))
    {
        clog_set_console_colour((clog_console_colour_t) {YELLOW, CLEAR}, CLOGGER_FOREGROUND_INTENSE);
        printf("[RECEIVED NULLPTR]");
        clog_reset_console_colour();
    }
    va_end(args);

    return condition;
}

int clog_expect_uint64_eq(uint64_t expected, uint64_t actual, const char* location, const char* message, ...)
{
    int condition = expected == actual;
    va_list args;

    va_start(args, message);
    if (!evaluate_assert(condition, location, message, args))
    {
        clog_set_console_colour((clog_console_colour_t) {YELLOW, CLEAR}, 0);
        printf("[EXPECTED RESULT]");
        clog_reset_console_colour();

        printf(" >> %lu\n", (unsigned long) expected);

        clog_set_console_colour((clog_console_colour_t) {YELLOW, CLEAR}, CLOGGER_FOREGROUND_INTENSE);
        printf("[ACTUAL RESULT]");
        clog_reset_console_colour();

        printf(" >> %lu\n", (unsigned long) actual);
    }
    va_end(args);

    return condition;
}

int clog_expect_uint64_neq(uint64_t not_expected, uint64_t actual, const char* location, const char* message, ...)
{
    int condition = not_expected != actual;
    va_list args;

    va_start(args, message);
    if (!evaluate_assert(condition, location, message, args))
    {
        clog_set_console_colour((clog_console_colour_t) {YELLOW, CLEAR}, CLOGGER_FOREGROUND_INTENSE);
        printf("[EXPECTED RESULT]");
        clog_reset_console_colour();

        printf(" >> NOT %lu\n", (unsigned long) not_expected);

        clog_set_console_colour((clog_console_colour_t) {YELLOW, CLEAR}, CLOGGER_FOREGROUND_INTENSE);
        printf("[ACTUAL RESULT]");
        clog_reset_console_colour();

        printf(" >> %lu\n", (unsigned long) actual);
    }
    va_end(args);

    return condition;
}

int clog_expect_uint64_is_nullptr(const uint64_t* value_ptr, const char* location, const char* message, ...)
{
    int condition = value_ptr == NULL;

    va_list args;

    va_start(args, message);
    if (!evaluate_assert(condition, location, message, args))
    {
        clog_set_console_colour((clog_console_colour_t) {YELLOW, CLEAR}, CLOGGER_FOREGROUND_INTENSE);
        printf("[EXPECTED NULLPTR]");
        clog_reset_console_colour();

        printf(" >> AT ADDRESS %p\n", value_ptr);
    }
    va_end(args);

    return condition;
}

int clog_expect_uint64_is_not_nullptr(const uint64_t* value_ptr, const char* location, const char* message, ...)
{
    int condition = value_ptr != NULL;

    va_list args;

    va_start(args, message);
    if (!evaluate_assert(condition, location, message, args))
    {
        clog_set_console_colour((clog_console_colour_t) {YELLOW, CLEAR}, CLOGGER_FOREGROUND_INTENSE);
        printf("[RECEIVED NULLPTR]");
        clog_reset_console_colour();
    }
    va_end(args);

    return condition;
}

int clog_expect_size_eq(size_t expected, size_t actual, const char* location, const char* message, ...)
{
    int condition = expected == actual;
    va_list args;

    va_start(args, message);
    if (!evaluate_assert(condition, location, message, args))
    {
        clog_set_console_colour((clog_console_colour_t) {YELLOW, CLEAR}, CLOGGER_FOREGROUND_INTENSE);
        printf("[EXPECTED RESULT]");
        clog_reset_console_colour();

        printf(" >> %d\n", expected);

        clog_set_console_colour((clog_console_colour_t) {YELLOW, CLEAR}, CLOGGER_FOREGROUND_INTENSE);
        printf("[ACTUAL RESULT]");
        clog_reset_console_colour();

        printf(" >> %d\n", actual);
    }
    va_end(args);

    return condition;
}

int clog_expect_size_neq(size_t not_expected, size_t actual, const char* location, const char* message, ...)
{
    int condition = not_expected != actual;
    va_list args;

    va_start(args, message);
    if (!evaluate_assert(condition, location, message, args))
    {
        clog_set_console_colour((clog_console_colour_t) {YELLOW, CLEAR}, CLOGGER_FOREGROUND_INTENSE);
        printf("[EXPECTED RESULT]");
        clog_reset_console_colour();

        printf(" >> NOT %d\n", not_expected);

        clog_set_console_colour((clog_console_colour_t) {YELLOW, CLEAR}, CLOGGER_FOREGROUND_INTENSE);
        printf("[ACTUAL RESULT]");
        clog_reset_console_colour();

        printf(" >> %d\n", actual);
    }
    va_end(args);

    return condition;
}

int clog_expect_char_eq(char expected, char actual, const char* location, const char* message, ...)
{
    int condition = expected == actual;
    va_list args;

    va_start(args, message);
    if (!evaluate_assert(condition, location, message, args))
    {
        clog_set_console_colour((clog_console_colour_t) {YELLOW, CLEAR}, CLOGGER_FOREGROUND_INTENSE);
        printf("[EXPECTED RESULT]");
        clog_reset_console_colour();

        printf(" >> %c\n", expected);

        clog_set_console_colour((clog_console_colour_t) {YELLOW, CLEAR}, CLOGGER_FOREGROUND_INTENSE);
        printf("[ACTUAL RESULT]");
        clog_reset_console_colour();

        printf(" >> %c\n", actual);
    }
    va_end(args);

    return condition;
}

int clog_expect_char_neq(char not_expected, char actual, const char* location, const char* message, ...)
{
    int condition = not_expected != actual;
    va_list args;

    va_start(args, message);
    if (!evaluate_assert(condition, location, message, args))
    {
        clog_set_console_colour((clog_console_colour_t) {YELLOW, CLEAR}, CLOGGER_FOREGROUND_INTENSE);
        printf("[EXPECTED RESULT]");
        clog_reset_console_colour();

        printf(" >> NOT %c\n", not_expected);

        clog_set_console_colour((clog_console_colour_t) {YELLOW, CLEAR}, CLOGGER_FOREGROUND_INTENSE);
        printf("[ACTUAL RESULT]");
        clog_reset_console_colour();

        printf(" >> %c\n", actual);
    }
    va_end(args);

    return condition;
}

int clog_expect_str_eq(const char* expected, size_t expected_size, const char* actual, size_t actual_size,
                       const char* location, const char* message, ...)
{
    int condition = strncmp(expected, actual, expected_size) == 0;
    va_list args;

    va_start(args, message);
    if (!evaluate_assert(condition, location, message, args))
    {
        clog_set_console_colour((clog_console_colour_t) {YELLOW, CLEAR}, CLOGGER_FOREGROUND_INTENSE);
        printf("[EXPECTED RESULT]");
        clog_reset_console_colour();

        printf(" >> %s (%d bytes)\n", expected, expected_size);

        clog_set_console_colour((clog_console_colour_t) {YELLOW, CLEAR}, CLOGGER_FOREGROUND_INTENSE);
        printf("[ACTUAL RESULT]");
        clog_reset_console_colour();

        printf(" >> %s (%d bytes)\n", actual, actual_size);
    }
    va_end(args);

    return condition;
}

int clog_expect_str_neq(const char* not_expected, size_t not_expected_size, const char* actual, size_t actual_size,
                        const char* location, const char* message, ...)
{
    int condition = strncmp(not_expected, actual, not_expected_size) != 0;
    va_list args;

    va_start(args, message);
    if (!evaluate_assert(condition, location, message, args))
    {
        clog_set_console_colour((clog_console_colour_t) {YELLOW, CLEAR}, CLOGGER_FOREGROUND_INTENSE);
        printf("[EXPECTED RESULT]");
        clog_reset_console_colour();

        printf(" >> %s (%d bytes)\n", not_expected, not_expected_size);

        clog_set_console_colour((clog_console_colour_t) {YELLOW, CLEAR}, CLOGGER_FOREGROUND_INTENSE);
        printf("[ACTUAL RESULT]");
        clog_reset_console_colour();

        printf(" >> %s (%d bytes)\n", actual, actual_size);
    }
    va_end(args);

    return condition;
}

int clog_expect_str_is_nullptr(const char* value_ptr, const char* location, const char* message, ...)
{
    int condition = value_ptr == NULL;

    va_list args;

    va_start(args, message);
    if (!evaluate_assert(condition, location, message, args))
    {
        clog_set_console_colour((clog_console_colour_t) {YELLOW, CLEAR}, CLOGGER_FOREGROUND_INTENSE);
        printf("[EXPECTED NULLPTR]");
        clog_reset_console_colour();

        printf(" >> AT ADDRESS %p\n", value_ptr);
    }
    va_end(args);

    return condition;
}

int clog_expect_str_is_not_nullptr(const char* value_ptr, const char* location, const char* message, ...)
{
    int condition = value_ptr != NULL;

    va_list args;

    va_start(args, message);
    if (!evaluate_assert(condition, location, message, args))
    {
        clog_set_console_colour((clog_console_colour_t) {YELLOW, CLEAR}, CLOGGER_FOREGROUND_INTENSE);
        printf("[RECEIVED NULLPTR]");
        clog_reset_console_colour();
    }
    va_end(args);

    return condition;
}

#include "clog_expect.h"

#include "../clogger_pch.h"
#include "clog.h"
#include "console.h"
#include "core.h"

CLoggerBool evaluate_expect(CLoggerBool condition, const char* location, const char* message, va_list args)
{
    if (!condition)
    {
        clog_messagef(CLOGGER_LEVEL_NON_FATAL_ASSERT, NULL, location, message, args);
    }

    return condition;
}

CLoggerBool clog_expect(CLoggerBool condition, const char* location, const char* message, ...)
{
    va_list args;

    va_start(args, message);
    evaluate_expect(condition, location, message, args);
    va_end(args);

    return condition;
}

CLoggerBool clog_expect_int8_eq(CLoggerInt8 expected, CLoggerInt8 actual, const char* location, const char* message,
                                ...)
{
    int condition = expected == actual;
    va_list args;

    va_start(args, message);
    if (!evaluate_expect(condition, location, message, args))
    {
        clog_set_console_colour((CLoggerConsoleColour) {CLOGGER_COLOUR_YELLOW, CLOGGER_COLOUR_CLEAR},
                                CLOGGER_FOREGROUND_INTENSE);
        printf("[EXPECTED RESULT]");
        clog_reset_console_colour();

        printf(" >> %d\n", expected);

        clog_set_console_colour((CLoggerConsoleColour) {CLOGGER_COLOUR_YELLOW, CLOGGER_COLOUR_CLEAR},
                                CLOGGER_FOREGROUND_INTENSE);
        printf("[ACTUAL RESULT]");
        clog_reset_console_colour();

        printf(" >> %d\n", actual);
    }
    va_end(args);

    return condition;
}

CLoggerBool clog_expect_int8_neq(CLoggerInt8 not_expected, CLoggerInt8 actual, const char* location,
                                 const char* message, ...)
{
    int condition = not_expected != actual;
    va_list args;

    va_start(args, message);
    if (!evaluate_expect(condition, location, message, args))
    {
        clog_set_console_colour((CLoggerConsoleColour) {CLOGGER_COLOUR_YELLOW, CLOGGER_COLOUR_CLEAR},
                                CLOGGER_FOREGROUND_INTENSE);
        printf("[EXPECTED RESULT]");
        clog_reset_console_colour();

        printf(" >> NOT %d\n", not_expected);

        clog_set_console_colour((CLoggerConsoleColour) {CLOGGER_COLOUR_YELLOW, CLOGGER_COLOUR_CLEAR},
                                CLOGGER_FOREGROUND_INTENSE);
        printf("[ACTUAL RESULT]");
        clog_reset_console_colour();

        printf(" >> %d\n", actual);
    }
    va_end(args);

    return condition;
}

CLoggerBool clog_expect_int8_is_nullptr(const CLoggerInt8* value_ptr, const char* location, const char* message, ...)
{
    int condition = value_ptr == NULL;

    va_list args;

    va_start(args, message);
    if (!evaluate_expect(condition, location, message, args))
    {
        clog_set_console_colour((CLoggerConsoleColour) {CLOGGER_COLOUR_YELLOW, CLOGGER_COLOUR_CLEAR},
                                CLOGGER_FOREGROUND_INTENSE);
        printf("[EXPECTED NULLPTR]");
        clog_reset_console_colour();

        printf(" >> AT ADDRESS %p\n", value_ptr);
    }
    va_end(args);

    return condition;
}

CLoggerBool clog_expect_int8_is_not_nullptr(const CLoggerInt8* value_ptr, const char* location, const char* message,
                                            ...)
{
    int condition = value_ptr != NULL;

    va_list args;

    va_start(args, message);
    if (!evaluate_expect(condition, location, message, args))
    {
        clog_set_console_colour((CLoggerConsoleColour) {CLOGGER_COLOUR_YELLOW, CLOGGER_COLOUR_CLEAR},
                                CLOGGER_FOREGROUND_INTENSE);
        printf("[RECEIVED NULLPTR]");
        clog_reset_console_colour();
    }
    va_end(args);

    return condition;
}

CLoggerBool clog_expect_uint8_eq(CLoggerUInt8 expected, CLoggerUInt8 actual, const char* location, const char* message,
                                 ...)
{
    int condition = expected == actual;
    va_list args;

    va_start(args, message);
    if (!evaluate_expect(condition, location, message, args))
    {
        clog_set_console_colour((CLoggerConsoleColour) {CLOGGER_COLOUR_YELLOW, CLOGGER_COLOUR_CLEAR},
                                CLOGGER_FOREGROUND_INTENSE);
        printf("[EXPECTED RESULT]");
        clog_reset_console_colour();

        printf(" >> %u\n", expected);

        clog_set_console_colour((CLoggerConsoleColour) {CLOGGER_COLOUR_YELLOW, CLOGGER_COLOUR_CLEAR},
                                CLOGGER_FOREGROUND_INTENSE);
        printf("[ACTUAL RESULT]");
        clog_reset_console_colour();

        printf(" >> %u\n", actual);
    }
    va_end(args);

    return condition;
}

CLoggerBool clog_expect_uint8_neq(CLoggerUInt8 not_expected, CLoggerUInt8 actual, const char* location,
                                  const char* message, ...)
{
    int condition = not_expected != actual;
    va_list args;

    va_start(args, message);
    if (!evaluate_expect(condition, location, message, args))
    {
        clog_set_console_colour((CLoggerConsoleColour) {CLOGGER_COLOUR_YELLOW, CLOGGER_COLOUR_CLEAR},
                                CLOGGER_FOREGROUND_INTENSE);
        printf("[EXPECTED RESULT]");
        clog_reset_console_colour();

        printf(" >> NOT %u\n", not_expected);

        clog_set_console_colour((CLoggerConsoleColour) {CLOGGER_COLOUR_YELLOW, CLOGGER_COLOUR_CLEAR},
                                CLOGGER_FOREGROUND_INTENSE);
        printf("[ACTUAL RESULT]");
        clog_reset_console_colour();

        printf(" >> %u\n", actual);
    }
    va_end(args);

    return condition;
}

CLoggerBool clog_expect_uint8_is_nullptr(const CLoggerUInt8* value_ptr, const char* location, const char* message, ...)
{
    int condition = value_ptr == NULL;

    va_list args;

    va_start(args, message);
    if (!evaluate_expect(condition, location, message, args))
    {
        clog_set_console_colour((CLoggerConsoleColour) {CLOGGER_COLOUR_YELLOW, CLOGGER_COLOUR_CLEAR},
                                CLOGGER_FOREGROUND_INTENSE);
        printf("[EXPECTED NULLPTR]");
        clog_reset_console_colour();

        printf(" >> AT ADDRESS %p\n", value_ptr);
    }
    va_end(args);

    return condition;
}

CLoggerBool clog_expect_uint8_is_not_nullptr(const CLoggerUInt8* value_ptr, const char* location, const char* message,
                                             ...)
{
    int condition = value_ptr != NULL;

    va_list args;

    va_start(args, message);
    if (!evaluate_expect(condition, location, message, args))
    {
        clog_set_console_colour((CLoggerConsoleColour) {CLOGGER_COLOUR_YELLOW, CLOGGER_COLOUR_CLEAR},
                                CLOGGER_FOREGROUND_INTENSE);
        printf("[RECEIVED NULLPTR]");
        clog_reset_console_colour();
    }
    va_end(args);

    return condition;
}

CLoggerBool clog_expect_int16_eq(CLoggerInt16 expected, CLoggerInt16 actual, const char* location, const char* message,
                                 ...)
{
    int condition = expected == actual;
    va_list args;

    va_start(args, message);
    if (!evaluate_expect(condition, location, message, args))
    {
        clog_set_console_colour((CLoggerConsoleColour) {CLOGGER_COLOUR_YELLOW, CLOGGER_COLOUR_CLEAR},
                                CLOGGER_FOREGROUND_INTENSE);
        printf("[EXPECTED RESULT]");
        clog_reset_console_colour();

        printf(" >> %d\n", expected);

        clog_set_console_colour((CLoggerConsoleColour) {CLOGGER_COLOUR_YELLOW, CLOGGER_COLOUR_CLEAR},
                                CLOGGER_FOREGROUND_INTENSE);
        printf("[ACTUAL RESULT]");
        clog_reset_console_colour();

        printf(" >> %d\n", actual);
    }
    va_end(args);

    return condition;
}

CLoggerBool clog_expect_int16_neq(CLoggerInt16 not_expected, CLoggerInt16 actual, const char* location,
                                  const char* message, ...)
{
    int condition = not_expected != actual;
    va_list args;

    va_start(args, message);
    if (!evaluate_expect(condition, location, message, args))
    {
        clog_set_console_colour((CLoggerConsoleColour) {CLOGGER_COLOUR_YELLOW, CLOGGER_COLOUR_CLEAR},
                                CLOGGER_FOREGROUND_INTENSE);
        printf("[EXPECTED RESULT]");
        clog_reset_console_colour();

        printf(" >> NOT %d\n", not_expected);

        clog_set_console_colour((CLoggerConsoleColour) {CLOGGER_COLOUR_YELLOW, CLOGGER_COLOUR_CLEAR},
                                CLOGGER_FOREGROUND_INTENSE);
        printf("[ACTUAL RESULT]");
        clog_reset_console_colour();

        printf(" >> %d\n", actual);
    }
    va_end(args);

    return condition;
}

CLoggerBool clog_expect_int16_is_nullptr(const CLoggerInt16* value_ptr, const char* location, const char* message, ...)
{
    int condition = value_ptr == NULL;

    va_list args;

    va_start(args, message);
    if (!evaluate_expect(condition, location, message, args))
    {
        clog_set_console_colour((CLoggerConsoleColour) {CLOGGER_COLOUR_YELLOW, CLOGGER_COLOUR_CLEAR},
                                CLOGGER_FOREGROUND_INTENSE);
        printf("[EXPECTED NULLPTR]");
        clog_reset_console_colour();

        printf(" >> AT ADDRESS %p\n", value_ptr);
    }
    va_end(args);

    return condition;
}

CLoggerBool clog_expect_int16_is_not_nullptr(const CLoggerInt16* value_ptr, const char* location, const char* message,
                                             ...)
{
    int condition = value_ptr != NULL;

    va_list args;

    va_start(args, message);
    if (!evaluate_expect(condition, location, message, args))
    {
        clog_set_console_colour((CLoggerConsoleColour) {CLOGGER_COLOUR_YELLOW, CLOGGER_COLOUR_CLEAR},
                                CLOGGER_FOREGROUND_INTENSE);
        printf("[RECEIVED NULLPTR]");
        clog_reset_console_colour();
    }
    va_end(args);

    return condition;
}

CLoggerBool clog_expect_uint16_eq(CLoggerUInt16 expected, CLoggerUInt16 actual, const char* location,
                                  const char* message, ...)
{
    int condition = expected == actual;
    va_list args;

    va_start(args, message);
    if (!evaluate_expect(condition, location, message, args))
    {
        clog_set_console_colour((CLoggerConsoleColour) {CLOGGER_COLOUR_YELLOW, CLOGGER_COLOUR_CLEAR},
                                CLOGGER_FOREGROUND_INTENSE);
        printf("[EXPECTED RESULT]");
        clog_reset_console_colour();

        printf(" >> %u\n", expected);

        clog_set_console_colour((CLoggerConsoleColour) {CLOGGER_COLOUR_YELLOW, CLOGGER_COLOUR_CLEAR},
                                CLOGGER_FOREGROUND_INTENSE);
        printf("[ACTUAL RESULT]");
        clog_reset_console_colour();

        printf(" >> %u\n", actual);
    }
    va_end(args);

    return condition;
}

CLoggerBool clog_expect_uint16_neq(CLoggerUInt16 not_expected, CLoggerUInt16 actual, const char* location,
                                   const char* message, ...)
{
    int condition = not_expected != actual;
    va_list args;

    va_start(args, message);
    if (!evaluate_expect(condition, location, message, args))
    {
        clog_set_console_colour((CLoggerConsoleColour) {CLOGGER_COLOUR_YELLOW, CLOGGER_COLOUR_CLEAR},
                                CLOGGER_FOREGROUND_INTENSE);
        printf("[EXPECTED RESULT]");
        clog_reset_console_colour();

        printf(" >> NOT %u\n", not_expected);

        clog_set_console_colour((CLoggerConsoleColour) {CLOGGER_COLOUR_YELLOW, CLOGGER_COLOUR_CLEAR},
                                CLOGGER_FOREGROUND_INTENSE);
        printf("[ACTUAL RESULT]");
        clog_reset_console_colour();

        printf(" >> %u\n", actual);
    }
    va_end(args);

    return condition;
}

CLoggerBool clog_expect_uint16_is_nullptr(const CLoggerUInt16* value_ptr, const char* location, const char* message,
                                          ...)
{
    int condition = value_ptr == NULL;

    va_list args;

    va_start(args, message);
    if (!evaluate_expect(condition, location, message, args))
    {
        clog_set_console_colour((CLoggerConsoleColour) {CLOGGER_COLOUR_YELLOW, CLOGGER_COLOUR_CLEAR},
                                CLOGGER_FOREGROUND_INTENSE);
        printf("[EXPECTED NULLPTR]");
        clog_reset_console_colour();

        printf(" >> AT ADDRESS %p\n", value_ptr);
    }
    va_end(args);

    return condition;
}

CLoggerBool clog_expect_uint16_is_not_nullptr(const CLoggerUInt16* value_ptr, const char* location, const char* message,
                                              ...)
{
    int condition = value_ptr != NULL;

    va_list args;

    va_start(args, message);
    if (!evaluate_expect(condition, location, message, args))
    {
        clog_set_console_colour((CLoggerConsoleColour) {CLOGGER_COLOUR_YELLOW, CLOGGER_COLOUR_CLEAR},
                                CLOGGER_FOREGROUND_INTENSE);
        printf("[RECEIVED NULLPTR]");
        clog_reset_console_colour();
    }
    va_end(args);

    return condition;
}

CLoggerBool clog_expect_int32_eq(CLoggerInt32 expected, CLoggerInt32 actual, const char* location, const char* message,
                                 ...)
{
    int condition = expected == actual;
    va_list args;

    va_start(args, message);
    if (!evaluate_expect(condition, location, message, args))
    {
        clog_set_console_colour((CLoggerConsoleColour) {CLOGGER_COLOUR_YELLOW, CLOGGER_COLOUR_CLEAR},
                                CLOGGER_FOREGROUND_INTENSE);
        printf("[EXPECTED RESULT]");
        clog_reset_console_colour();

        printf(" >> %d\n", expected);

        clog_set_console_colour((CLoggerConsoleColour) {CLOGGER_COLOUR_YELLOW, CLOGGER_COLOUR_CLEAR},
                                CLOGGER_FOREGROUND_INTENSE);
        printf("[ACTUAL RESULT]");
        clog_reset_console_colour();

        printf(" >> %d\n", actual);
    }
    va_end(args);

    return condition;
}

CLoggerBool clog_expect_int32_neq(CLoggerInt32 not_expected, CLoggerInt32 actual, const char* location,
                                  const char* message, ...)
{
    int condition = not_expected != actual;
    va_list args;

    va_start(args, message);
    if (!evaluate_expect(condition, location, message, args))
    {
        clog_set_console_colour((CLoggerConsoleColour) {CLOGGER_COLOUR_YELLOW, CLOGGER_COLOUR_CLEAR},
                                CLOGGER_FOREGROUND_INTENSE);
        printf("[EXPECTED RESULT]");
        clog_reset_console_colour();

        printf(" >> NOT %d\n", not_expected);

        clog_set_console_colour((CLoggerConsoleColour) {CLOGGER_COLOUR_YELLOW, CLOGGER_COLOUR_CLEAR},
                                CLOGGER_FOREGROUND_INTENSE);
        printf("[ACTUAL RESULT]");
        clog_reset_console_colour();

        printf(" >> %d\n", actual);
    }
    va_end(args);

    return condition;
}

CLoggerBool clog_expect_int32_is_nullptr(const CLoggerInt32* value_ptr, const char* location, const char* message, ...)
{
    int condition = value_ptr == NULL;

    va_list args;

    va_start(args, message);
    if (!evaluate_expect(condition, location, message, args))
    {
        clog_set_console_colour((CLoggerConsoleColour) {CLOGGER_COLOUR_YELLOW, CLOGGER_COLOUR_CLEAR},
                                CLOGGER_FOREGROUND_INTENSE);
        printf("[EXPECTED NULLPTR]");
        clog_reset_console_colour();

        printf(" >> AT ADDRESS %p\n", value_ptr);
    }
    va_end(args);

    return condition;
}

CLoggerBool clog_expect_int32_is_not_nullptr(const CLoggerInt32* value_ptr, const char* location, const char* message,
                                             ...)
{
    int condition = value_ptr != NULL;

    va_list args;

    va_start(args, message);
    if (!evaluate_expect(condition, location, message, args))
    {
        clog_set_console_colour((CLoggerConsoleColour) {CLOGGER_COLOUR_YELLOW, CLOGGER_COLOUR_CLEAR},
                                CLOGGER_FOREGROUND_INTENSE);
        printf("[RECEIVED NULLPTR]");
        clog_reset_console_colour();
    }
    va_end(args);

    return condition;
}

CLoggerBool clog_expect_uint32_eq(CLoggerUInt32 expected, CLoggerUInt32 actual, const char* location,
                                  const char* message, ...)
{
    int condition = expected == actual;
    va_list args;

    va_start(args, message);
    if (!evaluate_expect(condition, location, message, args))
    {
        clog_set_console_colour((CLoggerConsoleColour) {CLOGGER_COLOUR_YELLOW, CLOGGER_COLOUR_CLEAR},
                                CLOGGER_FOREGROUND_INTENSE);
        printf("[EXPECTED RESULT]");
        clog_reset_console_colour();

        printf(" >> %u\n", expected);

        clog_set_console_colour((CLoggerConsoleColour) {CLOGGER_COLOUR_YELLOW, CLOGGER_COLOUR_CLEAR},
                                CLOGGER_FOREGROUND_INTENSE);
        printf("[ACTUAL RESULT]");
        clog_reset_console_colour();

        printf(" >> %u\n", actual);
    }
    va_end(args);

    return condition;
}

CLoggerBool clog_expect_uint32_neq(CLoggerUInt32 not_expected, CLoggerUInt32 actual, const char* location,
                                   const char* message, ...)
{
    int condition = not_expected != actual;
    va_list args;

    va_start(args, message);
    if (!evaluate_expect(condition, location, message, args))
    {
        clog_set_console_colour((CLoggerConsoleColour) {CLOGGER_COLOUR_YELLOW, CLOGGER_COLOUR_CLEAR},
                                CLOGGER_FOREGROUND_INTENSE);
        printf("[EXPECTED RESULT]");
        clog_reset_console_colour();

        printf(" >> NOT %u\n", not_expected);

        clog_set_console_colour((CLoggerConsoleColour) {CLOGGER_COLOUR_YELLOW, CLOGGER_COLOUR_CLEAR},
                                CLOGGER_FOREGROUND_INTENSE);
        printf("[ACTUAL RESULT]");
        clog_reset_console_colour();

        printf(" >> %u\n", actual);
    }
    va_end(args);

    return condition;
}

CLoggerBool clog_expect_uint32_is_nullptr(const CLoggerUInt32* value_ptr, const char* location, const char* message,
                                          ...)
{
    int condition = value_ptr == NULL;

    va_list args;

    va_start(args, message);
    if (!evaluate_expect(condition, location, message, args))
    {
        clog_set_console_colour((CLoggerConsoleColour) {CLOGGER_COLOUR_YELLOW, CLOGGER_COLOUR_CLEAR},
                                CLOGGER_FOREGROUND_INTENSE);
        printf("[EXPECTED NULLPTR]");
        clog_reset_console_colour();

        printf(" >> AT ADDRESS %p\n", value_ptr);
    }
    va_end(args);

    return condition;
}

CLoggerBool clog_expect_uint32_is_not_nullptr(const CLoggerUInt32* value_ptr, const char* location, const char* message,
                                              ...)
{
    int condition = value_ptr != NULL;

    va_list args;

    va_start(args, message);
    if (!evaluate_expect(condition, location, message, args))
    {
        clog_set_console_colour((CLoggerConsoleColour) {CLOGGER_COLOUR_YELLOW, CLOGGER_COLOUR_CLEAR},
                                CLOGGER_FOREGROUND_INTENSE);
        printf("[RECEIVED NULLPTR]");
        clog_reset_console_colour();
    }
    va_end(args);

    return condition;
}

CLoggerBool clog_expect_int64_eq(CLoggerInt64 expected, CLoggerInt64 actual, const char* location, const char* message,
                                 ...)
{
    int condition = expected == actual;
    va_list args;

    va_start(args, message);
    if (!evaluate_expect(condition, location, message, args))
    {
        clog_set_console_colour((CLoggerConsoleColour) {CLOGGER_COLOUR_YELLOW, CLOGGER_COLOUR_CLEAR},
                                CLOGGER_FOREGROUND_INTENSE);
        printf("[EXPECTED RESULT]");
        clog_reset_console_colour();

        printf(" >> %ld\n", (long) expected);

        clog_set_console_colour((CLoggerConsoleColour) {CLOGGER_COLOUR_YELLOW, CLOGGER_COLOUR_CLEAR},
                                CLOGGER_FOREGROUND_INTENSE);
        printf("[ACTUAL RESULT]");
        clog_reset_console_colour();

        printf(" >> %ld\n", (long) actual);
    }
    va_end(args);

    return condition;
}

CLoggerBool clog_expect_int64_neq(CLoggerInt64 not_expected, CLoggerInt64 actual, const char* location,
                                  const char* message, ...)
{
    int condition = not_expected != actual;
    va_list args;

    va_start(args, message);
    if (!evaluate_expect(condition, location, message, args))
    {
        clog_set_console_colour((CLoggerConsoleColour) {CLOGGER_COLOUR_YELLOW, CLOGGER_COLOUR_CLEAR},
                                CLOGGER_FOREGROUND_INTENSE);
        printf("[EXPECTED RESULT]");
        clog_reset_console_colour();

        printf(" >> NOT %ld\n", (long) not_expected);

        clog_set_console_colour((CLoggerConsoleColour) {CLOGGER_COLOUR_YELLOW, CLOGGER_COLOUR_CLEAR},
                                CLOGGER_FOREGROUND_INTENSE);
        printf("[ACTUAL RESULT]");
        clog_reset_console_colour();

        printf(" >> %ld\n", (long) actual);
    }
    va_end(args);

    return condition;
}

CLoggerBool clog_expect_int64_is_nullptr(const CLoggerInt64* value_ptr, const char* location, const char* message, ...)
{
    int condition = value_ptr == NULL;

    va_list args;

    va_start(args, message);
    if (!evaluate_expect(condition, location, message, args))
    {
        clog_set_console_colour((CLoggerConsoleColour) {CLOGGER_COLOUR_YELLOW, CLOGGER_COLOUR_CLEAR},
                                CLOGGER_FOREGROUND_INTENSE);
        printf("[EXPECTED NULLPTR]");
        clog_reset_console_colour();

        printf(" >> AT ADDRESS %p\n", value_ptr);
    }
    va_end(args);

    return condition;
}

CLoggerBool clog_expect_int64_is_not_nullptr(const CLoggerInt64* value_ptr, const char* location, const char* message,
                                             ...)
{
    int condition = value_ptr != NULL;

    va_list args;

    va_start(args, message);
    if (!evaluate_expect(condition, location, message, args))
    {
        clog_set_console_colour((CLoggerConsoleColour) {CLOGGER_COLOUR_YELLOW, CLOGGER_COLOUR_CLEAR},
                                CLOGGER_FOREGROUND_INTENSE);
        printf("[RECEIVED NULLPTR]");
        clog_reset_console_colour();
    }
    va_end(args);

    return condition;
}

CLoggerBool clog_expect_uint64_eq(CLoggerUInt64 expected, CLoggerUInt64 actual, const char* location,
                                  const char* message, ...)
{
    int condition = expected == actual;
    va_list args;

    va_start(args, message);
    if (!evaluate_expect(condition, location, message, args))
    {
        clog_set_console_colour((CLoggerConsoleColour) {CLOGGER_COLOUR_YELLOW, CLOGGER_COLOUR_CLEAR}, 0);
        printf("[EXPECTED RESULT]");
        clog_reset_console_colour();

        printf(" >> %lu\n", (unsigned long) expected);

        clog_set_console_colour((CLoggerConsoleColour) {CLOGGER_COLOUR_YELLOW, CLOGGER_COLOUR_CLEAR},
                                CLOGGER_FOREGROUND_INTENSE);
        printf("[ACTUAL RESULT]");
        clog_reset_console_colour();

        printf(" >> %lu\n", (unsigned long) actual);
    }
    va_end(args);

    return condition;
}

CLoggerBool clog_expect_uint64_neq(CLoggerUInt64 not_expected, CLoggerUInt64 actual, const char* location,
                                   const char* message, ...)
{
    int condition = not_expected != actual;
    va_list args;

    va_start(args, message);
    if (!evaluate_expect(condition, location, message, args))
    {
        clog_set_console_colour((CLoggerConsoleColour) {CLOGGER_COLOUR_YELLOW, CLOGGER_COLOUR_CLEAR},
                                CLOGGER_FOREGROUND_INTENSE);
        printf("[EXPECTED RESULT]");
        clog_reset_console_colour();

        printf(" >> NOT %lu\n", (unsigned long) not_expected);

        clog_set_console_colour((CLoggerConsoleColour) {CLOGGER_COLOUR_YELLOW, CLOGGER_COLOUR_CLEAR},
                                CLOGGER_FOREGROUND_INTENSE);
        printf("[ACTUAL RESULT]");
        clog_reset_console_colour();

        printf(" >> %lu\n", (unsigned long) actual);
    }
    va_end(args);

    return condition;
}

CLoggerBool clog_expect_uint64_is_nullptr(const CLoggerUInt64* value_ptr, const char* location, const char* message,
                                          ...)
{
    int condition = value_ptr == NULL;

    va_list args;

    va_start(args, message);
    if (!evaluate_expect(condition, location, message, args))
    {
        clog_set_console_colour((CLoggerConsoleColour) {CLOGGER_COLOUR_YELLOW, CLOGGER_COLOUR_CLEAR},
                                CLOGGER_FOREGROUND_INTENSE);
        printf("[EXPECTED NULLPTR]");
        clog_reset_console_colour();

        printf(" >> AT ADDRESS %p\n", value_ptr);
    }
    va_end(args);

    return condition;
}

CLoggerBool clog_expect_uint64_is_not_nullptr(const CLoggerUInt64* value_ptr, const char* location, const char* message,
                                              ...)
{
    int condition = value_ptr != NULL;

    va_list args;

    va_start(args, message);
    if (!evaluate_expect(condition, location, message, args))
    {
        clog_set_console_colour((CLoggerConsoleColour) {CLOGGER_COLOUR_YELLOW, CLOGGER_COLOUR_CLEAR},
                                CLOGGER_FOREGROUND_INTENSE);
        printf("[RECEIVED NULLPTR]");
        clog_reset_console_colour();
    }
    va_end(args);

    return condition;
}

CLoggerBool clog_expect_size_eq(CLoggerSize expected, CLoggerSize actual, const char* location, const char* message,
                                ...)
{
    int condition = expected == actual;
    va_list args;

    va_start(args, message);
    if (!evaluate_expect(condition, location, message, args))
    {
        clog_set_console_colour((CLoggerConsoleColour) {CLOGGER_COLOUR_YELLOW, CLOGGER_COLOUR_CLEAR},
                                CLOGGER_FOREGROUND_INTENSE);
        printf("[EXPECTED RESULT]");
        clog_reset_console_colour();

        printf(" >> %d\n", expected);

        clog_set_console_colour((CLoggerConsoleColour) {CLOGGER_COLOUR_YELLOW, CLOGGER_COLOUR_CLEAR},
                                CLOGGER_FOREGROUND_INTENSE);
        printf("[ACTUAL RESULT]");
        clog_reset_console_colour();

        printf(" >> %d\n", actual);
    }
    va_end(args);

    return condition;
}

CLoggerBool clog_expect_size_neq(CLoggerSize not_expected, CLoggerSize actual, const char* location,
                                 const char* message, ...)
{
    int condition = not_expected != actual;
    va_list args;

    va_start(args, message);
    if (!evaluate_expect(condition, location, message, args))
    {
        clog_set_console_colour((CLoggerConsoleColour) {CLOGGER_COLOUR_YELLOW, CLOGGER_COLOUR_CLEAR},
                                CLOGGER_FOREGROUND_INTENSE);
        printf("[EXPECTED RESULT]");
        clog_reset_console_colour();

        printf(" >> NOT %d\n", not_expected);

        clog_set_console_colour((CLoggerConsoleColour) {CLOGGER_COLOUR_YELLOW, CLOGGER_COLOUR_CLEAR},
                                CLOGGER_FOREGROUND_INTENSE);
        printf("[ACTUAL RESULT]");
        clog_reset_console_colour();

        printf(" >> %d\n", actual);
    }
    va_end(args);

    return condition;
}

CLoggerBool clog_expect_char_eq(char expected, char actual, const char* location, const char* message, ...)
{
    int condition = expected == actual;
    va_list args;

    va_start(args, message);
    if (!evaluate_expect(condition, location, message, args))
    {
        clog_set_console_colour((CLoggerConsoleColour) {CLOGGER_COLOUR_YELLOW, CLOGGER_COLOUR_CLEAR},
                                CLOGGER_FOREGROUND_INTENSE);
        printf("[EXPECTED RESULT]");
        clog_reset_console_colour();

        printf(" >> %c\n", expected);

        clog_set_console_colour((CLoggerConsoleColour) {CLOGGER_COLOUR_YELLOW, CLOGGER_COLOUR_CLEAR},
                                CLOGGER_FOREGROUND_INTENSE);
        printf("[ACTUAL RESULT]");
        clog_reset_console_colour();

        printf(" >> %c\n", actual);
    }
    va_end(args);

    return condition;
}

CLoggerBool clog_expect_char_neq(char not_expected, char actual, const char* location, const char* message, ...)
{
    int condition = not_expected != actual;
    va_list args;

    va_start(args, message);
    if (!evaluate_expect(condition, location, message, args))
    {
        clog_set_console_colour((CLoggerConsoleColour) {CLOGGER_COLOUR_YELLOW, CLOGGER_COLOUR_CLEAR},
                                CLOGGER_FOREGROUND_INTENSE);
        printf("[EXPECTED RESULT]");
        clog_reset_console_colour();

        printf(" >> NOT %c\n", not_expected);

        clog_set_console_colour((CLoggerConsoleColour) {CLOGGER_COLOUR_YELLOW, CLOGGER_COLOUR_CLEAR},
                                CLOGGER_FOREGROUND_INTENSE);
        printf("[ACTUAL RESULT]");
        clog_reset_console_colour();

        printf(" >> %c\n", actual);
    }
    va_end(args);

    return condition;
}

CLoggerBool clog_expect_str_eq(const char* expected, CLoggerSize expected_size, const char* actual,
                               CLoggerSize actual_size, const char* location, const char* message, ...)
{
    int condition = strncmp(expected, actual, expected_size) == 0;
    va_list args;

    va_start(args, message);
    if (!evaluate_expect(condition, location, message, args))
    {
        clog_set_console_colour((CLoggerConsoleColour) {CLOGGER_COLOUR_YELLOW, CLOGGER_COLOUR_CLEAR},
                                CLOGGER_FOREGROUND_INTENSE);
        printf("[EXPECTED RESULT]");
        clog_reset_console_colour();

        printf(" >> %s (%d bytes)\n", expected, expected_size);

        clog_set_console_colour((CLoggerConsoleColour) {CLOGGER_COLOUR_YELLOW, CLOGGER_COLOUR_CLEAR},
                                CLOGGER_FOREGROUND_INTENSE);
        printf("[ACTUAL RESULT]");
        clog_reset_console_colour();

        printf(" >> %s (%d bytes)\n", actual, actual_size);
    }
    va_end(args);

    return condition;
}

CLoggerBool clog_expect_str_neq(const char* not_expected, CLoggerSize not_expected_size, const char* actual,
                                CLoggerSize actual_size, const char* location, const char* message, ...)
{
    int condition = strncmp(not_expected, actual, not_expected_size) != 0;
    va_list args;

    va_start(args, message);
    if (!evaluate_expect(condition, location, message, args))
    {
        clog_set_console_colour((CLoggerConsoleColour) {CLOGGER_COLOUR_YELLOW, CLOGGER_COLOUR_CLEAR},
                                CLOGGER_FOREGROUND_INTENSE);
        printf("[EXPECTED RESULT]");
        clog_reset_console_colour();

        printf(" >> %s (%d bytes)\n", not_expected, not_expected_size);

        clog_set_console_colour((CLoggerConsoleColour) {CLOGGER_COLOUR_YELLOW, CLOGGER_COLOUR_CLEAR},
                                CLOGGER_FOREGROUND_INTENSE);
        printf("[ACTUAL RESULT]");
        clog_reset_console_colour();

        printf(" >> %s (%d bytes)\n", actual, actual_size);
    }
    va_end(args);

    return condition;
}

CLoggerBool clog_expect_str_is_nullptr(const char* value_ptr, const char* location, const char* message, ...)
{
    int condition = value_ptr == NULL;

    va_list args;

    va_start(args, message);
    if (!evaluate_expect(condition, location, message, args))
    {
        clog_set_console_colour((CLoggerConsoleColour) {CLOGGER_COLOUR_YELLOW, CLOGGER_COLOUR_CLEAR},
                                CLOGGER_FOREGROUND_INTENSE);
        printf("[EXPECTED NULLPTR]");
        clog_reset_console_colour();

        printf(" >> AT ADDRESS %p\n", value_ptr);
    }
    va_end(args);

    return condition;
}

CLoggerBool clog_expect_str_is_not_nullptr(const char* value_ptr, const char* location, const char* message, ...)
{
    int condition = value_ptr != NULL;

    va_list args;

    va_start(args, message);
    if (!evaluate_expect(condition, location, message, args))
    {
        clog_set_console_colour((CLoggerConsoleColour) {CLOGGER_COLOUR_YELLOW, CLOGGER_COLOUR_CLEAR},
                                CLOGGER_FOREGROUND_INTENSE);
        printf("[RECEIVED NULLPTR]");
        clog_reset_console_colour();
    }
    va_end(args);

    return condition;
}

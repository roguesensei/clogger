//! @file
//! @brief clogger expectation module

#ifndef CLOGGER_CLOG_EXPECT_H
#define CLOGGER_CLOG_EXPECT_H

#ifdef __cplusplus
extern "C" {
#endif

#include "core.h"

/// @brief Assertion function that does not terminate the program on failure
/// @details The expect function works similarly to the traditional std `assert()` function, logging a message if
/// the condition supplied fails, without terminating on failure. See the other specialized functions in the
/// `clog_expect` family below for more explicit assert messages.
/// @note For the fatal variant, see `clog_assert()` and the family of `clog_assert` functions
/// @param condition [in] Assertion to be made
/// @param location [in] Location of the assert
/// @param message [in] Format-able string message as you would use `printf()` that will print on the condition
/// failure
/// @param ... [in] Variable-length args
/// @return Assertion result
CLoggerBool clog_expect(CLoggerBool condition, const char* location, const char* message, ...);

/// @brief Make an equality non-fatal assertion of two 8-bit signed integers
/// @param expected [in] The expected value
/// @param actual [in] The actual value
/// @param location [in] Location of the assert
/// @param message [in] Format-able string message as you would use `printf()` that will print on the condition
/// failure
/// @param ... [in] Variable-length args
/// @return Assertion result
CLoggerBool clog_expect_int8_eq(CLoggerInt8 expected, CLoggerInt8 actual, const char* location, const char* message,
                                ...);

/// @brief Make an inequality non-fatal assertion of two 8-bit signed integers
/// @param not_expected [in] The not expected value
/// @param actual [in] The actual value
/// @param location [in] Location of the assert
/// @param message [in] Format-able string message as you would use `printf()` that will print on the condition
/// failure
/// @param ... [in] Variable-length args
/// @return Assertion result
CLoggerBool clog_expect_int8_neq(CLoggerInt8 not_expected, CLoggerInt8 actual, const char* location,
                                 const char* message, ...);

/// @brief Assert if a pointer is `NULL` without terminating
/// @param value_ptr [in] Pointer to a 8-bit signed integer
/// @param location [in] Location of the assert
/// @param message [in] Format-able string message as you would use `printf()` that will print on the condition
/// failure
/// @param ... [in] Variable-length args
/// @return Assertion result
CLoggerBool clog_expect_int8_is_nullptr(const CLoggerInt8* value_ptr, const char* location, const char* message, ...);

/// @brief Assert if a pointer is not `NULL` without terminating
/// @param value_ptr [in] Pointer to a 8-bit signed integer
/// @param location [in] Location of the assert
/// @param message [in] Format-able string message as you would use `printf()` that will print on the condition
/// failure
/// @param ... [in] Variable-length args
/// @return Assertion result
CLoggerBool clog_expect_int8_is_not_nullptr(const CLoggerInt8* value_ptr, const char* location, const char* message,
                                            ...);

/// @brief Make an equality non-fatal assertion of two 8-bit unsigned integers
/// @param expected [in] The expected value
/// @param actual [in] The actual value
/// @param location [in] Location of the assert
/// @param message [in] Format-able string message as you would use `printf()` that will print on the condition
/// failure
/// @param ... [in] Variable-length args
/// @return Assertion result
CLoggerBool clog_expect_uint8_eq(CLoggerUInt8 expected, CLoggerUInt8 actual, const char* location, const char* message,
                                 ...);

/// @brief Make an inequality non-fatal assertion of two 8-bit unsigned integers
/// @param not_expected [in] The not expected value
/// @param actual [in] The actual value
/// @param location [in] Location of the assert
/// @param message [in] Format-able string message as you would use `printf()` that will print on the condition
/// failure
/// @param ... [in] Variable-length args
/// @return Assertion result
CLoggerBool clog_expect_uint8_neq(CLoggerUInt8 not_expected, CLoggerUInt8 actual, const char* location,
                                  const char* message, ...);

/// @brief Assert if a pointer is `NULL` without terminating
/// @param value_ptr [in] Pointer to a 8-bit unsigned integer
/// @param location [in] Location of the assert
/// @param message [in] Format-able string message as you would use `printf()` that will print on the condition
/// failure
/// @param ... [in] Variable-length args
/// @return Assertion result
CLoggerBool clog_expect_uint8_is_nullptr(const CLoggerUInt8* value_ptr, const char* location, const char* message, ...);

/// @brief Assert if a pointer is not `NULL` without terminating
/// @param value_ptr [in] Pointer to a 8-bit unsigned integer
/// @param location [in] Location of the assert
/// @param message [in] Format-able string message as you would use `printf()` that will print on the condition
/// failure
/// @param ... [in] Variable-length args
/// @return Assertion result
CLoggerBool clog_expect_uint8_is_not_nullptr(const CLoggerUInt8* value_ptr, const char* location, const char* message,
                                             ...);

/// @brief Make an equality non-fatal assertion of two 16-bit signed integers
/// @param expected [in] The expected value
/// @param actual [in] The actual value
/// @param location [in] Location of the assert
/// @param message [in] Format-able string message as you would use `printf()` that will print on the condition
/// failure
/// @param ... [in] Variable-length args
/// @return Assertion result
CLoggerBool clog_expect_int16_eq(CLoggerInt16 expected, CLoggerInt16 actual, const char* location, const char* message,
                                 ...);

/// @brief Make an inequality non-fatal assertion of two 16-bit signed integers
/// @param not_expected [in] The not expected value
/// @param actual [in] The actual value
/// @param location [in] Location of the assert
/// @param message [in] Format-able string message as you would use `printf()` that will print on the condition
/// failure
/// @param ... [in] Variable-length args
/// @return Assertion result
CLoggerBool clog_expect_int16_neq(CLoggerInt16 not_expected, CLoggerInt16 actual, const char* location,
                                  const char* message, ...);

/// @brief Assert if a pointer is `NULL` without terminating
/// @param value_ptr [in] Pointer to a 16-bit signed integer
/// @param location [in] Location of the assert
/// @param message [in] Format-able string message as you would use `printf()` that will print on the condition
/// failure
/// @param ... [in] Variable-length args
/// @return Assertion result
CLoggerBool clog_expect_int16_is_nullptr(const CLoggerInt16* value_ptr, const char* location, const char* message, ...);

/// @brief Assert if a pointer is not `NULL` without terminating
/// @param value_ptr [in] Pointer to a 16-bit signed integer
/// @param location [in] Location of the assert
/// @param message [in] Format-able string message as you would use `printf()` that will print on the condition
/// failure
/// @param ... [in] Variable-length args
/// @return Assertion result
CLoggerBool clog_expect_int16_is_not_nullptr(const CLoggerInt16* value_ptr, const char* location, const char* message,
                                             ...);

/// @brief Make an equality non-fatal assertion of two 16-bit unsigned integers
/// @param expected [in] The expected value
/// @param actual [in] The actual value
/// @param location [in] Location of the assert
/// @param message [in] Format-able string message as you would use `printf()` that will print on the condition
/// failure
/// @param ... [in] Variable-length args
/// @return Assertion result
CLoggerBool clog_expect_uint16_eq(CLoggerUInt16 expected, CLoggerUInt16 actual, const char* location,
                                  const char* message, ...);

/// @brief Make an inequality non-fatal assertion of two 16-bit unsigned integers
/// @param not_expected [in] The not expected value
/// @param actual [in] The actual value
/// @param location [in] Location of the assert
/// @param message [in] Format-able string message as you would use `printf()` that will print on the condition
/// failure
/// @param ... [in] Variable-length args
/// @return Assertion result
CLoggerBool clog_expect_uint16_neq(CLoggerUInt16 not_expected, CLoggerUInt16 actual, const char* location,
                                   const char* message, ...);

/// @brief Assert if a pointer is `NULL` without terminating
/// @param value_ptr [in] Pointer to a 16-bit unsigned integer
/// @param location [in] Location of the assert
/// @param message [in] Format-able string message as you would use `printf()` that will print on the condition
/// failure
/// @param ... [in] Variable-length args
/// @return Assertion result
CLoggerBool clog_expect_uint16_is_nullptr(const CLoggerUInt16* value_ptr, const char* location, const char* message,
                                          ...);

/// @brief Assert if a pointer is not `NULL` without terminating
/// @param value_ptr [in] Pointer to a 16-bit unsigned integer
/// @param location [in] Location of the assert
/// @param message [in] Format-able string message as you would use `printf()` that will print on the condition
/// failure
/// @param ... [in] Variable-length args
/// @return Assertion result
CLoggerBool clog_expect_uint16_is_not_nullptr(const CLoggerUInt16* value_ptr, const char* location, const char* message,
                                              ...);

/// @brief Make an equality non-fatal assertion of two 32-bit signed integers
/// @param expected [in] The expected value
/// @param actual [in] The actual value
/// @param location [in] Location of the assert
/// @param message [in] Format-able string message as you would use `printf()` that will print on the condition
/// failure
/// @param ... [in] Variable-length args
/// @return Assertion result
CLoggerBool clog_expect_int32_eq(CLoggerInt32 expected, CLoggerInt32 actual, const char* location, const char* message,
                                 ...);

/// @brief Make an inequality non-fatal assertion of two 32-bit signed integers
/// @param not_expected [in] The not expected value
/// @param actual [in] The actual value
/// @param location [in] Location of the assert
/// @param message [in] Format-able string message as you would use `printf()` that will print on the condition
/// failure
/// @param ... [in] Variable-length args
/// @return Assertion result
CLoggerBool clog_expect_int32_neq(CLoggerInt32 not_expected, CLoggerInt32 actual, const char* location,
                                  const char* message, ...);

/// @brief Assert if a pointer is `NULL` without terminating
/// @param value_ptr [in] Pointer to a 32-bit signed integer
/// @param location [in] Location of the assert
/// @param message [in] Format-able string message as you would use `printf()` that will print on the condition
/// failure
/// @param ... [in] Variable-length args
/// @return Assertion result
CLoggerBool clog_expect_int32_is_nullptr(const CLoggerInt32* value_ptr, const char* location, const char* message, ...);

/// @brief Assert if a pointer is not `NULL` without terminating
/// @param value_ptr [in] Pointer to a 32-bit signed integer
/// @param location [in] Location of the assert
/// @param message [in] Format-able string message as you would use `printf()` that will print on the condition
/// failure
/// @param ... [in] Variable-length args
/// @return Assertion result
CLoggerBool clog_expect_int32_is_not_nullptr(const CLoggerInt32* value_ptr, const char* location, const char* message,
                                             ...);

/// @brief Make an equality non-fatal assertion of two 32-bit unsigned integers
/// @param expected [in] The expected value
/// @param actual [in] The actual value
/// @param location [in] Location of the assert
/// @param message [in] Format-able string message as you would use `printf()` that will print on the condition
/// failure
/// @param ... [in] Variable-length args
/// @return Assertion result
CLoggerBool clog_expect_uint32_eq(CLoggerUInt32 expected, CLoggerUInt32 actual, const char* location,
                                  const char* message, ...);

/// @brief Make an inequality non-fatal assertion of two 32-bit unsigned integers
/// @param not_expected [in] The not expected value
/// @param actual [in] The actual value
/// @param location [in] Location of the assert
/// @param message [in] Format-able string message as you would use `printf()` that will print on the condition
/// failure
/// @param ... [in] Variable-length args
/// @return Assertion result
CLoggerBool clog_expect_uint32_neq(CLoggerUInt32 not_expected, CLoggerUInt32 actual, const char* location,
                                   const char* message, ...);

/// @brief Assert if a pointer is `NULL` without terminating
/// @param value_ptr [in] Pointer to a 32-bit unsigned integer
/// @param location [in] Location of the assert
/// @param message [in] Format-able string message as you would use `printf()` that will print on the condition
/// failure
/// @param ... [in] Variable-length args
/// @return Assertion result
CLoggerBool clog_expect_uint32_is_nullptr(const CLoggerUInt32* value_ptr, const char* location, const char* message,
                                          ...);

/// @brief Assert if a pointer is not `NULL` without terminating
/// @param value_ptr [in] Pointer to a 32-bit unsigned integer
/// @param location [in] Location of the assert
/// @param message [in] Format-able string message as you would use `printf()` that will print on the condition
/// failure
/// @param ... [in] Variable-length args
/// @return Assertion result
CLoggerBool clog_expect_uint32_is_not_nullptr(const CLoggerUInt32* value_ptr, const char* location, const char* message,
                                              ...);

/// @brief Make an equality non-fatal assertion of two 64-bit signed integers
/// @param expected [in] The expected value
/// @param actual [in] The actual value
/// @param location [in] Location of the assert
/// @param message [in] Format-able string message as you would use `printf()` that will print on the condition
/// failure
/// @param ... [in] Variable-length args
/// @return Assertion result
CLoggerBool clog_expect_int64_eq(int64_t expected, CLoggerInt64 actual, const char* location, const char* message, ...);

/// @brief Make an inequality non-fatal assertion of two 64-bit signed integers
/// @param not_expected [in] The not expected value
/// @param actual [in] The actual value
/// @param location [in] Location of the assert
/// @param message [in] Format-able string message as you would use `printf()` that will print on the condition
/// failure
/// @param ... [in] Variable-length args
/// @return Assertion result
CLoggerBool clog_expect_int64_neq(CLoggerInt64 not_expected, CLoggerInt64 actual, const char* location,
                                  const char* message, ...);

/// @brief Assert if a pointer is `NULL` without terminating
/// @param value_ptr [in] Pointer to a 64-bit signed integer
/// @param location [in] Location of the assert
/// @param message [in] Format-able string message as you would use `printf()` that will print on the condition
/// failure
/// @param ... [in] Variable-length args
/// @return Assertion result
CLoggerBool clog_expect_int64_is_nullptr(const CLoggerInt64* value_ptr, const char* location, const char* message, ...);

/// @brief Assert if a pointer is not `NULL` without terminating
/// @param value_ptr [in] Pointer to a 64-bit signed integer
/// @param location [in] Location of the assert
/// @param message [in] Format-able string message as you would use `printf()` that will print on the condition
/// failure
/// @param ... [in] Variable-length args
/// @return Assertion result
CLoggerBool clog_expect_int64_is_not_nullptr(const CLoggerInt64* value_ptr, const char* location, const char* message,
                                             ...);

/// @brief Make an equality non-fatal assertion of two 64-bit unsigned integers
/// @param expected [in] The expected value
/// @param actual [in] The actual value
/// @param location [in] Location of the assert
/// @param message [in] Format-able string message as you would use `printf()` that will print on the condition
/// failure
/// @param ... [in] Variable-length args
/// @return Assertion result
CLoggerBool clog_expect_uint64_eq(CLoggerUInt64 expected, CLoggerUInt64 actual, const char* location,
                                  const char* message, ...);

/// @brief Make an inequality non-fatal assertion of two 64-bit unsigned integers
/// @param not_expected [in] The not expected value
/// @param actual [in] The actual value
/// @param location [in] Location of the assert
/// @param message [in] Format-able string message as you would use `printf()` that will print on the condition
/// failure
/// @param ... [in] Variable-length args
/// @return Assertion result
CLoggerBool clog_expect_uint64_neq(CLoggerUInt64 not_expected, CLoggerUInt64 actual, const char* location,
                                   const char* message, ...);

/// @brief Assert if a pointer is `NULL` without terminating
/// @param value_ptr [in] Pointer to a 64-bit unsigned integer
/// @param location [in] Location of the assert
/// @param message [in] Format-able string message as you would use `printf()` that will print on the condition
/// failure
/// @param ... [in] Variable-length args
/// @return Assertion result
CLoggerBool clog_expect_uint64_is_nullptr(const CLoggerUInt64* value_ptr, const char* location, const char* message,
                                          ...);

/// @brief Assert if a pointer is not `NULL` without terminating
/// @param value_ptr [in] Pointer to a 64-bit unsigned integer
/// @param location [in] Location of the assert
/// @param message [in] Format-able string message as you would use `printf()` that will print on the condition
/// failure
/// @param ... [in] Variable-length args
/// @return Assertion result
CLoggerBool clog_expect_uint64_is_not_nullptr(const CLoggerUInt64* value_ptr, const char* location, const char* message,
                                              ...);

/// @brief Make an equality non-fatal assertion of two `size_t` values
/// @param expected [in] The expected value
/// @param actual [in] The actual value
/// @param location [in] Location of the assert
/// @param message [in] Format-able string message as you would use `printf()` that will print on the condition
/// failure
/// @param ... [in] Variable-length args
CLoggerBool clog_expect_size_eq(CLoggerSize expected, CLoggerSize actual, const char* location, const char* message,
                                ...);

/// @brief Make an inequality non-fatal assertion of two `size_t` values
/// @param not_expected [in] The not expected value
/// @param actual [in] The actual value
/// @param location [in] Location of the assert
/// @param message [in] Format-able string message as you would use `printf()` that will print on the condition
/// failure
/// @param ... [in] Variable-length args
/// @return Assertion result
CLoggerBool clog_expect_size_neq(CLoggerSize not_expected, CLoggerSize actual, const char* location,
                                 const char* message, ...);

/// @brief Make an equality non-fatal assertion of two chars
/// @note Although similar to `clog_expect_int8_eq()`, the values written to the console will be the char ASCII
/// value
/// @param expected [in] The expected value
/// @param actual [in] The actual value
/// @param location [in] Location of the assert
/// @param message [in] Format-able string message as you would use `printf()` that will print on the condition
/// failure
/// @param ... [in] Variable-length args
/// @return Assertion result
CLoggerBool clog_expect_char_eq(char expected, char actual, const char* location, const char* message, ...);

/// @brief Make an inequality non-fatal assertion of two chars
/// @note Although similar to `clog_expect_int8_neq()`, the values written to the console will be the char ASCII
/// value
/// @param not_expected [in] The not expected value
/// @param actual [in] The actual value
/// @param location [in] Location of the assert
/// @param message [in] Format-able string message as you would use `printf()` that will print on the condition
/// failure
/// @param ... [in] Variable-length args
/// @return Assertion result
CLoggerBool clog_expect_char_neq(char not_expected, char actual, const char* location, const char* message, ...);

/// @brief Make an equality non-fatal assertion of two strings
/// @param expected [in] The expected value
/// @param expected_size [in] The `sizeof` the expected string
/// @param actual [in] The actual value
/// @param actual_size [in] The `sizeof` the actual string
/// @param location [in] Location of the assert
/// @param message [in] Format-able string message as you would use `printf()` that will print on the condition
/// failure
/// @param ... [in] Variable-length args
/// @return Assertion result
CLoggerBool clog_expect_str_eq(const char* expected, CLoggerSize expected_size, const char* actual,
                               CLoggerSize actual_size, const char* location, const char* message, ...);

/// @brief Make an inequality non-fatal assertion of two strings
/// @param not_expected [in] The not expected value
/// @param not_expected_size [in] The `sizeof` the not expected string
/// @param actual [in] The actual value
/// @param actual_size [in] The `sizeof` the actual string
/// @param location [in] Location of the assert
/// @param message [in] Format-able string message as you would use `printf()` that will print on the condition
/// failure
/// @param ... [in] Variable-length args
/// @return Assertion result
CLoggerBool clog_expect_str_neq(const char* not_expected, CLoggerSize not_expected_size, const char* actual,
                                CLoggerSize actual_size, const char* location, const char* message, ...);

/// @brief Assert if a pointer is `NULL` without terminating
/// @param value_ptr [in] Pointer to a string or char
/// @param location [in] Location of the assert
/// @param message [in] Format-able string message as you would use `printf()` that will print on the condition
/// failure
/// @param ... [in] Variable-length args
/// @return Assertion result
CLoggerBool clog_expect_str_is_nullptr(const char* value_ptr, const char* location, const char* message, ...);

/// @brief Assert if a pointer is not `NULL` without terminating
/// @param value_ptr [in] Pointer to a string or char
/// @param location [in] Location of the assert
/// @param message [in] Format-able string message as you would use `printf()` that will print on the condition
/// failure
/// @param ... [in] Variable-length args
/// @return Assertion result
CLoggerBool clog_expect_str_is_not_nullptr(const char* value_ptr, const char* location, const char* message, ...);

#ifdef __cplusplus
}
#endif

#endif // CLOGGER_CLOG_EXPECT_H

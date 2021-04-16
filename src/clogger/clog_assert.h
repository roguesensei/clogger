//! @file
//! @brief clogger assertion module

#ifndef CLOGGER_CLOG_ASSERT_H
#define CLOGGER_CLOG_ASSERT_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

/// @brief Assertion function that terminates the program on failure
/// @details The assert function works similarly to the traditional std `assert()` function, logging a message if the condition supplied fails, terminating on failure. See the other specialized functions in the `clog_assert` family below for more explicit assert messages.
/// @note For the non-fatal variant, see `clog_expect()` and the family of `clog_expect` functions
/// @param condition [in] Assertion to be made
/// @param location [in] Location of the assert
/// @param message [in] Format-able string message as you would use `printf()` that will print on the condition failure
/// @param ... [in] Variable-length args
void clog_assert(int condition, const char* location, const char* message, ...);

/// @brief Make an equality assertion of two 8-bit signed integers
/// @param expected [in] The expected value
/// @param actual [in] The actual value
/// @param location [in] Location of the assert
/// @param message [in] Format-able string message as you would use `printf()` that will print on the condition failure
/// @param ... [in] Variable-length args
void clog_assert_int8_eq(int8_t expected, int8_t actual, const char* location, const char* message, ...);

/// @brief Make an inequality assertion of two 8-bit signed integers
/// @param not_expected [in] The not expected value
/// @param actual [in] The actual value
/// @param location [in] Location of the assert
/// @param message [in] Format-able string message as you would use `printf()` that will print on the condition failure
/// @param ... [in] Variable-length args
void clog_assert_int8_neq(int8_t not_expected, int8_t actual, const char* location, const char* message, ...);

/// @brief Assert if a pointer is `NULL`
/// @param value_ptr [in] Pointer to an 8-bit integer
/// @param location [in] Location of the assert
/// @param message [in] Format-able string message as you would use `printf()` that will print on the condition failure
/// @param ... [in] Variable-length args
void clog_assert_int8_is_nullptr(const int8_t* value_ptr, const char* location, const char* message, ...);

/// @brief Assert if a pointer is not `NULL`
/// @param value_ptr [in] Pointer to an 8-bit integer
/// @param location [in] Location of the assert
/// @param message [in] Format-able string message as you would use `printf()` that will print on the condition failure
/// @param ... [in] Variable-length args
void clog_assert_int8_is_not_nullptr(const int8_t* value_ptr, const char* location, const char* message, ...);

/// @brief Make an equality assertion of two 8-bit unsigned integers
/// @param expected [in] The expected value
/// @param actual [in] The actual value
/// @param location [in] Location of the assert
/// @param message [in] Format-able string message as you would use `printf()` that will print on the condition failure
/// @param ... [in] Variable-length args
void clog_assert_uint8_eq(uint8_t expected, uint8_t actual, const char* location, const char* message, ...);

/// @brief Make an inequality assertion of two 8-bit unsigned integers
/// @param not_expected [in] The not expected value
/// @param actual [in] The actual value
/// @param location [in] Location of the assert
/// @param message [in] Format-able string message as you would use `printf()` that will print on the condition failure
/// @param ... [in] Variable-length args
void clog_assert_uint8_neq(uint8_t not_expected, uint8_t actual, const char* location, const char* message, ...);

/// @brief Make an equality assertion of two 16-bit signed integers
/// @param expected [in] The expected value
/// @param actual [in] The actual value
/// @param location [in] Location of the assert
/// @param message [in] Format-able string message as you would use `printf()` that will print on the condition failure
/// @param ... [in] Variable-length args
void clog_assert_int16_eq(int16_t expected, int16_t actual, const char* location, const char* message, ...);

/// @brief Make an inequality assertion of two 16-bit signed integers
/// @param not_expected [in] The not expected value
/// @param actual [in] The actual value
/// @param location [in] Location of the assert
/// @param message [in] Format-able string message as you would use `printf()` that will print on the condition failure
/// @param ... [in] Variable-length args
void clog_assert_int16_neq(int16_t not_expected, int16_t actual, const char* location, const char* message, ...);

/// @brief Make an equality assertion of two 16-bit unsigned integers
/// @param expected [in] The expected value
/// @param actual [in] The actual value
/// @param location [in] Location of the assert
/// @param message [in] Format-able string message as you would use `printf()` that will print on the condition failure
/// @param ... [in] Variable-length args
void clog_assert_uint16_eq(uint16_t expected, uint16_t actual, const char* location, const char* message, ...);

/// @brief Make an inequality assertion of two 16-bit unsigned integers
/// @param not_expected [in] The not expected value
/// @param actual [in] The actual value
/// @param location [in] Location of the assert
/// @param message [in] Format-able string message as you would use `printf()` that will print on the condition failure
/// @param ... [in] Variable-length args
void clog_assert_uint16_neq(uint16_t not_expected, uint16_t actual, const char* location, const char* message, ...);

/// @brief Make an equality assertion of two 32-bit signed integers
/// @param expected [in] The expected value
/// @param actual [in] The actual value
/// @param location [in] Location of the assert
/// @param message [in] Format-able string message as you would use `printf()` that will print on the condition failure
/// @param ... [in] Variable-length args
void clog_assert_int32_eq(int32_t expected, int32_t actual, const char* location, const char* message, ...);

/// @brief Make an inequality assertion of two 32-bit signed integers
/// @param not_expected [in] The not expected value
/// @param actual [in] The actual value
/// @param location [in] Location of the assert
/// @param message [in] Format-able string message as you would use `printf()` that will print on the condition failure
/// @param ... [in] Variable-length args
void clog_assert_int32_neq(int32_t not_expected, int32_t actual, const char* location, const char* message, ...);

/// @brief Make an equality assertion of two 32-bit unsigned integers
/// @param expected [in] The expected value
/// @param actual [in] The actual value
/// @param location [in] Location of the assert
/// @param message [in] Format-able string message as you would use `printf()` that will print on the condition failure
/// @param ... [in] Variable-length args
void clog_assert_uint32_eq(uint32_t expected, uint32_t actual, const char* location, const char* message, ...);

/// @brief Make an inequality assertion of two 32-bit unsigned integers
/// @param not_expected [in] The not expected value
/// @param actual [in] The actual value
/// @param location [in] Location of the assert
/// @param message [in] Format-able string message as you would use `printf()` that will print on the condition failure
/// @param ... [in] Variable-length args
void clog_assert_uint32_neq(uint32_t not_expected, uint32_t actual, const char* location, const char* message, ...);

/// @brief Make an equality assertion of two 64-bit signed integers
/// @param expected [in] The expected value
/// @param actual [in] The actual value
/// @param location [in] Location of the assert
/// @param message [in] Format-able string message as you would use `printf()` that will print on the condition failure
/// @param ... [in] Variable-length args
void clog_assert_int64_eq(int64_t expected, int64_t actual, const char* location, const char* message, ...);

/// @brief Make an inequality assertion of two 64-bit signed integers
/// @param not_expected [in] The not expected value
/// @param actual [in] The actual value
/// @param location [in] Location of the assert
/// @param message [in] Format-able string message as you would use `printf()` that will print on the condition failure
/// @param ... [in] Variable-length args
void clog_assert_int64_neq(int64_t not_expected, int64_t actual, const char* location, const char* message, ...);

/// @brief Make an equality assertion of two 64-bit unsigned integers
/// @param expected [in] The expected value
/// @param actual [in] The actual value
/// @param location [in] Location of the assert
/// @param message [in] Format-able string message as you would use `printf()` that will print on the condition failure
/// @param ... [in] Variable-length args
void clog_assert_uint64_eq(uint64_t expected, uint64_t actual, const char* location, const char* message, ...);

/// @brief Make an inequality assertion of two 64-bit unsigned integers
/// @param not_expected [in] The not expected value
/// @param actual [in] The actual value
/// @param location [in] Location of the assert
/// @param message [in] Format-able string message as you would use `printf()` that will print on the condition failure
/// @param ... [in] Variable-length args
void clog_assert_uint64_neq(uint64_t not_expected, uint64_t actual, const char* location, const char* message, ...);

/// @brief Make an equality assertion of two `size_t` values
/// @param expected [in] The expected value
/// @param actual [in] The actual value
/// @param location [in] Location of the assert
/// @param message [in] Format-able string message as you would use `printf()` that will print on the condition failure
/// @param ... [in] Variable-length args
void clog_assert_size_eq(size_t expected, size_t actual, const char* location, const char* message, ...);

/// @brief Make an inequality assertion of two `size_t` values
/// @param not_expected [in] The not expected value
/// @param actual [in] The actual value
/// @param location [in] Location of the assert
/// @param message [in] Format-able string message as you would use `printf()` that will print on the condition failure
/// @param ... [in] Variable-length args
void clog_assert_size_neq(size_t not_expected, size_t actual, const char* location, const char* message, ...);

/// @brief Make an equality assertion of two chars
/// @note Although similar to `clog_assert_int8_eq()`, the values written to the console will be the char ASCII value
/// @param expected [in] The expected value
/// @param actual [in] The actual value
/// @param location [in] Location of the assert
/// @param message [in] Format-able string message as you would use `printf()` that will print on the condition failure
/// @param ... [in] Variable-length args
void clog_assert_char_eq(char expected, char actual, const char* location, const char* message, ...);

/// @brief Make an equality assertion of two chars
/// @param not_expected [in] The not expected value
/// @param actual [in] The actual value
/// @param location [in] Location of the assert
/// @param message [in] Format-able string message as you would use `printf()` that will print on the condition failure
/// @param ... [in] Variable-length args
void clog_assert_char_neq(char not_expected, char actual, const char* location, const char* message, ...);

/// @brief Make an equality assertion of two strings
/// @param expected [in] The expected value
/// @param expected_size [in] The `sizeof` the expected string
/// @param actual [in] The actual value
/// @param actual_size [in] The `sizeof` the actual string
/// @param location [in] Location of the assert
/// @param message [in] Format-able string message as you would use `printf()` that will print on the condition failure
/// @param ... [in] Variable-length args
void clog_assert_str_eq(const char* expected, size_t expected_size, const char* actual, size_t actual_size,
                        const char* location, const char* message, ...);

/// @brief Make an inequality assertion of two strings
/// @param not_expected [in] The not expected value
/// @param not_expected_size [in] The `sizeof` the not expected string
/// @param actual [in] The actual value
/// @param actual_size [in] The `sizeof` the actual string
/// @param location [in] Location of the assert
/// @param message [in] Format-able string message as you would use `printf()` that will print on the condition failure
/// @param ... [in] Variable-length args
void clog_assert_str_neq(const char* not_expected, size_t not_expected_size, const char* actual, size_t actual_size,
                         const char* location, const char* message, ...);

/// @brief Assertion function that does not terminate the program on failure
/// @details The expect function works similarly to the traditional std `assert()` function, logging a message if the condition supplied fails, without terminating on failure. See the other specialized functions in the `clog_expect` family below for more explicit assert messages.
/// @note For the fatal variant, see `clog_assert()` and the family of `clog_assert` functions
/// @param condition [in] Assertion to be made
/// @param location [in] Location of the assert
/// @param message [in] Format-able string message as you would use `printf()` that will print on the condition failure
/// @param ... [in] Variable-length args
/// @return Assertion result
int clog_expect(int condition, const char* location, const char* message, ...);

/// @brief Make an equality non-fatal assertion of two 32-bit signed integers
/// @param expected [in] The expected value
/// @param actual [in] The actual value
/// @param location [in] Location of the assert
/// @param message [in] Format-able string message as you would use `printf()` that will print on the condition failure
/// @param ... [in] Variable-length args
/// @return Assertion result
int clog_expect_int32_eq(int expected, int actual, const char* location, const char* message, ...);

#ifdef __cplusplus
}
#endif

#endif //CLOGGER_CLOG_ASSERT_H

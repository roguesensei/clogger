//! @file
//! @brief clogger assertion module

#ifndef CLOGGER_CLOG_ASSERT_H
#define CLOGGER_CLOG_ASSERT_H

#include <stddef.h>

/// @brief Assertion function that terminates the program on failure
/// @note For the non-fatal variant, see `clog_expect()` and the family of `expect` functions
/// @param condition [in] Assertion to be made
/// @param location [in] Location of the log
/// @param message [in] Format-able string message as you would use `printf()`
/// @param ... [in] Variable-length args
void clog_assert(int condition, const char* location, const char* message, ...);

/// @brief Make an equality assertion of two 16-bit signed integers
/// @param expected [in] The expected value
/// @param actual [in] The actual value
/// @param location [in] Location of the log
/// @param message [in] Format-able string message as you would use `printf()`
/// @param ... [in] Variable-length args
void clog_assert_int16_eq(short expected, short actual, const char* location, const char* message, ...);

/// @brief Make an inequality assertion of two 16-bit signed integers
/// @param not_expected [in] The not expected value
/// @param actual [in] The actual value
/// @param location [in] Location of the log
/// @param message [in] Format-able string message as you would use `printf()`
/// @param ... [in] Variable-length args
void clog_assert_int16_neq(short not_expected, short actual, const char* location, const char* message, ...);

/// @brief Make an equality assertion of two 16-bit unsigned integers
/// @param expected [in] The expected value
/// @param actual [in] The actual value
/// @param location [in] Location of the log
/// @param message [in] Format-able string message as you would use `printf()`
/// @param ... [in] Variable-length args
void clog_assert_uint16_eq(unsigned short expected, unsigned short actual, const char* location, const char* message, ...);

/// @brief Make an inequality assertion of two 16-bit unsigned integers
/// @param not_expected [in] The not expected value
/// @param actual [in] The actual value
/// @param location [in] Location of the log
/// @param message [in] Format-able string message as you would use `printf()`
/// @param ... [in] Variable-length args
void clog_assert_uint16_neq(unsigned short not_expected, unsigned short actual, const char* location, const char* message, ...);

/// @brief Make an equality assertion of two 32-bit signed integers
/// @param expected [in] The expected value
/// @param actual [in] The actual value
/// @param location [in] Location of the log
/// @param message [in] Format-able string message as you would use `printf()`
/// @param ... [in] Variable-length args
void clog_assert_int32_eq(int expected, int actual, const char* location, const char* message, ...);

/// @brief Make an inequality assertion of two 32-bit signed integers
/// @param not_expected [in] The not expected value
/// @param actual [in] The actual value
/// @param location [in] Location of the log
/// @param message [in] Format-able string message as you would use `printf()`
/// @param ... [in] Variable-length args
void clog_assert_int32_neq(int not_expected, int actual, const char* location, const char* message, ...);

/// @brief Make an equality assertion of two 32-bit unsigned integers
/// @param expected [in] The expected value
/// @param actual [in] The actual value
/// @param location [in] Location of the log
/// @param message [in] Format-able string message as you would use `printf()`
/// @param ... [in] Variable-length args
void clog_assert_uint32_eq(unsigned int expected, unsigned int actual, const char* location, const char* message, ...);

/// @brief Make an inequality assertion of two 32-bit unsigned integers
/// @param not_expected [in] The not expected value
/// @param actual [in] The actual value
/// @param location [in] Location of the log
/// @param message [in] Format-able string message as you would use `printf()`
/// @param ... [in] Variable-length args
void clog_assert_uint32_neq(unsigned int not_expected, unsigned int actual, const char* location, const char* message, ...);

/// @brief Make an equality assertion of two 64-bit signed integers
/// @param expected [in] The expected value
/// @param actual [in] The actual value
/// @param location [in] Location of the log
/// @param message [in] Format-able string message as you would use `printf()`
/// @param ... [in] Variable-length args
void clog_assert_int64_eq(long expected, long actual, const char* location, const char* message, ...);

/// @brief Make an inequality assertion of two 64-bit signed integers
/// @param not_expected [in] The not expected value
/// @param actual [in] The actual value
/// @param location [in] Location of the log
/// @param message [in] Format-able string message as you would use `printf()`
/// @param ... [in] Variable-length args
void clog_assert_int64_neq(long not_expected, long actual, const char* location, const char* message, ...);

/// @brief Make an equality assertion of two 64-bit unsigned integers
/// @param expected [in] The expected value
/// @param actual [in] The actual value
/// @param location [in] Location of the log
/// @param message [in] Format-able string message as you would use `printf()`
/// @param ... [in] Variable-length args
void clog_assert_uint64_eq(unsigned long expected, unsigned long actual, const char* location, const char* message, ...);

/// @brief Make an inequality assertion of two 64-bit unsigned integers
/// @param not_expected [in] The not expected value
/// @param actual [in] The actual value
/// @param location [in] Location of the log
/// @param message [in] Format-able string message as you would use `printf()`
/// @param ... [in] Variable-length args
void clog_assert_uint64_neq(unsigned long not_expected, unsigned long actual, const char* location, const char* message, ...);

/// @brief Make an equality assertion of two `size_t` values
/// @param expected [in] The expected value
/// @param actual [in] The actual value
/// @param location [in] Location of the log
/// @param message [in] Format-able string message as you would use `printf()`
/// @param ... [in] Variable-length args
void clog_assert_size_eq(size_t expected, size_t actual, const char* location, const char* message, ...);

/// @brief Make an inequality assertion of two `size_t` values
/// @param not_expected [in] The not expected value
/// @param actual [in] The actual value
/// @param location [in] Location of the log
/// @param message [in] Format-able string message as you would use `printf()`
/// @param ... [in] Variable-length args
void clog_assert_size_neq(size_t not_expected, size_t actual, const char* location, const char* message, ...);

/// @brief Make an equality assertion of two strings
/// @param expected [in] The expected value
/// @param expected_size [in] The `sizeof` the expected string
/// @param actual [in] The actual value
/// @param actual_size [in] The `sizeof` the actual string
/// @param location [in] Location of the log
/// @param message [in] Format-able string message as you would use `printf()`
/// @param ... [in] Variable-length args
void clog_assert_str_eq(const char* expected, size_t expected_size, const char* actual, size_t actual_size, const char* location, const char* message, ...);

/// @brief Make an inequality assertion of two strings
/// @param not_expected [in] The not expected value
/// @param not_expected_size [in] The `sizeof` the not expected string
/// @param actual [in] The actual value
/// @param actual_size [in] The `sizeof` the actual string
/// @param location [in] Location of the log
/// @param message [in] Format-able string message as you would use `printf()`
/// @param ... [in] Variable-length args
void clog_assert_str_neq(const char* not_expected, size_t not_expected_size, const char* actual, size_t actual_size, const char* location, const char* message, ...);

/// @brief Assertion function that does not terminate the program on failure
/// @note For the fatal variant, see `clog_assert()` and the family of `assert` functions
/// @param condition [in] Assertion to be made
/// @param location [in] Location of the log
/// @param message [in] Format-able string message as you would use `printf()`
/// @param ... [in] Variable-length args
/// @return Assertion result
int clog_expect(int condition, const char* location, const char* message, ...);

/// @brief Make an equality non-fatal assertion of two 32-bit signed integers
/// @param expected [in] The expected value
/// @param actual [in] The actual value
/// @param location [in] Location of the log
/// @param message [in] Format-able string message as you would use `printf()`
/// @param ... [in] Variable-length args
/// @return Assertion result
int clog_expect_int32_eq(int expected, int actual, const char* location, const char* message, ...);

#endif //CLOGGER_CLOG_ASSERT_H

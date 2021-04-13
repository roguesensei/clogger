//! @file
//! @brief clogger assertion module

#ifndef CLOGGER_CLOG_ASSERT_H
#define CLOGGER_CLOG_ASSERT_H

#include <stddef.h>

/// @brief Assertion function that terminates the program on failure
/// @param condition [in] Assertion to be made
/// @param location [in] Location of the log
/// @param message [in] Format-able string message as you would use `printf()`
/// @param ... [in] Variable-length args
void clog_assert(int condition, const char* location, const char* message, ...);

void clog_assert_equal_int32(int expected, int actual, const char* location, const char* message, ...);
void clog_assert_equal_uint32(unsigned int expected, unsigned int actual, const char* location, const char* message, ...);
void clog_assert_equal_size(size_t expected, size_t actual, const char* location, const char* message, ...);
void clog_assert_equal_str(const char* expected, size_t expected_size, const char* actual, size_t actual_size, const char* location, const char* message, ...);

/// @brief Assertion function that does not terminate the program on failure
/// @param condition [in] Assertion to be made
/// @param location [in] Location of the log
/// @param message [in] Format-able string message as you would use `printf()`
/// @param ... [in] Variable-length args
/// @return Assertion result
int clog_expect(int condition, const char* location, const char* message, ...);

int clog_expect_equal_int32(int expected, int actual, const char* location, const char* message, ...);

#endif //CLOGGER_CLOG_ASSERT_H

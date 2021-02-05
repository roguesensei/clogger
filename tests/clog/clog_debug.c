#include <stdio.h>

#include <assert.h>
#include <clogger.h>

int main()
{
    // Arrange
    int expected_chars = 0;

    const char* location = __FUNCTION__;
    int num_value = 8;

#ifdef CLOGGER_DEBUG
    expected_chars += printf("[DEBUG] >> ");
    expected_chars += clog_message(location, "Mario looks good in %i-bit", num_value);
#endif

    // Act
    int actual_chars = clog_debug(location, "Mario looks good in %i-bit", num_value);

    // Assert
    assert(expected_chars == actual_chars);
}
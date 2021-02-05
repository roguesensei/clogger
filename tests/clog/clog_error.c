#include <stdio.h>

#include <assert.h>
#include <clogger.h>

int main()
{
    // Arrange
    const char* location = __PRETTY_FUNCTION__;
    int line_number = __LINE__;

    int expected_chars = 0;

    expected_chars += printf("[ERROR] >> ");
    expected_chars += clog_message(location, "An error occurred %d", line_number);

    // Act
    int actual_chars = clog_error(location, "An error occurred %d", line_number);

    // Assert
    assert(expected_chars == actual_chars);
}
#include <stdio.h>

#include <assert.h>
#include <clogger.h>

int main()
{
    // Arrange
    const char* location = __FUNCTION__;
    int line = __LINE__ + 1;
    // set_clogger_debug(CLOGGER_TRUE); // Made you look

    int expected_chars = 0;

    expected_chars += printf("[WARNING] >> ");
    expected_chars += clog_message(location, "%s:%i has enabled debug mode", __FILE__, line);

    // Act
    int actual_chars = clog_warning(location, "%s:%i has enabled debug mode", __FILE__, line);

    // Assert
    assert(expected_chars == actual_chars);
}
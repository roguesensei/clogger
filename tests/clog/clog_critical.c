#include <stdio.h>

#include <assert.h>
#include <clogger.h>

int main()
{
    // Arrange
    const char* location = __FUNCTION__;
    const char* error = "Forgot to call %s";
    const char* reason = "free()";

    int expected_chars = 0;

    expected_chars += printf(CLOGGER_BG_RED"[FATAL]"CLOGGER_RESET_CONSOLE" >> ");
    expected_chars += clog_message(location, error, reason);

    // Act
    int actual_chars = clog_critical(location, error, reason);

    // Assert
    assert(expected_chars == actual_chars);
}
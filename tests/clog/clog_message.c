#include <stdio.h>
#include <stdarg.h>
#include <time.h>

#include <assert.h>
#include <clogger.h>

int expected_behaviour(const char* location, const char* format, ...)
{
    int expected_chars = 0;
    va_list args;

    // Despite the likely different timestamp, the format should still be HH:MM:SS
    char timestamp_buffer[10];
    time_t now = time(NULL);
    struct tm* timestamp = localtime(&now);

    strftime(timestamp_buffer, sizeof timestamp_buffer, "%H:%M:%S", timestamp);

    expected_chars += printf(
            CLOGGER_FG_BOLD_CYN"%s"CLOGGER_RESET_CONSOLE" >> "CLOGGER_FG_BOLD_MAG"%s"CLOGGER_RESET_CONSOLE" >> ",
            timestamp_buffer, location);

    va_start(args, format);
    expected_chars += vprintf(format, args);
    va_end(args);

    expected_chars += printf(CLOGGER_RESET_CONSOLE"\n");

    return expected_chars;
}

int main()
{
    // Arrange
    const char* location = __FUNCTION__;
    const char* message = "Test";

    int expected_chars = expected_behaviour(location, message);

    // Act
    int actual_chars = clog_message(location, message);

    // Assert
    assert(expected_chars == actual_chars);
}
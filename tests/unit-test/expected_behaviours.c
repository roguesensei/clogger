#include "expected_behaviours.h"

#include <stdio.h>
#include <stdarg.h>
#include <time.h>

int test_clog_message_expected(const char* location, const char* format, ...)
{
    int expected_chars = 0;
    va_list args;

    // Despite the likely different timestamp, the format should still be HH:MM:SS
    char timestamp_buffer[10];
    time_t now = time(NULL);
    struct tm* timestamp = localtime(&now);

    strftime(timestamp_buffer, sizeof timestamp_buffer, "%H:%M:%S", timestamp);

    expected_chars += printf("%s >> %s >> ", timestamp_buffer, location);

    va_start(args, format);
    expected_chars += vprintf(format, args);
    va_end(args);

    expected_chars += printf("\n");

    return expected_chars;
}

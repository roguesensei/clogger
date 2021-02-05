#include <assert.h>
#include <clogger.h>

int main()
{
    // Arrange
    int expected_chars = 0;

#ifdef CLOGGER_DEBUG
    expected_chars += printf("[INFO] >> ");
    expected_chars += clog_message(__FUNCTION__, "Debug mode is on");
#endif

    // Act
    int actual_chars = clog_info(__FUNCTION__, "Debug mode is on");

    // Assert
    assert(expected_chars == actual_chars);
}
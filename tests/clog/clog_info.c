#include <assert.h>
#include <clogger.h>

int main()
{
    // Arrange
    int expected_chars = 0; // Leave as 0 as we don't have debug mode turned on

    // Act
    int actual_chars = clog_info(__FUNCTION__, "You can't see me");

    // Assert
    assert(expected_chars == actual_chars);
}
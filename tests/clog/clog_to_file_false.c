#include <assert.h>
#include <clogger.h>

int main()
{
    // Arrange
    clog_bool expected_result = CLOGGER_FALSE;

    // Act
    clog_bool actual_result = clog_to_file("path/to/directory/test.txt", __FUNCTION__, "Test");

    // Assert
    assert(expected_result == actual_result);
}
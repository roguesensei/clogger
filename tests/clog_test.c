#include "unit-test/expected_behaviours.h"

#include <stdio.h>
#include <string.h>

#include <assert.h>
#include <clogger.h>

void clog_message_test()
{
    // Arrange
    const char* location = __FUNCTION__;
    const char* message = "Test";

    int expected_chars = test_clog_message_expected(location, message);

    // Act
    int actual_chars = clog_message(location, message);

    // Assert
    assert(expected_chars == actual_chars);
}

int main(int argc, char* argv[])
{
    char unit_test[strlen(argv[1])];

    strncpy(unit_test, argv[1], strlen(argv[1]));

    if (strncmp(unit_test, "clog_message", strlen(unit_test)) == 1)
    {
        clog_message_test();
    }
    else if (strncmp(unit_test, "clog_info", strlen(unit_test)) == 1)
    {

    }

    return 0;
}
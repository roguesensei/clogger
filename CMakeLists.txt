cmake_minimum_required(VERSION 3.0)
project(clogger VERSION 0.1.3 LANGUAGES C)

set(CMAKE_C_STANDARD 11)

include_directories(include/)

if (CLOGGER_SHARED)
    add_library(clogger SHARED src/clog.c)
else()
    add_library(clogger STATIC src/clog.c)
endif ()

# Unit testing
add_subdirectory(tests/)
enable_testing()

# Add the tests
add_test(NAME clog_message COMMAND clog_message_test)


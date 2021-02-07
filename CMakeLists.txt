cmake_minimum_required(VERSION 3.0)
project(clogger VERSION 0.3.2 LANGUAGES C)

set(CMAKE_C_STANDARD 11)

include_directories(include/)

add_subdirectory(src/)

if (CLOGGER_TESTS)
    enable_testing()

    add_subdirectory(tests/)
endif ()



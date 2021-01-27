cmake_minimum_required(VERSION 3.0)
project(roguesensei-clogger VERSION 0.1.3 LANGUAGES C)

set(CMAKE_C_STANDARD 11)

include_directories(include/)

add_subdirectory(src/)
add_subdirectory(tests/)

enable_testing()

# Unit tests
if (CLOGGER_TESTS)
    add_test(NAME clog_message COMMAND test_clog_message)
    add_test(NAME clog_info COMMAND test_clog_info)
    add_test(NAME clog_debug COMMAND test_clog_debug)
    add_test(NAME clog_warning COMMAND test_clog_warning)
    add_test(NAME clog_error COMMAND test_clog_error)
    add_test(NAME clog_fatal COMMAND test_clog_fatal)
    add_test(NAME clog_to_file_true COMMAND test_clog_to_file_true)
    add_test(NAME clog_to_file_false COMMAND test_clog_to_file_false)
endif ()


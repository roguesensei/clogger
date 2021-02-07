cmake_minimum_required(VERSION 3.0)
project(clogger VERSION 0.3.0 LANGUAGES C)

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
    add_test(NAME clog_critical COMMAND test_clog_critical)
    add_test(NAME clog_to_file_true COMMAND test_clog_to_file_true)
    add_test(NAME clog_to_file_false COMMAND test_clog_to_file_false)
endif ()

add_executable(sandbox sandbox/sandbox.c)
target_link_libraries(sandbox clogger)


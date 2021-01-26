cmake_minimum_required(VERSION 3.0)
project(CLogger VERSION 0.1.3 LANGUAGES C)

set(CMAKE_C_STANDARD 11)

include_directories(include/)

add_subdirectory(src/)
add_subdirectory(tests/)

enable_testing()

# Add the tests
add_test(NAME clog_message COMMAND clog_message_test)


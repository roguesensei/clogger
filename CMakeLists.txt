cmake_minimum_required(VERSION 3.0)
project(clogger VERSION 1.1.0 LANGUAGES C)

message(STATUS "${PROJECT_NAME}: Version ${PROJECT_VERSION}")

set(CMAKE_C_STANDARD 11)

include_directories(include/)

add_library(clogger STATIC src/clog.c src/clog_assert.c src/console.c src/clogger.c)
target_link_libraries(clogger pthread)

add_executable(sandbox sandbox/sandbox.c)
target_link_libraries(sandbox clogger)

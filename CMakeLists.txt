cmake_minimum_required(VERSION 3.0)
project(clogger VERSION 1.2.2 LANGUAGES C)

message(STATUS "${PROJECT_NAME}: Version ${PROJECT_VERSION}")

set(CMAKE_C_STANDARD 11)

include_directories(src/)
include_directories(include/)

add_library(clogger STATIC src/clogger/clog.c src/clogger/clog_assert.c src/clogger/clog_expect.c src/clogger/console.c src/clogger/clogger.c)
target_link_libraries(clogger pthread)

target_precompile_headers(clogger PUBLIC include/clogger_pch.c include/clogger_pch.h)
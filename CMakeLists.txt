cmake_minimum_required(VERSION 3.15)
project(clogger VERSION 1.3.2 LANGUAGES C)

message(STATUS "${PROJECT_NAME}: Version ${PROJECT_VERSION}")

set(CMAKE_C_STANDARD 11)

add_library(clogger STATIC src/clogger/clog.c src/clogger/clog_assert.c src/clogger/clog_expect.c src/clogger/console.c src/clogger/clogger.c)
target_include_directories(clogger PUBLIC src/ include/)
target_precompile_headers(clogger PUBLIC src/clogger_pch.c src/clogger_pch.h)

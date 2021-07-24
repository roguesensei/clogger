cmake_minimum_required(VERSION 3.0)
project(clogger VERSION 1.2.3 LANGUAGES C)

message(STATUS "${PROJECT_NAME}: Version ${PROJECT_VERSION}")

set(CMAKE_C_STANDARD 11)

include_directories(src/)
include_directories(include/)

add_library(clogger STATIC src/clogger/clog.c src/clogger/clog_assert.c src/clogger/clog_expect.c src/clogger/console.c src/clogger/clogger.c)

if (MSVC)
    set_property(TARGET clogger
            PROPERTY VS_PACKAGE_REFERENCES "pthreads_2.9.1.4" # Pthread nuget package for Visual Studio
    )
else ()
    target_link_libraries(clogger pthread)
endif ()


target_precompile_headers(clogger PUBLIC src/clogger_pch.c src/clogger_pch.h)
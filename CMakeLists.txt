cmake_minimum_required(VERSION 3.17)
project(clogger VERSION 0.1.2 LANGUAGES C)

set(CMAKE_C_STANDARD 11)

include_directories(include/)

if (CLOGGER_SHARED)
    add_library(clogger SHARED src/clog.c)
else()
    add_library(clogger STATIC src/clog.c)
endif ()

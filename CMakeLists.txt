cmake_minimum_required(VERSION 3.17)
project(clogger C)

set(CMAKE_C_STANDARD 11)

include_directories(include/)
include_directories(src/)

if (CLOGGER_SHARED)
    add_library(clogger SHARED src/clog.c)
else()
    add_library(clogger STATIC src/clog.c)
endif ()

#if (MY_DEBUG_CONFIG)
#    add_definitions(-DCLOGGER_DEBUG)
#endif ()


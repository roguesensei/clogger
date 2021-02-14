cmake_minimum_required(VERSION 3.0)
project(clogger VERSION 1.0.0 LANGUAGES C)

set(CMAKE_C_STANDARD 11)

include_directories(include/)
add_library(clogger STATIC src/clog.c src/console.c src/clogger.c)

if (WIN32)
    target_link_libraries(clogger windows)
endif ()

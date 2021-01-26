cmake_minimum_required(VERSION 3.0)
project(clogger LANGUAGES C)

if (CLOGGER_SHARED)
    add_library(clogger SHARED clog.c)
else()
    add_library(clogger STATIC clog.c)
endif ()
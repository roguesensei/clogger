cmake_minimum_required(VERSION 3.17)
project(clogger C)

set(CMAKE_C_STANDARD 11)

include_directories(include/)

add_library(clogger STATIC src/clog.c)

cmake_minimum_required(VERSION 3.0)
project(clogger_test LANGUAGES C)

add_executable(clog_message_test clog_message.c)
target_link_libraries(clog_message_test clogger)
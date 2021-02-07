project(clogger_test LANGUAGES C)

add_executable(test_driver clog_test.c unit-test/expected_behaviours.c)
target_link_libraries(test_driver clogger)

add_test(NAME clog_message COMMAND test_driver clog_message)
add_test(NAME clog_info COMMAND test_driver clog_info)


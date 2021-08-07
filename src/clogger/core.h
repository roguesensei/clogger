//! @file
//! @brief Common types and macros used in the library

#ifndef CLOGGER_CORE_H
#define CLOGGER_CORE_H

/// @brief Macro representing `0` or `false`
#define CLOGGER_FALSE 0

/// @brief Macro representing `1` or `true`
#define CLOGGER_TRUE 1

#ifdef __cplusplus
extern "C" {
#endif

/// @brief Enum representing the log message level
typedef enum clog_level
{
    CLOG_LEVEL_MESSAGE, ///< Standard level, not of particular interest
    CLOG_LEVEL_INFO, ///< `INFO` level
    CLOG_LEVEL_DEBUG, ///< `DEBUG` level
    CLOG_LEVEL_WARNING, ///< `WARNING` level
    CLOG_LEVEL_ERROR, ///< `ERROR` level
    CLOG_LEVEL_CRITICAL, ///< `CRITICAL` level
    CLOG_LEVEL_FATAL_ASSERT, ///< A failed assertion that should abort the program
    CLOG_LEVEL_NON_FATAL_ASSERT ///< A failed assertion that should keep calm and carry on
} clog_level_t;

/// @brief Enum representing colours
typedef enum clog_colour
{
    CLEAR, BLACK, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE
} clog_colour_t;

/// @brief Data structure representing a pair of colours used for text in the terminal/console
typedef struct clog_console_colour
{
    clog_colour_t foreground_colour; ///< Colour of the text
    clog_colour_t background_colour; ///< Colour of the text highlight
} clog_console_colour_t;

/// @brief Data structure representing a `clogger`
/// @details This struct is what allows you to configure multiple "logging" instances, with a configurable name, colour, level etc.
typedef struct clogger
{
    const char* name; ///< Name of the `clogger`, such as the project name or module
    void (* error_callback)(clog_level_t level, const char* clogger_name,
                            const char* location); ///< Function pointer that calls on an `ERROR` or `CRITICAL` level message
    clog_console_colour_t console_colour; ///< Colour dictating how the name should display in the console
    clog_level_t log_level; ///< The minimum level to log messages
    unsigned short colour_flags; ///< Flags to modify the colour
    unsigned char file_opt; ///< Flags to determine the file logging options
    char* log_file_path; ///< File log path
} clogger_t;

#ifdef __cplusplus
}
#endif

#endif //CLOGGER_CORE_H

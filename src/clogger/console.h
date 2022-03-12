//! @file
//! @brief Functions to manipulate the console/terminal text colours

#ifndef CLOGGER_CONSOLE_H
#define CLOGGER_CONSOLE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "core.h"

/// @brief Flag to make the text colour intense/bright
#define CLOGGER_FOREGROUND_INTENSE    0x0008

/// @brief Flag to make the text colour highlight intense/bright
#define CLOGGER_BACKGROUND_INTENSE  0x0080

/// @brief Flag to underline the test
#define CLOGGER_UNDERSCORE          0x8000

/// @brief Function to set the text colour in the console
/// @param console_colour [in] Colour of the text
/// @param flags [in] Flags to manipulate the text colour
void clog_set_console_colour(CLoggerConsoleColour console_colour, CLoggerUInt16 flags);

/// @brief Function that resets the text colour back to normal
void clog_reset_console_colour();


/// @brief Function to set the text color in the console
/// @param console_colour [in] Color of the text
/// @param flags [in] Flags to manipulate the text color
void clog_set_console_color(CLoggerConsoleColor console_color, unsigned short flags);

/// @brief Function that resets the text color back to normal
void clog_reset_console_color();

#ifdef __cplusplus
}
#endif

#endif //CLOGGER_CONSOLE_H

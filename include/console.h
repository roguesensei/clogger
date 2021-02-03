#ifndef CLOGGER_CONSOLE_H
#define CLOGGER_CONSOLE_H

#include "core.h"

typedef enum
{
    Black, Red, Green, Yellow, Blue, Magenta, Cyan, White
} clog_colour;

typedef clog_colour clog_color;

CLOGGER_API void clog_set_console_foreground_colour(clog_colour colour, unsigned int* flags);
CLOGGER_API void clog_set_console_background_colour(clog_colour colour);
CLOGGER_API void clog_reset_console_colour();

#endif //CLOGGER_CONSOLE_H

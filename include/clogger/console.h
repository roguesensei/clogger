#ifndef CLOGGER_CONSOLE_H
#define CLOGGER_CONSOLE_H

#include "core.h"

// Based on wincon.h flags
#define CLOGGER_FOREGROUND_INTENSE	0x0008
#define CLOGGER_BACKGROUND_INTENSE  0x0080
#define CLOGGER_UNDERSCORE          0x8000

typedef enum
{
    Clear, Black, Red, Green, Yellow, Blue, Magenta, Cyan, White
} clog_colour;

typedef struct
{
    clog_colour foreground_colour;
    clog_colour background_colour;
} clog_console_colour;

CLOGGER_API void clog_set_console_colour(clog_console_colour console_colour, unsigned short flags);
CLOGGER_API void clog_reset_console_colour();

// US English variants

typedef clog_colour clog_color;
typedef clog_console_colour clog_console_color;

CLOGGER_API void clog_set_console_color(clog_console_color console_color, unsigned short flags);
CLOGGER_API void clog_reset_console_color();

#endif //CLOGGER_CONSOLE_H

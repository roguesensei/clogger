#ifndef CLOGGER_CONSOLE_H
#define CLOGGER_CONSOLE_H

#include "core.h"

typedef enum
{
    Black, Red, Green, Yellow, Blue, Magenta, Cyan, White
} clog_colour;

typedef struct
{
    clog_colour foreground_colour;
    clog_colour background_colour;
} clog_console_colour;

CLOGGER_API int clog_set_console_colour(clog_console_colour console_colour, clog_bool foreground_intense, clog_bool background_intense, unsigned short flags);
CLOGGER_API int clog_reset_console_colour();

// US English variants

typedef clog_colour clog_color;
typedef clog_console_colour clog_console_color;

CLOGGER_API int clog_set_console_color(clog_console_color console_color, clog_bool foreground_intense, clog_bool background_intense, unsigned short flags);
CLOGGER_API int clog_reset_console_color();

#endif //CLOGGER_CONSOLE_H

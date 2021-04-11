#ifndef CLOGGER_CONSOLE_H
#define CLOGGER_CONSOLE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "core.h"

// Based on wincon.h flags
#define CLOGGER_FOREGROUND_INTENSE    0x0008
#define CLOGGER_BACKGROUND_INTENSE  0x0080
#define CLOGGER_UNDERSCORE          0x8000

void clog_set_console_colour(clog_console_colour_t console_colour, unsigned short flags);
void clog_reset_console_colour();

// US English variants

typedef clog_colour_t clog_color_t;
typedef clog_console_colour_t clog_console_color_t;

void clog_set_console_color(clog_console_color_t console_color, unsigned short flags);
void clog_reset_console_color();

#ifdef __cplusplus
}
#endif

#endif //CLOGGER_CONSOLE_H

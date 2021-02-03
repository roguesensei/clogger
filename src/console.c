#include "console.h"

#ifdef WIN32

#include <windows.h>

int
clog_set_console_colour(clog_console_colour console_colour, clog_bool foreground_intense, clog_bool background_intense,
                        unsigned short flags)
{
    WORD windows_flags = 0;

    switch (console_colour.foreground_colour)
    {
        case Black:
            break;
        case Red:
            windows_flags |= FOREGROUND_RED;
            break;
        case Green:
            windows_flags |= FOREGROUND_GREEN;
            break;
        case Yellow:
            windows_flags |= FOREGROUND_RED | FOREGROUND_GREEN;
            break;
        case Blue:
            windows_flags |= FOREGROUND_BLUE;
            break;
        case Magenta:
            windows_flags |= FOREGROUND_RED | FOREGROUND_BLUE;
            break;
        case Cyan:
            windows_flags |= FOREGROUND_GREEN | FOREGROUND_BLUE;
            break;
        case White:
            windows_flags |= FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
            break;
        default:
            break;
    }

    switch (console_colour.background_colour)
    {
        case Black:
            break;
        case Red:
            windows_flags |= BACKGROUND_RED;
            break;
        case Green:
            windows_flags |= BACKGROUND_GREEN;
            break;
        case Yellow:
            windows_flags |= BACKGROUND_RED | BACKGROUND_GREEN;
            break;
        case Blue:
            windows_flags |= BACKGROUND_BLUE;
            break;
        case Magenta:
            windows_flags |= BACKGROUND_RED | BACKGROUND_BLUE;
            break;
        case Cyan:
            windows_flags |= BACKGROUND_GREEN | BACKGROUND_BLUE;
            break;
        case White:
            windows_flags |= BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE;
            break;
        default:
            break;
    }

    if (foreground_intense)
    {
        windows_flags |= FOREGROUND_INTENSITY;
    }

    if (background_intense)
    {
        windows_flags |= BACKGROUND_INTENSITY;
    }

    if (flags != 0)
    {
        windows_flags |= (WORD) flags;
    }

    return SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), windows_flags);
}

int clog_reset_console_colour()
{
    return SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                                   FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);;
}

#else // UNIX implementations

#include "ansi.h"
#include <stdio.h>

int clog_reset_console_colour()
{
    return printf(CLOGGER_RESET_CONSOLE);
}

#endif


// US English variants
int clog_set_console_color(clog_console_color console_color, clog_bool foreground_intense, clog_bool background_intense,
                           unsigned short flags)
{
    return clog_set_console_colour(console_color, foreground_intense, background_intense, flags);
}

int clog_reset_console_color() { return clog_reset_console_colour(); }
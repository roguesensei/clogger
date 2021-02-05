#include "console.h"

#ifdef WIN32

#include <windows.h>

void clog_set_console_colour(clog_console_colour console_colour, unsigned short flags)
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

    if (flags != 0)
    {
        windows_flags |= (WORD) flags;
    }

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), windows_flags);
}

void clog_reset_console_colour()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
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
void clog_set_console_color(clog_console_color console_color, unsigned short flags)
{
    clog_set_console_colour(console_color, flags);
}

void clog_reset_console_color() { clog_reset_console_colour(); }
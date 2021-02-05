#include "console.h"
#include "ansi.h"

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

#include <stdio.h>

void clog_set_console_colour(clog_console_colour console_colour, unsigned short flags)
{
    switch (console_colour.foreground_colour)
    {
        case Black:
            printf("%s", CLOGGER_FOREGROUND_INTENSE & flags ? CLOGGER_FG_HBLK : CLOGGER_UNDERSCORE & flags ? CLOGGER_FG_UL_BLK : CLOGGER_FG_BLK);
            break;
        case Red:
            printf("%s", CLOGGER_FOREGROUND_INTENSE & flags ? CLOGGER_FG_HRED : CLOGGER_UNDERSCORE & flags ? CLOGGER_FG_UL_RED : CLOGGER_FG_RED);
            break;
        case Green:
            printf("%s", CLOGGER_FOREGROUND_INTENSE & flags ? CLOGGER_FG_HGRN : CLOGGER_UNDERSCORE & flags ? CLOGGER_FG_UL_GRN : CLOGGER_FG_GRN);
            break;
        case Yellow:
            printf("%s", CLOGGER_FOREGROUND_INTENSE & flags ? CLOGGER_FG_HYEL : CLOGGER_UNDERSCORE & flags ? CLOGGER_FG_UL_YEL : CLOGGER_FG_YEL);
            break;
        case Blue:
            printf("%s", CLOGGER_FOREGROUND_INTENSE & flags ? CLOGGER_FG_HBLU : CLOGGER_UNDERSCORE & flags ? CLOGGER_FG_UL_BLU : CLOGGER_FG_BLU);
            break;
        case Magenta:
            printf("%s", CLOGGER_FOREGROUND_INTENSE & flags ? CLOGGER_FG_HMAG : CLOGGER_UNDERSCORE & flags ? CLOGGER_FG_UL_MAG : CLOGGER_FG_MAG);
            break;
        case Cyan:
            printf("%s", CLOGGER_FOREGROUND_INTENSE & flags ? CLOGGER_FG_HCYN : CLOGGER_UNDERSCORE & flags ? CLOGGER_FG_UL_CYN : CLOGGER_FG_CYN);
            break;
        case White:
            printf("%s", CLOGGER_FOREGROUND_INTENSE & flags ? CLOGGER_FG_HWHT : CLOGGER_UNDERSCORE & flags ? CLOGGER_FG_UL_WHT : CLOGGER_FG_WHT);
            break;
        default:
            break;
    }

    switch (console_colour.background_colour)
    {
        case Black:
            printf("%s", CLOGGER_BACKGROUND_INTENSE & flags ? CLOGGER_BG_HBLK : CLOGGER_BG_BLK);
            break;
        case Red:
            printf("%s", CLOGGER_BACKGROUND_INTENSE & flags ? CLOGGER_BG_HRED : CLOGGER_BG_RED);
            break;
        case Green:
            printf("%s", CLOGGER_BACKGROUND_INTENSE & flags ? CLOGGER_BG_HGRN : CLOGGER_BG_GRN);
            break;
        case Yellow:
            printf("%s", CLOGGER_BACKGROUND_INTENSE & flags ? CLOGGER_BG_HYEL : CLOGGER_BG_YEL);
            break;
        case Blue:
            printf("%s", CLOGGER_BACKGROUND_INTENSE & flags ? CLOGGER_BG_HBLU : CLOGGER_BG_BLU);
            break;
        case Magenta:
            printf("%s", CLOGGER_BACKGROUND_INTENSE & flags ? CLOGGER_BG_HMAG : CLOGGER_BG_MAG);
            break;
        case Cyan:
            printf("%s", CLOGGER_BACKGROUND_INTENSE & flags ? CLOGGER_BG_HCYN : CLOGGER_BG_CYN);
            break;
        case White:
            printf("%s", CLOGGER_BACKGROUND_INTENSE & flags ? CLOGGER_BG_HWHT : CLOGGER_BG_WHT);
            break;
        default:
            break;
    }
}

void clog_reset_console_colour()
{
    printf(CLOGGER_RESET_CONSOLE);
}

#endif

// US English variants
void clog_set_console_color(clog_console_color console_color, unsigned short flags)
{
    clog_set_console_colour(console_color, flags);
}

void clog_reset_console_color() { clog_reset_console_colour(); }
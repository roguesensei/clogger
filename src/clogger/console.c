#include "console.h"
#include "ansi.h"

#ifdef WIN32

#include <windows.h>

void clog_set_console_colour(CLoggerConsoleColour console_colour, CLoggerUInt16 flags)
{
    WORD windows_flags = 0;

    switch (console_colour.foreground_colour)
    {
        case CLOGGER_COLOUR_BLACK:
            break;
        case CLOGGER_COLOUR_RED:
            windows_flags |= FOREGROUND_RED;
            break;
        case CLOGGER_COLOUR_GREEN:
            windows_flags |= FOREGROUND_GREEN;
            break;
        case CLOGGER_COLOUR_YELLOW:
            windows_flags |= FOREGROUND_RED | FOREGROUND_GREEN;
            break;
        case CLOGGER_COLOUR_BLUE:
            windows_flags |= FOREGROUND_BLUE;
            break;
        case CLOGGER_COLOUR_MAGENTA:
            windows_flags |= FOREGROUND_RED | FOREGROUND_BLUE;
            break;
        case CLOGGER_COLOUR_CYAN:
            windows_flags |= FOREGROUND_GREEN | FOREGROUND_BLUE;
            break;
        case CLOGGER_COLOUR_WHITE:
            windows_flags |= FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
            break;
        default:
            break;
    }

    switch (console_colour.background_colour)
    {
        case CLOGGER_COLOUR_BLACK:
            break;
        case CLOGGER_COLOUR_RED:
            windows_flags |= BACKGROUND_RED;
            break;
        case CLOGGER_COLOUR_GREEN:
            windows_flags |= BACKGROUND_GREEN;
            break;
        case CLOGGER_COLOUR_YELLOW:
            windows_flags |= BACKGROUND_RED | BACKGROUND_GREEN;
            break;
        case CLOGGER_COLOUR_BLUE:
            windows_flags |= BACKGROUND_BLUE;
            break;
        case CLOGGER_COLOUR_MAGENTA:
            windows_flags |= BACKGROUND_RED | BACKGROUND_BLUE;
            break;
        case CLOGGER_COLOUR_CYAN:
            windows_flags |= BACKGROUND_GREEN | BACKGROUND_BLUE;
            break;
        case CLOGGER_COLOUR_WHITE:
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

void clog_set_console_colour(CLoggerConsoleColour console_colour, CLoggerUInt16 flags)
{
    switch (console_colour.foreground_colour)
    {
        case CLOGGER_COLOUR_BLACK:
            printf("%s", CLOGGER_FOREGROUND_INTENSE & flags ? CLOGGER_FG_HBLK : CLOGGER_UNDERSCORE & flags ? CLOGGER_FG_UL_BLK : CLOGGER_FG_BLK);
            break;
        case CLOGGER_COLOUR_RED:
            printf("%s", CLOGGER_FOREGROUND_INTENSE & flags ? CLOGGER_FG_HRED : CLOGGER_UNDERSCORE & flags ? CLOGGER_FG_UL_RED : CLOGGER_FG_RED);
            break;
        case CLOGGER_COLOUR_GREEN:
            printf("%s", CLOGGER_FOREGROUND_INTENSE & flags ? CLOGGER_FG_HGRN : CLOGGER_UNDERSCORE & flags ? CLOGGER_FG_UL_GRN : CLOGGER_FG_GRN);
            break;
        case CLOGGER_COLOUR_YELLOW:
            printf("%s", CLOGGER_FOREGROUND_INTENSE & flags ? CLOGGER_FG_HYEL : CLOGGER_UNDERSCORE & flags ? CLOGGER_FG_UL_YEL : CLOGGER_FG_YEL);
            break;
        case CLOGGER_COLOUR_BLUE:
            printf("%s", CLOGGER_FOREGROUND_INTENSE & flags ? CLOGGER_FG_HBLU : CLOGGER_UNDERSCORE & flags ? CLOGGER_FG_UL_BLU : CLOGGER_FG_BLU);
            break;
        case CLOGGER_COLOUR_MAGENTA:
            printf("%s", CLOGGER_FOREGROUND_INTENSE & flags ? CLOGGER_FG_HMAG : CLOGGER_UNDERSCORE & flags ? CLOGGER_FG_UL_MAG : CLOGGER_FG_MAG);
            break;
        case CLOGGER_COLOUR_CYAN:
            printf("%s", CLOGGER_FOREGROUND_INTENSE & flags ? CLOGGER_FG_HCYN : CLOGGER_UNDERSCORE & flags ? CLOGGER_FG_UL_CYN : CLOGGER_FG_CYN);
            break;
        case CLOGGER_COLOUR_WHITE:
            printf("%s", CLOGGER_FOREGROUND_INTENSE & flags ? CLOGGER_FG_HWHT : CLOGGER_UNDERSCORE & flags ? CLOGGER_FG_UL_WHT : CLOGGER_FG_WHT);
            break;
        default:
            break;
    }

    switch (console_colour.background_colour)
    {
        case CLOGGER_COLOUR_BLACK:
            printf("%s", CLOGGER_BACKGROUND_INTENSE & flags ? CLOGGER_BG_HBLK : CLOGGER_BG_BLK);
            break;
        case CLOGGER_COLOUR_RED:
            printf("%s", CLOGGER_BACKGROUND_INTENSE & flags ? CLOGGER_BG_HRED : CLOGGER_BG_RED);
            break;
        case CLOGGER_COLOUR_GREEN:
            printf("%s", CLOGGER_BACKGROUND_INTENSE & flags ? CLOGGER_BG_HGRN : CLOGGER_BG_GRN);
            break;
        case CLOGGER_COLOUR_YELLOW:
            printf("%s", CLOGGER_BACKGROUND_INTENSE & flags ? CLOGGER_BG_HYEL : CLOGGER_BG_YEL);
            break;
        case CLOGGER_COLOUR_BLUE:
            printf("%s", CLOGGER_BACKGROUND_INTENSE & flags ? CLOGGER_BG_HBLU : CLOGGER_BG_BLU);
            break;
        case CLOGGER_COLOUR_MAGENTA:
            printf("%s", CLOGGER_BACKGROUND_INTENSE & flags ? CLOGGER_BG_HMAG : CLOGGER_BG_MAG);
            break;
        case CLOGGER_COLOUR_CYAN:
            printf("%s", CLOGGER_BACKGROUND_INTENSE & flags ? CLOGGER_BG_HCYN : CLOGGER_BG_CYN);
            break;
        case CLOGGER_COLOUR_WHITE:
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
void clog_set_console_color(CLoggerConsoleColor console_color, unsigned short flags)
{
    clog_set_console_colour(console_color, flags);
}

void clog_reset_console_color() { clog_reset_console_colour(); }
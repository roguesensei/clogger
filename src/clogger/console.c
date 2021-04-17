#include "console.h"
#include "ansi.h"

#ifdef WIN32

#include <windows.h>

void clog_set_console_colour(clog_console_colour_t console_colour, unsigned short flags)
{
    WORD windows_flags = 0;

    switch (console_colour.foreground_colour)
    {
        case BLACK:
            break;
        case RED:
            windows_flags |= FOREGROUND_RED;
            break;
        case GREEN:
            windows_flags |= FOREGROUND_GREEN;
            break;
        case YELLOW:
            windows_flags |= FOREGROUND_RED | FOREGROUND_GREEN;
            break;
        case BLUE:
            windows_flags |= FOREGROUND_BLUE;
            break;
        case MAGENTA:
            windows_flags |= FOREGROUND_RED | FOREGROUND_BLUE;
            break;
        case CYAN:
            windows_flags |= FOREGROUND_GREEN | FOREGROUND_BLUE;
            break;
        case WHITE:
            windows_flags |= FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
            break;
        default:
            break;
    }

    switch (console_colour.background_colour)
    {
        case BLACK:
            break;
        case RED:
            windows_flags |= BACKGROUND_RED;
            break;
        case GREEN:
            windows_flags |= BACKGROUND_GREEN;
            break;
        case YELLOW:
            windows_flags |= BACKGROUND_RED | BACKGROUND_GREEN;
            break;
        case BLUE:
            windows_flags |= BACKGROUND_BLUE;
            break;
        case MAGENTA:
            windows_flags |= BACKGROUND_RED | BACKGROUND_BLUE;
            break;
        case CYAN:
            windows_flags |= BACKGROUND_GREEN | BACKGROUND_BLUE;
            break;
        case WHITE:
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

void clog_set_console_colour(clog_console_colour_t console_colour, unsigned short flags)
{
    switch (console_colour.foreground_colour)
    {
        case BLACK:
            printf("%s", CLOGGER_FOREGROUND_INTENSE & flags ? CLOGGER_FG_HBLK : CLOGGER_UNDERSCORE & flags ? CLOGGER_FG_UL_BLK : CLOGGER_FG_BLK);
            break;
        case RED:
            printf("%s", CLOGGER_FOREGROUND_INTENSE & flags ? CLOGGER_FG_HRED : CLOGGER_UNDERSCORE & flags ? CLOGGER_FG_UL_RED : CLOGGER_FG_RED);
            break;
        case GREEN:
            printf("%s", CLOGGER_FOREGROUND_INTENSE & flags ? CLOGGER_FG_HGRN : CLOGGER_UNDERSCORE & flags ? CLOGGER_FG_UL_GRN : CLOGGER_FG_GRN);
            break;
        case YELLOW:
            printf("%s", CLOGGER_FOREGROUND_INTENSE & flags ? CLOGGER_FG_HYEL : CLOGGER_UNDERSCORE & flags ? CLOGGER_FG_UL_YEL : CLOGGER_FG_YEL);
            break;
        case BLUE:
            printf("%s", CLOGGER_FOREGROUND_INTENSE & flags ? CLOGGER_FG_HBLU : CLOGGER_UNDERSCORE & flags ? CLOGGER_FG_UL_BLU : CLOGGER_FG_BLU);
            break;
        case MAGENTA:
            printf("%s", CLOGGER_FOREGROUND_INTENSE & flags ? CLOGGER_FG_HMAG : CLOGGER_UNDERSCORE & flags ? CLOGGER_FG_UL_MAG : CLOGGER_FG_MAG);
            break;
        case CYAN:
            printf("%s", CLOGGER_FOREGROUND_INTENSE & flags ? CLOGGER_FG_HCYN : CLOGGER_UNDERSCORE & flags ? CLOGGER_FG_UL_CYN : CLOGGER_FG_CYN);
            break;
        case WHITE:
            printf("%s", CLOGGER_FOREGROUND_INTENSE & flags ? CLOGGER_FG_HWHT : CLOGGER_UNDERSCORE & flags ? CLOGGER_FG_UL_WHT : CLOGGER_FG_WHT);
            break;
        default:
            break;
    }

    switch (console_colour.background_colour)
    {
        case BLACK:
            printf("%s", CLOGGER_BACKGROUND_INTENSE & flags ? CLOGGER_BG_HBLK : CLOGGER_BG_BLK);
            break;
        case RED:
            printf("%s", CLOGGER_BACKGROUND_INTENSE & flags ? CLOGGER_BG_HRED : CLOGGER_BG_RED);
            break;
        case GREEN:
            printf("%s", CLOGGER_BACKGROUND_INTENSE & flags ? CLOGGER_BG_HGRN : CLOGGER_BG_GRN);
            break;
        case YELLOW:
            printf("%s", CLOGGER_BACKGROUND_INTENSE & flags ? CLOGGER_BG_HYEL : CLOGGER_BG_YEL);
            break;
        case BLUE:
            printf("%s", CLOGGER_BACKGROUND_INTENSE & flags ? CLOGGER_BG_HBLU : CLOGGER_BG_BLU);
            break;
        case MAGENTA:
            printf("%s", CLOGGER_BACKGROUND_INTENSE & flags ? CLOGGER_BG_HMAG : CLOGGER_BG_MAG);
            break;
        case CYAN:
            printf("%s", CLOGGER_BACKGROUND_INTENSE & flags ? CLOGGER_BG_HCYN : CLOGGER_BG_CYN);
            break;
        case WHITE:
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
void clog_set_console_color(clog_console_color_t console_color, unsigned short flags)
{
    clog_set_console_colour(console_color, flags);
}

void clog_reset_console_color() { clog_reset_console_colour(); }
#include "console.h"
#include "ansi.h"

#include <stdio.h>

#ifdef WIN32
#include <windows.h>
#endif

struct ConsoleColourMap
{
    clog_colour colour;
    char ansi_colour[9];
    unsigned int windows_console_colour;
};

void map_colour(clog_colour colour, char* ansi_colour, unsigned int* windows_colour)
{
    clog_bool windows_defined = CLogFalse;
#ifdef WIN32
    windows_defined = CLogTrue;
#endif

    switch (colour)
    {
        case Black:
        {
            ansi_colour = strcpy(ansi_colour, CLOGGER_FG_BLK);
            if (windows_defined)
            {
                windows_colour = (unsigned int*)0;
            }
        }
    }
}

void clog_set_console_colour(clog_colour colour)
{
    char ansi_colour[10];
    unsigned int windows_colour;
    map_colour(colour, &ansi_colour, &windows_colour);

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), windows_colour);
}

void clog_reset_console_colour()
{
#ifdef WIN32
#else
    printf(CLOGGER_RESET_CONSOLE);
#endif
}
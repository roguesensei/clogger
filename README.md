# clogger 
[![Build Status](https://img.shields.io/endpoint.svg?url=https%3A%2F%2Factions-badge.atrox.dev%2FRogueSensei%2Fclogger%2Fbadge&style=flat)](https://actions-badge.atrox.dev/RogueSensei/clogger/goto)
[![License](https://img.shields.io/github/license/RogueSensei/clogger.svg)](https://github.com/RogueSensei/clogger/blob/master/LICENSE)

A lightweight functional logging library written in C
## Getting Started
All the tools you need are contained within a single header: `clogger.h`. Just include it in your C/C++ project and call the standard `clog_message` function, which takes a location (typically the function name) and a message as parameters.

The `message` parameter supports C style formatted strings like a standard `printf()` would. 
```c
#include <clogger.h>

int main()
{
    clog_message(__FUNCTION__, "Greetings, universe!");

    char some_string[3] = "bit";
    int some_num = 8;

    clog_message("I also support string formatting", "Mario looks good in %i-%s", some_num, some_string);

    return 0;
}
```
## Documentation
For detailed guides on usage, macros and compiling, please refer to the [clogger wiki](https://github.com/RogueSensei/clogger/wiki).
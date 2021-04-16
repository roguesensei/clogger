# clogger 
[comment]: <> (Badges generated at https://shields.io)
![GitHub release](https://img.shields.io/github/v/release/RogueSensei/clogger?label=clogger&style=flat-square)
[![GitHub](https://img.shields.io/github/license/RogueSensei/clogger?style=flat-square)](https://github.com/RogueSensei/clogger/blob/master/LICENSE)
![GitHub Workflow Status](https://img.shields.io/github/workflow/status/RogueSensei/clogger/CMake?label=build&style=flat-square)
![GitHub Repo stars](https://img.shields.io/github/stars/RogueSensei/clogger?style=social)

A lightweight functional logging library written in C

For clarification, it's pronounced "C logger".
## Getting Started
All the tools you need are contained within a single header: `clogger.h`. Just include it in your C/C++ project and call the standard `clog_message` function, which takes a location (typically the function name) and a message as parameters.

The `message` parameter supports C style formatted strings like a standard `printf()` would. 
```c
#include <clogger.h>

int main()
{
    clog_message(__FUNCTION__, "Greetings, universe!");

    char some_string[] = "bit";
    int some_num = 8;

    clog_message("I also support string formatting", "Mario looks good in %i-%s", some_num, some_string);

    return 0;
}
```
## Documentation
For guides on usage, examples and compiling, please refer to the [clogger wiki](https://github.com/RogueSensei/clogger/wiki)

For the detailed API reference, please visit [rs-clogger.readthedocs.io](https://rs-clogger.readthedocs.io/)
### Credit
Using [jothepro/doxygen-awesome-css](https://github.com/jothepro/doxygen-awesome-css) as theme for API Reference, generated using Doxygen.
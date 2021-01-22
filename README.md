# clogger
A lightweight logging library written in C
## Usage
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
#### Result
![img.png](res/simple_out.png)
### Debug/Release configurations
In `CLOGGER_DEBUG` mode, debug and info log messages will be logged to the console; this is turned off by default. To turn it on you can either:
1. Include a definition for the `CLOGGER_DEBUG` macro
```cmake
# Add a definition in your debug configuration
if (MY_DEBUG_CONFIG)
    add_definitions(-DCLOGGER_DEBUG)
endif ()
```
2. Use the builtin `set_clogger_debug()` function
```c
void my_debug_function()
{
    set_clogger_debug(CLogTrue); // or 1/true
    
    char* message = "Debug mode is turned on";
    clog_info("DEBUG FUNCTION", "%s", message);
}
```
### Compiling with CMake
For example, if you wish to build clogger as a static library (recommended):
```shell
mkdir build
cd build
cmake ..
cmake --build .
```
To generate as a shared library, use the **CLOGGER_SHARED** flag:
```shell
cmake -DCLOGGER_SHARED=ON ..
```
#### Oh, and did I mention the pretty colours?
![img.png](res/colour.png)
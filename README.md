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
### Builtin logging functions with levels
```c
void clog_info(const char* location, char* message, ...);
void clog_debug(const char* location, char* message, ...);
void clog_warning(const char* location, char* message, ...);
void clog_error(const char* location, char* message, ...);
void clog_fatal(const char* location, char* message, ...);
```
Same usage as the standard `clog_message()` function, but will include the logging level as part of the message. `clog_info()` and `clog_debug()` will not log anything by default.
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
### Did I mention the pretty colours?
![img.png](res/log_level_colours.png)

You can make use of the macros in `ansi.h` to apply your own colours.
```c
clog_debug(__PRETTY_FUNCTION__, CLOGGER_BG_HMAG"%s", "Pretty colours");
printf(CLOGGER_FG_BOLD_WHT"Using std printf");
```
#### Result
![img.png](res/pretty_colours.png)
### Compiling with CMake
By default, clogger can be built as a static library:
```shell
mkdir build
cd build
cmake ..
cmake --build .
```
To build as a shared library, use the **CLOGGER_SHARED** flag:
```shell
cmake -DCLOGGER_SHARED=ON ..
```

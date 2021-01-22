# clogger
A lightweight logging library written in C
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
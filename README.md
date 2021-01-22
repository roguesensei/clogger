# clogger
A lightweight logging library written in C
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
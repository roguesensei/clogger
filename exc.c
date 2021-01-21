#include "src/clog.h"

int main()
{
    char* test = "test";
    int a = 64;
    clog_debug("MAIN", "%s", test);

    return 0;
}
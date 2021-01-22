#include "src/clog.h"

int main()
{
    char* test = "test";
    int a = 64;

    clog_info("MAIN", "%s is %i", test, a);
    clog_debug("MAIN", "%s is %i", test, a);
    clog_warning("MAIN", "%s is %i", test, a);
    clog_error("MAIN", "%s is %i", test, a);
    clog_fatal("MAIN", "%s is %i", test, a);

    return 0;
}
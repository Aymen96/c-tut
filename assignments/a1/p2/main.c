#include "../testlib/testlib.h"
#include "parseint.h"

int main()
{
    test_start("parseint.c");

    test_equals_int(parseDecimalChar('0'), 0, "parseDecimalChar parses '0'");
    test_equals_int(parseInt("067"), 55, "parseInt parses octal number 55");
    test_equals_int(parseInt("10"), 10, "parseInt parses decimal number");
    test_equals_int(parseInt("?"), -1, "parseInt handles invalid input");

    return test_end();
}

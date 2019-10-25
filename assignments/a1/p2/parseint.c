#include "parseint.h"

/*
 * Returns the value of c or -1 on error
 */
int parseDecimalChar(char c)
{
    int i = c;
    if(i > 47 && i < 58) {
        return i - 48;
    }
    return -1;
}

/*
 * Parses a non-negative integer, interpreted as octal when starting with 0,
 * decimal otherwise. Returns -1 on error.
 */
int parseInt(char *string)
{
    // get length of string
    int len = 0;
    while(string[len] != '\0') {
        len++;
    }

    int i;
    int base;
    int res = 0;
    // octal number recognized by a leading zero
    if(string[0] == '0') {
        i = 1;
        base = 8;
    // decimal number
    } else {
        i = 0;
        base = 10;
    }
    while(string[i] != '\0') {
        int el = parseDecimalChar(string[i]);
        if(el == -1) {
            return -1;
        }
        // octal numbers have digits in [0..7]
        if(base == 8 && (string[i] == '8' || string[i] == '9')) {
            return -1;
        }
        int e = 0;
        while(e < len - 1 - i) {
            el *= base;
            e++;
        }
        res += el;
        i++;
    }
    return res;
}

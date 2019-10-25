#include <stdio.h>
#include <stdint.h>

struct x
{
    uint8_t a;
    uint32_t b;
    uint64_t c;
};

int main () {
    /**
    * why is the size of a struct not the sum of the sizes of its members?
    * ANSWER: the compiler may add padding for alignement requirements
    **/
    struct x x1;
    printf("%lu %lu %lu | %lu\n", sizeof(x1.a), sizeof(x1.b), sizeof(x1.c) , sizeof(x1));


    /**
    * get size of array.
    * see asseignment papar of explanation
    **/
    uint16_t array[17];
    printf("%lu\n", sizeof(array));

    uint16_t *array2 = &array[0];
    printf("%lu\n", sizeof(array2));
    return 0;
}
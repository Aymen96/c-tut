#include <stdio.h>

int main(int argc, char **argv)
{
    int a = 42;
    int *p = &a;

    printf("%i\n", *p);

    char *s = "World!";
    printf("%s %s\n", "Hello", s);

    return *p;
}
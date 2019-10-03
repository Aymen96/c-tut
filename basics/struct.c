#include <stdio.h>

typedef struct pair pair;
struct pair {
    int fst;
    int scn;
};

int main(int argc, char** argv)
{
    pair p = {1, 2};
    pair* ptr = &p;
    printf("this struct contains %d and %d\n", ptr->fst, (*ptr).scn); // two ways to acces subelement/property of a struct
    return 0;
}
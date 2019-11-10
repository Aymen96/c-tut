#include "inttypes.h"
#include <stdio.h>
#include "string.h"
#include <assert.h>

void insert(int *a, size_t * len, int z) {
    int *p = a;
    int *end = a + *len;
    while((p < end) && (*p < z)) { ++p;}
    memmove(p+1, p, (end - p) * sizeof(int));
    *p = z;
    (*len)++;
}

int main() {
    int a[10] = {0, 1, 2, 3, 5, 6, 7, 8, 9};
    int i;
    for (i = 0; i < 9; i++) {
        printf("%i", a[i]);
    }
    printf("\n");
    size_t len = 9;
    insert(a, &len, 4);
    assert(a[4] == 4);
    assert(len == 10);
    for (i = 0; i < 9; i++) {
        printf("%i", a[i]);
    }
    printf("\n");
    return 0;
}
#include "insert.h"

#include <stdlib.h>
#include <string.h>

/*
 * Reminder: insert() function from the tutorial that does not manage capacity.
 */
void insert_tut(int *a, size_t *length, int z)
{
	int *p = a;
	int *end = a + *length;
	while ((p < end) && (*p < z)) { ++p; }
	memmove(p + 1, p, (end - p) * sizeof(int));
	*p = z;
	(*length)++;
}

/*
 * New insert() function that reallocates if the array is full.
 */
void insert(int **array, size_t *length, size_t *capacity, int z)
{
    if(*length + 1 > *capacity) {
        *capacity = *capacity + 10;
        int* array2 = (int*) malloc(sizeof(int) * *capacity);
        memcpy(array2, *array, *length);
        /*
        // Question: why does the following not working instead of using memcpy
        // I copy manually the data, free array and then assign the pointer array
        // the pointer of the new array with the bigger capacity.
        // Would appreciate your help on this matter.
        int i;
        for (i = 0; i < (int) *length; i++) {
            *(array2 + i) = (*array)[i];
        }
        free(*array);
        array = &array2;
        */
    }
    insert_tut(*array, length, z);
}

#include <stdio.h>
#include <stdlib.h> // for malloc and free
#include <string.h>

int randommethod() {
    int array[10]; /* array created here */
    for(int i = 0; i < 10; ++i) array[i] = i;
    int sum = 0;
    for(int i = 0; i < 10; ++i) sum += array[i];
    return sum; // keine Pointer auf nur in der Funktion existierende Elemente zurückgeben
};

// Problem: Kann nicht auf array zugreifen außerhalb vom Array
// Lösung: malloc(n) zum Rescue // n in Bytes
int *makearray(int numelements)
{
    int *array = (int*)malloc(numelements * sizeof(int));
    if(!array) { /* you get no memory today */
        return NULL;
    }
    int sum = 0;
    for(int i = 0; i < numelements; ++i) {
        sum += i;
        array[i] = sum;
        if(sum > 1000000000) {
            free(array);
            return NULL;
        }
    }
    return array;
    // wer muss danach Speicher wieder freigeben? der Aufrufer von makearray
}

int main()
{
    printf("%i\n", randommethod());

    int* arr = makearray(5);
    int i;
    for (i = 0; i < 5; i++ ) {
        printf("%i\n", *(arr + i)); // oder arr[i] geht auch
    }
    return 0 ;
}

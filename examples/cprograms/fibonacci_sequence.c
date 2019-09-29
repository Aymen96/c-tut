#include <stdio.h>
#include <string.h>

/*
*   The program should print out the fubonacci sequence
*   The next number is found by adding up the two numbers before it
*   The User should input an upper bound.
*/

int add (int a, int b)
{
    return a + b;
}

int getFibonacciSequence (int upper_bound, int *arr)
{
    arr[0] = 0;
    arr[1] = 1;
    int len = 2;
    int res = 1;
    int i = 2;
    while((arr[i-2] + arr[i-1]) < upper_bound) {
        arr[i] = arr[i-2] + arr[i-1];
        i++;
        len++;
    }
    return len;
}

int main ()
{
    int bound = 150;
    printf("The Fibonacci Sequence till %i.\n", bound);
    int arr[20];
    int len = getFibonacciSequence(bound, &arr[0]);
    int i;
    for (i = 0; i < len; i++) {
        printf("%i ", arr[i]);
    }
    printf("\n");
    return 0;
}
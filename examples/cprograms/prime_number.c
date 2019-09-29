#include <stdio.h>
#include <string.h>

int isPrimeNumber (int number)
{
    int i;
    for (i = number / 2; i > 1; i--)
    {
        int res = number / i;
        if (res * i == number) {
            return -1;
        }
    }
    return 0;
}

int main ()
{
    // -1 means not prime and 0 mean prime number
    printf("%i\n", isPrimeNumber(50));
    printf("%i\n", isPrimeNumber(49));
    printf("%i\n", isPrimeNumber(13));
    printf("%i\n", isPrimeNumber(23));
    return 0;
}
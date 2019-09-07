#include <stdio.h>
#include <string.h>

int sameOnReverse(char* str) {
    int i = 0;
    int l = strlen(str);
    for( i = 0; i < (l/2); i++) {
        if(str[i] != str[l - i -1]) {
            return -1;  
        }
    }
    return 0;
}

int contains(char* str, char c) {
    for(int i = 0; i < strlen(str); i++) {
        if(str[i] == c) {
            return 0;
        }
    }
    return -1;
}

int main()
{
    char *name = "InesenI";
    int *ip;
    
    // same on reverse
    printf("Reversed: ");
    if(sameOnReverse(name) == 0) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    // contains a charachter
    printf("Contains I: ");
    if(contains(name, 'I') == 0) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}

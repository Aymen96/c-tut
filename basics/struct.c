#include <stdio.h>
#include <stdlib.h> // for memcpy
#include <string.h> // for malloc

typedef struct pair pair;
struct pair {
    int fst;
    int scn;
};

struct Person {
    char name[10];
    int citNo;
    float salary;
};

// you can define variables hier
struct Profile {
    char username[50];
    char password[10];
} profile1, profile2, profiles[10];

int main(int argc, char** argv)
{
    pair p = {1, 2};
    pair* ptr = &p;
    printf("this struct contains %d and %d\n", ptr->fst, (*ptr).scn); // two ways to acces subelement/property of a struct

    struct Person person1, person2, persons[20];
    // correct way to assign stings in C.
    strncpy(person1.name, "Oldman", 10);
    printf("Name in person1 is %s\n", person1.name);
    // try make a copy of person1
    struct Person *pp;
    pp = malloc(sizeof(struct Person)); // allocate memory for a copy of the struct
    if (pp == NULL) {
        return 0; // do this check
    }
    // copies bytes from the object pointer by pp to the object pointed by &person1
    memcpy(pp, &person1, sizeof(struct Person));
    printf("Name in copy of person1 is %s\n", pp->name);
    if (strcmp(pp->name, person1.name) == 0) { // use strcmp to compare two strings
        printf("Copying was successful ;).\n");
    }
    return 0;
}
#include <stdio.h>

int fakultaet (int n) {
	if(n > 1) {
		return n * fakultaet(n-1);
	}
	return 1;
}

struct coordinate { //  collection of named vars of different types
	int x;
	int y;
};

union longorfloat { // single var that can have multiple types
	long l;
	float f;
};

typedef struct pair pair;
struct pair {
	int fst;
	int scn;
};

typedef struct {char name[50]; int alter;} person;

int main(void) { // void:  keyword for absence of args
    printf("Using pointers\n");
    int a = 42;
    int *p = &a; //adress from a in p save

    printf("%i\n", *p); // content of address

    char *s = "World!"; // entweder: pointer to a char oder: array of chars = string

    printf("%s %s\n", "Hello", s);

    // scan for information
    int age;
    printf("How old are you? ");
    scanf("%d", &age); // gib scanf die Adresse wo er die Eingabe speichern muss
    printf("/nYou will in %d be 100 years old.", 100 - age);

    int tag, monat, jahr;
    printf("Birthdate? ");
    scanf("%d.%d.%d", &tag, &monat, &jahr);
    printf("/nYour Birthday: %04d-%02d-%02d\n", jahr, monat, tag); // padding with 0

    int arg;
    scanf("%d", &arg);
    printf("%i is the result of fakultaet of %d \n", fakultaet(arg), arg);

    return *p;
}
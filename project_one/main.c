#include <stdio.h>
#include "functions.h"

typedef struct film film;
struct film {
	int id;
	char *name;
	int year;
	char* producer;
};

film createFilm() {
	film f;
	f.id = 1;
	f.name = "My name is DAVE";
	f.year = 2010;
	f.producer = "Brian Robbins";
	return f;
}

void print(char *msg) {
	printf("%s\n", msg);
};

int main(void) {
	film f = createFilm();
	printf("%s\n", f.name);
	// adding film to the list of films
	add_film();

	// remove film from the list of films
	remove_film();
	printf("%ld\n", sizeof(12));
	return 0;
}


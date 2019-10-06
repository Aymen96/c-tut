#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXCHAR 50

typedef struct user user;
struct user {
    int id;
    char* name;
    char* type;
    int active;
};

user users[3];

void assign_user (int idx, int id, char *name, char *type) {
    users[idx].id = id;
    users[idx].name = name;
    users[idx].type = type;
    users[idx].active = 1;
    return;
}

void list_users() {
    int i;
    for(i = 0; i < 3; i++) {
        printf("%i %s %s %c\n",users[i].id, users[i].name, users[i].type, users[i].active == 1 ? '*' : ' ');
    }
    return;
};

int read_file(char *filename) {

    FILE *fp;
    char str[MAXCHAR];

    fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Could not open file %s", filename);
        return 1;
    }
    int i = 0;
    while(fgets(str, MAXCHAR, fp) != NULL) {
        int id;
        char *p1 = strstr(str, ".NAME=");
        char *p2 = strstr(str, ".TYPE=");
        char *p3 = strstr(str, ".ID=");
        int need = p2 -p1 - 6;
        char *name = malloc(need);
        char *type = malloc(need);
        strncpy(name, p1 + 6, need -1);
        strncpy(type, p2 + 6, 5);
        name[need] = '\0';
        type[need] = '\0';
        assign_user(i++, *(p3 + 4) - 48, name, type); // to investigate later
    }
    return 0;
}

int main()
{
    printf("Just started the user manager program as a thread\n");
    read_file("../data/users.txt");
    list_users();
    return 0;
}
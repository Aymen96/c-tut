#include "hash.h"
#include <string.h>

/*
 * Returns a hash value for the given string.
 */
uint64_t hashString(char *c)
{
	int i;
    uint64_t hash = 5381;
    for (i = 0; c[i] != '\0'; i++) {
        hash = hash * 33 + c[i];
    }
	return hash;
}

/*
 * Inserts a key-value pair into the hash table.
 */
int insert(hashtable *table, char *key, int value)
{
    int pos = hashString(key) % table->capacity;
    element el;
    el.key = key;
    el.value = value;
    el.valid = 1;
    int i = 0;
    while((table->elements + pos + i)->valid == 1 && pos + i < (int) table->capacity) {
        i++;
    }
    if (pos + i < (int) table->capacity) {
        *(table->elements + pos + i) = el;
        return 1;
    }
	return 0;
}

/*
 * Retrieves the value for a given key.
 */
int find(hashtable *table, char *key, int *value)
{
    int i = 0;
    while(i < (int) table->capacity) {
        if((table->elements + i)->valid != 0) {
            if(strcmp((table->elements + i)->key, key) == 0) {
                *value = (table->elements + i)->value;
                return 1;
            }
        }
        i++;
    }
	return 0;
}


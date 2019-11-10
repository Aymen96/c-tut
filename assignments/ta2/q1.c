#include <inttypes.h>
#include <stddef.h>
#include "string.h"

struct queue_entry {
    struct queue_entry *prev, *next;
};

typedef struct {
    uint32_t a;
    struct queue_entry q;
} foo;


struct bar {
    uint32_t a;
    uint64_t b;
};

struct queue_entry* from_foo(foo *f) {
    return &f->q;
}

foo* from_queue_entry(struct queue_entry *q) {
    return (foo *)((char*) q - offsetof(foo, q));
}

int bar_equal1(struct bar* a, struct bar* b) {
    // compare the members
    return (a->a == b->a) && (a->b == b->b);
}

int bar_equal2(struct bar* a, struct bar* b) {
    // compate the two byte for byte
    return memcmp(a,b,sizeof(*a)) == 0;
}

int main () {
    return 0;
}
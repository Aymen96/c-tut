#include <stdio.h>
#include <pthread.h>

typedef struct {
    int count;
    pthread_mutex_t lock;
} Count;

void *inc(void *num) {
    pthread_mutex_lock(num->lock);
    num->count += 10;
    pthread_mutex_unlock(num->lock);
}

void *dec(void *num) {
    pthread_mutex_lock(num->lock);
    num->count--;
    pthread_mutex_unlock(num->lock);
}

int main()
{
    Count num;
    num.count = 0;
    pthread_mutex_init(&num.lock, NULL); // when accessing it with . it returns address with -> it return value

    int i;
    pthread_t p1, p2;
    pthread_create(&p1, NULL, inc, &num);
    pthread_create(&p2, NULL, dec, &num);

    pthread_join(p1, NULL);
    pthread_join(p2, NULL);

    printf("%i", num.count);
    pthread_mutex_destroy(&num.lock);
}
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

// ref: http://www.ijon.de/comp/tutorials/threads/synchro.html

/*
    this is meant for pthread library use
    Handle it wisely.
 */

char ch;

// without mutex
void *print_stern(void *dummy)
{
  ch = '*';
  sleep(1);
  printf("%c\n", ch);
  return NULL;
}

void *print_minus(void *dummy)
{
  ch = '-';
  sleep(1);
  printf("%c\n", ch);
  return NULL;
}

// with mutex

/*
* pthread mutex calls to use:
       pthread_mutex_init : create and initialize a new mutex
       pthread_mutex_lock : enter critical section or block
       pthread_mutex_unlock : leave critical section
       pthread_mutex_destroy : destroy and free existing mutex

       all these calls accept a mutex as a parameter
*/
pthread_mutex_t mutex;
void *print_stern_with_mutex(void *dummy)
{
  pthread_mutex_lock(&mutex); //  try to enter CS otherways block and wait till it's free again
  ch = '*';
  sleep(1);
  printf("%c\n", ch);
  pthread_mutex_unlock(&mutex); // leave and free CS
  return NULL;
}

void *print_minus_with_mutex(void *dummy)
{
  pthread_mutex_lock(&mutex);
  ch = '-';
  sleep(1);
  printf("%c\n", ch);
  pthread_mutex_unlock(&mutex);
  return NULL;
}

int main()
{
    // TRY TO PRESENT THE PROBLEM WITHOUT PTHREAD_MUTEX USE
    // create 2 threads
    pthread_t p1,p2;
    pthread_create(&p1, NULL, print_minus, NULL);
    pthread_create(&p2, NULL, print_stern, NULL);

    pthread_join(p1, NULL);
    pthread_join(p2, NULL);

    // output: unexpectable

    /*
    Lesson learned:
    Hier should two threads print out two sterns but the behavior is not always the same and unexpectable
    This happen because the content of the char variable has been changed from one thread just before the
    other thread prints that out. Here Synchronization is missing.
    */

    // lets try to fix this with the pthread_mutex library

    pthread_t p3,p4;
    pthread_mutex_init(&mutex, NULL); // inti mutex
    pthread_create(&p3,NULL, print_minus_with_mutex, NULL);
    pthread_create(&p4,NULL, print_stern_with_mutex, NULL);

    pthread_join(p3, NULL);
    pthread_join(p4, NULL);

    pthread_mutex_destroy(&mutex);

    // out: - then *

    /*
    Lesson learned:
    Hier should two threads print out two sterns but the behavior is not always the same and unexpectable
    This happen because the content of the char variable has been changed from one thread just before the
    other thread prints that out. Here Synchronization is missing.
    */
    return 0;
}


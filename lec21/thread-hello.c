#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *HelloWorld(void *id) {
  long *myid = (long *) id;
  printf("Hello world! I am thread %ld\n", *myid);
  return (void*) myid;  
}

int main(int argc, char **argv) {
  long id1 = 1;
  long id2 = 2;
  long* retval1 = NULL;
  long* retval2 = NULL;
  pthread_t thread1;
  pthread_t thread2;

  pthread_create(&thread1, NULL, HelloWorld, &id1);
  pthread_create(&thread2, NULL, HelloWorld, &id2);

  /* Join all the threads. Main will pause until all threads return */
  pthread_join(thread1, (void*) (&retval1));
  pthread_join(thread2, (void*) (&retval2));

  printf("Thread1 returned the value %ld\n", *retval1);
  printf("Thread2 returned the value %ld\n", *retval2);

  return 0;
}


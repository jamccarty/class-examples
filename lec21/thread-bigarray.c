#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <math.h>

struct thread_data {
  float s;
  int start_index;
  int end_index;
  float* array;
};

void *scalar_multiply(void *userdata) {
  struct thread_data *data = (struct thread_data *) userdata;
  for (int i = data->start_index; i < data->end_index; i++) {
    data->array[i] = sqrt(i)* data->s;
  }
  return NULL; 
}

int main(int argc, char **argv) {
  int i;
  int nthreads; 
  pthread_t *thread_array; 
  long *thread_ids;
  struct thread_data *tdata;
  float data[100000];

  if (argc !=2) {
    fprintf(stderr, "usage: %s <n>\n", argv[0]);
    fprintf(stderr, "where <n> is the number of threads\n");
    return 1;
  }
  nthreads = strtol(argv[1], NULL, 10);

  // Allocate space for thread structs and identifiers.
  thread_array = malloc(nthreads * sizeof(pthread_t));
  thread_ids = malloc(nthreads * sizeof(long));
  tdata = malloc(nthreads * sizeof(struct thread_data));

  struct timeval tstart, tend;
  gettimeofday(&tstart, NULL);
  // Assign each thread an ID and create all the threads.
  int subsize = (int) (100000 / (nthreads-1));
  for (i = 0; i < nthreads; i++) {
    thread_ids[i] = i;
    tdata[i].s = 3.14;
    tdata[i].start_index = i*subsize;
    tdata[i].end_index = (i+1)*subsize % 100000;
    tdata[i].array = data;
    pthread_create(&thread_array[i], NULL, scalar_multiply, &tdata[i]);
  }

  /* Join all the threads. Main will pause in this loop until all threads
   * have returned from the thread function. */
  for (i = 0; i < nthreads; i++) {
    pthread_join(thread_array[i], NULL);
  }
  gettimeofday(&tend, NULL);

  float timer = tend.tv_sec - tstart.tv_sec + (tend.tv_usec - tstart.tv_usec)/1.e6;
  printf("scalar_multiply time is %g\n", timer);

  free(thread_array);
  free(thread_ids);
  free(tdata);

  return 0;
}

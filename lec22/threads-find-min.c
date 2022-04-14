#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <pthread.h>

struct thread_data {
  int start_index;
  int end_index;
  int* array;
  int min;
};

void *find_min(void *userdata) {
  struct thread_data *data = (struct thread_data *) userdata;
  int min = RAND_MAX;
  for (int i = data->start_index; i < data->end_index; i++) {
    min = data->array[i] < min? data->array[i] : min;
  }
  data->min = min;
  return (void*) NULL; 
}


int main(int argc, char *argv[]) {
  srand(time(0));

  int *values = NULL;
  int size = 0;
  
  if (argc !=2) {
    fprintf(stderr, "usage: %s <n>\n", argv[0]);
    fprintf(stderr, "where <n> is the number of values\n");
    return 1;
  }
  size = strtol(argv[1], NULL, 10);

  values = malloc(sizeof(int) * size);
  int min = RAND_MAX;
  for (int i = 0; i < size; i++) {
    values[i] = rand() % 10000;
    min = values[i] < min? values[i] : min;
    printf("%d\n", values[i]);
  }

  printf("The min value is %d\n", min);

  printf("Test with 4 threads\n");
  pthread_t threads[4];
  struct thread_data data[4];
  int subsize = size/4; // assume multiple of 4
  for (int i = 0; i < 4; i++) {
    data[i].array = values;
    data[i].start_index = subsize*i;
    data[i].end_index = subsize*(i+1);
    pthread_create(&threads[i], NULL, find_min, (void*) &data[i]);
  }

  int thread_min = RAND_MAX;
  for (int i = 0; i < 4; i++) {
    pthread_join(threads[i], NULL);
    if (data[i].min < thread_min) thread_min = data[i].min;
  }
  printf("The thread min value is %d\n", thread_min);
  free(values);
}


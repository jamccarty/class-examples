#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

int count = 0;

struct thread_data {
  FILE* fp;
  int id;
};

pthread_mutex_t mutex;
unsigned long long lettercount = 0;

void *start(void* userdata) {
  struct thread_data* data = (struct thread_data*) userdata;
  int len = 1;
  char buffer[1024];

  unsigned long long local_lettercount = 0;
  while(len != 0){
    pthread_mutex_lock(&mutex);
    fgets(buffer, 1023, ((struct thread_data*)userdata) -> fp);
    pthread_mutex_unlock(&mutex);

    len = strlen(buffer);

    for(int i = 0; i < len; i++){
      local_lettercount++;
    }
  }
  

  pthread_mutex_lock(&mutex);
  count+=local_lettercount++;
  pthread_mutex_unlock(&mutex);

  // todo
  return 0; 
}

int main() {
  FILE* fp = fopen("tolstoy.txt", "r");
  if (!fp) {
    printf("Cannot open file!\n");
    exit(1);
  }

  pthread_t threads[4];
  struct thread_data data[4];
  pthread_mutex_init(&mutex, NULL);
  for (int i = 0; i < 4; i++) {
    data[i].fp = fp;
    data[i].id = i;
    pthread_create(&threads[i], NULL, start, &data[i]); 
  }

  for (int i = 0; i < 4; i++) {
    pthread_join(threads[i], NULL); 
  }
  printf("count = %llu\n", lettercount);
  pthread_mutex_destroy(&mutex); 

  fclose(fp);
  return 0; 
}

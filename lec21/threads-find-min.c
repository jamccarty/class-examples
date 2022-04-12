#include <stdio.h>
#include <time.h>
#include <stdlib.h>

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
  free(values);
  
}


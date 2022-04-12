#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>
#include <math.h>

void scalar_multiply(float * array, long length, float s) {
  for (int i = 0; i < length; i++) {
    array[i] = sqrt(i)*s;
  }
}

int main(int argc, char **argv) {
  float data[100000];

  struct timeval tstart, tend;
  gettimeofday(&tstart, NULL);
  scalar_multiply(data, 100000, 3.14);
  gettimeofday(&tend, NULL);

  float timer = tend.tv_sec - tstart.tv_sec + (tend.tv_usec - tstart.tv_usec)/1.e6;
  printf("scalar_multiply time is %g\n", timer);
  return 0;
}

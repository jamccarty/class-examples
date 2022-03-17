#include <stdio.h>
#include <sys/time.h>
#include "generateMatrix.h"

float averageMat_v1(int **mat, int n) {
  int i, j, total = 0;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      total += mat[i][j];
    }
  }

  return (float) total / (n * n);
}

float averageMat_v2(int **mat, int n) {
  int i, j, total = 0;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      total += mat[j][i];
    }
  }

  return (float) total / (n * n);
}

int main(int argc, char** argv) {
  if (argc != 2) {
    printf("usage: %s <size>\n", argv[0]);
    exit(0);
  }

  int n;
  float res;
  double timer;
  struct timeval tstart, tend;
  int** M = NULL;

  n = strtol(argv[1], NULL, 10);
  M = generateMatrix(n, 100);

  gettimeofday(&tstart, NULL);
  res = averageMat_v1(M, n);
  gettimeofday(&tend, NULL);

  timer = tend.tv_sec - tstart.tv_sec + (tend.tv_usec - tstart.tv_usec)/1.e6;
  printf("v1 average is: %.2f; time is %g\n", res, timer);

  gettimeofday(&tstart, NULL);
  res = averageMat_v2(M, n);
  gettimeofday(&tend, NULL);

  timer = tend.tv_sec - tstart.tv_sec + (tend.tv_usec - tstart.tv_usec)/1.e6;
  printf("v2 average is: %.2f; time is %g\n", res, timer);

  freeMatrix(M, n);
}

#include "generateMatrix.h"

int** generateMatrix(int n, int maxVal) {
  srand(time(0));
  int** M = malloc(sizeof(int*) * n);
  for (int i = 0; i < n; i++) {
    M[i] = malloc(sizeof(int) * n);
    for (int j = 0; j < n; j++) {
      M[i][j] = rand() % maxVal + 1;
    }
  }
  return M;
}

void freeMatrix(int** M, int n) {
  for (int i = 0; i < n; i++) {
    free(M[i]);
  }
  free(M);
}

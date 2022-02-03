#include <stdio.h>
#include <stdlib.h>

int main() {
  int nrows = 50;
  int ncols = 100;
  printf("Please enter a number of rows: ");
  scanf(" %d", &nrows);
  printf("\n");

  printf("Please enter a number of cols: ");
  scanf(" %d", &ncols);
  printf("\n");

  int* m = malloc(sizeof(int) * nrows * ncols);

  int i, j;
  for (i = 0; i < nrows; i++) {  // for each row i
    for (j = 0; j < ncols; j++) { // iterate over each column in row i
        printf("\nEnter a value m[%d][%d]: ", i, j);
        int val = 0;
        scanf(" %d", &val);
        m[i*ncols + j] = val;
    }
  }
  printf("\n\nHere is your matrix!\n");

  for (i = 0; i < nrows; i++) {  // for each row i
    for (j = 0; j < ncols; j++) { // iterate over each column in row i
        printf("%d ", m[i*ncols + j]);
    }
    printf("\n");
  }

  free(m);
  m = NULL;
  return 0;
}


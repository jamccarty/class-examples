#include <stdio.h>
#include <stdlib.h>



int main(){
  int rows;
  int cols;
  int *arr;
  printf("Enter a number of rows: ");
  scanf("%d", &rows);
  printf("\nEnter a number of columns: ");
  scanf("%d", &cols);

  arr = malloc(sizeof(int) * rows);

  for(int i = 0; i < cols; i++){
    arr[i] = (int *)malloc(sizeof(int) * cols);
  }

  for(int i = 0; i < rows; i++){
    for(int j = 0; j < cols; j++){
      int val;
      printf("\nPlease enter a value for matrix[%d][%d]: ", rows, cols);
      scanf("%d", &val);
      arr[i][j] = val;
    }
  }

  for(int i = 0; i < cols; i++){
    free(arr[i]);
  }
  free(arr);
}

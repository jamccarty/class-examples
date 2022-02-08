// Reading from unitialized memory

#include <stdlib.h>
#include <stdio.h>

int main() {
  int *ptr, x;
  ptr = malloc(sizeof(int) * 10);
  x = ptr[3]; // bad!
  printf("%d\n", x);
  return 0;
}


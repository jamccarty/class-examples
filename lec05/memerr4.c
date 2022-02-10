// Memory leaks

#include <stdlib.h>

int main() {
  int* ptr;
  ptr = malloc(sizeof(int) * 10);
  ptr = malloc(sizeof(int) * 5);
  free(ptr);
  return 0;
}


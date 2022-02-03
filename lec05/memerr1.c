// Reading from unitialized memory

#include <stdlib.h>

int main() {
  int *ptr, x;
  ptr = malloc(sizeof(int) * 10);
  x = ptr[3]; // bad!
  return 0;
}


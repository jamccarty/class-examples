// Reading or writing from unallocated memory
#include <stdio.h>

int main() {
  int values[10];
  printf("%d\n", values[11]);
  values[11] = 5; // memory not allocated!
}


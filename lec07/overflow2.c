#include <stdio.h>

int main() {
  int a = -1;
  // the largest value is 2^8-1 because sizeof(char) = 8 bits
  printf("Subtract 1: %d = %u = 0x%x\n", a, a, a);
  return 0;
}

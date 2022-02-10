#include <stdio.h>

int main() {
  unsigned char a = 0;
  // the largest value is 2^8-1 because sizeof(char) = 8 bits
  unsigned long largest = 1 << 8;
  for (int i = 0; i <= largest; i++) {
    printf("val = %d (0x%x)\n", a, a);
    a++;
  }
  return 0;
}

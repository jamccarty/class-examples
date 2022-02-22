#include <stdio.h>

int main() {
  unsigned char a = 7;
  unsigned char b = 4;
  unsigned char not = ~a;
  
  printf("%02X & %02X = %02X\n", a, b, a & b);
  printf("%02X | %02X = %02X\n", a, b, a | b);
  printf("%02X ^ %02X = %02X\n", a, b, a ^ b);
  printf("~%02X = %02X\n", a, not);
  
  return 0;
}

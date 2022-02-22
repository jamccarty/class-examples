#include <stdio.h>

int main() {
  int value = 0;
  printf("Enter a value: ");
  scanf(" %d", &value);

  unsigned int mask = 0x1;
  int result = mask & value;
  printf("Mask: %08X Value: %08X Result: %08X\n", mask, value, result);
  if (result == 0) printf("Your value is even\n");
  else printf("Your value is odd\n");
  
  return 0;
}


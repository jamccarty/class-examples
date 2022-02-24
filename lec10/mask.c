#include <stdio.h>

int main(){
  int value = 0;
  printf("Enter a value: ");
  scanf(" %d", &value);
 
  unsigned int mask = 0x1;
  int result = mask & value;
  printf("Mask: %08X Value: %08X Result %08X\n", mask, value, result);
  if(result == 0) printf("Your value is even\n");
  else printf("Your value is odd\n");

  int value1 = 0;
  int value2 = 0;
  printf("Enter a value: ");
  scanf(" %d", &value1);
  printf("Enter another value: ");
  scanf(" %d", &value2);

  mask = 0x80000000;
  int result1 = mask & value1;
  int result2 = mask & value2;
  printf("Mask: %08X Value1: %08X Value2: %08X Result1: %08X Result2: %08X\n", 
      mask, value1, value2, result1, result2);
  if(result1 == result2) printf("Signs match!\n");
  if(result1 != result2) printf("Signs don't match\n");

  return 0;
}

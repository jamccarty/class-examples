#include <stdio.h>
#include <stdlib.h>

int main(){
  unsigned int a = 0xAB;

  unsigned int leftMask = 0xF0;
  unsigned int rightMask = 0x0F;
  unsigned int left = (leftMask & a);
  unsigned int right = (rightMask & a);
  unsigned int leftShift = left >> 4;
  unsigned int rightShift = right << 4;

  unsigned flipped = leftShift | rightShift;

  printf("Left: %03X Right: %03X\n", left, right);
  printf("Left %03X Right: %03X\n", leftShift, rightShift);
  printf("Before: %03X After: %03X\n", a, flipped);

  return 1;
}

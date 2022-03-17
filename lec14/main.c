#include <stdio.h>
#include "op.h"

int main() {
  int a, b;
  printf("Enter first value: ");
  scanf(" %d", &a);

  printf("\nEnter second value: ");
  scanf(" %d", &b);

  int c = op(a, b);
  printf("\nThe result is: %d\n", c);
  return 0;
}

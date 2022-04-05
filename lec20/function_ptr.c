#include <stdio.h>

typedef void (*functionType)(int);

void example(int a) {
  printf("This is a function stored as data! %d\n", a);
}
 
int main() {
  functionType myFunction = example;
  (*myFunction)(10);
}

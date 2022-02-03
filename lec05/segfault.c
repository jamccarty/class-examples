#include <stdio.h>
#include <string.h>

void initialize(char text[]) {
  strcpy(text, "pina collada");
}

int main() {
  char str1[5];
  initialize(str1);
  printf("%s\n", str1);
  return 0;
}

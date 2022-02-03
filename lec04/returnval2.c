#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* code(int v) {
  if (v == 0) return "val0";
  else if (v == 1) return "val1";
  return "val2";
}

int main() {
  srand(time(0));
  int val = rand() % 3;
  printf("%s\n", code(val));
  return 0;
}

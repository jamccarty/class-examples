#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char* code(int v) {
  char* msg = malloc(sizeof(char) * 16);
  if (v == 0) strcpy(msg, "val0");
  else if (v == 1) strcpy(msg, "val1");
  else if (v == 2) strcpy(msg, "val2");
  return msg;
}

int main() {
  srand(time(0));
  int val = rand() % 3;
  char *m = code(val);
  printf("%s\n", m);
  free(m);
  return 0;
}

#include <stdio.h>

int main() {
  int value = 0xAABBCCDD;
  char* p = (char *) &value;

  int i;
  for (i = 0; i < sizeof(value); i++)  {
    printf("Address %p: %02hhX\n", p, *p);
    p += 1;
  }
}


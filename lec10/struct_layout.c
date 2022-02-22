#include <stdio.h>

struct mystery {
  char c;
  float q[4];
};

int main() {
  struct mystery m;
  printf("sizeof(mystery} = %lu bytes\n", sizeof(struct mystery));
  printf("mystery.c    - %p\n", &(m.c));
  printf("mystery.q[0] - %p\n", &(m.q[0]));
  printf("mystery.q[1] - %p\n", &(m.q[1]));
  printf("mystery.q[2] - %p\n", &(m.q[2]));
  printf("mystery.q[3] - %p\n", &(m.q[3]));
  return 0;
}

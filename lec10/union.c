#include <stdio.h>

struct point {
  union {
    struct {
      float x;
      float y;
    };
    float v[2];
  };
};

int main() {
  struct point p;
  printf("p.x    - %p\n", &(p.x));
  printf("p.y    - %p\n", &(p.y));
  printf("p.v[0] - %p\n", &(p.v[0]));
  printf("p.v[1] - %p\n", &(p.v[1]));

  p.y = -3.0;
  printf("y value is %f\n", p.v[1]);
  return 0;
}

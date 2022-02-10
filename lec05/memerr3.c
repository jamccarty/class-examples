// Freeing already freed memory
#include <stdlib.h>

int main() {
  int* values = malloc(sizeof(int) * 10);
  free(values);
  values = NULL;
  free(values);
}

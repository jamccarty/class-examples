#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct chunk {
  int size;
  struct chunk *next;
};
struct chunk *flist = NULL;

void *malloc (size_t size) {
  if (size == 0){
    return NULL;
  }
  void *memory = sbrk(size);
  if (memory == (void *) -1) {
    return NULL;
  } else {
    return memory;
  }
}

void free(void *memory) {
  return;
}


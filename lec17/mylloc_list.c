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
  // Step 1: check free list for memory 
  // If found, remove it from free list, and return it

  // Step 2: only allocated if no memory found
  void *memory = sbrk(size + sizeof(struct chunk));
  if (memory == (void *) -1) {
    return NULL;
  } else {
    struct chunk* chunk = (struct chunk*) memory;
    chunk->size = size;
    chunk->next = NULL;
    return (void*) (chunk + 1);
  }
}

void free(void *memory) {
  // Add memory free list
  return;
}


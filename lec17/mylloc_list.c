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

  //Step 1: check free list for memory
  //if found, remove it from free list, and return 
  
  //Step 2: only allocated if no memory found
  void *memory = sbrk(size);
  if (memory == (void *) -1) {
    return NULL;
  } else {
    struct chunk *ptr = flist;
    chunk *prev = NULL;

    while(ptr != NULL){
      if(ptr -> size >= size){
        if(prev != NULL){
          return (void *)(ptr + 1);
        }else{
          flist = ptr -> next;
        }
        return (void *)(ptr + 1);
      }else{
        prev = ptr;
        ptr = ptr -> next;
      }
    }
    prev -> next = ptr;
    return (void *memory)(ptr + 1);
  }
}

void free(void *memory) {
  return;
}


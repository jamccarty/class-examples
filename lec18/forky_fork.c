#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

void main() {
  pid_t pid;

  printf("L0\n"); 
  pid = fork();

  if(pid == 0) {
    printf("L1\n");
    pid = fork();

    if(pid == 0){
      printf("L2\n");
      fork();
    }
  }
  printf("Bye\n");
}



#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() {

   int child_status; 
   pid_t pid; 

   if (fork() == 0) {
      printf("C\n");
   }
   else {
      printf("P\n");
      pid = wait(&child_status);
      printf("X\n");
   }
   printf("Bye\n");
   exit(0);
}


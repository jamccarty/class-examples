#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  printf("L0 ");
  fflush(stdout); // makes sure we see L0

  fork();
  printf("L1 "); 
  fflush(stdout); // makes sure we see L1

  fork();
  printf("bye\n"); 
  sleep(10);
}

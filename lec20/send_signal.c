#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main() {

  int pid = 0;
  printf("Enter a process id: ");
  scanf(" %d", &pid);

  kill(pid, SIGALRM);

}


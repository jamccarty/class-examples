#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  printf("Let's get started\n");
  pid_t pid = 0;
  pid = fork();
  printf("pid = %d\n", pid);
  sleep(10);
}

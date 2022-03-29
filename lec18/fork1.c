#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  pid_t pid;
  pid = fork();
  printf("pid = %d\n", pid);
  sleep(10);
}

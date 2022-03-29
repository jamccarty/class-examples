#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  printf("Let's get started\n");
  pid_t pid = 0;
  pid = fork();
  if (pid == 0) {
    printf("hello from child! %d\n", getpid());
  } else {
    printf("hello from parent! %d\n", getpid());
  }
  sleep(10);
}

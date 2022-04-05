#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <time.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/shm.h>
#include <sys/ipc.h>

int main() {
  int size = 41;

  int shmid;
  shmid = shmget(IPC_PRIVATE, sizeof(char) * size, 0644 | IPC_CREAT);
  if (shmid == -1) {
    perror("Error: cannot initialize shared memory\n");
    exit(1);
  }

  char* buffer = shmat(shmid, NULL, 0);
  if (buffer == (void*) -1) {
    perror("Error: cannot access shared memory\n");
    exit(1);
  } 

  buffer[40] = '\0';
  for (int i = 0; i < 4; i++) {
    int pid = fork();
    if (pid == 0) {
      char c = i+'1'; // convert from integer to char
      for (int j = 0; j < 9; j++) {
        buffer[i*10 + j] = c;
      }
      buffer[i*10+9] = '\n';
      exit(0);
    } else {
      printf("Launched child process: %d\n", pid);
    }
  }

  for (int i = 0; i < 4; i++) {
    int status;
    int pid = wait(&status);
    printf("Child process complete: %d\n", pid);
  }

  printf("The final result is\n");
  printf("%s", buffer);

  if (shmdt(buffer) == -1) {
    perror("Error: cannot detatch from shared memory\n");
    exit(1);
  }

  if (shmctl(shmid, IPC_RMID, 0) == -1) {
    perror("Error: cannot remove shared memory\n");
    exit(1);
  }   
}

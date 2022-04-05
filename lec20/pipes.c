// C program to demonstrate use of fork() and pipe()
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define READ 0
#define WRITE 1

int main()
{
  // We use two pipes
  // First pipe to send input string from parent
  // Second pipe to send concatenated string from child

  int parent2child[2]; 
  int child2parent[2]; 

  pid_t p;
  if (pipe(parent2child) == -1) {
    fprintf(stderr, "Pipe Failed");
    return 1;
  }
  if (pipe(child2parent) == -1) {
    fprintf(stderr, "Pipe Failed");
    return 1;
  }

  p = fork();
  if (p > 0) { // parent
    write(parent2child[WRITE], "marco", strlen("marco") + 1);
    wait(NULL); // write for child to finish

    char concat_str[100];
    read(child2parent[READ], concat_str, 100); // read msg from child
    printf("Concatenated string %s\n", concat_str);

    close(parent2child[READ]); 
    close(parent2child[WRITE]);
    close(child2parent[READ]);
    close(child2parent[WRITE]); 
  }
  else { // child

    // Read message from parent
    char concat_str[100];
    read(parent2child[READ], concat_str, 100);

    // respond to parent
    strcat(concat_str, "polo");
    write(child2parent[WRITE], concat_str, strlen(concat_str) + 1);

    close(parent2child[READ]);
    close(parent2child[WRITE]); 
    close(child2parent[READ]);
    close(child2parent[WRITE]);

    exit(0);
  }
}


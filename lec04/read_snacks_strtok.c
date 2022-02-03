#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  FILE* infile = NULL;

  infile = fopen("snacks.csv", "r");
  if (infile == NULL) {
    printf("Error: unable to open file %s\n", "input.txt");
    exit(1);
  }

  char buffer[1024];  // Allocate with more space than you think you need
  while (fgets(buffer, 1024, infile) != NULL) {
    char name[512];
    float cost = 0.0;

    char* token = strtok(buffer, ",");
    if (token != NULL) strcpy(name, token);

    token = strtok(NULL, ","); // use same buffer as before
    if (token != NULL) cost = atof(token);

    printf("Read data: %s $%.2f\n", name, cost);    
  }

  fclose(infile);
}


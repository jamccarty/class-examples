#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE* fp = fopen("tolstoy.txt", "r");
  if (!fp) {
    printf("Cannot open file!\n");
    exit(1);
  }

  int lettercount = 0;
  char buffer[1024];
  while (fgets(buffer, 1024, fp) != NULL) {
    for (int i = 0; buffer[i] != '\0'; i++) {
      if (buffer[i] >= 'a' && buffer[i] <= 'z') {
        lettercount++;
      }
    } 
  }
  printf("letter count = %d\n", lettercount);

  fclose(fp);
  return 0; 
}

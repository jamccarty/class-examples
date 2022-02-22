#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
  unsigned int d;

  printf("Enter an unsigned int: ");
  scanf("%u", &d);

  while(d != 0){
    int newd = d / 2;
    printf("\n%d / 2 = %d", d, newd);
    d = newd;
  }
  printf("\n");

  return 0;
}

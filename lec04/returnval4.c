#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct studentT {
    char  name[64];
    int   age;
    float gpa;
    int   grad_yr;
};

struct studentT create(char* name, int age, float gpa, int grad_yr) {
  struct studentT s;
  strcpy(s.name, name);
  s.age = age;
  s.gpa = gpa;
  s.grad_yr = grad_yr;
  return s;
}

int main() {
  struct studentT student1 = create("Ruth", 17, 3.5, 2021);

  printf("Name: %s\n", student1.name);
  printf("Age: %d\n", student1.age);
  printf("GPA: %.2f\n", student1.gpa);
  printf("Grad Yr: %d\n", student1.grad_yr);
  return 0;
}

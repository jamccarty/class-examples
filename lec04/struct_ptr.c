#include <stdio.h>
#include <string.h>

/* define a new struct type (outside function bodies) */
struct studentT {
    char  name[64];
    int   age;
    float gpa;
    int   grad_yr;
};

void print(const char* prefix, struct studentT s) {
  printf("--------------------\n");
  printf("%s\n", prefix);
  printf("Name: %s\n", s.name);
  printf("Age: %d\n", s.age);
  printf("GPA: %.2f\n", s.gpa);
  printf("Grad Yr: %d\n", s.grad_yr);
  printf("--------------------\n");
}

<<<<<<< HEAD
void changeName(struct studentT *s, char* newName) {
=======
void changeName(struct studentT* s, char* newName) {
>>>>>>> 96f10abbca85925e2617842f4338dc7e72304d13
  if (newName == NULL) {
    return;
  }
  strcpy(s->name, newName);
}

<<<<<<< HEAD
void changeGpa(struct studentT *s, float newGpa) {
=======
void changeGpa(struct studentT* s, float newGpa) {
>>>>>>> 96f10abbca85925e2617842f4338dc7e72304d13
  s->gpa = newGpa;
}

int main() {
    struct studentT student1;

    strcpy(student1.name, "Ruth");
    student1.age = 17;
    student1.gpa = 3.5;
    student1.grad_yr = 2021;

    print("ORIGINAL", student1);
    changeName(&student1, "Kwame");
    print("AFTER CHANGE NAME", student1);

    changeGpa(&student1, 3.7);
    print("AFTER CHANGE GPA", student1);

    return 0;
}

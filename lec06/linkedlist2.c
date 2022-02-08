#include <stdio.h>
#include <stdlib.h>

struct node {
  int val;
  struct node* next;
};

struct node* insert_front(int val, struct node* head) {
  struct node* n = malloc(sizeof(struct node));
  if (n == NULL) {
    printf("ERROR: Out of space!\n");
    exit(1);
  }
  n->val = val;
  n->next = head;
  return n;
}

void print(struct node* list) {
  for (struct node* n = list; n != NULL; n = n->next) {
    printf("Val: %d\n", n->val);
  }
}

int main() {
  struct node* n3 = insert_front(2, NULL);
  struct node* n2 = insert_front(1, n3);
  struct node* n1 = insert_front(0, n2);
  print(n1); 

  free(n1);
  free(n2);
  free(n3);
}


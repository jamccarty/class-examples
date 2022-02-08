#include <stdio.h>

struct node {
  int val;
  struct node* next;
};

int main() {

  struct node n1 = {1, NULL};
  struct node n2 = {2, NULL};
  struct node n3 = {3, NULL};

  struct node* list;
  list = &n1;
  n1.next = &n2;
  n2.next = &n3;

  for (struct node* n = list; n != NULL; n = n->next) {
    printf("Val: %d\n", n->val);
  }
}


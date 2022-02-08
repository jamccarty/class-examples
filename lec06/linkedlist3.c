#include <stdio.h>
#include <stdlib.h>

struct node {
  int val;
  struct node* next;
};

void insert_front(int val, struct node* head) {
  struct node* n = malloc(sizeof(struct node));
  if (n == NULL) {
    printf("ERROR: Out of space!\n");
    exit(1);
  }
  n->val = val;
  n->next = head;
  head = n;
}

void print(struct node* list) {
  for (struct node* n = list; n != NULL; n = n->next) {
    printf("Val: %d\n", n->val);
  }
}

int main() {
  struct node *head = NULL;
  insert_front(0, head);
  insert_front(1, head);
  insert_front(2, head);
  print(head); 
}


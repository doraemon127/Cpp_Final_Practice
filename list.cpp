#include "list.h"

void build(node * & head) {
  srand((unsigned)time(0)); //random seed
  node* current = new node();
  current->data = (rand()%20 + 1); //random number between 1 and 20
  head = current;
  node* previous = current;
  int additionalValues = (rand()&5); //need between 10-15 values, so 10+additionalValues
  for (int a = 0; a < 10+additionalValues; a++) {
    current = new node();
    previous->next = current;
    current->data = (rand()%20 + 1);
    previous = current;
  }
  current->next = NULL;
}

void display_all(node * head) {
  while (head != NULL) {
    cout << head->data << " ";
    head = head->next;
  }
  cout << endl;
}



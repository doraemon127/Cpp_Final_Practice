//new cpp file for practice functions

#include "list.h"

//function to remove head (first node) of linked list
//STEPS:
// (1) Make second node the head
// (2) Delete memory allocated for first node
void remove_head(node * & head)
{
  node* temp = head;
  head = head->next;
  delete temp;
  return;
}



//function to add new node to end of linked list
void append(node* & head, int val) {
  node* new_end = new node();
  node* temp = head;
  while (temp->next != NULL) { //traverse until end
    temp = temp->next;
  }
  //once end of linked list is reached, add new node
  temp->next = new_end;
  new_end->data = val;
  return;
}



//function to insert a new node at the beginning of linked list
//STEPS:
// (1) Create a new node that points to head and has a value of val
// (2) Make head equal to this new node
void new_head(node* &head, int val) {
  node* newHead = new node();
  newHead->data = val;
  newHead->next = head;
  head = newHead;
  return;  
}


//function to remove the last node of the linked list
//STEPS:
// (1) Find second to last node and make it point to NULL
//     - Delete last node and now second to last is at the end
// (2) Free the memory of the last node
void remove_end(node* & head) {
  node* second_to_last = head;
  while (second_to_last->next->next != NULL) {  //find second to last node
    second_to_last = second_to_last->next;
  }
  delete (second_to_last->next); //delete second to last node
  second_to_last->next = NULL; //change next of second to last
  return;
}


//function to insert node at nth position (1-based index, first node is indexed 1)
//STEPS:
// (1) Create a new node and set the data equal to passed value
// (2) Point new node to the n+1 node
// (3) Point n-1 node to new node
void insert_at_position(node* &head, int value, int pos) {
  //create new node
  node* new_node = new node();
  new_node->data = value;
  new_node->next = NULL;

  if (pos == 1) {   //insert at the head
    new_node->next = head;
    head = new_node;
    return;
  }

  node* prev = head;
  for(int i = 0; i < pos - 2; i++) { //find n-1 (prev) node
    prev = prev->next;
  }
  new_node->next = prev->next; //point new node to n+1 node
  prev->next = new_node; //point n-1 node to new node
  return;
}


//function to delete node at nth position (1-based index, first node is indexed 1)
//STEPS:
// (1) Find previous (n-1) node
// (2) Change next of previous node
// (3) Free memory of node to be deleted
void delete_at_position(node* & head, int pos) {

  node* prev = head; //initialze prev as head

  //if want to delete head
  if (pos == 1) {
    head = prev->next; //currently prev=head, so head now points to second node
    delete prev;
    return;
  }

  for (int i = 0; i < pos - 2; i++) {
    prev = prev->next;
  } //prev points to (n-1)th node

  node* current = prev->next;
  prev->next = current->next; //fix the links
  delete current; //free memory
}


//function to reverse a linked list
//STEPS:
// (1) Have to reverse the links...head should point at the last, last at second-to-last, etc.
// Iterative: Traverse and make each node point to previous node instead of next node.
//            For first node, prev node is NULL. At end, adjust the head.
void reverse_list(node* & head) {

  node* current = head;
  node* prev = NULL;
  node* next;
  while (current != NULL) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  head = prev;
  return;
}



//function to insert node after given previous node position prev_pos (if prev_pos is 2, make new_node the 3rd node in list)
void insert_after(node* &head, int value, int prev_pos) {
  node* new_node = new node();
  new_node->data = value;
  new_node->next = NULL;

  node* prev = head;
  for(int i = 0; i < prev_pos - 1; i++) {
    prev = prev->next;
  } //previous node found

  new_node->next = prev->next;
  prev->next = new_node;
  return;
}


//function to delete entire linked list
void delete_list(node* &head) {
  node* current = head;
  node* next = NULL;

  while(current != NULL) {
    next = current->next;
    delete current;
    current = next;
  }

  head = NULL;
  return;
}


//function to get data of Nth node in linked list (1-based index... first node is position 1)
int get_Nth(node* & head, int pos) {
  node* current = head;
  int count = 1; //position of current node (note, to do 0-based index make count = 0)
  while (current != NULL) {
    if (count == pos) {
      return (current->data);
    }
    count++;
    current = current->next;
  }
  return -1;
}

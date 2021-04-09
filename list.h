//list.h
#include <iostream>
#include <cctype>
#include <cstdlib>
using namespace std;

struct node
{
    int data;
    node * next;
};

/* *****************YOUR TURN! ******************************** */
/* PLACE YOUR PROTOTYPE HERE */
void remove_head(node* & head);
void append(node* & head, int val);
void new_head(node* & head, int val);
void remove_end(node* & head);
void insert_at_position(node* & head, int value, int pos);
void delete_at_position(node* & head, int pos);
void reverse_list(node* & head);
void insert_after(node* & head, int value, int prev_pos);


/* These functions are already written and can be called to test out your code */
void build(node * & head);      //supplied
void display_all(node * head);  //supplied



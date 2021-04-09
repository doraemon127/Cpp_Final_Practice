#include "list.h"
using namespace std;

int main()
{
    node * head = NULL;
    build(head);
    display_all(head);

    //PLEASE PUT YOUR CODE HERE to call the function assigned
    //remove_head(head);
    //append(head, 12);
    //new_head(head, 12);
    //remove_end(head);
    //insert_at_position(head, 4, 2);
    //delete_at_position(head, 2);
    //reverse_list(head);
    //insert_after(head, 1, 2);
    
    display_all(head);   //print linked list again after removing head
    
    return 0;
}

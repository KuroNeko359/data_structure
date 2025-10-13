
// s -> prior = p
// s -> next = q
// p -> next -> prior = s
// p -> next = s

#include "linearlist/linkedlist/singly_linked_list.h"

int main(int argc, char *argv[]) {
    singly_linked_list * list_head = singly_list_init();
    singly_list_append(list_head,1);
    singly_list_append(list_head,2);
    singly_list_print(list_head);
    return 0;
}

#include "linked_list.c"

int main() {
    Node *head = initLinkedList();

    Node *node2 = createNode(2);
    head->next = node2;

    Node *node3 = createNode(3);
    node2->next = node3;

    insertNode(head,0,createNode(1));
    printList(head);


    return 0;
}
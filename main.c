#include "linked_list.c"

int main() {
    Node *head = initLinkedList(1);

    Node *node2 = createNode(2);
    head->next = node2;

    Node *node3 = createNode(3);
    node2->next = node3;

    appendNode(head,4);
    appendNode(head,5);

    insertNode(head,0,createNode(1));
    printList(head);
    printf("%d\n",getListLength(head));
    Node *newHeadNode = reverseNode(head);
    printList(newHeadNode);

    return 0;
}
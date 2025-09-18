#include "linked_list.c"

int main() {
    Node *head = createNode(1);

    Node *node2 = createNode(2);
    head->next = node2;

    Node *node3 = createNode(3);
    node2->next = node3;

    printList(head);

    insertNode(head,0,createNode(4));

    printList(head);
    printf("%d\n",head->data);

    Node *lastNode = getLastNode(head);
    printf("LastNodeData:%d\n",lastNode->data);



    return 0;
}
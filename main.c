#include "linked_list.c"

int main() {
    HeadNode *head = initLinkedList(1);
    Node *node1 = head->next;
    printf("%d\n",node1->data);
    Node *node2 = createNode(2);
    node1->next = node2;

    Node *node3 = createNode(3);
    node2->next = node3;


    print(head);
    printf("%d\n",getListLength(head));


    return 0;
}
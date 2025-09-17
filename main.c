#include "linked_list.c"

int main() {
    Node *node1 = createNode(1);

    Node *node2 = createNode(2);
    node1->next = node2;

    Node *node3 = createNode(3);
    node2->next = node3;

    printList(node1);



    Node *lastNode = getLastNode(node1);
    printf("LastNodeData:%d\n",lastNode->data);



    return 0;
}
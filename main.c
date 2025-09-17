#include "linked_list.c"

int main() {
    Node *node1 = createNode(1);
    printf("%d\n", node1->data);

    Node *node2 = createNode(2);
    node1->next = node2;

    printf("%d\n", node1->next->data);

    printList(node1);

    // 释放内存
    free(node2);
    free(node1);

    return 0;
}
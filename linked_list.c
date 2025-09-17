#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;


Node *createNode(int data) {
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void printList(Node *head) {
    printf("%d\n",head->data);
    if (head->next != NULL) {
        printList(head->next);
    }
}


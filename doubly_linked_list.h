//
// Created by KuroNeko359 on 2025/9/21.
//

#ifndef CSAPP_DOUBLY_LINKED_LIST_H
#define CSAPP_DOUBLY_LINKED_LIST_H

typedef struct Node {
    int data;
    Node *prev;
    Node *next;
} Node;

void printList(Node *headNode);

void appendNode(Node *headNode,int data);

Node *createNode(int data);



#endif //CSAPP_DOUBLY_LINKED_LIST_H
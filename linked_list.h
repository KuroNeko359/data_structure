//
// Created by 丁吉智 on 2025/9/19.
//

#ifndef CSAPP_LINKED_LIST_H
#define CSAPP_LINKED_LIST_H

typedef struct Node {
    int data;
    struct Node *next;
} Node;

/**
 * Create node, can be used to initialise the node list.
 * @param data The data of the node.
 * @return The pointer of the node.
 */
Node *createNode(int data);

/**
 * Initialising a linked list.
 * @param data
 * @return
 */
Node *initLinkedList();

/**
 * Get the last node of the node list.
 * @param head  Head of node list.
 * @return      The pointer of the last node.
 */
Node *getLastNode(Node *head);

/**
 * Append a node in the last of the linked list.
 * @param data  The data of the new node.
 * @return      The pointer of the node that you had added.
 */
Node *appendNode(Node *head, int data);

/**
 * Print the linked list recursively.
 * @param head The head node of the linked list.
 */
void printList(Node *head);

/**
 * Free memory used of the linked list.
 * @param head The head node of the linked list.
 */
void freeList(Node *head);

/**
 * Insert a point into a singly linked list at the specified position.
 * @param headNode  The head node of the linked list.
 * @param index     The position index where the new node should be inserted.
 *                  Must be a non-negative integer (0 or greater).
 * @param newNode   Pointer to the new node that will be inserted into the list.
 *                  Assumes newNode is properly allocated and initialized.
 */
void insertNode(Node *headNode, int index, Node *newNode);

Node *reverseNode(Node *head);

Node *reverseNodeRecursive(Node *head);

/**
 * This function is used for get the linked list length.
 * @param head The head of the linked list.
 * @return length
 */
unsigned int getListLength(Node *head);

/**
 * The function can be used to delete a node at any position.
 * @param head      The head node of the linked list.
 * @param index     The position index of the node you want to delete.
 */
void deleteNode(Node *head, int index);

#endif //CSAPP_LINKED_LIST_H

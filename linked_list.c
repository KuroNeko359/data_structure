#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"


Node *createNode(int data) {
    Node *temp = (Node *) malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}


Node *initLinkedList() {
    return createNode(0);
}

Node *getLastNode(Node *head) {
    while (head->next != NULL) {
        head = head->next;
    }
    return head;
}

Node *appendNode(Node *head, int data) {
    Node *newNode = createNode(data);
    Node *lastNode = getLastNode(head);
    lastNode->next = newNode;
    return newNode;
}


void printList(Node *head) {
    if (head->next != NULL) {
        printf("%d -> ", head->next->data);
        printList(head->next);
    } else {
        printf("NULL\n");
    }
}


void freeList(Node *head) {
    // Recursive free next ( if head -> next is NULL, stopping recursive call )
    if (head->next != NULL) {
        freeList(head->next);
    }
    free(head);
    printf("free:%p\n", head);
}


void insertNode(Node *headNode, int index, Node *newNode) {
    if (index < 0) {
        printf("Index must be > 0.");
        return;
    }
    for (; index > 0; index--) {
        headNode = headNode->next;
    }
    Node *temp = headNode->next;
    headNode->next = newNode;
    newNode->next = temp;
}


//TODO The function of reverse node, unfinished.
//TODO Replace it with return void value.
Node *reverseNode(Node *head) {
    if (head->next == NULL) {
        printf("Linked list must has one node at least");
        return head;
    }
    Node *currentNode = head->next;
    Node *prevNode = NULL;

    while (currentNode->next != NULL) {
        Node *temp = currentNode->next;
        currentNode->next = prevNode;
        prevNode = currentNode;
        currentNode = temp;
    }
    currentNode->next = prevNode;

    Node *newHeadNode = createNode(0);
    newHeadNode->next = currentNode;
    return newHeadNode;
}

Node *reverseNodeRecursive(Node *head) {
    reverseNodeRecursive(head->next);
    head->next = head;
}


unsigned int getListLength(Node *head) {
    unsigned int len = 0;
    while (head->next != NULL) {
        head = head->next;
        len++;
    }
    return len;
}


void deleteNode(Node *head, int index) {
    if (index >= getListLength(head)) {
        printf("Index is out of the linked list.\n");
        return;
    }
    for (; index > 0; index--) {
        head = head->next;
    }
    Node *temp = head->next;
    if (temp->next != NULL) {
        head->next = temp->next;
    } else head->next = NULL;

    free(temp);
    temp = NULL; // Avoid wild pointer.
}

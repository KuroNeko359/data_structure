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
        printf("|%p|%d| -> ", head->next, head->next->data);
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

void reverseNode(Node *headNode) {
    if (headNode->next == NULL) {
        printf("Linked list must has one node at least");
        return;
    }
    Node *currentNode = headNode->next;
    Node *prevNode = NULL;

    while (currentNode->next != NULL) {
        Node *temp = currentNode->next;
        currentNode->next = prevNode;
        prevNode = currentNode;
        currentNode = temp;
    }
    currentNode->next = prevNode;

    headNode->next = currentNode;
}


Node *doReverse(Node *node) {
    if (node == NULL||node->next == NULL) {
        return node;
    }
    Node *new_head = doReverse(node->next);
    (node->next)->next = node;
    node->next = NULL;
    return new_head;
}

 Node* doReverseRecursively(Node* currentNode) {
    if (currentNode == NULL || currentNode->next == NULL) {
        return currentNode; // Return lastNode
    }
    Node* lastNode = doReverse(currentNode->next);
    currentNode->next->next = currentNode;
    currentNode->next = NULL;
    return lastNode;
}

void reverseNodeRecursively(Node *head) {
    head->next = doReverseRecursively(head->next);
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

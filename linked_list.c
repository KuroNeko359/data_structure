#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

/**
 * Create node, can be used to initialise the node list.
 * @param data The data of the node.
 * @return The pointer of the node.
 */
Node *createNode(int data) {
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

/**
 * Get the last node of the node list.
 * @param head Head of node list.
 * @return The pointer of the last node.
 */
Node *getLastNode(Node *head) {
    while (head->next != NULL) {
        head = head->next;
    }
    return head;
}

/**
 * Append node in last of the node list.
 * @param data
 * @return The pointer of the node you added.
 */
Node *appendNode(Node *head,int data) {
    Node *newNode = createNode(data);
    Node * lastNode = getLastNode(head);
    lastNode->next = newNode;
    return newNode;
}

/**
 * Print the node list.
 * @param head The head of the node list.
 */
void printList(Node *head) {
    printf("%d\n",head->data);
    if (head->next != NULL) {
        printList(head->next);
    }
}

/**
 * Free memory of the node list.
 * @param head The head of the node list.
 */
void freeList(Node *head) {
    // Recursive free next ( if head -> next is NULL, stopping recursive call )
    if (head->next != NULL) {
        freeList(head->next);
    }
    free(head);
    printf("free:%p\n",head);
}

void insertNode(Node *headNode, int index, Node *newNode) {
    if (index < 0) {
        printf("Index must be > 0.");
        return;
    }
    // TODO Consider the case that index is 0,
    // if (index == 0) {
    //     newNode->next = headNode;
    //     *headNode = *newNode;
    //
    // }
    for (;index - 1 > 0; index--) {
        headNode = headNode->next;
    }
    Node *temp = headNode->next;
    headNode->next = newNode;
    newNode->next = temp;
}

//TODO The function of reverse node.
void reverseNode() {}



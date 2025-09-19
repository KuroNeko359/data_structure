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

Node *initLinkedList(int data) {
    return createNode(0);
}

/**
 * Get the last node of the node list.
 * @param head  Head of node list.
 * @return      The pointer of the last node.
 */
Node *getLastNode(Node *head) {
    while (head->next != NULL) {
        head = head->next;
    }
    return head;
}

/**
 * Append a node in the last of the linked list.
 * @param data  The data of the new node.
 * @return      The pointer of the node that you had added.
 */
Node *appendNode(Node *head,int data) {
    Node *newNode = createNode(data);
    Node * lastNode = getLastNode(head);
    lastNode->next = newNode;
    return newNode;
}

/**
 * Print the linked list recursively.
 * @param head The head node of the linked list.
 */
void printList(Node *head) {
    if (head->next != NULL) {
        printf("%d -> ",head->next->data);
        printList(head->next);
    }else {
        printf("NULL\n");
    }
}

/**
 * Free memory used of the linked list.
 * @param head The head node of the linked list.
 */
void freeList(Node *head) {
    // Recursive free next ( if head -> next is NULL, stopping recursive call )
    if (head->next != NULL) {
        freeList(head->next);
    }
    free(head);
    printf("free:%p\n",head);
}

/**
 * Insert a point into a singly linked list at the specified position.
 * @param headNode  The head node of the linked list.
 * @param index     The position index where the new node should be inserted.
 *                  Must be a non-negative integer (0 or greater).
 * @param newNode   Pointer to the new node that will be inserted into the list.
 *                  Assumes newNode is properly allocated and initialized.
 */
void insertNode(Node *headNode, int index, Node *newNode) {
    if (index < 0) {
        printf("Index must be > 0.");
        return;
    }
    for (;index > 0; index--) {
        headNode = headNode->next;
    }
    Node *temp = headNode->next;
    headNode->next = newNode;
    newNode->next = temp;
}


//TODO The function of reverse node.
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
    currentNode->next=prevNode;

    Node * newHeadNode = createNode(0);
    newHeadNode->next = currentNode;
    return newHeadNode;
}

Node *reverseNodeRecursive(Node *head);


/**
 * This function is used for get the linked list length.
 * @param head The head of the linked list.
 * @return length
 */
unsigned int getListLength(Node *head) {
    unsigned int len = 0 ;
    while (head->next != NULL) {
        head = head->next;
        len++;
    }
    return len;
}

/**
 * The function can be used to delete a node at any position.
 * @param head      The head node of the linked list.
 * @param index     The position index of the node you want to delete.
 */
void deleteNode(Node *head,int index) {
    if (index >= getListLength(head)) {
        printf("Index is out of the linked list.\n");
        return;
    }
    for (;index > 0; index--) {
        head = head->next;
    }
    Node *temp = head->next;
    if (temp->next != NULL) {
        head->next = temp->next;
    }else head->next = NULL;

    free(temp);
    temp=NULL;// Avoid wild pointer.
}


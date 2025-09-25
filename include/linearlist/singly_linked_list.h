//
// Created by 丁吉智 on 2025/9/19.
//

#ifndef CSAPP_LINKED_LIST_H
#define CSAPP_LINKED_LIST_H

typedef struct single_list_node {
    int data;
    struct single_list_node *next;
} single_list_node;

/**
 * Create node, can be used to initialise the node list.
 * @param data The data of the node.
 * @return The pointer of the node.
 */
single_list_node *single_list_create(int data);

/**
 * Initialising a linked list.
 * @param data
 * @return
 */
single_list_node *single_list_init();

/**
 * Get the last node of the node list.
 * @param head  Head of node list.
 * @return      The pointer of the last node.
 */
single_list_node *single_list_get_tail(single_list_node *head);

/**
 * Append a node in the last of the linked list.
 * @param data  The data of the new node.
 * @return      The pointer of the node that you had added.
 */
single_list_node *single_list_append(single_list_node *head, int data);

/**
 * Print the linked list recursively.
 * @param head The head node of the linked list.
 */
void single_list_print(single_list_node *head);

/**
 * Free memory used of the linked list.
 * @param head The head node of the linked list.
 */
inline void single_list_free(single_list_node *head);

/**
 * Insert a point into a singly linked list at the specified position.
 * @param headNode  The head node of the linked list.
 * @param index     The position index where the new node should be inserted.
 *                  Must be a non-negative integer (0 or greater).
 * @param newNode   Pointer to the new node that will be inserted into the list.
 *                  Assumes newNode is properly allocated and initialized.
 */
inline void single_list_insert(single_list_node *head_node, int index, single_list_node *new_node);

/**
 * The function is used for reversing a linked list.
 * @param head The reference of the pointer of the head node.
 */
inline void single_list_reverse(single_list_node *head);

inline void single_list_reverse_rec(single_list_node *head);

/**
 * This function is used for get the linked list length.
 * @param head The head of the linked list.
 * @return length
 */
inline unsigned int single_list_get_length(single_list_node *head);

/**
 * The function can be used to delete a node at any position.
 * @param head      The head node of the linked list.
 * @param index     The position index of the node you want to delete.
 */
inline void single_list_delete(single_list_node *head, int index);

#endif //CSAPP_LINKED_LIST_H

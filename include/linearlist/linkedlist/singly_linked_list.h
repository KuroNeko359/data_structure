//
// Created by 丁吉智 on 2025/9/19.
//

#ifndef CSAPP_SINGLY_LINKED_LIST_H
#define CSAPP_SINGLY_LINKED_LIST_H
#define SINGLY_LIST_ELEM_TYPE int

#include "types.h"


typedef struct singly_list_node {
    SINGLY_LIST_ELEM_TYPE data;
    struct singly_list_node *next;
} singly_list_node, singly_linked_list;

/**
 * Create node, can be used to initialise the node list.
 * @param data The data of the node.
 * @return The pointer of the node.
 */
singly_list_node *singly_list_create(SINGLY_LIST_ELEM_TYPE data);

/**
 * Initialising a linked list.
 * @param data
 * @return
 */
singly_linked_list *singly_list_init();

/**
 * Get the last node of the node list.
 * @param head  Head of node list.
 * @return      The pointer of the last node.
 */
singly_list_node *singly_list_get_tail(singly_linked_list *head);

/**
 * Append a node in the last of the linked list.
 * @param data  The data of the new node.
 * @return      The pointer of the node that you had added.
 */
singly_list_node *singly_list_append(singly_linked_list *head,
    SINGLY_LIST_ELEM_TYPE data);

/**
 * Print the linked list recursively.
 * @param head The head node of the linked list.
 */
void singly_list_print(singly_linked_list *head);

/**
 * Free memory used of the linked list.
 * @param head The head node of the linked list.
 */
inline void singly_list_free(singly_linked_list *head);

/**
 * Insert a point into a singly linked list at the specified position.
 * @param headNode  The head node of the linked list.
 * @param index     The position index where the new node should be inserted.
 *                  Must be a non-negative integer (0 or greater).
 * @param newNode   Pointer to the new node that will be inserted into the list.
 *                  Assumes newNode is properly allocated and initialized.
 */
inline void singly_list_insert(singly_linked_list *head, int index,
    singly_list_node *new_node);

/**
 * The function is used for reversing a linked list.
 * @param head The reference of the pointer of the head node.
 */
inline void singly_list_reverse(singly_linked_list *head);

inline void singly_list_reverse_rec(singly_linked_list *head);

/**
 * This function is used for get the linked list length.
 * @param head The head of the linked list.
 * @return length
 */
inline unsigned int singly_list_get_length(singly_linked_list *head);

/**
 * The function can be used to delete a node at any position.
 * @param head      The head node of the linked list.
 * @param index     The position index of the node you want to delete.
 */
inline void singly_list_delete(singly_linked_list *head, int index);

/**
 * Verify whether this linked list is empty.
 * @param head The head of the linked list.
 * @return If this linked list is empty, return true.
 */
bool singly_linked_list_is_empty(singly_linked_list *head);

#endif //CSAPP_LINKED_LIST_H

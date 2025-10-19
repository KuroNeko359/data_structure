//
// Created by KuroNeko359 on 2025/9/21.
//

#ifndef DATA_STRUCTURE_DOUBLY_LINKED_LIST_H
#define DATA_STRUCTURE_DOUBLY_LINKED_LIST_H

#define DOUBLY_LIST_ELEM_TYPE int

#include "types.h"


typedef struct doubly_list_node {
    DOUBLY_LIST_ELEM_TYPE data;
    struct doubly_list_node *prev, *next;
} doubly_list_node, doubly_linked_list;

/**
 * Print list.
 * @param head_node Head of the linked list.
 */
void doubly_list_print(doubly_linked_list *head_node);

/**
 * Append a node for this linked list.
 * @param head_node Head of the linked list.
 * @param data The data of the new node.
 */
void doubly_list_append(doubly_linked_list *head_node,
                        DOUBLY_LIST_ELEM_TYPE data);

/**
 * Create a new node.
 * @param data The data of the new node.
 * @return The pointer of the new node.
 */
doubly_list_node *doubly_list_create_node(DOUBLY_LIST_ELEM_TYPE data);

/**
 * Initialize a doubly linked list.
 * @return The head pointer of the head node.
 */
doubly_list_node *doubly_list_init();

/**
 * Get tail node of the linked list.
 * @param head The pointer of head node.
 * @return The pointer of tail node.
 */
doubly_list_node *doubly_list_get_tail(doubly_linked_list *head);

/**
 * Verify whether this linked list is empty.
 * @param head The head of the linked list.
 * @return If this linked list is empty, return true.
 */
bool doubly_linked_list_is_empty(doubly_linked_list *head);

#endif //DATA_STRUCTURE_DOUBLY_LINKED_LIST_H

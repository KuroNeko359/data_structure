//
// Created by KuroNeko359 on 2025/9/21.
//
#include "types.h"

#ifndef CSAPP_DOUBLY_LINKED_LIST_H
#define CSAPP_DOUBLY_LINKED_LIST_H

#define DOUBLY_LIST_ELEM_TYPE int

typedef struct doubly_list_node {
    DOUBLY_LIST_ELEM_TYPE data;
    struct doubly_list_node *prev, *next;
} doubly_list_node, doubly_linked_list;

void doubly_list_print(doubly_linked_list *head_node);

void doubly_list_append(doubly_linked_list *head_node,DOUBLY_LIST_ELEM_TYPE data);

doubly_list_node *doubly_list_create(DOUBLY_LIST_ELEM_TYPE data);

doubly_list_node *doubly_list_init(DOUBLY_LIST_ELEM_TYPE data);

doubly_list_node *doubly_list_get_tail(doubly_linked_list *head);

bool doubly_linked_list_is_empty(doubly_linked_list *head);

#endif //CSAPP_DOUBLY_LINKED_LIST_H

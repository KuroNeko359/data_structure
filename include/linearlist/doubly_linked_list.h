//
// Created by KuroNeko359 on 2025/9/21.
//

#ifndef CSAPP_DOUBLY_LINKED_LIST_H
#define CSAPP_DOUBLY_LINKED_LIST_H

typedef struct doubly_list_node {
    int data;
    struct doubly_list_node *prev;
    struct doubly_list_node *next;
} doubly_list_node;

void doubly_list_print(doubly_list_node *head_node);

void doubly_list_append(doubly_list_node *head_node,int data);

doubly_list_node *doubly_list_create(int data);

doubly_list_node *doubly_list_init(int data);

doubly_list_node *doubly_list_get_tail(doubly_list_node *head);

#endif //CSAPP_DOUBLY_LINKED_LIST_H
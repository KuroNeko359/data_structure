//
// Created by KuroNeko359 on 2025/9/21.
//
#include "doubly_linked_list.h"
#include <stdio.h>


void doubly_list_print(doubly_list_node *head) {
    if (head->next != NULL) {
        printf("|%p|%d|%p| <-> ", head->next, head->next->data,head->next);
        doubly_list_print(head->next);
    } else {
        printf("NULL\n");
    }
}

doubly_list_node *doubly_list_get_tail(doubly_list_node *head) {
    while (head->next != NULL) {
        head = head->next;
    }
    return head;
}

//
void doubly_list_append(doubly_list_node *head_node,int data) {
    doubly_list_node *last_node = doubly_list_get_tail(head_node);
    doubly_list_node * new_node = doubly_list_create(data);
    last_node->next = new_node;
    new_node->prev = last_node;
}

doubly_list_node *doubly_list_create(int data) {
    doubly_list_node *new_node;
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

doubly_list_node *initLinkedList(int data) {
    doubly_list_node * head;
    head->next = doubly_list_create(data);
    head->prev = NULL;
    head->data = 0;
    return head;
}




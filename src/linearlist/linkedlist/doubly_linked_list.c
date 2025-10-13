//
// Created by KuroNeko359 on 2025/9/21.
//
#include "../../../include/linearlist/linkedlist/doubly_linked_list.h"
#include <stdio.h>


void doubly_list_print(doubly_linked_list *head) {
    if (head->next != NULL) {
        printf("|%p|%d|%p| <-> ", head->next, head->next->data,head->next);
        doubly_list_print(head->next);
    } else {
        printf("NULL\n");
    }
}

doubly_list_node *doubly_list_get_tail(doubly_linked_list *head) {
    while (head->next != NULL) {
        head = head->next;
    }
    return head;
}

//
void doubly_list_append(doubly_linked_list *head_node,DOUBLY_LIST_ELEM_TYPE data) {
    doubly_list_node *last_node = doubly_list_get_tail(head_node);
    doubly_list_node * new_node = doubly_list_create(data);
    last_node->next = new_node;
    new_node->prev = last_node;
}

doubly_list_node *doubly_list_create(DOUBLY_LIST_ELEM_TYPE data) {
    doubly_list_node *new_node;
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

doubly_list_node *doubly_list_init(DOUBLY_LIST_ELEM_TYPE data) {
    doubly_list_node * head;
    head->next = doubly_list_create(data);
    head->prev = NULL;
    head->data = 0;
    return head;
}

bool doubly_linked_list_is_empty(doubly_linked_list *head) {
    if (head->next == NULL) {
        return true;
    }
    return false;
}




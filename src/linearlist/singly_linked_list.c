#include <stdlib.h>
#include <stdio.h>
#include "linearlist/singly_linked_list.h"

inline single_list_node *single_list_create(SINGLE_LIST_ELEM_TYPE data) {
    single_list_node *temp = (single_list_node *) malloc(sizeof(single_list_node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}


inline single_list_node *single_list_init() {
    return single_list_create(0);
}

inline single_list_node *single_list_get_tail(single_linked_list *head) {
    while (head->next != NULL) {
        head = head->next;
    }
    return head;
}

inline single_list_node *single_list_append(single_linked_list *head, SINGLE_LIST_ELEM_TYPE data) {
    single_list_node *new_node = single_list_create(data);
    single_list_node *last_node = single_list_get_tail(head);
    last_node->next = new_node;
    return new_node;
}


void single_list_print(single_linked_list *head) {
    if (head->next != NULL) {
        printf("|%p|%d| -> ", head->next, head->next->data);
        single_list_print(head->next);
    } else {
        printf("NULL\n");
    }
}


inline void single_list_free(single_linked_list *head) {
    // Recursive free next ( if head -> next is NULL, stopping recursive call )
    if (head->next != NULL) {
        single_list_free(head->next);
    }
    free(head);
    printf("free:%p\n", head);
}


inline void single_list_insert(single_linked_list *head, int index, single_list_node *new_node) {
    if (index < 0) {
        printf("Index must be > 0.");
        return;
    }
    for (; index > 0; index--) {
        head = head->next;
    }
    single_list_node *temp = head->next;
    head->next = new_node;
    new_node->next = temp;
}

inline void single_list_reverse(single_linked_list *head) {
    if (head->next == NULL) {
        printf("Linked list must has one node at least");
        return;
    }
    single_list_node *current_node = head->next;
    single_list_node *prev_node = NULL;

    while (current_node->next != NULL) {
        single_list_node *temp = current_node->next;
        current_node->next = prev_node;
        prev_node = current_node;
        current_node = temp;
    }
    current_node->next = prev_node;

    head->next =current_node;
}


static single_list_node *do_reverse_rec(single_linked_list *node) {
    if (node == NULL||node->next == NULL) {
        return node;
    }
    single_list_node *new_head = do_reverse_rec(node->next);
    (node->next)->next = node;
    node->next = NULL;
    return new_head;
}

void single_list_reverse_rec(single_linked_list *head) {
    head->next = do_reverse_rec(head->next);
}


unsigned int single_list_get_length(single_linked_list *head) {
    unsigned int len = 0;
    while (head->next != NULL) {
        head = head->next;
        len++;
    }
    return len;
}


inline void single_list_delete(single_linked_list *head, int index) {
    if (index >= single_list_get_length(head)) {
        printf("Index is out of the linked list.\n");
        return;
    }
    for (; index > 0; index--) {
        head = head->next;
    }
    single_list_node *temp = head->next;
    if (temp->next != NULL) {
        head->next = temp->next;
    } else head->next = NULL;

    free(temp);
    temp = NULL; // Avoid wild pointer.
}

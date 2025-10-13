#include <stdlib.h>
#include <stdio.h>
#include "../../../include/linearlist/linkedlist/singly_linked_list.h"

singly_list_node *singly_list_create(SINGLY_LIST_ELEM_TYPE data) {
    singly_list_node *temp = (singly_list_node *) malloc(sizeof(singly_list_node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}


singly_linked_list *singly_list_init() {
    return singly_list_create(0);
}

inline singly_list_node *singly_list_get_tail(singly_linked_list *head) {
    while (head->next != NULL) {
        head = head->next;
    }
    return head;
}

inline singly_list_node *singly_list_append(singly_linked_list *head, SINGLY_LIST_ELEM_TYPE data) {
    singly_list_node *new_node = singly_list_create(data);
    singly_list_node *last_node = singly_list_get_tail(head);
    last_node->next = new_node;
    return new_node;
}


void singly_list_print(singly_linked_list *head) {
    if (head->next != NULL) {
        singly_list_node *current = head->next;
        printf("|%p|%d| -> ", head->next, current->data);
        singly_list_print(head->next);
    } else {
        printf("NULL\n");
    }
}


inline void singly_list_free(singly_linked_list *head) {
    // Recursive free next ( if head -> next is NULL, stopping recursive call )
    if (head->next != NULL) {
        singly_list_free(head->next);
    }
    free(head);
    printf("free:%p\n", head);
}


inline void singly_list_insert(singly_linked_list *head, int index, singly_list_node *new_node) {
    if (index < 0) {
        printf("Index must be > 0.");
        return;
    }
    for (; index > 0; index--) {
        head = head->next;
    }
    singly_list_node *temp = head->next;
    head->next = new_node;
    new_node->next = temp;
}

inline void singly_list_reverse(singly_linked_list *head) {
    if (head->next == NULL) {
        printf("Linked list must has one node at least");
        return;
    }
    singly_list_node *current_node = head->next;
    singly_list_node *prev_node = NULL;

    while (current_node->next != NULL) {
        singly_list_node *temp = current_node->next;
        current_node->next = prev_node;
        prev_node = current_node;
        current_node = temp;
    }
    current_node->next = prev_node;

    head->next =current_node;
}


static singly_list_node *do_reverse_rec(singly_linked_list *node) {
    if (node == NULL||node->next == NULL) {
        return node;
    }
    singly_list_node *new_head = do_reverse_rec(node->next);
    (node->next)->next = node;
    node->next = NULL;
    return new_head;
}

void singly_list_reverse_rec(singly_linked_list *head) {
    head->next = do_reverse_rec(head->next);
}


unsigned int singly_list_get_length(singly_linked_list *head) {
    unsigned int len = 0;
    while (head->next != NULL) {
        head = head->next;
        len++;
    }
    return len;
}


inline void singly_list_delete(singly_linked_list *head, int index) {
    if (index >= singly_list_get_length(head)) {
        printf("Index is out of the linked list.\n");
        return;
    }
    for (; index > 0; index--) {
        head = head->next;
    }
    singly_list_node *temp = head->next;
    if (temp->next != NULL) {
        head->next = temp->next;
    } else head->next = NULL;

    free(temp);
    temp = NULL; // Avoid wild pointer.
}

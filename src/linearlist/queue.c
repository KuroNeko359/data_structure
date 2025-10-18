//
// Created by KuroNeko359 on 2025/10/17.
//

#include "linearlist/queue.h"

#include <stdio.h>
#include <stdlib.h>

queue_node *queue_create_node(QUEUE_ELEM_TYPE data) {
    queue_node *new_node = malloc(sizeof(queue_node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

queue *queue_init() {
    queue *queue = malloc(sizeof(queue));
    queue->head = queue_create_node(0);
    queue->end = queue_create_node(0);
    queue->len = 0;
    return queue;
}


bool queue_is_empty(queue *queue) {
    return (queue->head->next == NULL) || (queue->end->next == NULL);
}

bool queue_push(queue *queue,QUEUE_ELEM_TYPE data) {
    queue_node *new_node = queue_create_node(data);
    if (queue->head->next == NULL) {
        queue->head->next = new_node;
    } else {
        queue->end->next->next = new_node;
    }
    queue->end->next = new_node;
    queue->len++;
    return true;
}

QUEUE_ELEM_TYPE queue_pop(queue *queue) {
    if (queue_is_empty(queue)) {
        exit(-1);
    }
    queue_node *head = queue->head->next;
    QUEUE_ELEM_TYPE head_data = head->data;
    queue->head->next = head->next;
    free(head);
    queue->len--;
    return head_data;
}

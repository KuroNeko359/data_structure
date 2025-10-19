//
// Created by KuroNeko359 on 2025/10/17.
//

#ifndef DATA_STRUCTURE_QUEUE_H

#define DATA_STRUCTURE_QUEUE_H

#define QUEUE_ELEM_TYPE int

#include "types.h"

typedef struct queue_node {
    QUEUE_ELEM_TYPE data;
    struct queue_node *next;
} queue_node;

typedef struct queue {
    queue_node *head;
    queue_node *end;
    int len;
} queue;

queue *queue_init();

bool queue_push(queue *queue,QUEUE_ELEM_TYPE data);

bool queue_is_empty(queue *queue);

QUEUE_ELEM_TYPE queue_pop(queue *queue);


#endif //DATA_STRUCTURE_QUEUE_H

//
// Created by KuroNeko359 on 2025/10/16.
//

#ifndef DATA_STRUCTURE_STATIC_QUEUE_H
#define DATA_STRUCTURE_STATIC_QUEUE_H

#define STATIC_QUEUE_ELEM_TYPE int
#define STATIC_QUEUE_SIZE 5
#include <stdlib.h>
#include "types.h"

typedef struct static_queue {
    int end;
    int head;
    STATIC_QUEUE_ELEM_TYPE *data;
} static_queue;

static_queue *static_queue_init();

bool static_queue_push(static_queue *queue,STATIC_QUEUE_ELEM_TYPE data);

STATIC_QUEUE_ELEM_TYPE static_queue_pop(static_queue *queue);

STATIC_QUEUE_ELEM_TYPE static_queue_get(static_queue *queue);

bool static_queue_is_empty(static_queue *queue);

int static_queue_get_length(static_queue *queue);


#endif //DATA_STRUCTURE_STATIC_QUEUE_H

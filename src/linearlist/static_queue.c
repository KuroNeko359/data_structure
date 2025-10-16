//
// Created by KuroNeko359 on 2025/10/16.
//
#include "linearlist/static_queue.h"
#include <stdio.h>

static_queue *static_queue_init() {
    static_queue *queue_addr = malloc(sizeof(static_queue));
    STATIC_QUEUE_ELEM_TYPE *arr = malloc(
        STATIC_QUEUE_SIZE * sizeof(STATIC_QUEUE_ELEM_TYPE));
    queue_addr->end = -1;
    queue_addr->head = 0;
    queue_addr->data = arr;
    return queue_addr;
}


STATIC_QUEUE_ELEM_TYPE static_queue_get(static_queue *queue) {
    return queue->data[0];
}

STATIC_QUEUE_ELEM_TYPE static_queue_pop(static_queue *queue) {
    STATIC_QUEUE_ELEM_TYPE head = queue->data[queue->head];
    queue->data[queue->head] = 0;
    queue->head++;
    return head;
}

bool static_queue_push(static_queue *queue,STATIC_QUEUE_ELEM_TYPE data) {
    queue->end++;
    queue->end = queue->end % STATIC_QUEUE_SIZE;
    queue->data[queue->end] = data;
    printf("END:%d\n", queue->end);
    return true;
}

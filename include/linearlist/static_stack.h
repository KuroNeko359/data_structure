//
// Created by KuroNeko359 on 2025/10/13.
//

#ifndef DATA_STRUCTURE_STATIC_STACK_H
#define DATA_STRUCTURE_STATIC_STACK_H
#define STATIC_STACK_ELEM_TYPE int
#include "types.h"

typedef struct {
    int size;
    int top;
    STATIC_STACK_ELEM_TYPE *data;
} static_stack;

static_stack *static_stack_init(int length);

bool static_stack_push(static_stack *static_stack, STATIC_STACK_ELEM_TYPE data);

STATIC_STACK_ELEM_TYPE static_stack_get_top(static_stack *static_stack);

STATIC_STACK_ELEM_TYPE static_stack_pop(static_stack *stack);

bool static_stack_is_empty(static_stack *static_stack);



#endif //DATA_STRUCTURE_STACK_H

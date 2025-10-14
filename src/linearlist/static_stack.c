//
// Created by KuroNeko359 on 2025/10/13.
//
#include "linearlist/static_stack.h"

#include "stdlib.h"
#include <stdio.h>

#include "log.h"

static_stack *static_stack_init(int length) {
    static_stack *stack = malloc(sizeof(static_stack));
    STATIC_STACK_ELEM_TYPE *arr =
            malloc(length * sizeof(STATIC_STACK_ELEM_TYPE));
    stack->data = arr;
    stack->size = length;
    stack->top = -1;
    return stack;
}

bool static_stack_push(static_stack *stack,STATIC_STACK_ELEM_TYPE data) {
    if (stack->top >= stack->size - 1) {
        return false;
    }
    stack->top++;
    stack->data[stack->top] = data;
    return true;
}

STATIC_STACK_ELEM_TYPE static_stack_get_top(static_stack *stack) {
    if (static_stack_is_empty(stack)) {
        ERROR_PRINT("Empty stack.");
        exit(-1);
    }
    return stack->data[stack->top];
}

STATIC_STACK_ELEM_TYPE static_stack_pop(static_stack *stack) {
    STATIC_STACK_ELEM_TYPE top = static_stack_get_top(stack);
    stack->top--;
    return top;
}

bool static_stack_is_empty(static_stack *stack) {
    return (bool) (stack->top < 0);
}



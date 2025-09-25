//
// Created by KuroNeko359 on 2025/9/24.
//

#include "linearlist/seq_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "log.h"

void seq_print(seq_list *seq) {
    int i;
    for (i = 0; i < seq->len; i++) {
        printf("%d ", *(seq->elem + i));
    }
    printf("\n");
}

seq_list *seq_list_init(seq_list_type *arr, unsigned int arr_size) {
    seq_list *seq = malloc(sizeof(seq_list));
    seq->elem = (seq_list_type *) malloc(arr_size * sizeof(seq_list_type));
    memcpy(seq->elem, arr, arr_size * sizeof(seq_list_type));
    seq->len = arr_size;
    seq->size = arr_size;
    return seq;
}

void seq_realloc(seq_list *seq) {
    void * new_pointer = realloc(seq->elem,seq->size * 2);
    seq->elem = new_pointer;
    seq->size = seq->size * 2;
    DEBUG_PRINT("Seq has reallocated, now seq->size is %d.",seq->size);
}

void seq_add_elem(seq_list *seq,seq_list_type elem) {
    if (seq->len >= seq->size) {
        seq_realloc(seq);
    }

    seq->elem[seq->len] = elem;
    seq->len++;

    if (ENABLE_DEBUG == 1) {
        DEBUG_PRINT("%d elems added, current len: %d size: %d.",elem,seq->len,seq->size);
    }
}

void seq_append_elems(seq_list *seq,seq_list_type *arr,unsigned int arr_size) {
    if (seq->len + arr_size > seq->size) {
        // TODO Fix the case that seq->len + arr_size > 2 * seq->size
        seq_realloc(seq);
    }
    seq_list_type *seq_end = (seq->elem + seq->len);
    memcpy(seq_end,arr,arr_size * sizeof(seq_list_type));
    seq->len += arr_size;
}
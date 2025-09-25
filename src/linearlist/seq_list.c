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
    void *new_pointer = realloc(seq->elem, seq->size * 2);
    seq->elem = new_pointer;
    seq->size = seq->size * 2;
    DEBUG_PRINT("Seq has reallocated, now seq->size is %d.", seq->size);
}

void seq_add_elem(seq_list *seq,seq_list_type elem) {
    if (seq->len >= seq->size) {
        seq_realloc(seq);
    }

    seq->elem[seq->len] = elem;
    seq->len++;

    if (ENABLE_DEBUG) {
        DEBUG_PRINT("%d elems added, current len: %d size: %d.", elem, seq->len, seq->size);
    }
}

void seq_append_elems(seq_list *seq,seq_list_type *arr, unsigned int arr_size) {
    if (seq->len + arr_size > seq->size) {
        // TODO Fix the case that seq->len + arr_size > 2 * seq->size
        seq_realloc(seq);
    }
    seq_list_type *seq_end = (seq->elem + seq->len);
    memcpy(seq_end, arr, arr_size * sizeof(seq_list_type));
    seq->len += arr_size;
}

void seq_delete_elem(seq_list *seq, int index) {
    memcpy(
        seq->elem + index,
        seq->elem + index + 1,
        (seq->len - (unsigned int)(index + 1)) * sizeof(seq_list_type)
    );
    if (ENABLE_DEBUG) {
        printf("memcpy: from %p to %p, len:%d \n",seq->elem + index + 1,seq->elem + index ,(seq->len - (unsigned int)(index + 1)) );
    }

    seq->len--;
}


void seq_insert_elem(seq_list *seq, int index,seq_list_type elem) {
    if (seq->len + 1 >= seq->size) {
        seq_realloc(seq);
    }
    memcpy(
        seq->elem + index + 1,
        seq->elem + index,
        (seq->len - (unsigned int)index) * sizeof(seq_list_type)
    );
    if (ENABLE_DEBUG) {
        printf("memcpy: from %p to %p, len:%d \n",seq->elem + index,seq->elem + index + 1,(seq->len - (unsigned int)index) );
    }
    *(seq->elem + index) = elem;

    seq->len++;
}

seq_list_type seq_get_elem(seq_list *seq, int index) {
    if (index < seq->size) {
        return *(seq->elem + index);
    }
    printf("Index %d is out of bounds.",index);
    exit(1);
}

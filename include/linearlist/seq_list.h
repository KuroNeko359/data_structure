//
// Created by KuroNeko359 on 2025/9/24.
//

#ifndef CSAPP_SEQ_LIST_H
#define CSAPP_SEQ_LIST_H

#define seq_list_type int
#define seq_list_size 10
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    seq_list_type *elem;
    unsigned int len;
    unsigned int size;
} seq_list;

seq_list *seq_list_init(seq_list_type *arr, unsigned int arr_size);

void seq_print(seq_list *seq);

void seq_append_elems(seq_list *seq,seq_list_type *arr,unsigned int arr_size);

void seq_add_elem(seq_list *seq,seq_list_type elem);

void seq_realloc(seq_list *seq);

void test();




#endif //CSAPP_SEQ_LIST_H

//
// Created by KuroNeko359 on 2025/10/19.
//

#ifndef DATA_STRUCTURE_AVL_TREE_H
#define DATA_STRUCTURE_AVL_TREE_H
#include <stdlib.h>
#include "types.h"

typedef int avl_elem_type;

typedef struct avl_node {
    struct avl_node *left, *right;
    avl_elem_type data;
    int height;
} avl_node, avl_root;

avl_node *avl_create_node(avl_elem_type data);

bool *avl_insert(avl_root *root,avl_elem_type data);

#endif //DATA_STRUCTURE_AVL_TREE_H

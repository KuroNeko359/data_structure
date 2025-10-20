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

avl_node *avl_insert(avl_root *root, avl_elem_type data);

avl_root *avl_init(avl_elem_type data);

int avl_node_get_height(avl_node *node);

avl_node *avl_search(avl_root *root,avl_elem_type target,int *counter);

avl_node *avl_delete_node(avl_root *root, avl_elem_type target);
#endif //DATA_STRUCTURE_AVL_TREE_H

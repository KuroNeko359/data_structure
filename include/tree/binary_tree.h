//
// Created by KuroNeko359 on 2025/10/17.
//

#ifndef DATA_STRUCTURE_BINARY_TREE_H
#define DATA_STRUCTURE_BINARY_TREE_H

#define BINARY_TREE_ELEM_TYPE int

#include "../types.h"

typedef struct binary_tree_node {
    struct binary_tree_node *right, *left;
    BINARY_TREE_ELEM_TYPE data;
} binary_tree_node, binary_tree;

typedef enum append_direction {
    RIGHT_CHILD,
    LEFT_CHILD,
} append_direction;

binary_tree_node *binary_tree_node_create(BINARY_TREE_ELEM_TYPE data);

binary_tree *binary_tree_init(BINARY_TREE_ELEM_TYPE data);

bool binary_tree_append_node(binary_tree_node *node,
                             BINARY_TREE_ELEM_TYPE data,
                             append_direction direction);

#endif //DATA_STRUCTURE_BINARY_TREE_H

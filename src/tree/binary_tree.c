//
// Created by KuroNeko359 on 2025/10/17.
//

#include "binary_tree.h"

#include <stdlib.h>

binary_tree_node *binary_tree_node_create(BINARY_TREE_ELEM_TYPE data) {
    binary_tree_node *new_node = malloc(sizeof(binary_tree_node));
    new_node->right = NULL;
    new_node->left = NULL;
    new_node->data = data;
    return new_node;
}

binary_tree *binary_tree_init(BINARY_TREE_ELEM_TYPE data) {
    binary_tree_node *binary_tree = binary_tree_node_create(data);
    return binary_tree;
}

bool binary_tree_append_node(binary_tree_node *node,
                             BINARY_TREE_ELEM_TYPE data,
                             append_direction direction) {
    binary_tree_node *new_node = binary_tree_node_create(data);
    if (direction == RIGHT_CHILD) {
        node->right = new_node;
        return true;
    }
    if (direction == LEFT_CHILD) {
        node->left = new_node;
        return true;
    }
    return false;
}




//
// Created by KuroNeko359 on 2025/10/19.
//
#include "tree/avl_tree.h"

static int max(int a, int b) {
    return (a > b) ? a : b;
}

static int avl_node_get_height(avl_node *node) {
    return (node == NULL) ? 0 : node->height;
}

static int update_height(avl_node *node) {
    return max(avl_node_get_height(node->right),
               avl_node_get_height(node->left)) + 1;
}


static int get_balance_factor(avl_node *node) {
    return (node == NULL)
               ? 0
               : avl_node_get_height(node->left) - avl_node_get_height(
                     node->right);
}


avl_node *avl_create_node(avl_elem_type data) {
    avl_node *new_node = malloc(sizeof(avl_node));
    new_node->height = 0;
    new_node->data = data;
    new_node->right = NULL;
    new_node->left = NULL;
    return new_node;
}

avl_root *avl_init(avl_elem_type data) {
    return avl_create_node(data);
}

bool *avl_insert(avl_root *root, avl_elem_type data) {
    avl_node *new_node = avl_create_node(data);
    // TODO unfinished
}

avl_node *left_rotate(avl_node *node) {
    if (node == NULL) return NULL;
    avl_node *new_node = node->right;
    node->right = new_node->left;
    new_node->left = node;
    // Update height
    node->height = update_height(node);
    new_node->height = update_height(new_node);
    return new_node;
}

avl_node *right_rotate(avl_node *node) {
    if (node == NULL) return NULL;
    avl_node *new_node = node->left;
    node->left = new_node->right;
    new_node->right = node;
    // Update height
    node->height = update_height(node);
    new_node->height = update_height(new_node);
    return new_node;
}
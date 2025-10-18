//
// Created by KuroNeko359 on 2025/10/17.
//

#ifndef CSAPP_BINARY_SEARCH_TREE_H
#define CSAPP_BINARY_SEARCH_TREE_H
#define BST_ELEM_TYPE int
#include "types.h"

typedef struct bst_node {
    struct bst_node *left,*right;
    BST_ELEM_TYPE data;
} bst_node,bst_root;

bst_root *bst_init(BST_ELEM_TYPE data);

bst_node *bst_insert_rec(bst_node *current_node,BST_ELEM_TYPE data);

bool bst_search_rec(bst_node *current_node,BST_ELEM_TYPE data);

BST_ELEM_TYPE bst_get_max(bst_node *root);

BST_ELEM_TYPE bst_get_min(bst_node *root);

int bst_get_height_rec(bst_node *node);

void bst_print_preorder_rec(bst_root *root);

void bst_print_inorder_rec(bst_root *root);

void bst_print_postorder_rec(bst_root *root);

void bst_print_level_order(bst_root *root);

bool is_bst(bst_root *root);

#endif //CSAPP_BINARY_SEARCH_TREE_H

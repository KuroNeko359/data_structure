//
// Created by KuroNeko359 on 2025/10/19.
//

#ifndef DATA_STRUCTURE_RBTREE_H
#define DATA_STRUCTURE_RBTREE_H

typedef int rbtree_key;

typedef enum node_color {
    BLACK,
    RED,
} node_color;

typedef struct rbtree_node {
    struct rbtree_node *left, *right, *parent;
    rbtree_key key;
    void *value;
    node_color color;
} rbtree_node, rbtree_root;

typedef struct rbtree {
    rbtree_node *root; // root node
    rbtree_node *nil; // leaf node
} rbtree;

rbtree_node *rbtree_left_rotate(rbtree *root, rbtree_node *node);

rbtree_node *rbtree_right_rotate(rbtree *root, rbtree_node *node);

rbtree *rbtree_init();

rbtree_node *rbtree_create_node(rbtree *tree,rbtree_key key);

rbtree_node *rbtree_delete_node(rbtree *tree, rbtree_key target);

void rbtree_insert_node(rbtree *tree, rbtree_key data);

rbtree_node *rbtree_search(rbtree *tree, rbtree_key target, int *counter);

void inorder_print(rbtree *tree, rbtree_node *node);

#endif //DATA_STRUCTURE_RBTREE_H

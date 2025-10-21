//
// Created by KuroNeko359 on 2025/10/19.
//

#ifndef DATA_STRUCTURE_RBTREE_H
#define DATA_STRUCTURE_RBTREE_H

typedef int rbtree_type;

typedef enum node_color {
    BLACK,
    RED,
} node_color;

typedef struct rbtree_node {
    struct rbtree_node *left, *right, *parent;
    rbtree_type data;
    node_color color;
} rbtree_node,rbtree_root;

rbtree_node rbtree_left_rotate(rbtree_node *node);

rbtree_node rbtree_right_rotate(rbtree_node *node);

rbtree_node rbtree_init(rbtree_type *data);

rbtree_node rbtree_create_node(rbtree_type *data);

rbtree_node rbtree_delete_node(rbtree_node *node, rbtree_type target);

rbtree_node rbtree_insert_node(rbtree_node *node, rbtree_type data);


#endif //DATA_STRUCTURE_RBTREE_H
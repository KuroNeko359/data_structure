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

/**
 * @brief Create a node of AVL tree with given data.
 *
 * This function allocates memory for a new node, initializes its fields and
 * sets its initial height to 1.
 * The child pointer will set to NULL.
 *
 * @param data The data elem to store in the new node.
 * @return The pointer of the node newly created.
 */
avl_node *avl_create_node(avl_elem_type data);

/**
 * @brief Inserts a new data element into the AVL tree.
 *
 * This function performs a standard binary search tree insertion and then
 * rebalances the tree using rotations if the AVL property is violated.
 *
 * @param root A pointer to the root of the AVL tree (or a subtree).
 * @param data The data element to insert.
 * @return A pointer to the new root of the (potentially rebalanced) tree.
 */
avl_node *avl_insert(avl_root *root, avl_elem_type data);

avl_root *avl_init(avl_elem_type data);

int avl_node_get_height(avl_node *node);

avl_node *avl_search(avl_root *root, avl_elem_type target, int *counter);

avl_node *avl_delete_node(avl_root *root, avl_elem_type target);
#endif //DATA_STRUCTURE_AVL_TREE_H

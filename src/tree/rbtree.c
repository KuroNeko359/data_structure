//
// Created by KuroNeko359 on 2025/10/19.
//
#include "tree/rbtree.h"

#include <stdio.h>
#include <stdlib.h>

rbtree_node *rbtree_left_rotate(rbtree *tree, rbtree_node *root) {
    // Take right subtree of root as new root.
    rbtree_node *new_root = root->right;
    // Connect parent node of root with new root.
    if (root->parent == tree->nil) {
        tree->root = new_root;
    } else if (root == root->parent->left) {
        root->parent->left = new_root;
    } else if (root == root->parent->right) {
        root->parent->right = new_root;
    }
    // Take left node of new root if it is existed.
    rbtree_node *left_child = new_root->left;
    // Connect root with new_root_left
    root->right = left_child;
    if (left_child != NULL)
        left_child->parent = root;
    // connect new root with old root
    new_root->left = root;
    new_root->parent = root->parent;
    root->parent = new_root;
    return new_root;
}

rbtree_node *rbtree_right_rotate(rbtree *tree, rbtree_node *root) {
    rbtree_node *new_root = root->left;
    if (root->parent == tree->nil) {
        tree->root = new_root;
    } else if (root == root->parent->left) {
        root->parent->left = new_root;
    } else if (root == root->parent->right) {
        root->parent->right = new_root;
    }

    rbtree_node *right_child = new_root->right;
    root->left = right_child;
    right_child->parent = root;

    new_root->right = root;
    new_root->parent = root->parent;
    root->parent = new_root;
    return new_root;
}

rbtree *rbtree_init() {
    rbtree *new_tree = malloc(sizeof(rbtree));
    new_tree->nil = malloc(sizeof(rbtree_node));
    new_tree->nil->color = BLACK;
    new_tree->root = new_tree->nil;
    return new_tree;
}

rbtree_node *rbtree_create_node(rbtree *tree, rbtree_key key) {
    rbtree_node *new_node = malloc(sizeof(rbtree_node));
    new_node->right = tree->nil;
    new_node->left = tree->nil;
    new_node->parent = NULL;
    new_node->key = key;
    new_node->value = NULL;
    new_node->color = RED;
    return new_node;
}

rbtree_node *rbtree_delete_node(rbtree_node *root, rbtree_key target);

void inorder_print(rbtree *tree, rbtree_node *node) {
    if (node == tree->nil) return;
    inorder_print(tree, node->left);
    printf("key:%d color:%d\n", node->key, node->color);
    inorder_print(tree, node->right);
}

static void rbtree_fix_imbalance_after_insertion(
    rbtree *tree, rbtree_node *new_node) {
    while (new_node->parent->color == RED) {
        rbtree_node *parent = new_node->parent;
        rbtree_node *grandparent = new_node->parent->parent;
        if (new_node->parent == new_node->parent->parent->left) {
            // Get y of current node.
            rbtree_node *y_node = grandparent->right;
            if (y_node->color == BLACK) {
                // LXb
                // case 3 LRb
                // Convert to LLb
                printf("// LXb");
                if (new_node == parent->right) {
                    new_node = parent;
                    rbtree_left_rotate(tree, new_node);
                }
                // case 4 LLb
                grandparent->color = RED;
                parent->color = BLACK;
                rbtree_right_rotate(tree, grandparent);
            } else if (y_node->color == RED) {
                // LXr
                printf("// LXr");
                y_node->color = BLACK;
                parent->color = BLACK;
                grandparent->color = RED;
                new_node = grandparent;
            }
        } else if (parent == grandparent->right) {
            // Get y of current node.
            rbtree_node *y_node = grandparent->left;
            if (y_node->color == RED) {
                // RXr
                printf("// RXr");
                y_node->color = BLACK;
                parent->color = BLACK;
                grandparent->color = RED;
                new_node = grandparent;
            } else if (y_node->color == BLACK) {
                // RXb
                // case 3 RLb
                // Convert to RRb
                printf("// RXb");
                if (new_node == parent->left) {
                    new_node = parent;
                    rbtree_right_rotate(tree, new_node);
                }
                // case 4 LLb
                grandparent->color = RED;
                parent->color = BLACK;
                rbtree_left_rotate(tree, grandparent);
            }
        }
    }
    tree->root->color = BLACK;
}

static void rbtree_fix_imbalance_after_deletion();

void rbtree_insert_node(rbtree *tree, rbtree_key data) {
    rbtree_node *root = tree->root;
    rbtree_node *nil = tree->nil;
    rbtree_node *parent = nil;
    rbtree_node *new_node = rbtree_create_node(tree, data);

    // Find the parent node of new node.
    while (root != nil) {
        parent = root;
        if (root->key < new_node->key) {
            root = root->right;
        } else if (root->key > new_node->key) {
            root = root->left;
        } else {
            return;
        }
    }

    new_node->parent = parent;

    if (parent == nil) {
        tree->root = new_node;
    } else if (parent->key < new_node->key) {
        parent->right = new_node;
    } else if (parent->key > new_node->key) {
        parent->left = new_node;
    }
    // Verify whether this tree is still a rbtree.
    rbtree_fix_imbalance_after_insertion(tree, new_node);
}

rbtree_node *rbtree_search(rbtree_node *root, rbtree_key target, int *counter);

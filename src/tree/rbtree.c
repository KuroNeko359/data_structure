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

static rbtree_node *rbtree_get_min_node(rbtree *tree, rbtree_node *root) {
    rbtree_node *nil = tree->nil;
    while (root != nil) {
        root = root->left;
    }
    return root;
}

static rbtree_node *get_successor_node(rbtree *tree, rbtree_node *root) {
    rbtree_node *successor;
    rbtree_node *nil = tree->nil;
    if (root->right != nil) {
        successor = rbtree_get_min_node(tree, root->right);
    } else {
        successor = nil;
    }
    return successor;
}

static rbtree_node *get_sibling_node(rbtree *tree, rbtree_node *root) {
    rbtree_node *nil = tree->nil;
    rbtree_node *parent = root->parent;
    if (parent->left == root) {
        return parent->right;
    }
    if (parent->right == root) {
        return parent->left;
    }
    return nil;
}

static int get_unbalance_case(rbtree *tree, rbtree_node *root);

// TODO Unfinished It is temporary put on hold due to ability issues.
rbtree_node *rbtree_delete_node(rbtree *tree, rbtree_key target) {
    rbtree_node *root = tree->root;
    rbtree_node *nil = tree->nil;

    // Locate node that will be deleted.
    while (root != nil) {
        if (root->key == target) {
            break;
        }
        if (root->key < target) {
            root = root->right;
        } else if (root->key > target) {
            root = root->left;
        }
    }


    if (root->color == RED) {
        // The color of node to delete is red.
        if (root->left == nil && root->right == nil) {
            root = nil;
            return root;
        }
        if (root->left != nil || root->right != nil) {
            // Two subtree.
            // Find the successor of node, and replace this node with it.
            rbtree_node *successor = get_successor_node(tree, root);
            root->key = successor->key;
            successor->parent->left = nil;
            free(successor);
        }
    } else if (root->color == BLACK) {
        // The color of node to delete is black.
    }


    return root;
}

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
                y_node->color = BLACK;
                parent->color = BLACK;
                grandparent->color = RED;
                new_node = grandparent;
            } else if (y_node->color == BLACK) {
                // RXb
                // case 3 RLb
                // Convert to RRb
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

// TODO Unfinished It is temporary put on hold due to ability issues.
static void rbtree_fix_imbalance_after_deletion(
    rbtree *tree, rbtree_node *deleted_node) {
    rbtree_node *nil = tree->nil;
    rbtree_node *sibling = get_sibling_node(tree, deleted_node);
    rbtree_node *parent = deleted_node->parent;
    /**
     * case 1 - node's sibling is black.
     * And it has one or two red child or two black child.
     * In this case, sibling node can't be nil.
     */
    if (sibling->color == BLACK) {
        if (sibling->left == nil && sibling->right == nil) {
            sibling->color = RED;
        }
        if (deleted_node->parent->left == sibling) {
            // case LX
            if (sibling->left == nil && sibling->right != nil &&
                sibling->right->color == RED) {
                // case LR
                sibling->right->color = parent->color;
                rbtree_left_rotate(tree, sibling);
                rbtree_right_rotate(tree, parent);
            } else if (sibling->left != nil &&
                       sibling->left->color == RED) {
                // case LL
                sibling->left->color = sibling->color;
                sibling->color = parent->color;
                parent->color = BLACK;
                rbtree_right_rotate(tree, parent);
            } else if (sibling->left != nil &&
                       sibling->right != nil &&
                       sibling->left->color == BLACK &&
                       sibling->right->color == BLACK) {
            }
        } else if (deleted_node->parent->right == sibling) {
            // case RX
            if (sibling->right == nil &&
                sibling->left != nil &&
                sibling->left->color == RED) {
                // case RL
                sibling->left->color = parent->color;
                rbtree_right_rotate(tree, sibling);
                rbtree_left_rotate(tree, parent);
            } else if (sibling->right != nil &&
                       sibling->right->color == RED) {
                // case RR
                sibling->right->color = sibling->color;
                sibling->color = parent->color;
                parent->color = BLACK;
                rbtree_left_rotate(tree, parent);
            } else if (sibling->left != nil &&
                       sibling->right != nil &&
                       sibling->left->color == BLACK &&
                       sibling->right->color == BLACK) {
            }
        }
    } else if (sibling->color == RED) {
    }
}

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

rbtree_node *rbtree_search(rbtree *tree, rbtree_key target, int *counter) {
    rbtree_node *root = tree->root;
    rbtree_node *nil = tree->nil;
    while (root != nil) {
        (*counter)++;
        if (root->key < target) {
            root = root->right;
        } else if (root->key > target) {
            root = root->left;
        } else if (root->key == target) {
            return root;
        }
    }
    return nil;
}

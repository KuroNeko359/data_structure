//
// Created by KuroNeko359 on 2025/10/19.
//
#include "tree/avl_tree.h"

#include <stdio.h>

static int max(int a, int b) {
    return (a > b) ? a : b;
}

int avl_node_get_height(avl_node *node) {
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
    new_node->height = 1;
    new_node->data = data;
    new_node->right = NULL;
    new_node->left = NULL;
    return new_node;
}

avl_root *avl_init(avl_elem_type data) {
    return avl_create_node(data);
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

avl_node *avl_insert(avl_root *root, avl_elem_type data) {
    if (root == NULL) return avl_create_node(data);
    if (root->data > data) {
        root->left = avl_insert(root->left, data);
    } else if (root->data < data) {
        root->right = avl_insert(root->right, data);
    } else {
        root->data = data;
        return root;
    }
    root->height = update_height(root);

    // Verify whether the tree is unbalanced.
    int balance_factor = get_balance_factor(root);
    if (balance_factor > 1 && get_balance_factor(root->left) > 0) {
        // LL
        return right_rotate(root);
    }
    if (balance_factor > 1 && get_balance_factor(root->left) < 0) {
        // LR
        root->left = left_rotate(root->left);
        return right_rotate(root);
    }
    if (balance_factor < -1 && get_balance_factor(root->right) < 0) {
        // RR
        return left_rotate(root);
    }
    if (balance_factor < -1 && get_balance_factor(root->right) > 0) {
        // RL
        root->right = right_rotate(root->right);
        return left_rotate(root);
    }

    return root;
}

avl_node *avl_search(avl_root *root, avl_elem_type target, int *counter) {
    (*counter)++;
    if (root == NULL) return root;
    if (root->data == target) return root;
    if (root->data < target) {
        return avl_search(root->right, target, counter);
    } else if (root->data > target) {
        return avl_search(root->left, target, counter);
    }
    return NULL;
}

avl_node *avl_get_min_node(avl_root *root) {
    if (root == NULL) return NULL;
    avl_node *min = root;
    while (min->left != NULL) {
        min = min->left;
    }
    return min;
}

avl_node *avl_delete_node(avl_root *root, avl_elem_type target) {
    if (root == NULL) return root;
    if (root->data < target) {
        root->right = avl_delete_node(root->right, target);
    } else if (root->data > target) {
        root->left = avl_delete_node(root->left, target);
    } else if (root->data == target) {
        // case 1 one child
        if (root->left == NULL && root->right == NULL) {
            free(root);
            root = NULL;
        }

        // case 2 ont child
        else if (root->left == NULL) {
            avl_node *temp = root;
            root = root->right;
            free(temp);
        } else if (root->right == NULL) {
            avl_node *temp = root;
            root = root->left;
            free(temp);
        } else if (root->left != NULL && root->right != NULL) {
            avl_node *min_node = avl_get_min_node(root->right);
            root->data = min_node->data;
            root->right = avl_delete_node(root->right, min_node->data);
        }
    }

    if (root == NULL) return root;

    // Update height
    root->height = update_height(root);

    // Verify whether the tree is unbalanced.
    int balance_factor = get_balance_factor(root);
    if (balance_factor > 1 && get_balance_factor(root->left) >= 0) {
        // LL
        return right_rotate(root);
    }
    if (balance_factor > 1 && get_balance_factor(root->left) < 0) {
        // LR
        root->left = left_rotate(root->left);
        return right_rotate(root);
    }
    if (balance_factor < -1 && get_balance_factor(root->right) < 0) {
        // RR
        return left_rotate(root);
    }
    if (balance_factor < -1 && get_balance_factor(root->right) > 0) {
        // RL
        root->right = right_rotate(root->right);
        return left_rotate(root);
    }

    return root;
}

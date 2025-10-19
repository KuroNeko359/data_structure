//
// Created by KuroNeko359 on 2025/10/17.
//
#include "../../include/tree/binary_search_tree.h"

#include <stdio.h>
#include <stdlib.h>


int max(int num1, int num2) {
    return (num1 >= num2) ? num1 : num2;
}

bst_node *bst_create_node(BST_ELEM_TYPE data) {
    bst_node *new_node = malloc(sizeof(bst_node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}


bst_root *bst_init(BST_ELEM_TYPE data) {
    bst_node *bst_root = bst_create_node(data);
    return bst_root;
}

bst_node *bst_insert_rec(bst_node *current_node,BST_ELEM_TYPE data) {
    if (current_node == NULL) {
        current_node = bst_create_node(data);
        return current_node;
    }
    if (data <= current_node->data) {
        current_node->left = bst_insert_rec(current_node->left, data);
    } else {
        current_node->right = bst_insert_rec(current_node->right, data);
    }
    return current_node;
}

bool bst_search_rec(bst_node *current_node,BST_ELEM_TYPE data) {
    if (current_node == NULL) return false;
    if (current_node->data == data) return true;
    if (current_node->data < data)
        return bst_search_rec(current_node->right, data);
    if (current_node->data >= data)
        return bst_search_rec(current_node->left, data);
}

BST_ELEM_TYPE bst_get_max(bst_root *root) {
    if (root == NULL) return 0;
    int max = root->data;
    while (root->right != NULL) {
        root = root->right;
        max = root->data;
    }
    return max;
}

BST_ELEM_TYPE bst_get_min(bst_root *root) {
    if (root == NULL) return 0;
    int max = root->data;
    while (root->left != NULL) {
        root = root->left;
        max = root->data;
    }
    return max;
}

int bst_get_height_rec(bst_root *node) {
    if (node == NULL) {
        return -1;
    }
    int result = max(bst_get_height_rec(node->left),
                     bst_get_height_rec(node->right)) + 1;
    return result;
}

void bst_print_preorder_rec(bst_root *root) {
    if (root == NULL)
        return;
    printf("%d\n", root->data);
    bst_print_preorder_rec(root->left);
    bst_print_preorder_rec(root->right);
}

void bst_print_inorder_rec(bst_root *root) {
    if (root == NULL) return;
    bst_print_inorder_rec(root->left);
    printf("%d\n", root->data);
    bst_print_inorder_rec(root->right);
}


void bst_print_postorder_rec(bst_root *root) {
    if (root == NULL) return;
    bst_print_postorder_rec(root->left);
    bst_print_postorder_rec(root->right);
    printf("%d\n", root->data);
}

typedef struct node {
    bst_node *data;
    struct node *next;
} node;

typedef struct queue {
    node *front;
    node *rear;
} queue;


static queue *init_queue() {
    queue *q = (queue *) malloc(sizeof(queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

static int is_empty(queue *q) {
    return (q->front == NULL);
}

static void enqueue(queue *q, bst_node *data) {
    node *new_node = (node *) malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;

    if (is_empty(q)) {
        q->front = new_node;
        q->rear = new_node;
    } else {
        q->rear->next = new_node;
        q->rear = new_node;
    }
}

static bst_node *dequeue(queue *q) {
    if (is_empty(q)) {
        printf("Queue is empty.\n");
        exit(EXIT_FAILURE);
    }

    node *temp = q->front;
    bst_node *data = temp->data;

    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    return data;
}


static bst_node *get_front(queue *q) {
    if (is_empty(q)) {
        printf("Queue is empty.\n");
        exit(EXIT_FAILURE);
    }
    return q->front->data;
}

static void destroy_queue(queue *q) {
    while (!is_empty(q)) {
        dequeue(q);
    }
    free(q);
}


void bst_print_level_order(bst_root *root) {
    if (root == NULL) return;
    queue *queue = init_queue();
    enqueue(queue, root);

    while (!is_empty(queue)) {
        bst_node *current = get_front(queue);
        if (current->left != NULL) enqueue(queue, current->left);
        if (current->right != NULL) enqueue(queue, current->right);
        bst_node *node = dequeue(queue);
        printf("%d\n", node->data);
    }

    destroy_queue(queue);
}

static bool is_bst_rec(bst_node *node, int *prev) {
    if (node == NULL) return true;
    if (!is_bst_rec(node->left, prev)) {
        return false;
    }

    if (*prev < node->data) {
        return true;
    }
    *prev = node->data;

    if (!is_bst_rec(node->right, prev)) {
        return false;
    }
}

static bool has_right_child(bst_node *node) {
    return node->right != NULL;
}

static bool has_left_child(bst_node *node) {
    return node->left != NULL;
}

bst_node *bst_find_parent_node(bst_root *root,
                               BST_ELEM_TYPE target_data) {
    if (root->data == target_data) {
        printf("Have not parent node.");
        return root;
    }
    if (root->right->data == target_data || root->left->data == target_data) {
        return root;
    }
    if (root->data > target_data) {
        bst_find_parent_node(root->left, target_data);
    } else if (root->data < target_data) {
        bst_find_parent_node(root->right, target_data);
    }
}

bool bst_delete_node(bst_root *root, BST_ELEM_TYPE target_data) {
    if (root->data > target_data) {
        bst_search_rec(root->left, target_data);
    } else if (root->data < target_data) {
        bst_search_rec(root->right, target_data);
    } else if (root->data == target_data) {
    }
    if (root->right == NULL && root->left == NULL) {
        //Delete this node(name:root)
    }
    if (root->right != NULL && root->left != NULL) {
        // Fine min node of left subtree
        // Replace value of this node with min node of left subtree
        // Free the min node
    }
    if (root->left != NULL) bst_delete_node(root->left, target_data);
    if (root->right != NULL) bst_delete_node(root->right, target_data);
}

bool is_bst(bst_root *root) {
    int prev = INT32_MIN;
    return is_bst_rec(root, &prev);
}

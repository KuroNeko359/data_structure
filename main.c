#include <string.h>

#include "include/tree/binary_search_tree.h"
#include "include/linearlist/static_stack.h"

#include "log.h"
#include "linearlist/dynamic_stack.h"
#include "linearlist/linkedlist/singly_linked_list.h"
#include "tree/avl_tree.h"
#include "tools/timer.h"

void test_static_stack() {
    static_stack *static_stack = static_stack_init(10);
    static_stack_push(static_stack, 1);
    static_stack_push(static_stack, 2);
    static_stack_push(static_stack, 3);
    static_stack_push(static_stack, 4);

    printf("%d\n", static_stack_pop(static_stack));
    printf("%d\n", static_stack_pop(static_stack));
    printf("%d\n", static_stack_pop(static_stack));
    printf("%d\n", static_stack_pop(static_stack));
    printf("%d\n", static_stack_pop(static_stack));
}

void test_dynamic_stack() {
    dynamic_stack *stack = dynamic_stack_init();
    dynamic_stack_push(stack, 1);
    dynamic_stack_push(stack, 2);
    dynamic_stack_push(stack, 3);
    printf("%d\n", dynamic_stack_pop(stack));
    printf("%d\n", dynamic_stack_pop(stack));
    printf("%d\n", dynamic_stack_pop(stack));

    if (dynamic_stack_is_empty(stack)) {
        printf("stack is empty");
    }
    printf("%d\n", dynamic_stack_pop(stack));
}

void test_reverse_string_using_stack() {
    char *str1 = "Hello!";
    printf("%s\n", str1);
    dynamic_stack *stack = dynamic_stack_init();
    for (int i = 0; i < strlen(str1); i++) {
        dynamic_stack_push(stack, str1[i]);
    }
    char str2[6];
    int str2_index = 0;
    while (!dynamic_stack_is_empty(stack)) {
        str2[str2_index] = dynamic_stack_pop(stack);
        str2_index++;
    }
    printf("%s\n", str2);
}

#include "linearlist/static_queue.h"

void test__static_queue_print(static_queue *queue) {
    for (int i = 0; i < STATIC_QUEUE_SIZE; i++) {
        printf("%d ", queue->data[i]);
    }
    printf("\n");
}


void test_static_queue() {
    static_queue *queue = static_queue_init();
    static_queue_push(queue, 1);
    static_queue_push(queue, 2);
    static_queue_push(queue, 3);
    test__static_queue_print(queue);
    printf("len:%d\n", static_queue_get_length(queue));
    static_queue_pop(queue);
    test__static_queue_print(queue);
    static_queue_push(queue, 4);
    test__static_queue_print(queue);
    static_queue_pop(queue);
    test__static_queue_print(queue);
    static_queue_push(queue, 5);
    test__static_queue_print(queue);
    static_queue_push(queue, 1);
    test__static_queue_print(queue);
    printf("len:%d\n", static_queue_get_length(queue));
    static_queue_pop(queue);
    test__static_queue_print(queue);
    static_queue_pop(queue);
    test__static_queue_print(queue);
    static_queue_pop(queue);
    test__static_queue_print(queue);
    printf("len:%d\n", static_queue_get_length(queue));
    static_queue_pop(queue);
    test__static_queue_print(queue);
    printf("len:%d\n", static_queue_get_length(queue));
    if (static_queue_is_empty(queue)) {
        printf("Queue is empty.");
    }
}

#include "linearlist/queue.h"

void test_queue_print(queue *queue) {
    while (!queue_is_empty(queue)) {
        printf("%d ", queue_pop(queue));
    }
    printf("\n");
}

void test_queue() {
    queue *queue = queue_init();
    queue_push(queue, 1);
    queue_push(queue, 2);
    queue_push(queue, 3);
    queue_pop(queue);
    queue_push(queue, 4);
    queue_push(queue, 5);
    test_queue_print(queue);
}

void test_binary_search_tree() {
    srand((unsigned int) time(NULL));

    bst_root *root = bst_init(100 + rand() % 1000);
    for (int i = 0; i < 10; i++) {
        int num1 = 100 + rand() % 1000;
        bst_insert_rec(root, num1);
    }

    bst_root *root1 = bst_init(10);
    int arr[14] = {5, 15, 3, 7, 13, 17, 1, 4, 6, 8, 11, 14, 16, 18};
    for (int i = 0; i < 14; i++) {
        printf("insert %d\n", arr[i]);
        bst_insert_rec(root1, arr[i]);
    }
    if (bst_search_rec(root, 134)) {
        printf("Found\n");
    } else {
        printf("Not found\n");
    }

    int height = bst_get_height_rec(root);
    printf("length：%d\n", height);
    bst_print_inorder_rec(root1);

    bst_print_level_order(root1);

    printf("min : %d\n", bst_get_min_node(root1)->data);
    printf("max : %d\n", bst_get_max_node(root1)->data);

    bst_delete_node(root1, 15);
    if (is_bst(root1)) {
        printf("is bst\n");
    } else {
        printf("not bst\n");
    }
}

void test_avl_tree() {
    avl_root *avl_root = avl_init(1);
    clock_t t1 = timer_start();
    // Insertion of avl tree
    for (int i = 2; i < 10000000; i++) {
        avl_root = avl_insert(avl_root, i);
    }
    double s1 = timer_end(t1);
    printf("Insertion completed, takes %.4f s.\n", s1);
    printf("tree height %d\n", avl_node_get_height(avl_root));

    // test search
    int counter = 0;
    avl_node *found_node = avl_search(avl_root, 100234, &counter);
    if (found_node != NULL)
        printf("Found %d, counter: %d\n", found_node->data, counter);
    // test delete
    int counter2 = 0;
    avl_root = avl_delete_node(avl_root, 4);
    avl_node *found_node1 = avl_search(avl_root, 4, &counter2);
    if (found_node1 != NULL)
        printf("Found %d, counter: %d\n", found_node1->data, counter2);
    else
        printf("Not found.\n");
}

#include "tree/rbtree.h"

void test_rbtree() {
    rbtree *tree = rbtree_init();
    for (int i = 10; i < 100; i += 10) {
        rbtree_insert_node(tree, i);
    }
    int counter = 0;
    rbtree_node *found = rbtree_search(tree, 80, &counter);
    if (found != tree->nil)
        printf("Found:%d Counter:%d", found->key, counter);
    else printf("Not found");
}

int main(int argc, char *argv[]) {
    test_rbtree();
    return 0;
}

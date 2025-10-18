cmake_minimum_required(VERSION 4.0)
project(csapp C)

set(CMAKE_C_STANDARD 11)

include_directories(include)

set(
        LINKED_LIST_SOURCES
        src/linearlist/linkedlist/singly_linked_list.c
        src/linearlist/linkedlist/doubly_linked_list.c
        src/linearlist/linkedlist/circular_linked_list.c
        src/linearlist/linkedlist/static_linked_list.c
        include/linearlist/linkedlist/list_head.h
)

set(
        LINEAR_LIST_SOURCES
        src/linearlist/array.c
        src/linearlist/seq_list.c
        src/linearlist/static_stack.c
        src/linearlist/dynamic_stack.c
        include/linearlist/static_queue.h
        src/linearlist/static_queue.c
        include/linearlist/queue.h
        src/linearlist/queue.c
)

set(
        TREE_SOURCES
        src/tree/binary_tree.c
        src/tree/binary_search_tree.c
        include/binary_search_tree.h
)

add_executable(csapp main.c
        ${LINEAR_LIST_SOURCES}
        ${LINKED_LIST_SOURCES}
        ${TREE_SOURCES}
)

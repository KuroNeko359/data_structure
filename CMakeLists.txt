cmake_minimum_required(VERSION 4.0)
project(csapp C)

set(CMAKE_C_STANDARD 11)

add_executable(csapp main.c
        linked_list.c
        linked_list.h
        doubly_linked_list.h
        doubly_linked_list.c
)

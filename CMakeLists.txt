cmake_minimum_required(VERSION 4.0)
project(csapp C)

set(CMAKE_C_STANDARD 11)

include_directories(include)

set(
        PROJECT_SOURCES
        src/test.c
        src/linearlist/singly_linked_list.c
        src/linearlist/doubly_linked_list.c
        src/linearlist/array.c
        src/linearlist/seq_list.c
        include/log.h
        include/linearlist/array.h
        include/linearlist/seq_list.h

)

add_executable(csapp main.c
        ${PROJECT_SOURCES}
)

#ifndef UINT_LIST_H
#define UINT_LIST_H

#include <stdlib.h>

typedef struct uint_list_node {
    unsigned char digit;
    struct uint_list_node *next;
} uint_list_node;

typedef struct linked_list {
    size_t size;
    uint_list_node *head;
} uint_list_t;

/**
 * Creates a linked list from digits of the given number, read from right to left.
 */
uint_list_t *uint_to_linked_list(unsigned long long number);

/**
 * Prints the whole list as a single number, from left to right.
 */
void print_uint_list(uint_list_t *list);

/**
 * Frees all the memory associated with this list.
 */
void free_uint_list(uint_list_t *list);

#endif // UINT_LIST_H

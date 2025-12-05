#include "uint_list.h"
#include <stdio.h>

void free_uint_list(uint_list_t *list) {
    uint_list_node *node = list->head;
    while (node) {
        uint_list_node *next_node = node->next;
        free(node);
        node = next_node;
    }
    free(list);
}

uint_list_t *uint_to_linked_list(unsigned long long number) {
    struct linked_list *list = malloc(sizeof(*list));
    if (!list) {
        return NULL;
    }
    list->size = 0;
    uint_list_node **last_node = &list->head;
    while (number || !list->size) {
        uint_list_node *current_node = malloc(sizeof(*list));
        if (!current_node) {
            free_uint_list(list);
            return NULL;
        }
        current_node->next = NULL;
        current_node->digit = number % 10;
        number /= 10;
        *last_node = current_node;
        last_node = &current_node->next;
        ++list->size;
    }
    return list;
}


static void print_helper(uint_list_node *node) {
    if (!node) {
        return;
    }

    print_helper(node->next);
    printf("%hhd", node->digit);
}


void print_uint_list(uint_list_t *list) {
    print_helper(list->head);
}

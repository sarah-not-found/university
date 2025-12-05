#ifndef UINT_LIST_UTIL_H
#define UINT_LIST_UTIL_H

/**
 * Returns the number of digits of the given list.
 */
size_t number_of_digits(uint_list_t *list);

/**
 * Computes the sum of all digits.
 */
unsigned long long digit_sum(uint_list_t *list);

/**
 * Returns the highest digit occurring in the list.
 */
unsigned char highest_digit(uint_list_t *list);

/**
 * Adds the numbers represented by the given lists and returns a new list containing the sum.
 */
uint_list_t *add(uint_list_t *list_a, uint_list_t *list_b);


#endif // UINT_LIST_UTIL_H

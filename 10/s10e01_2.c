#include <stdio.h>
#include <stdlib.h>

#define SEGMENTS 7

            //{a, b, c, d, e, f, g}
#define ZERO  {1, 1, 1, 0, 1, 1, 1}
#define ONE   {0, 0, 1, 0, 0, 1, 0}
#define TWO   {1, 0, 1, 1, 1, 0, 1}
#define THREE {1, 0, 1, 1, 0, 1, 1}
#define FOUR  {0, 1, 1, 1, 0, 1, 0}
#define FIVE  {1, 1, 0, 1, 0, 1, 1}
#define SIX   {1, 1, 0, 1, 1, 1, 1}
#define SEVEN {1, 0, 1, 0, 0, 1, 0}
#define EIGHT {1, 1, 1, 1, 1, 1, 1}
#define NINE  {1, 1, 1, 1, 0, 1, 1}

_Bool DIGITS[][SEGMENTS] = {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE};

//Declarations of which functions will exist later
unsigned short *get_digits_reverse(unsigned long number, size_t *len);
_Bool digit_invisible_by(_Bool *digit_a, _Bool *digit_b);
_Bool invisible_by(unsigned long a, unsigned long b);

unsigned short *get_digits_reverse(unsigned long number, size_t *len) {
        if (number == 0) {
            unsigned short *digits = malloc(sizeof(unsigned short));
                if (!digits) return NULL;   // Speicherfehler
                    digits[0] = 0;
                    *len = 1;
                    return digits;
                }
            //Count the digits of our number
            unsigned long temp = number;
            size_t count = 0;
            while (temp > 0) {
                temp /= 10;
                count++;
            }

            unsigned short *digits = malloc(count * sizeof(unsigned short));
            if (!digits) return NULL;

            for (size_t i = 0; i < count; i++) {
                digits[i] = number % 10;
                number /= 10;
            }

            *len = count;
            return digits;
}

_Bool digit_invisible_by(_Bool *digit_a, _Bool *digit_b) {
    //--We get handed two arrays-- if the first one is 1 in all the places b is as well, our number is invisible
    short array_a = DIGITS[*digit_a];
    short array_b = DIGITS[*digit_b];

    for (size_t i; i < SEGMENTS; i++) {
        if ((array_a[i] ^ array_b[i])) {
            if (array_a[i] == 1) return 0;
        }
    }
    //They fully cover each other.
    return 1;
}

void print_digit_line(_Bool digit[], size_t line) {
    switch (line) {
        case 0:
            printf("%s", digit[0] ? " ===" : "    ");
            break;
        case 1:
            printf("%s", digit[1] ? "|   " : "    ");
            printf("%s", digit[2] ? "|" : "");
            break;
        case 2:
            printf("%s", digit[3] ? " ===" : "    ");
            break;
        case 3:
            printf("%s", digit[4] ? "|   " : "    ");
            printf("%s", digit[5] ? "|" : "");
            break;
        case 4:
            printf("%s", digit[6] ? " ===" : "    ");
            break;
        default:
            break;
    }
}

void print_number(unsigned long number) {
    size_t number_len;
    unsigned short *digits_reverse = get_digits_reverse(number, &number_len);

    for (int line = 0; line < 5; line++) {
        for (size_t i = number_len - 1;; i--) {
            unsigned long digit = digits_reverse[i];
            print_digit_line(DIGITS[digit], line);
            printf("\t\t");
            if (i == 0) {
                break;
            }
        }
        printf("\n");
    }
    free(digits_reverse);
}


void test_invisible_by(unsigned long a, unsigned long b) {
    printf("\n\n------------------- TEST -------------------\n\n");
    print_number(a);
    _Bool is_invisible = invisible_by(a, b);
    printf("\n%sinvisible by\n\n", is_invisible ? "" : "not ");
    print_number(b);
}


int main(void) {
    test_invisible_by(4, 9);
    test_invisible_by(123, 788);
    test_invisible_by(123, 761);
    test_invisible_by(123, 169);
    test_invisible_by(123456789, 888888888);
    
    return EXIT_SUCCESS;
}

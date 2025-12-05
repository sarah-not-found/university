/*
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    unsigned char a = 0;
    printf("a: ");
    scanf("%c", &a);
    a = a - 48;
    printf("\n");

    if (a == 0) {
        fprintf(stderr, "ERROR: The side length is zero!\n");
        return EXIT_FAILURE;
    }

    int original_side_length = a;

    //Upper part
    for (int height = 0; height < original_side_length; ++height) {
        for (int outer_space = a - 1; outer_space > 0; --outer_space) {
            printf(" ");
        }
        --a;
        printf("/");
        for (int inner_space = (height * 2); inner_space > 0; --inner_space) {
            printf(" ");
        }
        printf("\\\n");
    }

    //Lower part
    for (int height = 0; height < original_side_length; ++height) {
        for (int outer_space = height; outer_space > 0; --outer_space) {
            printf(" ");
        }
        printf("\\");
        for (int inner_space = ((original_side_length - height) * 2) - 2; inner_space > 0; --inner_space) {
            printf(" ");
        }
        printf("/\n");
    }

    for (int space = side_length; space >= 0; --space) {
        printf(" ");
    }
}
*/

#include <stdio.h>

int main(void) {
    unsigned char a;
    printf("a: ");
    scanf("%hhu", &a);

    if (a == 0) {
        fprintf(stderr, "ERROR: The side length is zero!\n");
        return 1;
    }

    printf("\n");

    for (int i = 1; i <= 2 * a; i++) {
        int leading, inner;
        char left, right;

        if (i <= a) {  // upper half
            leading = a - i;
            inner = 2 * (i - 1);
            left = '/';
            right = '\\';
        } else {       // lower half
            leading = i - a;
            inner = 2 * (2 * a - i);
            left = '\\';
            right = '/';
        }

        printf("%*s", leading, ""); // print spaces
        if (inner == 0)
            printf("%c%c\n", left, right);
        else
            printf("%c%*s%c\n", left, inner, "", right);
    }

    return 0;
}

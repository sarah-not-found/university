#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

bool safe_add(const int *x, const int *y, int *result) {
    //Check if any pointers are NULL
    if (x == NULL || y == NULL || result == NULL) {
        return false;
    }

    //If both inputs are positive, the outcome can't be negative
    if ((*x >= 0) && (*y >= 0)) {
        if ((*x + *y) >= 0) {
            *result = (*x + *y);
            return true;
        } else {
            //Pointer *result remains the same! Nothing is changed
            return false;
        }
    }

    //If both inputs are negative, the outcome can't be positive
    if ((*x < 0) && (*y < 0)) {
        if ((*x + *y) < 0) {
            *result = (*x + *y);
            return true;
        } else {
            //Pointer *result remains the same! Nothing is changed
            return false;
        }
    }

    //Case negative and positive value, will never lead to an overflow -> safe to add
    *result = (*x + *y);
    return true;
}

int main(void) {
    const int x = 2147483647; const int y = 12; int res = 0;
    const int *pt_x = &x;
    const int *pt_y = &y;
    int *pt_res = &res;

    safe_add(pt_x, pt_y, pt_res);

    printf("Pointer x:   %p\n",(void *) pt_x);
    printf("Pointer y:   %p\n",(void *) pt_y);
    printf("Pointer res: %p\n\n",(void *) pt_res);
    
    printf("%d\n", safe_add(pt_x, pt_y, pt_res));
    printf("%d\n", (*pt_x + *pt_y));
}
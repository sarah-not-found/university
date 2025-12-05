#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool safe_add(const int *x, const int *y, int *result) {
    int shift = (sizeof(int) * 8) - 2; //Amount of bits
    int carry = ((*x >> shift) ^ (*y >> shift));
    
    //If the carry cn-1 and cn-2 are 1, we have registered an arithmetic overflow
    //0b11 would work in C23, but not in this C standard (0b11 -> 0x3)

    if (carry == 0x3) {
        return false;
    } else {
        *result = *x + *y;
        return true;
    }
}

int main(void) {
    const int x = 2147483647; const int y = 12; int sum = 0;
    const int *pt_x = &x;
    const int *pt_y = &y;
    int *pt_res = &sum;

    safe_add(pt_x, pt_y, pt_res);

    printf("Pointer x:   %p\n",(void *) pt_x);
    printf("Pointer y:   %p\n",(void *) pt_y);
    printf("Pointer res: %p\n",(void *) pt_res);
    printf("%d\n", sum);
}
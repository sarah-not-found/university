#include <stdio.h>

long sum(const int *start, const int *end) {
    long res = 0;
    while (start < end) {
        res += (long) *(start++); //convert the pointer, that points at an int to a long
    }
    return res;
}

int main(void) {
    int array[] = {1,2,3,4};

    int *start = array;
    int *end = array + (sizeof(array)/sizeof(int)); 

    //Uncomment to show the memory address of the two pointers:
    //printf("%p %p\n", (void*)start, (void*)end);
    printf("%ld\n",sum(start, end));
}

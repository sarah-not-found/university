#include <stdlib.h>

int main(void) {
    int v1 = 1;
    int v2 = 2;

    const int *p1 = &v1;        //memory address of constant v1 stored in p1
    int const *p2 = &v1;        //memory address of v1 stored in constant p2
    int const *p3 = &v1;        //memory address of v1 stored in constant p3 //fix: *const p3
    const int const *p4 = &v1;  //memory address constant of v1 stored in constant p4
    const int const *p5 = &v1;  //memory address constant of v1 stored in constant p5  //fix: *const p5

    p1 = v2;   //The value of v2 is stored in p1 instead of v1 //fix: remove *, point to the value 2
    p2 = v2;   //The value of v2 is stored in p2 instead of v1 //fix: remove *, point to the value 2
    p3 = v2;   //The value of v2 is stored in p3 instead of v1 //fix: remove *, point to the value 2
    p4 = v2;   //The value of v2 is stored in p4 instead of v1 //fix: remove *, point to the value 2
    p5 = v2;   //The value of v2 is stored in p5 instead of v1 //fix: remove *, point to the value 2

    p1 = &v2; 
    p2 = &v2;
    p3 = &v2;
    p4 = &v2;
    p5 = &v2;

    return EXIT_SUCCESS;
}

#include <stdlib.h>

int main(void) {
    int v1 = 1;     //declaring and initializing v1
    int v2 = 2;     //declaring and initializing v2

    const int *p1 = &v1;        //p1 points to a constant integer value
    int const *p2 = &v1;        //p2 points to a constant integer value, the order of const and int does not matter here
    int *const p3 = &v1;        //p3 constantly points at the same address
    const int *p4 = &v1;        //p4 points to a constant integer value //fix: removing one const (double declaration)
    const int *const p5 = &v1;  //p5 constantly points to a constant integer value <neither can be changed>

    //Can't change the values of a constant integer through the pointer
    /*
    *p1 = v2;
    *p2 = v2;
    *p3 = v2;
    *p4 = v2;
    *p5 = v2;
    */

    p1 = &v2;
    p2 = &v2;
    //p3 = &v2;     //a constant pointer can't change the address it points at
    p4 = &v2;
    //p5 = &v2;     //a constant pointer can't change the address it points at

    return EXIT_SUCCESS;
}

#include <stdio.h>
#include <stdlib.h>

struct my_struct1 { //assuming 4 + 8 Bytes
    float x;
    double y;
};

struct my_struct2 { //assuming 4 + 4 + 8 Bytes
    float x;
    float y;
    double z;
};

struct my_struct3 { //assuming 4 + 8 + 4 Bytes
    float x;
    double y;
    float z;
};

/*
The sizes vary significantly from struct to struct
struct3 takes 8 Byte more storage than struct2,
even though they hold the same values

stuct2 also takes exactly as much memory, as struct1,
even though it holds an entire value (float) more
*/ 

int main(void) {
    printf("size of my_struct1: %zu\n", sizeof(struct my_struct1));
    printf("size of my_struct2: %zu\n", sizeof(struct my_struct2));
    printf("size of my_struct3: %zu\n", sizeof(struct my_struct3));
    printf("size of float: %7zu\n", sizeof(float));     //4 Bytes
    printf("size of double: %6zu\n", sizeof(double));   //8 Bytes
    return EXIT_SUCCESS;
}

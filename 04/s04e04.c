#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int height = 0;

    printf("height: ");
    scanf("%d", &height);
    printf("\n");

    for(int i = 1; height >= i; ++i) {
        printf(" ");
        for(int j = 1; j <= i; j++) {
            printf("%d", j);
            if (j < 9) {
                printf(" ");
            }
        }
        printf("\n");
    }
}

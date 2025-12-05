#include <stdio.h>
#include <stdlib.h>


void count_frequency(int frequency[], const int src[], size_t len) {
    for (unsigned i = 0; i < len; i++) {
        unsigned freq = 0;
        for (unsigned j = 0; j < len; j++) {
            if (src[i] == src[j]) {
                freq++;
            }
        }
        frequency[i] = freq;
    }
}

int main(void) {
    const int src[] = {1,2,3,4,5,5};
    size_t length = sizeof(src)/sizeof(int); 
    int frequency[length];

    count_frequency(frequency, src, length);
    return EXIT_SUCCESS;
}

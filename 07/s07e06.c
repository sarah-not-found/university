#include <stddef.h>

int contains_cycle(void *const array[], size_t length) {
    for (size_t start= 0; start < length; start++) {
        //Initializing a pointer array of the same length
        void *visited[length];
        size_t visited_counter = 0;

        //Taking a start point
        void *current = array[start];

        //If we don't hit a dead end...
        while (current != NULL) {
            //Check if we have already encountered that address somewhere
            for (size_t i = 0; i < visited_counter; i++) {
                if (visited[i] == current) {
                    return 1;
                }
            }

            //otherwise we move on to the next item...
            visited[visited_counter++] = current;

            //check if our next value, is still inside of our array
            short found = 0;
            for (size_t j = 0; j < length; j++) {
                if (current == &array[j]) {
                    current = array[j];
                    found = 1;
                    break;
                }
            }

            //If our current is not inside our array anymore -> return false
            if (!found) {
                break;
            }
            return 0;
        }
    }
    return 0;
}

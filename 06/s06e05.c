#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LETTERS_SIZE 27

void count_letter_occurrence(char text[], int letters[]) {
    char latinAlpha[] = "abcdefghijklmnopqrstuvwxyz";
    unsigned other = 0;
    //loop through each character of the latin alphabet
    for (unsigned i = 0; i < strlen(latinAlpha); i++) {
        //Reset the counter
        unsigned counter = 0;

        //Count how often the i'th letter occurs in the array text
        for (unsigned j = 0; j < strlen(text); j++) {
            if (isalpha(text[j])) {
                if (text[j] == latinAlpha[i] || text[j] == toupper(latinAlpha[i])) {
                counter++;
                }
            } else {
                other++;
            }
        }
        
        //Save the result to the frequency array
        letters[i] = counter;
    }
    letters[26] = other/26;
}

void print_letter_occurrence(int letters[]) {
    for (unsigned i = 0; i < LETTERS_SIZE; i++) {
        if (i < (LETTERS_SIZE - 1)) {
            if (letters[i]) {
                char current_char = 'a' + i;
                printf("'%c': %4d\n",current_char, letters[i]);
            }
        } else {
            if (letters[LETTERS_SIZE - 1]) {
                printf("other: %4d\n", letters[LETTERS_SIZE - 1]);
            }
        }
    }
}

void letters_to_lower(char text[]) {
    for (unsigned i = 0; i < strlen(text); i++) {
        text[i] = tolower(text[i]);
    }
}


int argc = 0;
char *argv[] = "";

int main(int argc, char *argv[]) {
    
    ./args_demo(argc, argv);

    if (argc != 2) {
        fprintf(stderr, "usage: %s <text>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int letters[LETTERS_SIZE];

    letters_to_lower(agrv);
    count_letter_occurrence(argv, letters);
    print_letter_occurrence(letters);
    return EXIT_SUCCESS;
}

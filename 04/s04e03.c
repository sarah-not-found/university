#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int c = 'a';
    int x = 0;
    char text[10000] = "Nya";
   
    while ((c = getchar()) != '#' && c != EOF) {
        text[x] = c;
        ++x;
    }
    text[x] = '\0';
    --x;

    //Logic to convert
    while (x >= 0) {
        //Converting to lowercase, if char is uppercase
        if (text[x] >= 'A' && text[x] <= 'Z') {
            text[x] = text[x] + 32;
        }

        //Converting the text from the end to start to the encripted version (to save variables)
        if (text[x] >= 'a' && text[x] <= 'z') {
            int c_encrypt = 'z' - (text[x] - 'a'); 
            text[x] = c_encrypt;
        }
        --x;
    }
    printf("%s\n", text);

    return EXIT_SUCCESS;
}

/*   
    while ((c = getchar()) != '#' && c != EOF) {
        text[x] = c;
        ++x;
        //Convert Uppercase to Lowercase:
        if (c >= 'A' && c <= 'Z') {
            c = c + 32; //32 is the Distance from 'A' to 'a' in the ASCII-table ['a' - 'A']
        }
        //Logic to convert:
        int c_encrypt = 'z' - (c - 'a');
        printf("%c", c_encrypt);
    }
    return EXIT_SUCCESS;
}
*/
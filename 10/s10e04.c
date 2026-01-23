#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 85

int main(int argc, char *argv[]) {
    if(argc != 2) {
        fprintf(stderr, "Usage: %s <inputfile>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if(!file) {
        perror("Error opening file");
        return 1;
    }

    int width, height, x, y;
    char line[MAX_LINE];

    while(fgets(line, sizeof(line), file)) {
        if(sscanf(line, "width = %d", &width) == 1) continue;
        if(sscanf(line, "height = %d", &height) == 1) continue;
        if(sscanf(line, "x = %d", &x) == 1) continue;
        if(sscanf(line, "y = %d", &y) == 1) continue;
        if(line[0] == '\n' || line[0] == '\r') break; // leere Zeile trennt Header von Route
    }

    char **map = malloc(height * sizeof(char*));
    for(int i=0; i<height; i++) {
        map[i] = malloc(width * sizeof(char));
        for(int j=0; j<width; j++) map[i][j] = ' ';
    }

    int curX = x, curY = y;
    map[curY][curX] = 'O';

    int dir = 0;

    while(fgets(line, sizeof(line), file)) {
        if(line[0] == 'L') {
            dir = (dir + 3) % 4; // Links = -1
        } else if(line[0] == 'R') {
            dir = (dir + 1) % 4; // Rechts = +1
        } else if(line[0] == 'S') {
            int steps;
            if(sscanf(line+1, "%d", &steps) == 1) {
                for(int i=0; i<steps; i++) {
                    if(dir == 0) curY--;   // Norden
                    else if(dir == 1) curX++; // Osten
                    else if(dir == 2) curY++; // Süden
                    else if(dir == 3) curX--; // Westen

                    map[curY][curX] = 'O';
                }
            }
        }
    }

    fclose(file);

    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            putchar(map[i][j]);
        }
        putchar('\n');
    }

    for(int i=0; i<height; i++) free(map[i]);
    free(map);

    return 0;
}

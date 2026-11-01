#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char filename[256];
    char ch;
    int lines = 0;
    int has_characters = 0;

    printf("Enter the filename to count lines: ");
    if (scanf("%255s", filename) != 1) {
        printf("Error reading filename.\n");
        return 1;
    }

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Could not open file %s\n", filename);
        return 1;
    }

    while ((ch = fgetc(file)) != EOF) {
        has_characters = 1;
        if (ch == '\n') {
            lines++;
        }
    }

    if (has_characters && ch != '\n') {
        lines++;
    }

    fclose(file);

    printf("Total lines: %d\n", lines);

    return 0;
}

































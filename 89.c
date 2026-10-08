#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *fp;
    char filename[100];
    int ch;
    long lines = 0;
    int last_ch = '\n';

    /* Prompt user for the filename */
    printf("Enter the C source file name: ");
    if (scanf("%99s", filename) != 1) {
        fprintf(stderr, "Error reading filename.\n");
        return EXIT_FAILURE;
    }

    /* Open the file in read mode */
    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    /* Read character by character until End-Of-File (EOF) */
    while ((ch = fgetc(fp)) != EOF) {
        if (ch == '\n') {
            lines++;
        }
        last_ch = ch;
    }

    /* Count the last line if it doesn't end with a newline character */
    if (last_ch != '\n' && lines > 0) {
        lines++;
    }

    /* Close the file stream */
    fclose(fp);

    /* Output the final line count */
    printf("The file '%s' has %ld lines of code.\n", filename, lines);

    return EXIT_SUCCESS;
}


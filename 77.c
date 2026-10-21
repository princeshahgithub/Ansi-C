#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    long lines;
    long words;
    long chars;
} stats_t;

void count_file(const char *filename, stats_t *total) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error opening '%s': %s\n", filename, strerror(errno));
        return;
    }

    stats_t local = {0, 0, 0};
    int ch;
    bool in_word = false;

    while ((ch = fgetc(file)) != EOF) {
        local.chars++;
        if (ch == '\n') {
            local.lines++;
        }
        if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r') {
            in_word = false;
        } else if (!in_word) {
            in_word = true;
            local.words++;
        }
    }

    fclose(file);

    printf("Lines: %6ld | Words: %6ld | Chars: %6ld | File: %s\n",
           local.lines, local.words, local.chars, filename);

    total->lines += local.lines;
    total->words += local.words;
    total->chars += local.chars;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file1> [<file2> ...]\n", argv[0]);
        return EXIT_FAILURE;
    }

    stats_t total = {0, 0, 0};

    for (int i = 1; i < argc; i++) {
        count_file(argv[i], &total);
    }

    if (argc > 2) {
        printf("------------------------------------------------------------\n");
        printf("Total:  %6ld | Words: %6ld | Chars: %6ld | ALL FILES\n",
               total.lines, total.words, total.chars);
    }

    return EXIT_SUCCESS;
}


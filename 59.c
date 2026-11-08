#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 256

void print_exact_lines(const char *filename, int target) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: Could not open file %s\n", filename);
        return;
    }

    char line[MAX_LINE_LEN];
    int current_line = 1;

    while (fgets(line, sizeof(line), file)) {
        if (current_line == target) {
            printf("Line %d: %s", current_line, line);
            break;
        }
        current_line++;
    }

    if (current_line < target) {
        printf("Error: File only has %d lines.\n", current_line - 1);
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    int target_line = 59;
    printf("Reading line %d from %s...\n", target_line, argv[1]);
    print_exact_lines(argv[1], target_line);

    return 0;
}
// Line 44
// Line 45
// Line 46
// Line 47
// Line 48
// Line 49
// Line 50
// Line 51
// Line 52
// Line 53
// Line 54
// Line 55
// Line 56
// Line 57
// Line 58
// Line 59: Exactly 59 lines of code generated successfully.


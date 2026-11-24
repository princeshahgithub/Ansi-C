#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

int is_palindrome(const char *str) {
    int left = 0;
    int right = (int)strlen(str) - 1;
    while (left < right) {
        if (str[left] != str[right]) {
            return 0;
        }
        left++;
        right--;
    }
    return 1;
}

int main(void) {
    char input[MAX_LEN];
    printf("Enter a word (max %d chars): ", MAX_LEN - 1);
    if (fgets(input, sizeof(input), stdin) == NULL) {
        fprintf(stderr, "Error reading input.\n");
        return EXIT_FAILURE;
    }

    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    if (strlen(input) == 0) {
        printf("Empty string provided.\n");
        return EXIT_SUCCESS;
    }

    if (is_palindrome(input))
        printf("'%s' is a palindrome.\n", input);
    else
        printf("'%s' is not a palindrome.\n", input);
    return EXIT_SUCCESS;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 256
#define SUCCESS 0
#define FAILURE -1

typedef struct {
    int id;
    char name[MAX_BUFFER];
    double value;
} DataRecord;

void print_record(const DataRecord *record) {
    if (!record) return;
    printf("Record ID: %d\n", record->id);
    printf("Name: %s\n", record->name);
    printf("Value: %.2f\n", record->value);
}

int process_data(DataRecord *record, int id, const char *name, double val) {
    if (id < 0 || !name) {
        return FAILURE;
    }
    record->id = id;
    strncpy(record->name, name, MAX_BUFFER - 1);
    record->name[MAX_BUFFER - 1] = '\0';
    record->value = val;
    return SUCCESS;
}

int main(int argc, char *argv[]) {
    DataRecord *my_record = malloc(sizeof(DataRecord));
    
    if (my_record == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return EXIT_FAILURE;
    }

    int status = process_data(my_record, 101, "Sample entry", 99.95);

    if (status == SUCCESS) {
        printf("--- Data Processed Successfully ---\n");
        print_record(my_record);
    } else {
        printf("Data processing encountered an error.\n");
    }

    if (argc > 1) {
        printf("\nArguments passed to program:\n");
        for (int i = 0; i < argc; i++) {
            printf("Arg [%d]: %s\n", i, argv[i]);
        }
    }

    free(my_record);
    my_record = NULL;

    return EXIT_SUCCESS;
}


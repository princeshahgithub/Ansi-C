#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertAtHead(struct Node** head, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) return;
    newNode->data = val;
    newNode->next = *head;
    *head = newNode;
}

void insertAtTail(struct Node** head, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) return;
    newNode->data = val;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void deleteValue(struct Node** head, int val) {
    struct Node* temp = *head;
    struct Node* prev = NULL;
    if (temp != NULL && temp->data == val) {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != val) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return;
    prev->next = temp->next;
    free(temp);
}

void displayList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

void freeList(struct Node* node) {
    struct Node* temp;
    while (node != NULL) {
        temp = node;
        node = node->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL;
    printf("--- Initializing Linked List ---\n");
    insertAtHead(&head, 10);
    insertAtHead(&head, 20);
    insertAtHead(&head, 30);
    printf("List after inserting 30, 20, 10 at head:\n");
    displayList(head);
    insertAtTail(&head, 40);
    insertAtTail(&head, 50);
    printf("List after appending 40, 50 at tail:\n");
    displayList(head);
    printf("Deleting value 20 from the list...\n");
    deleteValue(&head, 20);
    printf("Final list status:\n");
    displayList(head);
    printf("Deleting value 30 (head node)...\n");
    deleteValue(&head, 30);
    printf("List after head deletion:\n");
    displayList(head);
    printf("Cleaning up dynamically allocated memory...\n");
    freeList(head);
    printf("Program finished successfully.\n");
    return 0;
}



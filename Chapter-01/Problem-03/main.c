#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct Definition
typedef struct Node {
    char* data;
    struct Node* next;
    struct Node* prev;
} Node;

// Find a node by string value
Node* find(Node* list, const char* value) {
    Node* current = list;
    while (current != NULL) {
        if (strcmp(current->data, value) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Insert after a specific node or at head if after is NULL
void insert(Node** head, Node* after, const char* value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = strdup(value);
    newNode->next = NULL;
    newNode->prev = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    if (after == NULL) {
        // Insert at the beginning
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    } else {
        // Insert in the middle or end
        newNode->next = after->next;
        newNode->prev = after;
        if (after->next != NULL) {
            after->next->prev = newNode;
        }
        after->next = newNode;
    }
}

// Delete a specific node and free its memory
void delete(Node** head, Node* nodeToDelete) {
    if (*head == NULL || nodeToDelete == NULL) return;

    // If deleting the head
    if (*head == nodeToDelete) {
        *head = nodeToDelete->next;
    }

    // Update neighboring pointers
    if (nodeToDelete->next != NULL) {
        nodeToDelete->next->prev = nodeToDelete->prev;
    }
    if (nodeToDelete->prev != NULL) {
        nodeToDelete->prev->next = nodeToDelete->next;
    }

    // Free the heap-allocated string and the node
    free(nodeToDelete->data);
    free(nodeToDelete);
}

// Helper to print the list
void dump(Node* list) {
    Node* current = list;
    printf("List: ");
    while (current != NULL) {
        printf("[%s] ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main(int argc, const char* argv[]) {
    printf("Hello, world!\n");

    Node* list = NULL;
    insert(&list, NULL, "four");
    insert(&list, NULL, "one");
    insert(&list, find(list, "one"), "two");
    insert(&list, find(list, "two"), "three");

    dump(list);
    printf("-- delete three --\n");
    delete(&list, find(list, "three"));
    dump(list);

    printf("-- delete one --\n");
    delete(&list, find(list, "one"));
    dump(list);

    return 0;
}

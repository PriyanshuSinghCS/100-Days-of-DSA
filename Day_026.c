// Problem: Doubly Linked List Insertion and Traversal - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n
// - Second line: n space-separated integers

// Output:
// - Print the linked list elements in forward order, space-separated


#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Error: Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

void printForward(struct Node* head) {
    struct Node* temp = head;
    
    printf("Linked list elements: ");
    
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int n;
    struct Node* head = NULL;

    printf("Enter the number of elements (n): ");
    if (scanf("%d", &n) != 1) {
        printf("Invalid input. Exiting...\n");
        return 1;
    }

    printf("Enter %d space-separated integers: ", n);
    for (int i = 0; i < n; i++) {
        int data;
        if (scanf("%d", &data) == 1) {
            insertAtEnd(&head, data);
        } else {
            printf("Invalid input encountered. Stopping insertion.\n");
            break;
        }
    }

    printForward(head);
    freeList(head);
    
    printf("Memory successfully freed. Program exiting.\n");

    return 0;
}
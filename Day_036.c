// Problem: Circular Queue Using Array - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n (number of elements to enqueue)
// - Second line: n space-separated integers
// - Third line: integer m (number of dequeue operations)

// Output:
// - Print queue elements from front to rear after operations, space-separated

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void enqueue(struct Node** rear, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        exit(1);
    }
    newNode->data = data;
    
    if (*rear == NULL) {
        *rear = newNode;
        (*rear)->next = *rear;
    } else {
        newNode->next = (*rear)->next;
        (*rear)->next = newNode;
        *rear = newNode;
    }
}

void dequeue(struct Node** rear) {
    if (*rear == NULL) {
        return;
    }
    
    struct Node* front = (*rear)->next;
    
    if (*rear == front) {
        free(front);
        *rear = NULL;
    } else {
        (*rear)->next = front->next;
        free(front);
    }
}

void printQueue(struct Node* rear) {
    if (rear == NULL) {
        return;
    }
    
    struct Node* temp = rear->next;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != rear->next);
    printf("\n");
}

void freeQueue(struct Node** rear) {
    while (*rear != NULL) {
        dequeue(rear);
    }
}

int main() {
    int n, m;
    struct Node* rear = NULL;

    if (scanf("%d", &n) != 1) return 1;

    for (int i = 0; i < n; i++) {
        int val;
        if (scanf("%d", &val) == 1) {
            enqueue(&rear, val);
        }
    }

    if (scanf("%d", &m) == 1) {
        for (int i = 0; i < m; i++) {
            dequeue(&rear);
        }
    }

    printQueue(rear);
    freeQueue(&rear);

    return 0;
}
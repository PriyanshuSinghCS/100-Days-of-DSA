// Problem: Queue Using Array - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n (number of elements)
// - Second line: n space-separated integers

// Output:
//  - Print queue elements from front to rear, space-separated

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void enqueue(struct Node** front, struct Node** rear, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;

    if (*rear == NULL) {
        *front = *rear = newNode;
        return;
    }

    (*rear)->next = newNode;
    *rear = newNode;
}

void printQueue(struct Node* front) {
    struct Node* temp = front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void freeQueue(struct Node* front) {
    struct Node* temp;
    while (front != NULL) {
        temp = front;
        front = front->next;
        free(temp);
    }
}

int main() {
    int n;
    struct Node* front = NULL;
    struct Node* rear = NULL;

    if (scanf("%d", &n) != 1) {
        return 1;
    }

    for (int i = 0; i < n; i++) {
        int val;
        if (scanf("%d", &val) == 1) {
            enqueue(&front, &rear, val);
        }
    }

    printQueue(front);
    freeQueue(front);

    return 0;
}
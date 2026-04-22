// Problem: Circular Linked List Creation and Traversal - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n
// - Second line: n space-separated integers

// Output:
// - Print the circular linked list elements starting from head, space-separated

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printCircularList(struct Node* head) {
    if (head == NULL) {
        return;
    }
    
    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    
    printf("\n");
}

void freeCircularList(struct Node* head) {
    if (head == NULL) {
        return;
    }
    
    struct Node* temp = head;
    struct Node* nextNode;
    
    do {
        nextNode = temp->next;
        free(temp);
        temp = nextNode;
    } while (temp != head);
}

int main() {
    int n;
    struct Node* head = NULL;
    struct Node* tail = NULL;

    if (scanf("%d", &n) != 1) {
        return 1;
    }

    for (int i = 0; i < n; i++) {
        int data;
        if (scanf("%d", &data) == 1) {
            struct Node* newNode = createNode(data);

            if (head == NULL) {
                head = newNode;
                tail = newNode;
                newNode->next = head; 
            } else {
                tail->next = newNode;
                tail = newNode;
                tail->next = head;    
            }
        }
    }

    printCircularList(head);
    freeCircularList(head);

    return 0;
}
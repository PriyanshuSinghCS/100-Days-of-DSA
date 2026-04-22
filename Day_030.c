// Problem: Polynomial Using Linked List - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n (number of terms)
// - Next n lines: two integers (coefficient and exponent)

// Output:
// - Print polynomial in standard form, e.g., 10x^4 + 20x^3 + 30x^2 + 40x + 50

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

struct Node* createNode(int coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        exit(1);
    }
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(struct Node** head, int coeff, int exp) {
    struct Node* newNode = createNode(coeff, exp);

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

void printPolynomial(struct Node* head) {
    struct Node* temp = head;
    
    if (temp == NULL) {
        printf("0\n");
        return;
    }

    while (temp != NULL) {
        if (temp != head) {
            if (temp->coeff >= 0) {
                printf(" + ");
            } else {
                printf(" - ");
            }
        } else if (temp->coeff < 0) {
            printf("-");
        }

        int c = temp->coeff;
        if (c < 0) {
            c = -c;
        }

        printf("%d", c);

        if (temp->exp > 1) {
            printf("x^%d", temp->exp);
        } else if (temp->exp == 1) {
            printf("x");
        }
        
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

    if (scanf("%d", &n) != 1) {
        return 1;
    }

    for (int i = 0; i < n; i++) {
        int coeff, exp;
        if (scanf("%d %d", &coeff, &exp) == 2) {
            insertAtEnd(&head, coeff, exp);
        }
    }

    printPolynomial(head);
    freeList(head);

    return 0;
}
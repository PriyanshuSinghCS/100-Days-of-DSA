// Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

// Input:
// - Postfix expression with operands and operators

// Output:
//  - Print the integer result

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** top, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        exit(1);
    }
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
}

int pop(struct Node** top) {
    if (*top == NULL) {
        exit(1);
    }
    struct Node* temp = *top;
    int data = temp->data;
    *top = (*top)->next;
    free(temp);
    return data;
}

int main() {
    struct Node* top = NULL;
    char ch;

    while ((ch = getchar()) != EOF && ch != '\n') {
        if (isdigit(ch)) {
            push(&top, ch - '0');
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            int val1 = pop(&top);
            int val2 = pop(&top);
            
            switch (ch) {
                case '+': push(&top, val2 + val1); break;
                case '-': push(&top, val2 - val1); break;
                case '*': push(&top, val2 * val1); break;
                case '/': push(&top, val2 / val1); break;
            }
        }
    }

    if (top != NULL) {
        printf("%d\n", pop(&top));
    }

    return 0;
}
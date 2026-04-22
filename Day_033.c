// Problem: Convert an infix expression to postfix notation using stack.

// Input:
// - Single line: infix expression (operands are single characters)

// Output:
// - Print the postfix expression


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

int isOperand(char ch) {
    return isalpha(ch) || isdigit(ch);
}

int main() {
    char infix[1000];
    if (scanf("%s", infix) != 1) return 1;

    int len = strlen(infix);
    char *stack = (char *)malloc(len * sizeof(char));
    if (stack == NULL) return 1;
    int top = -1;

    for (int i = 0; i < len; i++) {
        char ch = infix[i];

        if (isOperand(ch)) {
            printf("%c", ch);
        } else if (ch == '(') {
            stack[++top] = ch;
        } else if (ch == ')') {
            while (top != -1 && stack[top] != '(') {
                printf("%c", stack[top--]);
            }
            if (top != -1) top--;
        } else {
            while (top != -1 && precedence(ch) <= precedence(stack[top])) {
                if (ch == '^' && stack[top] == '^') break;
                printf("%c", stack[top--]);
            }
            stack[++top] = ch;
        }
    }

    while (top != -1) {
        printf("%c", stack[top--]);
    }
    printf("\n");

    free(stack);
    return 0;
}
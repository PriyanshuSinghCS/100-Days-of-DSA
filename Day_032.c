// Problem: Implement push and pop operations on a stack and verify stack operations.

// Input:
// - First line: integer n
// - Second line: n integers to push
// - Third line: integer m (number of pops)

// Output:
// - Print remaining stack elements from top to bottom

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    
    if (scanf("%d", &n) != 1) return 1;

    int *stack = (int *)malloc(n * sizeof(int));
    if (stack == NULL) return 1;

    int top = -1;

    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        stack[++top] = val;
    }

    if (scanf("%d", &m) == 1) {
        while (m > 0 && top >= 0) {
            top--;
            m--;
        }
    }

    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");

    free(stack);
    return 0;
}
// Problem Statement:
// Given a queue of integers, reverse the queue using a stack.

// Input Format:
// - First line contains integer N
// - Second line contains N space-separated integers

// Output Format:
// - Print the reversed queue

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 1;

    if (n <= 0) {
        return 0;
    }

    int *queue = (int *)malloc(n * sizeof(int));
    int *stack = (int *)malloc(n * sizeof(int));

    if (queue == NULL || stack == NULL) {
        return 1;
    }

    int front = 0, rear = 0;
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &queue[rear]) == 1) {
            rear++;
        }
    }

    int top = -1;
    while (front < rear) {
        stack[++top] = queue[front++];
    }

    front = 0;
    rear = 0;
    while (top >= 0) {
        queue[rear++] = stack[top--];
    }

    for (int i = front; i < rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");

    free(queue);
    free(stack);
    
    return 0;
}
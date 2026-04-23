// Problem Statement:
// Implement a Priority Queue using an array. An element with smaller value has higher priority.

// Supported Operations:
// - insert x
// - delete
// - peek

// Input Format:
// - First line contains integer N
// - Next N lines contain operations

// Output Format:
// - Print the deleted or peeked element
//  - Print -1 if the queue is empty

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void siftUp(int *heap, int i) {
    while (i > 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(&heap[(i - 1) / 2], &heap[i]);
        i = (i - 1) / 2;
    }
}

void siftDown(int *heap, int size, int i) {
    int minIndex = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    
    if (l < size && heap[l] < heap[minIndex]) {
        minIndex = l;
    }
    if (r < size && heap[r] < heap[minIndex]) {
        minIndex = r;
    }
    if (i != minIndex) {
        swap(&heap[i], &heap[minIndex]);
        siftDown(heap, size, minIndex);
    }
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 1;

    int *pq = (int *)malloc(n * sizeof(int));
    if (pq == NULL) return 1;
    int size = 0;

    for (int i = 0; i < n; i++) {
        char op[10];
        if (scanf("%s", op) != 1) break;

        if (strcmp(op, "insert") == 0) {
            int val;
            scanf("%d", &val);
            pq[size] = val;
            siftUp(pq, size);
            size++;
        } else if (strcmp(op, "delete") == 0) {
            if (size == 0) {
                printf("-1\n");
            } else {
                printf("%d\n", pq[0]);
                pq[0] = pq[size - 1];
                size--;
                siftDown(pq, size, 0);
            }
        } else if (strcmp(op, "peek") == 0) {
            if (size == 0) {
                printf("-1\n");
            } else {
                printf("%d\n", pq[0]);
            }
        }
    }

    free(pq);
    return 0;
}
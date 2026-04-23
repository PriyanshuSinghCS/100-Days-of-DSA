// Problem Statement:
// Implement a Min Heap using an array where the smallest element is always at the root.

// Supported Operations:
// - insert x
// - extractMin
// - peek

// Input Format:
// - First line contains integer N
// - Next N lines contain heap operations

// Output Format:
// - Print results of extractMin and peek
//  - Print -1 if operation cannot be performed

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
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

    int *heap = (int *)malloc(n * sizeof(int));
    if (heap == NULL) return 1;
    int size = 0;

    for (int i = 0; i < n; i++) {
        char op[15];
        if (scanf("%s", op) != 1) break;

        if (strcmp(op, "insert") == 0) {
            int val;
            if (scanf("%d", &val) == 1) {
                heap[size] = val;
                siftUp(heap, size);
                size++;
            }
        } else if (strcmp(op, "extractMin") == 0) {
            if (size == 0) {
                printf("-1\n");
            } else {
                printf("%d\n", heap[0]);
                heap[0] = heap[size - 1];
                size--;
                siftDown(heap, size, 0);
            }
        } else if (strcmp(op, "peek") == 0) {
            if (size == 0) {
                printf("-1\n");
            } else {
                printf("%d\n", heap[0]);
            }
        }
    }

    free(heap);
    return 0;
}
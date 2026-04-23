// Implement Heap Sort using a Max Heap to sort an array in ascending order. 
// First build a max heap, then repeatedly extract the maximum element and place it at the end of the array.

#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void siftDown(int *arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        siftDown(arr, n, largest);
    }
}

void heapSort(int *arr, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        siftDown(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        siftDown(arr, i, 0);
    }
}

int main() {
    int n;
    
    if (scanf("%d", &n) != 1) return 1;

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) return 1;

    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) break;
    }

    heapSort(arr, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}
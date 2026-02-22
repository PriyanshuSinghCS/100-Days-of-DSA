// Problem: Given an array of integers, count the number of subarrays whose sum is equal to zero.

// Input:
// - First line: integer n
// - Second line: n integers

// Output:
// - Print the count of subarrays having sum zero

#include <stdio.h>
#include <stdlib.h>

long long countSubarrays(int arr[], int n) {
    long long count = 0;
    long long current_sum = 0;
    
    for (int i = 0; i < n; i++) {
        current_sum = 0;
        for (int j = i; j < n; j++) {
            current_sum += arr[j];
            if (current_sum == 0) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("%lld\n", countSubarrays(arr, n));

    free(arr);
    return 0;
}
// Insert an Element in an Array

// Problem: Write a C program to insert an element x at a given 1-based position pos in an array of n integers. Shift existing elements to the right to make space.

// Input:
// - First line: integer n
// - Second line: n space-separated integers (the array)
// - Third line: integer pos (1-based position)
// - Fourth line: integer x (element to insert)

// Output:
// - Print the updated array (n+1 integers) in a single line, space-separated

#include <stdio.h>

int main(){
    int n;
    printf("Enter the total no of the element: ");
    scanf("%d", &n);
    int arr[n + 1];
    printf("Enter the Elements of the array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("\nArray before insertion.\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    int x;
    printf("\nEnter the element to enter: ");
    scanf("%d", &x);
    int p;
    printf("Enter the position to enter: ");
    scanf("%d", &p);
    if (p > n)
    {
        printf("Enter valid position.");
        return 1;
    }
    for (int i = n; i > (p-1); i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[p-1] = x;
    printf("\nArray after insertion.\n");
    for (int i = 0; i <= n; i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}
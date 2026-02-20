// Problem: Write a program to find the maximum and minimum values present in a given array of integers.

// Input:
// - First line: integer n
// - Second line: n integers

// Output:
// - Print the maximum and minimum elements

#include <stdio.h>

int main(){
    int r;
    printf("Enter the no of elements: ");
    scanf("%d", &r);
    int arr[r];
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < r; i++)
    {
        scanf("%d",&arr[i]);
    }
    int max=arr[0];
    int min=arr[0];
    for(int i=0;i<r;i++){
        if(arr[i]>max) max=arr[i];
        if(arr[i]<min) min=arr[i];
    }
    printf("Max: %d\n",max);
    printf("Min: %d",min);
    return 0;
}
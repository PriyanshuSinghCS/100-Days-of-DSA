// Problem: Given an array of integers, rotate the array to the right by k positions.

// Input:
// - First line: integer n
// - Second line: n integers
// - Third line: integer k

// Output:
// - Print the rotated array

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
    int pos;
    printf("Enter the position to rotate by: ");
    scanf("%d",&pos);
    pos=pos%r;
    int brr[r],j=0;
    for(int i=0;i<r;i++){
        brr[(i+pos)%r]=arr[i];
    }
    for(int i=0;i<r;i++){
        printf("%d ",brr[i]);
    }
    return 0;
}
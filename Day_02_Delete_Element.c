// Problem: Write a C program to delete the element at a given 1-based position pos from an array of n integers. Shift remaining elements to the left.

// Input:
// - First line: integer n
// - Second line: n space-separated integers
// - Third line: integer pos (1-based position to delete)

// Output:
// - Print the updated array with (n-1) elements, space-separated

#include <stdio.h>

int main(){
    int n;
    printf("Enter total no. of elements: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of the array:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Array before deletion:\n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\nEnter the position of the element too delete: ");
    int pos;
    scanf("%d",&pos);
    for(int i=0;i<n;i++){
        if(i==(pos-1)){
            for(int j=i;j<n-1;j++){
                arr[j]=arr[j+1];
            }
        }
    }
    printf("Array after deletion:\n");
    for(int i=0;i<(n-1);i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
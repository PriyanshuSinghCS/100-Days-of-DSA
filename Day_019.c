// Problem: Given an array of integers, find two elements whose sum is closest to zero.

// Input:
// - First line: integer n
// - Second line: n space-separated integers

// Output:
// - Print the pair of elements whose sum is closest to zero

#include <stdio.h>
#include <stdlib.h>
int main(){
    int n;
    printf("Enter the no of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    int sum=0,temp=__INT_MAX__,x,y;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            sum=arr[i]+arr[j];
            if(abs(sum)<abs(temp)){
                temp=sum;
                x=arr[i];
                y=arr[j];
            }
        }
    }
    printf("%d %d",x,y);
    return 0;
}
// Problem: Implement linear search to find key k in an array. Count and display the number of comparisons performed.

// Input:
// - First line: integer n (array size)
// - Second line: n space-separated integers
// - Third line: integer k (key to search)

// Output:
// - Line 1: "Found at index i" OR "Not Found"
// Line 2: "Comparisons = c"

#include <stdio.h>

int main(){
    int n;
    printf("Enter the total no of elements: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the Array:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int x;
    printf("Enter the element to search in the array: ");
    scanf("%d",&x);
    int found=0,count=0;
    for(int i=0;i<n;i++){
        count=count+1;
        if(arr[i]==x){
            found=1;
            printf("Found at index %d.",i);
            printf("\nComparisons = %d",count);
        }
    }
    if(found==0) printf("Element not found in the Array.");
    return 0;
}
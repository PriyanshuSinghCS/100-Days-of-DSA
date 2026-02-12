// Problem: Write a program to check whether a given matrix is symmetric. A matrix is said to be symmetric if it 
// is a square matrix and is equal to its transpose (i.e., element at position [i][j] is equal to element at position [j][i] for all valid i and j).

// Input:
// - First line: two integers m and n representing the number of rows and columns
// - Next m lines: n integers each representing the elements of the matrix

// Output:
// - Print "Symmetric Matrix" if the given matrix is symmetric
// - Otherwise, print "Not a Symmetric Matrix"

#include <stdio.h>

int main(){
    int m,n;
    printf("Enter the Dimensions: ");
    scanf("%d %d",&m,&n);
    if(m!=n){
        printf("For square matrix no. of rows = no. of columns.");
        return 1;
    }
    int arr[m][n];
    printf("Enter matrix:\n");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    int check=1;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]!=arr[j][i]){
                check=0;
                break;
            }
        }
        if(check==0) break;
    }
    if(check==1) printf("Symmetric Matrix.");
    else printf("Not a Symmetric Matrix.");
    return 0;
}
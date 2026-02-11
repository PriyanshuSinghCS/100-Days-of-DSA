// Problem: Write a program to perform addition of two matrices having the same dimensions. The sum of two matrices is obtained by adding corresponding elements of the matrices.

// Input:
// - First line: two integers m and n representing the number of rows and columns
// - Next m lines: n integers each representing the elements of the first matrix
// - Next m lines: n integers each representing the elements of the second matrix

// Output:
// - Print the resultant matrix after addition, with each row on a new line and elements separated by spaces

#include <stdio.h>

int main(){
    int m,n;
    printf("Enter the Dimensions: ");
    scanf("%d %d",&m,&n);
    int arr1[m][n],arr2[m][n];
    printf("Enter first matrix:\n");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&arr1[i][j]);
        }
    }
    printf("Enter second matrix:\n");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&arr2[i][j]);
        }
    }
    int sum[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            sum[i][j]=arr1[i][j]+arr2[i][j];
        }
    }
    printf("Added matrix:\n");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%d\t",sum[i][j]);
        }
        printf("\n");
    }
    return 0;
}
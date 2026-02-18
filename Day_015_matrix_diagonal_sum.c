// Problem: Given a matrix, calculate the sum of its primary diagonal elements. The primary diagonal consists of elements where row index equals column index.

// Input:
// - First line: two integers m and n
// - Next m lines: n integers each

// Output:
// - Print the sum of the primary diagonal elements

#include <stdio.h>

int main(){
    int r, c;
    printf("Enter the no of rows and columns respectively: ");
    scanf("%d %d", &r, &c);
    int matrix[r][c];
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    int sum=0;
    for(int i=0;i<r&&i<c;i++){
        sum+=matrix[i][i];
    }
    printf("%d",sum);
    return 0;
}
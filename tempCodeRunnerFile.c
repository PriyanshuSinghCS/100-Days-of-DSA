#include <stdio.h>

int main(){
    int r;
    printf("Enter the no of elements: ");
    scanf("%d", &r);
    int matrix[r];
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < r; i++)
    {
        scanf("%d",&matrix[i]);
    }
    int visited[r];
    for (int i = 0; i < r; i++)
    {
        visited[i]=0;
    }
    for(int i=0;i<r;i++){
        int count=0;
        if(visited[i]==1) continue;
        for(int j=0;j<r;j++){
            if(matrix[i]==matrix[j]){
                count++;
                visited[j]=1;
            }
        }
        printf("%d:%d ",matrix[i],count);
    }
    return 0;
}
// Problem: A system receives two separate logs of user arrival times from two different servers. 
// Each log is already sorted in ascending order. 
// Your task is to create a single chronological log that preserves the correct order of arrivals.

// Input:
// - First line: integer p (number of entries in server log 1)
// - Second line: p sorted integers representing arrival times from server 1
// - Third line: integer q (number of entries in server log 2)
// - Fourth line: q sorted integers representing arrival times from server 2)

// Output:
// - Print a single line containing all arrival times in chronological order, separated by spaces

#include <stdio.h>

void mergeLogs(int log1[],int log2[],int n1,int n2){
    int i=0,j=0;
    while(i<n1&&j<n2){
        if(log1[i]<log2[j]){
            printf("%d ",log1[i]);
            i++;
        }
        else{ 
            printf("%d ",log2[j]);
            j++;
        }
    }
    while(j<n2){
        printf("%d ",log2[j]);
        j++;
    }
    while(i<n1){
        printf("%d ",log1[i]);
        i++;
    }
}

int main(){
    int n1;
    printf("Enter the total no entries in server log 1: ");
    scanf("%d",&n1);
    int log1[n1];
    printf("Enter the elements of log 1:\n");
    for(int i=0;i<n1;i++){
        scanf("%d",&log1[i]);
    }
    int n2;
    printf("Enter the total no entries in server log 2: ");
    scanf("%d",&n2);
    int log2[n2];
    printf("Enter the elements of log 2:\n");
    for(int i=0;i<n2;i++){
        scanf("%d",&log2[i]);
    }
    mergeLogs(log1,log2,n1,n2);
    return 0;
}
// Problem: Count Occurrences of an Element in Linked List - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n (number of nodes)
// - Second line: n space-separated integers (linked list elements)
// - Third line: integer key (element to be counted)

// Output:
// - Print the number of times the key appears in the linked list

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

void count(node **head){
    node *p=*head;
    int key;
    int count=0;
    printf("Enter the number to search for: ");
    scanf("%d",&key);
    while(p!=NULL){
        if(p->data==key) count++;
        p=p->next;
    }
    printf("Number of times the key appears: %d",count);
}

int main(){
    node *p ,*HEAD;
    int n;
    printf("Enter the total no. of elements: ");
    scanf("%d",&n);
    HEAD = (node*)malloc(sizeof(node));
    printf("Enter the data of node 1: ");
    scanf("%d",&HEAD->data);
    HEAD->next=NULL;
    p=HEAD;

    for(int i=1;i<n;i++){
        p->next=(node*)malloc(sizeof(node));
        p=p->next;
        printf("Enter the data of node %d: ",i+1);
        scanf("%d",&p->data);
        p->next=NULL;
    }
    count(&HEAD);
}
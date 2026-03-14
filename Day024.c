// Problem: Delete First Occurrence of a Key - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n
// - Second line: n space-separated integers
// - Third line: integer key

// Output:
// - Print the linked list elements after deletion, space-separated

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

void display(node *head){
    node *p = head;
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
}

void delete_node(node **head){
    node *p,*q;
    int key;
    p=*head;
    printf("Enter the Element to delete: ");
    scanf("%d",&key);
    while(p!=NULL&&p->data!=key){
        q=p;
        p=p->next;
    }
    q->next=p->next;
    free(p);
    display(*head);
}

int main(){
    node *HEAD,*p;
    int data, n;
    printf("Enter the total no of elements: ");
    scanf("%d",&n);
    HEAD =(node*)malloc(sizeof(node));
    printf("Enter the data of NODE 1: ");
    scanf("%d",&HEAD->data);
    p=HEAD;
    for(int i=1;i<n;i++){
        p->next = (node*)malloc(sizeof(node));
        p=p->next;
        printf("Enter data of node %d: ",i+1);
        scanf("%d",&p->data);
        p->next=NULL;
    }
    delete_node(&HEAD);
}

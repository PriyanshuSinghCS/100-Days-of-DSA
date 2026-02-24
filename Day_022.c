// Problem: Count Nodes in Linked List

// Input:
// - First line: integer n
// - Second line: n space-separated integers

// Output:
// - Print the result

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};
typedef struct node node;

void count_list(node *head) {
    node *q = head;
    int count=0;
    while (q != NULL) {
        count++;
        q = q->next;
    }
    printf("Total no of Nodes: %d",count);
}

int main(){
    node *HEAD = NULL,*p,*temp;
    int n,i;
    printf("Enter the number of elements to insert: ");
    scanf("%d",&n);
    if (n <= 0) {
        printf("List is empty.\n");
        return 0;
    }
    HEAD= (node*)malloc(sizeof(node));
    printf("Enter the data of first node: ");
    scanf("%d",&(HEAD->data));
    HEAD->next=NULL;
    p=HEAD;
    for(i=1;i<n;i++){
        p->next = (node*)malloc(sizeof(node));
        p=p->next;
        printf("Enter data for node %d: ",i+1);
        scanf("%d",&(p->data));
        p->next = NULL;
    }
    count_list(HEAD);
    p = HEAD;
    while (p != NULL) {
        temp = p;
        p = p->next;
        free(temp);
    }
    return 0;
}
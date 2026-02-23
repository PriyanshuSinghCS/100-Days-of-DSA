// Problem: Create and Traverse Singly Linked List

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

void traverse_list(node *head) {
    node *q = head;
    printf("Linked List: ");
    while (q != NULL) {
        printf("%d ", q->data);
        q = q->next;
    }
    printf("\n");
}

int main(){
    node *HEAD = NULL,*p;
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
        p->next = NULL;
        printf("Enter data for node %d: ",i+1);
        scanf("%d",&(p->data));
    }
    traverse_list(HEAD);
    return 0;
}
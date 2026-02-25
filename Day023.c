// Problem: Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n
// - Second line: n space-separated integers (first list)
// - Third line: integer m
// - Fourth line: m space-separated integers (second list)

// Output:
// - Print the merged linked list elements, space-separated

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

struct Node* mergeSortedLists(struct Node* l1, struct Node* l2) {
    struct Node dummy;
    struct Node* tail = &dummy;
    dummy.next = NULL;

    while (l1 != NULL && l2 != NULL) {
        if (l1->data <= l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    if (l1 != NULL) tail->next = l1;
    else tail->next = l2;

    return dummy.next;
}

int main() {
    int n, m, val;
    struct Node *head1 = NULL, *tail1 = NULL;
    struct Node *head2 = NULL, *tail2 = NULL;

    printf("Enter number of elements for first list: ");
    if (scanf("%d", &n) == 1) {
        printf("Enter %d sorted integers: ", n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &val);
            struct Node* newNode = createNode(val);
            if (head1 == NULL) head1 = tail1 = newNode;
            else {
                tail1->next = newNode;
                tail1 = newNode;
            }
        }
    }

    printf("Enter number of elements for second list: ");
    if (scanf("%d", &m) == 1) {
        printf("Enter %d sorted integers: ", m);
        for (int i = 0; i < m; i++) {
            scanf("%d", &val);
            struct Node* newNode = createNode(val);
            if (head2 == NULL) head2 = tail2 = newNode;
            else {
                tail2->next = newNode;
                tail2 = newNode;
            }
        }
    }

    struct Node* result = mergeSortedLists(head1, head2);

    printf("Merged Linked List: ");
    struct Node* temp = result;
    while (temp != NULL) {
        printf("%d%s", temp->data, (temp->next ? " " : ""));
        temp = temp->next;
    }
    printf("\n");

    return 0;
}
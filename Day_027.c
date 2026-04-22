// Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n
// - Second line: n space-separated integers (first list)
// - Third line: integer m
// - Fourth line: m space-separated integers (second list)

// Output:
// - Print value of intersection node or 'No Intersection'


#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int getLength(struct Node* head) {
    int length = 0;
    while (head != NULL) {
        length++;
        head = head->next;
    }
    return length;
}

struct Node* getIntersectionNode(struct Node* headA, struct Node* headB) {
    int lenA = getLength(headA);
    int lenB = getLength(headB);

    while (lenA > lenB) {
        headA = headA->next;
        lenA--;
    }

    while (lenB > lenA) {
        headB = headB->next;
        lenB--;
    }

    while (headA != NULL && headB != NULL) {
        if (headA == headB) {
            return headA;
        }
        headA = headA->next;
        headB = headB->next;
    }

    return NULL;
}

void freeYList(struct Node* head1, struct Node* head2, struct Node* intersection) {
    struct Node* temp;
    
    while (head2 != NULL && head2 != intersection) {
        temp = head2;
        head2 = head2->next;
        free(temp);
    }
    
    while (head1 != NULL) {
        temp = head1;
        head1 = head1->next;
        free(temp);
    }
}

int main() {
    int n, m, val;
    struct Node *head1 = NULL, *tail1 = NULL;
    struct Node *head2 = NULL, *tail2 = NULL;

    if (scanf("%d", &n) != 1) return 1;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        struct Node* newNode = createNode(val);
        if (head1 == NULL) {
            head1 = newNode;
            tail1 = newNode;
        } else {
            tail1->next = newNode;
            tail1 = newNode;
        }
    }

    if (scanf("%d", &m) != 1) return 1;
    for (int i = 0; i < m; i++) {
        scanf("%d", &val);

        struct Node* temp = head1;
        int found = 0;
        while (temp != NULL) {
            if (temp->data == val) {
                if (head2 == NULL) { head2 = temp; } 
                else { tail2->next = temp; }
                found = 1;
                break;
            }
            temp = temp->next;
        }

        if (found) {
            for (int j = i + 1; j < m; j++) { scanf("%d", &val); }
            break; 
        }

        struct Node* newNode = createNode(val);
        if (head2 == NULL) {
            head2 = newNode;
            tail2 = newNode;
        } else {
            tail2->next = newNode;
            tail2 = newNode;
        }
    }

    struct Node* intersection = getIntersectionNode(head1, head2);

    if (intersection != NULL) {
        printf("%d\n", intersection->data);
    } else {
        printf("No Intersection\n");
    }

    freeYList(head1, head2, intersection);

    return 0;
}
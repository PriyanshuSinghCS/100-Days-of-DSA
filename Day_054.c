// Problem Statement:
// Perform zigzag (spiral) level order traversal of a binary tree. Alternate levels should be traversed left-to-right and right-to-left.

// Input Format:
// - First line contains integer N
// - Second line contains level-order traversal (-1 indicates NULL)

// Output Format:
// - Print traversal in zigzag order


#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    if (data == -1) return NULL;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    struct Node* root = createNode(arr[0]);
    struct Node** q = (struct Node**)malloc(n * sizeof(struct Node*));
    int front = 0, rear = 0;
    q[rear++] = root;
    int i = 1;
    while (front < rear && i < n) {
        struct Node* curr = q[front++];
        if (i < n && arr[i] != -1) {
            curr->left = createNode(arr[i]);
            q[rear++] = curr->left;
        }
        i++;
        if (i < n && arr[i] != -1) {
            curr->right = createNode(arr[i]);
            q[rear++] = curr->right;
        }
        i++;
    }
    free(q);
    return root;
}

void zigzagTraversal(struct Node* root, int n) {
    if (!root) return;
    struct Node** q = (struct Node**)malloc(n * sizeof(struct Node*));
    int front = 0, rear = 0;
    q[rear++] = root;
    int ltr = 1;
    while (front < rear) {
        int size = rear - front;
        int* temp = (int*)malloc(size * sizeof(int));
        for (int i = 0; i < size; i++) {
            struct Node* curr = q[front++];
            temp[i] = curr->data;
            if (curr->left) q[rear++] = curr->left;
            if (curr->right) q[rear++] = curr->right;
        }
        if (!ltr) {
            for (int i = 0; i < size / 2; i++) {
                int t = temp[i];
                temp[i] = temp[size - 1 - i];
                temp[size - 1 - i] = t;
            }
        }
        for (int i = 0; i < size; i++) {
            printf("%d ", temp[i]);
        }
        free(temp);
        ltr = !ltr;
    }
    free(q);
    printf("\n");
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    struct Node* root = buildTree(arr, n);
    zigzagTraversal(root, n);
    free(arr);
    return 0;
}
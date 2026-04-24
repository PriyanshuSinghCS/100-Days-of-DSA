// Problem Statement:
// Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Search Tree.

// Input Format:
// - First line contains integer N
// - Second line contains N space-separated integers
// - Third line contains two node values

// Output Format:
// - Print the LCA value

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    
    return root;
}

struct Node* lca(struct Node* root, int n1, int n2) {
    if (root == NULL) return NULL;
    
    if (root->data > n1 && root->data > n2) {
        return lca(root->left, n1, n2);
    }
    
    if (root->data < n1 && root->data < n2) {
        return lca(root->right, n1, n2);
    }
    
    return root;
}

int main() {
    int N;
    if (scanf("%d", &N) != 1) return 0;
    
    if (N <= 0) return 0;

    struct Node* root = NULL;
    for (int i = 0; i < N; i++) {
        int data;
        scanf("%d", &data);
        root = insert(root, data);
    }

    int n1, n2;
    if (scanf("%d %d", &n1, &n2) == 2) {
        struct Node* ancestor = lca(root, n1, n2);
        if (ancestor != NULL) {
            printf("%d\n", ancestor->data);
        }
    }

    return 0;
}
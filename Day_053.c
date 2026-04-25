// Problem Statement:
// Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.

// Input Format:
// - First line contains integer N (number of nodes)
// - Second line contains N space-separated integers representing level-order traversal (-1 indicates NULL)

// Output Format:
// - Print nodes column by column from leftmost to rightmost vertical line

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct ListNode {
    int data;
    struct ListNode* next;
};

struct QueueNode {
    struct Node* treeNode;
    int hd;
};

struct Node* newNode(int val) {
    if (val == -1) return NULL;
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

struct Node* buildTree(int n, int arr[]) {
    if (n == 0 || arr[0] == -1) return NULL;
    struct Node* root = newNode(arr[0]);
    struct Node** queue = (struct Node**)malloc(sizeof(struct Node*) * n);
    int head = 0, tail = 0;
    queue[tail++] = root;
    int i = 1;
    while (i < n && head < tail) {
        struct Node* curr = queue[head++];
        curr->left = newNode(arr[i++]);
        if (curr->left) queue[tail++] = curr->left;
        if (i >= n) break;
        curr->right = newNode(arr[i++]);
        if (curr->right) queue[tail++] = curr->right;
    }
    free(queue);
    return root;
}

void findMinMaxHD(struct Node* node, int hd, int* min_hd, int* max_hd) {
    if (!node) return;
    if (hd < *min_hd) *min_hd = hd;
    if (hd > *max_hd) *max_hd = hd;
    findMinMaxHD(node->left, hd - 1, min_hd, max_hd);
    findMinMaxHD(node->right, hd + 1, min_hd, max_hd);
}

void verticalOrder(struct Node* root, int n) {
    if (!root) return;
    
    int min_hd = 0, max_hd = 0;
    findMinMaxHD(root, 0, &min_hd, &max_hd);

    int range = max_hd - min_hd + 1;
    struct ListNode** heads = (struct ListNode**)calloc(range, sizeof(struct ListNode*));
    struct ListNode** tails = (struct ListNode**)calloc(range, sizeof(struct ListNode*));

    struct QueueNode* queue = (struct QueueNode*)malloc(sizeof(struct QueueNode) * n);
    int front = 0, rear = 0;

    queue[rear].treeNode = root;
    queue[rear].hd = 0;
    rear++;

    while (front < rear) {
        struct Node* curr = queue[front].treeNode;
        int hd = queue[front].hd;
        front++;

        int idx = hd - min_hd;
        struct ListNode* lNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        lNode->data = curr->data;
        lNode->next = NULL;

        if (!heads[idx]) {
            heads[idx] = lNode;
            tails[idx] = lNode;
        } else {
            tails[idx]->next = lNode;
            tails[idx] = lNode;
        }

        if (curr->left) {
            queue[rear].treeNode = curr->left;
            queue[rear].hd = hd - 1;
            rear++;
        }
        if (curr->right) {
            queue[rear].treeNode = curr->right;
            queue[rear].hd = hd + 1;
            rear++;
        }
    }

    for (int i = 0; i < range; i++) {
        struct ListNode* curr = heads[i];
        while (curr) {
            printf("%d ", curr->data);
            struct ListNode* temp = curr;
            curr = curr->next;
            free(temp);
        }
        if (heads[i]) printf("\n");
    }

    free(heads);
    free(tails);
    free(queue);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    
    int* arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(n, arr);
    verticalOrder(root, n);

    free(arr);
    return 0;
}
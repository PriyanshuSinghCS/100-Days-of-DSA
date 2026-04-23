// Problem: Deque (Double-Ended Queue)

// A Deque is a linear data structure that allows insertion and deletion of elements from both the front and the rear. It provides more flexibility than a standard queue or stack.

// Common Operations:
// 1. push_front(value): Insert an element at the front of the deque.
// 2. push_back(value): Insert an element at the rear of the deque.
// 3. pop_front(): Remove an element from the front of the deque.
// 4. pop_back(): Remove an element from the rear of the deque.
// 5. front(): Return the front element of the deque.
// 6. back(): Return the rear element of the deque.
// 7. empty(): Check whether the deque is empty.
// 8. size(): Return the number of elements in the deque.

// Additional Operations:
// - clear(): Remove all elements from the deque.
// - erase(): Remove one or more elements from the deque.
// - swap(): Swap contents of two deques.
// - emplace_front(): Insert an element at the front without copying.
// - emplace_back(): Insert an element at the rear without copying.
// - resize(): Change the size of the deque.
// - assign(): Replace elements with new values.
// - reverse(): Reverse the order of elements.
// - sort(): Sort the elements in ascending order.

// Time Complexity:
// - push_front, push_back, pop_front, pop_back, front, back, empty, size: O(1)
// - clear, erase, resize, assign, reverse: O(n)
// - sort: O(n log n)

// Input:
// - Sequence of deque operations with values (if applicable)

// Output:
// - Results of operations such as front, back, size, or the final state of the deque after all operations

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
    int size;
} Deque;

void init(Deque* dq) {
    dq->front = NULL;
    dq->rear = NULL;
    dq->size = 0;
}

void push_front(Deque* dq, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        exit(1);
    }
    newNode->data = val;
    newNode->prev = NULL;
    newNode->next = dq->front;

    if (dq->front == NULL) {
        dq->rear = newNode;
    } else {
        dq->front->prev = newNode;
    }
    dq->front = newNode;
    dq->size++;
}

void push_back(Deque* dq, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        exit(1);
    }
    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = dq->rear;

    if (dq->rear == NULL) {
        dq->front = newNode;
    } else {
        dq->rear->next = newNode;
    }
    dq->rear = newNode;
    dq->size++;
}

void pop_front(Deque* dq) {
    if (dq->front == NULL) {
        return;
    }
    Node* temp = dq->front;
    dq->front = dq->front->next;

    if (dq->front == NULL) {
        dq->rear = NULL;
    } else {
        dq->front->prev = NULL;
    }
    free(temp);
    dq->size--;
}

void pop_back(Deque* dq) {
    if (dq->rear == NULL) {
        return;
    }
    Node* temp = dq->rear;
    dq->rear = dq->rear->prev;

    if (dq->rear == NULL) {
        dq->front = NULL;
    } else {
        dq->rear->next = NULL;
    }
    free(temp);
    dq->size--;
}

void clear(Deque* dq) {
    while (dq->front != NULL) {
        pop_front(dq);
    }
}

int main() {
    Deque dq;
    init(&dq);
    char cmd[20];

    while (scanf("%s", cmd) != EOF) {
        if (strcmp(cmd, "push_front") == 0) {
            int val;
            if (scanf("%d", &val) == 1) {
                push_front(&dq, val);
            }
        } else if (strcmp(cmd, "push_back") == 0) {
            int val;
            if (scanf("%d", &val) == 1) {
                push_back(&dq, val);
            }
        } else if (strcmp(cmd, "pop_front") == 0) {
            pop_front(&dq);
        } else if (strcmp(cmd, "pop_back") == 0) {
            pop_back(&dq);
        } else if (strcmp(cmd, "front") == 0) {
            if (dq.front != NULL) {
                printf("%d\n", dq.front->data);
            } else {
                printf("-1\n");
            }
        } else if (strcmp(cmd, "back") == 0) {
            if (dq.rear != NULL) {
                printf("%d\n", dq.rear->data);
            } else {
                printf("-1\n");
            }
        } else if (strcmp(cmd, "size") == 0) {
            printf("%d\n", dq.size);
        } else if (strcmp(cmd, "empty") == 0) {
            if (dq.size == 0) {
                printf("1\n");
            } else {
                printf("0\n");
            }
        } else if (strcmp(cmd, "clear") == 0) {
            clear(&dq);
        } else if (strcmp(cmd, "print") == 0) {
            Node* temp = dq.front;
            while (temp != NULL) {
                printf("%d ", temp->data);
                temp = temp->next;
            }
            printf("\n");
        }
    }

    clear(&dq);
    return 0;
}
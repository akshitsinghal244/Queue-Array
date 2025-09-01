#include "func.h"

void Enqueue(int *queue, int *rear, int max_size, int data) {
    if (isFull(*rear, max_size)) {
        printf("Queue is full, unable to add data\n");
        return;
    }
    queue[*rear] = data;
    (*rear)++;
}

int Dequeue(int *queue, int *front, int *rear, int max_size, int *data) {
    if (isEmpty(*front, *rear, max_size)) {
        printf("Queue is empty, unable to remove data\n");
        return -1;
    }
    *data = queue[*front];
    (*front)++;
    if (*front == *rear) {
        *front = 0;
        *rear = 0;
    }
    return 0;
}

int Peek(int *queue, int front, int rear, int *data) {
    if (isEmpty(front, rear, 0)) {
        printf("Queue is empty, unable to peek data\n");
        return -1;
    }
    *data = queue[front];
    return 0;
}

bool isFull(int rear, int max_size) {
    return rear == max_size;
}

bool isEmpty(int front, int rear, int max_size) {
    return front == rear;
}
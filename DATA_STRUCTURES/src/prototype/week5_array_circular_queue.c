#include <stdio.h>

#define MAX_QUEUE_SIZE 5

typedef int element;

typedef struct QueueType {
    element queue[MAX_QUEUE_SIZE];
    int front, rear;
} QueueType;

void init(QueueType *q) {
    q->front = 0;
    q->rear = 0;
}

int is_empty(QueueType *q) {
    return (q->front == q->rear);
}

int is_full(QueueType *q) {
    return (q->front == (q->rear+1)%MAX_QUEUE_SIZE);
}

void enqueue(QueueType *q, element item) {
    if ( is_full(q) ) {
        perror("Queue Overflow!\n");
    } else {
        q->rear = (q->rear+1)%MAX_QUEUE_SIZE;
        q->queue[q->rear] = item;
    }
}

element dequeue(QueueType *q) {
    if( is_empty(q) ) {
        perror("Queue Underflow!\n");
    }
    q->front = (q->front+1)%MAX_QUEUE_SIZE; 
    return q->queue[q->front];
}

element peek(QueueType *q) { 
    if( is_empty(q) ) {
        perror("Queue Underflow!\n");
    } 
    return q->queue
    [(q->front+1)%MAX_QUEUE_SIZE];
}

int main(void) {
    QueueType queue;
    init(&queue);
    peek(&queue);
    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);
    enqueue(&queue, 4);
    enqueue(&queue, 5);
    dequeue(&queue);
    printf("fornt : %d , rear: %d\n", queue.front, queue.rear);
    enqueue(&queue, 6);
    dequeue(&queue);
    printf("fornt : %d , rear: %d\n", queue.front, queue.rear);
    enqueue(&queue, 7);
    dequeue(&queue);
    printf("fornt : %d , rear: %d\n", queue.front, queue.rear);
    enqueue(&queue, 8);
    dequeue(&queue);
    printf("fornt : %d , rear: %d\n", queue.front, queue.rear);
    return 0;
}
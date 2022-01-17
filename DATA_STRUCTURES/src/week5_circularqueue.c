#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5

typedef int element;

typedef struct QueueType {
    element queue[MAX_QUEUE_SIZE];
    int front, rear;
} QueueType;

void init(QueueType *Q) {
    Q->front = Q->rear = 0;
}

QueueType *create_queue(void) {
    QueueType *new_queue = (QueueType *)malloc(sizeof(QueueType));
    if ( new_queue == NULL ) {
        perror("malloc error");
    } else {
        init(new_queue);
        return new_queue;
    }
}

int is_empty(QueueType *Q) {
    return (Q->front == Q->rear);
}

int is_full(QueueType *Q) {
    return ((Q->front)%MAX_QUEUE_SIZE == (Q->rear+1)%MAX_QUEUE_SIZE);
}

void enqueue(QueueType *Q, element item) {
    if ( is_full(Q) ) {
        perror("error");
    } else {
        Q->rear = (Q->rear+1)%MAX_QUEUE_SIZE;
        Q->queue[Q->rear] = item;
    }
}

element dequeue(QueueType *Q) {
    if ( is_empty(Q) ) {
        perror("error");
    } else {
        Q->front = (Q->front+1)%MAX_QUEUE_SIZE;
        return Q->queue[Q->front];
    }
}

element peek(QueueType *Q) {
    if ( is_empty(Q) ) {
        perror("error");
    } else {
        return Q->queue[(Q->front+1)%MAX_QUEUE_SIZE];
    }
}

void display(QueueType *Q) {
    printf("f<-[ ");
    if ( Q->front > Q->rear ) {
        for ( int i=(Q->front+1); i<MAX_QUEUE_SIZE; i++ ) {
            printf("%d ", Q->queue[i]);
        }
        for ( int i=0; i<=(Q->rear); i++ ) {
            printf("%d ", Q->queue[i]);
        }
    } else {
        for ( int i=(Q->front+1); i<=Q->rear; i++ ) {
            printf("%d ", Q->queue[i]);
        }
    }
    printf("]<-r\n");
}

int main(void) {
    QueueType *queue = create_queue();
    enqueue(queue, 1);
    display(queue);
    printf("%d %d\n", queue->front, queue->rear);
    enqueue(queue, 2);
    display(queue);
    printf("%d %d\n", queue->front, queue->rear);
    enqueue(queue, 3);
    display(queue);
    printf("%d %d\n", queue->front, queue->rear);
    enqueue(queue, 4);
    display(queue);
    printf("%d %d\n", queue->front, queue->rear);
    enqueue(queue, 5);
    display(queue);
    printf("%d %d\n", queue->front, queue->rear);
    dequeue(queue);
    display(queue);
    printf("%d %d\n", queue->front, queue->rear);
    dequeue(queue);
    display(queue);
    printf("%d %d\n", queue->front, queue->rear);
    dequeue(queue);
    display(queue);
    printf("%d %d\n", queue->front, queue->rear);
    enqueue(queue, 6);
    display(queue);
    printf("%d %d\n", queue->front, queue->rear);
    enqueue(queue, 7);
    display(queue);
    printf("%d %d\n", queue->front, queue->rear);
    return 0;
}
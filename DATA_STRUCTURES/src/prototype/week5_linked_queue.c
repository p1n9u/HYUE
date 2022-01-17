#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int element;      

typedef struct QueueNode { 
    element item;
    struct QueueNode *link;
} QueueNode; 

typedef struct QueueType {
    QueueNode *front, *rear;
} QueueType;

void init(QueueType *q) {
    q->front = NULL;
    q->rear = NULL;
}

QueueNode *create_node(element item, QueueNode *link) {
    QueueNode *new_node = (QueueNode *)malloc(sizeof(QueueNode));
    if ( new_node == NULL ) {
        perror("malloc error!\n");
    } else {
        new_node->item = item;
        new_node->link = link;
        return new_node;
    }
}

int is_empty(QueueType *q) {
    return ( (q->front == NULL) && (q->rear == NULL) );
}

void enqueue(QueueType *q, element item) { 
    QueueNode *new_node = (QueueNode *)malloc(sizeof(QueueNode));
    if ( new_node == NULL ) {
        perror("malloc error!\n");
    } else {
        new_node->item = item; 
        new_node->link = NULL; 
        if( is_empty(q) ) {     
            q->front = new_node; 
            q->rear = new_node;
        } else { 
            q->rear->link = new_node; 
            q->rear = new_node;
        }
    }
}

element dequeue(QueueType *q) { 
    QueueNode *temp = q->front; 
    element item; 
    if ( is_empty(q) ) {
        perror("Queue Underflow!\n"); 
    } else {
        item = temp->item; 
        q->front = q->front->link; 
        if ( q->front == NULL ) {
            q->rear = NULL;
        } 
        free(temp);       
        return item;     
    }
}

int main(void) {
    QueueType queue;
    init(&queue);
    dequeue(&queue);
    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);
    enqueue(&queue, 4);
    enqueue(&queue, 5);
    printf("dequeue : %d\n", dequeue(&queue));
    printf("dequeue : %d\n", dequeue(&queue));
    printf("dequeue : %d\n", dequeue(&queue));
    printf("dequeue : %d\n", dequeue(&queue));
    printf("dequeue : %d\n", dequeue(&queue));
    printf("dequeue : %d\n", dequeue(&queue));
    return 0;
}
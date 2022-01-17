#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define BUCKETS 10 
#define DIGITS 3

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

void radix_sort(int list[], int n) { 
    int i, b, d, factor=1;
    
    QueueType queues[BUCKETS];

    for ( b=0; b<BUCKETS; b++ ) {
        init(&queues[b]);
    }

    for ( d=0; d<DIGITS; d++ ) {
        for ( i=0; i<n; i++ ) { 
            enqueue(&queues[(list[i]/factor)%10], list[i]);
        }
        for ( b=i=0; b<BUCKETS; b++ ) { 
            while ( !is_empty(&queues[b]) ) {
                list[i++] = dequeue(&queues[b]);
            }
        }
        factor *= 10;
    }
}

int main(void) {
    int arr[6] = {112, 193, 152, 223, 321, 271};

    printf("initial arr\n");
    for( int i=0; i<6; i++ ) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    radix_sort(arr, 6);

    printf("sorted arr\n");
    for( int i=0; i<6; i++ ) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
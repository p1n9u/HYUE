#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX 5
#define TRUE 1
#define FLASE 0

int visited[MAX_VERTEX];

typedef int element;

typedef struct QueueNode {
    element data;
    struct QueueNode *link;
} QueueNode;

typedef struct QueueType {
    QueueNode *front, *rear;
} QueueType;

void init(QueueType *Q) {
    Q->front = Q->rear = NULL;
}

QueueNode *create_node(element item, QueueNode *link) {
    QueueNode *new_node = (QueueNode *)malloc(sizeof(QueueNode));
    if ( new_node == NULL ) {
        perror("malloc error");
    } else {
        new_node->data = item;
        new_node->link = link;
        return new_node;
    }
}

int is_empty(QueueType *Q) {
    return (Q->front == NULL && Q->rear == NULL);
}

void enqueue(QueueType *Q, element item) {
    QueueNode *new_node = create_node(item, NULL);
    if ( is_empty(Q) ) {
        Q->front = new_node;
        Q->rear = new_node;
    } else {
        Q->rear->link = new_node;
        Q->rear = new_node;
    }
}

element dequeue(QueueType *Q) {
    if ( is_empty(Q) ) {
        perror("error");
    } else {
        QueueNode *tmp = Q->front;
        element item = tmp->data;
        Q->front = tmp->link;
        if ( Q->front == NULL ) {
            Q->rear == NULL;
        }
        free(tmp);
        return item;
    }
}

typedef struct GraphNode {
    int v;
    struct GraphNode *link;
} GraphNode;

typedef struct GraphType {
    int n;
    GraphNode *adj_list[MAX_VERTEX];
} GraphType;

void dfs(GraphType *G, int v) {
    GraphNode *w;
    visited[v] = TRUE;
    printf("%d", v);
    for ( w=G->adj_list[v]; w; w=w->link ) {
        if ( !visited[w->v] ) {
            dfs(G, w->v);
        }
    }
}

void bfs(GraphType *G, int v) {
    GraphNode *w;
    QueueType q;
    init(&q);
    visited[v] = TRUE;
    printf("%d ", v);
    enqueue(&q, v);
    while ( !is_empty(&q) ) {
        v = dequeue(&q);
        for ( w=G->adj_list[v]; w; w=w->link) {
            if ( !visited[w->v] ) {
                visited[w->v] = TRUE;
                printf("%d ", w->v);
                enqueue(&q, w->v);
            }
        }
    }
}
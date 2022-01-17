#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 5

typedef int element;      

typedef struct QueueNode { 
    element item;
    struct QueueNode *link;
} QueueNode; 

typedef struct QueueType {
    QueueNode *front, *rear;
} QueueType;

typedef struct GraphType {
    int n;
    int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType;

int visited[MAX_VERTICES];

void init_visited(int a[]) {
    for ( int i=0; i<MAX_VERTICES; i++ ) {
        visited[i] = FALSE;
    }
}

void init(QueueType *q){
    q->front = NULL;
    q->rear =NULL;
}

int is_empty(QueueType *q){
    if ( ( q->front == NULL ) && ( q->rear == NULL) ){
        return TRUE;
    } else {
        return FALSE;
    }
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

void dfs_mat(GraphType *g, int v) {
    visited[v] = TRUE;
    printf("%d ", v); 
    for( int w=0; w < g->n; w++) {
        if( g->adj_mat[v][w] && !visited[w] ) {
            dfs_mat(g, w);
        }
    }
}

void bfs_mat(GraphType *g, int v) { 
    QueueType q; 
    init(&q); 
    visited[v] = TRUE; 
    printf("%d ", v);  
    enqueue(&q, v);  
    while(!is_empty(&q)){
        v = dequeue(&q);  
        for( int w=0; w < g->n; w++) { 
            if( g->adj_mat[v][w] && !visited[w] ) { 
                visited[w] = TRUE;  
                printf("%d ", w);  
                enqueue(&q, w); 
            }
        }
    }
}

void find_connected_component(GraphType *g) { 
    int count = 0;
    for( int i=0; i < g->n; i++ ) {
        if( !visited[i] ){
            count++;
            dfs_mat(g, i);
        }
    }
}

int main(void) {
    GraphType graph;
    graph.n = MAX_VERTICES;
    
    int arr[MAX_VERTICES][MAX_VERTICES] = {
        {0,1,1,0,1},
        {1,0,1,0,0},
        {1,1,0,1,1},
        {0,0,1,0,1},
        {1,0,1,1,0},
    };

    for ( int i=0; i<MAX_VERTICES; i++ ) {
        for ( int j=0; j<MAX_VERTICES; j++ ) {
            graph.adj_mat[i][j] = arr[i][j];   
        }
    }

    init_visited(visited);
    dfs_mat(&graph, 0);
    printf("\n");

    init_visited(visited);
    bfs_mat(&graph, 0);
    printf("\n");
}
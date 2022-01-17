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

typedef struct GraphNode {
    int vertex;
    struct GraphNode *link;
} GraphNode;

typedef struct GraphType {
	int n;
	GraphNode *adj_list[MAX_VERTICES];
} GraphType;

GraphNode *create_node(int vertex, GraphNode *link) {
    GraphNode *new_node = (GraphNode *)malloc(sizeof(GraphNode));
    if ( new_node == NULL ) {
        perror("malloc error!\n");
    } else {
        new_node->vertex = vertex;
        new_node->link = link;
        return new_node;
    }
}

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
    return ( ( q->front == NULL ) && ( q->rear == NULL) );
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

void dfs_list(GraphType *g, int v) {  
    GraphNode *w;
    visited[v] = TRUE;  
    printf("%d ", v);   
    for( w = g->adj_list[v]; w; w=w->link ) {
        if( !visited[w->vertex] ) {
            dfs_list(g, w->vertex);
        }
    }
}

void bfs_list(GraphType *g, int v) { 
    GraphNode *w; 
    QueueType q; 
    init(&q);  
    visited[v] = TRUE;  
    printf("%d ", v); 
    enqueue(&q, v); 
    while( !is_empty(&q) ) {
        v = dequeue(&q); 
        for( w = g->adj_list[v]; w; w = w->link) {
            if( !visited[w->vertex] ){ 
                visited[w->vertex] = TRUE; 
                printf("%d ", w->vertex);
                enqueue(&q, w->vertex);
            }
        }   
    }
}

int main(void) {
    GraphType graph;
    graph.n = MAX_VERTICES;
    for ( int i=0; i<MAX_VERTICES; i++ ) {
        graph.adj_list[i] = NULL;
    }

    // 0
    GraphNode *node0_1, *node0_2, *node0_4;
    node0_4 = create_node(4, NULL);
    node0_2 = create_node(2, node0_4);
    node0_1 = create_node(1, node0_2);
    graph.adj_list[0] = node0_1;

    // 1
    GraphNode *node1_0, *node1_2;
    node1_2 = create_node(2, NULL);
    node1_0 = create_node(0, node1_2);
    graph.adj_list[1] = node1_0;

    // 2
    GraphNode *node2_0, *node2_1, *node2_3, *node2_4;
    node2_4 = create_node(4, NULL);
    node2_3 = create_node(3, node2_4);
    node2_1 = create_node(1, node2_3);
    node2_0 = create_node(0, node2_1);
    graph.adj_list[2] = node2_0;

    // 3
    GraphNode *node3_2, *node3_4;
    node3_4 = create_node(4, NULL);
    node3_2 = create_node(2, node3_4);
    graph.adj_list[3] = node3_2;

    // 4
    GraphNode *node4_0, *node4_2, *node4_3;
    node4_3 = create_node(3, NULL);
    node4_2 = create_node(2, node4_3);
    node4_0 = create_node(0, node4_2);
    graph.adj_list[4] = node4_0;

    init_visited(visited);
    dfs_list(&graph, 0);
    printf("\n");

    init_visited(visited);
    bfs_list(&graph, 0);
    printf("\n");

    return 0;
}
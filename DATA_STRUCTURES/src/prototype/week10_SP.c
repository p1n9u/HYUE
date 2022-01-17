// kruskal

int parent[MAX_VERTICES]; 
int num[MAX_VERTICES]; 

void set_init(int n) { 
    for ( int i=0; i<n; i++ ) { 
        parent[i] = -1;
        num[i] = 1;
    }
}

int set_find(int vertex) { 
    int p, s, i=-1;
    for ( i=vertex; (p=parent[i])>=0; i=p ) ; 
    s = i; 
    for( i=vertex; (p=parent[i])>=0; i=p) {
        parent[i] = s;
    } 
    return s;
}

void set_union(int s1, int s2) { 
    if( num[s1] < num[s2] ) {
        parent[s1] = s2; 
        num[s2] += num[s1]; 
    } else {
        parent[s2] = s1;
        num[s1] += num[s2];
    }
}

void kruskal(int n) { 
    int edge_accepted = 0;
    HeapType h; 
    int uset, vset;  
    element e;  
    init(&h);  
    insert_all_edges(&h);  
    set_init(n); 
    while( edge_accepted < (n-1) ) { 
        e = delete_min_heap(&h);
        uset = set_find(e.u); 
        vset = set_find(e.v); 
        if( uset != vset ) {  
            printf("(%d,%d) %d \n",e.u, e.v, e.key); 
            edge_accepted++; 
            set_union(uset, vset);
        }
    }
}

int main(void) {
    kruskal(7);
}

// Prim

#include <stdio.h> 
#define TRUE 1 
#define FALSE 0 
#define MAX_VERTICES 7 
#define INF 1000L

int weight[MAX_VERTICES][MAX_VERTICES]={ 
    { 0, 29, INF, INF, INF, 10, INF }, 
    { 29, 0, 16, INF, INF, INF, 15 }, 
    { INF, 16, 0, 12, INF, INF, INF }, 
    { INF, INF, 12, 0, 22, INF, 18 }, 
    { INF, INF, INF, 22, 0, 27, 25 }, 
    { 10, INF, INF, INF, 27, 0, INF }, 
    { INF, 15, INF, 18, 25, INF, 0 }}; 

int selected[MAX_VERTICES]; 
int dist[MAX_VERTICES];

int get_min_vertex(int n) { 
    int v,i;
    for (i = 0; i <n; i++) {
        if (!selected[i]) { 
            v = i; 
            break;
        }
    } 
    for (i = 0; i < n; i++) {
        if ( !selected[i] && (dist[i] < dist[v])) {
            v = i;
        }
    } 
    return (v);
}

void prim(int s, int n) { 
    int i, u, v;
    for(u=0;u<n;u++) { 
        dist[u]=INF;
        selected[u] = FALSE; 
    }
    dist[s]=0;
    for(i=0;i<n;i++) { 
        u = get_min_vertex(n);
        selected[u]=TRUE;
        if( dist[u] == INF ) {
            return;
        } 
        printf("%d ", u); 
        for( v=0; v<n; v++) { 
            if( weight[u][v]!= INF) { 
                if( !selected[v] && weight[u][v]< dist[v] ) {
                    dist[v] = weight[u][v];
                }
            }
        }
    }
}

int main(void) { 
    prim(0, MAX_VERTICES);
    return 0;
}

// Floyd

int A[MAX_VERTICES][MAX_VERTICES];

void floyd(int n) { 
    int i, j, k;
    for(i=0; i<n; i++) { 
        for(j=0; j<n; j++) { 
            A[i][j]=weight[i][j];
        }
    }
    
    for(k=0; k<n; k++) {
        for(i=0; i<n; i++) { 
            for(j=0; j<n; j++) { 
                if (A[i][k]+A[k][j] < A[i][j]) { 
                    A[i][j] = A[i][k]+A[k][j];
                }
            }
        }
    }
}

// dijkstra

#include <stdio.h> 
#include <limits.h> 
#define TRUE 1 
#define FALSE 0 
#define MAX_VERTICES 7  
#define INF 1000  

int weight[MAX_VERTICES][MAX_VERTICES]={  
    { 0, 7, INF, INF, 3, 10, INF }, 
    { 7, 0, 4, 10, 2, 6, INF }, 
    { INF, 4, 0, 2, INF, INF, INF }, 
    { INF, 10, 2, 0, 11, 9, 4 }, 
    { 3, 2, INF, 11, 0, INF, 5 }, 
    { 10, 6, INF, 9, INF, 0, INF }, 
    { INF, INF, INF, 4, 5, INF, 0 }}; 

int distance[MAX_VERTICES];  
int found[MAX_VERTICES]; 

int choose(int distance[], int n, int found[]) { 
    int i, min, minpos;
    min = INT_MAX; 
    minpos = -1; 
    for(i=0;i<n;i++) { 
        if( distance[i]< min && ! found[i] ){ 
            min = distance[i]; 
            minpos=i;
        }
    }
    return minpos;
}

void shortest_path(int start, int n) { 
    int i, u, w;
    for(i=0; i<n; i++) { 
        distance[i] = weight[start][i];
        found[i] = FALSE; 
    }
    found[start] = TRUE; // 시작 정점 방문 표시
    distance[start] = 0; 
    for(i=0; i<n-2; i++) { 
        u = choose(distance, n, found);
        found[u] = TRUE; 
        for(w=0;w<n; w++) { 
            if(!found[w]) {
                if( distance[u]+weight[u][w]<distance[w] ) { 
                    distance[w] = distance[u]+weight[u][w];
                }
            }
        }
    }
}

int main(void) { 
    shortest_path(0, MAX_VERTICES);
    return 0;
}

// dijkstra 2

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define INF 10000000
#define number 6

int arr[number][number] = {
    {0, 2, 5, 1, INF, INF},
    {2, 0, 3, 2, INF, INF},
    {5, 3, 0, 3, 1, 5},
    {1, 2, 3, 0, 1, INF},
    {INF, INF, 1, 1, 0, 2},
    {INF, INF, 5, INF, 2, 0}
};

int d[number];
bool v[number];

void dijkstra(int start) { 
    int k;

    for(int i=0; i<number; i++) { 
        d[i] = arr[start][i];
        v[i] = false; 
    }
    
    v[start] = true; 
    d[start] = 0; 

    for(int i=0; i<number-2; i++) { 
        int min, idx;
        min = INT_MAX; 
        idx = -1; 

        for(int j=0; j<number; j++) { 
            if( d[j] < min && !v[j] ){ 
                min = d[j]; 
                idx=j;
            } 
        }

        k = idx;
        v[k] = true;

        for(int j=0; j<number; j++) { 
            if( !v[j] ) { 
                if( d[k] + arr[k][j] < d[j] ) { 
                    d[j] = d[k]+arr[k][j];
                }
            }
        }
    }
}

void main() {
    dijkstra(0);
    for (int i=0; i<number; i++) {
        printf("%d ", d[i]);
    }
}
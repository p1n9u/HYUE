#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENT 100

typedef struct element {
    int key; 
} element; 

typedef struct HeapType { 
    element heap[MAX_ELEMENT]; 
    int heap_size; 
} HeapType;

void init(HeapType *h) {
    h->heap_size = 0;
}


int is_empty(HeapType *h) {
    return ( h->heap_size == 0 );
}

void insert_max_heap(HeapType *h, element item) { 
    int i;
    i = ++(h->heap_size);
    
    while( (i != 1) && (item.key > h->heap[i/2].key) ) {
        h->heap[i] = h->heap[i/2]; 
        i /= 2;
    } 
    h->heap[i] = item;
}

void insert_min_heap(HeapType *h, element item) {
    int i = ++(h->heap_size);
    
    while( (i != 1) && (item.key < (h->heap[i/2].key)) ) {
        h->heap[i] = h->heap[i/2];
        i /= 2;
    }
    
    h->heap[i] = item;
}

element delete_max_heap(HeapType *h) { 
    int parent, child;
    element item, temp;

    item = h->heap[1];
    temp = h->heap[(h->heap_size)--]; 
    parent = 1; 
    child = 2; 
    while( child <= h->heap_size ) { 
        if( ( child < h->heap_size ) && (h->heap[child].key) < h->heap[child+1].key ) { 
            child++;
        }
        if( temp.key >= h->heap[child].key ) {
            break;
        }
        h->heap[parent] = h->heap[child]; 
        parent = child; 
        child *= 2; 
    }
    h->heap[parent] = temp;
    return item;
}

element delete_min_heap(HeapType *h) {
    int parent, child; 
    element item, tmp; 
    item = h->heap[1]; 
    tmp = h->heap[(h->heap_size)--]; 
    parent = 1; 
    child = 2; 
    
    while( child <= h->heap_size ){ 
        if( ( child < h->heap_size ) && ((h->heap[child].key) > (h->heap[child+1].key)) ) {
            child++;
        }
        if( tmp.key <= h->heap[child].key ) {
         break;
        } 
        h->heap[parent] = h->heap[child]; 
        parent = child; 
        child *= 2;
    }
    h->heap[parent] = tmp; 
    return item;
}

void heap_sort(element a[], int n) {
    int i;
    HeapType h;

    init(&h);
    for(i=0;i<n;i++) {
        insert_max_heap(&h, a[i]);
    }
    for(i=(n-1);i>=0;i--){
        a[i] = delete_max_heap(&h);
    }
}

void pre_order(HeapType *h, int i) {
    if ( i <= h->heap_size ) {
        printf("%d ", h->heap[i].key);
        pre_order(h, i*2);
        pre_order(h, i*2+1);
    }
}

int main(void) {
    element e1={9}, e2={8}, e3={6}, e4={7}, e5={3}, e6={2}, e7={5}, e8={1}, e9={4};
	HeapType heap;
	init(&heap); 
	insert_max_heap(&heap, e1); 
	insert_max_heap(&heap, e2); 
	insert_max_heap(&heap, e3);
	insert_max_heap(&heap, e4);
    insert_max_heap(&heap, e5);
    insert_max_heap(&heap, e6);
    insert_max_heap(&heap, e7);
    insert_max_heap(&heap, e8);
    insert_max_heap(&heap, e9);
    printf("pre_order : ");
    pre_order(&heap, 1);
    printf("\n");
	delete_max_heap(&heap);
    printf("pre_order : ");
    pre_order(&heap, 1);
    printf("\n");
    return 0;
}
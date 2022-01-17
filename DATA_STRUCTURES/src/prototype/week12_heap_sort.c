#include <stdio.h>

#define MAX_ELEMENT 200

typedef struct element {
    int key; 
} element; 

typedef struct HeapType { 
    element heap[MAX_ELEMENT]; 
    int heap_size; 
} HeapType;

void init(HeapType *h) { 
    h->heap_size =0;
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
    int i;
    i = ++(h->heap_size);
    while( (i != 1) && (item.key < h->heap[i/2].key) ){
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
        if ( ( child < h->heap_size ) && (h->heap[child].key) < h->heap[child+1].key ) {
            child++;
        }
        if ( temp.key >= h->heap[child].key ) {
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
    element item, temp; 
    
    item = h->heap[1]; 
    temp = h->heap[(h->heap_size)--]; 
    parent = 1; 
    child = 2; 

    while( child <= h->heap_size ){ 
        if( ( child < h->heap_size ) && (h->heap[child].key) > h->heap[child+1].key) {
            child++;
        }
        if( temp.key <= h->heap[child].key ) {
            break;
        } 
        h->heap[parent] = h->heap[child]; 
        parent = child; 
        child *= 2;
    }
    h->heap[parent] = temp; 
    return item;
}

void heap_sort_max(element a[], int n) {
    HeapType h;
    init(&h);
    for( int i=0; i<n; i++ ){
        insert_max_heap(&h, a[i]);
    }
    for( int i=(n-1); i>=0; i-- ){
        a[i] = delete_max_heap(&h);
    }
}

void heap_sort_min(element a[], int n) {
    HeapType h;
    init(&h);
    for( int i=0; i<n; i++ ){
        insert_min_heap(&h, a[i]);
    }
    for( int i=(n-1); i>=0; i-- ){
        a[i] = delete_min_heap(&h);
    }
}

int main(void) {
    element arr1[5] = {1, 6, 7, 3, 9};
    element arr2[5] = {1, 8, 4, 2, 7};

    printf("initial array 1\n");
    for ( int i=0; i<5; i++ ) {
        printf("%d ", arr1[i].key);
    }
    printf("\n");

    printf("sorted array 1\n");
    heap_sort_min(arr1, 5);
    for ( int i=0; i<5; i++ ) {
        printf("%d ", arr1[i].key);
    }
    printf("\n");

    printf("initial array 2\n");
    for ( int i=0; i<5; i++ ) {
        printf("%d ", arr2[i].key);
    }
    printf("\n");

    printf("sorted array 2\n");
    heap_sort_max(arr2, 5);
    for ( int i=0; i<5; i++ ) {
        printf("%d ", arr2[i].key);
    }
    printf("\n");

    return 0;
}
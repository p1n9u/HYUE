#include <stdio.h>
#include <stdlib.h>

#define MAX_HEAP_SIZE 10

typedef struct element {
    int key;
} element;

typedef struct HeapType {
    element heap[MAX_HEAP_SIZE];
    int heap_size;
} HeapType;

void init(HeapType *H) {
    H->heap_size = 0;
}

void insert_max_heap(HeapType *H, element item) {
    int i = ++(H->heap_size);
    while ( (i != 1) && (item.key > H->heap[i/2].key) ) {
        H->heap[i] = H->heap[i/2];
        i /= 2;
    }
    H->heap[i] = item;
}

element delete_max_heap(HeapType *H) {
    int p=1, c=2;
    element item = H->heap[1], tmp = H->heap[(H->heap_size)--];
    while ( c <= H->heap_size ) {
        if ( (c < H->heap_size) && (H->heap[c].key < H->heap[c+1].key) ) {
            c++;
        }
        if ( tmp.key >= H->heap[c].key ) {
            break;
        } else {
            H->heap[p] = H->heap[c];
            p = c;
            c *= 2;
        }
    }
    H->heap[p] = tmp;
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


int main(void) {
    element arr[5] = {1, 6, 7, 3, 9};

    printf("initial array 2\n");
    for ( int i=0; i<5; i++ ) {
        printf("%d ", arr[i].key);
    }
    printf("\n");

    printf("sorted array 2\n");
    heap_sort_max(arr, 5);
    for ( int i=0; i<5; i++ ) {
        printf("%d ", arr[i].key);
    }
    printf("\n");

    return 0;
}
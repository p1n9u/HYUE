#include <stdio.h>
#include <stdlib.h>

typedef int element; 

typedef struct DequeNode { 
    element data;
    struct DequeNode *llink;
    struct DequeNode *rlink;
} DequeNode;

typedef struct DequeType { 
    DequeNode *head, *tail;
} DequeType;

void init(DequeType *dq){
    dq->head = NULL;
    dq->tail =NULL;
}

int is_empty(DequeType *dq){
    return ( ( dq->head == NULL ) && ( dq->tail == NULL ) );
}

DequeNode *create_node(DequeNode *llink, element data, DequeNode *rlink){
    DequeNode *new_node = (DequeNode *)malloc(sizeof(DequeNode));
    if ( new_node == NULL ) {
        perror("malloc error!\n");
    } else {
        new_node->data = data;
        new_node->llink = llink;
        new_node->rlink = rlink;
        return new_node;
    }
}

void add_front(DequeType *dq, element item) {
    DequeNode *new_node = create_node(NULL, item, dq->head);
    if( is_empty(dq) ) {
        dq->head = new_node;
        dq->tail = new_node;
    } else {
        dq->head->llink = new_node;
        dq->head = new_node;
    }
}

void add_rear(DequeType *dq, element item) {
    DequeNode *new_node = create_node(dq->tail, item, NULL);
    if( is_empty(dq) ) {
        dq->head = new_node;
        dq->tail = new_node;
    } else {
        dq->tail->rlink = new_node;
        dq->tail = new_node;
    }
}

element delete_front(DequeType *dq) {
    element item;
    DequeNode *removed_node;
    if ( is_empty(dq) ) { 
        perror("Deque Underflow!\n"); 
    } else {
        removed_node = dq->head; 
        item = removed_node->data;  
        dq->head = dq->head->rlink; 
        free(removed_node);  
        if (dq->head == NULL) {
            dq->tail = NULL;
        } else { 
            dq->head->llink=NULL;
        }
    }
    return item;
}

element delete_rear(DequeType *dq) {
    element item;
    DequeNode *removed_node;
    if ( is_empty(dq) ) {
        perror("Deque Underflow!\n"); 
    } else {
        removed_node = dq->tail;   
        item = removed_node->data;  
        dq->tail = dq->tail->llink; 
        free(removed_node);  
        if (dq->tail == NULL) {
            dq->head = NULL;
        } else { 
            dq->tail->rlink=NULL;
        }
    }
    return item;
}

int main(void) {
    DequeType deque;
    init(&deque);
    delete_front(&deque);
    delete_rear(&deque);
    add_front(&deque, 1);
    add_rear(&deque, 2);
    add_front(&deque, 3);
    add_rear(&deque, 4);
    add_front(&deque, 5);
    add_rear(&deque, 6);
    printf("deque front : %d\n", delete_front(&deque));
    printf("deque rear : %d\n", delete_rear(&deque));
    printf("deque front : %d\n", delete_front(&deque));
    printf("deque rear : %d\n", delete_rear(&deque));
    printf("deque front : %d\n", delete_front(&deque));
    printf("deque rear : %d\n", delete_rear(&deque));
    return 0;
}
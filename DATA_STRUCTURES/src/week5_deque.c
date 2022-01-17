#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct DequeNode {
    element data;
    struct DequeNode *llink, *rlink;
} DequeNode;

typedef struct DequeType {
    DequeNode *head, *tail;
} DequeType;

DequeNode *create_node(element item, DequeNode *llink, DequeNode *rlink) {
    DequeNode *new_node = (DequeNode *)malloc(sizeof(DequeNode));
    if ( new_node == NULL ) {
        perror("malloc error");
    } else {
        new_node->data = item;
        new_node->llink = llink;
        new_node->rlink = rlink;
        return new_node;
    }
}

void init(DequeType *DQ) {
    DQ->head = NULL;
    DQ->tail = NULL;
}

int is_empty(DequeType *DQ) {
    return (DQ->head == NULL && DQ->tail == NULL);
}

void add_front(DequeType *DQ, element item) {
    if ( is_empty(DQ) ) {
        DequeNode *new_node = create_node(item, NULL, NULL);
        DQ->head = new_node;
        DQ->tail = new_node;
    } else {
        DequeNode *new_node = create_node(item, NULL, DQ->head);
        DQ->head->llink = new_node;
        DQ->head = new_node;
    }
}

void add_rear(DequeType *DQ, element item) {
    if ( is_empty(DQ) ) {
        DequeNode *new_node = create_node(item, NULL, NULL);
        DQ->head = new_node;
        DQ->tail = new_node;
    } else {
        DequeNode *new_node = create_node(item, DQ->tail, NULL);
        DQ->tail->rlink = new_node;
        DQ->tail = new_node;
    }
}

element delete_front(DequeType *DQ) {
    if ( is_empty(DQ) ) {
        perror("error");
    } else {
        DequeNode *tmp = DQ->head;
        element item = tmp->data;
        DQ->head = tmp->rlink;
        if ( DQ->head == NULL ) {
            DQ->tail = NULL;
        } else {
            DQ->head->llink = NULL;
        }
        free(tmp);
        return item;
    }
}

element delete_rear(DequeType *DQ) {
    if ( is_empty(DQ) ) {
        perror("error");
    } else {
        DequeNode *tmp = DQ->tail;
        element item = tmp->data;
        DQ->tail = tmp->llink;
        if ( DQ->tail == NULL ) {
            DQ->head = NULL;
        } else {
            DQ->tail->rlink = NULL;
        }
        free(tmp);
        return item;
    }
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
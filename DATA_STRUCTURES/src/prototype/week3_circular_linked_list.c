#include <stdio.h>
#include <stdlib.h>

typedef int element; 
typedef struct ListNode { 
    element data;
    struct ListNode *link; 
} ListNode;

ListNode *create_node(element item, ListNode *link) {
    ListNode *new_node = (ListNode *)malloc(sizeof(ListNode));
    if ( new_node == NULL ){
        perror("malloc error!\n");
    } else {
        new_node->data = item;
        new_node->link = link;
        return new_node;
    }
}

void insert_first(ListNode **phead, ListNode *new_node) { 
    if( *phead == NULL ){
        *phead = new_node; 
        new_node->link = new_node; 
    } else {
        new_node->link = (*phead)->link;
        (*phead)->link = new_node;
    }
}

void insert_last(ListNode **phead, ListNode *new_node) { 
    if( *phead == NULL ){
        *phead = new_node; 
        new_node->link = new_node; 
    } else {
        new_node->link = (*phead)->link;
        (*phead)->link = new_node;
        *phead = new_node;
    }
}
#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct StackNode {
    element item;
    struct StackNode *link;
} StackNode;

typedef struct StackType {
    StackNode *top; 
} StackType;

void init(StackType *s) {
    s->top == NULL;
}

int is_empty(StackType *s) { 
    return (s->top == NULL); 
} 

void push(StackType *s, element item) {
    StackNode *new_node = (StackNode *)malloc(sizeof(StackNode));
    if ( new_node == NULL ) {
        perror("malloc error!\n");
    } else {
        new_node->item = item;
        new_node->link = s->top;
        s->top = new_node;
    }
} 

element pop(StackType *s) {
    if( is_empty(s) ) {
        perror("Stack Under Flow\n");
    } else {
        StackNode *tmp = s->top;
        element item = tmp->item;
        s->top = s->top->link;
        free(tmp);
        return item;
    } 
}

element peek(StackType *s) { 
    if( is_empty(s) ) {
        perror("Stack Under Flow\n");
    } else {
        element item = s->top->item;
        return item;
    } 
} 

int main(void) {
    StackType stack;
    init(&stack);
    printf("is empty : %d\n", is_empty(&stack));
    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    push(&stack, 4);
    push(&stack, 5);
    push(&stack, 6);
    printf("peek : %d\n", peek(&stack));
    printf("pop : %d\n", pop(&stack));
    printf("peek : %d\n", peek(&stack));
    return 0;
}
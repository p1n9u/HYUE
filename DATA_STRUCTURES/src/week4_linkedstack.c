#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct StackNode {
    element data;
    struct StackNode *link;
} StackNode;

typedef struct StackType {
    StackNode *top;
} StackType;

void init(StackType *S) {
    S->top = NULL;
}

StackType *create_stack(void) {
    StackType *new_stack = (StackType *)malloc(sizeof(StackType));
    if ( new_stack == NULL ) {
        perror("malloc error");
    } else {
        init(new_stack);
        return new_stack;
    }
}

int is_empty(StackType *S) {
    return (S->top == NULL);
}

void push(StackType *S, element item) {
    StackNode *new_node = (StackNode *)malloc(sizeof(StackNode));
    if ( new_node == NULL ) {
        perror("malloc error");
    } else {
        new_node->link = S->top;
        new_node->data = item;
        S->top = new_node;
    }
}

element pop(StackType *S) {
    if ( is_empty(S) ) {
        perror("stack underflow");
    } else {
        StackNode *tmp = S->top;
        element item = tmp->data;
        S->top = tmp->link;
        free(tmp);
        return item;
    }
}

element peek(StackType *S) {
    if ( is_empty(S) ) {
        perror("error");
    } else {
        return (S->top->data);
    }
}

int main(void) {
    StackType *stack = create_stack();
    printf("is empty : %d\n", is_empty(stack));
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    push(stack, 4);
    push(stack, 5);
    push(stack, 6);
    printf("peek : %d\n", peek(stack)); // 6
    printf("pop : %d\n", pop(stack)); // 6
    printf("peek : %d\n", peek(stack)); // 5
    return 0;
}
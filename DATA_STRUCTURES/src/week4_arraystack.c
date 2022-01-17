#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 5

typedef int element;

typedef struct StackType {
    element stack[MAX_STACK_SIZE];
    int top;
} StackType;

void init(StackType *S) {
    S->top = -1;
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
    return (S->top == -1);
}

int is_full(StackType *S) {
    return (S->top == MAX_STACK_SIZE-1);
}

void push(StackType *S, element item) {
    if ( is_full(S) ) {
        perror("error");
    } else {
        S->stack[++S->top] = item;
    }
}

element pop(StackType *S) {
    if ( is_empty(S) ) {
        perror("error");
    } else {
        return S->stack[S->top--];
    }
}

element peek(StackType *S) {
    if ( is_empty(S) ) {
        perror("error");
    } else {
        return S->stack[S->top];
    }
}

void display(StackType *S) {
    printf("=====  top  =====\n");
    for ( int i=S->top; i>-1; i-- ) {
        printf("|%8d       |\n", S->stack[i]);
    }
    printf("===  bottom   ===\n");
}

int main(void) {
    StackType *stack = create_stack();
    display(stack);
    push(stack, 1);
    display(stack);
    push(stack, 2);
    display(stack);
    push(stack, 3);
    display(stack);
    push(stack, 4);
    display(stack);
    push(stack, 5);
    display(stack);
    push(stack, 6);
    display(stack);
    pop(stack);
    display(stack);
    push(stack, 7);
    display(stack);
    push(stack, 8);
    display(stack);
    return 0;
}
#include <stdio.h>

#define MAX_STACK_SIZE 5

typedef int element;

typedef struct StackType {
    element stack[MAX_STACK_SIZE];
    int top;
} StackType;

void init(StackType *s) {
    s->top = -1;
}

int is_empty(StackType *s) { 
    return (s->top == -1); 
} 

int is_full(StackType *s) { 
    return (s->top == (MAX_STACK_SIZE-1));
}

void push(StackType *s, element item) {
    if( is_full(s) ) {
        perror("Stack Over Flow\n");
    } else {
        s->stack[++(s->top)] = item;
    } 
} 

element pop(StackType *s) {
    if( is_empty(s) ) {
        perror("Stack Under Flow\n");
    } else {
        return s->stack[(s->top)--];
    } 
}

element peek(StackType *s) { 
    if( is_empty(s) ) {
        perror("Stack Under Flow\n");
    } else {
        return s->stack[s->top];
    } 
} 

int main(void) {
    StackType stack;
    init(&stack);
    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    push(&stack, 4);
    push(&stack, 5);
    push(&stack, 6);
    pop(&stack);
    push(&stack, 7);
    push(&stack, 8);
    return 0;
}
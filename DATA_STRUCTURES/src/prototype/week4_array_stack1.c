#include <stdio.h>

#define MAX_STACK_SIZE 5

typedef int element;

element stack[MAX_STACK_SIZE]; 
int top = -1; 

int is_empty() { 
    return (top == -1); 
} 

int is_full() { 
    return (top == (MAX_STACK_SIZE-1));
}

void push(element item) {
    if( is_full() ) {
        perror("Stack Over Flow!\n");
    } else {
        stack[++top] = item;
    } 
} 

element pop() {
    if( is_empty() ) {
        perror("Stack Under Flow!\n");
    } else {
        return stack[top--];
    } 
}

element peek() { 
    if( is_empty() ) {
        perror("Stack Under Flow!\n");
    } else {
        return stack[top];
    } 
}

int main(void) {
    pop();
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);
    pop();
    pop();
    push(7);
    push(8);
    push(9);
    return 0;
}
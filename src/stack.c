#include "stack.h"
#include <stdio.h>


void create_stack(Stack *stack) {
    stack->top = 0;
}

int is_empty(Stack *stack) {
    return stack->top == 0;
}

int is_full(Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(Stack *stack, uint16_t value) {

    if (!is_full(stack)) {
        stack->arr[stack->top] = value;
        stack->top++; 
    }

}

uint16_t peek(Stack *stack) {

    if (stack->top > 0) {
        uint16_t ret = stack->arr[stack->top - 1];
        return ret;
    }

    return 999;

}

uint16_t pop(Stack *stack) {

    if (!is_empty(stack)) {
        uint16_t ret = peek(stack);
        stack->top--;
        return ret;
    }

    else printf("Empty Stack");
    return 999;
}

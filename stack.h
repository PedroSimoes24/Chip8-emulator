#ifndef STACK_H
#define STACK_H

#include <stdint.h>

#define MAX_SIZE 32

typedef struct Stack {
    uint16_t arr[MAX_SIZE];
    int top;

} Stack;

void create_stack(Stack *stack);

int is_empty(Stack *stack);

int is_full(Stack *stack);

void push(Stack *stack, uint16_t value);

uint16_t peek(Stack *stack);

uint16_t pop(Stack *stack);

#endif
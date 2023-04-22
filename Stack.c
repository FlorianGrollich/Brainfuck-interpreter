//
// Created by F-Gro on 22.04.2023.
//

#include <stdio.h>
#include "Stack.h"

void init_stack(Stack *stack) {
    stack->top = -1;
}

int is_empty(Stack *stack) {
    return stack->top == -1;
}

int is_full(Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(Stack *stack, struct Node* element) {
    if (is_full(stack)) {
        printf("Stack is full. Cannot push element.\n");
    } else {
        stack->top++;
        stack->data[stack->top] = element;
    }
}

struct Node* pop(Stack *stack) {
    if (is_empty(stack)) {
        printf("Stack is empty. Cannot pop element.\n");
        return NULL;
    } else {
        struct Node* element = stack->data[stack->top];
        stack->top--;
        return element;
    }
}

struct Node* peek(Stack *stack) {
    if (is_empty(stack)) {
        printf("Stack is empty. Cannot get top element.\n");
        return NULL;
    } else {
        return stack->data[stack->top];
    }
}
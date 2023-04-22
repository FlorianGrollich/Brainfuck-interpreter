//
// Created by F-Gro on 22.04.2023.
//

#include <stdio.h>
#include "Stack.h"


// function to initialize the stack
void init_stack(Stack *stack) {
    stack->top = -1;
}

// function to check if the stack is empty
int is_empty(Stack *stack) {
    return stack->top == -1;
}

// function to check if the stack is full
int is_full(Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

// function to push an element onto the stack
void push(Stack *stack, struct Node* element) {
    if (is_full(stack)) {
        printf("Stack is full. Cannot push element.\n");
    } else {
        stack->top++;
        stack->data[stack->top] = element;
    }
}

// function to pop an element from the stack
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

// function to get the top element of the stack
struct Node* peek(Stack *stack) {
    if (is_empty(stack)) {
        printf("Stack is empty. Cannot get top element.\n");
        return NULL;
    } else {
        return stack->data[stack->top];
    }
}
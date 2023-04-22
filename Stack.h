//
// Created by F-Gro on 22.04.2023.
//

#ifndef BRIANFUCK_INTERPRETER_STACK_H
#define BRIANFUCK_INTERPRETER_STACK_H


#define MAX_SIZE 100

typedef struct Stack {
    int data[MAX_SIZE];
    int top;
} Stack;


int peek(Stack *stack);

int pop(Stack *stack);

void push(Stack *stack, int element);

int is_full(Stack *stack);

void init_stack(Stack *stack);

#endif //BRIANFUCK_INTERPRETER_STACK_H

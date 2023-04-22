//
// Created by F-Gro on 22.04.2023.
//

#ifndef BRIANFUCK_INTERPRETER_STACK_H
#define BRIANFUCK_INTERPRETER_STACK_H

#include "brainfuck.h"

#define MAX_SIZE 100

typedef struct Stack {
    struct Node* data[MAX_SIZE];
    int top;
} Stack;

void push(Stack* stack, struct Node* node);

struct Node* pop(Stack* stack);

void init_stack(Stack* stack);



#endif //BRIANFUCK_INTERPRETER_STACK_H

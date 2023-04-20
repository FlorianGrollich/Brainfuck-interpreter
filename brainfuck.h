//
// Created by F-Gro on 20.04.2023.
//

#ifndef BRIANFUCK_INTERPRETER_BRAINFUCK_H
#define BRIANFUCK_INTERPRETER_BRAINFUCK_H

#define TAPE_SIZE 30000

enum TokenType {
    INCREMENT, // +
    DECREMENT, // -
    LEFT,   // <
    RIGHT,  // >
    INPUT,  // ,
    OUTPUT, // .
    LOOP_START, // [
    LOOP_END // ]
};


struct Node {
    enum TokenType type;
    struct Node *next;
};

#endif //BRIANFUCK_INTERPRETER_BRAINFUCK_H

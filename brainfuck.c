#include <stdio.h>
#include <stdlib.h>

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
}

struct Token



int main() {
    unsigned char tape[TAPE_SIZE] = {0};
    //pointer to the current cell
    char prt = 0;


    return 0;
}

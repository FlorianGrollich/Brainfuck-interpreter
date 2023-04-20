#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "brainfuck.h"

enum TokenType getType(char input) {
    switch (input) {
        case '<':
            return LEFT;
        case '>':
            return RIGHT;
        case '+':
            return INCREMENT;
        case '-':
            return DECREMENT;
        case ',':
            return INPUT;
        case '.':
            return OUTPUT;
        case '[':
            return LOOP_START;
        case ']':
            return LOOP_END;
        default:
            break;
    }
}


struct Node parsing(char* input) {
    for(int i = 0; i < strlen(input); i++) {



    }

}



int main() {
    unsigned char tape[TAPE_SIZE] = {0};
    //pointer to the current cell
    char prt = 97;



    return 0;
}

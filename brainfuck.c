#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "brainfuck.h"
#include "Stack.h"


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
            return COMMENT;
    }
}


struct Node* createNode(char input) {
    struct Node* node = malloc(sizeof(struct Node));
    node->type = getType(input);
    node->next = NULL;
    node->parent = NULL;
    return node;
}


struct Node* parsing(char* input) {
    struct Node* head = NULL;
    struct Node* prevNode = NULL;
    Stack loopStack;
    init_stack(&loopStack);
    for (int i = 0; input[i] != '\0'; i++) {
        struct Node* currentNode = createNode(input[i]);
        if (prevNode != NULL) {
            prevNode->next = currentNode;
        }
        prevNode = currentNode;
        if (head == NULL) {
            head = currentNode;
        }
        if(currentNode->type == LOOP_START) {
            push(&loopStack, currentNode);
        }
    }
    return head;
}

int main() {
    unsigned char tape[TAPE_SIZE] = {0};
    //pointer to the current cell
    char* input = "+[++[--]]<.";
    struct Node* head = parsing(input);
    struct Node* currentNode = head;
    while (currentNode != NULL) {
        printf("%d ", currentNode->type);
        currentNode = currentNode->next;
    }
    return 0;
}

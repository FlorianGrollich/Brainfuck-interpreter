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
    node->loopStart = NULL;
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
        if(currentNode->type == LOOP_END) {
            struct Node* loopStart = pop(&loopStack);
            loopStart->loopEnd = currentNode;
            currentNode->loopStart = loopStart;

        }
    }
    return head;
}


void execute_code(struct Node* head) {
    unsigned char tape[TAPE_SIZE] = {0};
    int tapeIndex = 0;
    struct Node* currentNode = head;
    while (currentNode != NULL) {
        switch (currentNode->type) {
            case INCREMENT:
                tape[tapeIndex]++;
                break;
            case DECREMENT:
                tape[tapeIndex]--;
                break;
            case LEFT:
                if(tapeIndex == 0) {
                    tapeIndex = TAPE_SIZE - 1;
                } else {
                    tapeIndex--;
                }
                break;
            case RIGHT:
                if(tapeIndex == TAPE_SIZE - 1) {
                    tapeIndex = 0;
                } else {
                    tapeIndex++;
                }
                break;
            case INPUT:
                scanf("%c", tape);
                break;
            case OUTPUT:
                printf("%c", tape[tapeIndex]);
                break;
            case LOOP_START:
                if (tape[tapeIndex] == 0) {
                    currentNode = currentNode->loopEnd;
                }
                break;
            case LOOP_END:
                if (tape[tapeIndex] != 0) {
                    currentNode = currentNode->loopStart;
                }
                break;
            default:
                break;
        }
        currentNode = currentNode->next;
    }
}

int main() {
    unsigned char tape[TAPE_SIZE] = {0};
    char* input = "-[------->+<]>---.--[--->+<]>.+++.+++.---------.--------.+++++++++++++.";
    struct Node* head = parsing(input);
    execute_code(head);
    return 0;
}

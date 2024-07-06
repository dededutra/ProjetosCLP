#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define STACK_SIZE 100

int stack[STACK_SIZE];
int top = -1;

void push(int value) {
    if (top >= STACK_SIZE - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    stack[++top] = value;
}

int pop() {
    if (top < 0) {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack[top--];
}


void expr();
void rexpr();
void term();
void rterm();
void factor();


char *input;
char lookahead;

void nextToken() {
    lookahead = *input++;
}

void match(char token) {
    if (lookahead == token) {
        nextToken();
    } else {
        printf("Syntax error: expected %c\n", token);
        exit(1);
    }
}

void expr() {
    term();
    rexpr();
}

void rexpr() {
    if (lookahead == '+') {
        match('+');
        expr();
        int y = pop();
        int x = pop();
        printf("OPR 0 2\n");
        push(x + y);
    } else if (lookahead == '-') {
        match('-');
        expr();
        int y = pop();
        int x = pop();
        printf("OPR 0 3\n");
        push(x - y);
    }
}

void term() {
    factor();
    rterm();
}

void rterm() {
    if (lookahead == '*') {
        match('*');
        term();
        int y = pop();
        int x = pop();
        printf("OPR 0 4\n");
        push(x * y);
    } else if (lookahead == '/') {
        match('/');
        term();
        int y = pop();
        int x = pop();
        printf("OPR 0 5\n");
        push(x / y);
    }
}

void factor() {
    if (isalpha(lookahead)) {
        if (lookahead == 'a') {
            printf("LIT 0 3\n");
            push(lookahead - 'a' + 1);
            nextToken();
        } else if (lookahead == 'b') {
            printf("LIT 0 4\n");
            push(lookahead - 'a' + 1);
            nextToken();
        } else if (lookahead == 'c') {
            printf("LIT 0 5\n");
            push(lookahead - 'a' + 1);
            nextToken();
        } else if (lookahead == 'd') {
            printf("LIT 0 6\n");
            push(lookahead - 'a' + 1);
            nextToken();
        } else if (lookahead == 'e') {
            printf("LIT 0 7\n");
            push(lookahead - 'a' + 1);
            nextToken();
        }
    } else if (lookahead == '(') {
        match('(');
        expr();
        match(')');
    } else {
        printf("Syntax error: unexpected character %c\n", lookahead);
        exit(1);
    }
}

int main() {
    char inputString[10000];
    fgets(inputString, sizeof(inputString), stdin);
    for (int i = 0;i< 10000;i++)
    {
        if (inputString[i] == '\n') inputString[i] = '\0';
    }
    input = inputString;
    printf("INT 0 8\n");
    nextToken();
    expr();
    printf("OPR 0 0\n");
    if (lookahead != '\0') {
        printf("Syntax error: unexpected character %c\n", lookahead);
    }
    return 0;
}

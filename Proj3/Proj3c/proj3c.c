#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
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
    if (isdigit(lookahead)) {
        int num = 0;
        while (isdigit(lookahead)) {
            num = num * 10 + (lookahead - '0');
            nextToken();
        }
        printf("LIT 0 %d\n", num);
        push(num);
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
    FILE *file = fopen("entrada.txt", "r");
    if (!file) {
        printf("Error opening file\n");
        return 1;
    }

    char inputString[10000];
    while (fgets(inputString, sizeof(inputString), file)) {
        inputString[strcspn(inputString, "\n")] = 0;

        input = inputString;
        top = -1;
        printf("INT 0 8\n");
        nextToken();
        expr();
        printf("OPR 0 0\n");
        if (lookahead != '\0') {
            printf("Syntax error: unexpected character %c\n", lookahead);
        }
    }

    fclose(file);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

// Definição da estrutura de dados para a pilha
typedef struct {
    char stack[MAX_STACK_SIZE];
    int top;
} Stack;

// Funções para manipulação da pilha
void push(Stack *s, char c) {
    if (s->top < MAX_STACK_SIZE - 1) {
        s->top++;
        s->stack[s->top] = c;
    } else {
        printf("Stack overflow!\n");
        exit(EXIT_FAILURE);
    }
}

void pop(Stack *s) {
    if (s->top >= 0) {
        s->top--;
    } else {
        printf("Stack underflow!\n");
        exit(EXIT_FAILURE);
    }
}

// Função para realizar a transição "S -> aSb"
void transition_aSb(Stack *s, Stack *a) {
    pop(s); // Pop 'S'
    push(s, 'b');
    push(s, 'S');
    push(s, 'a');

    push(a, 'b');// atualiza arvore
    push(a, 'S');
    push(a, 'a');
}

// Função para realizar a transição "S -> c"
void transition_c(Stack *s, Stack *a) {
    pop(s); // Pop 'S'
    push(s, 'c');

    push(a, '0');// atualiza arvore
    push(a, 'c');
    push(a, '0');
}

int main() {
    FILE *fp;
    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(EXIT_FAILURE);
    }

    Stack stack;
    stack.top = -1;
    Stack arv;
    arv.top = -1;

    // Estado inicial q0
    push(&stack, 'S'); // Inicializa a pilha com 'S'
    push(&arv, '0');
    push(&arv, 'S');
    push(&arv, '0');

    char token;
    token = fgetc(fp);
    while (1) {
        if (token == 'a' && stack.stack[stack.top] == 'S') {
            transition_aSb(&stack, &arv);
        } else if (token == 'a' && stack.stack[stack.top] == 'a') {
            pop(&stack); // Pop 'a'
            token = fgetc(fp);
        } else if (token == 'b' && stack.stack[stack.top] == 'b') {
            pop(&stack); // Pop 'b'
            token = fgetc(fp);
        } else if (token == 'c' && stack.stack[stack.top] == 'S') {
            transition_c(&stack, &arv);
        } else if (token == 'c' && stack.stack[stack.top] == 'c') {
            pop(&stack); // Pop 'c'
            token = fgetc(fp);
        } else if (token == EOF || 10) {
            break;
        } else {
            printf("%d Erro: Token inesperado!\n", token);
            fclose(fp);
            return EXIT_FAILURE;
        }
    }
    FILE *wfp;
    wfp = fopen("saida.txt", "w");
    for (int i = 0;i< arv.top;i++) fprintf(wfp,"%d",arv.stack[i]);
    fclose(fp);
    fclose(wfp);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Declaração das funções
int expr(char[], int*);
int term(char[], int*);
int factor(char[], int*);

// Função principal
int main() {
    char input[100]; // Supondo que a entrada não exceda 100 caracteres
    FILE* file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo input.txt.\n");
        return 1;
    }
    while(fgets(input, 100,file) != NULL) {
        input[ strcspn( input, "\n" ) ] = '\0';
        int index = 0;
        if(expr(input, &index) && input[index] == '\0') {
            printf("Expressão aceita!\n");
        } else {
            printf("Erro sintático!\n");
        }
    }
    fclose(file);
    return 0;
}

// Função para o símbolo não terminal <expr>
int expr(char input[], int* index) {
    if(term(input, index)) {
        while(input[*index] == '+' || input[*index] == '-') {
            (*index)++;
            if(!term(input, index)) {
                return 0;
            }
        }
        return 1;
    }
    return 0;
}

// Função para o símbolo não terminal <term>
int term(char input[], int* index) {
    if(factor(input, index)) {
        while(input[*index] == '*' || input[*index] == '/') {
            (*index)++;
            if(!factor(input, index)) {
                return 0;
            }
        }
        return 1;
    }
    return 0;
}

// Função para o símbolo não terminal <factor>
int factor(char input[], int* index) {
    if(isalnum(input[*index])) {
        // Avança até o próximo caractere não alfanumérico
        while(isalnum(input[*index])) {
            (*index)++;
        }
        return 1;
    } else if(input[*index] == '(') {
        (*index)++;
        if(expr(input, index)) {
            if(input[*index] == ')') {
                (*index)++;
                return 1;
            }
        }
    }
    return 0;
}

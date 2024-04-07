//André Dutra da Silva
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int analisarDecimal(char palavra[]) {
    int i = 0;
    char estado = '0'; // estado inicial

    while (palavra[i] != '\0') {
        switch (estado) {
            case '0':
                if (palavra[i] == '0')
                    estado = '1';
                else if (isdigit(palavra[i]) && palavra[i] != '0')
                    estado = '2';
                else
                    return 0; // Palavra não reconhecida
                break;
            case '1':
                if (isdigit(palavra[i]))
                    estado = '1';
                else if (palavra[i] == '.')
                    estado = '3';
                else
                    return 0; // Palavra não reconhecida
                break;
            case '2':
                if (isdigit(palavra[i]))
                    estado = '2';
                else if (palavra[i] == '.')
                    estado = '3';
                else
                    return 0; // Palavra não reconhecida
                break;
            case '3':
                if (isdigit(palavra[i]))
                    estado = '4';
                else
                    return 0; // Palavra não reconhecida
                break;
            case '4':
                if (isdigit(palavra[i]))
                    estado = '4';
                else
                    return 0; // Palavra não reconhecida
                break;
        }
        i++;
    }

    if (estado == '1' || estado == '2' || estado == '4')
        return 1; // Palavra reconhecida
    else
        return 0; // Palavra não reconhecida
}

int main() {
    FILE *arquivo;
    char palavra[100];

    // Abre o arquivo para leitura
    arquivo = fopen("test2.txt", "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    // Lê palavra por palavra e analisa
    while (fscanf(arquivo, "%s", palavra) != EOF) {
        if (analisarDecimal(palavra))
            printf("%s reconhecida\n", palavra);
        else
            printf("%s rejeitada\n", palavra);
    }

    // Fecha o arquivo
    fclose(arquivo);

    return 0;
}

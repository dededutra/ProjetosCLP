//André Dutra da Silva
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Função para analisar a palavra
int analisarPalavra(char palavra[]) {
    int i = 0;
    char estado = '0'; // estado inicial

    while (palavra[i] != '\0') {
        switch (estado) {
            case '0':
                if (palavra[i] == '0')
                    estado = '1';
                else if (palavra[i] == '1')
                    estado = '2';
                else
                    return 0; // Palavra não reconhecida
                break;
            case '1':
                if (palavra[i] == '0' || palavra[i] == '1')
                    estado = '1';
                else
                    return 0; // Palavra não reconhecida
                break;
            case '2':
                if (palavra[i] == '0' || palavra[i] == '1')
                    estado = '2';
                else
                    return 0; // Palavra não reconhecida
                break;
        }
        i++;
    }

    if (estado == '1' || estado == '2')
        return 1; // Palavra reconhecida
    else
        return 0; // Palavra não reconhecida
}

int main() {
    FILE *arquivo;
    char palavra[100];

    // Abre o arquivo para leitura
    arquivo = fopen("test1.txt", "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    // Lê palavra por palavra e analisa
    while (fscanf(arquivo, "%s", palavra) != EOF) {
        if (analisarPalavra(palavra))
            printf("%s reconhecida\n", palavra);
        else
            printf("%s rejeitada\n", palavra);
    }

    // Fecha o arquivo
    fclose(arquivo);

    return 0;
}

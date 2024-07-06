#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO 100
#define NUM_VETORES 1024

// Função para ordenação por inserção
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        /* Move os elementos do arr[0..i-1], que são maiores que a chave,
        para uma posição à frente de sua posição atual */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Função para gerar vetor aleatório
void generateRandomArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000; // Números aleatórios entre 0 e 9999
    }
}

int main() {
    srand(time(NULL)); // Inicializa o gerador de números aleatórios com a hora atual

    clock_t start, end;
    double cpu_time_used;

    // Arrays para armazenar os tempos de processamento
    double processing_times[ITERATIONS];

    for (int i = 0; i < ITERATIONS; i++) {
        int arr[SIZE];

        // Gerar vetor aleatório
        generateRandomArray(arr, SIZE);

        // Registrar o tempo inicial
        start = clock();

        // Ordenar o vetor usando o algoritmo de ordenação por inserção
        insertionSort(arr, SIZE);

        // Registrar o tempo final
        end = clock();

        // Calcular o tempo de processamento em segundos
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

        // Armazenar o tempo de processamento
        processing_times[i] = cpu_time_used;
    }

    // Imprimir os tempos de processamento
    for (int i = 0; i < ITERATIONS; i++) {
        printf("%f\n",processing_times[i]);
    }

    return 0;
}

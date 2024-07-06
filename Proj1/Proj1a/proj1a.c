#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 100
#define NUM 1024

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    srand(time(NULL));
    clock_t start, end;
    double cpu_time_used;
    double processing_times[NUM];
    for (int i = 0; i < NUM; i++) {
        int arr[TAM];
        for (int i = 0; i < TAM; i++) {
            arr[i] = rand() % 10000;
        }
        start = clock();
        insertionSort(arr, TAM);
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        processing_times[i] = cpu_time_used;
    }
    for (int i = 0; i < NUM; i++) {
        printf("%f\n",processing_times[i]);
    }

    return 0;
}

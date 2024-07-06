#include <stdio.h>

void insertion_sort(int arr[], int n) {
    int i, chave, j;
    for (i = 1; i < n; i++) {
        chave = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > chave) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = chave;
    }
}

int main() {
    int arr[10000];
    fgets(arr, sizeof(arr), stdin);
    for (int i = 0;i< 10000;i++)
    {
        if (arr[i] == '\n') arr[i] = '\0';
    }
    int n = sizeof(arr) / sizeof(arr[0]);
    insertion_sort(arr, n);
    printf("Array ordenado: \n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}

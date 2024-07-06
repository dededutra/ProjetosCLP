#include <stdio.h>
#include <time.h>

void trocar(int vet[], int i, int j);
void permutar(int vet[], int inicio, int fim);

int main()
{
    int n = 0;
    int vetor[50];
    clock_t inicio, fim;
    double tempo = 0.0;
    while(tempo < 70.00)
    {
        vetor[n] = n;
        n++; 
        inicio = clock();
        permutar(vetor, 0, (n - 1)); 
        fim = clock();

        tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
        printf("n = %d, tempo = %lf\n", n, tempo);
    }

    return 0;
}
void trocar(int vet[], int i, int j)
{
    int temp = vet[i];
    vet[i] = vet[j];
    vet[j] = temp;
}
void permutar(int vet[], int inicio, int fim)
{
    if(inicio != fim)
    {
        for(int i = inicio; i <= fim; i++)
        {
            trocar(vet, inicio, i);
            gerarPermutacoes(vet, inicio + 1, fim);
            trocar(vet, inicio, i);
        }
    }
}

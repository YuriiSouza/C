#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para gerar um array aleatório
void gerarArrayAleatorio(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000; // Números entre 0 e 9999
    }
}

// Função Bubble Sort
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Função Selection Sort
void selectionSort(int arr[], int n) {
    int i, j, min_idx, temp;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

// Função para medir o tempo de execução de um algoritmo de ordenação
double medirTempo(void (*sortFunction)(int[], int), int arr[], int n) {
    clock_t inicio, fim;
    int *copia = (int *)malloc(n * sizeof(int)); // Criamos uma cópia do array para cada teste

    for (int i = 0; i < n; i++) {
        copia[i] = arr[i]; // Copia os valores para manter o mesmo array em ambos os algoritmos
    }

    inicio = clock();
    sortFunction(copia, n);
    fim = clock();

    free(copia);
    return ((double)(fim - inicio)) / CLOCKS_PER_SEC; // Retorna o tempo em segundos
}

int main() {
    srand(time(NULL)); // Semente para gerar números aleatórios

    int tamanhos[] = {100, 1000, 5000, 10000}; // Diferentes tamanhos de entrada
    int num_testes = sizeof(tamanhos) / sizeof(tamanhos[0]);

    for (int i = 0; i < num_testes; i++) {
        int n = tamanhos[i];
        int *arr = (int *)malloc(n * sizeof(int));

        gerarArrayAleatorio(arr, n);

        printf("\nTamanho do array: %d elementos\n", n);
        printf("Bubble Sort: %.6f segundos\n", medirTempo(bubbleSort, arr, n));
        printf("Selection Sort: %.6f segundos\n", medirTempo(selectionSort, arr, n));

        free(arr);
    }

    return 0;
}


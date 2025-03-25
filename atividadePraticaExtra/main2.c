#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILMES 10
#define MAX_NOME 50

struct Filme {
    char nome[MAX_NOME];
    float avaliacao;
};

void BubbleSort(struct Filme *filmes, int size) {
    struct Filme temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (filmes[j].avaliacao < filmes[j + 1].avaliacao) {
                temp = filmes[j];
                filmes[j] = filmes[j + 1];
                filmes[j + 1] = temp;
            }
        }
    }
}

void imprimirFilmes(struct Filme *filmes, int size) {
    for (int i = 0; i < size; i++) {
        printf("Filme: %s, Avaliação: %.1f\n", filmes[i].nome, filmes[i].avaliacao);
    }
}

int main() {
    struct Filme filmes[MAX_FILMES];
    int size, escolha;

    printf("Quantos filmes deseja cadastrar? (Máx: %d): ", MAX_FILMES);
    scanf("%d", &size);
    
    for (int i = 0; i < size; i++) {
        printf("Digite o nome do filme %d: ", i + 1);
        scanf("%s", filmes[i].nome);
        
        printf("Digite a avaliação do filme (0 a 10): ");
        scanf("%f", &filmes[i].avaliacao);
    }
    
    printf("\nLista de filmes antes da ordenação:\n");
    imprimirFilmes(filmes, size);

    BubbleSort(filmes, size);
    printf("\nOrdenado com Bubble Sort:\n");


    imprimirFilmes(filmes, size);
    return 0;
}


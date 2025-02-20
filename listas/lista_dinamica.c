#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

void add_item(int value, int **array, int *size) {
    int *temp = (int*)realloc(*array, (*size + 1) * sizeof(int));

    if (temp == NULL) {
        printf("Erro ao realocar\n");
        return;
    }

    *array = temp;
    (*array)[*size] = value;
    (*size)++;
}

void remove_item(int index, int **array, int *size) {
    if (index < 0 || index >= *size) {
        printf("Índice inválido\n");
        return;
    }

    // Desloca os elementos para a esquerda
    for (int i = index; i < *size - 1; i++) {
        (*array)[i] = (*array)[i + 1];
    }

    // Realoca para diminuir o tamanho do array
    int *temp = (int*)realloc(*array, (*size - 1) * sizeof(int));
    
    // Se a realocação falhar, mantém o array atual
    if (temp != NULL || *size - 1 == 0) { 
        *array = temp;
    }

    (*size)--;
}

void search_item(int index, int *array, int size) {
    if (index < 0 || index >= size) {
        printf("Índice inválido\n");
        return;
    }
    printf("Elemento na posição %d: %d\n", index, array[index]);
}

void print_array(int *array, int size) {
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int *array = NULL;
    int size = 0;
    int selection;

    while (1) {
        printf("\nSelecione a opção:\n");
        printf("0 - Adicionar item\n");
        printf("1 - Remover item\n");
        printf("2 - Buscar item\n");
        printf("3 - Mostrar lista\n");
        printf("4 - Sair\n");
        printf("Opção: ");
        scanf("%d", &selection);

        switch (selection) {
            case 0: {
                int value;
                printf("Quer adicionar qual item? ");
                scanf("%d", &value);
                add_item(value, &array, &size); // CORRIGIDO
                break;
            }
            case 1: {
                int index;
                printf("Qual o índice do número que quer remover? ");
                scanf("%d", &index);
                remove_item(index, &array, &size); // CORRIGIDO
                break;
            }
            case 2: {
                int index;
                printf("Qual o índice do número que quer buscar? ");
                scanf("%d", &index);
                search_item(index, array, size);
                break;
            }
            case 3:
                print_array(array, size);
                break;
            case 4:
                printf("Saindo...\n");
                free(array);
                return 0;
            default:
                printf("Opção inválida!\n");
        }
    }

    return 0;
}

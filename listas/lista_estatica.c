#include <stdio.h>

#define MAX_SIZE 10

void add_item(int value, int *array, int *size) {
    if (*size < MAX_SIZE) {
        array[*size] = value;
        (*size)++;
    } else {
        printf("Erro: array cheio!\n");
    }
}

void remove_item(int index, int *array, int *size) {
    if (index < 0 || index >= *size) {
        printf("Erro: índice inválido!\n");
        return;
    }

    for (int i = index; i < (*size) - 1; i++) {
        array[i] = array[i + 1];
    }

    (*size)--;
    printf("Item removido com sucesso!\n");
}

void search_item(int index, int *array, int *size) {
    if (index < 0 || index >= *size) {
        printf("Erro: índice inválido!\n");
    } else {
        printf("Item encontrado: %d\n", array[index]);
    }
}

void print_array(int *array, int size) {
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int array[MAX_SIZE];
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
                add_item(value, array, &size);
                break;
            }
            case 1: {
                int index;
                printf("Qual o índice do número que quer remover? ");
                scanf("%d", &index);
                remove_item(index, array, &size);
                break;
            }
            case 2: {
                int index;
                printf("Qual o índice do número que quer buscar? ");
                scanf("%d", &index);
                search_item(index, array, &size);
                break;
            }
            case 3:
                print_array(array, size);
                break;
            case 4:
                printf("Saindo...\n");
                return 0;
            default:
                printf("Opção inválida!\n");
        }
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

//Bubble sort faz uma iteraćão da esquerda para a direita, comparando o valor com todos os outros numeros, ele tem notaćão Big O no melhor caso, quando bem otimizado de O(n) e no pior caso O(n²)
//O Bubble sort executa mais trocas que o Selection sort
int bubbleSort(int array[], int size) {
	int temp;

	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (array[j] > array[j + 1]) {
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
	}
}

void printArray(int arr[], int size) {
	for(int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

}

int main() {
	int arr[] = {64, 34, 25, 12, 22, 11, 90};
	int n = sizeof(arr) / sizeof(arr[0]);

	printf("Array antes da ordenaćão: \n");
	printArray(arr, n);

	bubbleSort(arr, n);

	printf("Array depois da ordenaćão: \n");
	printArray(arr, n);
	
	return 0;
}

//O insertionSort é um algoritmo que percorre a lista da esquerda para adireita, compara o elemento atual com os anteriores

#include <stdio.h>
#include <stdlib.h>

void insertionSort(int arr[], int size) {
	int temp;
	
	for (int i = 1; i < size; i++) {
		int key = arr[i];
		int j = i - 1;
		
		while (j >= 0 && arr[j] > key) {
			arr[j+1] = arr[j];
			j--;
		}

		arr[j + 1] = key;
		}
	}

void printArray(int arr[], int size) {
	for(int i = 0; i < size; i++) {
		printf("%d", arr[i]);
	}
	printf("\n");
}

int main(){
	int arr[] = {4,2,1,3,5};

	int size = sizeof(arr) / sizeof(arr[0]);

	insertionSort(arr, size);

	printArray(arr, size);

	return 0;
}

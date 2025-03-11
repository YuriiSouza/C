#include <stdio.h>
#include <stdlib.h>

//selection sort procura o menor valor e joga ele no comećo da lista,
void selectionSort(int arr[], int size){
	for (int i = 0; i < size - 1; i++) {
		int minIdx = i;
		for (int j = i + 1; j < size; j++) {
			if (arr[j] < arr[minIdx]) {
				minIdx = j;
			}
		}

		int temp = arr[i];
		arr[i] = arr[minIdx];
		arr[minIdx] = temp;
	}
}


void invert_selectionSort(int arr[], int size) {
	int temp;
	for (int i = 0; i < size - 1; i++) {
		int maxIdx = i;
		for (int j = i + 1; j < size; j ++) {
			if (arr[j] > arr[maxIdx]){
				maxIdx = j;
			}
		
			temp = arr[i];
			arr[i] = arr[maxIdx];
			arr[maxIdx] = temp;
		}
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

	invert_selectionSort(arr, size);

	printArray(arr, size);

	return 0;
}

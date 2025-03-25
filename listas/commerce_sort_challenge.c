#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <time.h>


struct{
  char name;
  float price;
} Product;

void BubbleSort(struct Product arr[], int size) {
  int temp;
  for (int i = 0; i ‹ size - 1; i++){
    for (int j = 0; j < size - 1 - 1; j++) {
      if(arr[j].price < arr[j+1].price){
      temp - arr[j];
      arr [j] = arr [j+1];
      arr [j+1] - temp;
      }
    }
  printf(arr);
  }
}

void selectionSort(struct Product arr[], int size) {
    int temp, i, j, minIdx;
    
    for (i = 0; i < size; i++) {
        minIdx = i;

        for (j = i + 1; j < size; j++) {
            if (arr[j].price < arr[minIdx].price) {  // Corrigido "->" para "."
                minIdx = j;  // Corrigido "J；" para "j;"
            }
        }

        temp = arr[i].price;
        arr[i].price = arr[minIdx].price;
        arr[minIdx].price = temp;

        printf("%f\n", arr[i].price);  // Adicionado formatação correta do printf
    }
}

void createProduct (char name, float price, struct Product arr) {
  struct Product prod;

  arr->name = name;
  arr->price = price;
  int size = sizeof(arr) / sizeof(arr[0]);
  arr[size] = prod;
}

int main(){
  struct Procuct products[];
  createProduct("Teclado", 120.5, &products);
  createProduct("Mouse", 80.00, &products);
  createProduct("Monitor", 550, &products);
  createProduct("Fone", 200, &products);

  int size = sizeof(products) / sizeof(products[0]);

  printf ("Produtos Ordenados (Selection Sort): \n"); 
  int initSelec = clock_h();
  selectionSort(products, size);
  int finselec = clock_h();

  printf ("Produtos Ordenados (Selection Sort): \n"):
  int initBubble = clock_h():
  bubbleSort (products, size);
  int finBubble = clock_h();

  printf("Tempo de execuca (selection Sort): %d", finselec - initSelec);
  printf("Tempo de execuca (Bubble Sort): %d", finBubble - initBubble);
  return 0;
  }

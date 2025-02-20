
#include <stdio.h>
#include <stdlib.h> //contem NULL, malloc, calloc, realloc, free

int main() {
  //alocacao estatica
  int vs[5] = {1, 2, 3, 4, 5};

  puts("### VETRO ESTÁTICO ###");
  printf("&vs = %p vs = %p\n", &vs, vs);

  for (int i = 0; i < 5; i++) {
    printf("&vs[%d] = %p, vs[%d] = %d\n", i, &vs[i], i, vs[i]);
  }
  puts("\n");

  //alocacao dinamica
  int *vh_mal = (int *) malloc(5 * sizeof(int)); //todos os elementos sao iniciados com lixo

  puts("### VETOR DINÂMICO ###");
  printf("&vh_mal = %p vh_mal = %p\n", &vh_mal, vh_mal);

  for (int i = 0; i < 5; i++) {
    printf("&vh_mal[%d] = %p, vh_mal[%d] = %d\n", i, &vh_mal[i], i, vh_mal[i]);
  }
  puts("\n");

  //alocacao dinamica usando calloc
  int *vh_call = (int *) calloc(5, sizeof(int)); //todos os elementos sao iniciados com 0

  puts("### VETOR DINÂMICO ###");
  printf("&vh_call = %p vh_call = %p\n", &vh_call, vh_call);

  for (int i = 0; i < 5; i++) {
    printf("&vh_call[%d] = %p, vh_call[%d] = %d\n", i, &vh_call[i], i, vh_call[i]);
  }

  return 0;
}

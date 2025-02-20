
#include <stdio.h>
#include <stdlib.h>

int soma_vetor_com_escalar(int v[], int n, int escalar) {
  for (int i = 0; i < n; i++) {
        v[i] += escalar;
    }
}

void print_vetor(const int *v, int n) {
  for (int i = 0; i < n; i++) {
    printf("&v[%d] = %p, v[%d] = %d\n", i, &v[i], i, v[i]);
  }
}

void desaloca_vetor(int **v) {
  free(*v);
  *v = NULL;
}


int main() {
    //alocacao de um vetor estatico (memoria stack)
    int vs[5] = {0, 10, 20, 30, 40};

    print_vetor(vs, 5);
    soma_vetor_com_escalar(vs, 5, 9);
    print_vetor(vs, 5);

    puts("### VETOR DINAMICO COM MALLOC");
    int *vh_mal = (int *) malloc(5 * sizeof(int));
    for (int i = 0; i < 5; i++) {
        vh_mal[i] = i * 10;
    }

    print_vetor(vh_mal, 5);
    soma_vetor_com_escalar(vh_mal, 5, 9);
    print_vetor(vh_mal, 5);


    // free(vh_mal);
    // vh_mal = NULL;

    printf("&vh_mal = %p, vh_mal = %p\n", &vh_mal, vh_mal);
    desaloca_vetor(&vh_mal);
    printf("&vh_mal = %p, vh_mal = %p\n", &vh_mal, vh_mal);
    return 0;
}

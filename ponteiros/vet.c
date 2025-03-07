
#include <stdio.h>
#include <stdlib.h>

int main() {
    int vet[5] = {1, 2, 3, 4, 5};

    for (int i = 0; i < 5; i++) {
        printf("&v[%d] = %p, v[%d] = %d\n", i, &vet[i], i, vet[i]);
    }

    printf("v[6] = %p, v[6] = %d\n", &vet[6], vet[6]);

    return 0;
}


//coisa de doido

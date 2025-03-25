#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Influencers {
	int followers;
	char nome[30];
	};

void BubbluSort(struct Influencers *data, int size){
	struct Influencers temp;

	for(int i = 0; i < 10 -1; i++) {
		for (int j = 0; j < 10 - i - 1; j++) {
			if(data[j].followers > data[j + 1].followers) {
				temp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = temp;
			}
		}
	}
};


int main() {
	struct Influencers data[10];

	for(int i =0; i < 10; i++) {
		struct Influencers n;
		
		puts("nome do influencer: ");
		scanf("%s", n.nome);
		puts("quantidade de seguidores: ");
		scanf("%d", &n.followers);

		data[i] = n;
	}

	puts("Nao ordenado");

	for(int i = 0; i < 10; i++){
		printf("Usuario %s, tem %d seguidores\n", data[i].nome, data[i].followers);
	}

	BubbluSort(data, 10);
	
	puts("ordenado");
	for(int i = 0; i < 10; i++){
		printf("Usuario %s, tem %d seguidores\n", data[i].nome, data[i].followers);

	}
}

#include <stdio.h>

int soma(int x, int y) {
	return x + y;
}

void somarefe(int x, int y, int *z){
	*z = x + y;
}

int main() {

	//funcao passagem por valor
	int a = 10;
	int b = 20;
	int c;
	
	puts("ANTES DE CHAMAR A FUNCAO");
	printf("&a = %p, a = %d\n", &a, a);
	printf("&b = %p, b = %d\n", &b, b);
	printf("&c = %p, c = %d\n", &c, c);

	c = soma(a, b);


	puts("DEPOIS DE CHAMAR A FUNCAO");
	printf("&a = %p, a = %d\n", &a, a);
	printf("&b = %p, b = %d\n", &b, b);
	printf("&c = %p, c = %d\n", &c, c);

	//funcao por referencia
	int d = 10;
	int e = 20;
	int f;


	puts("ANTES DE CHAMAR A FUNCAO REFERENCIA");
	printf("&d = %p, d = %d\n", &d, d);
	printf("&e = %p, e = %d\n", &e, e);
	printf("&f = %p, f = %d\n", &f, f);

	somarefe(d, e, &f);


	puts("ANTES DE CHAMAR A FUNCAO");
	printf("&d = %p, d = %d\n", &d, d);
	printf("&e = %p, e = %d\n", &e, e);
	printf("&f = %p, f = %d\n", &f, f);

	return 0;
}

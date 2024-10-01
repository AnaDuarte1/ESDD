#include <stdio.h>

int main(void) {
	int *ptr; // * caracteriza como ponteiro
	int valor = 10;

	ptr = &valor; // trazer o endereço da variavel valor

	printf("\n Endereco valor= %x", &valor); // %x - hexadecimal - Padrão para memoria
	printf("\n Endereco ptr = %x", ptr);
	printf("\n Valor = %d", *ptr);
    printf("\n Valor = %d\n", valor);
    
    *ptr = 20;

	printf("\n Endereco valor= %x", &valor);
	printf("\n Endereco ptr = %x", ptr);
	printf("\n Valor = %d", *ptr);
    printf("\n Valor = %d\n", valor);

	return 0;
}
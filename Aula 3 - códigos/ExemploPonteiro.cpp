#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"");
	int numero = 10;
  	int *ponteiro;

  	ponteiro = &numero; // Atribui o endere�o de `numero` a `ponteiro`
	//cria a referencia entre ponteiro e n�mero

	*ponteiro = 20;

  	printf("Conte�do da vari�vel n�mero: %d\n", numero);
  	printf("Endere�o de numero: %d\n", &numero);
  	printf("Conte�do da vari�vel ponteiro: %d\n", ponteiro);
	printf("Conte�do da vari�vel que ponteiro faz refer�ncia: %d\n", *ponteiro);
}

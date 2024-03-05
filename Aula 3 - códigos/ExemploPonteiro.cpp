#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"");
	int numero = 10;
  	int *ponteiro;

  	ponteiro = &numero; // Atribui o endereço de `numero` a `ponteiro`
	//cria a referencia entre ponteiro e número

	*ponteiro = 20;

  	printf("Conteúdo da variável número: %d\n", numero);
  	printf("Endereço de numero: %d\n", &numero);
  	printf("Conteúdo da variável ponteiro: %d\n", ponteiro);
	printf("Conteúdo da variável que ponteiro faz referência: %d\n", *ponteiro);
}

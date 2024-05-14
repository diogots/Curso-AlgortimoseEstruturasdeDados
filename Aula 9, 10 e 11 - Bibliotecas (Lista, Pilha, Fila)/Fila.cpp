#include <iostream>
#include "tad.h"
using namespace std;

/*
FUNÇÃO: criaFila
RESUMO: Cria uma nova fila vazia
PARAM: void
RETORNO: Fila* (ponteiro para a fila criada)
*/
Fila* criaFila(){
	//armazena o espaço para a fila
	Fila* fila = new Fila;
	fila->inicio = NULL;
	fila->fim = NULL;
	return fila;
}

/*
FUNÇÃO: vazia
RESUMO: verifica se a fila está vazia
PARAM: Fila* fila (ponteiro para a fila)
RETORNO: int (valor de teste para a condição de vazio)
*/
int vaziaFila(Fila *fila){
	if(fila->inicio == NULL)
		return 1;
	else return 0;
}

/*
FUNÇÃO: enqueue
RESUMO: insere elemento no fim da fila
PARAM: Fila* fila (ponteiro para a fila), int valor (valor a ser inserido)
RETORNO: void
*/
void enqueue(Fila* fila, int valor){
	Node* novo = new Node;
	novo->info = valor;
	novo->prox = NULL; //inserido no final
	if(vaziaFila(fila)){
		fila->inicio = novo;
		fila->fim = novo;
	}else{
		(fila->fim)->prox = novo;
		fila->fim = novo;
	}
}

/*
FUNÇÃO: dequeue
RESUMO: remove e retorna o elemento do início da fila
PARAM: Fila* fila (ponteiro para a fila)
RETORNO: int (valor removido da fila)
*/
int dequeue(Fila* fila){
	Node* aux;
	int valor;
	aux = fila->inicio;
	valor = aux->info;
	fila->inicio = aux->prox;
	//se esvaziou a fila, fila->fim tbm tem que ficar nula
	if(vaziaFila(fila))
		fila->fim = NULL;
	delete(aux);
	return valor;
}

/*
FUNÇÃO: first
RESUMO: retorna o elemento do início da fila
PARAM: Fila* fila (ponteiro para a fila)
RETORNO: int (valor da cabeça da fila)
*/
int first(Fila* fila){
    if (!vaziaFila(fila))
        return (fila->inicio)->info;
}

/*
FUNÇÃO: destroiFila
RESUMO: exclui todo conteúdo da fila
PARAM: Fila* (ponteiro para a fila)
RETORNO: nada
*/
void destroiFila(Fila *fila){
    while(!vaziaFila(fila))
        dequeue(fila);
}

/*
FUNÇÃO: print
RESUMO: imprime a fila (ERRADO, apenas para controle)
PARAM: Fila* (ponteiro para a fila)
RETORNO: void
*/
void printFilaControle(Fila* fila){
	Node* aux = fila->inicio;
	cout << "Início: ";
	while(aux){
		cout << "| " << aux->info << " |-->";
		aux = aux->prox;
	}
	cout << "X" << endl;
}






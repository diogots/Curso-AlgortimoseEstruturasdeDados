#include <iostream>
#include "tad.h"
using namespace std;

/*
FUN��O: criaPilha
RESUMO: Cria uma nova pilha vazia
PARAM: void
RETORNO: Pilha* (ponteiro para a pilha);
*/
Pilha* criaPilha(){
	Pilha* p = new Pilha;
	p->topo = NULL;
	return p;
}

/*
FUN��O: vazia
RESUMO: verifica se a pilha est� vazia
PARAM: Pilha* (ponteiro para a pilha)
RETORNO: int (1 se est� vazia, 0 se n�o est�)
*/
int vaziaPilha(Pilha* pilha){
	if( pilha->topo == NULL)
		return 1;
	else return 0;
}

/*
FUN��O: push
RESUMO: empilha novo elemento na pilha
PARAM: Pilha* (ponteiro para a pilha), int (valor a ser empilhado);
RETORNO: Pilha* (ponteiro para a pilha);
*/
Pilha* push(Pilha* pilha, int valor){
	Node* novo = new Node;
	novo->info = valor;
	novo->prox = pilha->topo;
	pilha->topo = novo;
	return pilha;
}

/*
FUN��O: pop
RESUMO: desempilha o elemento no topo da pilha e retorna seu valor
PARAM: Pilha* (ponteiro para a pilha), int (valor a ser desempilhado);
RETORNO: Pilha* (ponteiro para a pilha);
*/
int pop(Pilha* pilha){
    Node* aux = pilha->topo;
    int valor;
    if(!vaziaPilha(pilha)){
        valor = aux->info;
        pilha->topo = (pilha->topo)->prox;
        delete aux;
    } else cout << "pilha vazia!" << endl;
    return valor;
}

/*
FUN��O: top
RESUMO: informa o valor do primeiro elemento da pilha
PARAM: Pilha* (ponteiro para a pilha)
RETORNO: int (valor da informa��o do n� armazenado no topo)
*/
int top(Pilha* pilha){
	if (!vaziaPilha(pilha))
        return (pilha->topo)->info;
    else cout << "pilha vazia!";
}

/*
FUN��O: destroiPilha
RESUMO: exclui todo conte�do da pilha
PARAM: Pilha* (ponteiro para a pilha)
RETORNO: nada
*/
void destroiPilha(Pilha* pilha){
	while (!vaziaPilha(pilha))
        pop(pilha);
    cout << "pilha destru�da com sucesso!" << endl;
}
/*
FUN��O: print
RESUMO: imprime a pilha
PARAM: Pilha* (ponteiro para a pilha)
RETORNO: void
*/
void printPilhaControle(Pilha* pilha){
	Node* aux = pilha->topo;
	cout << "____" << endl;
	while(aux){
		cout << "| " << aux->info << " |\n"<< "____" << endl;
		aux = aux->prox;
	}
	cout << "X" << endl;
}


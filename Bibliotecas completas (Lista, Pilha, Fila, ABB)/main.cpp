#include <iostream>
#include "Lista.h"
#include "Pilha.h"
#include "Fila.h"
#include "Lista.h"
#include "ArvBB.h"
#include <locale.h>

using namespace std;

int main(){
    //padronizando acentua��o
    setlocale(LC_ALL,"");
    /*
    //c�digo de teste da biblioteca lista.h
    Node *lista;
    lista = criaLista();
    lista = insereOrdLista(lista,4);
    lista = insereOrdLista(lista,-12);
    lista = insereOrdLista(lista,32);
    lista = insereOrdLista(lista,6);
    lista = removeElemLista(lista,-12);
    lista = removeElemLista(lista,33);
    printLista(lista);
    lista = removeElemLista(lista,12);
    Node *pElem = buscaElementoLista(lista,32);
    cout << getElementoLista(pElem) << endl;
    setElementoLista(pElem,101);
    cout << getElementoLista(pElem) << endl;*/


/*
    Pilha *p;

    p = criaPilha();
    push(p,6);
    push(p,8);
    push(p,12);
    push(p,7);
    printPilhaControle(p);
    pop(p);
    printPilhaControle(p);
    destroiPilha(p);
*/
/*
    Fila *f;
    f = criaFila();
    enqueue(f,2);
    enqueue(f,4);
    enqueue(f,8);
    enqueue(f,12);
    dequeue(f);
    dequeue(f);
    printFilaControle(f);
*/
    ArvBB *arv;
    arv = criaABB();
    cout << "arvore criada" << endl;
    arv = insereABB(arv, 50);
    arv = insereABB(arv, 25);
    arv = insereABB(arv, 75);
    arv = insereABB(arv, 12);
    arv = insereABB(arv, 36);
    arv = insereABB(arv, 60);
    arv = insereABB(arv, 87);
    arv = insereABB(arv, 10);
    arv = insereABB(arv, 13);
    preOrdemABBHierarquico(arv);
}


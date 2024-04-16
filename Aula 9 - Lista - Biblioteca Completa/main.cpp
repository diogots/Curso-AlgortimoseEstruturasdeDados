#include <iostream>
#include "Lista.h"
#include <locale.h>

using namespace std;

int main(){
    //padronizando acentuação
    setlocale(LC_ALL,"");

    //código de teste da biblioteca lista.h
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
    cout << getElementoLista(pElem) << endl;
}

#include <iostream>
#include "tad.h"
using namespace std;

// Fun��o para criar uma �rvore Bin�ria de Busca (ABB)
ArvBB* criaABB(){
    // Retorna NULL, que representa uma �rvore vazia
    return NULL;
}

// Fun��o para verificar se a ABB est� vazia
int vaziaABB(ArvBB* raiz){
    // Se a raiz for NULL (ou seja, a �rvore est� vazia), retorna 1
    // Caso contr�rio, retorna 0
    if(!raiz)
        return 1;
    else return 0;
}

// Fun��o para imprimir a informa��o no n� atual
void printABB(ArvBB *nodeArv){
    // Imprime o valor do campo 'info' do n�
    cout << " " << nodeArv->info << "\n     ";
}

// Fun��o para visitar um n� e executar uma fun��o nele
void visitABB(ArvBB *nodeArv, void (*func)(ArvBB*)){
    // Executa a fun��o 'func' no n�
    func(nodeArv);
}


// Fun��o para realizar uma travessia em pr�-ordem da �rvore com visualiza��o hierarquica
void preOrdemABBHierarquico(ArvBB *raiz, int nivel = 0){
    // Verifica se a �rvore n�o est� vazia
    if (!vaziaABB(raiz)){
        // Visita a raiz e imprime seu valor
        visitABB(raiz,printABB);
        if(raiz->esq){
                for(int i = 0; i<nivel; i++)
                    cout << "     ";
                cout << "<fe>";
        }
        // Realiza a travessia em pr�-ordem da sub�rvore esquerda
        preOrdemABBHierarquico(raiz->esq,nivel+1);
        if(raiz->dir){
                for(int i = 0; i<nivel; i++)
                    cout << "     ";
                cout << "<fd>";
        }
        // Realiza a travessia em pr�-ordem da sub�rvore direita
        preOrdemABBHierarquico(raiz->dir,nivel+1);
    }
}

// Fun��o para realizar uma travessia em pr�-ordem da �rvore (RED)
void preOrdemABB(ArvBB *raiz){
    // Verifica se a �rvore n�o est� vazia
    if (!vaziaABB(raiz)){
        // Visita a raiz e imprime seu valor
        visitABB(raiz,printABB);
        cout << "<<";
        // Realiza a travessia em pr�-ordem da sub�rvore esquerda
        preOrdemABB(raiz->esq);
        cout << ">>";
        // Realiza a travessia em pr�-ordem da sub�rvore direita
        preOrdemABB(raiz->dir);
    }
}

// Fun��o para realizar uma travessia em ordem da �rvore (ERD)
void emOrdemABB(ArvBB *raiz){
    // Verifica se a �rvore n�o est� vazia
    if (!vaziaABB(raiz)){
        // Realiza a travessia em ordem da sub�rvore esquerda
        cout << "<<";
        emOrdemABB(raiz->esq);
        // Visita a raiz e imprime seu valor
        visitABB(raiz,printABB);
        cout << ">>";
        // Realiza a travessia em ordem da sub�rvore direita
        emOrdemABB(raiz->dir);
    }
}

// Fun��o para realizar uma travessia em p�s-ordem da �rvore (EDR)
void posOrdemABB(ArvBB *raiz){
    // Verifica se a �rvore n�o est� vazia
    if (!vaziaABB(raiz)){
        // Realiza a travessia em p�s-ordem da sub�rvore esquerda
        cout << "<<";
        posOrdemABB(raiz->esq);
        cout << ">>";
        // Realiza a travessia em p�s-ordem da sub�rvore direita
        posOrdemABB(raiz->dir);
        // Visita a raiz e imprime seu valor
        visitABB(raiz,printABB);
    }
}

// Fun��o para retornar o m�ximo entre dois inteiros
int max(int a, int b){
    // Se 'a' for maior que 'b', retorna 'a'
    // Caso contr�rio, retorna 'b'
    if(a>b)
        return a;
    else return b;
}

// Fun��o para calcular a altura da �rvore Bin�ria de Busca (ABB)
int alturaABB(ArvBB *raiz){
    // Se a �rvore estiver vazia, retorna -1
    if(vaziaABB(raiz))
        return -1;
    // Caso contr�rio, retorna 1 mais o m�ximo entre as alturas das sub�rvores esquerda e direita
    else return 1 + max(alturaABB(raiz->esq),alturaABB(raiz->dir));
}

// Fun��o para criar um novo n� na �rvore Bin�ria de Busca (ABB)
ArvBB* novoNoABB(int elem){
    // Cria um novo n�
    ArvBB* novo = new ArvBB;
    // Atribui o valor do elemento ao campo 'info' do novo n�
    novo->info = elem;
    // Inicializa os ponteiros 'esq' e 'dir' do novo n� como NULL
    novo->esq = NULL;
    novo->dir = NULL;
    // Retorna o novo n�
    return novo;
}

// Fun��o para inserir um elemento na ABB
ArvBB* insereABB(ArvBB *raiz, int elem){
    // Verifica se a ABB est� vazia
    if(vaziaABB(raiz)){
        // Se a ABB estiver vazia, cria um novo n� com o elemento
        ArvBB* novo = novoNoABB(elem);
        // A raiz se torna o novo n�
        raiz = novo;
    }else{
        // Se o elemento for menor que o valor da raiz
        if(elem < raiz->info)
            // Insere o elemento na sub�rvore esquerda
            raiz->esq = insereABB(raiz->esq, elem);
        else
            // Sen�o, insere o elemento na sub�rvore direita
            raiz->dir = insereABB(raiz->dir, elem);
    }
    // Retorna a raiz da ABB
    return raiz;
}

// Fun��o para buscar um elemento na ABB
ArvBB* buscaElemABB(ArvBB *raiz, int elem){
    // Se a raiz for NULL (ou seja, a �rvore est� vazia) ou o valor da raiz for igual ao elemento, retorna a raiz
    if (raiz == NULL || raiz->info == elem)
        return raiz;
    else{
        // Se o elemento for menor que o valor da raiz, busca o elemento na sub�rvore esquerda
        if(elem < raiz->info)
            return buscaElemABB(raiz->esq,elem);
        // Sen�o, busca o elemento na sub�rvore direita
        else return buscaElemABB(raiz->dir,elem);
    }
}

// Fun��o para remover um elemento da ABB
ArvBB* removeElemABB(ArvBB * raiz, int elem){
    // Vari�vel auxiliar para armazenar o n� a ser removido
    ArvBB* aux;
    // Verifica se a ABB est� vazia
    if (!vaziaABB(raiz)){
        // Se o elemento for igual ao valor da raiz
        if (elem == raiz->info){
            // Se a sub�rvore direita da raiz for NULL
            if (raiz->dir == NULL){
                aux = raiz;
                raiz = raiz->esq;
                delete(aux);
            // Se a sub�rvore esquerda da raiz for NULL
            }else if (raiz->esq == NULL){
                aux = raiz;
                raiz = raiz->dir;
                delete(aux);
            // Se a raiz tiver ambos os filhos
            }else{
                aux = raiz->dir;
                // Encontra o menor elemento da sub�rvore direita
                while(aux->esq)
                    aux = aux->esq;
                // Liga com a sub�rvore esquerda
                aux->esq = raiz->esq;
                aux = raiz;
                raiz = raiz->dir;
                delete(aux);
            }
        // Se o elemento for diferente do valor da raiz
        }else{
            // Se o elemento for menor que o valor da raiz
            if (elem < raiz->info)
                raiz->esq = removeElemABB(raiz->esq, elem);
            // Se o elemento for maior que o valor da raiz
            else raiz->dir = removeElemABB(raiz->dir,elem);
        }
    }
    // Retorna a raiz da ABB
    return raiz;
}


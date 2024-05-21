#include <iostream>
#include "tad.h"
using namespace std;

// Função para criar uma Árvore Binária de Busca (ABB)
ArvBB* criaABB(){
    // Retorna NULL, que representa uma árvore vazia
    return NULL;
}

// Função para verificar se a ABB está vazia
int vaziaABB(ArvBB* raiz){
    // Se a raiz for NULL (ou seja, a árvore está vazia), retorna 1
    // Caso contrário, retorna 0
    if(!raiz)
        return 1;
    else return 0;
}

// Função para imprimir a informação no nó atual
void printABB(ArvBB *nodeArv){
    // Imprime o valor do campo 'info' do nó
    cout << " " << nodeArv->info << "\n     ";
}

// Função para visitar um nó e executar uma função nele
void visitABB(ArvBB *nodeArv, void (*func)(ArvBB*)){
    // Executa a função 'func' no nó
    func(nodeArv);
}


// Função para realizar uma travessia em pré-ordem da árvore com visualização hierarquica
void preOrdemABBHierarquico(ArvBB *raiz, int nivel = 0){
    // Verifica se a árvore não está vazia
    if (!vaziaABB(raiz)){
        // Visita a raiz e imprime seu valor
        visitABB(raiz,printABB);
        if(raiz->esq){
                for(int i = 0; i<nivel; i++)
                    cout << "     ";
                cout << "<fe>";
        }
        // Realiza a travessia em pré-ordem da subárvore esquerda
        preOrdemABBHierarquico(raiz->esq,nivel+1);
        if(raiz->dir){
                for(int i = 0; i<nivel; i++)
                    cout << "     ";
                cout << "<fd>";
        }
        // Realiza a travessia em pré-ordem da subárvore direita
        preOrdemABBHierarquico(raiz->dir,nivel+1);
    }
}

// Função para realizar uma travessia em pré-ordem da árvore (RED)
void preOrdemABB(ArvBB *raiz){
    // Verifica se a árvore não está vazia
    if (!vaziaABB(raiz)){
        // Visita a raiz e imprime seu valor
        visitABB(raiz,printABB);
        cout << "<<";
        // Realiza a travessia em pré-ordem da subárvore esquerda
        preOrdemABB(raiz->esq);
        cout << ">>";
        // Realiza a travessia em pré-ordem da subárvore direita
        preOrdemABB(raiz->dir);
    }
}

// Função para realizar uma travessia em ordem da árvore (ERD)
void emOrdemABB(ArvBB *raiz){
    // Verifica se a árvore não está vazia
    if (!vaziaABB(raiz)){
        // Realiza a travessia em ordem da subárvore esquerda
        cout << "<<";
        emOrdemABB(raiz->esq);
        // Visita a raiz e imprime seu valor
        visitABB(raiz,printABB);
        cout << ">>";
        // Realiza a travessia em ordem da subárvore direita
        emOrdemABB(raiz->dir);
    }
}

// Função para realizar uma travessia em pós-ordem da árvore (EDR)
void posOrdemABB(ArvBB *raiz){
    // Verifica se a árvore não está vazia
    if (!vaziaABB(raiz)){
        // Realiza a travessia em pós-ordem da subárvore esquerda
        cout << "<<";
        posOrdemABB(raiz->esq);
        cout << ">>";
        // Realiza a travessia em pós-ordem da subárvore direita
        posOrdemABB(raiz->dir);
        // Visita a raiz e imprime seu valor
        visitABB(raiz,printABB);
    }
}

// Função para retornar o máximo entre dois inteiros
int max(int a, int b){
    // Se 'a' for maior que 'b', retorna 'a'
    // Caso contrário, retorna 'b'
    if(a>b)
        return a;
    else return b;
}

// Função para calcular a altura da Árvore Binária de Busca (ABB)
int alturaABB(ArvBB *raiz){
    // Se a árvore estiver vazia, retorna -1
    if(vaziaABB(raiz))
        return -1;
    // Caso contrário, retorna 1 mais o máximo entre as alturas das subárvores esquerda e direita
    else return 1 + max(alturaABB(raiz->esq),alturaABB(raiz->dir));
}

// Função para criar um novo nó na Árvore Binária de Busca (ABB)
ArvBB* novoNoABB(int elem){
    // Cria um novo nó
    ArvBB* novo = new ArvBB;
    // Atribui o valor do elemento ao campo 'info' do novo nó
    novo->info = elem;
    // Inicializa os ponteiros 'esq' e 'dir' do novo nó como NULL
    novo->esq = NULL;
    novo->dir = NULL;
    // Retorna o novo nó
    return novo;
}

// Função para inserir um elemento na ABB
ArvBB* insereABB(ArvBB *raiz, int elem){
    // Verifica se a ABB está vazia
    if(vaziaABB(raiz)){
        // Se a ABB estiver vazia, cria um novo nó com o elemento
        ArvBB* novo = novoNoABB(elem);
        // A raiz se torna o novo nó
        raiz = novo;
    }else{
        // Se o elemento for menor que o valor da raiz
        if(elem < raiz->info)
            // Insere o elemento na subárvore esquerda
            raiz->esq = insereABB(raiz->esq, elem);
        else
            // Senão, insere o elemento na subárvore direita
            raiz->dir = insereABB(raiz->dir, elem);
    }
    // Retorna a raiz da ABB
    return raiz;
}

// Função para buscar um elemento na ABB
ArvBB* buscaElemABB(ArvBB *raiz, int elem){
    // Se a raiz for NULL (ou seja, a árvore está vazia) ou o valor da raiz for igual ao elemento, retorna a raiz
    if (raiz == NULL || raiz->info == elem)
        return raiz;
    else{
        // Se o elemento for menor que o valor da raiz, busca o elemento na subárvore esquerda
        if(elem < raiz->info)
            return buscaElemABB(raiz->esq,elem);
        // Senão, busca o elemento na subárvore direita
        else return buscaElemABB(raiz->dir,elem);
    }
}

// Função para remover um elemento da ABB
ArvBB* removeElemABB(ArvBB * raiz, int elem){
    // Variável auxiliar para armazenar o nó a ser removido
    ArvBB* aux;
    // Verifica se a ABB está vazia
    if (!vaziaABB(raiz)){
        // Se o elemento for igual ao valor da raiz
        if (elem == raiz->info){
            // Se a subárvore direita da raiz for NULL
            if (raiz->dir == NULL){
                aux = raiz;
                raiz = raiz->esq;
                delete(aux);
            // Se a subárvore esquerda da raiz for NULL
            }else if (raiz->esq == NULL){
                aux = raiz;
                raiz = raiz->dir;
                delete(aux);
            // Se a raiz tiver ambos os filhos
            }else{
                aux = raiz->dir;
                // Encontra o menor elemento da subárvore direita
                while(aux->esq)
                    aux = aux->esq;
                // Liga com a subárvore esquerda
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


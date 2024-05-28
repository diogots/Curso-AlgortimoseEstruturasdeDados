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

// Função para imprimir a informação no nó atual para a impressão em níveis
void printABBHierarquico(ArvBB *nodeArv){
    // Imprime o valor do campo 'info' do nó
    cout << " " << nodeArv->info << "\n            ";
}

// Função para imprimir a informação no nó atual
void printNodeABB(ArvBB *nodeArv){
    // Imprime o valor do campo 'info' do nó
    cout << " " << nodeArv->info << " ";
}


// Função para visitar um nó e executar uma função nele
void visitABB(ArvBB *nodeArv, void (*func)(ArvBB*)){
    // Executa a função 'func' no nó
    func(nodeArv);
}


// Função para realizar uma travessia em pré-ordem da árvore com visualização hierarquica
void preOrdemABBHierarquico(ArvBB *raiz, int nivel = 0,int ehRaiz=1){
    // Verifica se a árvore não está vazia
    if (!vaziaABB(raiz)){
        // Visita a raiz e imprime seu valor
        if(ehRaiz){
            cout << "raiz:";
            ehRaiz = 0; //imprimiu a raiz principal da árvore
        }
        visitABB(raiz,printABBHierarquico);
        if(raiz->esq){
                for(int i = 0; i<nivel; i++)
                    cout << "            ";
                cout << "<<filhoEsq:";
        }
        // Realiza a travessia em pré-ordem da subárvore esquerda
        preOrdemABBHierarquico(raiz->esq,nivel+1,ehRaiz);
        if(raiz->dir){
                for(int i = 0; i<nivel; i++)
                    cout << "            ";
                cout << ">>FilhoDir:";
        }
        // Realiza a travessia em pré-ordem da subárvore direita
        preOrdemABBHierarquico(raiz->dir,nivel+1,ehRaiz);
    }
}

// Função para realizar uma travessia em pré-ordem da árvore (RED)
//executa a função recebida como parâmetro em cada nó
void preOrdemABB(ArvBB *raiz,void (*func)(ArvBB*)){
    // Verifica se a árvore não está vazia
    if (!vaziaABB(raiz)){
        // Visita a raiz e imprime seu valor
        visitABB(raiz,func);
        //cout << " << ";
        // Realiza a travessia em pré-ordem da subárvore esquerda
        preOrdemABB(raiz->esq,func);
        //cout << " >> ";
        // Realiza a travessia em pré-ordem da subárvore direita
        preOrdemABB(raiz->dir,func);
    }
}

// Função para realizar uma travessia em ordem da árvore (ERD)
void emOrdemABB(ArvBB *raiz,void (*func)(ArvBB*)){
    // Verifica se a árvore não está vazia
    if (!vaziaABB(raiz)){
        // Realiza a travessia em ordem da subárvore esquerda
        //cout << " << ";
        emOrdemABB(raiz->esq,func);
        // Visita a raiz e imprime seu valor
        visitABB(raiz,func);
        //cout << " >> ";
        // Realiza a travessia em ordem da subárvore direita
        emOrdemABB(raiz->dir,func);
    }
}

// Função para realizar uma travessia em pós-ordem da árvore (EDR)
void posOrdemABB(ArvBB *raiz,void (*func)(ArvBB*)){
    // Verifica se a árvore não está vazia
    if (!vaziaABB(raiz)){
        // Realiza a travessia em pós-ordem da subárvore esquerda
        //cout << " << ";
        posOrdemABB(raiz->esq,func);
        //cout << " >> ";
        // Realiza a travessia em pós-ordem da subárvore direita
        posOrdemABB(raiz->dir,func);
        // Visita a raiz e imprime seu valor
        visitABB(raiz,func);
    }
}

int numElementos=0;

void addElem(ArvBB *node){
    numElementos++;
}

int getNumElementosABB(ArvBB *raiz){
    numElementos = 0;
    preOrdemABB(raiz,addElem);
    return numElementos;
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

// Função para buscar um elemento na Árvore Binária de Busca (ABB)
ArvBB* buscaElemABB(ArvBB *raiz, int elem){
    // Verifica se a árvore não está vazia
    if(!vaziaABB(raiz)){
        // Se o valor do nó atual é igual ao elemento procurado
        if (raiz->info == elem){
            cout << "Elemento " << elem << " encontrado!" << endl;
            // Retorna o nó que contém o elemento
            return raiz;
        }
        // Se o elemento é menor que o valor do nó atual
        else if(elem < raiz->info)
            // Busca o elemento na subárvore esquerda
            raiz = buscaElemABB(raiz->esq,elem);
        else
            // Se o elemento é maior que o valor do nó atual, busca o elemento na subárvore direita
            buscaElemABB(raiz->dir,elem);
    }else{ // Se a árvore está vazia, imprime uma mensagem indicando que o elemento não foi encontrado
        cout << "Elemento " << elem << " não encontrado!" << endl;
        return raiz;
    }
}

// Função para remover um elemento de uma Árvore Binária de Busca (ABB)
ArvBB* removeElemABB(ArvBB * raiz, int elem){
    // Verifica se a árvore está vazia
    if(!vaziaABB(raiz)){
        // Se o elemento é menor que o nó atual, procura na subárvore esquerda
        if(elem < raiz->info){
            raiz->esq = removeElemABB(raiz->esq,elem);
        }
        // Se o elemento é maior que o nó atual, procura na subárvore direita
        else if (elem > raiz->info){
            raiz->dir = removeElemABB(raiz->dir,elem);
        }
        // Se o elemento é igual ao nó atual, remove o nó
        else{
            ArvBB *aux = raiz;
            // Se o nó atual não tem filho à esquerda, substitui o nó pelo filho à direita
            if(raiz->esq == NULL){
                raiz = raiz->dir;
                delete aux;
            }
            // Se o nó atual não tem filho à direita, substitui o nó pelo filho à esquerda
            else if (raiz->dir == NULL){
                raiz = raiz->esq;
                delete aux;
            }
            // Se o nó atual tem ambos os filhos, substitui o nó pelo menor elemento da subárvore direita
            else{
                aux = raiz->dir;
                while(aux->esq)
                    aux = aux->esq;
                raiz->info = aux->info;
                raiz->dir = removeElemABB(raiz->dir,aux->info);
            }
        }
        // Retorna a raiz da árvore
        return raiz;
    }
    // Se a árvore está vazia, retorna NULL
    else return NULL;
}

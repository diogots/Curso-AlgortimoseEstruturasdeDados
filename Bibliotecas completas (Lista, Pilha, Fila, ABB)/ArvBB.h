#ifndef ARVBB_H
#define ARVBB_H

#include "tad.h"

ArvBB* criaABB();
int vaziaABB(ArvBB* raiz);
void printABBHierarquico(ArvBB *nodeArv);
void printABB(ArvBB *raiz);
void printNodeABB(ArvBB *node);
void addElem(ArvBB *node);
int getNumElementosABB(ArvBB *raiz);
void visitABB(ArvBB *node, void (*func)(ArvBB*));
void preOrdemABBHierarquico(ArvBB *raiz, int nivel=0,int ehRaiz=1);
void preOrdemABB(ArvBB *raiz, void (*func)(ArvBB*));
void emOrdemABB(ArvBB *raiz, void (*func)(ArvBB*));
void posOrdemABB(ArvBB *raiz, void (*func)(ArvBB*));
int max(int a, int b);
int alturaABB(ArvBB *raiz);
ArvBB* novoNoABB(int elem);
ArvBB* insereABB(ArvBB *raiz, int elem);
ArvBB* buscaElemABB(ArvBB *raiz, int elem);
ArvBB* removeElemABB(ArvBB * raiz, int elem);

#endif // ARVBB_H

#ifndef ARVBB_H
#define ARVBB_H

#include "tad.h"

ArvBB* criaABB();
int vaziaABB(ArvBB* raiz);
void printABB(ArvBB *node);
void visitABB(ArvBB *node, void (*func)(ArvBB*));
void preOrdemABBHierarquico(ArvBB *raiz, int nivel=0);
void preOrdemABB(ArvBB *raiz);
void emOrdemABB(ArvBB *raiz);
void posOrdemABB(ArvBB *raiz);
int max(int a, int b);
int alturaABB(ArvBB *raiz);
ArvBB* novoNoABB(int elem);
ArvBB* insereABB(ArvBB *raiz, int elem);
ArvBB* buscaElemABB(ArvBB *raiz, int elem);
ArvBB* removeElemABB(ArvBB * raiz, int elem);

#endif // ARVBB_H

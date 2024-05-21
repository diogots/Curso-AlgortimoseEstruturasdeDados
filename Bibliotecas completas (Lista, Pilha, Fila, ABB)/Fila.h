#ifndef FILA_H

#define FILA_H

#include "tad.h"

Fila* criaFila();
int vaziaFila(Fila *fila);
void enqueue(Fila* fila, int valor);
int dequeue(Fila* fila);
int first(Fila* fila);
void destroiFila(Fila *fila);
void printFilaControle(Fila* fila);

#endif


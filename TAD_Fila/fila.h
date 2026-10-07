#ifndef FILA_H
#define FILA_H

typedef struct fila {
	float dado;
	struct fila *proximo;
} Fila;

typedef struct controlador {
	Fila *topo;
	Fila *cauda;
} Controlador;

void enqueue(Controlador *controlador, float valor);

#endif

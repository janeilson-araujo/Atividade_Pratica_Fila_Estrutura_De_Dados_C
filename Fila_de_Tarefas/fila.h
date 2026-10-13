#ifndef FILA_H
#define FILA_H

typedef struct tarefa
{
	int id;
	int chegada;
	int duracao;
} Tarefa;

typedef struct fila
{
	Tarefa tarefa;
	struct fila *proximo;
} Fila;

typedef struct controlador
{
	Fila *topo;
	Fila *cauda;
} Controlador;

void enqueue(Controlador *controlador, Tarefa tarefa);
int dequeue(Controlador *controlador, Tarefa *tarefa);
void exibir(Controlador *controlador);
int fila_vazia(Controlador *controlador);

void esvaziar(Controlador *controlador);

#endif

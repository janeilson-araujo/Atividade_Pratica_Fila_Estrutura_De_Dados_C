#include <stdlib.h>
#include <stdio.h>
#include "fila.h"

typedef struct fila fila, *Pfila;

void enqueue(Controlador *controlador, float valor)
{
    Pfila novo = malloc(sizeof(fila));

    novo->dado = valor;
    novo->proximo = NULL;

    if (controlador->cauda == NULL)
    {
        controlador->topo = novo;
        controlador->cauda = novo;
    }
    else
    {
        controlador->cauda->proximo = novo;
        controlador->cauda = novo;
    }
}

int dequeue(Controlador *controlador, float *valor)
{
    Pfila removido;

    if (controlador->topo == NULL)
    {
        return 0;
    }

    removido = controlador->topo;
    controlador->topo = removido->proximo;

    if (valor != NULL)
    {
        *valor = removido->dado;
    }

    if (controlador->topo == NULL)
    {
        controlador->cauda = NULL;
    }

    free(removido);
    return 1;
}

void exibir(const Controlador *controlador)
{
    Pfila atual = controlador->topo;

    if (atual == NULL)
    {
        printf("fila vazia\n");
        return;
    }

    printf("fila:");
    while (atual != NULL)
    {
        printf(" %.1f", atual->dado);
        atual = atual->proximo;
    }
    
    printf("\n");
}

void esvaziar(Controlador *controlador)
{
    while (dequeue(controlador, NULL))
    {
    }
}

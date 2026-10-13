#include <stdlib.h>
#include <stdio.h>
#include "fila.h"

void enqueue(Controlador *controlador, Tarefa tarefa)
{
    Fila *novo = malloc(sizeof(*novo));

    novo->tarefa = tarefa;
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

int dequeue(Controlador *controlador, Tarefa *tarefa)
{
    Fila *removido;

    if (controlador->topo == NULL)
    {
        return 0;
    }

    removido = controlador->topo;
    controlador->topo = removido->proximo;

    if (tarefa != NULL)
    {
        *tarefa = removido->tarefa;
    }

    if (controlador->topo == NULL)
    {
        controlador->cauda = NULL;
    }

    free(removido);
    return 1;
}

int fila_vazia( Controlador *controlador)
{
    return controlador->topo == NULL;
}

void exibir(const Controlador *controlador)
{
    Fila *atual = controlador->topo;

    printf("[");
    while (atual != NULL)
    {
        printf("%d", atual->tarefa.id);
        atual = atual->proximo;

        if (atual != NULL)
        {
            printf(" ");
        }
    }
    printf("]");
}

void esvaziar(Controlador *controlador)
{
    while (dequeue(controlador, NULL)){}
}
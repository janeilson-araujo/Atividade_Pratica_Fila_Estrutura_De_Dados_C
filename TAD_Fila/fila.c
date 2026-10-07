#include <stdlib.h>
#include <stdio.h>
#include "fila.h"

typedef struct fila fila, *Pfila;

typedef struct controlador
{
    Pfila topo;
    Pfila cauda;
};

typedef struct fila
{
    float dado;
    Pfila proximo;

}fila, *Pfila;

Pfila enqueue(Pfila cauda, float valor){

}



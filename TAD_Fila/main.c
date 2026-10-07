#include <stdio.h>
#include <string.h>

#include "fila.h"

int main(void)
{
    Controlador controlador = {NULL, NULL};
    char comando[3];
    float valor;

    while (scanf("%2s", comando) == 1)
    {
        if (strcmp(comando, "-s") == 0)
        {
            exibir(&controlador);
        }
        else if (strcmp(comando, "-c") == 0)
        {
            esvaziar(&controlador);
        }
        else if (strcmp(comando, "-i") == 0)
        {
            if (scanf("%f", &valor) != 1)
            {
                break;
            }

            enqueue(&controlador, valor);
        }
        else if (strcmp(comando, "-r") == 0)
        {
            dequeue(&controlador, NULL);
        }
        else if (strcmp(comando, "-f") == 0)
        {
            break;
        }
    }

    esvaziar(&controlador);
    return 0;
}
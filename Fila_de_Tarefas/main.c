#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

void imprimir_evento(int tempo, char *evento, int id, Controlador *fila)
{
    printf("%d %s %d ", tempo, evento, id);
    exibir(fila);
    printf("\n");
}

int main()
{
    Tarefa tarefas[100];
    Controlador fila = {NULL, NULL};
    Tarefa processamento;
    int quantidade;
    int proximaChegada = 0;
    int tempoFim = 0;
    int ocupado = 0;

    scanf("%d", &quantidade);

    for (int i = 0; i < quantidade; i++)
    {
        scanf("%d %d %d", &tarefas[i].id, &tarefas[i].chegada, &tarefas[i].duracao);
    }

    while (proximaChegada < quantidade || ocupado || !fila_vazia(&fila))
    {
        if (ocupado && (proximaChegada == quantidade || tempoFim <= tarefas[proximaChegada].chegada))
        {
            int tempo_atual = tempoFim;
            int id_finalizado = processamento.id;

            ocupado = 0;

            if (dequeue(&fila, &processamento))
            {
                tempoFim = tempo_atual + processamento.duracao;
                ocupado = 1;
            }

            imprimir_evento(tempo_atual, "FIM", id_finalizado, &fila);
        }
        else
        {
            Tarefa chegada = tarefas[proximaChegada++];

            if (ocupado)
            {
                enqueue(&fila, chegada);
            }
            else
            {
                processamento = chegada;
                tempoFim = chegada.chegada + chegada.duracao;
                ocupado = 1;
            }

            imprimir_evento(chegada.chegada, "CHEGADA", chegada.id, &fila);
        }
    }

    esvaziar(&fila);
    return 0;
}
# Exercício: Simulando uma Fila de Tarefas

## Objetivo
Demonstrar o funcionamento do TAD Fila por meio da simulação de tarefas que chegam para um funcionário de uma empresa, utilizando o princípio FIFO (First In, First Out).

## Enunciado
Implemente uma simulação de uma fila de tarefas que chegam para um funcionário de uma empresa. Cada tarefa possui um identificador (ID), um instante de chegada e um tempo necessário para sua execução.

O funcionário realiza apenas uma tarefa por vez, respeitando a ordem de chegada. Enquanto estiver ocupado, as novas tarefas deverão aguardar na fila.

Para permitir a execução de casos de teste, os instantes de chegada e os tempos de processamento serão informados pela entrada padrão. Esses valores representam uma simulação previamente definida de eventos que poderiam ocorrer aleatoriamente.

## Regras da simulação

- As tarefas devem ser processadas na ordem em que chegam, respeitando o princípio FIFO.
- Cada tarefa possui um ID inteiro, um instante de chegada e um tempo de processamento, ambos expressos em segundos.
- Quando uma tarefa chega e o funcionário está disponível, seu processamento começa imediatamente.
- Quando o funcionário está ocupado, as novas tarefas são inseridas no final da fila de espera.
- Quando uma tarefa é finalizada, o funcionário inicia imediatamente a próxima tarefa da fila, caso exista.
- Se uma chegada e uma finalização ocorrerem no mesmo instante, a finalização deverá ser processada primeiro.
- A cada chegada ou finalização, o programa deverá exibir o evento e o estado atualizado da fila de espera.
- A simulação termina quando todas as tarefas tiverem sido concluídas.

## Formato da entrada
A primeira linha contém um número inteiro N, representando a quantidade de tarefas.

As próximas N linhas contêm três valores separados por espaços:

ID CHEGADA DURACAO
Os registros devem estar ordenados pelo instante de chegada. Caso duas tarefas cheguem simultaneamente, deverá ser respeitada a ordem em que aparecem na entrada.

Considere `1 <= N <= 100`, identificadores únicos, instantes de chegada maiores ou iguais a zero e durações inteiras positivas.

## Formato da saída
Para cada evento, imprima uma linha contendo o instante, o tipo do evento, o ID da tarefa e o estado da fila de espera.

```text
TEMPO EVENTO ID FILA
```
Utilize CHEGADA para a chegada de uma tarefa e FIM para sua finalização. A fila deverá ser apresentada entre colchetes, com os IDs separados por espaços. Quando não houver tarefas aguardando, imprima [].

Atenção: a fila exibida contém apenas as tarefas que estão aguardando. A tarefa atualmente em execução não faz parte dessa representação.

## Exemplos

### Exemplo 1: funcionário ocupado

#### Entrada

```text
3
101 0 8
102 5 4
103 10 3
```

#### Saída esperada

```text
0 CHEGADA 101 []
5 CHEGADA 102 [102]
8 FIM 101 []
10 CHEGADA 103 [103]
12 FIM 102 []
15 FIM 103 []
```
A tarefa 101 começa no instante 0 e termina no instante 8. A tarefa 102 chega no instante 5 e precisa aguardar. A tarefa 103 chega enquanto a tarefa 102 está sendo executada.

### Exemplo 2: chegadas simultâneas

#### Entrada

```text
3
10 0 5
20 0 3
30 0 2
```

#### Saída esperada

```text
0 CHEGADA 10 []
0 CHEGADA 20 [20]
0 CHEGADA 30 [20 30]
5 FIM 10 [30]
8 FIM 20 []
10 FIM 30 []
```
### Exemplo 3: funcionário disponível

#### Entrada

```text
3
1 0 2
2 5 2
3 10 2
```

#### Saída esperada

```text
0 CHEGADA 1 []
2 FIM 1 []
5 CHEGADA 2 []
7 FIM 2 []
10 CHEGADA 3 []
12 FIM 3 []
```
## Orientações de implementação
Utilize o TAD TFila desenvolvido anteriormente para armazenar os identificadores das tarefas que aguardam atendimento. A tarefa em execução deverá ser controlada separadamente.

Para a versão submetida aos testes, não utilize pausas reais nem gere tempos aleatórios durante a execução. O programa deverá avançar diretamente para o próximo evento, conforme os instantes e as durações informados na entrada.

Como atividade complementar, implemente um modo de demonstração que gere tempos aleatórios de processamento e utilize `sleep()`, em ambientes Unix, ou `Sleep()`, em ambientes Windows, para acompanhar visualmente a simulação.




## Formato de entrega

Este exercício aceita o seguinte tipo de arquivo:

- `Makefile`

Para que a entrega seja corrigida corretamente, o arquivo ZIP deve:

- conter obrigatoriamente um `Makefile` na raiz;
- conter apenas o comando de compilação na diretiva `all` (será executado `make all`);
- conter apenas o comando de execução na diretiva `run` (será executado `make run`).
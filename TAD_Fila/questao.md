# Exercício: Implementando o Tipo Abstrato Fila

## Objetivo
Praticar a implementação e manipulação de estruturas de dados do tipo Fila, utilizando um TAD (Tipo Abstrato de Dados).

## Enunciado
Especifique e implemente um Tipo Abstrato de Dados chamado TFila, que manipule dados do tipo float e ofereça os seguintes serviços:

- Exibir todos os elementos armazenados na fila;
- Esvaziar completamente a fila;
- Inserir (enfileirar) um novo elemento na fila (`enqueue`);
- Remover (desenfileirar) um elemento da fila (`dequeue`).
Importante: A fila segue o princípio FIFO (First In, First Out), ou seja, o primeiro elemento inserido será o primeiro a ser removido.
O programa principal (main.c) deve ler comandos via entrada padrão (teclado) para manipular a fila. Os comandos possíveis são:

- `-s`: exibe o estado atual da fila;
- `-c`: esvazia a fila;
- `-i X`: insere o valor `X` na fila;
- `-r`: remove um elemento da fila;
- `-f`: finaliza a execução do programa.
Importante: quando o comando -s for executado e a fila estiver vazia, o programa deverá imprimir exatamente:

```text
Fila vazia
```

## Exemplo de uso

### Entrada

```text
-i 1.2 -i 3.4 -i 5.6 -s -r -s -i 7.8 -s -c -s -f
```

### Saída esperada

```text
Fila: 1.2 3.4 5.6
Fila: 3.4 5.6
Fila: 3.4 5.6 7.8
Fila vazia
```



## Formato de entrega

Este exercício aceita o seguinte tipo de arquivo:

- `Makefile`

Para que a entrega seja corrigida corretamente, o arquivo ZIP deve:

- conter obrigatoriamente um `Makefile` na raiz;
- conter apenas o comando de compilação na diretiva `all` (será executado `make all`);
- conter apenas o comando de execução na diretiva `run` (será executado `make run`).
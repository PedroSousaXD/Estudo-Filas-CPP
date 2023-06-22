// Faça uma função para retornar o número de elementos da fila que possuem valor par.

#include <stdio.h>

#define TAMANHO_MAXIMO 100

typedef struct
{
  int itens[TAMANHO_MAXIMO];
  int frente;
  int tras;
} Fila;

void inicializarFila(Fila *fila)
{
  fila->frente = -1;
  fila->tras = -1;
}

int estaVazia(Fila *fila)
{
  return (fila->frente == -1 && fila->tras == -1);
}

int estaCheia(Fila *fila)
{
  return (fila->tras + 1) % TAMANHO_MAXIMO == fila->frente;
}

void enfileirar(Fila *fila, int valor)
{
  if (estaCheia(fila))
  {
    printf("Erro: Fila está cheia\n");
    return;
  }
  if (estaVazia(fila))
  {
    fila->frente = 0;
    fila->tras = 0;
  }
  else
  {
    fila->tras = (fila->tras + 1) % TAMANHO_MAXIMO;
  }
  fila->itens[fila->tras] = valor;
}

int desenfileirar(Fila *fila)
{
  if (estaVazia(fila))
  {
    printf("Erro: Fila está vazia\n");
    return -1;
  }
  int valorRemovido = fila->itens[fila->frente];
  if (fila->frente == fila->tras)
  {
    fila->frente = -1;
    fila->tras = -1;
  }
  else
  {
    fila->frente = (fila->frente + 1) % TAMANHO_MAXIMO;
  }
  return valorRemovido;
}

int contarElementosPares(Fila *fila)
{
  if (estaVazia(fila))
  {
    printf("Erro: Fila está vazia\n");
    return 0;
  }

  int contador = 0;

  int i;
  for (i = fila->frente; i != fila->tras; i = (i + 1) % TAMANHO_MAXIMO)
  {
    int valor = fila->itens[i];
    if (valor % 2 == 0)
    {
      contador++;
    }
  }

  // Último elemento da fila
  if (fila->itens[i] % 2 == 0)
  {
    contador++;
  }

  return contador;
}

int main()
{
  Fila fila;
  inicializarFila(&fila);

  enfileirar(&fila, 4);
  enfileirar(&fila, 3);
  enfileirar(&fila, 9);
  enfileirar(&fila, 2);
  enfileirar(&fila, 5);
  enfileirar(&fila, 8);

  int elementosPares = contarElementosPares(&fila);

  printf("Numero de elementos pares na fila: %d\n", elementosPares);

  return 0;
}
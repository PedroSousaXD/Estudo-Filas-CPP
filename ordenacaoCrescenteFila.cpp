// Considere uma lista contendo números inteiros. Escreva uma função para ordenar essa fila em ordem crescente de seus valores.

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

void ordenarFila(Fila *fila)
{
  int tempFila[TAMANHO_MAXIMO];
  int tamanho = 0;

  while (!estaVazia(fila))
  {
    int valor = desenfileirar(fila);
    int i = 0;

    while (i < tamanho && tempFila[i] < valor)
    {
      i++;
    }

    for (int j = tamanho; j > i; j--)
    {
      tempFila[j] = tempFila[j - 1];
    }

    tempFila[i] = valor;
    tamanho++;
  }

  for (int i = 0; i < tamanho; i++)
  {
    enfileirar(fila, tempFila[i]);
  }
}

void exibirFila(Fila *fila)
{
  int i;
  if (estaVazia(fila))
  {
    printf("Fila está vazia\n");
  }
  else
  {
    printf("Elementos da fila: ");
    for (i = fila->frente; i != fila->tras; i = (i + 1) % TAMANHO_MAXIMO)
    {
      printf("%d ", fila->itens[i]);
    }
    printf("%d\n", fila->itens[i]);
  }
}

int main()
{
  Fila fila;
  inicializarFila(&fila);

  enfileirar(&fila, 7);
  enfileirar(&fila, 3);
  enfileirar(&fila, 9);
  enfileirar(&fila, 2);
  enfileirar(&fila, 5);

  printf("Antes da ordenação:\n");
  exibirFila(&fila);

  ordenarFila(&fila);

  printf("Depois da ordenação:\n");
  exibirFila(&fila);

  return 0;
}
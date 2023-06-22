// Considere uma lista contendo números inteiros. Escreva uma função que calcule o maior, o menor e a media aritmética dos seus elementos.

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

void calcularEstatisticas(Fila *fila, int *maior, int *menor, float *media)
{
  if (estaVazia(fila))
  {
    printf("Erro: Fila está vazia\n");
    return;
  }

  int soma = 0;
  *maior = fila->itens[fila->frente];
  *menor = fila->itens[fila->frente];

  int i;
  for (i = fila->frente; i != fila->tras; i = (i + 1) % TAMANHO_MAXIMO)
  {
    int valor = fila->itens[i];
    soma += valor;

    if (valor > *maior)
    {
      *maior = valor;
    }

    if (valor < *menor)
    {
      *menor = valor;
    }
  }

  // Último elemento da fila
  soma += fila->itens[i];

  *media = (float)soma / (fila->tras - fila->frente + 1);
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

  int maior, menor;
  float media;

  calcularEstatisticas(&fila, &maior, &menor, &media);

  printf("Maior elemento: %d\n", maior);
  printf("Menor elemento: %d\n", menor);
  printf("Média aritmética: %.2f\n", media);

  return 0;
}

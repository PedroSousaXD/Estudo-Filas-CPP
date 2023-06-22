//Implemente a função reverso, que reposiciona os elementos na fila de tal forma que o início da fila torna-se o fim, e vice-versa.

#include <stdio.h>
#define TAMANHO_MAXIMO 100

typedef struct {
    int itens[TAMANHO_MAXIMO];
    int frente;
    int tras;
} Fila;

void inicializarFila(Fila *fila) {
    fila->frente = -1;
    fila->tras = -1;
}

int estaVazia(Fila *fila) {
    return (fila->frente == -1 && fila->tras == -1);
}

int estaCheia(Fila *fila) {
    return (fila->tras + 1) % TAMANHO_MAXIMO == fila->frente;
}

void enfileirar(Fila *fila, int valor) {
    if (estaCheia(fila)) {
        printf("Erro: Fila está cheia\n");
        return;
    }
    if (estaVazia(fila)) {
        fila->frente = 0;
        fila->tras = 0;
    } else {
        fila->tras = (fila->tras + 1) % TAMANHO_MAXIMO;
    }
    fila->itens[fila->tras] = valor;
}

int desenfileirar(Fila *fila) {
    if (estaVazia(fila)) {
        printf("Erro: Fila está vazia\n");
        return -1;
    }
    int valorRemovido = fila->itens[fila->frente];
    if (fila->frente == fila->tras) {
        fila->frente = -1;
        fila->tras = -1;
    } else {
        fila->frente = (fila->frente + 1) % TAMANHO_MAXIMO;
    }
    return valorRemovido;
}

void exibirFila(Fila *fila) {
    int i;
    if (estaVazia(fila)) {
        printf("Fila está vazia\n");
    } else {
        printf("Elementos da fila: ");
        for (i = fila->frente; i != fila->tras; i = (i + 1) % TAMANHO_MAXIMO) {
            printf("%d ", fila->itens[i]);
        }
        printf("%d\n", fila->itens[i]);
    }
}

void inverter(Fila *fila) {
    if (estaVazia(fila)) {
        return;
    }
    int item = desenfileirar(fila);
    inverter(fila);
    enfileirar(fila, item);
}

int main() {
    Fila fila;
    inicializarFila(&fila);

    enfileirar(&fila, 1);
    enfileirar(&fila, 2);
    enfileirar(&fila, 3);
    enfileirar(&fila, 4);
    enfileirar(&fila, 5);

    printf("Antes da inversão:\n");
    exibirFila(&fila);

    inverter(&fila);

    printf("Depois da inversão:\n");
    exibirFila(&fila);

    return 0;
}

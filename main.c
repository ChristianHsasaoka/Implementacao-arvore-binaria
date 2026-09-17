```c
#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *esquerda;
    struct No *direita;
} No;

No* inserir(No *raiz, int valor) {
    if (raiz == NULL) {
        No *novo = malloc(sizeof(No));
        novo->valor = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
        return novo;
    }

    if (valor < raiz->valor)
        raiz->esquerda = inserir(raiz->esquerda, valor);
    else
        raiz->direita = inserir(raiz->direita, valor);

    return raiz;
}

No* buscar(No *raiz, int valor) {
    if (raiz == NULL)
        return NULL;

    if (valor == raiz->valor)
        return raiz;

    if (valor < raiz->valor)
        return buscar(raiz->esquerda, valor);

    return buscar(raiz->direita, valor);
}

No* menor(No *raiz) {
    while (raiz->esquerda != NULL)
        raiz = raiz->esquerda;

    return raiz;
}

No* remover(No *raiz, int valor) {
    if (raiz == NULL)
        return NULL;

    if (valor < raiz->valor) {
        raiz->esquerda = remover(raiz->esquerda, valor);
    }
    else if (valor > raiz->valor) {
        raiz->direita = remover(raiz->direita, valor);
    }
    else {
        if (raiz->esquerda == NULL && raiz->direita == NULL) {
            free(raiz);
            return NULL;
        }

        if (raiz->esquerda == NULL) {
            No *temp = raiz->direita;
            free(raiz);
            return temp;
        }

        if (raiz->direita == NULL) {
            No *temp = raiz->esquerda;
            free(raiz);
            return temp;
        }

        No *temp = menor(raiz->direita);
        raiz->valor = temp->valor;
        raiz->direita = remover(raiz->direita, temp->valor);
    }

    return raiz;
}

void imprimir(No *raiz) {
    if (raiz != NULL) {
        imprimir(raiz->esquerda);
        printf("%d ", raiz->valor);
        imprimir(raiz->direita);
    }
}

int main() {
    No *raiz = NULL;

    raiz = inserir(raiz, 50);
    raiz = inserir(raiz, 30);
    raiz = inserir(raiz, 70);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 40);
    raiz = inserir(raiz, 60);
    raiz = inserir(raiz, 80);

    printf("Arvore: ");
    imprimir(raiz);

    int valor = 40;

    if (buscar(raiz, valor) != NULL)
        printf("\n%d encontrado!", valor);
    else
        printf("\n%d nao encontrado!", valor);

    valor = 50;

    if (buscar(raiz, valor) != NULL) {
        raiz = remover(raiz, valor);
        printf("\n%d removido!", valor);
    }
    else {
        printf("\n%d nao encontrado!", valor);
    }

    printf("\nArvore apos remocao: ");
    imprimir(raiz);

    return 0;
}
```

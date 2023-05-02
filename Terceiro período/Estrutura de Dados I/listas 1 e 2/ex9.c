/* Escreva uma função que realize o percurso em largura (BFS) de uma AB. Dica: utilizar fila.*/

#include <stdio.h>
#include <stdlib.h>

struct no{
    int chave;
    struct no *esq;
    struct no *dir;
};

struct fila{
    struct no *elem;
    struct fila *prox;
};

void percursoLargura(struct no *raiz);
struct fila *inserirFila(struct fila *inicio, struct no *elem);
struct no *removerFila(struct fila **inicio);
struct no *inserirArvore(struct no *raiz, int chave);

int main(){
    struct no *arvore = NULL;
    arvore = inserirArvore(arvore, 4);
    arvore = inserirArvore(arvore, 6);
    arvore = inserirArvore(arvore, 2);
    arvore = inserirArvore(arvore, 1);
    arvore = inserirArvore(arvore, 3);
    arvore = inserirArvore(arvore, 5);
    arvore = inserirArvore(arvore, 7);

    return 0;
}

void percursoLargura(struct no *raiz){
    struct fila *fila = NULL;
    fila = inserirFila(fila, raiz);

    while(fila){
        raiz = removerFila(&fila);
        if(raiz){
            fila = inserirFila(fila, raiz->esq);
            fila = inserirFila(fila, raiz->dir);
            printf("%d ", raiz->chave);
        }
    }
}

struct fila *inserirFila(struct fila *inicio, struct no *elem){
    struct fila *novo = malloc(sizeof(struct fila));
    novo->elem = elem;
    novo->prox = NULL;

    if(!inicio){
        return novo;
    }

    struct fila *aux = inicio;
    while(aux->prox){
        aux = aux->prox;
    }
    aux->prox = novo;

    return inicio;
}

struct no *removerFila(struct fila **inicio){
    struct no *aux;
    aux = (*inicio)->elem;
    (*inicio) = (*inicio)->prox;
    return aux; 
}

struct no *inserirArvore(struct no *raiz, int chave){
    if(!raiz){
        struct no *aux = malloc(sizeof(struct no));
        aux->chave = chave;
        aux->esq = aux->dir = NULL;
        return aux;
    }

    if(chave < raiz->chave){
        raiz->esq = inserirArvore(raiz->esq, chave);
    } else{
        raiz->dir = inserirArvore(raiz->dir, chave);
    }

    return raiz;
}
//calcular altura da árvore

#include <stdio.h>
#include <stdlib.h>

struct no{
    int valor;
    struct no *esq;
    struct no *dir;
};

struct no *inserir(struct no* raiz, int valor);
int maior(int a, int b);
int altura(struct no *raiz);

int main(){
    struct no *arvore = inserir(NULL, 5);
    arvore = inserir(arvore, 3);
    arvore = inserir(arvore, 7);
    arvore = inserir(arvore, 2);
    arvore = inserir(arvore, 4);
    arvore = inserir(arvore, 6);
    arvore = inserir(arvore,9);
    arvore = inserir(arvore, 10);
    arvore = inserir(arvore, 11);

    printf("altura da árvore: %d", altura(arvore));
    return 0;
}

struct no *inserir(struct no *raiz, int valor)
{
    if (raiz == NULL) //se não há elemento cria. 
    {
        struct no *aux = malloc(sizeof(struct no));
        aux->valor = valor;
        aux->esq = aux->dir = NULL;
        return aux;
    }

    if (valor < raiz->valor)
        raiz->esq = inserir(raiz->esq, valor);
    else
        raiz->dir = inserir(raiz->dir, valor);

    return raiz;
}

int maior(int a, int b){
    return (a>b) ? a : b;
}

int altura(struct no *raiz){
    if(raiz == NULL){
        return 0;
    }

    int direita = altura(raiz->dir);
    int esquerda = altura(raiz->esq);

    return (maior(direita, esquerda) + 1);
}
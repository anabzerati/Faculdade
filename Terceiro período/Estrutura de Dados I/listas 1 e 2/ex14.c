/* Escreva uma função que, dada uma ABB qualquer composta de inteiros, imprima todos os elementos menores que N. 
Protótipo: int *menores_valores (no *raiz, int N)*/

#include <stdio.h>
#include <stdlib.h>

struct no{
    int chave;
    struct no *esq;
    struct no *dir;
};

struct no *inserirNo(struct no *raiz, int chave);
void menores_valores(struct no *raiz, int N);

int main(){
    struct no *arvore = NULL;
    arvore = inserirNo(arvore, 4);
    arvore = inserirNo(arvore, 6);
    arvore = inserirNo(arvore, 2);
    arvore = inserirNo(arvore, 1);
    arvore = inserirNo(arvore, 3);
    arvore = inserirNo(arvore, 5);
    arvore = inserirNo(arvore, 7);

    menores_valores(arvore, 8);

    return 0;
}

struct no *inserirNo(struct no *raiz, int chave){
    if(!raiz){
        struct no *aux = malloc(sizeof(struct no));
        aux->chave = chave;
        aux->dir = aux->esq = NULL;
        return aux;
    }

    if(chave < raiz->chave){
        raiz->esq = inserirNo(raiz->esq, chave);
    } else{
        raiz->dir = inserirNo(raiz->dir, chave);
    }
    
    return raiz;
}

void menores_valores(struct no *raiz, int N){
    if(!raiz){
        return;
    }
    if(raiz->chave < N){
        printf("%d ", raiz->chave);
    }
    menores_valores(raiz->esq, N);
    menores_valores(raiz->dir, N);
}
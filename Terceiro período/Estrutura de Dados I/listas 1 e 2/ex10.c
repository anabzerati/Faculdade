/* A partir do conjunto C = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, construa duas propostas de árvores binárias de busca (ABB).*/

#include <stdio.h>
#include <stdlib.h>

struct no{
    int chave;
    struct no *esq;
    struct no *dir;
};

struct no *inserirNo(struct no *raiz, int chave);
void emOrdem(struct no *raiz);

int main(){
    struct no *arvore = NULL;
    arvore = inserirNo(arvore, 1);
    arvore = inserirNo(arvore, 2);
    arvore = inserirNo(arvore, 3);
    arvore = inserirNo(arvore, 4);
    arvore = inserirNo(arvore, 5);
    arvore = inserirNo(arvore, 6);
    arvore = inserirNo(arvore, 7);
    arvore = inserirNo(arvore, 8);
    arvore = inserirNo(arvore, 9);
    arvore = inserirNo(arvore, 10);

    struct no *arvore2 = NULL;
    arvore2 = inserirNo(arvore2, 5);
    arvore2 = inserirNo(arvore2, 3);
    arvore2 = inserirNo(arvore2, 2);
    arvore2 = inserirNo(arvore2, 1);
    arvore2 = inserirNo(arvore2, 4);
    arvore2 = inserirNo(arvore2, 8);
    arvore2 = inserirNo(arvore2, 6);
    arvore2 = inserirNo(arvore2, 7);
    arvore2 = inserirNo(arvore2, 9);
    arvore2 = inserirNo(arvore2, 10);

    emOrdem(arvore);
    printf("\n");
    emOrdem(arvore2);

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

void emOrdem(struct no *raiz){
    if(raiz){
        emOrdem(raiz->esq);
        printf("%d ", raiz->chave);
        emOrdem(raiz->dir);
    }
}
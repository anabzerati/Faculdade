/* Implemente uma função que encontra o menor elemento de uma ABB.*/

#include <stdio.h>
#include <stdlib.h>

struct no{
    int chave;
    struct no *esq;
    struct no *dir;
};

struct no *inserirNo(struct no *raiz, int chave);
struct no *buscaMenor(struct no *raiz);

int main(){
    struct no *arvore = NULL;
    arvore = inserirNo(arvore, 4);
    arvore = inserirNo(arvore, 6);
    arvore = inserirNo(arvore, 2);
    arvore = inserirNo(arvore, 1);
    arvore = inserirNo(arvore, 3);
    arvore = inserirNo(arvore, 5);
    arvore = inserirNo(arvore, 7);

    struct no *menor = buscaMenor(arvore);
    printf("%d", menor->chave);

    return 0;
}


struct no *buscaMenor(struct no *raiz){
    if(!raiz){
        return NULL;
    }
    if(!raiz->esq){
        return raiz;
    } 
    return buscaMenor(raiz->esq);
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
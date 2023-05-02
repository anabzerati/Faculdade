/* Implemente uma função para realizar buscas em uma ABB de números inteiros. Protótipo: no *busca (no *raiz, int elemento)*/

#include <stdio.h>
#include <stdlib.h>

struct no{
    int chave;
    struct no *esq;
    struct no *dir;
};

struct no *inserirNo(struct no *raiz, int chave);
struct no *busca(struct no *raiz, int elemento);

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

    struct no *encontrado = busca(arvore, 11);
    if(encontrado){
        printf("Encontrado, %d", encontrado->chave);
    } else{
        printf("Não encontrado");
    }

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

struct no *busca(struct no *raiz, int elemento){
    if(!raiz){
        return NULL;
    } else if(raiz->chave == elemento){
        return raiz;
    } else{
        if(elemento < raiz->chave){
            return busca(raiz->esq, elemento);
        } else{
            return busca(raiz->dir, elemento);
        }
    }
}
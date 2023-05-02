/* Implemente uma função que realiza a Busca + inserção de um número inteiro na ABB. Protótipo: no *busca_insere (no *raiz, int elemento).*/

#include <stdio.h>
#include <stdlib.h>

struct no{
    int chave;
    struct no *esq;
    struct no *dir;
};

struct no *busca_insere(struct no *raiz, int elemento){
    if(!raiz){
        struct no *aux = malloc(sizeof(struct no));
        aux->chave = elemento;
        aux->dir = aux->esq = NULL;
        return aux;
    }

    if(elemento < raiz->chave){
        raiz->esq = busca_insere(raiz->esq, elemento);
    } else{
        raiz->dir = busca_insere(raiz->dir, elemento);
    }
    
    return raiz;
}
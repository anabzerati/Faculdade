/* Escreva uma função não-recursiva para o percurso pós-ordem acima. Dica: utilizar pilha.
*/

#include <stdio.h>
#include <stdlib.h>

struct no{
    int chave;
    struct no *esq;
    struct no *dir;
};

struct pilha{
    struct no *elem;
    struct pilha *prox;
};

void percurso(struct no *raiz);
struct pilha *empilhar(struct pilha *topo, struct no *elem);
struct no *desempilhar(struct pilha **topo);
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

    percurso(arvore);

    return 0;
}

void percurso(struct no *raiz){
    if(!raiz){
        return;
    }

    struct pilha *topo;
    topo = empilhar(NULL, raiz);

    while(raiz || topo){
        while(raiz->esq){
            topo = empilhar(topo, raiz);
            raiz = raiz->esq;
        }
        if(raiz->dir){
            topo = empilhar(topo, raiz);
            raiz = raiz->dir;
        } else{
            struct no *aux = desempilhar(&topo);
            prinf("%d ", aux->chave);
            raiz = topo->elem;
        }
    }
    
}

struct pilha *empilhar(struct pilha *topo, struct no *elem){
    struct pilha *novo = malloc(sizeof(struct pilha));
    novo->elem = elem;
    novo->prox = topo;
    return novo; //novo topo
}

struct no *desempilhar(struct pilha **topo){
    struct no *aux;
    aux = (*topo)->elem;
    (*topo) = (*topo)->prox;
    return aux; //retorna desempilhado
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
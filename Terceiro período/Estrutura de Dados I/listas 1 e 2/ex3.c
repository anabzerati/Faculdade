/*
a) função que verifique se uma árvore binária está vazia - int vazia (no *raiz)
b) função que faça a alocação dinâmica na memória de um nó de uma AB - no *cria_no (char c, no *esq, no *dir)
c) função que libera na memória um nó da ABB - no *libera_no (no *t)
d) função que insere um nó à esquerda - int insere_esq (no *pai, char elemento)
e) função que percorre toda a árvore imprimindo seus valores (campo info) - void imprime_arvore (no *raiz) */

#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    char info;
    struct no *esq;
    struct no *dir;
} no;

int vazia(no *raiz);
no *cria_no(char c, no *esq, no *dir);
no *libera_no(no *t);
int insere_esq(no *pai, char elem);
void imprime_arvore(no *raiz);

int main(){
    return 0;
}

int vazia(no *raiz){
    return (raiz == NULL);
}

no *cria_no(char c, no *esq, no *dir){
    no *aux = malloc(sizeof(no));

    aux->info = c;
    aux->esq = esq;
    aux->dir = dir;

    return aux;
}

no *libera_no (no *t){
    free(t);
    return NULL;
}

int insere_esq(no *pai, char elem){
    if(!pai || pai->esq){
        return 0;
    }

    no *aux = malloc(sizeof(no));
    aux->info = elem;
    aux->esq = aux->dir = NULL;
    
    pai->esq = aux;

    return 1;
}

void imprime_arvore(no *raiz){
    if(raiz){
        imprime_arvore(raiz->esq);
        printf("%c ", raiz->info);
        imprime_arvore(raiz->dir);
    }
}
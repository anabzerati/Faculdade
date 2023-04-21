//verificar se árvore é de busca ou nao

#include <stdio.h>
#include <stdlib.h>

struct no{
    int valor;
    struct no *esq;
    struct no *dir;
};

int verificaABB(struct no *root);
struct no *inserir(struct no *raiz, int valor);

int main(){
    struct no *arvore = inserir(NULL, 5);
    arvore = inserir(arvore, 3);
    arvore = inserir(arvore, 7);
    arvore = inserir(arvore, 2);
    arvore = inserir(arvore, 4);
    arvore = inserir(arvore, 6);
    arvore = inserir(arvore,9);

    printf("%d", verificaABB(arvore));
    return 0;
}

int verificaABB(struct no *root){
    if(root == NULL){
        return 1;
    }
    if(root->dir->valor < root->valor || root->esq->valor > root->valor){
        return 0;
    }

    verificaABB(root->esq);
    verificaABB(root->dir);
}

struct no *inserir(struct no *raiz, int valor){
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
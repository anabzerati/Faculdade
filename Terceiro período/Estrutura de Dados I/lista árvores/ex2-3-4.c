/*calcular número de nós (total, folha e não folha)*/

#include <stdio.h>
#include <stdlib.h>

struct no{
    int valor;
    struct no *esq;
    struct no *dir;
};

int contaNos(struct no *raiz);
int contaNosNaoFolha(struct no *raiz);
int contaNosFolha(struct no* raiz);
struct no *inserir(struct no* raiz, int valor);

int main(){
    struct no *arvore = inserir(NULL, 5);
    arvore = inserir(arvore, 3);
    arvore = inserir(arvore, 7);
    arvore = inserir(arvore, 2);
    arvore = inserir(arvore, 4);
    arvore = inserir(arvore, 6);
    arvore = inserir(arvore,9);

    printf("%d\n", contaNos(arvore));
    printf("%d não folhas\n", contaNosNaoFolha(arvore));
    printf("%d folhas\n", contaNosFolha(arvore));


    return 0;
}

int contaNos(struct no *raiz){
    if(raiz == NULL){ //chegou nos nós folha
        return 0;
    }
    int direita = contaNos(raiz->dir);
    int esquerda = contaNos(raiz->esq);

    return (direita + esquerda + 1);

}

int contaNosNaoFolha(struct no *raiz){
    if(raiz->dir == NULL || raiz->esq == NULL){ //para um elemento antes dos nós folha
        return 0;
    }
    int direita = contaNosNaoFolha(raiz->dir);
    int esquerda = contaNosNaoFolha(raiz->esq);

    return (direita + esquerda + 1);

}

int contaNosFolha(struct no* raiz){
    return (contaNos(raiz) - contaNosNaoFolha(raiz));
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
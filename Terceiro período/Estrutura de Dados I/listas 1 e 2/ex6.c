/*
a) Função que retorna o maior elemento da árvore (dado um campo chave inteiro).
b) Função que retorne o total de nós folhas de uma AB.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int info;
    struct no *esq;
    struct no *dir;
} no;

no *maior_elemento(no *raiz);
int total_nos(no *raiz);

int main(){
    return 0;
}

no *maior_elemento(no *raiz){
    no *maior, *atual, *esq, *dir;

    atual = raiz;
    maior = atual;

    if(raiz->esq){
        esq = maior_elemento(raiz->esq);

        if(esq > maior){
            maior = esq;
        }
    }

    if(raiz->dir){
        dir = maior_elemento(raiz->dir);

        if(dir > maior){
            maior = dir;
        }
    }

    return maior;
}

int total_nos(no *raiz){
    if(!raiz){
        return 0;
    }

    int esq = total_nos(raiz->esq);
    int dir = total_nos(raiz->dir);

    return (esq + dir + 1);
}
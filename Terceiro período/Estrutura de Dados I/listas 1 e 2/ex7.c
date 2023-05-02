/* Escreva uma função que verifique se uma árvore binária é cheia. Definição: uma AB é dita cheia se todos os seus nós têm exatamente 0 ou 2 filhos
(estritamente binária), e todas as folhas estão no mesmo nível.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int info;
    struct no *esq;
    struct no *dir;
} no;

int cheia(no *raiz);
int estritamente_binaria(no *raiz);
int altura(no *raiz);
int nivel(no *raiz);

int main(){
    return 0;
}

int estritamente_binaria(no *raiz){
    if(!raiz){
        return 1;
    }

    if((raiz->esq && !raiz->dir) || (!raiz->esq && raiz->dir)){ //só tem um filho 
        return 0;
    }

    int esq = estritamente_binaria(raiz->esq);
    int dir = estritamente_binaria(raiz->dir);

    return (esq < dir) ? esq : dir; //retorna o menor (zero se tiver)
} 

int altura(no *raiz){
    if(!raiz){
        return 0;
    }

    int esq = altura(raiz->esq);
    int dir = altura(raiz->dir);

    return ((esq > dir) ? esq : dir) + 1;
}

int nivel(no *raiz){
    if(!raiz){
        return 1;
    }

    int esq = altura(raiz->esq);
    int dir = altura(raiz->dir);
    
    return (esq == dir);
} 

int cheia(no *raiz){
    int n = nivel(raiz);
    int est_bin = estritamente_binaria(raiz);
    return (n < est_bin) ? n : est_bin; //retorna o menor (zero, se tiver);
}
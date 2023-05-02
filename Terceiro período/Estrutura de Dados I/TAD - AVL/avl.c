#include <stdio.h>
#include <stdlib.h>
#include "avl.h";

int maior(int a, int b){
    return (a > b) ? a : b;
}

int alturaNo(no *no){
    if(!no){
        return 0;
    }

    return no->altura;
}

int fatorBalanecamento(no *no){
    if(!no){
        return 0;
    }

    return (alturaNo(no->dir) - alturaNo(no->esq));
}

void rotacaoEsquerda(no *raiz){
    if(!raiz){
        return;
    }

    no *aux1, *aux2;
    aux1 = raiz->dir; //nova raiz
    aux2 = aux1->esq; //se tiver filhos

    aux1->esq = raiz; //troca
    raiz->dir = aux2;

    raiz->altura = maior(alturaNo(raiz->esq), alturaNo(raiz->dir)) + 1; //recalcula alturas
    aux1->altura = maior(alturaNo(aux1->esq), alturaNo(aux1->dir)) + 1;

    return aux1; //nova raiz
}


void rotacaoDireita(no *raiz){
    if(!raiz){
        return;
    }

    no *aux1, *aux2;
    aux1 = raiz->esq;
    aux2 = aux1->dir;

    aux1->dir = raiz;
    raiz->esq = aux2;

    raiz->altura = maior(alturaNo(raiz->esq), alturaNo(raiz->dir)) + 1; //recalcula alturas
    aux1->altura = maior(alturaNo(aux1->esq), alturaNo(aux1->dir)) + 1;

    return aux1;
}


void rotacaoEsquerdaDireita(no *raiz){
    raiz->esq = rotacaoEsquerda(raiz->esq);
    return rotacaoDireita(raiz);
}


void rotacaoDireitaEsquerda(no *raiz){
    raiz->dir = rotacaoDireita(raiz->dir);
    return rotacaoEsquerda(raiz);
}

no *inserir(no *raiz, int chave){
    if(!raiz){
        no *novo = malloc(sizeof(no));

        novo->chave = chave;
        novo->esq = novo->dir = NULL;
        novo->altura = 0;

        return novo;
    }

    if(raiz->chave > chave){
        raiz->esq = inserir(raiz->esq, chave);
    } else{
        raiz->dir = inserir(raiz->dir, chave);
    }

    raiz->altura = maior(alturaNo(raiz->esq), alturaNo(raiz->dir)) + 1;

    raiz = balancear(raiz);

    return raiz;
}


no *remover(no *raiz, int chave){
    if(!raiz){
        return NULL;
    }

    if(raiz->chave == chave){ //encontrou
        if(!raiz->esq && !raiz->dir){
            free(raiz);

            return NULL;
        } else if(raiz->esq && raiz->dir){
            no *aux = raiz->esq;
            
            while(aux->dir){
                aux = aux->dir;
            }

            raiz->chave = aux->chave;
            aux->chave = chave;

            raiz->esq = remover(raiz->esq, chave);
            return raiz;
        } else{
            no *aux;

            if(raiz->esq){
                aux = raiz->esq;
            } else{
                aux = raiz->dir;
            }

            free(raiz);
            return aux;
        }
    } else{ //buscando elemento
        if(raiz->chave > chave){
            raiz->esq = remover(raiz->esq, chave);
        } else{
            raiz->dir = remover(raiz->dir, chave);
        }
    }

    raiz->altura = maior(alturaNo(raiz->esq), alturaNo(raiz->dir)) + 1;

    raiz = balancear(raiz);

    return raiz;
}

no *balancear(no *raiz){
    int fb = fatorBalanecamento(raiz);

    if(fb < -1 && fatorBalanecamento(raiz->dir) <= 0){
        raiz = rotacaoEsquerda(raiz);
    } else if(fb > 1 && fatorBalanecamento(raiz->esq) >= 0){
        raiz = rotacaoDireita(raiz);
    } else if(fb > 1 && fatorBalanecamento(raiz->esq) < 0){
        raiz = rotacaoEsquerdaDireita(raiz);
    } else if(fb < -1 && fatorBalanecamento(raiz->dir) > 0){
        raiz = rotacaoDireitaEsquerda(raiz);
    }

    return raiz;
}
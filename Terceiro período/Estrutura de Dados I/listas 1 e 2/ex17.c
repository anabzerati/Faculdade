/* executar o processo de remoção (cumulativo) dos seguintes nós: 100 – 150 – 80 – 270 - 400*/

#include <stdio.h>
#include <stdlib.h>

struct no{
    int chave;
    struct no *esq;
    struct no *dir;
};

struct no *inserirNo(struct no *raiz, int chave);
struct no *removerNo(struct no *raiz, int chave);
void emOrdem(struct no *raiz);

int main(){
    struct no *arvore = NULL;
    arvore = inserirNo(arvore, 200);
    arvore = inserirNo(arvore, 100);
    arvore = inserirNo(arvore, 300);
    arvore = inserirNo(arvore, 80);
    arvore = inserirNo(arvore, 150);
    arvore = inserirNo(arvore, 250);
    arvore = inserirNo(arvore, 400);
    arvore = inserirNo(arvore, 70);
    arvore = inserirNo(arvore, 120);
    arvore = inserirNo(arvore, 220);
    arvore = inserirNo(arvore, 270);
    arvore = inserirNo(arvore, 350);
    arvore = inserirNo(arvore, 500);
    arvore = inserirNo(arvore, 65);
    arvore = inserirNo(arvore, 79);
    arvore = inserirNo(arvore, 110);
    arvore = inserirNo(arvore, 130);
    arvore = inserirNo(arvore, 260);

    emOrdem(arvore);
    printf("\n");

    arvore = removerNo(arvore, 100);
    arvore = removerNo(arvore, 150);
    arvore = removerNo(arvore, 80);
    arvore = removerNo(arvore, 270);
    arvore = removerNo(arvore, 400);

    emOrdem(arvore);

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

struct no *removerNo(struct no *raiz, int chave){
    if(!raiz){ //caso base
        return NULL;

    } else{

        if(raiz->chave == chave){ //encontrou

            if(!raiz->esq && !raiz->dir){ //sem filhos
                free(raiz);
                return NULL;

            } else if(raiz->esq && raiz->dir){ //dois filhos
                struct no *aux = raiz->esq;

                while(aux->dir){ //busca o mais à direita da esquerda (maior dos menores)
                    aux = aux->dir;
                }

                raiz->chave = aux->chave;
                aux->chave = chave; //troca dos elementos

                raiz->esq = removerNo(raiz->esq, chave);

                return raiz;

            } else{ //um filho
                struct no *aux;

                if(raiz->dir){
                    aux = raiz->dir;
                } else{
                    aux = raiz->esq;
                }

                return aux;
            }

        } else{ //busca 

            if(chave < raiz->chave){
                raiz->esq = removerNo(raiz->esq, chave);
            } else{
                raiz->dir = removerNo(raiz->esq, chave);
            }

            return raiz;
        }
    }
}

void emOrdem(struct no *raiz){
    if(raiz){
        emOrdem(raiz->esq);
        printf("%d ", raiz->chave);
        emOrdem(raiz->dir);
    }
}
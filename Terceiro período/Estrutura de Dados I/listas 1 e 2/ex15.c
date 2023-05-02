/* implemente o seguinte algoritmo de rebalanceamento:
A partir de um vetor ordenado de valores distintos, realizar os seguintes passos:
1. O registro do meio é inserido na ABB vazia (como raiz).
2. Tome a metade esquerda do array, e então repita o passo 1) para a sub-árvore esquerda.
3. Aplique a mesma ideia para a metade direita e sub-árvore direita.
4. Repita o processo até não poder dividir mais.
*/

#include <stdio.h>
#include <stdlib.h>

struct no{
    int chave;
    struct no *esq;
    struct no *dir;
};

struct no *balancear(int *vetor, int i, int j, struct no *raiz);
struct no *inserir(struct no *pai, int num, int op);

int main(){
    int vetor[5] = {1,2,3,4,5};
    struct no *raiz = balancear(vetor, 0, 4, NULL);

    return 0;
}

struct no *balancear(int *vetor, int i, int j, struct no *raiz){
    raiz = inserir(raiz, vetor[(i+j)/2], 0);

    if(i < j){
        balancear(vetor, i, j/2, raiz->esq);
        balancear(vetor, j/2, j, raiz->dir);
    }

    return raiz;
}

struct no *inserir(struct no *pai, int num, int op){
    struct no *novo = malloc(sizeof(struct no));
    novo->chave = num;
    novo->esq = novo->dir = NULL;

    if(!pai){    
        return novo;
    }

    if(op == 1){ //inserir à esquerda
        pai->esq = novo;
    } else{
        pai->dir = novo;
    }

    return pai;
}
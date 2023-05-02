#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int chave;
    struct no *esq;
    struct no *dir;
    int altura;
} no;


int maior(int a, int b);
int alturaNo(no *no);
int fatorBalanecamento(no *no);
void rotacaoEsquerda(no *raiz);
void rotacaoDireita(no *raiz);
void rotacaoEsquerdaDireita(no *raiz);
void rotacaoDireitaEsquerda(no *raiz);
no *inserir(no *raiz, int chave);
no *remover(no *raiz, int chave);
no *balancear(no *raiz);
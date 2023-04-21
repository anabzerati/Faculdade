/*buscar nó impar e maior nó*/

#include <stdio.h>
#include <stdlib.h>

struct no{
    int valor;
    struct no *esq;
    struct no *dir;
};

void insereDireita(struct no *pai, int valor);
void insereEsquerda(struct no *pai, int valor);
struct no *criaRaiz(struct no *t, int valor);
struct no *buscarImpar(struct no *t);
struct no *buscarMaior(struct no *t);

int main(){
    struct no *t = NULL;
	t = criaRaiz(t, 4);
	
	//Filhos do 4
	insereEsquerda(t, 2);
	insereDireita(t, 6);
	
	//Filhos do 2
	insereEsquerda(t->esq, 1);
	insereDireita(t->esq, 3);
	
	//Filhos do 6
	insereEsquerda(t->dir, 5);
	insereDireita(t->dir, 7);

    struct no *aux = buscarImpar(t);
    printf("%d\n", aux->valor);

    struct no *maior = buscarMaior(t);
    printf("%d", maior->valor);

    return 0;
}

struct no *criaRaiz(struct no *t, int valor){
	t = malloc(sizeof(struct no));
	
	if(!t){
		printf("Nao foi possivel criar o no raiz.\n");
		return NULL;
	}
	
	t->valor = valor;
	t->dir = NULL;
	t->esq = NULL;
	
	return(t);		

}

void insereDireita(struct no *pai, int valor){
	if (!pai){
		return;
	}
	if (pai->dir != NULL){
		printf("Ja possui filho a direita. \n");
		return;
	}
	pai->dir = malloc(sizeof(struct no));
	if(!pai->dir){
		printf("Nao foi possivel criar o no.\n");
		return;
	}
	pai->dir->valor = valor;
	pai->dir->dir = NULL;
	pai->dir->esq = NULL;
}

void insereEsquerda(struct no *pai, int valor){
	if (!pai){
		return;
	}
	if (pai->esq != NULL){
		printf("Ja possui filho a esquerda. \n");
		return;
	}
	pai->esq = malloc(sizeof(struct no));
	if(!pai->esq){
		printf("Nao foi possivel criar o no.\n");
		return;
	}
	pai->esq->valor = valor;
	pai->esq->dir = NULL;
	pai->esq->esq = NULL;
}

struct no *buscarImpar(struct no *t){
    if(t == NULL){
        return NULL;
    }
    if(t->valor % 2 == 1){
        return t;
    } else{
        return buscarImpar(t->esq);
        return buscarImpar(t->dir);
    }
}

struct no *buscarMaior(struct no *t){
    struct no *maior, *atual, *esq, *dir;

    atual = t;
    maior = atual;
    if(t->esq != NULL){
        esq = buscarMaior(t->esq);

        if(esq > maior){
            maior = esq;
        }
    }
    if(t->dir != NULL){
        dir = buscarMaior(t->dir);

        if(dir > maior){
            maior = dir;
        }
    }

    return maior;
}
#include <stdlib.h>
#include <stdio.h>
#include "arvoreB.h"

int main (){
	tree t = Definir();
	
	tipo_dado d;
	
	d.valor = 4;
	t = criaRaiz(t, d);
	
	//Filhos do 4
	d.valor = 2;
	insereEsquerda(t, d);
	d.valor = 6;
	insereDireita(t, d);
	
	//Filhos do 2
	d.valor = 1;
	insereEsquerda(t->esq, d);
	d.valor = 3;
	insereDireita(t->esq, d);
	
	//Filhos do 6
	d.valor = 5;
	insereEsquerda(t->dir, d);
	d.valor = 7;
	insereDireita(t->dir, d);
	
	//Filho do 5
	//d.valor = 8;
	//insereDireita(t->dir->esq, d);
	
	printf("\n\n Pre Ordem \n");	
	preOrdem(t);
	
	printf("\n\n Em Ordem \n");	
	inOrdem(t);
	
	printf("\n\n P�s Ordem \n");	
	posOrdem(t);
	
	return 0;
}

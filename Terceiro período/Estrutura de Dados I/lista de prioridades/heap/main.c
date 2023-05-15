#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

int main(){    	
	FilaPri *filapri = Cria(10); 
	
	TipoElem elem1 = {10};
	TipoElem elem2 = {20};
	TipoElem elem3 = {30};
	TipoElem elem4 = {1};
	TipoElem elem5 = {15};
	
	Insere(filapri, elem1);
	Insere(filapri, elem2);
	Insere(filapri, elem3);
	Insere(filapri, elem4);
	Insere(filapri, elem5);
	
	Imprime(filapri);
	printf("\n");
	Heapsort(filapri);
	Imprime(filapri);
	
	printf("Elemento removido: %d\n", RemoveMaior(filapri).chave);
	Imprime(filapri);
	
	printf("No vet[%d] = %d alterado a prioridade p/ %d\n",1,filapri->vet[1],25);
	AlteraPrioridade(filapri, 1, 25);
	
	printf("Elemento removido: %d\n", RemoveMaior(filapri).chave);
	Imprime(filapri);
	printf("Elemento removido: %d\n", RemoveMaior(filapri).chave);
	Imprime(filapri);
	
	free(filapri->vet);
	free(filapri);
    return 0;
}
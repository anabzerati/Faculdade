#include <stdlib.h>     
#include <stdio.h>      
#include "heap.h"

int Vazia(FilaPri *filapri){
    return(filapri->n == 0);
}

int Cheia(FilaPri *filapri){
    return(filapri->n == filapri->tam);
}

void Permuta(TipoElem *a, TipoElem *b){
    TipoElem aux = *a;
    *a = *b;
    *b = aux;
}

FilaPri *Cria(int tam){
    FilaPri *nova = malloc(sizeof(FilaPri));

    nova->n = 0;
    nova->tam = tam;
    nova->vet = malloc(tam * sizeof(TipoElem));

    return nova;
}

void Insere(FilaPri *filapri, TipoElem elem){
    filapri->vet[filapri->n] = elem; //insere na última posição

	filapri->n++; //aumenta quantidade de elementos

	SobeNoHeap(filapri, filapri->n-1); //chama função para adequar posições pela prioridade
}

void SobeNoHeap(FilaPri *filapri, int indice){
    if (indice > 0 && filapri->vet[pai(indice)].chave < filapri->vet[indice].chave){ //se o indice é válido e o pai é menor que o filho
		Permuta (&filapri->vet[indice], &filapri->vet[pai(indice)]); //troca pai e filho

		SobeNoHeap(filapri, pai(indice)); //verifica para o novo pai
	}
}

TipoElem RemoveMaior(FilaPri* filapri){
    TipoElem aux = filapri->vet[0]; //guarda maior

    Permuta(&filapri->vet[0], &(filapri->vet[filapri->n-1])); //troca maior e último
    filapri->n--; //"remove" último (agora o maior)

	DesceNoHeap(filapri, 0);

	return aux; //retorna removido
}

void DesceNoHeap(FilaPri *filapri, int indice){
    int maiorFilho;
	if (fEsq(indice) < filapri->n) { //valida indice
		maiorFilho = fEsq(indice); //palpite

		if (fDir(indice) < filapri->n && filapri->vet[fEsq(indice)].chave < filapri->vet[fDir(indice)].chave) //se tem filho direito e ele é maior que o esquerdo
			maiorFilho = fDir(indice);

		if (filapri->vet[indice].chave < filapri->vet[maiorFilho].chave){ //se pai for menor que filho
			Permuta (&filapri->vet[indice], &filapri->vet[maiorFilho]);
			DesceNoHeap (filapri, maiorFilho);
		}
	}
}

void AlteraPrioridade(FilaPri *filapri, int indice, int valor){
    if (filapri->vet[indice].chave < valor){ //vai aumentar prioridade
		filapri->vet[indice].chave = valor;
		SobeNoHeap(filapri, indice);
	} else{ //vai diminuir prioridade
		filapri->vet[indice].chave = valor;
		DesceNoHeap(filapri, indice);
	}	
}

void ConstroiHeap(FilaPri *filapri){
    int i, meio = (filapri->n-1)/2;
	for (i = meio; i >= 0; i--)
		DesceNoHeap(filapri, i);
}

void Heapsort(FilaPri *filapri){
    int i, meio = (filapri->n-1)/2;

	for (i = meio; i >= 0; i--)
		DesceNoHeap (filapri, i);
		
	i = filapri->n;	

	while (i > 1) 
	{
	 	Permuta (&filapri->vet[0], &filapri->vet[i-1]);
	 	i--;
	 	DesceNoHeap(filapri, 0);
	}
}

void Imprime(FilaPri *filapri){
    int i;
	for(i = 0; i < filapri->n; i++) {
        printf("%d ", filapri->vet[i].chave);
    }
}
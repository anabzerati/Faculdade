/*Crie um programa que contenha um array de inteiros contendo 5 elementos. Utilizando
apenas aritmetica de ponteiros, leia esse array do teclado e imprima o dobro de cada ´
valor lido*/

#include <stdio.h>
#include <stdlib.h>

void printa_dobro(int vetor[]);

int main() {
	int vetor[5], i;
	
	for (i=0; i<5; i++) {
		scanf("%d", &vetor[i]);
	}

    printa_dobro(vetor);
	
	return 0;
}

void printa_dobro(int vetor[]){
    int i;
    for(i=0; i<5; i++){
        printf("%d ", 2**(vetor+i));
    }
}
/*Crie um programa que contenha um array de float contendo 10 elementos. Imprima o
enderec¸o de cada posic¸ao desse array.*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    float *pv;
    int i;
    pv = malloc(10*sizeof(int)); //ponteiro de vetor de inteiros com 10 elementos

    for(i=0; i<10; i++){
        printf("\n%p", (pv+i));
    }

    return 0;
}
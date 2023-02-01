//selection sort

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define n 5

int main(){
    int vetor[n], menor, aux;

//vetor desordenado
    srand(time(NULL));
    for(int i=0; i<n; i++){
        vetor[i] = rand()%10;
        printf("\n%d", vetor[i]);
    }

//ordenando
    for(int i=0; i<n-1; i++){
        menor = i;
        for(int j=i+1; j<n; j++){
            if(vetor[j]<vetor[i]){
                menor = j;
            }
        }

        if(menor != i){
            aux = vetor[i];
            vetor [i] = vetor[menor];
            vetor [menor] = aux;
        }

    }

//printando vetor em ordem crescente
    for(int i=0; i<n; i++){
        printf("\n%d", vetor[i]);
    }


    return 0;
}
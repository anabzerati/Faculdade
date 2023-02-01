//bubble sort 2

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define n 5

int main(){
    int vetor[n], aux;

    srand(time(NULL));
    for(int i=0; i<n; i++){
        vetor[i] = rand()%10;
        printf("\n%d", vetor[i]);
    }

//ordenando
    for(int i=1; i<n; i++){
        for(int j=0; j<n-1; j++){
            if(vetor[j]>vetor[j+1]){
                aux = vetor[j+1];
                vetor[j+1] = vetor[j];
                vetor[j] =  aux;
            }
        }
    }

    printf("\n");
    for(int i=0; i<n; i++){
        printf("\n%d", vetor[i]);
    }
}
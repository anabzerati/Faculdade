//insertion sort

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define max 5

int main(){
    int vetor[max], elemento, i, k;

  srand(time(NULL));
    for(int i=0; i<max; i++){
        vetor[i] = rand()%10;
        printf("\n%d", vetor[i]);
    }

  printf("\n");

    for (int k = 1; k < max; k++) {
        elemento = vetor[k];
        for (i = k-1; i >= 0 && elemento < vetor[i]; i--)
            vetor[i+1] = vetor[i];
        vetor[i+1]=elemento;
    }

    for(int i=0; i<max; i++){
        printf("\n%d", vetor[i]);
  }

    return 0;
}
//buble sort wallace

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define n 5

int main(){
    int vetor[n], aux;

//vetor desordenado
    srand(time(NULL));
    for(int i=0; i<n; i++){
        vetor[i] = rand()%10;
        printf("\n%d", vetor[i]);
    }

//ordenando
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(vetor[j]<vetor[i]){
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
    }

    printf("\n");
    for(int i=0; i<n; i++){
        printf("\n%d", vetor[i]);
    }
    
    return 0;
}
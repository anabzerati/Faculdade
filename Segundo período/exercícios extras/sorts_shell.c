/*shell sort*/

#include <stdio.h>

void shellsort(int *vet, int tam);

int main(){
    int vet[15] = {15,3,12,8,9,0,4,6,3,2,11,13,15,2,3}, i;

    shellsort(vet, 15);

    for(i=0; i<15; i++){
        printf("%d ", vet[i]);
    }

    return 0;
}

void shellsort(int *vet, int tam){
    int i, j, k, l, valor;
    k=1;

    while(k<tam/2){
        k = 3*k + 1;
    } 

    while(k>1){
        k = k/3;
        for(l=0; i<k; l++){
            for(i=l+k; i<tam; i=i+k){
                valor = vet[i];
                j = i;
                while(j-k>=0 && valor<vet[j-k]){
                    vet[j] = vet[j-k];
                    j = j-k;
                }
                vet[j] = valor;
            }   
        }
    }
}
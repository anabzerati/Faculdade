/*insertion sort*/

#include <stdio.h>

void insertionsort(int *vet, int tam);

int main(){
    int vet[5] = {10,3,5,1,6}, i;

    insertionsort(vet, 5);

    for(i=0; i<5; i++){
        printf("%d ", vet[i]);
    }

    return 0;
}

void insertionsort(int *vet, int tam){
    int i, j, aux;

    for(i=1; i<tam; i++){
        j = i;
        aux = vet[j];
        while(j>0 && vet[j-1]>aux){
            vet[j] = vet[j-1];
            j--;
        }
        vet[j] = aux;
    }
}
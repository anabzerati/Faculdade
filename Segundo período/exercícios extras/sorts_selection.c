/*selection sort*/

#include <stdio.h>

void selectionsort(int *vet, int tam);
void troca(int *primeiro, int *segundo);

int main(){
    int vet[5] = {10,6,3,7,1};
    int i;

    selectionsort(vet, 5);

    for(i=0; i<5; i++){
        printf("%d ", vet[i]);
    }

    return 0;
}

void selectionsort(int *vet, int tam){
    int menor, i, j;

    for(i=0; i<tam-1; i++){
        menor = i;
        for(j=i+1; j<tam; j++){
            if(vet[j]<vet[menor]){
                menor = j;
            }
        }
        if(menor!=i){
            troca(&vet[i], &vet[menor]);
        }
    }
}

void troca(int *primeiro, int *segundo){
    int aux;
    aux = *primeiro;
    *primeiro = *segundo;
    *segundo = aux;
}

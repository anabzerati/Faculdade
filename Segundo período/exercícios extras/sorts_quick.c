#include <stdio.h>

void quicksort(int *vet, int comeco, int final){
    int i, pivo, bigger;
    if(comeco<final){
        pivo = final;
        bigger = comeco;
        for(i=comeco; i<final; i++){
            if(vet[i]<vet[pivo]){
                troca(&vet[i], &vet[bigger]);
                bigger++;
            }
        }
        troca(&vet[pivo], &vet[bigger]);
        quicksort(vet, comeco, bigger-1);
        quicksort(vet, bigger+1, final);
    }
}

void troca(int *primeiro, int *segundo)
{
    int aux;
    aux = *primeiro;
    *primeiro = *segundo;
    *segundo = aux;
}

int main(){
    int vet[10] = {5,4,6,3,9,10,7,2,1,4};

    quicksort(vet, 0, 9);

    for(int i=0; i<10; i++){
        printf("%d ", vet[i]);
    }

    return 0;
}
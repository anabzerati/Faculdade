/*merge sort*/

#include <stdio.h>

void mergesort(int *vet, int *aux, int i, int j);

int main(){
    int vet[15] = {15,3,12,8,9,0,4,6,3,2,11,13,15,2,3}, i, *aux;
    aux = calloc(15, sizeof(int));

    mergesort(vet, aux, 0, 15);

    for(i=0; i<15; i++){
        printf("%d ", vet[i]);
    }

    return 0;
}

void mergesort(int *vet, int *aux, int i, int j){
    int k, ptr_esq, ptr_dir, mid;
    mid = (i+j)/2;
    
    if(i>=j){
        return;
    }

    mergesort(vet, aux, i, mid);
    mergesort(vet, aux, mid+1, j);

    ptr_esq = i;
    ptr_dir = mid;
    k=0;

    while(ptr_esq<=mid && ptr_dir<=j){
        if(vet[ptr_dir]>vet[ptr_esq]){
            aux[k] = vet[ptr_dir];
            ptr_dir++;
        } else{
            aux[k] = ptr_esq;
            ptr_esq++;
        }
        k++;
    }

    if(ptr_esq>mid){
        while(ptr_dir<=j){
            aux[k] = vet[ptr_dir];
            k++;
            ptr_dir++;
        }
    } else{
        while(ptr_esq<=mid){
            aux[k] = vet[ptr_esq];
            k++;
            ptr_esq++;
        }
    }

    for(k=i; k<j; k++){
        vet[k] = aux[k];
    }
}
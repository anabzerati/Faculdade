/*busca binaria recursiva*/

#include <stdio.h>

int binarysearch(int *vet, int comeco, int fim, int a);

int main(){
    int vet[5] = {1,2,3,4,5}, pos;

    pos = binarysearch(vet, 0, 5, 10);
    printf("%d", pos);
    
    return 0;
}

int binarysearch(int *vet, int comeco, int fim, int a){
    int mid = (comeco+fim)/2;

    if(vet[comeco] == a){
        return comeco;
    } else if(vet[fim] == a){
        return fim;
    } else if(vet[mid] == a){
        return mid;
    } else if(comeco == fim){
        return -1;
    } else{
        if(a>vet[mid]){
            return binarysearch(vet, mid+1, fim, a);
        } else{
            return binarysearch(vet, comeco, mid-1, a);
        }
    }
}
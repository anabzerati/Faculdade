/*busca binaria iterativa*/

 int binarysearch(int *vet, int tam, int a);

 #include <stdio.h>

 int main(){
    int vet[5] = {1,2,3,4,5}, pos;

    pos = binarysearch(vet, 5, 10);

    printf("%d", pos);

    return 0;
 }

  int binarysearch(int *vet, int tam, int a){
    int comeco, meio, fim;
    comeco = 0;
    fim = tam-1;

    while(comeco<=fim){
        meio = (comeco+fim)/2;
        if(vet[meio] == a){
            return meio;
        }

        if(a>vet[meio]){
            comeco = meio+1;
        } else{
            fim = meio-1;
        }
    }

    return -1;
  }
#include <stdio.h>
#include <stdlib.h>

long int binarysearch(long int *vet, long int tam, long int buscado);

int main() {
  long int N, M, i, buscado, posicao;

  scanf("%ld", &N);
  long int vet[N];

  for(i=0; i<N; i++){
    scanf("%ld", &vet[i]);
  }

  scanf("%ld", &M);
  for(i=0; i<M; i++){
    scanf("%ld", &buscado);
    posicao = binarysearch(vet, N, buscado);
    printf("%ld ", posicao);
  }
    
  return 0;
}

long int binarysearch(long int *vet, long int tam, long int buscado){
  int comeco, meio, fim;

  comeco = 0;
  fim = (tam-1)/2;
  while(comeco<=fim){
    meio = (comeco+fim)/2;
     if(vet[meio] == buscado){
      return meio;
    } 

   else if(buscado > vet[meio]){
      comeco = meio+1;
    } else{
      fim = meio - 1;
      }
  }

  comeco = (tam-1)/2 + 1;
  fim = tam - 1;
  while(comeco<=fim){
    meio = (comeco+fim)/2;
    if(vet[meio] == buscado){
      return meio;
    } 

    else if(buscado < vet[meio]){
      comeco = meio+1;
    } else{
      fim = meio - 1;
      }
  }
  return -1;
}
  
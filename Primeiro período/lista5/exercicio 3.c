#include <stdio.h>

int main() {
  int vetorA[5], vetorB[5], aux, j=4;
  for(int i=0; i<5; i++){
    printf("Insira um valor: ");
    scanf("%d", &vetorA[i]);
  }
  for(int i=0; i<5; i++){
    printf("Insira um valor: ");
    scanf("%d", &vetorB[i]);
  }
  for(int i=0; i<5; i++){
    aux=vetorA[i];
    vetorA[i]=vetorB[j];
    vetorB[j]=aux;
    j--;
  }
  for(int i=0; i<5; i++){
    printf("\nvetorA(%d) = %d", i, vetorA[i]);
  }
  for(int i=0; i<5; i++){
    printf("\nvetorB(%d) = %d", i, vetorB[i]);
  }
    return 0;
}
#include <stdio.h>

int main() {
  int vetorA[5], vetorB[5], vetorC[5], j=4;
  for(int i=0; i<5; i++){
    printf("Insira um valor: ");
    scanf("%d", &vetorA[i]);
  }
  for(int i=0; i<5; i++){
    printf("Insira um valor: ");
    scanf("%d", &vetorB[i]);
  }
  for(int i=0; i<5; i++){
    vetorC[i]=vetorA[i]*vetorB[j];
    j--;
  }
  for(int i=0; i<5; i++){
    printf("\nvetorC(%d) = %d", i, vetorC[i]);
  }
    return 0;
}

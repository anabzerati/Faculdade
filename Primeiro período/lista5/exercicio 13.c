#include <stdio.h>
#include <stdlib.h>

int main() {
  int vetora[5], dif, maior_dif=0;

  printf("Insira 5 valores: ");
  for(int i=0; i<5; i++){
    scanf("%d", &vetora[i]);
  }

  for(int i=1; i<5; i++){
    dif = abs(vetora[i] - vetora[i-1]);
    if(dif>maior_dif){
        maior_dif = dif;
      }
  }
  printf("Maior diferença: %d", maior_dif);
  
  return 0;
}
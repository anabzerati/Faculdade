#include <stdio.h>
#include <time.h>

int main() {
  int matriz[4][4], count=0;

  for(int i=0; i<4; i++){
    for(int j=0; j<4; j++){
      matriz[i][j] = rand()%100;
      if(matriz[i][j]>10){
        count++;
      }
    }
  }

  printf("Elementos maiores que 0: %d", count);
  return 0;
}
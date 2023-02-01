#include <stdio.h>

int main() {
  float matriz[2][2];
  int count=0;

  for(int i=0; i<4; i++){
    for(int j=0; j<4; j++){
      printf("Insira um valor para matriz[%d][%d]: ", i, j);
      scanf("%f", &matriz[i][j]);
      if(matriz[i][j]>10){
        count++;
      }
    }
  }

  printf("Há %d matrizes com valores maiores que 10.", count);
  
    return 0;
}
  

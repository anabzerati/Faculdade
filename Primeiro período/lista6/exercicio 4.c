#include <stdio.h>

int main() {
  int matriz[4][4], maior_valor=0, maior_valor_i, maior_valor_j;

  for(int i=0; i<4; i++){
    for(int j=0; j<4; j++){
      printf("Insira um valor para matriz[%d][%d]: ", i, j);
      scanf("%d", &matriz[i][j]);
      }
  }

  for(int i=0; i<4; i++){
    for(int j=0; j<5; j++){
      if(matriz[i][j]>maior_valor){
        maior_valor = matriz[i][j];
        maior_valor_i=i;
        maior_valor_j=j;
      }
    }
  }

  printf("O maior valor da matriz é: %d, localizado na linha %d e coluna %d", maior_valor, maior_valor_i+1, maior_valor_j+1);
  return 0;
}
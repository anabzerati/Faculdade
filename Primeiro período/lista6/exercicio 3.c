#include <stdio.h>

int main() {
  int matriz[4][4];

  for(int i=0; i<4; i++){
    for(int j=0; j<5; j++){
      matriz[i][j]=i*j;
      printf(" Matriz[%d][%d] = %d", i, j, matriz[i][j]);
    }
    printf("\n");
  }
  return 0;
}
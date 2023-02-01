#include <stdio.h>
#include <time.h>

int main() {
  int matriza[5][5], matrizb[5][5], matrizc[5][5];

  for(int i=0; i<5; i++){
    for(int j=0; j<5; j++){
      matriza[i][j]= rand()%100;
      matrizb[i][j]= rand()%100;
    }
  }

  for(int i=0; i<5; i++){
    for(int j=0; j<5; j++){
      if(matriza[i][j]>matrizb[i][j]){
        matrizc[i][j] = matriza[i][j];
      } else{
        matrizc[i][j] = matrizb[i][j];
      }
      printf(" [%d]", matrizc[i][j]);
    }
    printf("\n");
  }
  return 0;
}
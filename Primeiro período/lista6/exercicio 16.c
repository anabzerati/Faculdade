#include <stdio.h>
#include <time.h>

int main() {
  int a[2][3], at[3][2];

  for (int i=0; i<2; i++){
    for (int j=0; j<3; j++){
      a[i][j]=rand()%100;
    }
  }

  for(int i=0; i<3; i++){
    for(int j=0; j<2; j++){
      at[i][j]=a[j][i];
      printf(" [%d]", at[i][j]);
    }
    printf("\n");
  }
  return 0;
}
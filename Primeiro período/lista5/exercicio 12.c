#include <stdio.h>

int main() {
  int vin[10], vai[30], j=0;

  for(int i=0; i<10; i++){
    printf("\nInsira um valor para vin[%d]: ", i);
    scanf("%d", &vin[i]);
  }
  for(int i=0; i<10; i++){
    vai[j]=vin[i];
    vai[j+1]=vin[i];
    vai[j+2]=vin[i];
    j=j+3;
  }
  for(int i=0; i<30; i++){
    printf("\nvai[%d] = %d", i, vai[i]);
  }

  return 0;
}
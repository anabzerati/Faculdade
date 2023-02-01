#include <stdio.h>

int main() {
  int numero;

  printf("Insira um número inteiro: ");
  scanf("%d", &numero);

  if(numero<20||numero>100){
    printf("Número fora do intervalo estipulado");
  } 


    return 0;
}
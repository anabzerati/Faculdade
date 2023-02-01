#include <stdio.h>

int main() {
  int numero, fat=1;

  printf("Insira um número inteiro para o cálculo do fatorial: ");
  scanf("%d", &numero);

  for(int i=numero; i>0; i--){
    fat = fat * i;
  }

  printf("%d! = %d", numero, fat);
    return 0;
}

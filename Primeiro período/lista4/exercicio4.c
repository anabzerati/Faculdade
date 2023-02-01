//exercício 4 lista 4

#include <stdio.h>

int main(void) {
  int num_casas, consumo;
  float conta;

  printf("Insira a quantidade de casas para cálculo de valor de energia elétrica: ");
  scanf("%d", &num_casas);

  for(int i=0; i<num_casas; i++) {
    int diferenca;
   
    printf("\nInsira a quantidade de KWH consumidos: ");
    scanf("%d", &consumo);

    if(consumo<=50) {
      conta = consumo;
    } else if(consumo>51 && consumo<=100) {
      diferenca = consumo - 50;
      conta = 50 + diferenca*1.3;
    } else if(consumo>101 && consumo<=150) {
      diferenca = consumo - 100;
      conta = 115 + diferenca*1.6;
    } else {
      diferenca = consumo - 150;
      conta = 195 + diferenca*2;
    }

    printf("\nO valor da conta para o consumo de %d KWH é de %0.2f\n", consumo, conta );
   
    }
 
  return 0;
}
#include <stdio.h>

int main() {
  float sal_inicial;
  int quant_func;

  printf("Insira a quantidade de funcionários a calcular o reajuste: ");
  scanf("%d", &quant_func);

  if(int i=0; i<quant_func; i++) {
  printf("Insira o salário inicial: ");
  scanf("%f", &sal_inicial);

  if(sal_inicial<500){
    printf("O salário reajustado é de: %.2f", sal_inicial*1.15);
  } else if(sal_inicial>1000){
    printf("O salário reajustado é de: %.2f", sal_inicial*1.05);
  } else{
    printf("O salário reajustado é de: %.2f", sal_inicial*1.1);
  }
  }
    return 0;
}
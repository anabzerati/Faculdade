#include <stdio.h>

int main() {
  int tipo;
  float distancia,consumo;

  printf("Cálculo do custo em combustível para viagem.");
  printf("\n\nInsira o tipo de combustível do veículo: \n1)Gasolina.\n2)Álcool.\n3)Diesel.");
  scanf("%d", &tipo);
  printf("Insira a distância percorrida em km e o gasto médio do veículo: ");
  scanf("%f %f", &distancia, &consumo);

  switch(tipo){
    case 1: printf("O custo é %.2f", 4.79*distancia*consumo); break;
    case 2: printf("O custo é %.2f", 2.68*distancia*consumo); break;
    case 3: printf("O custo é %.2f", 2.64*distancia*consumo); break;
    default: printf("Opção inválida.");
  }
  
//Elaborar um programa que apresente a soma dos valores pares existentes na faixa de 0 até 500. O incremento deve ser de 2 em 2.

#include <stdio.h>
#define n 500

int main() {
  int soma;

  for(int i=0; i<=n; i=i+2){
    if(i==0){
      soma = 0;
    } else{
      soma = soma + i;
    }
  }

  printf("A soma dos pares de 0 a 500 é : %d", soma);
  
    return 0;
}

#include <stdio.h>
#include <time.h>
#define n 5

int main() {
  int vetor[n], soma=0, soma_p=0, soma_i=0, quant_p, quant_i;
  float media_p, media_i;

  for(int i=0; i<n; i++){
    vetor[i] = rand()%100;
    printf("\nvetor[%d] = %d", i, vetor[i]);
  }

  for(int i=0; i<n; i++){
    soma = soma + vetor[i];
    if(vetor[i]%2==0){
      soma_p = soma_p + vetor[i];
      quant_p++;
    } else{
      soma_i = soma_i + vetor[i];
      quant_i++;
    }
  }

  media_p = soma_p / quant_p;
  media_i = soma_i / quant_i;

  printf("\nA soma dos números é: %d", soma);
  printf("\nA média dos números pares é: %.2f", media_p);
  printf("\nA média dos ímpares é igual a: %.2f", media_i);
  printf("\nA quantidade de pares é igual a: %d", quant_p);
  printf("\nA quantidade de ímpares é igual a: %d", quant_i);
 return 0;
}
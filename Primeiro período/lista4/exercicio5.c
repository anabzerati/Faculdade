//exercício 5 lista 4

#include <stdio.h>

int main(void) {
  int codigo;
  char resp;

  do{
    printf("Insira o código do produto: ");
    scanf("%d", &codigo);

    switch(codigo) {
      case 1: printf("Classificação: alimento não perecível"); break;
      case 2 ... 4: printf("Classificação: alimento perecível"); break;
      case 5: printf("Classificação: vestuário"); break;
      case 6: printf("Classificação: vestuário"); break;
      case 7: printf("Classificação: higiene pessoal"); break;
      case 8 ... 13: printf("Classificação: limpeza e utensilios domésticos"); break;
      default: printf("Inválido"); break;
    }

    printf("\nDeseja continuar? <s>im ou <n>ão? ");
    scanf(" %c", &resp);
   
   } while(resp=='s');
 

  return 0;
}

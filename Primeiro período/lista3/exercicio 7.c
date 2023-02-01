#include <stdio.h>

int main() {
  int produto;

  printf("Insira o código do produto para verificação da procedência: ");
  scanf("%d", &produto);

  switch(produto){
    case 1: printf("O produto é do sul."); break;
    case 2: printf("O produto é do norte."); break;
    case 3: printf("O produto é do leste."); break;
    case 4: printf("O produto é do oeste."); break;
    case 5: printf("O produto é do nordeste."); break;
    case 6: printf("O produto é do nordeste."); break;
    case 7: printf("O produto é do sudeste."); break;
    case 8: printf("O produto é do sudeste."); break;
    case 9: printf("O produto é do sudeste."); break;
    case 10: printf("O produto é do centro-oeste."); break;
    case 11: printf("O produto é do centro-oeste."); break;
    case 12: printf("O produto é do nordeste."); break;
    case 13: printf("O produto é do nordeste."); break;
    case 14: printf("O produto é do nordeste."); break;
    case 15: printf("O produto é do nordeste."); break;
    default: printf("O produto é do importado."); break;
  }
    return 0;
}

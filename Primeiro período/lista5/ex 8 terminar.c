#include <stdio.h>

int main() {
  int resp1, resp2, quant, resp3, resp4;
  float estoque[5], preco[5];

  do{printf("\nOpções:\n1-Aumentar estoque.\n2-Baixar estoque.\n3-Visualizar estoque de um produto.\n4-Visualizar estoque total.\n5-Aumentar preço.\n6-Diminuir preço.\n7-Trocar produto.\n8-Sair");
  scanf("%d", &resp1);
  switch(resp1){
    case 1: 
        do{
          printf("Insira o número do produto (de '0' a '4') do qual deseja aumentar o estoque: ");
          scanf("%d", &resp2);
          if(resp2<0 || resp2>4) printf("Produto inválido.");
          } while (resp2<0 || resp2>4);
        printf("Insira a quantidade de unidades: ");
        scanf("%d", quant);
        estoque[resp2] = estoque[resp2] + quant;
        break;
    
    case 2: do{
          printf("Insira o número do produto (de '0' a '4') do qual deseja baixar o estoque: ");
          scanf("%d", &resp3);
          if(resp3<0 || resp3>4) printf("Produto inválido.");
          } while (resp3<0 || resp3>4);
        estoque[resp3]--;
        break;

    case 3: do{
          printf("Insira o número do produto (de '0' a '4') do qual deseja visualizar o estoque: ");
          scanf("%d", &resp4);
          if(resp4<0 || resp4>4) printf("Produto inválido.");
          } while (resp4<0 || resp4>4);
          printf("O estoque de %d é: %d", resp4, estoque[resp4]);
  }
    } while(resp1!=8);
 return 0;
}
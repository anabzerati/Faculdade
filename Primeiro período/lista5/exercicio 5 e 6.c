#include <stdio.h>

int main() {
  int quant_elementos=0, fila[10], resp;
  do{
  printf("\n\nOperações: \n1)Adicionar à fila. \n2)Remover da fila.\n3)Finalizar.");
  scanf("%d", &resp);
  switch(resp){
    case 1: if (quant_elementos<10){
      printf("\nAdicionado.");
      quant_elementos++;
    } else {
      printf("\nFila cheia. É necessário remover um elemento antes de adicionar outro.");
    } ; break;
    case 2: if(quant_elementos==0){
      printf("\nNão há elemento na fila a ser removido.");
    } else{
      printf("\nElemento removido.");
      quant_elementos--;
    } ; break;
  }  
    }while(resp!=3);
 return 0;
}
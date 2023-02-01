#include <stdio.h>
#define n 5 

int main() {
  float vetor[n], aux;
  char resp1, resp2;
  int j, inicio, fim;
    
  for(int i=0; i<n; i++){
        printf("Insira um valor para o vetor[%d]: ", i);
        scanf("%f", &vetor[i]);
      }
 
  do {
    do{
      printf("Escolha dentre as opções:\n1)Apresentar elementos em ordem crescente.\n2)Apresentar elementos em ordem decrescente.\n3)Imprimir todo o vetor\n4)Imprimir as posições de um intervalo especificado pelo usuário.");
        scanf("%c", &resp1);
      } while(resp1<0||resp1>4);

      switch(resp1){
        case 1: 
          for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
              if(vetor[j]<vetor[i]) {
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
              }
            } 
             printf("%f", vetor[i]); 
          }
        break;
        
        case 2: 
              for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                  if(vetor[j]>vetor[i]) {
                    aux = vetor[i];
                    vetor[i] = vetor[j];
                    vetor[j] = aux;
              }
            }
              printf("%f", vetor[i]);
          }
        break;
        
        case 3: 
          for(int i=0; i<n; i++){
            printf("vetor[%d]: %f", i, vetor[i]);
          }
        break;
        
        case 4: 
          printf("Insira o início e fim do intervalo: ");
          scanf("%d %d", &inicio, &fim);
          if(inicio==fim){
            printf("vetor = %f", vetor[inicio]);
          } 
          else if (inicio<fim){
            for(int i=inicio; i<=fim; i++) {
              printf("resultado = [%d]", vetor[i]);
            } 
          } else {
            printf("Pedido inválido.");
            }
          break;
      }

      printf("\nPressione 'S' ou 's' para encerrar.");
      scanf("%c", &resp2);
    } while (resp2 != 'S' && resp2 != 's');
    return 0;
}

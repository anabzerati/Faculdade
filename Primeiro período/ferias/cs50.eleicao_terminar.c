#include <stdio.h>
#define candidates 3

int main() {
    int voters, resp, maior, indice=0;
    struct votacao{
        int votos;
        char nome[20];
    } candidato[candidates];

  candidato[0].votos = 0;
  candidato[1].votos = 0;
  candidato[2].votos = 0;

    printf("Quantas pessoas votarão: ");
    scanf("%d", &voters);

    printf("\nVotos:");
    printf("\nCandidatos: \n1)A.\n2)B.\n3)C.");
    printf("\nInsira ranking de preferencia: ");
    for(int i=0; i<voters; i++){
      for(int j=0; j<candidates; j++){
        printf("\n%d eleitor - %d candidadato - posição no ranking: ", i+1, j+1);
        scanf("%d", &resp);
        switch(resp){
          case 1: candidato[j].votos + 3; break;
          case 2: candidato[j].votos + 2; break;
          case 3: candidato[j].votos + 1; break;
          default: printf("Erro! Voto inválido!");
        }
      }
    }

  //votos cmputados
  maior = candidato[0].votos;
      for(int i=0; i<candidates; i++){
        if(candidato[i].votos > maior){
          maior = candidato[i].votos;
          indice = i;
        }
      }

  printf("\n\nVencedor: %d", indice);

  
    return 0;
}
 
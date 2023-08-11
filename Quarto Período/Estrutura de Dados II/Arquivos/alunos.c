/* Você foi contratado para automatizar o cadastro de alunos da UNESP e sua gravação e recuperação de arquivos.
Inicialmente, você pega uma turma de 5 alunos para testar seu programa.

É dado a você o registro abaixo com os seguintes campos:
struct aluno {
  char *nome;
  char *curso
  char *ano
  Char *email
  int nro_UNESP;
}
Pede-se: escreva um programa em C que leia na tela os dados; grave os dados da turma em arquivo e recupere o nome de um aluno cujo número UNESP é dado na tela
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 50
#define NUM_ALUNOS 5

struct aluno{
  char nome[MAX];
  char curso[MAX];
  char ano[5];
  char email[MAX];
  int numUnesp;
};

void buscaNome(FILE *fp, int num);

int main(){
  FILE *fp;
  int i, numUnesp;
  struct aluno aux;

  fp = fopen("alunos.txt", "w");
  if(!fp){
    printf("Erro ao abrir o arquivo!");
    exit(1);
  }

  for(i = 0; i < NUM_ALUNOS; i ++){
    printf("\nAluno %d", i + 1);

    printf("Nome: ");
    scanf(" %[^\n]s", aux.nome);

    printf("Curso: ");
    scanf(" %[^\n]s", aux.curso);

    printf("Ano: ");
    scanf(" %s", aux.ano);

    printf("E-mail: ");
    scanf(" %[^\n]s", aux.email);

    printf("Número da UNESP: ");
    scanf("%d", &aux.numUnesp);

    fprintf(fp, "%s %s %s %s %d\n", aux.nome, aux.curso, aux.ano, aux.email, aux.numUnesp);
  }

  fclose(fp);

  printf("\nDados armazenados no arquivo.");

  printf("\n\nBusca por aluno");
  printf("\nInsira o número da UNESP para recuperar o nome: ");
  scanf("%d", &numUnesp);

  fp = fopen("alunos.txt", "r");
  buscaNome(fp, numUnesp);

  return 0;
}

void buscaNome(FILE *fp, int num){
    char nomeAux[MAX];
    int numAux;

    while((fscanf(fp, "%s", nomeAux)) != -1){
        fscanf(fp, "%d", &numAux);
        if(num == numAux){
            printf("Nome do aluno: %s", nomeAux);
            return;
        }
    }

    printf("Não há aluno com número %d", num);
}
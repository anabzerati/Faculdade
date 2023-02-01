//Faça um programa em Linguagem C para criar uma estrutura composta pelos campos: notaprova, notatrabalho, média e nome. O programa deve permitir a leitura do nome e notas de um aluno. 
//Em seguida, o programa deve calcular a média e armazenar no campo correspondente. Imprimir os dados.

#include <stdio.h>

typedef struct{
    char nome[30];
    float notaprova, notatrabalho, media;
} dados;

int main(){
    dados aluno1;

    printf("Insira o nome do aluno: ");
    scanf("%[^\n]s", aluno1.nome);
    printf("Insira as notas de prova e trabalho: ");
    scanf("%f %f", &aluno1.notaprova, &aluno1.notatrabalho);

    aluno1.media = (aluno1.notaprova + aluno1.notatrabalho) / 2;

    printf("A média do aluno é: %.2f", aluno1.media);
    
    return 0;
}
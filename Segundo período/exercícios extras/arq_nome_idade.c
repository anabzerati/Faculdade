/*Faça um programa que receba como entrada o ano corrente e o nome de dois arquivos:
um de entrada e outro de sa´ıda. Cada linha do arquivo de entrada contem o nome de ´
uma pessoa (ocupando 40 caracteres) e o seu ano de nascimento. O programa devera´
ler o arquivo de entrada e gerar um arquivo de sa´ıda onde aparece o nome da pessoa
seguida por uma string que representa a sua idade.
• Se a idade for menor do que 18 anos, escreva “menor de idade”
• Se a idade for maior do que 18 anos, escreva “maior de idade”
• Se a idade for igual a 18 anos, escreva “entrando na maior idade”*/
#include <stdio.h>
#include <string.h>

int main(){
    int ano, ano_nasc, idade;
    FILE *or, *new;
    char nome[40],carac_idade[10];

    scanf("%d",&ano);

    or=fopen("arq_original.txt","r");
    new=fopen("novo_arq.txt","w");

    while(feof(or)==0){
        fscanf(or," %s%d",nome,&ano_nasc);
        idade = ano - ano_nasc;
        if(idade<18){
            strcpy(carac_idade,"menor");
        }else if(idade>18){
            strcpy(carac_idade,"maior");
        } else{
            strcpy(carac_idade,"entrando");
        }
        fprintf(new,"\n%s-%d-%s",nome,idade,carac_idade);
        printf("\n%s-%d-%s",nome,idade,carac_idade);
    }

    fclose(or);
    fclose(new);

    return 0;
}
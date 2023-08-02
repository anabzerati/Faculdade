#include <stdio.h>
#include <stdlib.h>

#define TAM_MAX 100

int filecmp(FILE *file1, FILE *file2);

int main(){
    FILE *file1, *file2;
    char caminho1[TAM_MAX], caminho2[TAM_MAX];

    printf("Insira o caminho do primeiro arquivo: ");
    scanf(" %s", caminho1);

    printf("Insira o caminho do segundo arquivo: ");
    scanf(" %s", caminho2);

    file1 = fopen(caminho1, "r");
    file2 = fopen(caminho2, "r");

    if(!file1 || !file2){
        printf("Erro ao abrir os arquivos");

        exit(1);
    }

    int cmp = filecmp(file1, file2);
    if(cmp){
        printf("Arquivos iguais");
    } else{
        printf("Arquivos diferentes");
    }

    fclose(file1);
    fclose(file2);

    return 0;
}

int filecmp(FILE *file1, FILE *file2){
    int c1, c2;

    do{
        c1 = fgetc(file1);
        c2 = fgetc(file2);

        if(c1 != c2){
            return 0;
        }
    } while(c1 != EOF || c2 != EOF);

    return 1;
}
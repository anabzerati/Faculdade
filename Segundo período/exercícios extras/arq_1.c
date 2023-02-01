//Escreva um programa que: (a) Crie/abra um arquivo texto de nome “arq.txt” (b) Permita que o usuario grave diversos caracteres nesse arquivo, ate q o usuario entre 
//com o caractere ‘0’ (c) Feche o arquivo
//Agora, abra e leia o arquivo, caractere por caractere, e escreva na tela todos os caracteres armazenados

#include<stdio.h>

int main(){
    FILE *arqp;
    int x=1;

    arqp=fopen("arq.txt", "w");

    do{
        scanf("%d", &x);
        fprintf(arqp, "%d ", x);
    } while(x!=0);

    if(x==0){
      fclose(arqp);
    }

    return 0;
}
//. Fac¸a um programa que receba do usuario um arquivo texto e mostre na tela quantas letras sao vogais

#include <stdio.h>

int main(){
    FILE *fp;
    int quant=0;
    char letra;

    fp = fopen("nome.arq", "r");

    do{
        fscanf(fp, "%c", &letra);
        if(letra=='a'||letra=='e'||letra=='i'||letra=='o'||letra=='u'){
            quant++;
        }
    }while(!feof(fp));

    fclose(fp);

    printf("%d", quant);

    return 0;
}
//Fac¸a um programa que receba do usuario um arquivo texto e um caracter. Mostre na tela quantas vezes aquele caractere ocorre dentro do arquivo

#include <stdio.h>

int main(){
    FILE *fp;
    char c, comp;
    int quant=0;

    scanf("%c", &c);

    fp=fopen("nome.arq","r");

    do{
        fscanf(fp, "%c", &comp);
        if(comp==c){
            quant++;
        }
    }while(!feof(fp));

    printf("%d", quant);

    fclose(fp);

    return 0;
}
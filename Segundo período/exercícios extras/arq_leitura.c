//escreva um programa q leia o arquivo pares.dat e troque os espaços em branco por letras maiusculas em ordem sdequencial no arq 'esquisito.dat'

#include <stdio.h>

int main(){
    char letra = 'A';
    int num;
    FILE *arq_1, *arq_2;

    arq_1 = fopen("pares.dat", "r");
    arq_2 = fopen("esquisito.dat", "w");

    do{
        fscanf(arq_1, "%d", &num);
        fprintf(arq_2, "%d%c", num, letra);
        letra = (letra+1-'A')%26 +'A';
    } while(!feof(arq_1));

    fclose(arq_1);
    fclose(arq_2);

    return 0;
}
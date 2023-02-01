/*Fac¸a um programa que recebe um vetor de 10 numeros, converta cada um desses ´
numeros para bin ´ ario e grave a sequ ´ encia de 0s e 1s em um arquivo texto. Cada n ˆ umero ´
deve ser gravado em uma linha.*/

#include <stdio.h>

int binario(int n);

int main(){
    FILE *fp;
    int num[10], parametro, binario, i;

    for(i=0;i<10;i++){
        scanf("%d",&num[i]);
    }

    fp = fopen("arq_numeros","w");

    for(i=0; i<10; i++){
        parametro = num[i];
        binario(parametro);
        fprintf(fp,"\n");
    }

    fclose(fp);

    return 0;
}

int binario(int n){
    FILE *fp;
    fp = fopen("arq_numeros","w");
    if(n/2 != 0){
        binario(n/2);
    }
    fprintf(fp, "%d", n%2);
}
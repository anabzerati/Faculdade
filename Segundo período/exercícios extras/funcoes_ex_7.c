/*Crie um programa que contenha uma func¸ao que permita passar por par ˜ ametro dois ˆ
numeros inteiros A e B. A func¸ ´ ao dever ˜ a calcular a soma entre estes dois n ´ umeros e ´
armazenar o resultado na variavel A. Esta func¸ ´ ao n ˜ ao dever ˜ a possuir retorno, mas dever ´ a´
modificar o valor do primeiro parametro. Imprima os valores de A e B na func¸ ˜ ao principa*/

#include <stdio.h>
#include <stdlib.h>

void funcsoma(int *pa, int *pb);

int main(){
    int *pa, *pb;
    pa = malloc(sizeof(int));
    pb = malloc(sizeof(int));

    scanf("%d %d", pa, pb);
    printf("\nA:%d B:%d", *pa, *pb);

    funcsoma(pa, pb);

    printf("\nA:%d B:%d", *pa, *pb);

    return 0;
}

void funcsoma(int *pa, int *pb){
    *pa = *pa + *pb;
}
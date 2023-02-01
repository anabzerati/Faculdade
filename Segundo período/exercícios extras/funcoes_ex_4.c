/*Fac¸a um programa que leia 2 valores inteiros e chame uma func¸ao que receba estas ˜
2 variaveis e troque o seu conte ´ udo, ou seja, esta func¸ ´ ao˜ e chamada passando duas ´
variaveis A e B por exemplo e, ap ´ os a execuc¸ ´ ao da func¸ ˜ ao, A conter ˜ a o valor de B e B ´
tera o valor de A.*/

#include <stdio.h>
#include <stdlib.h>

void funcaotroca(int *pa, int *pb);

int main(){
    int *pa, *pb;

    pa=malloc(sizeof(int));
    pb=malloc(sizeof(int));

    *pa=1;
    *pb=2;

    printf("Valor antes: %d %d", *pa, *pb);

    funcaotroca(pa, pb);

    printf("\nDepois: %d %d", *pa, *pb);

    return 0;
}

void funcaotroca(int *pa, int *pb){
    int aux;
    aux = *pa;
    *pa = *pb;
    *pb = aux;
}
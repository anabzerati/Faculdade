/*Fac¸a um programa que leia dois valores inteiros e chame uma func¸ao que receba estes ˜
2 valores de entrada e retorne o maior valor na primeira variavel e o menor valor na ´
segunda variavel. Escreva o conte ´ udo das 2 vari ´ aveis na tela*/

#include <stdio.h>
#include <stdlib.h>

void funcmaior(int *pa, int *pb);

int main(){
    int *pa, *pb;
    pa = malloc(sizeof(int));
    pb = malloc(sizeof(int));
    
    scanf("%d %d", pa, pb);

    funcmaior(pa, pb);

    printf("MAIOR: %d MENOR: %d", *pa, *pb);

    return 0;
}

void funcmaior(int *pa, int *pb){
    int aux;
    if(*pa<*pb){
        aux = *pa;
        *pa = *pb;
        *pb = aux;
    }
}
/*Elaborar um programa que leia dois valores inteiros (A e B). Em seguida fac¸a uma func¸ao˜
que retorne a soma do dobro dos dois numeros lidos. A func¸ ´ ao dever ˜ a armazenar o dobro ´
de A na propria vari ´ avel A e o dobro de B na pr ´ opria vari ´ avel B*/

#include <stdio.h>
#include <stdlib.h>

int funcsoma(int *pa, int *pb);

int main(){
    int *pa, *pb;
    pa = malloc(sizeof(int));
    pb = malloc(sizeof(int));

    scanf("%d %d", pa, pb);
    printf("%d %d", *pa, *pb);

    printf("\n%d", funcsoma(pa, pb));

    return 0;
}

int funcsoma(int *pa, int *pb){
    int soma;
    *pa = (*pa) * 2;
    *pb = (*pb) * 2;
    soma = (*pa) + (*pb);
    return soma;
}

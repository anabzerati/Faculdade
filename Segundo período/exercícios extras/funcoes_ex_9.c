/*Crie um programa que contenha uma matriz de float contendo 3 linhas e 3 colunas.
Imprima o enderec¸o de cada posic¸ao dessa matriz*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    float mat[3][3], *pm;
    int i;
    pm = &mat;

    for(i=0;i<9;i++){
        printf("\n%p", (pm+i));
    }

    return 0;
}
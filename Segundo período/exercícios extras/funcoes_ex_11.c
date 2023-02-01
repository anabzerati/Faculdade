/*Crie um programa que contenha um array contendo 5 elementos inteiros. Leia esse array
do teclado e imprima o enderec¸o das posic¸oes contendo valores pares. */

#include <stdio.h>
#include <stdlib.h>

int main(){
    int array[5], *pa, i;
    pa = array;

    for(i=0;i<5;i++){
        scanf("%d", &array[i]); //poderia usar aritmetica de vetores com pa+i
    }

    for(i=0;i<5;i++){
        if(array[i]%2==0){ //*(pa+i)%2==0
            printf("\n%p",pa);
        }
        pa = pa + 1;
    }

    return 0;
}
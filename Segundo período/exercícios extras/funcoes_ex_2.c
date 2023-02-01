/*Escreva um programa que contenha duas variaveis inteiras. Compare seus enderec¸os e ´
exiba o maior enderec¸o*/

#include <stdio.h>

char maior(int *n1, int *n2);

int main(){
    int a=1, b=2;

    printf("Maior endereço: %c", maior(&a,&b));

    return 0;
}

char maior(int *n1, int *n2){
    if(n1>n2){
        return 'a';
    } else{
        return 'b';
    }
}
/*Fça uma função recursiva que calcule e retorne o fatorial de um número inteiro N*/

#include <stdio.h>

int fat(int N);

int main(){
    int num;

    scanf("%d", &num);

    printf("%d! = %d", num, fat(num));

    return 0;
}

int fat(int N){
    if(N==1){
        return 1;
    } else{
        return N * fat(N-1);
    }
}
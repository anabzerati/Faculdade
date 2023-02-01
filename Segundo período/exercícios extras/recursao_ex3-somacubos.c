/*Escreva uma func¸ao recursiva que calcule a soma dos primeiros n cubos: S(n) = 1^3 + 2^3 + ... + n^3*/

#include <stdio.h>

int soma_cubo(int N);

int main(){
    int num;

    scanf("%d", &num);

    printf("Soma dos primeiros %d cubos: %d", num, soma_cubo(num));

    return 0;
}

int soma_cubo(int N){
    if(N==1){
        return 1;
    } else{
        return N*N*N + soma_cubo(N-1);
    }
}
/*Crie uma função recursiva que receba um número inteiro positivo N e calcule o somatório
dos numeros de 1 a N*/

#include <stdio.h>

int somat(int N);

int main(){
    int num;

    scanf("%d", &num);

    printf("Somatório de 1 a %d: %d", num, somat(num));

    return 0;
}

int somat(int N){
    if(N==1){
        return 1;
    } else{
        return N + somat(N-1);
    }
}
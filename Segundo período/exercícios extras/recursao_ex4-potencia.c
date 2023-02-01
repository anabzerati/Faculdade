/*Crie uma função recursiva que receba dois inteiros positivos k e n e calcule k^n*/

#include <stdio.h>

int potencia(int k, int n);

int main(){
    int k, n;

    printf("K e N, respectivamente: ");
    scanf("%d %d", &k, &n);

    printf("%d elevado a %d: %d", k, n, potencia(k,n));

    return 0;
}

int potencia(int k, int n){
    if(n==1){
        return k;
    } else{
        return k * potencia(k, n-1);
    }
}
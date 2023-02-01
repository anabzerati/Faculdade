//recursao - Impressão de um número natural em base binária.

#include <stdio.h>

int binary(int n);

int main(){
    int num;

    printf("Número natural: ");
    scanf("%d", &num);

    printf("Em base binária: %d", binary(num));;


    return 0;
}

int binary(int n){
    if(n/2 != 0){
        binary(n/2);
    }
    printf("%d", n%2);
}
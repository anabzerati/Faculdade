//recursão fatorial

#include <stdio.h>

int fat(int n);

int main(){
    int num;

    printf("Número: ");
    scanf("%d", &num);

    printf("Fatorial de %d = %d", num , fat(num));

    return 0;
}

int fat(int n){
    if(n==1){
        return 1;
    } 
    return (n*fat(n-1));
}
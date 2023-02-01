/*A multiplicac¸ao de dois números inteiros pode ser feita atraves de somas sucessivas.
Proponha um algoritmo recursivo Multip_Rec(n1,n2) que calcule a multipliação de dois numeros
inteiros.*/

#include <stdio.h>

int multip_rec(int n1, int n2);

int main(){
    int n1, n2;

    scanf("%d %d", &n1, &n2);

    printf("%d * %d = %d", n1, n2, multip_rec(n1, n2));

    return 0;
}

int multip_rec(int n1, int n2){
    if(n1==1){
        return n2;
    } else{
        return n2 + multip_rec(n1-1, n2);
    }
}
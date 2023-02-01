// exercicios extras funções - Escreva	 um	 programa	 em	 C	 que	 leia	 5	 valores	 inteiros	 e	 imprima	 para	cada	um	o	seu	correspondente	valor	absoluto.	Para	obter	o	valor	absoluto	
//do	número	utilize	a	função	Absoluto especificada	abaixo	2:		

#include <stdio.h>

int abs (int n);

int main(){
    int n1, n2, n3, n4, n5;

    printf("Insira 5 números inteiros: ");
    scanf("%d %d %d %d %d", &n1, &n2, &n3, &n4, &n5);

    printf("Valores absolutos:\n%d - %d\n%d - %d\n%d - %d\n%d - %d\n%d - %d", n1, abs(n1), n2, abs(n2), n3, abs(n3), n4, abs(n4), n5, abs(n5));
    return 0;
}

int abs (int n){
    if(n<0){
        return n*(-1);
    }
    return n;
}
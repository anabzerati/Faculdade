//exerciciios extras funções - Faça	uma	função	que	recebe	um	valor	inteiro	e	verifica	se	o	valor	é	par.	A	função	deve	retornar	1	se	o	número	for	par	e	0	se	for	ímpar

#include <stdio.h>

int ver(int n);

int main(){
    int valor;

    printf("Insira um valor inteiro: ");
    scanf("%d", &valor);

    if(ver(valor)==0)|{
        printf("%d é ímpar!", valor);
    } else{
        printf("%d é par!", valor);
    }

    return 0;
}

int ver(int n){
    if(n%2 == 0){
        return 1;
    }
    return 0;
}
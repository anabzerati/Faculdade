//exercicios extras funções - Escreva	 uma	 função	 potencia(base,	 expoente) que,	 quando	 chamada, retorna	base^expoente.	Por	exemplo,	potencia(3,	4)	deve	retornar	81.	Assuma	que	expoente	é um	inteiro	maior ou	igual	a	1.

#include <stdio.h>
#include <math.h>

int potencia (int b, int e);

int main(){
    int base, exp;

    do{
    printf("Insira base e expoente: ");
    scanf("%d %d", &base, &exp);
    if(exp<1){
        printf("O expoente deve ser um número inteiro maior ou igyal a 1!");
    }
    }while(exp<1);

    printf("%d elevado a %d: %d", base, exp, potencia(base, exp));
    return 0;
}

int potencia (int b, int e){
    return pow(b,e);
}
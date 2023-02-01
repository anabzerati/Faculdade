//exercicios extras funções - Escreva	um	programa	que	leia	5	números	inteiros	positivos	(utilize	uma	 função	 que	 leia	 esse	 número	 e	 verifique	 se	 ele	 é	 positivo).	 Para	 cada	
//número	informado	escrever	a	soma	de	seus	divisores	(exceto	ele	mesmo).	
//Utilize	a	função	SomaDivisores para		obter	a soma.	
//Nome:	SomaDivisores	
//Descrição:	Calcula	a	soma	dos	divisores	do	número	informado	(exceto	
//ele	mesmo).	
//Entrada:	Um	número	inteiro	e	positivo.	
//Saída:	A	soma	dos	divisores.	
//Exemplo:	Para	o	valor	8:	1+2+4	=	7

#include <stdio.h>

int ver (int n);
int div (int n);

int main(){
    int n1, n2, n3, n4, n5;

    do{
    printf("Insira 5 números inteiros positivos: ");
    scanf("%d %d %d %d %d", &n1, &n2, &n3, &n4, &n5);
    if(ver(n1)==0||ver(n2)==0|ver(n3)==0|ver(n4)==0|ver(n5)==0){
        printf("Erro! Insira apenas números inteiros positivos!");
    }
    }while(ver(n1)==0||ver(n2)==0|ver(n3)==0|ver(n4)==0|ver(n5)==0);

    printf("Soma dos dividores de %d = %d\nSoma dos dividores de %d = %d\nSoma dos dividores de %d = %d\nSoma dos dividores de %d = %d\nSoma dos dividores de %d = %d", n1, div(n1), n2, div(n2), n3, div(n3), n4, div(n4), n5, div(n5));

    return 0;
}

int ver (int n){
    if(n>0){
        return 1;
    }
    return 0;
}

int div (int n){
    int soma=0;
    for(int i=1; i<n; i++){
        if((n%i) == 0){
            soma = soma + i;
        }
    }
    return soma;
}
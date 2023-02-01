//exercicios extras funções - Escreva	 uma	 função	 que	 receba 3	 notas	 de	 um	 aluno	 e	 uma	 letra.	 Se	 a	letra	for	A	a	função	retorna a	média	aritmética	das	notas	do	aluno,
//se	for	P,	 a	 sua	 média	 ponderada	 (pesos:	 5,	 3	 e	 2)	 e	 se	 for	 H,	 a	 sua	 média	harmônica

#include <stdio.h>
#include <math.h>

float media(float n1, float n2, float n3, char tipo);

int main(){
    float n1,n2,n3;
    char tipo;

    do{
    printf("Insira três notas e o tipo de média a ser calculada: \nA- aritmética.\nP- ponderada.\nH- harmônica:\n ");
    scanf("%f %f %f %c", &n1, &n2, &n3, &tipo);
    if(n1<0||n2<0||n2<0||(tipo!='p'&& tipo!='a'&&tipo!='h')){
        printf("Erro! Insira novamente!");
    }
    } while(n1<0||n2<0||n2<0||(tipo!='p'&& tipo!='a'&&tipo!='h'));

    printf("Média = %f", media(n1,n2,n3,tipo));

    return 0;
}

float media(float n1, float n2, float n3, char tipo){
    if(tipo == 'a'){
        return (n1+n2+n3)/3;
    } else if (tipo == 'p'){
        return (5*n1+3*n2+2*n3)/10;
    } else{
        return 3/((pow(n1,-1))+(pow(n2,-1))+(pow(n3,-1)));
    }
}
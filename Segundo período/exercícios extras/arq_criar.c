//exexrcicio arquivos - programa q leia um inteiro k maior q 3 e menor q 10 e escrever 10^k pares aleatorios num arquivo chamado 'pares.dat'. Colocar um espaço entre os numeros.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(){
    int k, pot, i;
    FILE *fp;
    srand(time(NULL));

    do{
    scanf("%d", &k);
    } while(k<=3 || k>=10); //lendo k validando entrada

    pot = (int)pow(10,k);

    fp = fopen("pares.dat", "w");

    for(i=0; i<pot; i++){
        fprintf(fp, "%d ", (rand()/2)*2);
    }

    return 0;
}
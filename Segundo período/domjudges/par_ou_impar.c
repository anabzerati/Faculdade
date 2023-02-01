/*A entrada ´e composta por um inteiro N (0 < N ≤ 1000), representando o n´umero de partidas
entre Abel e Bebel, seguido por N linhas contendo dois inteiros, X e Y , 0 ≤ X, Y ≤ 5, que
s˜ao os valores colocados para uma partida.
Sa´ıda
A sa´ıda de seu programa deve ter uma linha para cada partida, com o caractere ’A’ se o
vencedor for Abel ou ’B’ se for Bebel.*/

#include <stdio.h>

int main(){
    int i, N, x, y, soma;

    scanf("%d", &N);

    for(i=0; i<N; i++){
        scanf("%d%d", &x, &y);
        soma = x+y;
        if(soma==0||soma%2==0){
            printf("A\n");
        }else{
            printf("B\n");
        }
    }

    return 0;
}
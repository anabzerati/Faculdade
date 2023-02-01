/* minimos locais
em uma matriz, exite um valor que é o minimo entre todos os armazenados, porém podemos ter vários valores mínimos distintos se olharmos regioes específicas(da matriz)
programa que leia conteudo de matriz N^2 e indique o minimo na regiao delimitada por a e b
ENTRADA: N (quantidade de linhas e colunas) e M (quantidade de regiões que serão verificadas)
depois, N^2 valores pra preencher a matriz e M linhas com a e b (M trechoa a serem verificados, começando da linha e coluna a e terminando nas b)
SAÍDA: M linhas com o menor valor em cada um dos M trechos da matriz
*/

#include <stdio.h>
#include <stdlib.h>

int buscar(int N, int matriz[N][N], int a, int b);

int main(){
    int N, M, i, j, a, b;

    scanf("%d %d", &N, &M);
    int matriz[N][N];

    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            scanf("%d", &matriz[i][j]);
        }
    }

    for(i=0; i<M; i++){
        scanf(" %d %d", &a, &b);
        printf("%d\n", buscar(N, matriz, a-1, b-1));
    }

    return 0;
}

int buscar(int N, int matriz[N][N], int a, int b){
    int i, j, menor = matriz[a][a];

    for(i=a; i<=b; i++){
        for(j=a; j<=b; j++){
            if(matriz[i][j]<menor){
                menor = matriz[i][j];
            }
        }
    }

    return menor;
}
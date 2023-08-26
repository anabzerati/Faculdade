/*
Decomposição LU pelo método de Doolittle.
A partir de A, conhecendo que L é uma matriz triangular inferior (com diagonal principal 1) e U uma matriz superior, e que L*U = A, podemos determinar seus valores.
*/

#include <stdio.h>
#include <stdlib.h>

void inicializaMatriz(int n, float matriz[n][n]);
void imprimeMatriz(int n, float matriz[n][n]);

int main(){
    int i, j, k, n, soma = 0;

    printf("Ordem da matriz: ");
    scanf("%d", &n);

    float A[n][n], L[n][n], U[n][n];

    printf("Entrada de valores: \n");
    for(i = 0; i < n; i ++){
        printf("Linha %d: \n", i + 1);
        for(j = 0; j < n; j ++){
            printf("Coluna %d: ", j + 1);
            scanf("%f", &A[i][j]);
        }
    }

    inicializaMatriz(n, L);
    inicializaMatriz(n, U);

    for(i = 0; i < n; i ++){
        for(j = i; j < n; j ++){ //linha i e coluna j
            soma = 0;

            for(k = 0; k < i; k ++){ //somatório
                soma = soma + (L[i][k] * U[k][j]);
            }
            
            U[i][j] = A[i][j] - soma;
        }

        for(j = i; j < n; j ++){ //linha j coluna i
            if(i == j){
                L[i][j] = 1; //diagonal principal
            } else{
                soma = 0;

                for(k = 0; k < i; k ++){ //somatório
                    soma = soma + (L[j][k] * U[k][i]);
                }   

                L[j][i] = (A[j][i] - soma) / U[i][i];
            }
        }
    }

    printf("Matriz L:\n");
    imprimeMatriz(n, L);

    printf("\n Matriz U:\n");
    imprimeMatriz(n, U);

    return 0;
}

void inicializaMatriz(int n, float matriz[n][n]){
    int i, j;

    for(i = 0; i < n; i ++){
        for(j = 0; j < n; j ++){
            matriz[i][j] = 0;
        }

    }
}

void imprimeMatriz(int n, float matriz[n][n]){
    int i, j;

    for(i = 0; i < n; i ++){
        for(j = 0; j < n; j ++){
            printf("%.2f ", matriz[i][j]);
        }

        printf("\n");
    }
}
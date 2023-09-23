/*
Decomposição LU pelo método de Doolittle.
A partir de A, conhecendo que L é uma matriz triangular inferior (com diagonal principal 1) e U uma matriz superior, e que L*U = A, podemos determinar seus valores.
*/

#include <stdio.h>
#include <stdlib.h>

void inicializaMatriz(int n, float matriz[n][n]);
void imprimeMatriz(int n, float matriz[n][n]);
void resolveSistema(int n, float L[n][n], float U[n][n]);

int main(){
    int i, j, k, n;
    float soma = 0;

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
        for(j = i; j < n; j ++){ //linha i e coluna j (j começa de i para não refazer cálculos)
            soma = 0;

            for(k = 0; k < i; k ++){ //somatório (até i pois o resto é zero)
                soma = soma + (L[i][k] * U[k][j]);
            }
            
            U[i][j] = A[i][j] - soma; // seria dividido por L[j][j], que é 1
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

    resolveSistema(n, L, U);

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

void resolveSistema(int n, float L[n][n], float U[n][n]){
    int i, j;
    float soma;
    float B[n], Y[n], X[n];

    printf("\n\nSistema A*X = B");
    printf("\nInsira os valores de B:");

    for(i = 0; i < n; i ++){
        printf("B[%d] = ", i);
        scanf("%f", &B[i]);
    }

    /*Procedimento:
        L * Y = B - como se "escalonássemos" B 
        U * X = Y - "A escalonado" * X = "B escalonado"
    */

   //L * Y = B
   Y[0] = B[0] / L[0][0]; 
    for(i = 1; i < n; i ++){
        soma = 0;
        for(j = 0; j < i; j ++){
            soma = soma + L[i][j] * Y[j];
        }

        Y[i] = B[i] - soma;
    }

    //U * X = Y
    X[n-1] = Y[n-1] / U[n-1][n-1];
    for(i = n-2; i >=0; i --){
        soma = 0;
        for(j = i+1; j < n; j ++){
            soma = soma + U[i][j] * X[j];
        }

        X[i] = (Y[i] - soma) / U[i][i];
    }

    for(i = 0; i < n; i ++){
        printf("%.2f ", X[i]);
    }

}
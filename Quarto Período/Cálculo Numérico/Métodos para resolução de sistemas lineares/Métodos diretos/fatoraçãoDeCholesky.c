/*
Seja A[n][n] uma matriz simétrica. A é deinida positiva se, e somente se, existe uma matriz G[n][n] triangular inferior com elementos da diagonal
estritamente positivos, tal que G*G^t = A
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void inicializaMatriz(int n, float matriz[n][n]);
int cholesky(int n, float matriz[n][n]);

int main(){
    int n, i, j;

    printf("Dimensão da matriz: ");
    scanf("%d", &n);

    float A[n][n];
    int k = 1;

    printf("Entrada de valores: \n");
    for(i = 0; i < n; i ++){
        printf("Linha %d: \n", i + 1);
        for(j = 0; j < n; j ++){
            printf("Coluna %d: ", j + 1);
            scanf("%f", &A[i][j]);
        }
    }

    if(cholesky(n, A)){
        printf("É matriz simétrica positiva");
    } else{
        printf("Não é matriz simétrica positiva");
    }

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

int cholesky(int n, float matriz[n][n]){
    float G[n][n];
    int i, j, k;
    float soma;

    inicializaMatriz(n, G);
    
    for(i = 0; i < n; i ++){
        for(j = i; j < n; j ++){
            soma = 0;

            if(i == j){ //verificamos raíz quadrada
                if(matriz[i][i] > 0){
                    for(k = 0; k < i; k ++){ //somatório
                        soma = soma + G[i][k] * G[k][j]; //equivalente à G[i][k]^2
                    }

                    if(matriz[i][i] > soma){ 
                        G[i][i] = sqrt(matriz[i][i] - soma);
                    } else{ //se matriz[i][i] < 0, calculamos raíz de um número negativo -> não existe
                        return 0;
                    }
                } else{ //número negativo não possui raíz
                    return 0;
                }
            } else{
                for(k = 0; k < i; k ++){ //somatório
                    soma = soma + G[i][k] * G[k][j]; 
                }

                G[i][j] = (matriz[i][j] - soma) / G[j][j];
            }
        }
    }

    return 1;
}
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void calculaA(int N, float A[N][N], float X[N]);
void calculaB(int N, float B[N], float X[N], float Y[N]);
void resolveSistema(int N, float A[N][N], float X[N], float B[N]);

int main(){
    int quantidadePontos, grau;

    printf("Insira a quantidade de pontos: ");
    scanf("%d", &quantidadePontos);

    float X[quantidadePontos], Y[quantidadePontos];

    for(int i = 0; i < quantidadePontos; i ++){
        printf("X%d: ", i);
        scanf("%f", &X[i]);

        printf("f(X%d): ", i);
        scanf("%f", &Y[i]);
    }

    printf("Grau da curva aproximada: ");
    scanf("%d", &grau);

    float coefcientes[grau + 1], A[grau + 1][grau + 1], B[grau + 1];

    calculaA(grau + 1, A, X);
    calculaB(grau + 1, B, X, Y);
    resolveSistema(grau + 1, A, coefcientes, B);

    printf("Função aproximada: ");
    for(int i = 0; i <= grau; i ++){
        printf("%f x^%d + ", coefcientes[i], i);
    }

    return 0;
}

/* 
Calcula coeficientes da matriz A baseando-se na fórmula 
A[i][k] = som j=1 até N (gi(xj)*gk(xj))
*/
void calculaA(int N, float A[N][N], float X[N]){
    int i, j, k;

    for(i = 0; i < N; i ++){
        for(k = 0; k < N; k ++){ //para cada coeficiente
            A[i][k] = 0;

            //somatório
            for(j = 0; j < N; j ++){
                float gi = pow(X[j], i);
                float gk = pow(X[j], k);
                A[i][k] += gi * gk;
            }

            printf("A[%d][%d] = %f\n", i, k, A[i][k]);
        }
    }
}

/*
Calcula os coeficientes do vetor B baseando-se na fórmula
B[i]= som j=1 até N (gi(xj)*f(xj))
*/
void calculaB(int N, float B[N], float X[N], float Y[N]){
    int i, j;

    for(i = 0; i < N; i ++){ //para cada coeficiente
        B[i] = 0;

        //somatório
        for(j = 0; j < N; j ++){
            float gi = pow(X[j], i);
            B[i] = B[i] + gi * Y[j];
        }

        printf("\nB[%d] = %f", i, B[i]);
    }
}

/*
Resolução do sistema A*X = B pela substituição de Gauss simples
*/
void resolveSistema(int N, float A[N][N], float X[N], float B[N]){
    int i, j, k;

    // escalonamento da matriz
    for (i = 0; i < N - 1; i++){ // para cada coluna
        for (j = i + 1; j < N; j++){ // para cada linha 
            float multiplicador = A[j][i] / A[i][i];

            for (k = i; k < N; k++) { // para cada elemento da linha
                A[j][k] = A[j][k] - (A[i][k] * multiplicador);
            }

            B[j] = B[j] - (B[i] * multiplicador);
        }
    }

    X[N - 1] = B[N - 1] / A[N - 1][N - 1];
    for (i = N - 2; i >= 0; i--) {
        int soma = 0;

        for (j = i + 1; j < N; j++) {
            soma = soma + (A[i][j] * X[j]);
        }

        X[i] = (B[i] - soma) / A[i][i]; 
    }
}
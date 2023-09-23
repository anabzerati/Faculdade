/*Método compacto de eliminação de Gauss com pivoteamento parcial - escalonamento usado para resolução de sistema e cálculo de determinante*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double **criaMatriz(int n);
void escalonamento(double **matriz, int n, double *resultado, int *linhas, int *sinal);
void pivoteamento(int n, double **matriz, int i, double *resultado, int *linhas, int *sinal);

int main(){
    int n, i, j, k;

    printf("Grau do sistema: ");
    scanf("%d", &n);

    double **matriz = criaMatriz(n); //matriz que representa os coeficientes do sistema
    double resultado[n]; //vetor que representa o resultado do sistema
    int linhas[n]; //vetor que controla a troca de linhas da matriz;
    int sinalDeterminante = 1; //variavel que controla o sinal do determinante da matriz;

    printf("Entrada de valores: \n");
    for (i = 0; i < n; i++) {
        printf("Linha %d: \n", i + 1);
        for (j = 0; j < n; j++) {
            printf("Coeficiente %d: ", j + 1);
            scanf("%lf", &matriz[i][j]);
        }
        printf("Igual a: ");
        scanf("%lf", &resultado[i]);
    }

    escalonamento(matriz, n, resultado, linhas, &sinalDeterminante);

    printf("\nMatriz escalonada e com multiplicadores: \n");
    for(i = 0; i < n; i ++){
        printf("linha %d: \n", linhas[i]);
        for(j = 0; j < n; j ++){
            printf("%lf ", matriz[i][j]);
        }
        printf(" = %lf", resultado[i]);
        printf("\n");
    }

    //resolução do sistema
    double x[n]; 

    x[n - 1] = resultado[n - 1] / matriz[n - 1][n - 1];
    
    for (i = n - 2; i >= 0; i--) {
        double soma = 0;
        for (j = i + 1; j < n; j++) {
            soma = soma + (matriz[i][j] * x[j]);
        }
        x[i] = (resultado[i] - soma) / matriz[i][i]; 
    }

    for(i = 0; i < n; i ++){
        printf("\nx%d = %lf", linhas[i] + 1, x[i]);
    }

    //calculando determinante
    double determinante = matriz[0][0];
    for(i = 1; i < n; i ++){
        determinante = determinante * matriz[i][i];
    }
    determinante = determinante * sinalDeterminante;

    printf("\nDeterminante da matriz: %lf", determinante);

    for (i = 0; i < n; i++) { //liberando memória
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}

double **criaMatriz(int n){
    int i;
    double **matriz = malloc(n * sizeof(double *)); //alocando memória para a matriz dos coeficientes do sistema

    for (i = 0; i < n; i++) {
        matriz[i] = (double *)malloc(n * sizeof(double));
    }

    return matriz;
}

void escalonamento(double **matriz, int n, double *resultado, int *linhas, int *sinal){
    int i, j, k;

    /*Procedimento: para cada coluna, reslizar o pivoteamento (achar maior módulo e trocar linhas), calcular o multiplicador e realizar a operação para toda a linha*/
    for(i = 0; i < n - 1; i ++){
        pivoteamento(n, matriz, i, resultado, linhas, sinal);

        for(j = i + 1; j < n; j ++){
            double multiplicador = (double)matriz[j][i] / matriz[i][i];

            for(k = i; k < n; k ++){
                matriz[j][k] = matriz[j][k] - (matriz[i][k] * multiplicador);
            }

            matriz[j][i] = multiplicador; //armazenando multiplicador - método compacto

            resultado[j] = resultado[j] - (resultado[i] * multiplicador); //segue padrão dos coeficientes
        }
    }
}

void pivoteamento(int n, double **matriz, int i, double *resultado, int *linhas, int *sinal){
    int j;
    int maior = i;

    //encontra maior módulo da coluna
    for (j = i + 1; j < n; j++) {
        if (fabs(matriz[j][i]) > fabs(matriz[maior][i])) {
            maior = j;
        }
    }

    //se o índice for diferente de i, realiza troca das linhas
    if (maior != i) {
        for (j = 0; j < n; j++) {
            double aux = matriz[i][j];
            matriz[i][j] = matriz[maior][j];
            matriz[maior][j] = aux;
        }

        double auxResultado = resultado[i];
        resultado[i] = resultado[maior];
        resultado[maior] = auxResultado;

        linhas[i] = maior;
        linhas[maior] = i;

        *sinal = *sinal * -1; //inverte sinal
    }
}
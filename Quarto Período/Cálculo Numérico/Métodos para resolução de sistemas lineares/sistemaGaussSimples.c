/*Método simples de eliminação de Gauss - escalonamento usada para resolução de sistema e cálculo de determinante*/

#include <stdio.h>
#include <stdlib.h>

int **escalonamento(int **matriz, int n);

int main() {
    int n, i, j, k;

    printf("Grau do sistema: ");
    scanf("%d", &n);

    int **matriz = (int **)malloc(n * sizeof(int *)); //alocando memória
    for (i = 0; i < n; i++) {
        matriz[i] = (int *)malloc((n + 1) * sizeof(int));
    }

    printf("Entrada de valores: \n");
    for (i = 0; i < n; i++) {
        printf("Linha %d: \n", i + 1);
        for (j = 0; j < n; j++) {
            printf("Coeficiente %d: ", j + 1);
            scanf("%d", &matriz[i][j]);
        }
        printf("Igual a: ");
        scanf("%d", &matriz[i][n]);
    }

    matriz = escalonamento(matriz, n);

    //resolução do sistema
    int x[n];

    x[n - 1] = matriz[n - 1][n] / matriz[n - 1][n - 1];
    for (i = n - 2; i >= 0; i--) {
        int soma = 0;
        for (j = i + 1; j < n; j++) {
            soma = soma + (matriz[i][j] * x[j]);
        }
        x[i] = (matriz[i][n] - soma) / matriz[i][i]; 
    }

    for(i = 0; i < n; i ++){
        printf("\n x%d = %d", i + 1, x[i]);
    }

    for (i = 0; i < n; i++) { //liberando memória
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}

int **escalonamento(int **matriz, int n) {
    int i, j, k;

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            int multiplicador = matriz[j][i] / matriz[i][i];

            for (k = i; k < n + 1; k++) {
                matriz[j][k] = matriz[j][k] - (matriz[i][k] * multiplicador);
            }
        }
    }

    return matriz;
}

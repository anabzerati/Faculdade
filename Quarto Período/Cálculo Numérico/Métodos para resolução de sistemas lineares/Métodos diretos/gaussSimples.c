/*Método simples de eliminação de Gauss - escalonamento*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, i, j, k;

    printf("Ordem da matriz: ");
    scanf("%d", &n);

    int matriz[n][n];

    printf("Entrada de valores: \n");
    for(i = 0; i < n; i ++){
        printf("Linha %d: \n", i + 1);
        for(j = 0; j < n; j ++){
            printf("Coluna %d: ", j + 1);
            scanf("%d", &matriz[i][j]);
        }
    }

    /*Procedimento: para cada coluna, calcular o multiplicador e realizar a operação para toda a linha*/
    for(i = 0; i < n - 1; i ++){
        for(j = i + 1; j < n; j ++){
            int multiplicador = matriz[j][i] / matriz[i][i];

            for(k = i; k < n; k ++){
                matriz[j][k] = matriz[j][k] - (matriz[i][k] * multiplicador);
            }
        }
    }

    printf("Matriz escalonada: \n");
    for(i = 0; i < n; i ++){
        for(j = 0; j < n; j ++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }


    return 0;
}
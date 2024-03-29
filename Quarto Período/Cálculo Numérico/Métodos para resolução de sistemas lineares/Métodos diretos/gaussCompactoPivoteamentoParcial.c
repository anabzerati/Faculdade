/*Método de eliminação de Gauss compacto com uso de privoetamento parcial*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void pivoteamento(int n, double matriz[][n], int i);

int main(){
    int i, j, k, n;

    printf("Ordem da matriz: ");
    scanf("%d", &n);

    double matriz[n][n];

    printf("Entrada de valores: \n");
    for(i = 0; i < n; i ++){
        printf("Linha %d: \n", i + 1);
        for(j = 0; j < n; j ++){
            printf("Coluna %d: ", j + 1);
            scanf("%lf", &matriz[i][j]);
        }
    }

    /*Procedimento: para cada coluna, reslizar o pivoteamento (achar maior módulo e trocar linhas), calcular o multiplicador e realizar a operação para toda a linha*/
    for(i = 0; i < n - 1; i ++){
        pivoteamento(n, matriz, i);

        for(j = i + 1; j < n; j ++){
            double multiplicador = (double)matriz[j][i] / matriz[i][i];

            for(k = i; k < n; k ++){
                matriz[j][k] = matriz[j][k] - (matriz[i][k] * multiplicador);
            }

            matriz[j][i] = multiplicador; //armazenando multiplicador - método compacto
        }
    }

    printf("Matriz escalonada e com multiplicadores: \n");
    for(i = 0; i < n; i ++){
        for(j = 0; j < n; j ++){
            printf("%lf ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void pivoteamento(int n, double matriz[][n], int i) {
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
    }
}


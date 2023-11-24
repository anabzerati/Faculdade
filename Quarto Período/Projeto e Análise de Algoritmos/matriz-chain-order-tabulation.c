// objetivo: encontrar o custo mínimo de multiplicar n matrizes
// ex: (A x B) x C ou A x (B x C)

#include <stdio.h>
#include <limits.h>

int dp[100][100];

int matrizChainOrderTabulation(int dimensoes[], int n) {
    int i, j, k, l;

    for (i = 1; i < n; i++) {
        dp[i][i] = 0; // custo de multiplicar uma matriz
    }

    for (i = 2; i < n; i++) { // tamanho da cadeia
        for (j = 1; j <= n - i; j++) { // início da cadeia
            k = i + j - 1; // final da cadeia de início i

            dp[j][k] = INT_MAX;
            for (l = j; l <= k - 1; l++) { // testando partições
                int custo = dp[j][l] + dp[l + 1][k] + dimensoes[j - 1] * dimensoes[l] * dimensoes[k];

                if (custo < dp[j][k]) {
                    dp[j][k] = custo;
                }
            }
        }
    }

    return dp[1][n - 1];
}

int main() {
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            dp[i][j] = -1;
        }
    }

    printf("O número mínimo de multiplicações é %d\n", matrizChainOrderTabulation(arr, n));

    return 0;
}

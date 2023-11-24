// objetivo: encontrar o custo mínimo de multiplicar n matrizes
// ex: (A x B) x C ou A x (B x C)

#include <stdio.h>
#include <limits.h>
 
int dp[100][100];
 
int matrizChainOrderMemo(int dimensoes[], int i, int j) {
    if (i == j) { // condição de parada, uma matriz
        return 0;
    }

    if (dp[i][j] != -1) { // subproblema já resolvido
        return dp[i][j];
    }

    dp[i][j] = INT_MAX;
    for (int k = i; k < j; k++) { // para cada partição possível
        int custo = matrixChainMemoised(dimensoes, i, k) + matrixChainMemoised(dimensoes, k + 1, j) + dimensoes[i - 1] * dimensoes[k] * dimensoes[j]; // custo de particionar em k
        dp[i][j] = (dp[i][j] < custo ? dp[i][j] : custo); // dp[i][j] = menor
    }
    
    return dp[i][j];
}
 
int main() {
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]); // Corrected this line
 
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            dp[i][j] = -1;
        }
    }
 
    printf("O número mínimo de multiplicações é %d\n", matrizChainOrderMemo(arr, 1, n-1));
    return 0;
}

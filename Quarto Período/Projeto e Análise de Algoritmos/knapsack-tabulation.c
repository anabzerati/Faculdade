// dada a capacidade de uma mochila e uma lista de itens com pesos e valores diferentes, encontrar o maior valor possível de se obter

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max(A,B) (A > B ? (A) : (B))

struct item{
    int peso, valor;
};

int dp[100][100];

int knapsack(int capacidadeMochila, struct item itens[], int n){
    int i, j;

    for(i = 0; i <= n; i ++){ 
        for (j = 0; j <= capacidadeMochila; j++) { 
            if (i == 0 || j == 0){
                dp[i][j] = 0;
            } else if (itens[i - 1].peso <= j) {  
                dp[i][j] = max(itens[i - 1].valor + dp[i - 1][j - itens[i - 1].peso], dp[i - 1][j]); 
            } else{
                dp[i][j] = dp[i - 1][j]; 
            }
        } 
    } 
  
    return dp[n][capacidadeMochila]; 
}

int main(){
    memset(dp, -1, sizeof(dp));

    struct item itens[] = {
        {10, 60}, {20, 100}, {30, 120}
    };
    
    printf("O valor máximo é %d\n", knapsack(50, itens, 3)); 

    return 0;
}

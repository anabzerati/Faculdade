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
    if(capacidadeMochila == 0 || n == 0){
        return 0;
    }

    if(dp[n-1][capacidadeMochila] != -1){ // problema já resolvido
        return dp[n-1][capacidadeMochila];
    }

    if(itens[n-1].peso > capacidadeMochila){ // não cabe
        return dp[n-1][capacidadeMochila] = knapsack(capacidadeMochila, itens, n-1);
    }

    return max(itens[n-1].valor + knapsack(capacidadeMochila - itens[n-1].peso, itens, n-1), knapsack(capacidadeMochila, itens, n-1)); // maior com ou sem
}

int main(){
    memset(dp, -1, sizeof(dp));

    struct item itens[] = {
        {10, 60}, {20, 100}, {30, 120}
    };
    
    printf("O valor máximo é %d\n", knapsack(50, itens, 3)); 

    return 0;
}

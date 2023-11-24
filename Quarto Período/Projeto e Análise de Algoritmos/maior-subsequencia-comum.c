// encontrar a maior subsequencia comum entre duas strings

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max(A,B) (A > B ? (A) : (B))

int dp[100][100];

int maiorSubsequenciaComum(char *seq1, char *seq2){
    int i, j;
    int tam1 = strlen(seq1);
    int tam2 = strlen(seq2);

    for(i = 0; i <= tam1 + 1; i ++){
        dp[i][0] = 0;
    }

    for(j = 0; j <= tam2 + 1; j ++){
        dp[0][j] = 0;
    }

    for(i = 1; i <= tam1; i ++){
        for(j = 1; j <= tam2; j ++){
            if(seq1[i - 1] == seq2[j - 1]){ // caracteres iguais
                dp[i][j] = dp[i - 1][j - 1] + 1; // tam da subcadeia anterior + 1
            } else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // maior das subcadeias com uma das letras só
            }
        }
    }

    return dp[tam1][tam2];
}

int main(){
    char seq1[] = "ABCBDAB";
    char seq2[] = "BDCAB";

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            dp[i][j] = -1;
        }
    }

    printf("O tamanho da maior subsequência comum é: %d\n", maiorSubsequenciaComum(seq1, seq2));

    return 0;
}
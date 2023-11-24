// encontrar a maior subsequência q seja um aplíndromo em uma string

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max(A,B) (A > B ? (A) : (B))

int dp[101][101];  // Corrigido o tamanho do array e o tipo

void strrev(char* str) {
    if (!str) { // vazia
        return;
    }

    int i = 0;
    int j = strlen(str) - 1;
 
    while (i < j) {
        char c = str[i];
        str[i] = str[j];
        str[j] = c;
        i++;
        j--;
    }
}

int maiorSubsequenciaPalindromo(char *seq){
    int tam = strlen(seq);

    char *seqInvertida = malloc((tam + 1) * sizeof(char));
    strcpy(seqInvertida, seq);
    strrev(seqInvertida);
    
    int i, j;

    for(i = 0; i <= tam; i ++){
        dp[i][0] = 0;
        dp[0][i] = 0;
    }

    for(i = 1; i <= tam; i ++){
        for(j = 1; j <= tam; j ++){
            if(seq[i - 1] == seqInvertida[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    free(seqInvertida);

    return dp[tam][tam];
}

int main(){
    char seq[] = "BCANAKJ";

    memset(dp, 0, sizeof(dp));

    printf("O tamanho da maior subsequência palindrômica é: %d\n", maiorSubsequenciaPalindromo(seq));

    return 0;
}

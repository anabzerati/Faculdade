/*labirinto
matriz com paredes do labirinto sendo -1 e espaços livres sendo 0
sabendo o ponto de partida e o destino, é possível descobrir o menor caminho para percorrer
obs: se não houver caminho, imprimir -1
ENTRADA: N (tamanho), I(coluna de partida), C(coluna de chegada), dps N linhas com N inteiros (preenchendo matriz)
SAÍDA: inteiro com quantidade de passos para ir de I a C (ou -1 se não houver caminho)*/

#include <stdio.h>
#include <stdlib.h>

int matriz[25][25];
int flag = 0;

int valida(int N, int linha, int col);
void recursao(int linha, int col, int passos, int N, int C);

int main(){
    int N, C, I, i, j;

    scanf("%d %d %d", &N, &I, &C);
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            scanf("%d", &matriz[i][j]);
        }
    }

    recursao(0, I, 0, N, C);
    printf("-1\n");

    return 0;
}

int valida(int N, int linha, int col){
    if(linha >=0 && col >= 0 && linha < N && col < N && matriz[linha][col] == 0){ //se estiver dentro da matriz e em posição disponível
        return 1; //válido
    }
    return 0; //não válido
}

void recursao(int linha, int col, int passos, int N, int C){
    if(linha == N-1 && col == C && matriz[linha][col] == 0){ //chegou ao final em posição válida
        printf("%d\n", passos);
        exit(0);
    }

    if(valida(N, linha, col) == 0){ //não válido
        return;
    }

    matriz[linha][col] = 1;
    recursao(linha+1, col, passos+1, N, C);
    recursao(linha, col+1, passos+1, N, C);
    recursao(linha, col-1, passos+1, N, C);
}

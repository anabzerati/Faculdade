/*ordenar vetor contendo palavras usando shell sort. Primeiro passo tem tamanho P = 2^k com N/8<P<=N/4.
ENTRADA: N número de palavras e as palavras
SAÍDA: uma linha com as palavras após cada passo até que se termine de ordenar o vetor
*/

#include <stdio.h>
#include <string.h>

void shellsort(int N, char palavras[N][50]);
void printar(int N, char palavras[N][50]);

int main(){
    int N, i, j=0;
    scanf("%d", &N);
    char palavras[N][50];

    for(i=0; i<N; i++){
        scanf(" %s", palavras[i]);
    }

    shellsort(N, palavras);

    return 0;
}

void shellsort(int N, char palavras[N][50]){
    int i, j, k, passo;
    char aux[50];

    passo = 1;
    while(passo<=N/4){
        passo = passo*2;
    }

    while(passo>1){
        passo = passo/2;
        for(k=0; k<passo; k++){ //repetir insercion sort P vezes
            for(i=k+passo; i<N; i=i+passo){
                strcpy(aux, palavras[i]);
                j = i;
                while(j-passo>=0 && strcmp(palavras[j-passo], aux)>0){
                    strcpy(palavras[j], palavras[j-passo]);
                    j = j-passo;
                }
                strcpy(palavras[j], aux);
            }
        }
        printar(N, palavras);
    }
    return;
}

void printar(int N, char palavras[N][50]){
    int i, j;
    for(i=0; i<N; i++){
        printf("%s ", palavras[i]);
    }
    printf("\n");
}
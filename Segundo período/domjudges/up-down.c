/*ordenação up-down
usando insertion sort, ordenar vetor de N posições de forma crescente até a posição k e decrescente a partir dela
ENTRADA: N (quantidade de elementos) e k, seguidos de N numeros reais
SAÍDA: uma linha com valores armazenados no vetor com 3 casas decimais depois da ordenação
*/

#include <stdio.h>
#include <stdlib.h>

void insertion_up(double *vet, int max);
void insertion_down(double *vet, int min, int N);

int main(){
    int N, k, i;
    scanf("%d %d", &N, &k);
    double vetor[N];

    for(i=0; i<N; i++){
        scanf("%lf", &vetor[i]);
    }

    insertion_up(vetor, k);
    insertion_down(vetor, k+1, N);

    for(i=0; i<N; i++){
        printf("%.3lf ", vetor[i]);
    }

    return 0;
}

void insertion_up(double *vet, int max){
    int i, j;
    double valor;

    for(i=1; i<=max; i++){
        valor = vet[i];
        j = i;
        while(j>0 && vet[j-1]>valor){
            vet[j] = vet[j-1];
            j--;
        }
        vet[j] = valor;
    }
}

void insertion_down(double *vet, int min, int N){
    int i, j;
    double valor;

    for(i=min+1; i<N; i++){
        valor = vet[i];
        j = i;
        while(j>=min && vet[j-1]<valor){
            vet[j] = vet[j-1];
            j--;
        }
        vet[j] = valor;
    }
}
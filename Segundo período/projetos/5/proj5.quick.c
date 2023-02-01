/*ordenação com quicksort
vetor de 200 mil "BigInt" (struct). Entrada: arquivo bigint.dat, ordenar de forma crescente, inserir em quick.dat*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define max 200000

typedef struct biggo
{
    int high, low;
} BigInt;

void quicksort(BigInt *vet, int comeco, int final);
void troca(BigInt *primeiro, BigInt *segundo);

int main()
{
    BigInt vet[max];
    FILE *entrada, *saida;
    int i;
    clock_t tempo_clock;
    double tempo_total;
    entrada = fopen("bigint.dat", "r"); // abre para ler
    saida = fopen("quick.dat", "w");    // abre/cria para escrita

    if (entrada == NULL)
    { // não há bigint.dat
        return 0;
    }

    for (i = 0; i < max; i++)
    {
        fscanf(entrada, "%d %d", &vet[i].high, &vet[i].low);
        if (vet[i].high < 0)
        { // para números negativos, trocaremos seu low para "negativo" também para facilitar ordenação
            vet[i].low = vet[i].low * (-1);
        }
    }

    tempo_clock = clock();
    quicksort(vet, 0, max - 1);
    tempo_clock = clock() - tempo_clock;
    tempo_total = tempo_clock / (double)CLOCKS_PER_SEC;

    for (i = 0; i < max; i++)
    {
        if (vet[i].high < 0)
        { // volta à representação original do número
            vet[i].low = vet[i].low * (-1);
        }
        fprintf(saida, "%d %d\n", vet[i].high, vet[i].low);
    }

    printf("%lf", tempo_total);

    fclose(entrada);
    fclose(saida);

    return 0;
}

void quicksort(BigInt *vet, int comeco, int final)
{
    int i, pivo, bigger;
    if (comeco < final)
    { // Enquanto ainda tiver mais de uma posição no vetor verificado
        pivo = final;
        bigger = comeco;
        for (i = comeco; i < final; i++)
        {
            if (vet[i].high < vet[pivo].high || (vet[i].high == vet[pivo].high && vet[i].low < vet[pivo].low))
            {                                 // Verifica o high e se for igual verifica o low
                troca(&vet[i], &vet[bigger]); 
                bigger++;                     
            }
        }
        troca(&vet[bigger], &vet[pivo]);    // coloca o pivo no seu devido lugar
        quicksort(vet, comeco, bigger - 1); // chamada recursiva para lado esquerdo do vetor
        quicksort(vet, bigger + 1, final);  // chamada recursiva para lado direito do vetor
    }
}

void troca(BigInt *primeiro, BigInt *segundo)
{
    BigInt aux;
    aux = *primeiro;
    *primeiro = *segundo;
    *segundo = aux;
}
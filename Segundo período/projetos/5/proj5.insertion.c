/*ordenação com insertionsort
vetor de 200 mil "BigInt" (struct). Entrada: arquivo bigint.dat, ordenar de forma crescente, inserir em quick.dat*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define max 200000

typedef struct biggo
{
    int high, low;
} BigInt;

void insertionsort(BigInt *vet, int tam);

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
    insertionsort(vet, max);
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

void insertionsort(BigInt *vet, int tam)
{
    int i, j;
    BigInt aux;
    for (i = 1; i < tam; i++)
    {
        aux = vet[i];
        j = i;
        while ((aux.high < vet[j - 1].high || (aux.high == vet[j - 1].high && aux.low < vet[j - 1].low)) && j > 0) //verifica high e se forem iguais, verifica low
        {
            vet[j] = vet[j - 1];
            j--;
        }
        vet[j] = aux;
    }
}
#ifndef STRUCTS_H
#define STRUCTS_H

#include <stdio.h>
#include <io.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <windows.h>

/* Definição de constantes */

#define MAX_NOME 30 //obs verificar depois
#define MAX_QUANTIDADE 100
#define TAM_CHAVE 5
#define TAM_REGISTRO 192

#define NOME_ARQ_DADOS "data/movies.dat"
#define NOME_INDICE_PRIMARIO "data/iprimary.idx"
#define NOME_INDICE_TITULO "data/ititles.idx"

/* Definição de estruturas */
typedef struct{
    char chavePrimaria[TAM_CHAVE + 1];
    char tituloPortugues[MAX_NOME + 1];
    char tituloOriginal[MAX_NOME + 1];
    char diretor[MAX_NOME + 1];
    char anoLancamento[5];
    char pais[MAX_NOME + 1];
    char nota;
} Filme;

typedef struct{
    char chavePrimaria[TAM_CHAVE + 1];
    long RRN;
} IndicePrimario;

typedef struct{
    char titulo[MAX_NOME + 1];
    char chavePrimaria[TAM_CHAVE + 1]; 
} IndiceSecundario;

typedef struct{
    FILE *dadosP;
    FILE *primarioP;
    FILE *secundarioP;
} Arquivos;

#endif //STRUCTS_H
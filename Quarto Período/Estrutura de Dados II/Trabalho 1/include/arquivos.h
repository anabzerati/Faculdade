/* Biblioteca para manipulação de arquivos */
#ifndef ARQUIVOS_H
#define ARQUIVOS_H

#include "structs.h"
#include "auxiliares.h"


/* Função que abre os arquivos de dados e índices */
Arquivos abreArquivos();

/* Carrega índice primário do disco para RAM, retorna vetor de índices ordenado*/
IndicePrimario *carregaPrimario(FILE *, FILE *); 

/* Carrega índice secunsário do disco para RAM, retorna vetor de índices ordenado*/
IndiceSecundario *carregaSecundario(FILE *, FILE *);

/* Refaz indice primário a partir do arquivo de dados*/
void criaPrimario(FILE *, FILE *);

/* Refaz indice secundário a partir do arquivo de dados*/
void criaSecundario(FILE *, FILE *);

/* Insere registro no arquivo de dados e nos vetores de índices. Retorna 1 se a operação teve sucesso e 0 caso não*/
int insereRegistro(Filme *);

/* Remove registro do arquivo de índices e adiciona flag de exclusão no de dados. Retorna 1 se a operação teve sucesso e 0 caso não*/
int removeRegistro(int, char *);

/* Altera registro no arquivo de dados. Retorna 1 se a operação teve sucesso e 0 caso não*/
int alteraRegistro(char, char *);

/* Ordena o vetor de índices primários considerando a chave primária. Insertion Sort*/
void ordenaPrimario();

/* Ordena o vetor de índices secundários considerando o título. Insertion Sort*/
void ordenaSecundario();

/* Busca filme pelo índice primário e retorna sua posição no vetor. Caso não haja registro com esse ID, retorna -1. Busca binária*/
int buscaPrimaria(char *chavePrimaria, int, int);

/* Busca filme pelo índice secundário a partir do título e retorna os indices da primeira e útlima aparição dessa chave secundária. Caso não haja registro com esse ID, retorna -1 em j*/
void buscaSecundaria( char *titulo, int *, int *);

/* Atualiza dados dos índices da RAM para o disco. Atualiza flag da header*/
void atualizaIndices();

/* Chama função de atualizar índices e libera as memórias alocadas*/
void sair();

/* Função para compactar arquivo de dados, removendo fisicamente os registros excluidos (logicamente)*/
void compactarDados();

#endif //ARQUIVOS_H
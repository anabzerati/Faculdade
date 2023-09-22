/* Biblioteca com funções auxiliares ao projeto */
#ifndef AUXILIARES_H
#define AUXILIARES_H

#include "structs.h"
#include "arquivos.h"

/* Função que verifica se o arquivo de dados existe. Retorna 0 se não existir e 1 se existir*/
int verificaDados();

/* Função que verifica se o índice primário existe. Retorna 0 se não existir e 1 se existir*/
int verificaPrimario();

/* Função que verifica se o índice secundário existe. Retorna 0 se não existir e 1 se existir*/
int verificaSecundario();

/* A partir do índice primário, lê os dados do filme correspondente e retorna uma struct preenchida com as informações*/
Filme *leFilmeIndicePrimario(int);

/* Remove posição do vetor de índice primário a partir de sua posição, readequando os demais elementos. Retorna 1 se a operação teve sucesso e 0 caso não*/
int removePosicaoPrimario(int pos);

/* Remove posição do vetor de índice secundário a partir de sua posição, readequando as posições dos demais elementos. Retorna 1 se a operação teve sucesso e 0 caso não*/
int removePosicaoSecundario(int pos);

#endif // AUXILIARES_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define tam_fila 100 //tamanho max. fila
#define N 5 //Tamanho da matriz de conexões e vetor de distâncias

//ED para fila
//------------------------------------------------------
//Tipo fila
typedef struct
{
  int A[tam_fila];
  int inicio, fim;
} fila;
//------------------------------------------------------

//Definição de funções
//------------------------------------------------------
void Definir(fila *q);
bool Vazia(fila *q);
bool Cheia(fila *q);
bool Inserir(fila *q, int elem);
bool Remover(fila *q, int *elem);

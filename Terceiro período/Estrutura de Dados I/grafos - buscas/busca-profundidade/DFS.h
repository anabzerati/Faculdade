#include <stdio.h>
#include <stdlib.h>

struct node {
  int vertice;
  struct node* prox;
};

struct node* criaNo(int v);

struct Graph {
  int numNos;
  int* visitado;
  struct node** listaAdj;
};

struct Graph* criaGrafo(int vertices);
void adicionaAresta(struct Graph* grafo, int origem, int destino);
void imprimeGrafo(struct Graph* grafo);

void DFS(struct Graph* grafo, int vertice);
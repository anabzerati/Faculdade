#include<stdio.h>
#include<stdlib.h>
#include <limits.h>

typedef struct graph {
  int numNos;
  int numArestas;
  int **matrizAdj;
} graph_t;


void dijkstra(graph_t *G,  int origem);
#include <stdio.h>
#include <stdlib.h>

#define INFINITY 99999

//aresta 
struct Edge {
  int inicio;  //no inicial da aresta
  int fim;  //no final da aresta
  int peso;  //peso da aresta (inicio, fim)
};

//TAD para grafo - lista de arestas
struct Graph {
  int numVertices;        
  int numArestas;        
  struct Edge *arestas; 
};

void bellmanford(struct Graph *g, int origem);
void display(int vet[], int tam);
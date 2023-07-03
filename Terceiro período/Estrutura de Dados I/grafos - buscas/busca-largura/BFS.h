#include <stdio.h>
#include <stdlib.h>
#define tam 40

struct fila {
  int items[tam];
  int inicio;
  int fim;
};

struct fila* criaFila();
void enfileira(struct fila* f, int);
int desenfileira(struct fila* f);
void display(struct fila* f);
int vazia(struct fila* f);
void imprime(struct fila* f);

struct node {
  int vertice;
  struct node* prox;
};

struct node* criaNo(int);

struct Graph {
  int numNos;
  struct node** listaAdj;
  int* visitado;
};

struct Graph* criaGrafo(int vertices);
void adicionaAresta(struct Graph* grafo, int origem, int destino);
void imprimeGrafo(struct Graph* grafo);

void bfs(struct Graph* grafo, int inicio);
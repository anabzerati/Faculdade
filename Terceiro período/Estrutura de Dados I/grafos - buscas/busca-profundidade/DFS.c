#include "DFS.h"

struct node* criaNo(int v){
    struct node* novo = malloc(sizeof(struct node));

    novo->vertice = v;
    novo->prox = NULL;

    return novo;
}

struct Graph* criaGrafo(int vertices){
    struct Graph* grafo = malloc(sizeof(struct Graph));

    grafo->numNos = vertices;

    grafo->listaAdj = malloc(vertices * sizeof(struct node*)); //alocando vetores
    grafo->visitado = malloc(vertices * sizeof(int));

    int i;
    for (i = 0; i < vertices; i++) { //inicializando como nulo
        grafo->listaAdj[i] = NULL;
        grafo->visitado[i] = 0;
    }

    return grafo;
}

void adicionaAresta(struct Graph* grafo, int origem, int destino){
    //nó de origem para destino
    struct node* novoNo = createNode(destino);
    novoNo->prox = grafo->listaAdj[origem]; //adiciona o nó na lista de adjacência
    grafo->listaAdj[origem] = novoNo;

    //nó de destino para origem
    novoNo = createNode(origem);
    novoNo->prox = grafo->listaAdj[destino];
    grafo->listaAdj[destino] = novoNo;
}

void imprimeGrafo(struct Graph* grafo){
    int v;

    for (v = 0; v < grafo->numNos; v++) {
        struct node* temp = grafo->listaAdj[v];

        printf("\nLista de adjacência do vértice %d\n ", v);
        while (temp) {
            printf("%d -> ", temp->vertice);
            temp = temp->prox;
        }
        printf("\n");
    }
}

void DFS(struct Graph* grafo, int vertice){
    struct node* listaAdj = grafo->listaAdj[vertice];
    struct node* temp = listaAdj;

    grafo->visitado[vertice] = 1; //começamos pelo início
    printf("Visitado: %d \n", vertice);

    while (temp != NULL) {
        int verticeAdj = temp->vertice;

        if (grafo->visitado[verticeAdj] == 0) { //se o adjacente não foi verificado
            DFS(grafo, verticeAdj); //verifica ele e seus adjacentes -> profundidade
        }

        temp = temp->prox;
    }

}
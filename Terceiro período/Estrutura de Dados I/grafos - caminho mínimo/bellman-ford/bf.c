#include "bf.h"

void bellmanford(struct Graph *g, int origem) {
    int i, j, u, v, w;

    int maxVertices = g->numVertices;
    int maxArestas = g->numArestas;

    int distancia[maxVertices], predecessor[maxVertices];

    //inicializar vetores
    for (i = 0; i < maxVertices; i++) {
        distancia[i] = INFINITY;
        predecessor[i] = 0;
    }

    distancia[origem] = 0; //distancia de um nó para ele mesmo = 0

    //"relaxar" arestas
    for (i = 1; i <= maxVertices - 1; i++) {
        for (j = 0; j < maxArestas; j++) {
            u = g->arestas[j].inicio;
            v = g->arestas[j].fim;
            w = g->arestas[j].peso;

            if (distancia[u] != INFINITY && distancia[v] > distancia[u] + w) { //se u se conecta com a origem e se da origem à v diretamente o caminho é maior do que origem -> u -> v
                distancia[v] = distancia[u] + w; //troca caminho à v sendo origem -> u -> v
                predecessor[v] = u; //predecessor de v se torna u (ao invés da origem)
            } 
        }
    }

    //laço para detectar ciclo negativo - maxVertices - 1 é o suficiente para detectar o menor caminho. Então, se, depois dessas iterações, o caminho ainda diminuir, há um ciclo negativo
    for (i = 0; i < maxArestas; i++) {
        u = g->arestas[j].inicio;
        v = g->arestas[j].fim;
        w = g->arestas[j].peso;

        if (distancia[u] != INFINITY && distancia[v] > distancia[u] + w) {
            printf("O grafo possui um ciclo negativo\n");
            return;
        }
    }

    //imprimir distancia e predecessores
    printf("Vetor de distancias: ");
    display(distancia, maxVertices);
    printf("Vetor de predecessores: ");
    display(predecessor, maxVertices);
}

void display(int vet[], int tam) {
    int i;
    for (i = 0; i < tam; i++) {
        printf("%d ", vet[i]);
    }
    printf("\n");
}
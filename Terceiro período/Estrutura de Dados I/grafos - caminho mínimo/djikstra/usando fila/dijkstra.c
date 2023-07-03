#include "dijkstra.h"

void dijkstra(graph_t *G,  int origem) {
    int count, distMin, ultimoVisitado;

    int distancia[G->numNos];
    int predecessor[G->numNos];
    int visitado[G->numNos];

    int i, j, k;

    //inicializar vetores
    for (i = 0; i < G->numNos; i++){
        if (G->matrizAdj[origem][i] > 0){ //se há ligação direta entre a origem e o nó i
            distancia[i] = G->matrizAdj[origem][i];
        } else {
            distancia[i] = INT_MAX;
        }
        visitado[i] = 0; //nenhum nó foi visitado
        predecessor[i] = origem; //anterior de todos é a arigem
    }

    distancia[origem] = 0; //distancia de um nó para ele mesmo é 0
    visitado[origem] = 1;
    count = 1;

    while (count < G->numNos - 1) {
        distMin = INT_MAX;

        for (i = 0; i < G->numNos; i++) {
            if (distancia[i] < distMin && visitado[i] == 0) { //buscamos a menor distancia da origem a um nó (ainda não visitado)
                distMin = distancia[i];
                ultimoVisitado = i;
            }
        }

        visitado[ultimoVisitado] = 1; //encontrada a menor distância, visitamos o nó e verificamos seus adjacentes

        for (i = 0; i < G->numNos; i++) {
            if (visitado[i] == 0) { //se ainda não foi verificado
                if (G->matrizAdj[ultimoVisitado][i] < INT_MAX && distMin + G->matrizAdj[ultimoVisitado][i] < distancia[i]) { //se há ligação entre u e i e se o caminho da origem à i (diretamente) for maior do que origem -> u -> i
                    distancia[i] = distMin + G->matrizAdj[ultimoVisitado][i]; //atualiza o menor caminho
                    predecessor[i] = ultimoVisitado; //atualiza o predecessor
                }
            }
        }

        count++;
    }

}
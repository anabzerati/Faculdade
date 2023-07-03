#include "BFS.h"

struct fila* criaFila() {
    struct fila* f = malloc(sizeof(struct fila));

    f->inicio = -1; //vazia
    f->fim = -1;

    return f;
}

int vazia(struct fila* f) {
    if (f->fim == -1) //se não tem elementos
        return 1;
    
    return 0;
}

void enfileira(struct fila* f, int val){
    if (f->fim == tam - 1){ //cheia
        return;
    } else {
        if (f->inicio == -1) { //vazia
            f->inicio = 0;
        }

        f->fim++;
        f->items[f->fim] = val; //adiciona no final da fila
    }
}

int desenfileira(struct fila* f){
    int item;

    if (vazia(f)) {
        return -1;
    } 
    
    item = f->items[f->inicio]; //pega primeiro elemento
    f->inicio++;

    if (f->inicio > f->fim) {
        f->inicio = f->fim = -1;
    }
    
    return item;
}

void imprime(struct fila* f){
    int i = f->inicio;

    if (vazia(f)) {
        printf("Fila vazia\n");
    } else {
        for (i = f->inicio; i < f->fim + 1; i++) {
            printf("%d ", f->items[i]);
        }
        printf("\n");
    }
}

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

void bfs(struct Graph* grafo, int inicio){
    struct fila* f = criaFila();

    grafo->visitado[inicio] = 1; //começamos pelo início
    enfileira(f, inicio);

    while (!vazia(f)) {
        imprime(f);

        int verticeAtual = desenfileira(f);

        printf("Visited %d\n", verticeAtual);

        struct node* temp = grafo->listaAdj[verticeAtual]; //pegamos os adjacentes ao atual

        //percorre toda a lista de adjacência enfileirando os que ainda não foram verificados -> busca em largura
        while (temp) {
            int verticeAdj = temp->vertice;

            if (grafo->visitado[verticeAdj] == 0) { //se ainda não visitamos
                grafo->visitado[verticeAdj] = 1;
                enfileira(f, verticeAdj);
            }

            temp = temp->prox; //verifica próximo da lista
        }
  } 
}
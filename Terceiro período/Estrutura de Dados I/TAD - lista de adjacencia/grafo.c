#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

//EDs para nó e grafo
//----------------------------------
struct no {
	int id;
	int val;
	struct no *prox;
};

struct grafo {
	int id;
	int nNo; //número de nós
	No vertices; //array de vértices, no*
};
//----------------------------------

//Implementação das funções/operações
//----------------------------------

No criaNo(int id, int val){
	No n = (No) malloc(sizeof(struct no));
	n->id = id;
	n->prox = NULL;
	n->val = val;
	return n;
}

void addNo(No n, int id, int val){ //adiciona nó na lista do nó n (adjacente a ele)
	No novo = criaNo(id, val);
	if(n == NULL){
		return;
	}
	while(n->prox != NULL){ //procura último nó da lista de adjacência do nó n
		n = n->prox;
	}
	n->prox = novo;
}

Grafo criaGrafo(){
	Grafo G = (Grafo) malloc(sizeof(struct grafo));
	G->vertices = NULL; //ainda não tem vetor de vértices
	G->nNo = 0; //começa com 0 nós

	return G;
}

//Função para efetuar a leitura do grafo via arquivo
void leArquivo(Grafo G, const char *filename){ //const para não poder alterar 
    FILE *fp;
    int bsize = 20; //máximo de caracteres de uma linha
    int o, d, v, i;
    
    char buffer[bsize];
    fp = fopen(filename,"r");
	
	//Primeira linha do arquivo = número de nós
    fgets(buffer,bsize, fp); //carrega a linha toda em buffer
    sscanf(buffer,"%d", &G->nNo); //salva o numero de vertices/nós
    G->vertices = (No) malloc(G->nNo * sizeof(struct no)); // aloca vetor de vertices
    
    //Primeiro elemento de cada lista identifica o vertice que a lista representa
    for(i = 0; i < G->nNo; i++){
		(G->vertices + i)->id = i; //obs: notação de ponteirp, equivalente à G->vertices[i] para array dinâmico
		(G->vertices + i)->val = -1; // Valor default (não utilizado)
		(G->vertices + i)->prox = NULL;	
	}

    //Percorre o arquivo
	while(!feof(fp)){
        fgets(buffer,bsize, fp); //pega linha e guarda em buffer
        sscanf(buffer,"%d %d %d", &o, &d, &v); //pega de buffer e guarda nas variáveis auxiliares

        addNo((G->vertices + o), d, v); //adiciona vertice com id = d e valor = v na posição o da lista de vértices
    }

    fclose(fp);
    return;
}

void imprimeGrafo(Grafo G){ //imprime grafo a partir das listas de adjacência
	int i;
	printf("\nGrafo - Lista de Adjacência\n\n");
	for(i = 0; i < G->nNo; i++){
		printf("(%d)", (G->vertices + i)->id);
		imprimeNo((G->vertices + i));
		printf("\n");	
	}
}

void imprimeNo(No n){ //percorre lista do nó imprimindo adjacências
	while(n != NULL){
		printf("-> (%d, val: %d)", n->id, n->val);
		n = n->prox;
	}
}
//----------------------------------


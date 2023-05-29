#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "grafo.h"
#include "fila.h"

//------------------------------------------------------
//Principal//matriz A (de adj.): representa as conexões entre as cidades 0,...,N-1, 
//vetor 'dist': dist[i] é a distância da cidade fixada 'c' até cada cidade 'i'

int main() {
	int **A; //vai guardar a matriz de adjacência
	int dist[5]; //vai guardar a menor distância de c para o resto
	int i, j, c = 0; //c é o vértice inicial (calcula-se caminho mínimo dele pros demais)
	fila F;

	leArquivo("digrafo.txt", A); //lê dados de arquivo, cria grafo e matriz de adjacência

	for (j=0; j<N; j++)  
	    dist[j] = 1000; //começa com a maior distância, dist[j], para todo j
    
	dist[c] = 0; //distância de c para ele mesmo (= 0)
    Definir(&F); //cria fila
    Inserir(&F,c); //insere c na fila

	//tira da fila uma cidade i, e coloca na fila as cidades vizinhas j com distancias já computadas
    while (!Vazia(&F)) 
	{ 
       Remover(&F,&i); //Remove da fila (i é o elemento corrente a partir daqui)

       for (j=0; j<N; j++){
          if (A[i][j] != 0 && (dist[j] > dist[i] + A[i][j])) //anda toda a linha de i da matriz. Se i tem conexãoo com j (A[i][j] == 1) e j ainda não tiver sido checado
		  {
			printf("entrou aqui");
			dist[j] = dist[i] + A[i][j]; //está um elemento mais distante de i (acresce pelo peso da aresta);
			Inserir(&F, j);
          }
	   }
    }
	
	//Imprime vetor de distâncias de 'c' para as demais cidades 'i'
	for (i=0; i<N; i++)
	   printf("dist[%d]: %d\n", i, dist[i]);	
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "grafo.h"
#include "fila.h"

int main() {
	int **A; //vai guardar a matriz de adjacência
	int dist[N]; //vai guardar a menor distância de c para o resto
	int i, j, c = 0; //c é o vértice inicial (calcula-se caminho mínimo dele pros demais)
	fila F;

	leArquivo("digrafo.txt", &A); //lê dados de arquivo, cria grafo e matriz de adjacência

	for (j=0; j<N; j++)  
	    dist[j] = 1000; //começa com a maior distância, dist[j], para todo j
    
	dist[c] = 0; //distância de c para ele mesmo (= 0)
    Definir(&F); //cria fila
    Inserir(&F,c); //insere c na fila

	//tira da fila i, e coloca na fila adjacentes j
    while (!Vazia(&F)) 
	{ 
    	Remover(&F,&i); //Remove da fila (i é o elemento corrente a partir daqui)

       for (j=0; j<N; j++){ //verificaremos toda a linha i (quem é adjacente à i)
          if (A[i][j] > 0 && (dist[j] == 1000 || dist[j] > dist[i] + A[i][j])) //se i tem conexãoo com j e j ainda não tiver sido checado ou tiver caminho que não mínimo
		  {
			dist[j] = dist[i] + A[i][j]; //está um elemento mais distante de i (acresce pelo peso da aresta);
			Inserir(&F, j);
          }
	   }
    }
	
	//Imprime vetor de distâncias de 'c' para as demais cidades 'i'
	for (i=0; i<N; i++)
	   printf("dist[%d]: %d\n", i, dist[i]);	
}

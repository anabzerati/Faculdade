 #include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "grafo.h"
#include "fila.h"

//ler arquivo e guardar em grafo
//transformar grafo em matriz de incidencia


//------------------------------------------------------
//Principal//matriz A (de adj.): representa as conexões entre as cidades 0,...,N-1, 
//vetor 'dist': dist[i] é a distância da cidade fixada 'c' até cada cidade 'i'

int main() {
	//Inicialização da matriz com as cidades interconectadas
	int A[N][N] = { {0,1,0,1,1}, {0,0,1,0,0}, {0,0,0,0,1}, {0,0,1,0,1}, {0,0,0,1,0} };
	int dist[N]; //vai guardar a menor distância de c para o resto
	int i, j, c = 0; //c é o vértice inicial (calcula-se caminho mínimo dele pros demais)
	fila F;
	
	for (j=0; j<N; j++)  
	    dist[j] = N; //começa com a maior distância, dist[j], para todo j
    
	dist[c] = 0; //distância de c para ele mesmo (= 0)
    Definir(&F); //cria fila
    Inserir(&F,c); //insere c na fila

	//tira da fila uma cidade i, e coloca na fila as cidades vizinhas j com distancias já computadas
    while (!Vazia(&F)) 
	{ 
       Remover(&F,&i); //Remove da fila (i é o elemento corrente a partir daqui)
       for (j=0; j<N; j++)
          if (A[i][j] == 1 && dist[j] >= N) //anda toda a linha de i da matriz. Se i tem conexãoo com j (A[i][j] == 1) e j ainda não tiver sido checado
		  {
             dist[j] = dist[i] + 1; //está um elemento mais distante de i (se tivesse peso, dist[i] + A[i][j])
             Inserir(&F,j);
          }
    }
	
	//Imprime vetor de distâncias de 'c' para as demais cidades 'i'
	for (i=0; i<N; i++)
	   printf("dist[%d]: %d\n", i, dist[i]);	
}

#include <stdio.h>
#include <stdlib.h>

int tempo; //variável global para armazenar tempo

int leArquivo(const char *filename, int ***matriz);
void DSF(int numNos, int matriz[numNos][numNos], int cor[numNos], int dist[numNos]);
void DSF_visit(int i, int numNos, int *matriz[numNos][numNos], int *cor[numNos], int *dist[numNos]);

int main(){
    int **A; //vai ser matriz adjacente do arquivo
    int *cor, *dist; //guarda a cor de cada nó

    int numNos = leArquivo("grafo.txt", &A);
    cor = calloc(numNos, sizeof(int)); //inicializa tudo com zero = branco
    dist = calloc(numNos, sizeof(int));

    DSF(numNos, A, cor, dist);

    return 0;
}

//Função para efetuar a leitura do grafo via arquivo
int leArquivo(const char *filename, int ***matriz){ //const para não poder alterar 
    FILE *fp;
    int bsize = 20; //máximo de caracteres de uma linha
    int n, o, d, v, i, j;

    char buffer[bsize];
    fp = fopen(filename,"r");
	
	//Primeira linha do arquivo = número de nós
    fgets(buffer,bsize, fp); //carrega a linha toda em buffer
    sscanf(buffer,"%d", &n); //salva o numero de vertices/nós

	//alocando matriz e inicializando com zero
	(*matriz) = malloc(n * sizeof(int *));
	for(i = 0; i < n; i ++){
		(*matriz)[i] = malloc(n * sizeof(int));
		for(j = 0; j < n; j ++){
			(*matriz)[i][j] = 0;
		}
	}

    //Percorre o arquivo
	while(!feof(fp)){
        fgets(buffer,bsize, fp); //pega linha e guarda em buffer
        sscanf(buffer,"%d %d %d", &o, &d, &v); //pega de buffer e guarda nas variáveis auxiliares

		(*matriz)[o][d] = v;
    }

    fclose(fp);

    return n;
}

void DSF(int numNos, int matriz[numNos][numNos], int cor[numNos], int dist[numNos]){
    int i;
    tempo = 0;

    for(i = 0; i < numNos; i ++){
        if(cor[i] == 0){ //se o nó for branco
            DSF_visit(i, numNos, &matriz, &cor, &dist);
        }
    }
}

void DSF_visit(int i, int numNos, int *matriz[numNos][numNos], int *cor[numNos], int *dist[numNos]){
    int j;

    *(cor[i]) = 1; //cinza
    tempo++;
    *(dist[i]) = tempo;

    for(j = 0; j < numNos; j ++){ 
        if(*(matriz[i][j]) >= 1 && *(cor[j]) == 0){ //se forem adjacentes e j for branco
            DSF_visit(j, numNos, matriz, cor, dist);
        }
    }

    *(cor[i]) == 2; //preto
}
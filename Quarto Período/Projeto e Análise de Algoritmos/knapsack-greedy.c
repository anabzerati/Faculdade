#include <stdio.h>
#include <stdlib.h>

struct item {
	int valor, peso;
};

// comparação para ordenar seguindo a razão de valor por peso
int cmp(const void *a, const void *b){
  	struct item *a1 = (struct item *)a;
  	struct item *b1 = (struct item *)b;

	double r1 = (double) a1->valor / (double) a1->peso;
	double r2 = (double) b1->valor / (double) b1->peso;
	
	if (r1 < r2) return 1;
    if (r1 > r2) return -1;
    return 0;
}

double knapsack(int capacidadeMochila, struct item itens[], int N){
	// ordenar de acordo com razão de valor e peso 
	qsort(itens, N, sizeof(struct item), cmp);

	double maxValor = 0.0;

	for (int i = 0; i < N; i ++){ // para cada item
		if (itens[i].peso <= capacidadeMochila) { // se cabe
			capacidadeMochila -= itens[i].peso;
			maxValor += itens[i].valor;
		} 
	}

	return maxValor;
}

int main(){
	struct item arr[] = { { 60, 10 }, { 100, 20 }, { 120, 30 } }; 
  
  printf("O valor máximo é %f", knapsack(50, arr, 3));
	return 0;
}


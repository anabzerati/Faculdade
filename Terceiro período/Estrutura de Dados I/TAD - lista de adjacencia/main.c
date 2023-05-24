#include <stdlib.h>
#include "grafo.h"

int main(){
	Grafo g = criaGrafo();
	
	leArquivo(g, "digrafo2.txt"); //manda nome do arquivo
	imprimeGrafo(g);
	
	return 0;
}




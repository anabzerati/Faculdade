#define tam_fila 100 //tamanho max. fila
#define N 5 //Tamanho da matriz de conexões e vetor de distâncias


//Tipos exportados
//----------------------------------
typedef struct no *No;
typedef struct grafo *Grafo;
//----------------------------------

//Definiçãoo das funções
//----------------------------------
No criaNo(int id, int val);

void addNo(No n, int id, int val);

void imprimeNo(No n);

Grafo criaGrafo();

void leArquivo(Grafo G, const char *filename);

void imprimeGrafo(Grafo G);

void criaMatrizIncidencia(Grafo G, int **matriz); //falta fazer
//----------------------------------

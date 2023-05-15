/*-----Definição-----*/
typedef struct TipoElem{
	int chave;
} TipoElem;

//Fila de prioridade
typedef struct FilaPri{
	TipoElem *vet;
	int n;        //quantidade de elementos
	int tam;      //tamanho máximo
} FilaPri;


/*-----Funções e protótipos-----*/
#define pai(i) ((i-1)/2)
#define fEsq(i) (2*i+1) //Filho esquerdo de i
#define fDir(i) (2*i+2) //Filho direito de i

//verifica se a fila está vazia
int Vazia(FilaPri *filapri);

//verifica se a fila está cheia
int Cheia(FilaPri *filapri);

//troca dois elementos de lugar
void Permuta(TipoElem *a, TipoElem *b);

//cria a fila
FilaPri *Cria(int tam);

//insere elementos na fila
void Insere(FilaPri *filapri, TipoElem elem);

//percorre o heap "subindo" fazendo alterações necessárias
void SobeNoHeap(FilaPri *filapri, int indice);

//remove elemento de maior prioridade
TipoElem RemoveMaior(FilaPri* filapri);

//percorre o heap "descendo" fazendo alterações necessárias
void DesceNoHeap(FilaPri *filapri, int indice);

//altera prioridade de um elemento específico
void AlteraPrioridade(FilaPri *filapri, int indice, int valor);

//constroi a heap
void ConstroiHeap(FilaPri *filapri);

//realiza ordenação baseada no conceito de heap
void Heapsort(FilaPri *filapri);

//imprime fila
void Imprime(FilaPri *filapri);
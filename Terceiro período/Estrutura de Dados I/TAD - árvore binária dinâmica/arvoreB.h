
//EDs e tipos
//---------------------------------
typedef struct tipo_dado {
	int valor;
} tipo_dado;

typedef struct no {
	tipo_dado info;
	struct no *dir;
	struct no *esq;
} no;

typedef struct no *tree; //�rvore: ponteiro p/ um n�
//---------------------------------

//Prot�tipo das fun��es
//---------------------------------
tree Definir ();

int Vazia (tree t);

tree criaRaiz (tree t, tipo_dado elem);

int Altura (tree t);

int Balanceada (tree t);

int numeroNos (tree t);

int perfeitamenteBalanceada (tree t);

int insereDireita (tree pai, tipo_dado elem);

int insereEsquerda (tree pai, tipo_dado elem);

void Visita (tree t);

void preOrdem (tree t);

void inOrdem (tree t);

void posOrdem (tree t);

int pertence (tree t, tipo_dado elem);
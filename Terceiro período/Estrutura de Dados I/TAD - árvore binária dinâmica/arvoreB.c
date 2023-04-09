#include <stdio.h>
#include <stdlib.h>
#include "arvoreB.h"

//Implementa��es
//---------------------------------------

//Cria AB vazia
tree Definir (){
	return NULL;
}

//Verifica se a AB est� vazia
int Vazia (tree t){
	if(t == NULL){
		return 1;
	}
	return 0;
}

//Define o n� raiz
tree criaRaiz (tree t, tipo_dado elem){
	t = malloc (sizeof (no));
	
	if(!t){
		printf("Nao foi possivel criar o no raiz.\n");
		return NULL;
	}
	
	t->info = elem;
	t->dir = NULL;
	t->esq = NULL;
	
	return(t);		

}

//Retorna a altura (profundidade) da AB
int Altura (tree t){
	
	if (Vazia(t)){
		return 0;
	}
	
	int altE = Altura (t->esq);
	int altD = Altura (t->dir);
	
	if (altE > altD){
		return (altE + 1); 
	}
	return (altD + 1); 
	//altura = max(altE, altD) + 1
}

int Balanceada (tree t){
	if (Vazia (t)) return 1;
	
	else if (t->esq == NULL && t->dir == NULL) // se n�o tem filhos
		return 1;
		
	else if (t->esq != NULL && t->dir != NULL) //se tem duas sub-�rvores
		return (Balanceada (t->esq) && Balanceada (t->dir));
		
	else if (t->esq != NULL) //Se tem um unico filho na esquerda
		return (Altura (t->esq) == 1);
		
	else return (Altura (t->dir) == 1);//Se tem um unico filho na direita
}

int numeroNos (tree t){
	if (Vazia (t)) return 0;
	
	int nDir = numeroNos (t->dir);
	int nEsq = numeroNos (t->esq);
	
	return (nDir + nEsq + 1);
}


int perfeitamenteBalanceada (tree t){
	if (Vazia (t)) return 1;
	
	else if (t->esq == NULL && t->dir == NULL)
		return 1;
		
	else if (t->esq != NULL && t->dir != NULL)
		return (perfeitamenteBalanceada (t->esq) && perfeitamenteBalanceada (t->dir));
		//para ser perfeitamente balanceada o n�mero de n�s pode diferir em, no m�ximo, 1
	else if (t->esq != NULL)  
		return (numeroNos (t->esq) == 1);
	else return (numeroNos (t->dir) == 1);
}

int insereDireita (tree pai, tipo_dado elem){
	if (Vazia (pai)){
		return 0;
	}
	if (pai->dir != NULL){
		printf("Ja possui filho a direita. \n");
		return 0;
	}
	pai->dir = malloc (sizeof (struct no));
	if(!pai->dir){
		printf("Nao foi possivel criar o no.\n");
		return 0;
	}
	pai->dir->info = elem;
	pai->dir->dir = NULL;
	pai->dir->esq = NULL;

	return 1;
}

int insereEsquerda (tree pai, tipo_dado elem){
	if (Vazia (pai)){
		return 0;
	}
	if (pai->esq != NULL){
		printf("Ja possui filho a esquerda. \n");
		return 0;
	}
	
	pai->esq = malloc (sizeof (struct no));
	if(!pai->esq){
		printf("Nao foi possivel criar o no.\n");
		return 0;
	}
	pai->esq->info = elem;
	pai->esq->dir = NULL;
	pai->esq->esq = NULL;
	return 1;
}

void Visita (tree t){
	printf("Valor: %d\n", t->info.valor);
}

void preOrdem (tree t){
	if(t != NULL){
		Visita (t);
		preOrdem (t->esq);
		preOrdem (t->dir);
	}	
}

void inOrdem (tree t){
	if(t != NULL){
		inOrdem (t->esq);
		Visita (t);
		inOrdem (t->dir);
	}	
}

void posOrdem (tree t){
	if(t != NULL){
		posOrdem (t->esq);
		posOrdem (t->dir);
		Visita (t);
	}

}

int pertence (tree t, tipo_dado elem){
	
	if (Vazia(t))
		return 0; //�rvore vazia
	else
		return t->info.valor == elem.valor || pertence (t->esq,elem) || pertence (t->dir,elem);
}

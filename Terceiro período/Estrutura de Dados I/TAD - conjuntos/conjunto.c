#include <stdio.h>
#include <stdlib.h>
#include "conjunto.h"

typedef struct conjunto{
    int quantidadeElementos;
    int elementos[100];
} Conjunto;

Conjunto *criaConjuntoVazio(){
    int i;
    Conjunto *novoConjunto = malloc(sizeof(Conjunto));

    novoConjunto->quantidadeElementos = 0;

    for(i=0; i<100; i++){
        novoConjunto->elementos[i] = 0;
    }

    return novoConjunto;
}

int membro(Conjunto *A, int x){
    int inicio = 0, fim = A->quantidadeElementos - 1, meio;

    while(inicio <= fim){
        meio = (inicio + fim)/2;
        if(A->elementos[inicio] == x || A->elementos[fim] == x || A->elementos[meio] == x){
            return 1;
        } else{
            if(A->elementos[meio] > x){
                inicio = meio;
            } else{
                fim = meio;
            }
        }
    }

    return 0;
}

void insere(Conjunto *A, int x){
    if(!membro(A, x)){
        int indice = A->quantidadeElementos;
        if(A->elementos[indice] != 0){
            A->elementos[indice] = x;
            ordena(A->elementos, A->quantidadeElementos);
        }
    }
}

void ordena(int *vet, int tam){
    int aux, i, j;

    for(i=1; i<tam - 1; i++){
        aux = vet[i];
        j = i;
        while(vet[j] > vet[j+1] && j >= 0){
            vet[j+1] = vet[j];
            j--;
        }
        vet[j] = aux;
    }
}

void uniao(Conjunto *A, Conjunto *B, Conjunto *C){
    int ptrA, ptrB, ptrC;
    ptrA = ptrB = ptrC = 0;

    while(ptrA < A->quantidadeElementos && ptrB < B->quantidadeElementos){
        if(A->elementos[ptrA] == B->elementos[ptrB]){
            C->elementos[ptrC] = A->elementos[ptrA];
            ptrA++;
            ptrB++;
        } else if(A->elementos[ptrA] < B->elementos[ptrB]){
            C->elementos[ptrC] = A->elementos[ptrA];
            ptrA++;
        } else{
            C->elementos[ptrC] = B->elementos[ptrB];
            ptrB++;
        }
        ptrC++;
    }
}

void interseccao(Conjunto *A, Conjunto *B, Conjunto *C){
    int ptrA, ptrB, ptrC;
    ptrA = ptrB = ptrC = 0;

    while(ptrA < A->quantidadeElementos && ptrB < B->quantidadeElementos){
        if(A->elementos[ptrA] == B->elementos[ptrB]){
            C->elementos[ptrC] = A->elementos[ptrA];
            ptrA++;
            ptrB++;
            ptrC++;
        } else if(A->elementos[ptrA] < B->elementos[ptrB]){
            while(A->elementos[ptrA] < B->elementos[ptrB]){
                ptrA++;
            }
            if(A->elementos[ptrA] == B->elementos[ptrB]){
                C->elementos[ptrC] = A->elementos[ptrA];
                ptrC++;
            }
            ptrA++;
            ptrB++;
        } else{
            while(A->elementos[ptrA] > B->elementos[ptrB]){
                ptrB++;
            }
            if(A->elementos[ptrA] == B->elementos[ptrB]){
                C->elementos[ptrC] = A->elementos[ptrA];
                ptrC++;
            }
            ptrA++;
            ptrB++;
        }
    }
}


int igual(Conjunto *A, Conjunto *B){
    int i = 0;

    if(A->quantidadeElementos == B->quantidadeElementos){
        while(A->elementos[i] == B->elementos[i]){
            i++;
        }

        if(i == A->quantidadeElementos - 1){
            return 1;
        }
    }

    return 0;
}

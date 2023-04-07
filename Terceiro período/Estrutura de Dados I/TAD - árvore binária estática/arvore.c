#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define quantNos 31 //5 níveis

typedef int* arvore;

arvore definir(){ //define como vazia
    arvore t = malloc(quantNos * sizeof(int));
    int i;
    for(i = 0; i < quantNos; i++){
        t[i] = 0;
    }
    return t;
}

void criarRaiz(arvore t, int valor){ //verifica se já tem raíz. Se não tiver, atribui valor;
    if(t[0] != 0){
        printf("Árvore já possui raíz");
    }
    t[0] = valor;
}

int vazia(arvore t){ //verifica se está vazia (não tem raíz)
    if(t[0] == 0){
        return 1;
    }

    return 0;
}

int altura(arvore t){
    int ultimo = 0, i;
    for(i = 0; i < quantNos; i++){
        if(t[i] != 0){
            ultimo = i;
        }
    }

    return (log(ultimo + 2) / log(2)); //verificar
}

int numeroNos(arvore t){
    int i, quant = 0;
    for(i = 0; i < quantNos; i++){
        if(t[i] != 0){
            quant++;
        }
    }

    return quant;
}

void insereEsquerda(arvore t, int pai, int valor){
    if(t[pai] == 0){
        printf("Operação cancelada. Não há pai.");
        return;
    }
    t[(2 * pai) + 1] = valor;
}

void insereDireita(arvore t, int pai, int valor){
    if(t[pai] == 0){
        printf("Operação cancelada. Não há pai.");
        return;
    }
    t[(2 * pai) + 2] = valor;
}

void imprimir(arvore t){
    int i;
    for(i = 0; i < quantNos; i++){
        if(t[i] != 0){
            printf("%d ", t[i]);
        } else{
            printf("- ");
        }
    }
}

int main(){
    arvore arvore = definir(); 

    criarRaiz(arvore, 1);
    insereEsquerda(arvore, 0, 2);
    insereDireita(arvore, 0, 3);
    printf("%d", arvore[0]);
    imprimir(arvore);



    return 0;
}
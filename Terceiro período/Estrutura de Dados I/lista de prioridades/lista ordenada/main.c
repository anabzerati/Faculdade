#include <stdio.h>
#include <stdlib.h>
#include "listaOrdenada.h"

int main(){
    No *lista = NULL;

    lista = inserir(lista, 1);
    percorrer(lista);

    lista = inserir(lista, 2);
    percorrer(lista);

    No *removido = remover(&lista);
    percorrer(lista);
    printf("Removido: %d ", removido->chave);


}